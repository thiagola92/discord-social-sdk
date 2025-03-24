#include "discord_audio_device.h"

using namespace godot;

discordpp::AudioDevice *DiscordAudioDevice::unwrap() {
	return audio_device;
}

void DiscordAudioDevice::_bind_methods() {
	//
}

// DiscordAudioDevice::DiscordAudioDevice() {}

DiscordAudioDevice::~DiscordAudioDevice() {}
