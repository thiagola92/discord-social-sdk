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
