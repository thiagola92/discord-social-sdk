def get_runtime_macro(class_name: str) -> str:
    return f"GDREGISTER_RUNTIME_CLASS(Discordpp{class_name});"
