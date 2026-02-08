def get_return_statements(conversion: str, target: str) -> str:
    return f"""
{conversion}

return {target};
"""
