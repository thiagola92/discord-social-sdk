def get_discord_class_cpp(
    class_name: str,
    functions: str,
    overloadings: str,
    binds: str,
) -> str:
    return f"""
#include "discord_classes.h"

using namespace godot;

// Functions.
{functions}

// Overload functions.
{overloadings}

// Binding.
void Discord{class_name}::_bind_methods() {{
    {binds}
}}
"""
