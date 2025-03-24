#include "discord_user_handle.h"

using namespace godot;

discordpp::UserHandle *DiscordUserHandle::unwrap() {
	return user_handle;
}

void DiscordUserHandle::_bind_methods() {
    //
}

DiscordUserHandle::DiscordUserHandle() {}

DiscordUserHandle::DiscordUserHandle(discordpp::UserHandle *user_handle) {
    this->user_handle = user_handle;
}

DiscordUserHandle::~DiscordUserHandle() {}
