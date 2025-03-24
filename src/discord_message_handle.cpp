#include "discord_message_handle.h"

using namespace godot;

discordpp::MessageHandle *DiscordMessageHandle::unwrap() {
	return message_handle;
}

void DiscordMessageHandle::_bind_methods() {
    //
}

DiscordMessageHandle::DiscordMessageHandle() {}

DiscordMessageHandle::DiscordMessageHandle(discordpp::MessageHandle *message_handle) {
    this->message_handle = message_handle;
}

DiscordMessageHandle::~DiscordMessageHandle() {}
