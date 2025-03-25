get_int32_template = """
int32_t Discord{class_name}::get_{method_snake_name}() {{
    return {property_name}{operator}{method_name}();
}}
"""

get_uint64_template = """
uint64_t Discord{class_name}::get_{method_snake_name}() {{
    return {property_name}{operator}{method_name}();
}}
"""

get_string_template = """
String Discord{class_name}::get_{method_snake_name}() {{
    return String({property_name}{operator}{method_name}().c_str());
}}
"""

get_enum_template = """
Discord{return_type}::Enum Discord{class_name}::get_{method_snake_name}() {{
    return (Discord{return_type}::Enum){property_name}{operator}{method_name}();
}}
"""

##### Optional return #####

get_optional_int32_template = """
Variant Discord{class_name}::get_{method_snake_name}() {{
    auto {method_snake_name} = {property_name}{operator}{method_name}();

    if ({method_snake_name}.has_value()) {{
        return Variant({method_snake_name}.value());
    }}

    return nullptr;
}}
"""

get_optional_uint64_template = get_optional_int32_template

get_optional_string_template = """
Variant Discord{class_name}::get_{method_snake_name}() {{
    auto {method_snake_name} = {property_name}{operator}{method_name}();

    if ({method_snake_name}.has_value()) {{
        return Variant({method_snake_name}.value().c_str());
    }}

    return nullptr;
}}
"""

get_optional_enum_template = """
Variant Discord{class_name}::get_{method_snake_name}() {{
    auto {method_snake_name} = {property_name}{operator}{method_name}();

    if ({method_snake_name}.has_value()) {{
        return Variant((Discord{return_type}::Enum){method_snake_name}.value());
    }}

    return nullptr;
}}
"""
