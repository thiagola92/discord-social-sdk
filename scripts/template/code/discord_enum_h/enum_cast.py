def get_enum_cast(enum_name: str) -> str:
    return f"VARIANT_ENUM_CAST(Discord{enum_name}::Enum);"
