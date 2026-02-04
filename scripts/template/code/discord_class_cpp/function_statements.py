def get_function_statements(
    conversion_statements: str,
    call_statement: str,
    return_statements: str,
) -> str:
    return f"""
{conversion_statements}
{call_statement}
{return_statements}
"""
