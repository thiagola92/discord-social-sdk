def get_function_statements(
    convertion_statements: str,
    call_statement: str,
    return_statements: str,
) -> str:
    return f"""
{convertion_statements}
{call_statement}
{return_statements}
"""
