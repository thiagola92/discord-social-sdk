def get_godot_array(typed_array: str, target: str, source: str, convertion: str) -> str:
    return f"""
{typed_array} {target} = {typed_array}();

for (auto i : {source}) {{
    {convertion}
    {target}.push_back({target}_t);
}}
"""
