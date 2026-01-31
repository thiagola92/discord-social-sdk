def get_optional(
    target_type: str,
    target: str,
    source: str,
    source_variant: str,
    statements: str,
) -> str:
    return f"""
std::optional<{target_type}> {target};

if ({source}.get_type() == {source_variant}) {{"
    {statements}
}}
"""
