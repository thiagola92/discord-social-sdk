def get_godot_object(
    discord_type: str, godot_type: str, target: str, source: str
) -> str:
    return f"""
{discord_type} *{target}_t = memnew({discord_type}(std::move({source})));
{godot_type} *{target} = memnew({godot_type} {{ {target}_t }});
"""
