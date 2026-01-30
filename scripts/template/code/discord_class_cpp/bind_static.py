def get_bind_static(function: str, class_name: str, params: str) -> str:
    return f"""
	ClassDB::bind_static_method("Discord{class_name}", D_METHOD("{function}"{params}),
			&Discord{class_name}::{function});
"""
