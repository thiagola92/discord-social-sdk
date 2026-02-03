
#include "discord_classes.h"

using namespace godot;

// Functions.

void Discord::run_callbacks() {
	discordpp::RunCallbacks();
}

// Overload functions.

String Discord::enum_to_string(int value, Variant enum_type) {
	discordpp::ActivityActionTypes p0 = (discordpp::ActivityActionTypes)value;
	auto r = discordpp::EnumToString(p0);

	String cr = String(r);
	return cr;
}

// Binding.
void Discord::_bind_methods() {
	ClassDB::bind_static_method("Discord", D_METHOD("run_callbacks"),
			&Discord::run_callbacks);

	ClassDB::bind_static_method("Discord", D_METHOD("enum_to_string", "value", "enum_type"),
			&Discord::enum_to_string);
}
