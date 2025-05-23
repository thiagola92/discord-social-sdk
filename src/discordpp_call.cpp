
#include "discordpp_classes.h"

using namespace godot;

void DiscordppCall::Drop() {
	obj->Drop();
}

String DiscordppCall::ErrorToString(DiscordppCallError::Enum type) {
	discordpp::Call::Error p0 = (discordpp::Call::Error)type;

	return String(discordpp::Call::ErrorToString(p0).c_str());
}

DiscordppAudioModeType::Enum DiscordppCall::GetAudioMode() {
	return (DiscordppAudioModeType::Enum)obj->GetAudioMode();
}

int64_t DiscordppCall::GetChannelId() {
	return obj->GetChannelId();
}

int64_t DiscordppCall::GetGuildId() {
	return obj->GetGuildId();
}

bool DiscordppCall::GetLocalMute(int64_t userId) {
	int64_t p0 = userId;

	return obj->GetLocalMute(p0);
}

TypedArray<int64_t> DiscordppCall::GetParticipants() {
	auto r = obj->GetParticipants();
	TypedArray<int64_t> t_r = TypedArray<int64_t>();

	for (auto i : r) {
		t_r.push_back((int64_t)i);
	}

	return t_r;
}

float DiscordppCall::GetParticipantVolume(int64_t userId) {
	int64_t p0 = userId;

	return obj->GetParticipantVolume(p0);
}

bool DiscordppCall::GetPTTActive() {
	return obj->GetPTTActive();
}

int64_t DiscordppCall::GetPTTReleaseDelay() {
	return obj->GetPTTReleaseDelay();
}

bool DiscordppCall::GetSelfDeaf() {
	return obj->GetSelfDeaf();
}

bool DiscordppCall::GetSelfMute() {
	return obj->GetSelfMute();
}

DiscordppCallStatus::Enum DiscordppCall::GetStatus() {
	return (DiscordppCallStatus::Enum)obj->GetStatus();
}

DiscordppVADThresholdSettings *DiscordppCall::GetVADThreshold() {
	discordpp::VADThresholdSettings r = obj->GetVADThreshold();
	discordpp::VADThresholdSettings *t_r = memnew(discordpp::VADThresholdSettings(std::move(r)));
	return memnew(DiscordppVADThresholdSettings{ t_r });
}

Variant DiscordppCall::GetVoiceStateHandle(int64_t userId) {
	int64_t p0 = userId;

	auto r = obj->GetVoiceStateHandle(p0);

	if (!r.has_value()) {
		return nullptr;
	}

	discordpp::VoiceStateHandle *t_r = memnew(discordpp::VoiceStateHandle(std::move(r.value())));
	return Variant(memnew(DiscordppVoiceStateHandle{ t_r }));
}

void DiscordppCall::SetAudioMode(DiscordppAudioModeType::Enum audioMode) {
	discordpp::AudioModeType p0 = (discordpp::AudioModeType)audioMode;

	obj->SetAudioMode(p0);
}

void DiscordppCall::SetLocalMute(int64_t userId, bool mute) {
	int64_t p0 = userId;
	bool p1 = mute;

	obj->SetLocalMute(p0, p1);
}

void DiscordppCall::SetOnVoiceStateChangedCallback(Callable cb) {
	obj->SetOnVoiceStateChangedCallback([cb](auto userId) {
		int64_t p0 = (int64_t)userId;
		cb.call(p0);
	});
}

void DiscordppCall::SetParticipantChangedCallback(Callable cb) {
	obj->SetParticipantChangedCallback([cb](auto userId, auto added) {
		int64_t p0 = (int64_t)userId;
		bool p1 = added;
		cb.call(p0, p1);
	});
}

void DiscordppCall::SetParticipantVolume(int64_t userId, float volume) {
	int64_t p0 = userId;
	float p1 = volume;

	obj->SetParticipantVolume(p0, p1);
}

void DiscordppCall::SetPTTActive(bool active) {
	bool p0 = active;

	obj->SetPTTActive(p0);
}

void DiscordppCall::SetPTTReleaseDelay(int64_t releaseDelayMs) {
	int64_t p0 = releaseDelayMs;

	obj->SetPTTReleaseDelay(p0);
}

void DiscordppCall::SetSelfDeaf(bool deaf) {
	bool p0 = deaf;

	obj->SetSelfDeaf(p0);
}

void DiscordppCall::SetSelfMute(bool mute) {
	bool p0 = mute;

	obj->SetSelfMute(p0);
}

void DiscordppCall::SetSpeakingStatusChangedCallback(Callable cb) {
	obj->SetSpeakingStatusChangedCallback([cb](auto userId, auto isPlayingSound) {
		int64_t p0 = (int64_t)userId;
		bool p1 = isPlayingSound;
		cb.call(p0, p1);
	});
}

