def get_godot_dictionary(
    typed_dictionary: str,
    target: str,
    source: str,
    convertion: str,
) -> str:
    return f"""
{typed_dictionary} {target} = {typed_dictionary}();

for (auto i : {source}) {{
    {convertion}
    {target}[k] = v;
}}
"""
