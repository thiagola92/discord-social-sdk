
#include "discord_classes.h"

using namespace godot;

// Functions.

bool DiscordVADThresholdSettings::automatic() {
	auto r = obj->Automatic();
}

float DiscordVADThresholdSettings::vad_threshold() {
	auto r = obj->VadThreshold();
}

void DiscordVADThresholdSettings::set_automatic(bool automatic) {
	bool p0 = automatic;
	obj->SetAutomatic(p0);
}

void DiscordVADThresholdSettings::set_vad_threshold(float vad_threshold) {
	float p0 = vad_threshold;
	obj->SetVadThreshold(p0);
}

// Overload functions.

// Binding.
void DiscordVADThresholdSettings::_bind_methods() {
	ClassDB::bind_method(D_METHOD("automatic"),
			&DiscordVADThresholdSettings::automatic);

	ClassDB::bind_method(D_METHOD("set_automatic", "automatic"),
			&DiscordVADThresholdSettings::set_automatic);

	ClassDB::bind_method(D_METHOD("set_vad_threshold", "vad_threshold"),
			&DiscordVADThresholdSettings::set_vad_threshold);

	ClassDB::bind_method(D_METHOD("vad_threshold"),
			&DiscordVADThresholdSettings::vad_threshold);
}
