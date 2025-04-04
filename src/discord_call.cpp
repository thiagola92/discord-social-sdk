// AUTO-GENERATED
#include "discord_call.h"

using namespace godot;

discordpp::Call *DiscordCall::unwrap() {
	return call;
}

DiscordAudioModeType::Enum DiscordCall::get_audio_mode() {
	auto r = call->GetAudioMode();
	return (DiscordAudioModeType::Enum)r;
}

uint64_t DiscordCall::get_channel_id() {
	auto r = call->GetChannelId();
	return r;
}

uint64_t DiscordCall::get_guild_id() {
	auto r = call->GetGuildId();
	return r;
}

bool DiscordCall::get_local_mute(uint64_t user_id) {
	auto r = call->GetLocalMute(user_id);
	return r;
}

TypedArray<uint64_t> DiscordCall::get_participants() {
	auto r = call->GetParticipants();
	auto t_r = TypedArray<uint64_t>();

	for (auto i_r : r) {
		t_r.push_back(i_r);
	}

	return t_r;
}

float DiscordCall::get_participant_volume(uint64_t user_id) {
	auto r = call->GetParticipantVolume(user_id);
	return r;
}

bool DiscordCall::get_pttactive() {
	auto r = call->GetPTTActive();
	return r;
}

bool DiscordCall::get_self_deaf() {
	auto r = call->GetSelfDeaf();
	return r;
}

bool DiscordCall::get_self_mute() {
	auto r = call->GetSelfMute();
	return r;
}

DiscordCall::Status::Enum DiscordCall::get_status() {
	auto r = call->GetStatus();
	return (DiscordCall::Status::Enum)r;
}

DiscordVADThresholdSettings *DiscordCall::get_vadthreshold() {
	auto r = call->GetVADThreshold();
	auto t_r = (discordpp::VADThresholdSettings *)memalloc(sizeof(discordpp::VADThresholdSettings));
	*t_r = r;
	return memnew(DiscordVADThresholdSettings{ t_r });
}

Variant DiscordCall::get_voice_state_handle(uint64_t user_id) {
	auto r = call->GetVoiceStateHandle(user_id);

	if (!r.has_value()) {
		return nullptr;
	}

	auto t_r = (discordpp::VoiceStateHandle *)memalloc(sizeof(discordpp::VoiceStateHandle));
	*t_r = r.value();
	return Variant(memnew(DiscordVoiceStateHandle{ t_r }));
}

void DiscordCall::set_audio_mode(DiscordAudioModeType::Enum audio_mode) {
	auto p0 = (discordpp::AudioModeType)audio_mode;
	call->SetAudioMode(p0);
}

void DiscordCall::set_local_mute(uint64_t user_id, bool mute) {
	call->SetLocalMute(user_id, mute);
}

void DiscordCall::set_on_voice_state_changed_callback(DiscordCall::OnVoiceStateChanged::Enum cb) {
	auto p0 = (discordpp::Call::OnVoiceStateChanged)cb;
	call->SetOnVoiceStateChangedCallback(p0);
}

void DiscordCall::set_participant_changed_callback(DiscordCall::OnParticipantChanged::Enum cb) {
	auto p0 = (discordpp::Call::OnParticipantChanged)cb;
	call->SetParticipantChangedCallback(p0);
}

void DiscordCall::set_participant_volume(uint64_t user_id, float volume) {
	call->SetParticipantVolume(user_id, volume);
}

void DiscordCall::set_pttactive(bool active) {
	call->SetPTTActive(active);
}

void DiscordCall::set_pttrelease_delay(uint32_t release_delay_ms) {
	call->SetPTTReleaseDelay(release_delay_ms);
}

void DiscordCall::set_self_deaf(bool deaf) {
	call->SetSelfDeaf(deaf);
}

void DiscordCall::set_self_mute(bool mute) {
	call->SetSelfMute(mute);
}

