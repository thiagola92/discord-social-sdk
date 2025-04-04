// AUTO-GENERATED
#ifndef DISCORD_AUDIO_DEVICE_H
#define DISCORD_AUDIO_DEVICE_H

#include "discord_audio_device.h"
#include "discordpp.h"
#include "godot_cpp/classes/ref_counted.hpp"
#include "godot_cpp/variant/typed_array.hpp"
#include "godot_cpp/variant/typed_dictionary.hpp"

namespace godot {

class DiscordAudioDevice : public RefCounted {
	GDCLASS(DiscordAudioDevice, RefCounted)

private:
	discordpp::AudioDevice *audio_device;

	DiscordAudioDevice();

protected:
	static void _bind_methods();

public:
	discordpp::AudioDevice *unwrap(); // Internal usage.

	bool equals(DiscordAudioDevice *rhs);
	String id();
	void set_id(String id);
	String name();
	void set_name(String name);
	bool is_default();
	void set_is_default(bool is_default);

	DiscordAudioDevice(discordpp::AudioDevice *audio_device);
	~DiscordAudioDevice();
};

} //namespace godot

#endif
