from parser import Method

#####################################################

TEMPLATE_GET_INT = """
{return_type} Discord{class_name}::get_{method_snake_name}() {{
    return {property_name}{operator}{method_name}();
}}
"""

TEMPLATE_GET_STRING = """
String Discord{class_name}::{method_snake_name}() {{
    return String({property_name}{operator}{method_name}().c_str());
}}
"""

TEMPLATE_GET_ENUM = """
Discord{return_type}::Enum Discord{class_name}::{method_snake_name}() {{
    return (Discord{return_type}::Enum){property_name}{operator}{method_name}();
}}
"""

TEMPLATE_GET_OBJ = """
// IMPLEMENT TEMPLATE_GET_OBJ
"""

#####################################################

TEMPLATE_GET_OPTIONAL_INT = """
Variant Discord{class_name}::{method_snake_name}() {{
    auto {method_snake_name} = {property_name}{operator}{method_name}();

    if ({method_snake_name}.has_value()) {{
        return Variant({method_snake_name}.value());
    }}

    return nullptr;
}}
"""

TEMPLATE_GET_OPTIONAL_STRING = """
Variant Discord{class_name}::{method_snake_name}() {{
    auto {method_snake_name} = {property_name}{operator}{method_name}();

    if ({method_snake_name}.has_value()) {{
        return Variant({method_snake_name}.value().c_str());
    }}

    return nullptr;
}}
"""

TEMPLATE_GET_OPTIONAL_ENUM = """
Variant Discord{class_name}::{method_snake_name}() {{
    auto {method_snake_name} = {property_name}{operator}{method_name}();

    if ({method_snake_name}.has_value()) {{
        return Variant((Discord{return_type}::Enum){method_snake_name}.value());
    }}

    return nullptr;
}}
"""

TEMPLATE_GET_OPTIONAL_OBJ = """
// IMPLEMENT TEMPLATE_GET_OPTIONAL_OBJ
"""

#####################################################


def get_get_template(method: Method) -> str:
    if method.ret.is_opt:
        if method.ret.is_enum:
            return TEMPLATE_GET_OPTIONAL_ENUM

        if method.ret.is_discord:
            return TEMPLATE_GET_OPTIONAL_OBJ

        if method.ret.name == "std::string":
            return TEMPLATE_GET_OPTIONAL_STRING

        if method.ret.name in ["int64_t", "uint64_t", "int32_t", "int32_t"]:
            return TEMPLATE_GET_OPTIONAL_INT

        return f"// IMPLEMENT GET OPTIONAL FOR {method.ret.name}"

    if method.ret.is_enum:
        return TEMPLATE_GET_ENUM

    if method.ret.is_discord:
        return TEMPLATE_GET_OBJ

    if method.ret.name == "std::string":
        return TEMPLATE_GET_STRING

    if method.ret.name in ["int64_t", "uint64_t", "int32_t", "int32_t"]:
        return TEMPLATE_GET_INT

    return f"// IMPLEMENT GET FOR {method.ret.name}"
