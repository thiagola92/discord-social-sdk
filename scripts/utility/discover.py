# Functions to discover information about the data collected.
#
# type: ignore
from enum import Enum

from utility.data import ClassInfo, FunctionInfo, NamespaceInfo, TypeInfo
from utility.name import to_gdscript_variable_name


# It's not possible to know the pointer size by reading the signature of the function:
#       void example(int64_t* a, int64_t b, int64_t c);
#           - It could be a pointer for one value
#           - It could be that b is the size
#           - It could be some math like b * c is the size
# The fact is, only reading the documentation we can know. So the best solution is to "map" them.
POINTER_SIZE_MAP: list[dict] = [
    {
        "path": [
            "Client",
            "UserAudioReceivedCallback",
            "std::function",
            "",
            "data",
            "int16_t *",
        ],
        "size": to_gdscript_variable_name("samplesPerChannel * channels"),
    },
    {
        "path": [
            "Client",
            "UserAudioCapturedCallback",
            "std::function",
            "",
            "data",
            "int16_t *",
        ],
        "size": to_gdscript_variable_name("samplesPerChannel * channels"),
    },
]


class OverloadingPattern(Enum):
    # Was not possible to detect a pattern! Try solving with:
    #       function(arg0: Variant, arg1: Variant, types: Dictionary[String, String]) -> String
    NONE = 0

    # Use an extra argument to discover the enum.
    #       function(arg0: int, type: String) -> String
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


def discover_pointer_size(type_info: TypeInfo) -> str:
    """
    Discover the string that will give the pointer size,
    otherwise assume that is a pointer for only one value.
    """

    for option in POINTER_SIZE_MAP:
        if option["path"] == type_info.pointer_path:
            return option["size"]

    return "1"
