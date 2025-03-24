#ifndef DISCORD_LOBBY_MEMBER_HANDLE_H
#define DISCORD_LOBBY_MEMBER_HANDLE_H

#include "discordpp.h"
#include "godot_cpp/classes/ref_counted.hpp"

namespace godot {

class DiscordLobbyMemberHandle : public RefCounted {
	GDCLASS(DiscordLobbyMemberHandle, RefCounted)

private:
	discordpp::LobbyMemberHandle lobby_member_handle;

protected:
	static void _bind_methods();

public:
	discordpp::LobbyMemberHandle *unwrap(); // Internal usage.

	DiscordLobbyMemberHandle();
	~DiscordLobbyMemberHandle();
};

} //namespace godot

#endif
