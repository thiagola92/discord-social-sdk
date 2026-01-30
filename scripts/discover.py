# Responsible for discovering information.
from enum import Enum

from data import FunctionInfo, TypeInfo


class OverloadingPattern(Enum):
    # Was not possible to detect a pattern,
    # solve using a generic approach.
    NONE = 0

    # Overloading is just switching between
    # types of enums.
    ENUMS = 1


def discover_overloading_type(functions: list[FunctionInfo]) -> OverloadingPattern:
    """
    Discover the best strategy to deal with this overloading.

    This information is later used to forge a function that
    best solve this problem.
    """

    only_enums = True
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
                only_enums = False

    if only_enums and match_quantity and match_return:
        return OverloadingPattern.ENUMS

    return OverloadingPattern.NONE
