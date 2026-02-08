def get_function_definition(
    ret: str,
    class_name: str,
    function: str,
    params: str,
    statements: str,
) -> str:
    return f"""
{ret} Discord{class_name}::{function}({params}) {{
    {statements}
}}
"""
