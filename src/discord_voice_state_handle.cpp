
#include "discord_classes.h"

using namespace godot;

void DiscordppVoiceStateHandle::Drop() {
	obj->Drop();
}

bool DiscordppVoiceStateHandle::SelfDeaf() {
	return obj->SelfDeaf();
}

bool DiscordppVoiceStateHandle::SelfMute() {
	return obj->SelfMute();
}

void DiscordppVoiceStateHandle::_bind_methods() {
	ClassDB::bind_method(D_METHOD("Drop"),
			&DiscordppVoiceStateHandle::Drop);

	ClassDB::bind_method(D_METHOD("SelfDeaf"),
			&DiscordppVoiceStateHandle::SelfDeaf);

	ClassDB::bind_method(D_METHOD("SelfMute"),
			&DiscordppVoiceStateHandle::SelfMute);
}
