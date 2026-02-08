def get_discord_classes_h(classes_declarations: str, classes_definitions: str) -> str:
    return f"""
#ifndef DISCORD_CLASSES_H
#define DISCORD_CLASSES_H

#include "discord_enum.h"
#include "discordpp.h"
#include "godot_cpp/classes/node.hpp"
#include "godot_cpp/classes/ref_counted.hpp"
#include "godot_cpp/variant/typed_array.hpp"
#include "godot_cpp/variant/typed_dictionary.hpp"

namespace godot {{

// Declarations.
{classes_declarations}

// Definitions.
{classes_definitions}

}} //namespace godot

#endif
"""
