from parser import Method

#####################################################

TEMPLATE_SET_NUMBER = """
void Discord{class_name}::{method_snake_name}({parameter_type} {parameter_name}) {{
    {property_name}{operator}{method_name}({parameter_name});
}}
"""

TEMPLATE_SET_STRING = """
void Discord{class_name}::{method_snake_name}(String {parameter_name}) {{
    {property_name}{operator}{method_name}({parameter_name}.utf8().get_data());
}}
"""

TEMPLATE_SET_ENUM = """
void Discord{class_name}::{method_snake_name}(Discord{parameter_type}::Enum {parameter_name}) {{
    {property_name}{operator}{method_name}((discordpp::{parameter_type}){parameter_name});
}}
"""

TEMPLATE_SET_OBJ = """
// IMPLEMENT TEMPLATE_SET_OBJ
"""

#####################################################

TEMPLATE_SET_OPTIONAL_NUMBER = """
// IMPLEMENT TEMPLATE_SET_OPTIONAL_NUMBER
"""

TEMPLATE_SET_OPTIONAL_STRING = """
void Discord{class_name}::{method_snake_name}(Variant {parameter_name}) {{
	if ({parameter_name}.get_type() == Variant::STRING) {{
		{property_name}{operator}{method_name}({{ {parameter_name}.stringify().utf8().get_data() }});
		return;
	}}

	{property_name}{operator}{method_name}({{}});
}}
"""

TEMPLATE_SET_OPTIONAL_ENUM = """
// IMPLEMENT TEMPLATE_SET_OPTIONAL_ENUM
"""

TEMPLATE_SET_OPTIONAL_OBJ = """
void Discord{class_name}::{method_snake_name}(Variant {parameter_name}) {{
	if ({parameter_name}.get_type() == Variant::OBJECT) {{
		auto dacc = Object::cast_to<Discord{parameter_type}>({parameter_name});
		auto acc = dacc->unwrap();
		{property_name}{operator}{method_name}(std::optional<discordpp::{parameter_type}>{{ *acc }});
		return;
	}}

	{property_name}{operator}{method_name}({{}});
}}
"""

#####################################################


def get_set_template(method: Method) -> str:
    if method.params[0].type.is_opt:
        if method.params[0].type.is_enum:
            return TEMPLATE_SET_OPTIONAL_ENUM

        if method.params[0].type.name == "std::string":
            return TEMPLATE_SET_OPTIONAL_STRING

        return TEMPLATE_SET_OPTIONAL_NUMBER

    if method.params[0].type.is_enum:
        return TEMPLATE_SET_ENUM

    if method.params[0].type.name == "std::string":
        return TEMPLATE_SET_STRING

    return TEMPLATE_SET_NUMBER
