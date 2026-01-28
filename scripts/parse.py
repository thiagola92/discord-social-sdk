# Responsible for parsing strings that doxygen didn't parsed.
from pprint import pprint

from name import to_gdscript_name
from data import ParamInfo, TypeInfo, FunctionInfo


class Parser:
    def __init__(self, content: str):
        self.current_position = 0
        self.content = content

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
        start_position: int = self.current_position

        if (string := self.read_until_find(strings)) is None:
            return (None, None)

        return (self.content[start_position : self.current_position - 1], string)

    def read_until_leave_bracket(self, enter_bracket: str, leave_bracket: str) -> None:
        """
        Read characters until find the bracket
        that leave the current scope.

        The current position must be pointing to the
        bracket that enter the scope, otherwise
        it will leave right away.

        If you need to know the content between where you are
        and where the string was found, you need to save
        the current_position before calling this.
        """

        scope_counter: int = 0

        while not self.is_eof(self.current_position):
            char: str = self.content[self.current_position]

            if char == enter_bracket:
                scope_counter += 1
            elif char == leave_bracket:
                scope_counter -= 1

            if scope_counter == 0:
                return

            self.current_position += 1

    def get_text_inside_brackets(self, enter_bracket: str, leave_bracket: str) -> str:
        """
        Returns the text inside the most outside brackets.

        This will move the current position while searching for a match.
        """
        start_position: int = self.current_position

        self.read_until_leave_bracket(enter_bracket, leave_bracket)

        return self.content[start_position + 1 : self.current_position]

    def parse_param(self) -> TypeInfo:
        """
        Parse knowing that content is ONE parameter. Example:
            - int a
            - float a
            - Vector<int> b
            - Dictionary<int, float> b
            - void(int a, float b) c
            - void(Vector<int> a, Vector<float> b) c
        """

        # We are walking backwards.
        self.current_position = len(self.content) - 1
        param_info = ParamInfo()

        while self.current_position >= 0:
            char = self.content[self.current_position]

            if char == " ":
                parser = Parser(self.content[: self.current_position])
                param_info.name = self.content[self.current_position :]
                param_info.name = param_info.name.strip()
                param_info.gdscript_name = to_gdscript_name(param_info.name)
                param_info.type = parser.parse_type()
                return param_info

            self.current_position -= 1

        raise Exception("Unable to find parameter name")

    def parse_type(self) -> TypeInfo | FunctionInfo:
        """
        Parse knowing that content is ONE type. Example:
            - int
            - float
            - Vector<int>
            - Dictionary<int, float>
            - void(int a, float b)
            - void(Vector<int> a, Vector<float> b)
        """

        type_info = TypeInfo()
        initial_position = self.current_position

        def get_type_name() -> str:
            return self.content[initial_position : self.current_position].strip()

        while not self.is_eof(self.current_position):
            char = self.content[self.current_position]

            if char == "<":
                type_info.name = get_type_name()
                parser = Parser(self.get_text_inside_brackets("<", ">"))
                type_info.templates = parser.parse_types()
            elif char == "(":
                if not type_info.name:
                    type_info.name = get_type_name()

                function_info = FunctionInfo()
                function_info.type = type_info
                parser = Parser(self.get_text_inside_brackets("(", ")"))
                function_info.params = parser.parse_params()

                return function_info
            else:
                self.current_position += 1

        if not type_info.name:
            type_info.name = get_type_name().strip()

        return type_info

    def parse_types(self) -> list[TypeInfo | FunctionInfo]:
        """
        Parse knowing that content is ONLY a list of types. Example:
            - int
            - float
            - int, float
            - Vector<int>
            - Vector<int>, Vector<float>
            - Dictionary<int, float>
        """

        types_found = []
        type_info = TypeInfo()
        type_start_position = self.current_position

        def get_type_name() -> str:
            return self.content[type_start_position : self.current_position].strip()

        while not self.is_eof(self.current_position):
            char = self.content[self.current_position]

            if char == "<":
                type_info.name = get_type_name()
                parser = Parser(self.get_text_inside_brackets("<", ">"))
                type_info.templates = parser.parse_types()

                # Skip ">"
                type_start_position = self.current_position + 1
            elif char == "(":
                if not type_info.name:
                    type_info.name = get_type_name()

                function_info = FunctionInfo()
                function_info.type = type_info
                parser = Parser(self.get_text_inside_brackets("(", ")"))
                function_info.params = parser.parse_params()

                # Skip ")"
                type_start_position = self.current_position + 1

                types_found.append(function_info)
            elif char == ",":
                if not type_info.name:
                    type_info.name = get_type_name()

                types_found.append(type_info)
                type_info = TypeInfo()
                type_start_position = self.current_position + 1

            self.current_position += 1

        if type_name := get_type_name():
            type_info.name = type_name
            types_found.append(type_info)

        return types_found

    def parse_params(self) -> list[ParamInfo]:
        """
        Parse knowing that is ONLY a list of params. Example:
            - int
            - float
            - int, float
            - Vector<int>
            - Vector<int>, Vector<float>
            - Dictionary<int, float>
        """

        params_found = []
        param_start_position = self.current_position

        def get_param() -> ParamInfo:
            text = self.content[param_start_position : self.current_position].strip()
            return Parser(text).parse_param()

        while not self.is_eof(self.current_position):
            char = self.content[self.current_position]

            if char == "<":
                self.read_until_leave_bracket("<", ">")
            elif char == "(":
                self.read_until_leave_bracket("(", ")")
            elif char == ",":
                params_found.append(get_param())
                param_start_position = self.current_position + 1

            self.current_position += 1

        param_info = get_param()

        if param_info.type.name:
            params_found.append(param_info)

        return params_found


# pprint(Parser("int").parse_type())
# pprint(Parser("Vector<int>").parse_type())
# pprint(Parser("Dictionary<int, float>").parse_type())
# pprint(Parser("void(int a)").parse_type())
# pprint(Parser("void(int a, float b)").parse_type())
# pprint(Parser("void(Vector<int> a)").parse_type())
# pprint(Parser("void(Dictionary<int, float> a)").parse_type())
# pprint(Parser("Vector<Vector<int>, float>").parse_type())
# pprint(Parser("Vector<int>(int a, float b)").parse_type())
