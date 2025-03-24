#include "discord_lobby_member_handle.h"

using namespace godot;

discordpp::LobbyMemberHandle *DiscordLobbyMemberHandle::unwrap() {
	return lobby_member_handle;
}

void DiscordLobbyMemberHandle::_bind_methods() {
	//
}

// DiscordLobbyMemberHandle::DiscordLobbyMemberHandle() {}

DiscordLobbyMemberHandle::~DiscordLobbyMemberHandle() {}
