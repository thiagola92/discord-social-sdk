def get_godot_dictionary(
    typed_dictionary: str,
    target: str,
    source: str,
    conversion: str,
) -> str:
    return f"""
{typed_dictionary} {target} = {typed_dictionary}();

for (auto i : {source}) {{
    {conversion}
    {target}[k] = v;
}}
"""
