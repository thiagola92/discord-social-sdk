
#include "discord_classes.h"

using namespace godot;

// Functions.

// Overload functions.

// Binding.
void Discord::_bind_methods() {
	ClassDB::bind_method(D_METHOD("RunCallbacks"),
			&Discord::RunCallbacks);

	ClassDB::bind_method(D_METHOD("EnumToString", value, enum_type),
			&Discord::EnumToString);
}
