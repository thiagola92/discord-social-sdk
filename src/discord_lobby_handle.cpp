
#include "discord_classes.h"

using namespace godot;

// Functions.

TypedArray<DiscordLobbyMemberHandle> DiscordLobbyHandle::lobby_members() {
}

TypedArray<int64_t> DiscordLobbyHandle::lobby_member_ids() {
}

TypedDictionary<String, String> DiscordLobbyHandle::metadata() {
}

Variant DiscordLobbyHandle::get_call_info_handle() {
}

Variant DiscordLobbyHandle::get_lobby_member_handle(int64_t member_id) {
	int64_t p0 = member_id;
}

Variant DiscordLobbyHandle::linked_channel() {
}

int64_t DiscordLobbyHandle::id() {
}

// Overload functions.

// Binding.
void DiscordLobbyHandle::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_call_info_handle"),
			&DiscordLobbyHandle::get_call_info_handle);

	ClassDB::bind_method(D_METHOD("get_lobby_member_handle", "member_id"),
			&DiscordLobbyHandle::get_lobby_member_handle);

	ClassDB::bind_method(D_METHOD("id"),
			&DiscordLobbyHandle::id);

	ClassDB::bind_method(D_METHOD("linked_channel"),
			&DiscordLobbyHandle::linked_channel);

	ClassDB::bind_method(D_METHOD("lobby_member_ids"),
			&DiscordLobbyHandle::lobby_member_ids);

	ClassDB::bind_method(D_METHOD("lobby_members"),
			&DiscordLobbyHandle::lobby_members);

	ClassDB::bind_method(D_METHOD("metadata"),
			&DiscordLobbyHandle::metadata);
}
