#include "discord_vadthreshold_settings.h"

using namespace godot;

discordpp::VADThresholdSettings *DiscordVADThresholdSettings::unwrap() {
	return vadthreshold_settings;
}

void DiscordVADThresholdSettings::_bind_methods() {
	//
}

// DiscordVADThresholdSettings::DiscordVADThresholdSettings() {}

DiscordVADThresholdSettings::~DiscordVADThresholdSettings() {}
