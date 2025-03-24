#include "discord_linked_channel.h"

using namespace godot;

discordpp::LinkedChannel *DiscordLinkedChannel::unwrap() {
	return linked_channel;
}

void DiscordLinkedChannel::_bind_methods() {
	//
}

// DiscordLinkedChannel::DiscordLinkedChannel() {}

DiscordLinkedChannel::~DiscordLinkedChannel() {}
