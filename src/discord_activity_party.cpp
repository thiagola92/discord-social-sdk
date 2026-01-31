
#include "discord_classes.h"

using namespace godot;

// Functions.

DiscordActivityPartyPrivacy DiscordActivityParty::privacy() {
}

String DiscordActivityParty::id() {
}

int64_t DiscordActivityParty::current_size() {
}

int64_t DiscordActivityParty::max_size() {
}

void DiscordActivityParty::set_current_size(int64_t current_size) {
	int64_t p0 = current_size;
}

void DiscordActivityParty::set_id(String id) {
	std::string p0 = std::string(id.utf8().get_data());
}

void DiscordActivityParty::set_max_size(int64_t max_size) {
	int64_t p0 = max_size;
}

void DiscordActivityParty::set_privacy(DiscordActivityPartyPrivacy privacy) {
	TODO
}

// Overload functions.

// Binding.
void DiscordActivityParty::_bind_methods() {
	ClassDB::bind_method(D_METHOD("current_size"),
			&DiscordActivityParty::current_size);

	ClassDB::bind_method(D_METHOD("id"),
			&DiscordActivityParty::id);

	ClassDB::bind_method(D_METHOD("max_size"),
			&DiscordActivityParty::max_size);

	ClassDB::bind_method(D_METHOD("privacy"),
			&DiscordActivityParty::privacy);

	ClassDB::bind_method(D_METHOD("set_current_size", "current_size"),
			&DiscordActivityParty::set_current_size);

	ClassDB::bind_method(D_METHOD("set_id", "id"),
			&DiscordActivityParty::set_id);

	ClassDB::bind_method(D_METHOD("set_max_size", "max_size"),
			&DiscordActivityParty::set_max_size);

	ClassDB::bind_method(D_METHOD("set_privacy", "privacy"),
			&DiscordActivityParty::set_privacy);
}
