// AUTO-GENERATED
#include "discord_classes.h"

using namespace godot;

discordpp::VoiceStateHandle *DiscordVoiceStateHandle::unwrap() {
	return voice_state_handle;
}

bool DiscordVoiceStateHandle::self_deaf() {
	auto r = voice_state_handle->SelfDeaf();
	return r;
}

bool DiscordVoiceStateHandle::self_mute() {
	auto r = voice_state_handle->SelfMute();
	return r;
}

void DiscordVoiceStateHandle::_bind_methods() {
	ClassDB::bind_method(D_METHOD("self_deaf"),
			&DiscordVoiceStateHandle::self_deaf);

	ClassDB::bind_method(D_METHOD("self_mute"),
			&DiscordVoiceStateHandle::self_mute);
}

DiscordVoiceStateHandle::DiscordVoiceStateHandle() {
}

DiscordVoiceStateHandle::DiscordVoiceStateHandle(discordpp::VoiceStateHandle *voice_state_handle) {
	this->voice_state_handle = voice_state_handle;
}

DiscordVoiceStateHandle::~DiscordVoiceStateHandle() {}
