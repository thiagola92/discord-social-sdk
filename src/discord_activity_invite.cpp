#include "discord_activity_invite.h"

using namespace godot;

discordpp::ActivityInvite *DiscordActivityInvite::unwrap() {
	return &activity_invite;
}

void DiscordActivityInvite::_bind_methods() {
    //
}

DiscordActivityInvite::DiscordActivityInvite() {}

DiscordActivityInvite::~DiscordActivityInvite() {}