void DiscordppCall::SetStatusChangedCallback(Callable cb) {
	obj->SetStatusChangedCallback([cb](auto status, auto error, auto errorDetail) {
		DiscordppCallStatus::Enum p0 = (DiscordppCallStatus::Enum)status;
		DiscordppCallError::Enum p1 = (DiscordppCallError::Enum)error;
		int64_t p2 = (int64_t)errorDetail;
		cb.call(p0, p1, p2);
	});
}

void DiscordppCall::SetVADThreshold(bool automatic, float threshold) {
	bool p0 = automatic;
	float p1 = threshold;

	obj->SetVADThreshold(p0, p1);
}

String DiscordppCall::StatusToString(DiscordppCallStatus::Enum type) {
	discordpp::Call::Status p0 = (discordpp::Call::Status)type;

	return String(discordpp::Call::StatusToString(p0).c_str());
}

void DiscordppCall::_bind_methods() {
	ClassDB::bind_method(D_METHOD("Drop"),
			&DiscordppCall::Drop);

	ClassDB::bind_static_method("DiscordppCall", D_METHOD("ErrorToString", "type"),
			&DiscordppCall::ErrorToString);

	ClassDB::bind_method(D_METHOD("GetAudioMode"),
			&DiscordppCall::GetAudioMode);

	ClassDB::bind_method(D_METHOD("GetChannelId"),
			&DiscordppCall::GetChannelId);

	ClassDB::bind_method(D_METHOD("GetGuildId"),
			&DiscordppCall::GetGuildId);

	ClassDB::bind_method(D_METHOD("GetLocalMute", "userId"),
			&DiscordppCall::GetLocalMute);

	ClassDB::bind_method(D_METHOD("GetParticipants"),
			&DiscordppCall::GetParticipants);

	ClassDB::bind_method(D_METHOD("GetParticipantVolume", "userId"),
			&DiscordppCall::GetParticipantVolume);

	ClassDB::bind_method(D_METHOD("GetPTTActive"),
			&DiscordppCall::GetPTTActive);

	ClassDB::bind_method(D_METHOD("GetPTTReleaseDelay"),
			&DiscordppCall::GetPTTReleaseDelay);

	ClassDB::bind_method(D_METHOD("GetSelfDeaf"),
			&DiscordppCall::GetSelfDeaf);

	ClassDB::bind_method(D_METHOD("GetSelfMute"),
			&DiscordppCall::GetSelfMute);

	ClassDB::bind_method(D_METHOD("GetStatus"),
			&DiscordppCall::GetStatus);

	ClassDB::bind_method(D_METHOD("GetVADThreshold"),
			&DiscordppCall::GetVADThreshold);

	ClassDB::bind_method(D_METHOD("GetVoiceStateHandle", "userId"),
			&DiscordppCall::GetVoiceStateHandle);

	ClassDB::bind_method(D_METHOD("SetAudioMode", "audioMode"),
			&DiscordppCall::SetAudioMode);

	ClassDB::bind_method(D_METHOD("SetLocalMute", "userId", "mute"),
			&DiscordppCall::SetLocalMute);

	ClassDB::bind_method(D_METHOD("SetOnVoiceStateChangedCallback", "cb"),
			&DiscordppCall::SetOnVoiceStateChangedCallback);

	ClassDB::bind_method(D_METHOD("SetParticipantChangedCallback", "cb"),
			&DiscordppCall::SetParticipantChangedCallback);

	ClassDB::bind_method(D_METHOD("SetParticipantVolume", "userId", "volume"),
			&DiscordppCall::SetParticipantVolume);

	ClassDB::bind_method(D_METHOD("SetPTTActive", "active"),
			&DiscordppCall::SetPTTActive);

	ClassDB::bind_method(D_METHOD("SetPTTReleaseDelay", "releaseDelayMs"),
			&DiscordppCall::SetPTTReleaseDelay);

	ClassDB::bind_method(D_METHOD("SetSelfDeaf", "deaf"),
			&DiscordppCall::SetSelfDeaf);

	ClassDB::bind_method(D_METHOD("SetSelfMute", "mute"),
			&DiscordppCall::SetSelfMute);

	ClassDB::bind_method(D_METHOD("SetSpeakingStatusChangedCallback", "cb"),
			&DiscordppCall::SetSpeakingStatusChangedCallback);

	ClassDB::bind_method(D_METHOD("SetStatusChangedCallback", "cb"),
			&DiscordppCall::SetStatusChangedCallback);

	ClassDB::bind_method(D_METHOD("SetVADThreshold", "automatic", "threshold"),
			&DiscordppCall::SetVADThreshold);

	ClassDB::bind_static_method("DiscordppCall", D_METHOD("StatusToString", "type"),
			&DiscordppCall::StatusToString);
}
