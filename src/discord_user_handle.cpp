#include "discord_user_handle.h"

using namespace godot;

discordpp::UserHandle *DiscordUserHandle::unwrap() {
	return user_handle;
}

void DiscordUserHandle::_bind_methods() {
	//
}

// DiscordUserHandle::DiscordUserHandle() {}

DiscordUserHandle::~DiscordUserHandle() {}
