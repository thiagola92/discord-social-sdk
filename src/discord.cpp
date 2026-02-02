
#include "discord_classes.h"

using namespace godot;

// Functions.

void Discord::run_callbacks() {
	obj->RunCallbacks();
}

// Overload functions.

// Binding.
void Discord::_bind_methods() {
	ClassDB::bind_method(D_METHOD("run_callbacks"),
			&Discord::run_callbacks);

	ClassDB::bind_method(D_METHOD("enum_to_string", "value", "enum_type"),
			&Discord::enum_to_string);
}
