#ifndef DISCORD_AUDIO_DEVICE_H
#define DISCORD_AUDIO_DEVICE_H

#include "discordpp.h"
#include "godot_cpp/classes/ref_counted.hpp"

namespace godot {

class DiscordAudioDevice : public RefCounted {
	GDCLASS(DiscordAudioDevice, RefCounted)

private:
	discordpp::AudioDevice audio_device;

protected:
	static void _bind_methods();

public:
	discordpp::AudioDevice *unwrap(); // Internal usage.

	DiscordAudioDevice();
	~DiscordAudioDevice();
};

} //namespace godot

#endif
