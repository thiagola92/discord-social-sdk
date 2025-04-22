def get_method(
    ret: str,
    class_name: str,
    method: str,
    params: str,
    statements: str,
) -> str:
    return f"""
{ret} Discordpp{class_name}::{method}({params}) {{
    {statements}
}}
"""
