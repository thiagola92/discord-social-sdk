def get_optional(
    template: str,
    target: str,
    source: str,
    variant: str,
    statements: str,
) -> str:
    return f"""
std::optional<{template}> {target};

if ({source}.get_type() == {variant}) {{
    {statements}
}}
"""
