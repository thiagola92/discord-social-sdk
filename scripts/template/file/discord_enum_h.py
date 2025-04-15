def get_discord_enum_h(enums: str, casts: str) -> str:
    return f"""
#ifndef DISCORD_ENUM_H
#define DISCORD_ENUM_H

#include "godot_cpp/classes/ref_counted.hpp"
#include "godot_cpp/classes/wrapped.hpp"
#include "godot_cpp/core/binder_common.hpp"
#include "godot_cpp/core/class_db.hpp"

namespace godot {{

{enums}

}} // namespace godot

// Needed so we can bind functions.
{casts}

#endif
"""
