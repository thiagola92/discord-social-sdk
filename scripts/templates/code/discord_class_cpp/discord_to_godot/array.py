def get_godot_array(typed_array: str, target: str, source: str, conversion: str) -> str:
    return f"""
{typed_array} {target} = {typed_array}();

for (auto i : {source}) {{
    {conversion}
    {target}.push_back({target}_t);
}}
"""


def get_godot_pointer(class_name: str, target: str, source: str, size: str) -> str:
    return f"""{class_name} *{target} = memnew({class_name}({source}, {size}));"""