void DiscordCall::set_speaking_status_changed_callback(DiscordCall::OnSpeakingStatusChanged::Enum cb) {
	auto p0 = (discordpp::Call::OnSpeakingStatusChanged)cb;
	call->SetSpeakingStatusChangedCallback(p0);
}

void DiscordCall::set_status_changed_callback(DiscordCall::OnStatusChanged::Enum cb) {
	auto p0 = (discordpp::Call::OnStatusChanged)cb;
	call->SetStatusChangedCallback(p0);
}

void DiscordCall::set_vadthreshold(bool automatic, float threshold) {
	call->SetVADThreshold(automatic, threshold);
}

void DiscordCall::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_audio_mode"),
			&DiscordCall::get_audio_mode);

	ClassDB::bind_method(D_METHOD("get_channel_id"),
			&DiscordCall::get_channel_id);

	ClassDB::bind_method(D_METHOD("get_guild_id"),
			&DiscordCall::get_guild_id);

	ClassDB::bind_method(D_METHOD("get_local_mute", "user_id"),
			&DiscordCall::get_local_mute);

	ClassDB::bind_method(D_METHOD("get_participants"),
			&DiscordCall::get_participants);

	ClassDB::bind_method(D_METHOD("get_participant_volume", "user_id"),
			&DiscordCall::get_participant_volume);

	ClassDB::bind_method(D_METHOD("get_pttactive"),
			&DiscordCall::get_pttactive);

	ClassDB::bind_method(D_METHOD("get_self_deaf"),
			&DiscordCall::get_self_deaf);

	ClassDB::bind_method(D_METHOD("get_self_mute"),
			&DiscordCall::get_self_mute);

	ClassDB::bind_method(D_METHOD("get_status"),
			&DiscordCall::get_status);

	ClassDB::bind_method(D_METHOD("get_vadthreshold"),
			&DiscordCall::get_vadthreshold);

	ClassDB::bind_method(D_METHOD("get_voice_state_handle", "user_id"),
			&DiscordCall::get_voice_state_handle);

	ClassDB::bind_method(D_METHOD("set_audio_mode", "audio_mode"),
			&DiscordCall::set_audio_mode);

	ClassDB::bind_method(D_METHOD("set_local_mute", "user_id", "mute"),
			&DiscordCall::set_local_mute);

	ClassDB::bind_method(D_METHOD("set_on_voice_state_changed_callback", "cb"),
			&DiscordCall::set_on_voice_state_changed_callback);

	ClassDB::bind_method(D_METHOD("set_participant_changed_callback", "cb"),
			&DiscordCall::set_participant_changed_callback);

	ClassDB::bind_method(D_METHOD("set_participant_volume", "user_id", "volume"),
			&DiscordCall::set_participant_volume);

	ClassDB::bind_method(D_METHOD("set_pttactive", "active"),
			&DiscordCall::set_pttactive);

	ClassDB::bind_method(D_METHOD("set_pttrelease_delay", "release_delay_ms"),
			&DiscordCall::set_pttrelease_delay);

	ClassDB::bind_method(D_METHOD("set_self_deaf", "deaf"),
			&DiscordCall::set_self_deaf);

	ClassDB::bind_method(D_METHOD("set_self_mute", "mute"),
			&DiscordCall::set_self_mute);

	ClassDB::bind_method(D_METHOD("set_speaking_status_changed_callback", "cb"),
			&DiscordCall::set_speaking_status_changed_callback);

	ClassDB::bind_method(D_METHOD("set_status_changed_callback", "cb"),
			&DiscordCall::set_status_changed_callback);

	ClassDB::bind_method(D_METHOD("set_vadthreshold", "automatic", "threshold"),
			&DiscordCall::set_vadthreshold);
}

DiscordCall::DiscordCall() {}

DiscordCall::DiscordCall(discordpp::Call *call) {
	this->call = call;
}

DiscordCall::~DiscordCall() {}
