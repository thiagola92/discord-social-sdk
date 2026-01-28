# Responsible for parsing strings.
from dataclasses import dataclass, field

from data import ParamInfo, TypeInfo, FunctionInfo


def parse_every_scope(text: str):
    """
    Recursively split text every time that detects another scope.
    """

    main_scope = parse_main_scope(text)

    for i, t in enumerate(main_scope):
        if t.startswith("<"):  # Template types.
            main_scope[i] = {
                "templates": parse_every_scope(t[1:-1]),
            }
            pass
        elif t.startswith("("):  # Parameters.
            main_scope[i] = {
                "parameters": parse_every_scope(t[1:-1]),
            }

    for i, t in enumerate(main_scope):
        if "," in t:
            t.split(",")

    return main_scope


def parse_main_scope(text: str) -> list[str]:
    """
    Split text every time that leave/enter main scope.
    """

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
    texts_found = [t.strip() for t in texts_found]
    texts_found = [t for t in texts_found if t]

    return texts_found


print(parse_every_scope("int"))
print(parse_every_scope("int, float"))
print(parse_every_scope("Vector<int>"))
print(parse_every_scope("Vector<int>, Vector<int>"))
print(parse_every_scope("Dictionary<int, float>"))
print(parse_every_scope("void(int)"))
print(parse_every_scope("void(int, float)"))
print(parse_every_scope("void(Vector<int>)"))
print(parse_every_scope("void(Dictionary<int, float>)"))
print(parse_every_scope("Vector<Vector<int>, float>"))
print(parse_every_scope("Vector<int>(int a, int b)"))
