
#include "discord_classes.h"

using namespace godot;

// Functions.

TypedArray<int64_t> DiscordCallInfoHandle::get_participants() {
	auto r = obj->GetParticipants();

	TypedArray<int64_t> cr = TypedArray<int64_t>();

	for (auto i : r) {
		int64_t cr_t = (int64_t)i;
		cr.push_back(cr_t);
	}

	return cr;
}

Variant DiscordCallInfoHandle::get_voice_state_handle(int64_t user_id) {
	int64_t p0 = user_id;
	auto r = obj->GetVoiceStateHandle(p0);

	Variant cr;

	if (!r.has_value()) {
		cr = nullptr;
	} else {
		auto r_v = r.value();

		discordpp::VoiceStateHandle *cr_v_t = memnew(discordpp::VoiceStateHandle(std::move(r_v)));
		DiscordVoiceStateHandle *cr_v = memnew(DiscordVoiceStateHandle{ cr_v_t });

		cr = Variant(cr_v);
	}

	return cr;
}

int64_t DiscordCallInfoHandle::channel_id() {
	auto r = obj->ChannelId();

	int64_t cr = (int64_t)r;
	return cr;
}

int64_t DiscordCallInfoHandle::guild_id() {
	auto r = obj->GuildId();

	int64_t cr = (int64_t)r;
	return cr;
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
