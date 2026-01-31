def get_optional(
    templates: str,
    target: str,
    source: str,
    variant: str,
    statements: str,
) -> str:
    return f"""
std::optional<{templates}> {target};

if ({source}.get_type() == {variant}) {{
    {statements}
}}
"""
