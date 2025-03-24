#include "discord_channel_handle.h"

using namespace godot;

discordpp::ChannelHandle *DiscordChannelHandle::unwrap() {
	return channel_handle;
}

void DiscordChannelHandle::_bind_methods() {
	//
}

// DiscordChannelHandle::DiscordChannelHandle() {}

DiscordChannelHandle::~DiscordChannelHandle() {}
