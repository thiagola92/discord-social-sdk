TEMPLATE_CPP_1 = """#include "{filename_h}"

using namespace godot;

discordpp::{class_name} *Discord{class_name}::unwrap() {{
	return &{property_name};
}}
{methods}
void Discord{class_name}::_bind_methods() {{
    {binds}
}}

Discord{class_name}::Discord{class_name}() {{}}

Discord{class_name}::~Discord{class_name}() {{}}
"""

#####################################################

TEMPLATE_CPP_2 = """#include "{filename_h}"

using namespace godot;

discordpp::{class_name} *Discord{class_name}::unwrap() {{
	return {property_name};
}}
{methods}
void Discord{class_name}::_bind_methods() {{
    {binds}
}}

Discord{class_name}::Discord{class_name}() {{}}

Discord{class_name}::Discord{class_name}(discordpp::{class_name} *{property_name}) {{
    this->{property_name} = {property_name};
}}

Discord{class_name}::~Discord{class_name}() {{}}
"""

#####################################################


def get_source_template(is_property_pointer: bool) -> str:
    if is_property_pointer:
        return TEMPLATE_CPP_2
    return TEMPLATE_CPP_1
