def get_callback_param(param_name: str, params: str, return_type: str) -> str:
    return f"""Parameter [param {param_name}] example:
[codeblock]
func({params}) -> {return_type}: pass
[/codeblock]
"""
