def get_discord_optional_object(
    godot_type: str, target: str, source: str, discord_type: str
) -> str:
    return f"""
{godot_type} *{target}_t = Object::cast_to<{godot_type}>({source});
{target} = std::optional<{discord_type}>{{ *{target}_t->unwrap() }};
"""
