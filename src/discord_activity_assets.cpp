#include "discord_activity_assets.h"

using namespace godot;

discordpp::ActivityAssets *DiscordActivityAssets::unwrap() {
	return &activity_assets;
}

void DiscordActivityAssets::_bind_methods() {
    //
}

DiscordActivityAssets::DiscordActivityAssets() {}

DiscordActivityAssets::~DiscordActivityAssets() {}
