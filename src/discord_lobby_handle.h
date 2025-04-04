// AUTO-GENERATED
#ifndef DISCORD_LOBBY_HANDLE_H
#define DISCORD_LOBBY_HANDLE_H

#include "discord_call_info_handle.h"
#include "discord_linked_channel.h"
#include "discord_lobby_member_handle.h"
#include "discordpp.h"
#include "godot_cpp/classes/ref_counted.hpp"
#include "godot_cpp/variant/typed_array.hpp"
#include "godot_cpp/variant/typed_dictionary.hpp"

namespace godot {

class DiscordLobbyHandle : public RefCounted {
	GDCLASS(DiscordLobbyHandle, RefCounted)

private:
	discordpp::LobbyHandle *lobby_handle;

	DiscordLobbyHandle();

protected:
	static void _bind_methods();

public:
	discordpp::LobbyHandle *unwrap(); // Internal usage.

	Variant get_call_info_handle();
	Variant get_lobby_member_handle(uint64_t member_id);
	uint64_t id();
	Variant linked_channel();
	TypedArray<uint64_t> lobby_member_ids();
	TypedArray<DiscordLobbyMemberHandle *> lobby_members();
	TypedDictionary<String, String> metadata();

	DiscordLobbyHandle(discordpp::LobbyHandle *lobby_handle);
	~DiscordLobbyHandle();
};

} //namespace godot

#endif
