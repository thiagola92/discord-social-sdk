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
        docstring = TokenDocstring([])
        string_matched = self.read_until_find(["enum", "inline", "class", "///"])

        while string_matched:
            match string_matched:
                case "enum":
                    tokens.append(self.parse_enum(docs=docstring))
                    docstring = TokenDocstring([])
                case "inline":
                    tokens.append(self.parse_function(docs=docstring, static=True))
                    docstring = TokenDocstring([])
                case "class":
                    tokens.append(self.parse_class(docstring))
                    docstring = TokenDocstring([])
                    pass
                case "///":
                    self.parse_docstring(docstring)

            string_matched = self.read_until_find(["enum", "inline", "class", "///"])

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

    def get_text_before(self, strings: list[str]) -> tuple[str | None, str | None]:
        """
        Returns a tuple:
            First value is the text between current position and the matched string
            Second value is the matched string

        Both will be None if doesn't find a match.

        This will move the current position while searching for a match.
        """
        start_position = self.current_position

        if (string := self.read_until_find(strings)) is None:
            return (None, None)

        return (self.content[start_position : self.current_position - 1], string)

    def parse_enum(self, docs: TokenDocstring) -> TokenEnum | None:
        # Parse name.
        text, _ = self.get_text_before(["{"])

        if text is None:
            return None

        name = text.strip().removeprefix("class ")

        # Parse options.
        text, string_matched = self.get_text_before(["}", "///", ","])
        counter = 0
        options = {}
        docstring = TokenDocstring([])
        options_docs = {}

        while string_matched:
            match string_matched:
                case "}":
                    break
                case "///":
                    self.parse_docstring(docstring)
                case ",":
                    texts = text.split("=")
                    texts = [t.strip() for t in texts]

                    if len(texts) == 1:
                        options[texts[0]] = str(counter)
                        counter += 1
                    else:
                        options[texts[0]] = texts[1]
                        counter = int(texts[1]) + 1

                    options_docs[texts[0]] = docstring
                    docstring = TokenDocstring([])

            text, string_matched = self.get_text_before(["}", "///", ","])

        return TokenEnum(
            docs=docs,
            name=name,
            options_docs=options_docs,
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
        text, _ = self.get_text_before([")"])

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

    def parse_function(
        self,
        docs: TokenDocstring,
        static: bool = False,
    ) -> TokenFunction | None:
        text, _ = self.get_text_before(["("])

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
            docs=docs,
            ret=ret,
            name=name,
            params=params,
            static=static,
        )

    def parse_callback(self) -> TokenCallback | None:
        # Parse name.
        name, _ = self.get_text_before(["="])
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

    def parse_class(self, docs: TokenDocstring) -> TokenClass | None:
        # Parse name.
        name, _ = self.get_text_before(["{"])

        if name is None:
            return None

        name = name.strip()

        # Split statements (with their respective docstring).
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
            elif char == "/":
                s = self.content[self.current_position : self.current_position + 2]

                if s == "///":
                    self.read_until_find(["\n"])
                    self.current_position -= 1  # Undo next addition.

            self.current_position += 1

        # Parse statements.
        enums = []
        callbacks = []
        constructors = []
        functions = []

        for statement in statements:
            parser = Parser(statement)
            docstring = TokenDocstring([])
            s = parser.parse_statement(name, docstring)

            if isinstance(s, TokenEnum):
                enums.append(s)
            elif isinstance(s, TokenCallback):
                callbacks.append(s)
            elif isinstance(s, TokenConstructor):
                constructors.append(s)
            elif isinstance(s, TokenFunction):
                functions.append(s)
            else:
                assert False, "Fail to parse statement"

        # for statement in statements:
        #     parser = Parser(content=statement)

        #     if statement.startswith("enum "):
        #         parser.read_until_find(["enum"])
        #         enums.append(parser.parse_enum())
        #     elif statement.startswith("using "):
        #         callbacks.append(parser.parse_callback())
        #     elif statement.startswith(name):
        #         constructors.append(parser.parse_constructor())
        #     elif statement.startswith("explicit "):
        #         parser.read_until_find(["explicit"])
        #         constructors.append(parser.parse_constructor())
        #     elif statement.startswith("static "):
        #         parser.read_until_find(["static"])
        #         functions.append(parser.parse_function(static=True))
        #     elif statement.startswith("///"):
        #         pass
        #     else:
        #         functions.append(parser.parse_function(TokenDocstring([])))

        return TokenClass(
            docs=docs,
            name=name,
            enums=enums,
            callbacks=callbacks,
            constructors=constructors,
            functions=functions,
        )

    def parse_statement(
        self,
        class_name: str,
        docs: TokenDocstring,
    ) -> TokenEnum | TokenCallback | TokenConstructor | TokenFunction:
        if self.content.startswith("enum "):
            self.read_until_find(["enum"])
            return self.parse_enum(docs)
        elif self.content.startswith("using "):
            return self.parse_callback()
        elif self.content.startswith(class_name):
            return self.parse_constructor()
        elif self.content.startswith("explicit "):
            self.read_until_find(["explicit"])
            return self.parse_constructor()
        elif self.content.startswith("static "):
            self.read_until_find(["static"])
            return self.parse_function(docs, static=True)
        elif self.content.startswith("///"):
            self.read_until_find(["///"])
            self.parse_docstring(docs)

            residue = self.content[self.current_position :]
            residue = residue.strip()
            parser = Parser(residue)

            return parser.parse_statement(class_name, docs)
        else:
            return self.parse_function(docs)

    def parse_docstring(self, docstring: TokenDocstring):
        """
        Receives the token that will be expanded as we discover more docstrings.
        """

        # Parse docstring.
        line, _ = self.get_text_before(["\n"])
        line = line or ""
        line = line.strip()

        # Docstring just extend an existing one.
        docstring.lines.append(line)
