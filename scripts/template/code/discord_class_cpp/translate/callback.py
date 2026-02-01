def get_callback(target: str, source: str, params: str, statements: str) -> str:
    return f"""
auto {target} = [{source}]({params}) {{
    {statements}
}};
"""
