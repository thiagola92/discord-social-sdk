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

#####################################################

TEMPLATE_SET_OPTIONAL_NUMBER = """

"""

TEMPLATE_SET_OPTIONAL_STRING = """

"""

TEMPLATE_SET_OPTIONAL_ENUM = """

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
