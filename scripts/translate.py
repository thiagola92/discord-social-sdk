# Responsible for translating between Discord C++ and Godot C++.
#
# Most translation functions will follow the pattern:
#   discord_type_to_godot_type()
#   discord_optional_to_godot_variant()
#   discord_vector_to_godot_array()
#   godot_type_to_discord_type()
#   godot_variant_to_discord_optional()
#   godot_array_to_discord_vector()
from data import TypeInfo, FunctionInfo, ParamInfo
from name import to_gdscript_class_name, to_gdscript_variable_name
from template.code.discord_class_cpp.discord_to_godot.object import get_godot_object
from template.code.discord_class_cpp.discord_to_godot.variant import get_godot_variant
from template.code.discord_class_cpp.discord_to_godot.array import get_godot_array
from template.code.discord_class_cpp.discord_to_godot.dictionary import (
    get_godot_dictionary,
)
from template.code.discord_class_cpp.godot_to_discord.map import get_discord_map
from template.code.discord_class_cpp.godot_to_discord.optional import (
    get_discord_optional,
)
from template.code.discord_class_cpp.godot_to_discord.optional_enum import (
    get_discord_optional_enum,
)
from template.code.discord_class_cpp.godot_to_discord.optional_object import (
    get_discord_optional_object,
)
from template.code.discord_class_cpp.godot_to_discord.callback import (
    get_discord_callback,
)


def is_discord_void(type_info: TypeInfo) -> bool:
    return type_info.name in ["void"]


def is_discord_bool(type_info: TypeInfo) -> bool:
    return type_info.name in ["bool", "bool&", "bool &"]


