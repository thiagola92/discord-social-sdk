
#include "discord_classes.h"

using namespace godot;

// Functions.

TypedArray<int64_t> DiscordCallInfoHandle::get_participants() {
}

Variant DiscordCallInfoHandle::get_voice_state_handle(int64_t user_id) {
	int64_t p0 = user_id;
}

int64_t DiscordCallInfoHandle::channel_id() {
}

int64_t DiscordCallInfoHandle::guild_id() {
}

// Overload functions.

// Binding.
void DiscordCallInfoHandle::_bind_methods() {
	ClassDB::bind_method(D_METHOD("channel_id"),
			&DiscordCallInfoHandle::channel_id);

	ClassDB::bind_method(D_METHOD("get_participants"),
			&DiscordCallInfoHandle::get_participants);

	ClassDB::bind_method(D_METHOD("get_voice_state_handle", "user_id"),
			&DiscordCallInfoHandle::get_voice_state_handle);

	ClassDB::bind_method(D_METHOD("guild_id"),
			&DiscordCallInfoHandle::guild_id);
}
