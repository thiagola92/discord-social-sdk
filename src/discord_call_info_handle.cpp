
#include "discord_classes.h"

using namespace godot;

// Functions.

TypedArray<int64_t> DiscordCallInfoHandle::get_participants() {
	auto r0 = obj->GetParticipants();

	TypedArray<int64_t> r1 = TypedArray<int64_t>();

	for (auto i : r0) {
		int64_t r1_t = (int64_t)i;
		r1.push_back(r1_t);
	}

	return r1;
}

Variant DiscordCallInfoHandle::get_voice_state_handle(int64_t user_id) {
	int64_t p0 = user_id;
	auto r0 = obj->GetVoiceStateHandle(p0);

	Variant r1;

	if (!r0.has_value()) {
		r1 = nullptr;
	} else {
		auto r0_v = r0.value();

		discordpp::VoiceStateHandle *r1_v_t = memnew(discordpp::VoiceStateHandle(std::move(r0_v)));
		DiscordVoiceStateHandle *r1_v = memnew(DiscordVoiceStateHandle{ r1_v_t });

		r1 = Variant(r1_v);
	}

	return r1;
}

int64_t DiscordCallInfoHandle::channel_id() {
	auto r0 = obj->ChannelId();

	int64_t r1 = (int64_t)r0;

	return r1;
}

int64_t DiscordCallInfoHandle::guild_id() {
	auto r0 = obj->GuildId();

	int64_t r1 = (int64_t)r0;

	return r1;
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
