TEMPLATE_BIND = """
	ClassDB::bind_method(D_METHOD("{method_snake_name}"),
			&Discord{class_name}::{method_snake_name});
"""
