def get_bind_method(function: str, class_name: str, params: str) -> str:
    return f"""
	ClassDB::bind_method(D_METHOD("{function}"{params}),
			&Discord{class_name}::{function});
"""
