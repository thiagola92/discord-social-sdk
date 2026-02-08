def get_discord_optional_enum(target: str, template: str, source: str) -> str:
    return f"{target} = std::optional<{template}>{{ ({template})(uint64_t){source} }};"
