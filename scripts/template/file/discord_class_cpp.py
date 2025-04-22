def get_discord_class_cpp(
    class_name: str,
    methods: str,
    binds: str,
) -> str:
    return f"""
#include "discordpp_classes.h"

using namespace godot;

{methods}

void Discordpp{class_name}::_bind_methods() {{
    {binds}
}}
"""
