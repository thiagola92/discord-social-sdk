#ifndef DISCORD_AUDIO_DEVICE_H
#define DISCORD_AUDIO_DEVICE_H

#include "discordpp.h"
#include "godot_cpp/classes/ref_counted.hpp"

namespace godot {

class DiscordAudioDevice : public RefCounted {
	GDCLASS(DiscordAudioDevice, RefCounted)

    DiscordAudioDevice();

private:
	discordpp::AudioDevice *audio_device;

protected:
	static void _bind_methods();

public:
	discordpp::AudioDevice *unwrap(); // Internal usage.

	DiscordAudioDevice(discordpp::AudioDevice *audio_device);
	~DiscordAudioDevice();
};

} //namespace godot

#endif
