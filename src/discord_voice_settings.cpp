
#include "discord_classes.h"

using namespace godot;

// Functions.

DiscordVoiceInputModeType::Enum DiscordVoiceSettings::input_mode() {
	auto r0 = obj->InputMode();

	DiscordVoiceInputModeType::Enum r1 = (DiscordVoiceInputModeType::Enum)r0;

	return r1;
}

String DiscordVoiceSettings::ptt_key() {
	auto r0 = obj->PttKey();

	String r1 = String(r0.c_str());

	return r1;
}

bool DiscordVoiceSettings::automatic_gain_control() {
	auto r0 = obj->AutomaticGainControl();

	bool r1 = r0;

	return r1;
}

bool DiscordVoiceSettings::echo_cancellation() {
	auto r0 = obj->EchoCancellation();

	bool r1 = r0;

	return r1;
}

bool DiscordVoiceSettings::noise_cancellation() {
	auto r0 = obj->NoiseCancellation();

	bool r1 = r0;

	return r1;
}

bool DiscordVoiceSettings::noise_suppression() {
	auto r0 = obj->NoiseSuppression();

	bool r1 = r0;

	return r1;
}

bool DiscordVoiceSettings::self_deaf() {
	auto r0 = obj->SelfDeaf();

	bool r1 = r0;

	return r1;
}

bool DiscordVoiceSettings::self_mute() {
	auto r0 = obj->SelfMute();

	bool r1 = r0;

	return r1;
}

real_t DiscordVoiceSettings::input_volume() {
	auto r0 = obj->InputVolume();

	real_t r1 = (real_t)r0;

	return r1;
}

real_t DiscordVoiceSettings::output_volume() {
	auto r0 = obj->OutputVolume();

	real_t r1 = (real_t)r0;

	return r1;
}

void DiscordVoiceSettings::set_automatic_gain_control(bool automatic_gain_control) {
	bool p0 = automatic_gain_control;
	obj->SetAutomaticGainControl(p0);
}

void DiscordVoiceSettings::set_echo_cancellation(bool echo_cancellation) {
	bool p0 = echo_cancellation;
	obj->SetEchoCancellation(p0);
}

void DiscordVoiceSettings::set_input_mode(DiscordVoiceInputModeType::Enum input_mode) {
	discordpp::VoiceInputModeType p0 = (discordpp::VoiceInputModeType)input_mode;
	obj->SetInputMode(p0);
}

void DiscordVoiceSettings::set_input_volume(real_t input_volume) {
	float p0 = (float)input_volume;
	obj->SetInputVolume(p0);
}

void DiscordVoiceSettings::set_noise_cancellation(bool noise_cancellation) {
	bool p0 = noise_cancellation;
	obj->SetNoiseCancellation(p0);
}

void DiscordVoiceSettings::set_noise_suppression(bool noise_suppression) {
	bool p0 = noise_suppression;
	obj->SetNoiseSuppression(p0);
}

void DiscordVoiceSettings::set_output_volume(real_t output_volume) {
	float p0 = (float)output_volume;
	obj->SetOutputVolume(p0);
}

void DiscordVoiceSettings::set_ptt_key(String ptt_key) {
	std::string p0 = std::string(ptt_key.utf8().get_data());
	obj->SetPttKey(p0);
}

void DiscordVoiceSettings::set_self_deaf(bool self_deaf) {
	bool p0 = self_deaf;
	obj->SetSelfDeaf(p0);
}

void DiscordVoiceSettings::set_self_mute(bool self_mute) {
	bool p0 = self_mute;
	obj->SetSelfMute(p0);
}

// Overload functions.

// Binding.
void DiscordVoiceSettings::_bind_methods() {
	ClassDB::bind_method(D_METHOD("automatic_gain_control"),
			&DiscordVoiceSettings::automatic_gain_control);

	ClassDB::bind_method(D_METHOD("echo_cancellation"),
			&DiscordVoiceSettings::echo_cancellation);

	ClassDB::bind_method(D_METHOD("input_mode"),
			&DiscordVoiceSettings::input_mode);

	ClassDB::bind_method(D_METHOD("input_volume"),
			&DiscordVoiceSettings::input_volume);

	ClassDB::bind_method(D_METHOD("noise_cancellation"),
			&DiscordVoiceSettings::noise_cancellation);

	ClassDB::bind_method(D_METHOD("noise_suppression"),
			&DiscordVoiceSettings::noise_suppression);

	ClassDB::bind_method(D_METHOD("output_volume"),
			&DiscordVoiceSettings::output_volume);

	ClassDB::bind_method(D_METHOD("ptt_key"),
			&DiscordVoiceSettings::ptt_key);

	ClassDB::bind_method(D_METHOD("self_deaf"),
			&DiscordVoiceSettings::self_deaf);

	ClassDB::bind_method(D_METHOD("self_mute"),
			&DiscordVoiceSettings::self_mute);

	ClassDB::bind_method(D_METHOD("set_automatic_gain_control", "automatic_gain_control"),
			&DiscordVoiceSettings::set_automatic_gain_control);

	ClassDB::bind_method(D_METHOD("set_echo_cancellation", "echo_cancellation"),
			&DiscordVoiceSettings::set_echo_cancellation);

	ClassDB::bind_method(D_METHOD("set_input_mode", "input_mode"),
			&DiscordVoiceSettings::set_input_mode);

	ClassDB::bind_method(D_METHOD("set_input_volume", "input_volume"),
			&DiscordVoiceSettings::set_input_volume);

	ClassDB::bind_method(D_METHOD("set_noise_cancellation", "noise_cancellation"),
			&DiscordVoiceSettings::set_noise_cancellation);

	ClassDB::bind_method(D_METHOD("set_noise_suppression", "noise_suppression"),
			&DiscordVoiceSettings::set_noise_suppression);

	ClassDB::bind_method(D_METHOD("set_output_volume", "output_volume"),
			&DiscordVoiceSettings::set_output_volume);

	ClassDB::bind_method(D_METHOD("set_ptt_key", "ptt_key"),
			&DiscordVoiceSettings::set_ptt_key);

	ClassDB::bind_method(D_METHOD("set_self_deaf", "self_deaf"),
			&DiscordVoiceSettings::set_self_deaf);

	ClassDB::bind_method(D_METHOD("set_self_mute", "self_mute"),
			&DiscordVoiceSettings::set_self_mute);
}
