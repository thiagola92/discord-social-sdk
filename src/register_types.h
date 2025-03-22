#ifndef DISCORDGDEXTENSION_REGISTER_TYPES_H
#define DISCORDGDEXTENSION_REGISTER_TYPES_H

#define DISCORDPP_IMPLEMENTATION

#include <godot_cpp/core/class_db.hpp>

using namespace godot;

void initialize_module(ModuleInitializationLevel p_level);
void uninitialize_module(ModuleInitializationLevel p_level);

#endif // DISCORDGDEXTENSION_REGISTER_TYPES_H