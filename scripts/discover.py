# Responsible for discovering information.
from enum import Enum

from data import FunctionInfo


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
    params_quantity = []

    for f in functions:
        params_quantity.append(len(f.params))

        for p in f.params:
            if not p.enum:
                only_enums = False
                print(f.name, p.type.name)

    for c in params_quantity[:1]:
        match_quantity = params_quantity.count(c) == len(params_quantity)

    if only_enums and match_quantity:
        return OverloadingPattern.ENUMS

    return OverloadingPattern.NONE
