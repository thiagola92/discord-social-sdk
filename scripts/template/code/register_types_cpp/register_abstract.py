def get_abstract_macro(enum_name: str) -> str:
    return f"GDREGISTER_ABSTRACT_CLASS(Discordpp{enum_name});"
