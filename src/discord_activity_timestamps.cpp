#include "discord_activity_timestamps.h"

using namespace godot;

discordpp::ActivityTimestamps *DiscordActivityTimestamps::unwrap() {
	return &activity_timestamps;
}

void DiscordActivityTimestamps::_bind_methods() {
    //
}

DiscordActivityTimestamps::DiscordActivityTimestamps() {}

DiscordActivityTimestamps::~DiscordActivityTimestamps() {}
