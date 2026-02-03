def get_godot_variant(target: str, source: str, convertion: str) -> str:
    return f"""
Variant {target};

if (!{source}.has_value()) {{
    {target} = nullptr;
}} else {{
    auto {source}_v = {source}.value();
    {convertion}
    {target} = Variant({target}_v);
}}
"""

    #     f"{src.type.subtype.name} *t = memnew({src.type.subtype.name}(std::move({src.name}.value())));",
    #     f"{dest} = Variant(memnew({type_name}{{ t }}));",
    #     f"",
    # ]


#         {src.type.name} *t_{dest} = memnew({src.type.name}(std::move({src.name})));",
#         f"{name} *{dest} = memnew({name} {{ t_{dest} }});",
#         f"",
