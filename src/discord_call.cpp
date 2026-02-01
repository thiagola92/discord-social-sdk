
#include "discord_classes.h"

using namespace godot;

// Functions.

DiscordAudioModeType::Enum DiscordCall::get_audio_mode() {
}

DiscordCallStatus::Enum DiscordCall::get_status() {
}

DiscordVADThresholdSettings DiscordCall::get_vadthreshold() {
}

String DiscordCall::error_to_string(DiscordCallError::Enum type) {
	discordpp::Call::Error p0 = (discordpp::Call::Error)type;
}

String DiscordCall::status_to_string(DiscordCallStatus::Enum type) {
	discordpp::Call::Status p0 = (discordpp::Call::Status)type;
}

TypedArray<int64_t> DiscordCall::get_participants() {
}

Variant DiscordCall::get_voice_state_handle(int64_t user_id) {
	int64_t p0 = user_id;
}

bool DiscordCall::get_local_mute(int64_t user_id) {
	int64_t p0 = user_id;
}

bool DiscordCall::get_pttactive() {
}

bool DiscordCall::get_self_deaf() {
}

bool DiscordCall::get_self_mute() {
}

float DiscordCall::get_participant_volume(int64_t user_id) {
	int64_t p0 = user_id;
}

int64_t DiscordCall::get_channel_id() {
}

int64_t DiscordCall::get_guild_id() {
}

int64_t DiscordCall::get_pttrelease_delay() {
}

void DiscordCall::set_audio_mode(DiscordAudioModeType::Enum audio_mode) {
	discordpp::AudioModeType p0 = (discordpp::AudioModeType)audio_mode;
}

void DiscordCall::set_local_mute(int64_t user_id, bool mute) {
	int64_t p0 = user_id;
	bool p1 = mute;
}

void DiscordCall::set_on_voice_state_changed_callback(Callable cb) {
	// TODO callable
}

void DiscordCall::set_participant_changed_callback(Callable cb) {
	// TODO callable
}

void DiscordCall::set_participant_volume(int64_t user_id, float volume) {
	int64_t p0 = user_id;
	float p1 = volume;
}

void DiscordCall::set_pttactive(bool active) {
	bool p0 = active;
}

void DiscordCall::set_pttrelease_delay(int64_t release_delay_ms) {
	int64_t p0 = release_delay_ms;
}

void DiscordCall::set_self_deaf(bool deaf) {
	bool p0 = deaf;
}

void DiscordCall::set_self_mute(bool mute) {
	bool p0 = mute;
}

void DiscordCall::set_speaking_status_changed_callback(Callable cb) {
	// TODO callable
}

void DiscordCall::set_status_changed_callback(Callable cb) {
	// TODO callable
}

void DiscordCall::set_vadthreshold(bool automatic, float threshold) {
	bool p0 = automatic;
	float p1 = threshold;
}

// Overload functions.

// Binding.
void DiscordCall::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_audio_mode"),
			&DiscordCall::get_audio_mode);

	ClassDB::bind_method(D_METHOD("get_channel_id"),
			&DiscordCall::get_channel_id);

	ClassDB::bind_method(D_METHOD("get_guild_id"),
			&DiscordCall::get_guild_id);

	ClassDB::bind_method(D_METHOD("get_local_mute", "user_id"),
			&DiscordCall::get_local_mute);

	ClassDB::bind_method(D_METHOD("get_participant_volume", "user_id"),
			&DiscordCall::get_participant_volume);

	ClassDB::bind_method(D_METHOD("get_participants"),
			&DiscordCall::get_participants);

	ClassDB::bind_method(D_METHOD("get_pttactive"),
			&DiscordCall::get_pttactive);

	ClassDB::bind_method(D_METHOD("get_pttrelease_delay"),
			&DiscordCall::get_pttrelease_delay);

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

	ClassDB::bind_static_method("DiscordCall", D_METHOD("error_to_string", "type"),
			&DiscordCall::error_to_string);

	ClassDB::bind_static_method("DiscordCall", D_METHOD("status_to_string", "type"),
			&DiscordCall::status_to_string);
}
