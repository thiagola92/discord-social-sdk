# Responsible for parsing strings.
from data import TypeInfo


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
