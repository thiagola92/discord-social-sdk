
#include "discordpp_classes.h"

using namespace godot;

void DiscordppCallInfoHandle::Drop() {
	obj->Drop();
}

int64_t DiscordppCallInfoHandle::ChannelId() {
	return obj->ChannelId();
}

TypedArray<int64_t> DiscordppCallInfoHandle::GetParticipants() {
	auto r = obj->GetParticipants();
	TypedArray<int64_t> t_r = TypedArray<int64_t>();

	for (auto i : r) {
		t_r.push_back((int64_t)i);
	}

	return t_r;
}

Variant DiscordppCallInfoHandle::GetVoiceStateHandle(int64_t userId) {
	int64_t p0 = userId;

	auto r = obj->GetVoiceStateHandle(p0);

	if (!r.has_value()) {
		return nullptr;
	}

	discordpp::VoiceStateHandle *t_r = memnew(discordpp::VoiceStateHandle(std::move(r.value())));
	return Variant(memnew(DiscordppVoiceStateHandle{ t_r }));
}

int64_t DiscordppCallInfoHandle::GuildId() {
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
