#include "discord_linked_lobby.h"

using namespace godot;

discordpp::LinkedLobby *DiscordLinkedLobby::unwrap() {
	return &linked_lobby;
}

void DiscordLinkedLobby::_bind_methods() {
    //
}

DiscordLinkedLobby::DiscordLinkedLobby() {}

DiscordLinkedLobby::~DiscordLinkedLobby() {}
