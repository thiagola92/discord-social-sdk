
#include "discord_classes.h"

using namespace godot;

// Functions.

bool DiscordVoiceStateHandle::self_deaf() {
	auto r0 = obj->SelfDeaf();

	bool r1 = r0;

	return r1;
}

bool DiscordVoiceStateHandle::self_mute() {
	auto r0 = obj->SelfMute();

	bool r1 = r0;

	return r1;
}

// Overload functions.

// Binding.
void DiscordVoiceStateHandle::_bind_methods() {
	ClassDB::bind_method(D_METHOD("self_deaf"),
			&DiscordVoiceStateHandle::self_deaf);

	ClassDB::bind_method(D_METHOD("self_mute"),
			&DiscordVoiceStateHandle::self_mute);
}
