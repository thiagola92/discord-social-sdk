
#include "discord_classes.h"

using namespace godot;

// Binding.
void DiscordBoolRef::_bind_methods() {
	{
		ClassDB::bind_method(D_METHOD("get_value"),
				&DiscordBoolRef::get_value);

		ClassDB::bind_method(D_METHOD("set_value", "value"),
				&DiscordBoolRef::set_value);
	}
}
