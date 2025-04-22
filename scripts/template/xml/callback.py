def get_callback(param_name: str, params: str) -> str:
    return f"""
				Where [code]{param_name}[/code] signature is:
				[codeblock]
				func({params})
				[/codeblock]
			"""
