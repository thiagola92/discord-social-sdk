from parser.tokens import (
    TokenEnum,
    TokenType,
    TokenParam,
    TokenConstructor,
    TokenFunction,
    TokenCallback,
    TokenClass,
    TokenDocstring,
)


class Parser:
    def __init__(self, content: str):
        self.current_position = 0
        self.content = content

    def start(self) -> list[TokenEnum | TokenFunction | TokenClass]:
        tokens = []
        string_matched = self.read_until_find(["enum", "inline", "class", "///"])

        while string_matched:
            match string_matched:
                case "enum":
                    tokens.append(self.parse_enum())
                case "inline":
                    tokens.append(self.parse_function(static=True))
                case "class":
                    tokens.append(self.parse_class())
                case "///":
                    tokens.append(self.parse_docstring())

            string_matched = self.read_until_find(["enum", "inline", "class"])

        return tokens

    def is_eof(self, pos: int) -> bool:
        return pos >= len(self.content)

    def read_until_find(self, strings: list[str]) -> str | None:
        """
        Read characters until find one of the passed strings.

        It will return the string found or
        None if it's at the end of file.

        If you need to know the content between where you are
        and where the string was found, you need to save
        the current_position before calling this.
        """

        match_count: list[int] = [0 for _ in strings]

        while not self.is_eof(self.current_position):
            char: str = self.content[self.current_position]

            for i, string in enumerate(strings):
                string_char: str = string[match_count[i]]

                # Reset counter if doesn't match.
                if char != string_char:
                    match_count[i] = 0
                    continue

                match_count[i] += 1

                # Found it, move to next character so
                # next search start from the next one.
                if match_count[i] == len(string):
                    self.current_position += 1
                    return string

            self.current_position += 1

        return None

    def get_text_before(self, string: str) -> str | None:
        """
        Return the text between current position and a string,
        otherwise None.

        This will move the current position while searching
        for the string.
        """
        start_position = self.current_position

        if self.read_until_find([string]) is None:
            return None

        return self.content[start_position : self.current_position - 1]

    def parse_enum(self) -> TokenEnum | None:
        # Parse name.
        text = self.get_text_before("{")

        if text is None:
            return None

        name = text.strip().removeprefix("class ")

        # Parse options.
        text = self.get_text_before("}")
        text = text or ""
        lines = text.split(",")
        lines = [l.strip() for l in lines]
        lines = [l for l in lines if l]
        lines = [l.split("=") for l in lines]
        counter = 0

        for l in lines:
            if len(l) == 1:
                l.append(str(counter))
                counter += 1

            l[0] = l[0].strip()

        options = {l[0]: l[1] for l in lines}

        return TokenEnum(
            name=name,
            options=options,
        )

    def parse_type(self, text: str) -> TokenType:
        """
        Parse a specific text that you know it's a type.

        This doesn't move the current position,
        it just get the type from a specific text.
        """
        text = text.strip()
        current_position: int = 0
        name: str = ""

        while current_position < len(text):
            char: str = text[current_position]

            if char == "<":
                subtype = self.parse_type(text[current_position + 1 :])
                return TokenType(name=name, subtype=subtype)
            elif char == ">":
                return TokenType(name=name, subtype=None)

            # NOTE: I know that I'm not solving for cases where
            # there is generics with generics inside, like:
            #       std::unordered_map<std::string, std::vector<std::string>>
            # But I beleive that will always be simple something simple, like:
            #       std::unordered_map<std::string, std::string>
            # Otherwise I would have to do subtype a list.

            name += char
            current_position += 1

        return TokenType(
            name=name,
            subtype=None,
        )

    def parse_param(self, text: str) -> TokenParam:
        """
        Parse a specific text that you know it's a param.

        This doesn't move the current position,
        it just get the param from a specific text.
        """

        # Parse name.
        for i in range(-1, -len(text), -1):
            if text[i] == " " or text[i] == "*" or text[i] == "&":
                name = text[i + 1 :].strip()
                type = text[: i + 1].strip()
                break

        # Parse type.
        type = self.parse_type(type)

        return TokenParam(
            type=type,
            name=name,
        )

    def parse_params(self) -> list[TokenParam]:
        text = self.get_text_before(")")

        if text is None or text == "":
            return []

        # Split text in params by detecting commas,
        # but taking care to not match generics like <String, String>
        param_start_position = 0
        current_position = 0
        inside_brackets = 0
        params = []

        while current_position < len(text):
            char: str = text[current_position]

            if char == "<":
                inside_brackets += 1
            elif char == ">":
                inside_brackets -= 1
            elif char == "," and inside_brackets == 0:
                params.append(text[param_start_position:current_position])
                param_start_position = current_position + 1

            current_position += 1

        params.append(text[param_start_position:])
        params = [self.parse_param(p) for p in params]

        return params

    def parse_function(self, static: bool = False) -> TokenFunction | None:
        text = self.get_text_before("(")

        if text is None:
            return None

        # Funny that I can reuse the parse_param() to get
        # return type and function name.
        token_param = self.parse_param(text)
        name = token_param.name
        ret = token_param.type

        # Parse params.
        params = self.parse_params()

        return TokenFunction(
            ret=ret,
            name=name,
            params=params,
            static=static,
        )

    def parse_callback(self) -> TokenCallback | None:
        # Parse name.
        name = self.get_text_before("=")
        name = name.removeprefix("using")
        name = name.strip()

        # Parse params.
        if self.read_until_find(["void("]) is None:
            return None

        params = self.parse_params()

        return TokenCallback(
            name=name,
            params=params,
        )

    def parse_constructor(self) -> TokenConstructor | None:
        if self.read_until_find(["("]) is None:
            return None

        params = self.parse_params()
        deleted = self.content.endswith("delete")

        return TokenConstructor(
            params=params,
            deleted=deleted,
        )

    def parse_class(self) -> TokenClass | None:
        # Parse name.
        name = self.get_text_before("{")

        if name is None:
            return None

        name = name.strip()

        # Split statements.
        statements: list[str] = []
        statement_start_position = self.current_position
        braces = 1

        while braces > 0:
            char: str = self.content[self.current_position]

            if char == "{":
                braces += 1
            elif char == "}":
                braces -= 1
            elif char == ";":
                s = self.content[statement_start_position : self.current_position]
                statements.append(s.strip())
                statement_start_position = self.current_position + 1

            self.current_position += 1

        # Parse statements
        enums = []
        callbacks = []
        constructors = []
        functions = []

        for statement in statements:
            parser = Parser(content=statement)

            if statement.startswith("enum "):
                parser.read_until_find(["enum"])
                enums.append(parser.parse_enum())
            elif statement.startswith("using "):
                callbacks.append(parser.parse_callback())
            elif statement.startswith(name):
                constructors.append(parser.parse_constructor())
            elif statement.startswith("explicit "):
                parser.read_until_find(["explicit"])
                constructors.append(parser.parse_constructor())
            elif statement.startswith("static "):
                parser.read_until_find(["static"])
                functions.append(parser.parse_function(static=True))
            else:
                functions.append(parser.parse_function())

        return TokenClass(
            name=name,
            enums=enums,
            callbacks=callbacks,
            constructors=constructors,
            functions=functions,
        )

    def parse_docstring(self) -> TokenDocstring:
        return TokenDocstring(text=self.get_text_before("\n").strip())
