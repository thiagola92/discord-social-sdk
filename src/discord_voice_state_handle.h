#ifndef DISCORD_VOICE_STATE_HANDLE_H
#define DISCORD_VOICE_STATE_HANDLE_H

#include "discordpp.h"
#include "godot_cpp/classes/ref_counted.hpp"

namespace godot {

class DiscordVoiceStateHandle : public RefCounted {
	GDCLASS(DiscordVoiceStateHandle, RefCounted)

private:
	discordpp::VoiceStateHandle *voice_state_handle;

protected:
	static void _bind_methods();

public:
	discordpp::VoiceStateHandle *unwrap(); // Internal usage.

	// DiscordVoiceStateHandle();
	~DiscordVoiceStateHandle();
};

} //namespace godot

#endif
