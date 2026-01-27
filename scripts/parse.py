# Responsible for parsing strings.
from data import ParamInfo, TypeInfo, FunctionInfo


def parse_type(type_str: str) -> list[TypeInfo]:
    """
    Parse string to obtain all types.

    Note: It assumes that we will never have mix of brackets.
    Note: Don't aske me to review but I will not remember.
    """

    if type_str == "":
        return []

    types_found = [TypeInfo()]
    type_start = 0
    subtype_start = 0
    current_pos = 0
    brackets_deep = 0

    while current_pos < len(type_str):
        c: str = type_str[current_pos]

        if c == "<" or c == "(":
            brackets_deep += 1

            if brackets_deep == 1:
                types_found[-1].name = type_str[type_start:current_pos].strip()
                subtype_start = current_pos + 1
        elif c == ">" or c == ")":
            brackets_deep -= 1

            if brackets_deep == 0:
                si = parse_type(type_str[subtype_start:current_pos])
                types_found[-1].subtype = si
                type_start = current_pos + 1
        elif c == "," and brackets_deep == 0:
            if not types_found[-1].name:
                n, _, e = type_str[type_start:current_pos].strip().partition(" ")
                types_found[-1].name = n.strip()
                types_found[-1].extra = e.strip()
            else:
                types_found[-1].extra = type_str[type_start:current_pos].strip()

            types_found.append(TypeInfo())
            type_start = current_pos + 1

        current_pos += 1

    if not types_found[-1].name:
        n, _, e = type_str[type_start:current_pos].strip().partition(" ")
        types_found[-1].name = n.strip()
        types_found[-1].extra = e.strip()
    else:
        types_found[-1].extra = type_str[type_start:current_pos].strip()

    return types_found


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
        start_position = self.current_position

        if (string := self.read_until_find(strings)) is None:
            return (None, None)

        return (self.content[start_position : self.current_position - 1], string)

    def parse_type(self) -> TypeInfo | FunctionInfo:
        """Parse the content that is a supposed type."""

        type_info = TypeInfo()
        text, matched = self.get_text_before(["<", ">", "(", ")", ","])

        match matched:
            case "<":
                type_info.name = text
                type_info.templates = self.parse_templates()
            case "(":
                if not type_info.name:
                    type_info.name = text

                fi = FunctionInfo()
                fi.type = type_info
                fi.params = self.parse_params()

                return fi

        return type_info

    def parse_templates(self) -> list[TypeInfo | FunctionInfo]:
        type_info = TypeInfo()
        templates = []
        text, matched = self.get_text_before(["<", ">", ","])

        while matched:
            match matched:
                case "<":
                    type_info.name = text
                    type_info.templates = self.parse_templates()
                case ">":
                    type_info.name = text
                    templates.append(type_info)
                    return templates
                case ",":
                    if not type_info.name:
                        type_info.name = text

                    templates.append(type_info)
                    type_info = TypeInfo()

            text, matched = self.get_text_before(["<", ">", ","])

    def parse_params(self) -> list[ParamInfo]:
        pass
