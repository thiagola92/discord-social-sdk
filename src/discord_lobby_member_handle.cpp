
#include "discord_classes.h"

using namespace godot;

// Functions.

TypedDictionary<String, String> DiscordLobbyMemberHandle::metadata() {
	auto r = obj->Metadata();
}

Variant DiscordLobbyMemberHandle::user() {
	auto r = obj->User();
}

bool DiscordLobbyMemberHandle::can_link_lobby() {
	auto r = obj->CanLinkLobby();
}

bool DiscordLobbyMemberHandle::connected() {
	auto r = obj->Connected();
}

int64_t DiscordLobbyMemberHandle::id() {
	auto r = obj->Id();
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
