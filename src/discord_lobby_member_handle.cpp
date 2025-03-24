#include "discord_lobby_member_handle.h"

using namespace godot;

discordpp::LobbyMemberHandle *DiscordLobbyMemberHandle::unwrap() {
	return lobby_member_handle;
}

void DiscordLobbyMemberHandle::_bind_methods() {
    //
}

DiscordLobbyMemberHandle::DiscordLobbyMemberHandle() {}

DiscordLobbyMemberHandle::DiscordLobbyMemberHandle(discordpp::LobbyMemberHandle *lobby_member_handle) {
    this->lobby_member_handle = lobby_member_handle;
}

DiscordLobbyMemberHandle::~DiscordLobbyMemberHandle() {}
