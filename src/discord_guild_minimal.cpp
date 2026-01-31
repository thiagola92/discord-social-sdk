
#include "discord_classes.h"

using namespace godot;

// Functions.

String DiscordGuildMinimal::name() {
}

int64_t DiscordGuildMinimal::id() {
}

void DiscordGuildMinimal::set_id(int64_t id) {
	int64_t p0 = id;
}

void DiscordGuildMinimal::set_name(String name) {
	std::string p0 = std::string(name.utf8().get_data());
}

// Overload functions.

// Binding.
void DiscordGuildMinimal::_bind_methods() {
	ClassDB::bind_method(D_METHOD("id"),
			&DiscordGuildMinimal::id);

	ClassDB::bind_method(D_METHOD("name"),
			&DiscordGuildMinimal::name);

	ClassDB::bind_method(D_METHOD("set_id", "id"),
			&DiscordGuildMinimal::set_id);

	ClassDB::bind_method(D_METHOD("set_name", "name"),
			&DiscordGuildMinimal::set_name);
}
