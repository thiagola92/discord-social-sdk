def get_method_bind(method: str, class_name: str, params: str) -> str:
    return f"""
	ClassDB::bind_method(D_METHOD("{method}"{params}),
			&Discordpp{class_name}::{method});
"""
