
#include "discord_classes.h"

using namespace godot;

// Functions.

bool DiscordVADThresholdSettings::automatic() {
	auto r0 = obj->Automatic();

	bool r1 = r0;

	return r1;
}

real_t DiscordVADThresholdSettings::vad_threshold() {
	auto r0 = obj->VadThreshold();

	real_t r1 = (real_t)r0;

	return r1;
}

void DiscordVADThresholdSettings::set_automatic(bool automatic) {
	bool p0 = automatic;
	obj->SetAutomatic(p0);
}

void DiscordVADThresholdSettings::set_vad_threshold(real_t vad_threshold) {
	float p0 = (float)vad_threshold;
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
