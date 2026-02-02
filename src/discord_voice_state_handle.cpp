
#include "discord_classes.h"

using namespace godot;

// Functions.

bool DiscordVoiceStateHandle::self_deaf() {
	auto r = obj->SelfDeaf();
}

bool DiscordVoiceStateHandle::self_mute() {
	auto r = obj->SelfMute();
}

// Overload functions.

// Binding.
void DiscordVoiceStateHandle::_bind_methods() {
	ClassDB::bind_method(D_METHOD("self_deaf"),
			&DiscordVoiceStateHandle::self_deaf);

	ClassDB::bind_method(D_METHOD("self_mute"),
			&DiscordVoiceStateHandle::self_mute);
}
