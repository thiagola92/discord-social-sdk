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
from name import to_godot_class_name, to_gdscript_variable_name
from template.code.discord_class_cpp.translate.map import get_map
from template.code.discord_class_cpp.translate.optional import get_optional


def is_discord_void(type_info: TypeInfo) -> bool:
    return type_info.name in ["void"]


def is_discord_bool(type_info: TypeInfo) -> bool:
    return type_info.name in ["bool", "bool&", "bool &"]


def is_discord_int(type_info: TypeInfo) -> bool:
    return type_info.name in [
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


def is_discord_float(type_info: TypeInfo) -> bool:
    return type_info.name in ["float"]


def is_discord_string(type_info: TypeInfo) -> bool:
    return type_info.name in [
        "std::string",
        "std::string const",
        "static std::string",
        "std::string const &",
    ]


def is_discord_char_array(type_info: TypeInfo) -> bool:
    return type_info.name in ["const char *"]


def is_discord_enum(type_info: TypeInfo) -> bool:
    return type_info.enum


def is_discord_optional(type_info: TypeInfo) -> bool:
    return type_info.name.startswith("std::optional")


def is_discord_vector(type_info: TypeInfo) -> bool:
    return type_info.name.startswith("std::vector")


def is_discord_map(type_info: TypeInfo) -> bool:
    return type_info.name.startswith("std::unordered_map")


def is_discord_object(type_info: TypeInfo) -> bool:
    return type_info.name.startswith("discordpp::")


# Use it first because it removes the possibility
# of being FunctionInfo for the following checks.
def is_discord_function(info: TypeInfo | FunctionInfo) -> bool:
    return isinstance(info, FunctionInfo) or info.callback


######################################################################
# Translate Discord type to Godot type.
######################################################################


def discord_type_to_godot_type(info: TypeInfo | FunctionInfo) -> str:
    if is_discord_function(info):
        return "Callable"

    if is_discord_void(info):
        return "void"

    if is_discord_bool(info):
        return "bool"

    if is_discord_int(info):
        return "int64_t"

    if is_discord_float(info):
        return "float"

    if is_discord_string(info):
        return "String"

    if is_discord_char_array(info):
        return "String"

    if is_discord_enum(info):
        if info.fake:
            return "Variant"

        if info.overloading:
            return "int"

        return to_godot_class_name(info.name) + "::Enum"

    if is_discord_optional(info):
        return "Variant"

    if is_discord_vector(info):
        t = discord_type_to_godot_type(info.templates[0])
        return f"TypedArray<{t}>"

    if is_discord_map(info):
        t = [discord_type_to_godot_type(t) for t in info.templates]
        t = ",".join(t)
        return f"TypedDictionary<{t}>"

    if is_discord_object(info):
        return to_godot_class_name(info.name)

    assert False, f'Fail to identify a good type for "{info.name}"'


def discord_params_to_godot_params(params_info: list[ParamInfo]) -> str:
    params = []

    for p in params_info:
        t = discord_type_to_godot_type(p.type)
        t = f"{t} {p.gdscript_name}"

        params.append(t)

    params = ", ".join(params)

    return params


def discord_type_to_variant_type(info: TypeInfo | FunctionInfo) -> str:
    if isinstance(info, FunctionInfo):
        return "Variant::CALLABLE"

    if info.callback:
        return "Variant::CALLABLE"

    if is_discord_void(info):
        return "Variant::NIL"

    if is_discord_bool(info):
        return "Variant::BOOL"

    if is_discord_int(info):
        return "Variant::INT"

    if is_discord_float(info):
        return "Variant::FLOAT"

    if is_discord_string(info):
        return "Variant::STRING"

    if is_discord_char_array(info):
        return "Variant::STRING"

    if is_discord_vector(info):
        return "Variant::ARRAY"

    if is_discord_map(info):
        return "Variant::DICTIONARY"

    if is_discord_object(info):
        return "Variant::OBJECT"

    assert False, f'Fail to identify a good Variant type for "{info.name}"'


######################################################################
# Translate Godot type to Discord type.
######################################################################


def godot_variables_to_discord_variables(params_info: list[ParamInfo]) -> str:
    statements = ""

    for i, p in enumerate(params_info):
        n = to_gdscript_variable_name(p.name)
        statements += godot_variable_to_discord_variable(p.type, f"p{i}", n)

    return statements


def godot_variable_to_discord_variable(
    info: TypeInfo | FunctionInfo,
    target: str,
    source: str,
) -> str:
    if is_discord_function(info):
        return "\n// TODO callable"

    if is_discord_bool(info):
        return f"bool {target} = {source};"

    if is_discord_int(info):
        return f"int64_t {target} = {source};"

    if is_discord_float(info):
        return f"float {target} = {source};"

    if is_discord_string(info):
        return f"std::string {target} = std::string({source}.utf8().get_data());"

    if is_discord_char_array(info):
        return f"std::string {target} = std::string({source}.utf8().get_data());"

    if is_discord_enum(info):
        return f"{info.name} {target} = ({info.name}){source};"

    if is_discord_optional(info):
        return godot_variant_to_discord_optional(info, source, target)

    if is_discord_vector(info):
        return "\n// TODO vect"

    if is_discord_map(info):
        return godot_dictionary_to_discord_map(info, source, target)

    if is_discord_object(info):
        return "\n// TODO object"

    return "\n// TODO"


def godot_variant_to_discord_optional(
    type_info: TypeInfo,
    source: str,
    target: str,
) -> str:
    for t in type_info.templates:
        v = discord_type_to_variant_type(t)
        s = godot_variant_to_discord_variable(t, source, target)

        # Leave because std::optional will never have more than one template.
        return get_optional(
            template=t.name,
            target=target,
            source=source,
            variant=v,
            statements=s,
        )

    pprint(type_info)
    assert False, "An std::optional is missing it template"


def godot_variant_to_discord_variable(type_info: TypeInfo, source: str, target: str):
    statements = []

    if isinstance(type_info, FunctionInfo):
        assert False, "Not implemented (implement if needed)"
    elif is_discord_bool(type_info):
        statements = [f"{target} = {source};"]
    elif is_discord_int(type_info):
        statements = [f"{target} = {source};"]
    elif is_discord_float(type_info):
        statements = [f"{target} = {source};"]
    elif is_discord_string(type_info):
        statements = [f"{target} = {source}.stringify().utf8().get_data();"]
    elif is_discord_char_array(type_info):
        statements = [f"{target} = {source}.stringify().utf8().get_data();"]
    elif is_discord_enum(type_info):
        statements = [
            f"{target} = std::optional<{type_info.name}>{{ ({type_info.name})(uint64_t){source} }};"
        ]
    elif is_discord_vector(type_info):
        assert False, "Not implemented (implement if needed)"
    elif is_discord_map(type_info):
        assert False, "Not implemented (implement if needed)"
    elif is_discord_optional(type_info):
        assert False, "Not implemented (implement if needed)"

    statements = "\n".join(statements)

    return statements


def godot_dictionary_to_discord_map(
    type_info: TypeInfo,
    source: str,
    target: str,
) -> str:
    # Maps always have two templates.
    template1 = type_info.templates[0]
    template2 = type_info.templates[1]
    statements = godot_variant_to_discord_variable(template1, "k", "kv")
    statements += godot_variant_to_discord_variable(template2, "v", "vv")

    return get_map(
        template1=template1.name,
        template2=template2.name,
        target=target,
        source=source,
        statements=statements,
    )