def is_discord_int(type_info: TypeInfo) -> bool:
    return type_info.name in [
        "uint8_t",
        "int16_t",
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
def is_discord_function(info: TypeInfo) -> bool:
    return info.callback or info.name.startswith("std::function")


######################################################################
# Translate Discord type to Godot type.
######################################################################


def discord_type_to_godot_type(
    info: TypeInfo | FunctionInfo,
    pointer: bool = True,
) -> str:
    if isinstance(info, FunctionInfo):
        return "Callable"

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
            return "int64_t"

        if info.overloading:
            return "int64_t"

        return to_gdscript_class_name(info.name) + "::Enum"

    if is_discord_optional(info):
        return "Variant"

    if is_discord_vector(info):
        t = discord_type_to_godot_type(info.templates[0], False)
        return f"TypedArray<{t}>"

    if is_discord_map(info):
        t = [discord_type_to_godot_type(t, False) for t in info.templates]
        t = ",".join(t)
        return f"TypedDictionary<{t}>"

    if is_discord_object(info):
        if pointer:
            return to_gdscript_class_name(info.name) + " *"
        return to_gdscript_class_name(info.name)

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


def discord_variables_to_godot_variables(
    params_info: list[ParamInfo],
    skip: int = 0,
) -> str:
    statements = []

    for i, p in enumerate(params_info, skip):
        n = to_gdscript_variable_name(p.name)
        statements.append(discord_variable_to_godot_variable(p.type, f"p{i}", n))

    statements = "\n".join(statements)

    return statements


def discord_variable_to_godot_variable(
    info: TypeInfo | FunctionInfo,
    target: str,
    source: str,
) -> str:
    if isinstance(info, FunctionInfo):
        return False, f"Not implemented for {info.name} (implement if needed)"

    if is_discord_function(info):
        return False, f"Not implemented for {info.name} (implement if needed)"

    if is_discord_bool(info):
        return f"bool {target} = {source};"

    if is_discord_int(info):
        return f"int64_t {target} = (int64_t){source};"

    if is_discord_float(info):
        return f"float {target} = (float){source};"

    if is_discord_string(info):
        return f"String {target} = String({source}.c_str());"

    if is_discord_char_array(info):
        return f"String {target} = String({source});"

    if is_discord_enum(info):
        if info.fake:
            return f"int64_t {target} = {source};"

        name = to_gdscript_class_name(info.name) + "::Enum"
        return f"{name} {target} = ({name}){source};"

    if is_discord_optional(info):
        return discord_optional_to_godot_variant(info.templates[0], target, source)

    if is_discord_vector(info):
        return discord_vector_to_godot_array(info, target, source)

    if is_discord_map(info):
        return discord_map_to_godot_dictionary(info, target, source)

    if is_discord_object(info):
        return discord_object_to_godot_object(info, target, source)

    assert False, f"Not implemented for {info.name} (implement if needed)"


def discord_optional_to_godot_variant(
    type_info: TypeInfo, target: str, source: str
) -> str:
    conversion = discord_variable_to_godot_variable(
        type_info,
        f"{target}_v",
        f"{source}_v",
    )

    return get_godot_variant(
        target=target,
        source=source,
        conversion=conversion,
    )


def discord_vector_to_godot_array(type_info: TypeInfo, target: str, source: str) -> str:
    typed_array = discord_type_to_godot_type(type_info)
    conversion = discord_variable_to_godot_variable(
        type_info.templates[0],
        f"{target}_t",
        "i",
    )

    return get_godot_array(
        typed_array=typed_array,
        target=target,
        source=source,
        conversion=conversion,
    )


def discord_map_to_godot_dictionary(
    type_info: TypeInfo, target: str, source: str
) -> str:
    typed_dictionary = discord_type_to_godot_type(type_info)
    conversions = [
        discord_variable_to_godot_variable(
            type_info.templates[0],
            "k",
            "i.first",
        ),
        discord_variable_to_godot_variable(
            type_info.templates[1],
            "v",
            "i.second",
        ),
    ]

    conversions = "\n".join(conversions)

    return get_godot_dictionary(
        typed_dictionary=typed_dictionary,
        target=target,
        source=source,
        conversion=conversions,
    )


def discord_object_to_godot_object(
    type_info: TypeInfo, target: str, source: str
) -> str:
    godot_name = to_gdscript_class_name(type_info.name)

    return get_godot_object(
        discord_type=type_info.name,
        godot_type=godot_name,
        target=target,
        source=source,
    )


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
    if isinstance(info, FunctionInfo):
        return False, f"Not implemented for {info.name} (implement if needed)"

    if is_discord_function(info):
        return godot_callable_to_discord_callback(info, source, target)

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
        return godot_array_to_discord_vector(info, source, target)

    if is_discord_map(info):
        return godot_dictionary_to_discord_map(
            info.templates[0],
            info.templates[1],
            source,
            target,
        )

    if is_discord_object(info):
        return f"{info.name} {target} = *{source}->unwrap();"

    assert False, f"Not implemented for {info.name} (implement if needed)"


def godot_callable_to_discord_callback(
    type_info: TypeInfo,
    source: str,
    target: str,
) -> str:
    if not type_info.callback:
        assert False, f"Not implemented for {type_info.name} (implement if needed)"

    # Complicate, use pprint() to better understand.
    function_info = type_info.callback_ref.type.templates[0]

    conversions = discord_variables_to_godot_variables(function_info.params)
    callback_params = []
    call_params = []

    for i, p in enumerate(function_info.params):
        callback_params.append(f"auto {p.gdscript_name}")
        call_params.append(f"p{i}")

    callback_params = ", ".join(callback_params)
    call_params = ", ".join(call_params)

    return get_discord_callback(
        target=target,
        source=source,
        callback_params=callback_params,
        conversions=conversions,
        call_params=call_params,
    )


def godot_variant_to_discord_optional(
    type_info: TypeInfo, source: str, target: str
) -> str:
    for t in type_info.templates:
        v = discord_type_to_variant_type(t)
        s = godot_variant_to_discord_variable(t, source, target)

        # Leave because std::optional will never have more than one template.
        return get_discord_optional(
            template=t.name,
            target=target,
            source=source,
            variant=v,
            statements=s,
        )

    assert False, "An std::optional is missing it template"


def godot_variant_to_discord_variable(type_info: TypeInfo, source: str, target: str):
    if isinstance(type_info, FunctionInfo):
        assert False, "Not implemented (implement if needed)"

    if is_discord_bool(type_info):
        return f"{target} = {source};"

    if is_discord_int(type_info):
        return f"{target} = {source};"

    if is_discord_float(type_info):
        return f"{target} = {source};"

    if is_discord_string(type_info):
        return f"{target} = {source}.stringify().utf8().get_data();"

    if is_discord_char_array(type_info):
        return f"{target} = {source}.stringify().utf8().get_data();"

    if is_discord_enum(type_info):
        return get_discord_optional_enum(
            target=target,
            template=type_info.name,
            source=source,
        )

    if is_discord_vector(type_info):
        assert False, "Not implemented (implement if needed)"

    if is_discord_map(type_info):
        assert False, "Not implemented (implement if needed)"

    if is_discord_optional(type_info):
        assert False, "Not implemented (implement if needed)"

    if is_discord_object(type_info):
        n = to_gdscript_class_name(type_info.name)

        return get_discord_optional_object(
            godot_type=n,
            target=target,
            source=source,
            discord_type=type_info.name,
        )

    assert False, f"Not implemented for {type_info.name} (implement if needed)"


def godot_array_to_discord_vector(type_info: TypeInfo, source: str, target: str) -> str:
    assert False, "Not implemented (implement if needed)"


def godot_dictionary_to_discord_map(
    key_info: TypeInfo,
    value_info: TypeInfo,
    source: str,
    target: str,
) -> str:
    statements = godot_variant_to_discord_variable(key_info, "k", "kv")
    statements += godot_variant_to_discord_variable(value_info, "v", "vv")

    return get_discord_map(
        template1=key_info.name,
        template2=value_info.name,
        target=target,
        source=source,
        statements=statements,
    )


######################################################################
# Translate Discord type to GDScript type (not Godot C++).
######################################################################


def discord_type_to_gdscript_type(info: TypeInfo | FunctionInfo) -> str:
    if isinstance(info, FunctionInfo):
        return "Callable"

    if is_discord_function(info):
        return "Callable"

    if is_discord_void(info):
        return "void"

    if is_discord_bool(info):
        return "bool"

    if is_discord_int(info):
        return "int"

    if is_discord_float(info):
        return "float"

    if is_discord_string(info):
        return "String"

    if is_discord_char_array(info):
        return "String"

    if is_discord_enum(info):
        if info.fake:
            return "int"

        if info.overloading:
            return "int"

        return to_gdscript_class_name(info.name) + ".Enum"

    if is_discord_optional(info):
        return "Variant"

    if is_discord_vector(info):
        t = discord_type_to_godot_type(info.templates[0], False)
        return f"Array[{t}]"

    if is_discord_map(info):
        t = [discord_type_to_godot_type(t, False) for t in info.templates]
        t = ",".join(t)
        return f"Dictionary[{t}]"

    if is_discord_object(info):
        return to_gdscript_class_name(info.name)

    assert False, f'Fail to identify a good type for "{info.name}"'
