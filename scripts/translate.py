# Responsible for translating between Discord C++ and Godot C++.
#
# Most translation functions will follow the pattern:
#   discord_type_to_godot_type()
#   discord_optional_to_godot_variant()
#   discord_vector_to_godot_array()
#   godot_type_to_discord_type()
#   godot_variant_to_discord_optional()
#   godot_array_to_discord_vector()
from pprint import pprint

from data import TypeInfo, FunctionInfo, ParamInfo
from name import to_godot_class_name


def is_discord_void(type_str: str) -> bool:
    return type_str in ["void"]


def is_discord_bool(type_str: str) -> bool:
    return type_str in ["bool", "bool&", "bool &"]


def is_discord_int(type_str: str) -> bool:
    return type_str in [
        "uint8_t",
        "int16_t *",
        "int16_t const*",
        "int16_t const *",
        "int32_t",
        "static int32_t",
        "uint32_t",
        "int64_t",
        "uint64_t",
    ]


def is_discord_float(type_str: str) -> bool:
    return type_str in ["float"]


def is_discord_string(type_str: str) -> bool:
    return type_str in [
        "std::string",
        "std::string const",
        "static std::string",
        "std::string const &",
    ]


def is_discord_char_array(type_str: str) -> bool:
    return type_str in ["const char *"]


def is_discord_opt(type_str: str) -> bool:
    return type_str.startswith("std::optional")


def is_discord_vec(type_str: str) -> bool:
    return type_str.startswith("std::vector")


def is_discord_map(type_str: str) -> bool:
    return type_str.startswith("std::unordered_map")


def is_discord_obj(type_str: str) -> bool:
    return type_str.startswith("discordpp::")


######################################################################
# Translate Discord type to Godot type.
######################################################################


def discord_type_to_godot_type(info: TypeInfo | FunctionInfo) -> str:
    if is_discord_void(info.name):
        return "void"

    if is_discord_bool(info.name):
        return "bool"

    if is_discord_int(info.name):
        return "int64_t"

    if is_discord_float(info.name):
        return "float"

    if is_discord_string(info.name):
        return "String"

    if is_discord_char_array(info.name):
        return "String"

    if is_discord_opt(info.name):
        return "Variant"

    if is_discord_vec(info.name):
        t = discord_type_to_godot_type(info.templates[0])
        return f"TypedArray<{t}>"

    if is_discord_map(info.name):
        t = [discord_type_to_godot_type(t) for t in info.templates]
        t = ",".join(t)
        return f"TypedDictionary<{t}>"

    if is_discord_obj(info.name):
        return to_godot_class_name(info.name)

    assert False, f'Fail to identify a good type for "{info.name}"'


def discord_params_to_godot_params(params: list[ParamInfo]) -> str:
    result = ""

    for i, p in enumerate(params):
        if p.callback:
            result += "Callable"
        elif p.enum and p.fake:
            result += "Variant"
        elif p.enum and p.overloading:
            result += "int"
        elif p.enum:
            result += discord_type_to_godot_type(p.type)
            result += "::Enum"
        else:
            result += discord_type_to_godot_type(p.type)

        result += " "
        result += p.gdscript_name

        if i != len(params) - 1:
            result += ", "

    return result
