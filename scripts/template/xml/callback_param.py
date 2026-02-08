def get_callback_param(param_name: str, params: str) -> str:
    return f"""Parameter [param {param_name}] signature:
[codeblock]
func({params})
[/codeblock]
"""
