def get_discord_optional(
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
}} else if ({source}.get_type() != Variant::NIL) {{
    ERR_PRINT("Invalid type passed as argument");
}}
"""
