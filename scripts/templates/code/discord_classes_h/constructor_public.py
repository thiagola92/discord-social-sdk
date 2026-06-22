def get_constructor_public(class_name: str) -> str:
    return f"""Discord{class_name}() {{
        this->obj = memnew(discordpp::{class_name});
    }}
"""
