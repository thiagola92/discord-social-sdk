
#include "discord_classes.h"

using namespace godot;

// Functions.

String DiscordGuildMinimal::name() {
	auto r = obj->Name();
}

int64_t DiscordGuildMinimal::id() {
	auto r = obj->Id();
}

void DiscordGuildMinimal::set_id(int64_t id) {
	int64_t p0 = id;
	obj->SetId(p0);
}

void DiscordGuildMinimal::set_name(String name) {
	std::string p0 = std::string(name.utf8().get_data());
	obj->SetName(p0);
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
