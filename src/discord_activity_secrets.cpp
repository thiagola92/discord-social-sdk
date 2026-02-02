
#include "discord_classes.h"

using namespace godot;

// Functions.

String DiscordActivitySecrets::join() {
	auto r = obj->Join();
}

void DiscordActivitySecrets::set_join(String join) {
	std::string p0 = std::string(join.utf8().get_data());
	obj->SetJoin(p0);
}

// Overload functions.

// Binding.
void DiscordActivitySecrets::_bind_methods() {
	ClassDB::bind_method(D_METHOD("join"),
			&DiscordActivitySecrets::join);

	ClassDB::bind_method(D_METHOD("set_join", "join"),
			&DiscordActivitySecrets::set_join);
}
