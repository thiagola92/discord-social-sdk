def get_runtime_macro(class_name: str) -> str:
    return f"GDREGISTER_CLASS(Discordpp{class_name});"
