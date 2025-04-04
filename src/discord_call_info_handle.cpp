// AUTO-GENERATED
#include "discord_call_info_handle.h"

using namespace godot;

discordpp::CallInfoHandle *DiscordCallInfoHandle::unwrap() {
	return call_info_handle;
}

uint64_t DiscordCallInfoHandle::channel_id() {
	auto r = call_info_handle->ChannelId();
	return r;
}

TypedArray<uint64_t> DiscordCallInfoHandle::get_participants() {
	auto r = call_info_handle->GetParticipants();
	auto t_r = TypedArray<uint64_t>();

	for (auto i_r : r) {
		t_r.push_back(i_r);
	}

	return t_r;
}

Variant DiscordCallInfoHandle::get_voice_state_handle(uint64_t user_id) {
	auto r = call_info_handle->GetVoiceStateHandle(user_id);

	if (!r.has_value()) {
		return nullptr;
	}

	auto t_r = (discordpp::VoiceStateHandle *)memalloc(sizeof(discordpp::VoiceStateHandle));
	*t_r = r.value();
	return Variant(memnew(DiscordVoiceStateHandle{ t_r }));
}

uint64_t DiscordCallInfoHandle::guild_id() {
	auto r = call_info_handle->GuildId();
	return r;
}

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

DiscordCallInfoHandle::DiscordCallInfoHandle() {}

DiscordCallInfoHandle::DiscordCallInfoHandle(discordpp::CallInfoHandle *call_info_handle) {
	this->call_info_handle = call_info_handle;
}

DiscordCallInfoHandle::~DiscordCallInfoHandle() {}
