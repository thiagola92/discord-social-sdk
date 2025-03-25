source_template = """#include "{filename_h}"

using namespace godot;

discordpp::{class_name} *Discord{class_name}::unwrap() {{
	return &{property_name};
}}

void Discord{class_name}::_bind_methods() {{
    //
}}

Discord{class_name}::Discord{class_name}() {{}}

Discord{class_name}::~Discord{class_name}() {{}}
"""

source_template2 = """#include "{filename_h}"

using namespace godot;

discordpp::{class_name} *Discord{class_name}::unwrap() {{
	return {property_name};
}}

void Discord{class_name}::_bind_methods() {{
    //
}}

Discord{class_name}::Discord{class_name}() {{}}

Discord{class_name}::Discord{class_name}(discordpp::{class_name} *{property_name}) {{
    this->{property_name} = {property_name};
}}

Discord{class_name}::~Discord{class_name}() {{}}
"""
