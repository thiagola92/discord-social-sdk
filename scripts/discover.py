# Responsible for discovering information about the data collected.
from enum import Enum

from data import FunctionInfo, TypeInfo, NamespaceInfo, ClassInfo


class OverloadingPattern(Enum):
    # Was not possible to detect a pattern! Try solving with:
    #       function(arg0: Variant, arg1: Variant, types: Dictionary[String, String]) -> String
    NONE = 0

    # Use an extra argument to discover the enum.
    #       function(arg0: int, type: Variant) -> String
    RET_SAME_ARGS_ENUMS = 1

    # The order of types tell us which function to use.
    #       function(arg0: int, arg1: float) -> float
    #       function(arg0: float, arg1: int) -> float
    RET_SAME_ARGS_TYPES = 2


def discover_overloading_pattern(functions: list[FunctionInfo]) -> OverloadingPattern:
    """
    Discover the best strategy to deal with this overloading.

    This information is later used to forge a function that
    best solve this problem.
    """

    only_enum_params = True
    match_quantity = True
    match_return = True
    first_quantity: None | int = None
    first_return: None | TypeInfo = None

    for f in functions:
        if first_quantity is None:
            first_quantity = len(f.params)
        elif first_quantity != len(f.params):
            match_quantity = False

        if first_return is None:
            first_return = f.type
        elif first_return != f.type:
            match_return = False

        for p in f.params:
            if not p.enum:
                only_enum_params = False

    if only_enum_params and match_quantity and match_return:
        return OverloadingPattern.RET_SAME_ARGS_ENUMS

    return OverloadingPattern.NONE


def discover_overloading_groups(
    info: NamespaceInfo | ClassInfo,
) -> dict[str, list[FunctionInfo]]:
    overloading_groups: dict[str, list[FunctionInfo]] = {}

    for f in info.functions:
        if f.overloading:
            if f.gdscript_name in overloading_groups:
                overloading_groups[f.gdscript_name].append(f)
            else:
                overloading_groups[f.gdscript_name] = [f]

    return overloading_groups
