def get_discord_callback(
    target: str,
    source: str,
    callback_params: str,
    conversions: str,
    call_params: str,
) -> str:
    return f"""
auto {target} = [{source}]({callback_params}) {{
    {conversions}
    {source}.call({call_params});
}};
"""
