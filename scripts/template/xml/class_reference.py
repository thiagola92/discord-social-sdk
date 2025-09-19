def get_class_reference(class_name: str, docstring: str) -> str:
    return f"""
{docstring}

Reference: [url]https://discord.com/developers/docs/social-sdk/classdiscordpp_1_1{class_name}.html[/url]
"""
