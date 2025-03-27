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

TEMPLATE_SET_OPTIONAL_INT = """
void Discord{class_name}::{method_snake_name}(Variant {parameter_name}) {{
	if ({parameter_name}.get_type() == Variant::INT) {{
		{property_name}{operator}{method_name}({{ {parameter_name}.value() }});
		return;
	}}

	{property_name}{operator}{method_name}({{}});
}}
"""

TEMPLATE_SET_OPTIONAL_FLOAT = """
void Discord{class_name}::{method_snake_name}(Variant {parameter_name}) {{
	if ({parameter_name}.get_type() == Variant::FLOAT) {{
		{property_name}{operator}{method_name}({{ {parameter_name}.value() }});
		return;
	}}

	{property_name}{operator}{method_name}({{}});
}}
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

        if method.params[0].type.is_discord:
            return TEMPLATE_SET_OPTIONAL_OBJ

        if method.params[0].type.name == "std::string":
            return TEMPLATE_SET_OPTIONAL_STRING

        if method.params[0].type.name in ["int64_t", "uint64_t", "int32_t", "int32_t"]:
            return TEMPLATE_SET_OPTIONAL_INT

        return f"// IMPLEMENT SET OPTIONAL FOR {method.params[0].type.name}"

    if method.params[0].type.is_enum:
        return TEMPLATE_SET_ENUM

    if method.params[0].type.is_discord:
        return TEMPLATE_SET_OPTIONAL_OBJ

    if method.params[0].type.name == "std::string":
        return TEMPLATE_SET_STRING

    if method.params[0].type.name in ["int64_t", "uint64_t", "int32_t", "int32_t"]:
        return TEMPLATE_SET_NUMBER

    return f"// IMPLEMENT SET FOR {method.params[0].type.name}"
