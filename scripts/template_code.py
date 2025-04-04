def lambda_(params: str, statements: str, signal_name: str, signal_params: str) -> str:
    return f"""[this]({params}) {{
        {statements}
        this->emit_signal("{signal_name}"{signal_params});
    }}"""


def signal_(signal_name: str, signal_params: str) -> str:
    return f"""
    ADD_SIGNAL(MethodInfo("{signal_name}"{signal_params}));
    """


def signal_property(param_type: str, param_name: str, param_type_name="") -> str:
    if param_type == "VARIANT::OBJECT":
        return f'PropertyInfo({param_type}, "{param_name}", PROPERTY_HINT_RESOURCE_TYPE, "{param_type_name}")'
    return f'PropertyInfo({param_type}, "{param_name}")'


def bind_(bind_params: str, class_name: str, method_snake_name: str) -> str:
    return f"""
    ClassDB::bind_method(D_METHOD({bind_params}),
            &Discord{class_name}::{method_snake_name});
    """


def include_(include: str) -> str:
    return f'#include "{include}"'


def signature_(return_type: str, method_snake_name: str, params: str) -> str:
    return f"    {return_type} {method_snake_name}({params});"


def call_(
    property_name: str,
    method_name: str,
    passing_params: str,
) -> str:
    return f"{property_name}->{method_name}({passing_params});"


def method_(
    return_type: str,
    class_name: str,
    method_snake_name: str,
    params: str,
    statements: str,
) -> str:
    return f"""
{return_type} Discord{class_name}::{method_snake_name}({params}) {{
    {statements}
}}
    """


#################### Before Call ####################
# Everything here is to be called BEFORE
# making the call to the wrapped function.
# Convert "Godot type" to "C type".
#####################################################


def string_from_godot_(variable_name: str, param_snake_name: str) -> str:
    return f"auto {variable_name} = {param_snake_name}.utf8().get_data();"


def enum_from_godot_(variable_name: str, enum_type: str, param_snake_name: str) -> str:
    return f"auto {variable_name} = (discordpp::{enum_type}){param_snake_name};"


def obj_from_godot_(variable_name: str, param_snake_name: str) -> str:
    return f"auto {variable_name} = *{param_snake_name}->unwrap();"


def dict_from_godot(variable_name: str, param_snake_name: str) -> str:
    return f"""auto {variable_name} = std::unordered_map<std::string, std::string>();

    for (auto p_{variable_name} : {param_snake_name}) {{
        {variable_name}[p_{variable_name}.key] = p_{variable_name}.value;
    }}
    """


def array_from_godot(variable_name: str) -> str:
    return f"""
    
    """


def variant_from_godot_(
    parameter_type: str,
    variable_name: str,
    param_snake_name: str,
    variant_type: str,
    variant_convertion: str,
) -> str:
    return f"""
    std::optional<{parameter_type}> {variable_name};

    if ({param_snake_name}.get_type() == {variant_type}) {{
        {variant_convertion}
    }}
    """


def variant_number_from_godot_(
    variable_name: str, variant_type: str, param_snake_name: str
) -> str:
    return f"{variable_name} = ({variant_type}){param_snake_name};"


def variant_string_from_godot_(variable_name: str, param_snake_name: str) -> str:
    return f"{variable_name} = {param_snake_name}.stringify().utf8().get_data();"


def variant_object_from_godot_(
    variable_name: str,
    variant_type: str,
    param_snake_name: str,
) -> str:
    return f"""
        auto t_{variable_name} = Object::cast_to<Discord{variant_type}>({param_snake_name});
        auto t2_{variable_name} = t_{variable_name}->unwrap();
        {variable_name} = std::optional<discordpp::{variant_type}>{{ *t2_{variable_name} }};
    """


#################### After Call ####################
# Everything here is to be called AFTER
# making the call to the wrapped function.
# Convert "C type" to "Godot type".
####################################################


def number_to_godot_(variable_name: str) -> str:
    return f"return {variable_name};"


def string_to_godot_(variable_name: str) -> str:
    return f"return String({variable_name}.c_str());"


def enum_to_godot_(return_type: str, variable_name: str) -> str:
    return f"return (Discord{return_type}::Enum){variable_name};"


def obj_to_godot_(variable_name: str, class_name: str) -> str:
    return f"""auto t_{variable_name} = (discordpp::{class_name} *)memalloc(sizeof(discordpp::{class_name}));
    *t_{variable_name} = {variable_name};
    return memnew(Discord{class_name}{{ t_{variable_name} }});
    """


def map_string_string_to_godot_(variable_name: str, typed_dict: str) -> str:
    return f"""auto t_{variable_name} = {typed_dict}();

    for (auto p_{variable_name} : {variable_name}) {{
        t_{variable_name}[String(p_{variable_name}.first.c_str())] = String(p_{variable_name}.second.c_str());
    }}
    
    return t_{variable_name};
    """


def vector_number_to_godot_(variable_name: str, typed_array: str) -> str:
    return f"""auto t_{variable_name} = {typed_array}();

    for (auto i_{variable_name} : {variable_name}) {{
        t_{variable_name}.push_back(i_{variable_name});
    }}

    return t_{variable_name};
    """


def vector_string_to_godot_(variable_name: str, typed_array: str) -> str:
    return f"""auto t_{variable_name} = {typed_array}();

    for (auto i_{variable_name} : {variable_name}) {{
        t_{variable_name}.push_back(String(i_{variable_name}.c_str()));
    }}

    return t_{variable_name};
    """


def vector_obj_to_godot_(variable_name: str, typed_array: str, class_name: str) -> str:
    return f"""auto t_{variable_name} = {typed_array}();

    for (auto i_{variable_name} : {variable_name}) {{
        t_{variable_name}.push_back(memnew(Discord{class_name}{{ {variable_name} }}));
    }}

    return t_{variable_name};
    """


def optional_to_godot_(variable_name: str) -> str:
    return f"""
    if (!{variable_name}.has_value()) {{
        return nullptr;
    }}
    """


def optional_number_to_variant_(variable_name: str) -> str:
    return f"return Variant({variable_name}.value());"


def optional_string_to_variant_(variable_name: str) -> str:
    return f"return Variant({variable_name}.value().c_str());"


def optional_enum_to_variant_(return_type: str, variable_name: str) -> str:
    return f"return Variant((Discord{return_type}::Enum){variable_name}.value());"


def optional_obj_to_godot_(variable_name: str, class_name: str) -> str:
    return f"""auto t_{variable_name} = (discordpp::{class_name} *)memalloc(sizeof(discordpp::{class_name}));
    *t_{variable_name} = {variable_name}.value();
    return Variant(memnew(Discord{class_name}{{ t_{variable_name} }}));
    """
