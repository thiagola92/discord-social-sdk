def get_variant_param(param_name: str, type_name: str) -> str:
    return f"""Parameter [param {param_name}] can be {type_name} or [code]null[/code].
"""
