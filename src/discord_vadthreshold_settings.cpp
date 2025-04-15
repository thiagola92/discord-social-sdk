
#include "discord_classes.h"

using namespace godot;

void DiscordppVADThresholdSettings::Drop() {
	obj->Drop();
}

float DiscordppVADThresholdSettings::VadThreshold() {
	return obj->VadThreshold();
}

void DiscordppVADThresholdSettings::SetVadThreshold(float VadThreshold) {
	auto p0 = VadThreshold;
	obj->SetVadThreshold(p0);
}

bool DiscordppVADThresholdSettings::Automatic() {
	return obj->Automatic();
}

void DiscordppVADThresholdSettings::SetAutomatic(bool Automatic) {
	auto p0 = Automatic;
	obj->SetAutomatic(p0);
}

void DiscordppVADThresholdSettings::_bind_methods() {
	ClassDB::bind_method(D_METHOD("Drop"),
			&DiscordppVADThresholdSettings::Drop);

	ClassDB::bind_method(D_METHOD("VadThreshold"),
			&DiscordppVADThresholdSettings::VadThreshold);

	ClassDB::bind_method(D_METHOD("SetVadThreshold", "VadThreshold"),
			&DiscordppVADThresholdSettings::SetVadThreshold);

	ClassDB::bind_method(D_METHOD("Automatic"),
			&DiscordppVADThresholdSettings::Automatic);

	ClassDB::bind_method(D_METHOD("SetAutomatic", "Automatic"),
			&DiscordppVADThresholdSettings::SetAutomatic);
}
