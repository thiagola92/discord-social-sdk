#include "discord_activity_party.h"

using namespace godot;

discordpp::ActivityParty *DiscordActivityParty::unwrap() {
	return &activity_party;
}

void DiscordActivityParty::_bind_methods() {
    //
}

DiscordActivityParty::DiscordActivityParty() {}

DiscordActivityParty::~DiscordActivityParty() {}
