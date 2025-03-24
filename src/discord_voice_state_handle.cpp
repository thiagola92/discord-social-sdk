#include "discord_voice_state_handle.h"

using namespace godot;

discordpp::VoiceStateHandle *DiscordVoiceStateHandle::unwrap() {
	return voice_state_handle;
}

void DiscordVoiceStateHandle::_bind_methods() {
    //
}

DiscordVoiceStateHandle::DiscordVoiceStateHandle() {}

DiscordVoiceStateHandle::DiscordVoiceStateHandle(discordpp::VoiceStateHandle *voice_state_handle) {
    this->voice_state_handle = voice_state_handle;
}

DiscordVoiceStateHandle::~DiscordVoiceStateHandle() {}
