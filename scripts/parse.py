# Responsible for parsing strings.
from data import ParamInfo, TypeInfo, FunctionInfo


def parse_brackets(text: str) -> list[str]:
    if text == "":
        return []

    texts_found = [""]
    current_pos = 0
    brackets_deep = 0

    while current_pos < len(text):
        c = text[current_pos]

        if c == "<" or c == "(":
            if brackets_deep == 0:  # Leaving main scope.
                texts_found.append("")

            texts_found[-1] += c
            brackets_deep += 1
        elif c == ">" or c == ")":
            texts_found[-1] += c
            brackets_deep -= 1

            if brackets_deep == 0:  # Entering main scope.
                texts_found.append("")
        else:
            texts_found[-1] += c

        current_pos += 1

    # Remove empties.
    texts_found = [t for t in texts_found if t]

    return texts_found


print(parse_brackets("int"))
print(parse_brackets("int, float"))
print(parse_brackets("Vector<int>"))
print(parse_brackets("Dictionary<int, float>"))
print(parse_brackets("void(int)"))
print(parse_brackets("void(int, float)"))
print(parse_brackets("void(Vector<int>)"))
print(parse_brackets("void(Dictionary<int, float>)"))
print(parse_brackets("Vector<Vector<int>, float>"))
print(parse_brackets("Vector<int>(int a, int b)"))
