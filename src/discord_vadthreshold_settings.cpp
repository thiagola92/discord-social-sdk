// AUTO-GENERATED
#include "discord_vadthreshold_settings.h"

using namespace godot;

discordpp::VADThresholdSettings *DiscordVADThresholdSettings::unwrap() {
	return vadthreshold_settings;
}

float DiscordVADThresholdSettings::vad_threshold() {
	auto r = vadthreshold_settings->VadThreshold();
	return r;
}

void DiscordVADThresholdSettings::set_vad_threshold(float vad_threshold) {
	vadthreshold_settings->SetVadThreshold(vad_threshold);
}

bool DiscordVADThresholdSettings::automatic() {
	auto r = vadthreshold_settings->Automatic();
	return r;
}

void DiscordVADThresholdSettings::set_automatic(bool automatic) {
	vadthreshold_settings->SetAutomatic(automatic);
}

void DiscordVADThresholdSettings::_bind_methods() {
	ClassDB::bind_method(D_METHOD("vad_threshold"),
			&DiscordVADThresholdSettings::vad_threshold);

	ClassDB::bind_method(D_METHOD("set_vad_threshold", "vad_threshold"),
			&DiscordVADThresholdSettings::set_vad_threshold);

	ClassDB::bind_method(D_METHOD("automatic"),
			&DiscordVADThresholdSettings::automatic);

	ClassDB::bind_method(D_METHOD("set_automatic", "automatic"),
			&DiscordVADThresholdSettings::set_automatic);
}

DiscordVADThresholdSettings::DiscordVADThresholdSettings() {
}

DiscordVADThresholdSettings::DiscordVADThresholdSettings(discordpp::VADThresholdSettings *vadthreshold_settings) {
	this->vadthreshold_settings = vadthreshold_settings;
}

DiscordVADThresholdSettings::~DiscordVADThresholdSettings() {}
