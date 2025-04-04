// AUTO-GENERATED
#ifndef DISCORD_VOICE_STATE_HANDLE_H
#define DISCORD_VOICE_STATE_HANDLE_H

#include "discordpp.h"
#include "godot_cpp/classes/ref_counted.hpp"
#include "godot_cpp/variant/typed_array.hpp"
#include "godot_cpp/variant/typed_dictionary.hpp"

namespace godot {

class DiscordVoiceStateHandle : public RefCounted {
	GDCLASS(DiscordVoiceStateHandle, RefCounted)

private:
	discordpp::VoiceStateHandle *voice_state_handle;

	DiscordVoiceStateHandle();

protected:
	static void _bind_methods();

public:
	discordpp::VoiceStateHandle *unwrap(); // Internal usage.

	bool self_deaf();
	bool self_mute();

	DiscordVoiceStateHandle(discordpp::VoiceStateHandle *voice_state_handle);
	~DiscordVoiceStateHandle();
};

} //namespace godot

#endif
