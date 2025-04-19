def get_function_declaration(modifier: str, ret: str, name: str, params: str) -> str:
    return f"{modifier}{ret} {name}({params});"
