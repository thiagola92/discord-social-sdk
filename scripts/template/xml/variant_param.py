def get_variant_param(param_name: str, type_name: str) -> str:
    return f"""\tWhere [param {param_name}] is {type_name} or [code]null[/code].
			"""
