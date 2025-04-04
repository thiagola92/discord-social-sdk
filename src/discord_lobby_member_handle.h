// AUTO-GENERATED
#ifndef DISCORD_LOBBY_MEMBER_HANDLE_H
#define DISCORD_LOBBY_MEMBER_HANDLE_H

#include "discord_user_handle.h"
#include "discordpp.h"
#include "godot_cpp/classes/ref_counted.hpp"

namespace godot {

class DiscordLobbyMemberHandle : public RefCounted {
	GDCLASS(DiscordLobbyMemberHandle, RefCounted)

private:
	discordpp::LobbyMemberHandle *lobby_member_handle; // Doesn't have public empty contrusctor, needs to be a pointer.

	DiscordLobbyMemberHandle();

protected:
	static void _bind_methods();

public:
	discordpp::LobbyMemberHandle *unwrap(); // Internal usage.

	bool can_link_lobby();
	bool connected();
	uint64_t id();
	TypedDictionary<String, String> metadata();
	Variant user();

	DiscordLobbyMemberHandle(discordpp::LobbyMemberHandle *lobby_member_handle);
	~DiscordLobbyMemberHandle();
};

} //namespace godot

#endif
