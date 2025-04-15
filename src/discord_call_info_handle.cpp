
#include "discord_classes.h"

using namespace godot;

void DiscordppCallInfoHandle::Drop() {
	obj->Drop();
}

uint64_t DiscordppCallInfoHandle::ChannelId() {
	return obj->ChannelId();
}

TypedArray<uint64_t> DiscordppCallInfoHandle::GetParticipants() {
	auto r = obj->GetParticipants();
	auto t_r = TypedArray<uint64_t>();

	for (auto i_r : r) {
		t_r.push_back(i_r);
	}

	return t_r;
}

Variant DiscordppCallInfoHandle::GetVoiceStateHandle(uint64_t userId) {
	auto p0 = userId;
	auto r = obj->GetVoiceStateHandle(p0);

	if (!r.has_value()) {
		return nullptr;
	}

	auto t_r = (discordpp::VoiceStateHandle *)memalloc(sizeof(discordpp::VoiceStateHandle));
	*t_r = r.value();
	return Variant(memnew(DiscordppVoiceStateHandle{ t_r }));
}

uint64_t DiscordppCallInfoHandle::GuildId() {
	return obj->GuildId();
}

void DiscordppCallInfoHandle::_bind_methods() {
	ClassDB::bind_method(D_METHOD("Drop"),
			&DiscordppCallInfoHandle::Drop);

	ClassDB::bind_method(D_METHOD("ChannelId"),
			&DiscordppCallInfoHandle::ChannelId);

	ClassDB::bind_method(D_METHOD("GetParticipants"),
			&DiscordppCallInfoHandle::GetParticipants);

	ClassDB::bind_method(D_METHOD("GetVoiceStateHandle", "userId"),
			&DiscordppCallInfoHandle::GetVoiceStateHandle);

	ClassDB::bind_method(D_METHOD("GuildId"),
			&DiscordppCallInfoHandle::GuildId);
}
