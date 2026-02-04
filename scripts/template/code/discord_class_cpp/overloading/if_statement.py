def get_if_statement(condition: str, statements: str) -> str:
    return f"""
if ({condition}) {{
    {statements}
}}
"""
