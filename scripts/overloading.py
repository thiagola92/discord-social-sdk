# Responsible for solving function overloading problems.

"""
### Problem
GDScript doesn't support function overloading.This means that,
we can't have two functions having the same name but different parameters:

    func example(a: int)
    func example(a: int, b: int)
    func example(a: float)

An enum parameter is nothing more than an integer. This means that,
we can't indentify an enum after receiving it value:

    func _ready() -> void
        example(0)             # "int"
        example(MyEnum.ZERO)   # "int"

    func example(a: int) -> String:
        return type_string(typeof(a))

Using Variant and checking type will also not work:

    func _ready() -> void
        example(0)             # true
        example(MyEnum.ZERO)   # true

    func example((a: Variant) -> bool:
        return a is MyEnum
"""

from data import FunctionInfo


def check_overloading(functions: list[FunctionInfo]) -> list[FunctionInfo]:
    counter: dict[str, int] = {}

    for f in functions:
        if f.gdscript_name in counter:
            counter[f.gdscript_name] += 1
        else:
            counter[f.gdscript_name] = 0

    for f in functions:
        if counter[f.gdscript_name] > 0:
            f.overloading = True

    return functions
