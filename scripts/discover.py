# Responsible for discovering information.
from enum import Enum

from data import FunctionInfo


class OverloadingPattern(Enum):
    # Was not possible to detect a pattern,
    # solve using a generic approach.
    UNKNOWN = 0

    # Overloading is just switching between
    # types of enums.
    ENUMS = 1


def discover_overloading_type(functions: list[FunctionInfo]) -> OverloadingPattern:
    """
    Discover the best strategy to deal with this overloading.

    This information is later used to forge a function that
    best solve this problem.
    """

    all_enums = False

    for f in functions:
        for p in f.params:
            pass
