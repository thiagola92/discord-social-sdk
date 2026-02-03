
#include "discord_classes.h"

using namespace godot;

// Functions.

int64_t DiscordLinkedLobby::application_id() {
	auto r = obj->ApplicationId();

	int64_t cr = (int64_t)r;
	return cr;
}

int64_t DiscordLinkedLobby::lobby_id() {
	auto r = obj->LobbyId();

	int64_t cr = (int64_t)r;
	return cr;
}

void DiscordLinkedLobby::set_application_id(int64_t application_id) {
	int64_t p0 = application_id;
	obj->SetApplicationId(p0);
}

void DiscordLinkedLobby::set_lobby_id(int64_t lobby_id) {
	int64_t p0 = lobby_id;
	obj->SetLobbyId(p0);
}

// Overload functions.

// Binding.
void DiscordLinkedLobby::_bind_methods() {
	ClassDB::bind_method(D_METHOD("application_id"),
			&DiscordLinkedLobby::application_id);

	ClassDB::bind_method(D_METHOD("lobby_id"),
			&DiscordLinkedLobby::lobby_id);

	ClassDB::bind_method(D_METHOD("set_application_id", "application_id"),
			&DiscordLinkedLobby::set_application_id);

	ClassDB::bind_method(D_METHOD("set_lobby_id", "lobby_id"),
			&DiscordLinkedLobby::set_lobby_id);
}
