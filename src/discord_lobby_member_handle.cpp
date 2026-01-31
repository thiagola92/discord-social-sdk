
#include "discord_classes.h"

using namespace godot;

// Functions.

TypedDictionary<String, String> DiscordLobbyMemberHandle::metadata() {
}

Variant DiscordLobbyMemberHandle::user() {
}

bool DiscordLobbyMemberHandle::can_link_lobby() {
}

bool DiscordLobbyMemberHandle::connected() {
}

int64_t DiscordLobbyMemberHandle::id() {
}

// Overload functions.

// Binding.
void DiscordLobbyMemberHandle::_bind_methods() {
	ClassDB::bind_method(D_METHOD("can_link_lobby"),
			&DiscordLobbyMemberHandle::can_link_lobby);

	ClassDB::bind_method(D_METHOD("connected"),
			&DiscordLobbyMemberHandle::connected);

	ClassDB::bind_method(D_METHOD("id"),
			&DiscordLobbyMemberHandle::id);

	ClassDB::bind_method(D_METHOD("metadata"),
			&DiscordLobbyMemberHandle::metadata);

	ClassDB::bind_method(D_METHOD("user"),
			&DiscordLobbyMemberHandle::user);
}
