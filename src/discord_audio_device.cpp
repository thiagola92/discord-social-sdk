#include "discord_audio_device.h"

using namespace godot;

discordpp::AudioDevice *DiscordAudioDevice::unwrap() {
	return audio_device;
}

void DiscordAudioDevice::_bind_methods() {
    //
}

DiscordAudioDevice::DiscordAudioDevice() {}

DiscordAudioDevice::DiscordAudioDevice(discordpp::AudioDevice *audio_device) {
    this->audio_device = audio_device;
}

DiscordAudioDevice::~DiscordAudioDevice() {}
