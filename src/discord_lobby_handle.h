#ifndef DISCORD_LOBBY_HANDLE_H
#define DISCORD_LOBBY_HANDLE_H

#include "discordpp.h"
#include "godot_cpp/classes/ref_counted.hpp"

namespace godot {

class DiscordLobbyHandle : public RefCounted {
	GDCLASS(DiscordLobbyHandle, RefCounted)

    DiscordLobbyHandle();

private:
	discordpp::LobbyHandle *lobby_handle;

protected:
	static void _bind_methods();

public:
	discordpp::LobbyHandle *unwrap(); // Internal usage.

	DiscordLobbyHandle(discordpp::LobbyHandle *lobby_handle);
	~DiscordLobbyHandle();
};

} //namespace godot

#endif
