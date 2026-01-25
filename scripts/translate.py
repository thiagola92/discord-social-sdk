# Responsible for translating between Discord C++ and Godot C++.
#
# Most translation functions will follow the pattern:
#   discord_variable_to_godot_variable()
#   discord_optional_to_godot_variant()
#   discord_vector_to_godot_array()
#   godot_variable_to_discord_variable()
#   godot_variant_to_discord_optional()
#   godot_array_to_discord_vector()


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
