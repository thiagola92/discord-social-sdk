# Responsible for parsing strings that doxygen didn't parsed.
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

    def read_until_leave_scope(self, new_scope: str, end_scope: str) -> None:
        """
        Read characters until find the character
        that leave the current scope.

        The current position must be poiting to the character
        that start a new scope, otherwise it will leave right
        after starting.

        If you need to know the content between where you are
        and where the string was found, you need to save
        the current_position before calling this.
        """

        scope_counter: int = 0

        while not self.is_eof(self.current_position):
            char: str = self.content[self.current_position]

            if char == new_scope:
                scope_counter += 1
            elif char == end_scope:
                scope_counter -= 1

            if scope_counter == 0:
                return

            self.current_position += 1

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
            c = self.content[self.current_position]

            if c == " ":
                p = Parser(self.content[: self.current_position])
                param_info.name = self.content[self.current_position :]
                param_info.name = param_info.name.strip()
                param_info.gdscript_name = to_gdscript_name(param_info.name)
                param_info.type = p.parse_type()
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

        while not self.is_eof(self.current_position):
            c = self.content[self.current_position]

            if c == "<":
                type_info.name = self.content[initial_position : self.current_position]
                type_info.name = type_info.name.strip()
                type_info.templates = self.parse_types()
            elif c == "(":
                if not type_info.name:
                    type_info.name = self.content[
                        initial_position : self.current_position
                    ]
                    type_info.name = type_info.name.strip()

                fi = FunctionInfo()
                fi.type = type_info
                fi.params = self.parse_params()
                return fi
            else:
                self.current_position += 1

        if not type_info.name:
            type_info.name = self.content[initial_position : self.current_position]
            type_info.name = type_info.name.strip()

        return type_info

    def parse_types(self) -> list[TypeInfo | FunctionInfo]:
        """
        Parse knowing that content includes angle brackets. Example:
            - <int>
            - <float>
            - <int, float>
            - <Vector<int>>
            - <Vector<int>, Vector<float>>
            - <Dictionary<int, float>>
        """

        # Start skipping first character.
        self.current_position += 1

        types_found = []
        brackets_deep = 0
        initial_position = self.current_position

        while not self.is_eof(self.current_position):
            c = self.content[self.current_position]

            if brackets_deep == 0:
                if c == ">":
                    p = Parser(self.content[initial_position : self.current_position])
                    ti = p.parse_type()

                    types_found.append(ti)

                    return types_found
                elif c == ",":
                    p = Parser(self.content[initial_position : self.current_position])
                    ti = p.parse_type()
                    initial_position = self.current_position + 1

                    types_found.append(ti)
            else:
                if c == ">":
                    brackets_deep += 1
                elif c == "<":
                    brackets_deep -= 1

            self.current_position += 1

        raise Exception(f"Missing closing angle bracket at {self.current_position}")

    def parse_params(self) -> list[ParamInfo]:
        """
        Parse knowing that content includes round brackets. Example:
            - (int)
            - (float)
            - (int, float)
            - (Vector<int>)
            - (Vector<int>, Vector<float>)
            - (Dictionary<int, float>)
        """

        # Start skipping first character.
        self.current_position += 1

        params_found = []
        brackets_deep = 0
        initial_position = self.current_position

        while not self.is_eof(self.current_position):
            c = self.content[self.current_position]

            if brackets_deep == 0:
                if c == ")":
                    p = Parser(self.content[initial_position : self.current_position])
                    pi = p.parse_param()

                    params_found.append(pi)

                    return params_found
                elif c == "<":
                    s = self.current_position

                    self.read_until_leave_scope("<", ">")

                    ti = TypeInfo()
                    ti.name = self.content[initial_position:s]
                    t = self.content[s : self.current_position + 1]
                    p = Parser(t)
                    ti.templates = p.parse_types()

                    if self.content[self.current_position + 1] == "(":
                        pass
                        # TODO: Mayyybe I should have a variable
                        # to remember the last type I'm working with...

                elif c == ",":
                    p = Parser(self.content[initial_position : self.current_position])
                    pi = p.parse_param()
                    initial_position = self.current_position + 1

                    params_found.append(pi)
            else:
                if c == ")":
                    brackets_deep += 1
                elif c == "(":
                    brackets_deep -= 1

            self.current_position += 1

        raise Exception(f"Missing closing round bracket at {self.current_position}")


# print(Parser("int").parse_type())
# print(Parser("Vector<int>").parse_type())
# print(Parser("Dictionary<int, float>").parse_type())
# print(Parser("void(int a)").parse_type())
# print(Parser("void(int a, float b)").parse_type())
# print(Parser("void(Vector<int> a)").parse_type())
# print(Parser("void(Dictionary<int, float> a)").parse_type())
print(Parser("Vector<Vector<int> a, float b>").parse_type())
# print(Parser("Vector<int>(int a, int b)").parse_type())
