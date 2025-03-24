#include "discord_activity_secrets.h"

using namespace godot;

discordpp::ActivitySecrets *DiscordActivitySecrets::unwrap() {
	return &activity_secrets;
}

void DiscordActivitySecrets::_bind_methods() {
    //
}

DiscordActivitySecrets::DiscordActivitySecrets() {}

DiscordActivitySecrets::~DiscordActivitySecrets() {}
