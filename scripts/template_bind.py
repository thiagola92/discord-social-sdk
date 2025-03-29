from parser import Method

#####################################################

TEMPLATE_BIND_GET = """
	ClassDB::bind_method(D_METHOD("{method_snake_name}"),
			&Discord{class_name}::{method_snake_name});
"""

TEMPLATE_BIND_SET = """
	ClassDB::bind_method(D_METHOD("{method_snake_name}", "{parameter_name}"),
			&Discord{class_name}::{method_snake_name});
"""

TEMPLATE_BIND = """
	ClassDB::bind_method(D_METHOD({bind_params}),
			&Discord{class_name}::{method_snake_name});
"""

#####################################################


def get_bind_template(method: Method) -> str:
    if method.is_setter:
        return TEMPLATE_BIND_SET
    return TEMPLATE_BIND_GET
