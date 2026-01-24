def get_constructor(class_name: str) -> str:
    return f"""Discord{class_name}() {{
        this->obj = memnew(discordpp::{class_name});
    }}
"""


def get_constructor_empty(class_name: str) -> str:
    return f"""Discord{class_name}() {{}}"""
