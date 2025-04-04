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

DiscordCallStatus::Enum DiscordCall::get_status() {
	auto r = call->GetStatus();
	return (DiscordCallStatus::Enum)r;
}

DiscordVADThresholdSettings *DiscordCall::get_vadthreshold() {
	auto t_r = (discordpp::VADThresholdSettings *)memalloc(sizeof(discordpp::VADThresholdSettings));
	*t_r = call->GetVADThreshold();
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

void DiscordCall::set_on_voice_state_changed_callback() {
	call->SetOnVoiceStateChangedCallback([this](uint64_t userId) {
		auto p0 = userId;
		this->emit_signal("set_on_voice_state_changed_callback_callback", p0);
	});
}

void DiscordCall::set_participant_changed_callback() {
	call->SetParticipantChangedCallback([this](uint64_t userId, bool added) {
		auto p0 = userId;
		auto p1 = added;
		this->emit_signal("set_participant_changed_callback_callback", p0, p1);
	});
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

void DiscordCall::set_speaking_status_changed_callback() {
	call->SetSpeakingStatusChangedCallback([this](uint64_t userId, bool isPlayingSound) {
		auto p0 = userId;
		auto p1 = isPlayingSound;
		this->emit_signal("set_speaking_status_changed_callback_callback", p0, p1);
	});
}

void DiscordCall::set_status_changed_callback() {
	call->SetStatusChangedCallback([this](discordpp::Call::Status status, discordpp::Call::Error error, int32_t errorDetail) {
		auto p0 = (DiscordCallStatus::Enum)status;
		auto p1 = (DiscordCallError::Enum)error;
		auto p2 = errorDetail;
		this->emit_signal("set_status_changed_callback_callback", p0, p1, p2);
	});
}

void DiscordCall::set_vadthreshold(bool automatic, float threshold) {
	call->SetVADThreshold(automatic, threshold);
}

void DiscordCall::_bind_methods() {
	ADD_SIGNAL(MethodInfo("call_on_voice_state_changed", PropertyInfo(Variant::INT, "user_id")));

	ADD_SIGNAL(MethodInfo("call_on_participant_changed", PropertyInfo(Variant::INT, "user_id"), PropertyInfo(Variant::BOOL, "added")));

	ADD_SIGNAL(MethodInfo("call_on_speaking_status_changed", PropertyInfo(Variant::INT, "user_id"), PropertyInfo(Variant::BOOL, "is_playing_sound")));

	ADD_SIGNAL(MethodInfo("call_on_status_changed", PropertyInfo(Variant::OBJECT, "status"), PropertyInfo(Variant::OBJECT, "error"), PropertyInfo(Variant::INT, "error_detail")));

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

	ClassDB::bind_method(D_METHOD("set_on_voice_state_changed_callback"),
			&DiscordCall::set_on_voice_state_changed_callback);

	ClassDB::bind_method(D_METHOD("set_participant_changed_callback"),
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

	ClassDB::bind_method(D_METHOD("set_speaking_status_changed_callback"),
			&DiscordCall::set_speaking_status_changed_callback);

	ClassDB::bind_method(D_METHOD("set_status_changed_callback"),
			&DiscordCall::set_status_changed_callback);

	ClassDB::bind_method(D_METHOD("set_vadthreshold", "automatic", "threshold"),
			&DiscordCall::set_vadthreshold);
}

DiscordCall::DiscordCall() {
}

DiscordCall::DiscordCall(discordpp::Call *call) {
	this->call = call;
}

DiscordCall::~DiscordCall() {}
