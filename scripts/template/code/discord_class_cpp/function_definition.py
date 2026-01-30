def get_function_definition(
    ret: str,
    class_name: str,
    method: str,
    params: str,
    statements: str,
) -> str:
    return f"""
{ret} Discord{class_name}::{method}({params}) {{
    {statements}
}}
"""
