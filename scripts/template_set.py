set_int32_template = """
void Discord{class_name}::{method_snake_name}(int32_t {parameter_name}) {{
    {property_name}{operator}{method_name}({parameter_name});
}}
"""

set_uint64_template = """
void Discord{class_name}::{method_snake_name}(uint64_t {parameter_name}) {{
    {property_name}{operator}{method_name}({parameter_name});
}}
"""

set_string_template = """
void Discord{class_name}::{method_snake_name}(String {parameter_name}) {{
    {property_name}{operator}{method_name}({parameter_name}.utf8().get_data());
}}
"""

set_enum_template = """
void Discord{class_name}::{method_snake_name}(Discord{parameter_type}::Enum {parameter_name}) {{
    {property_name}{operator}{method_name}((discordp::{parameter_type}){parameter_name});
}}
"""

##### Optional return #####

set_optional_int32_template = """
Variant Discord{class_name}::{method_snake_name}() {{
    auto {method_snake_name} = {property_name}{operator}{method_name}();

    if ({method_snake_name}.has_value()) {{
        return Variant({method_snake_name}.value());
    }}

    return nullptr;
}}
"""

set_optional_uint64_template = set_optional_int32_template

set_optional_string_template = """
Variant Discord{class_name}::{method_snake_name}() {{
    auto {method_snake_name} = {property_name}{operator}{method_name}();

    if ({method_snake_name}.has_value()) {{
        return Variant({method_snake_name}.value().c_str());
    }}

    return nullptr;
}}
"""

set_optional_enum_template = """
Variant Discord{class_name}::{method_snake_name}() {{
    auto {method_snake_name} = {property_name}{operator}{method_name}();

    if ({method_snake_name}.has_value()) {{
        return Variant((Discord{return_type}::Enum){method_snake_name}.value());
    }}

    return nullptr;
}}
"""
