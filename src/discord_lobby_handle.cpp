#include "discord_lobby_handle.h"

using namespace godot;

discordpp::LobbyHandle *DiscordLobbyHandle::unwrap() {
	return lobby_handle;
}

void DiscordLobbyHandle::_bind_methods() {
    //
}

DiscordLobbyHandle::DiscordLobbyHandle() {}

DiscordLobbyHandle::DiscordLobbyHandle(discordpp::LobbyHandle *lobby_handle) {
    this->lobby_handle = lobby_handle;
}

DiscordLobbyHandle::~DiscordLobbyHandle() {}
