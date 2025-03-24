#ifndef DISCORD_LINKED_LOBBY_H
#define DISCORD_LINKED_LOBBY_H

#include "discordpp.h"
#include "godot_cpp/classes/ref_counted.hpp"

namespace godot {

class DiscordLinkedLobby : public RefCounted {
	GDCLASS(DiscordLinkedLobby, RefCounted)

private:
	discordpp::LinkedLobby linked_lobby;

protected:
	static void _bind_methods();

public:
	discordpp::LinkedLobby *unwrap(); // Internal usage.

	DiscordLinkedLobby();
	~DiscordLinkedLobby();
};

} //namespace godot

#endif
