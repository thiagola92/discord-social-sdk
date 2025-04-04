// AUTO-GENERATED
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

	uint64_t application_id();
	void set_application_id(uint64_t application_id);
	uint64_t lobby_id();
	void set_lobby_id(uint64_t lobby_id);

	DiscordLinkedLobby();
	DiscordLinkedLobby(discordpp::LinkedLobby linked_lobby);
	~DiscordLinkedLobby();
};

} //namespace godot

#endif
