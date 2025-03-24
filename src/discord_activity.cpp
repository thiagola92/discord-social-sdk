#include "discord_activity.h"

using namespace godot;

discordpp::Activity *DiscordActivity::unwrap() {
	return &activity;
}

void DiscordActivity::_bind_methods() {
    //
}

DiscordActivity::DiscordActivity() {}

DiscordActivity::~DiscordActivity() {}
