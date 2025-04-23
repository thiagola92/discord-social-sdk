def get_callback_param(param_name: str, params: str) -> str:
    return f"""
				Where [param {param_name}] signature is:
				[codeblock]
				func({params})
				[/codeblock]
			"""
