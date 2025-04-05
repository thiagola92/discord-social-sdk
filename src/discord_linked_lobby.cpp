// AUTO-GENERATED
#include "discord_classes.h"

using namespace godot;

discordpp::LinkedLobby *DiscordLinkedLobby::unwrap() {
	return linked_lobby;
}

uint64_t DiscordLinkedLobby::application_id() {
	auto r = linked_lobby->ApplicationId();
	return r;
}

void DiscordLinkedLobby::set_application_id(uint64_t application_id) {
	linked_lobby->SetApplicationId(application_id);
}

uint64_t DiscordLinkedLobby::lobby_id() {
	auto r = linked_lobby->LobbyId();
	return r;
}

void DiscordLinkedLobby::set_lobby_id(uint64_t lobby_id) {
	linked_lobby->SetLobbyId(lobby_id);
}

void DiscordLinkedLobby::_bind_methods() {
	ClassDB::bind_method(D_METHOD("application_id"),
			&DiscordLinkedLobby::application_id);

	ClassDB::bind_method(D_METHOD("set_application_id", "application_id"),
			&DiscordLinkedLobby::set_application_id);

	ClassDB::bind_method(D_METHOD("lobby_id"),
			&DiscordLinkedLobby::lobby_id);

	ClassDB::bind_method(D_METHOD("set_lobby_id", "lobby_id"),
			&DiscordLinkedLobby::set_lobby_id);
}

DiscordLinkedLobby::DiscordLinkedLobby() {
	this->linked_lobby = memnew(discordpp::LinkedLobby);
}

DiscordLinkedLobby::DiscordLinkedLobby(discordpp::LinkedLobby *linked_lobby) {
	this->linked_lobby = linked_lobby;
}

DiscordLinkedLobby::~DiscordLinkedLobby() {}
