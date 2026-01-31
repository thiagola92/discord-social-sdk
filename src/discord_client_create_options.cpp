
#include "discord_classes.h"

using namespace godot;

// Functions.

DiscordAudioSystem DiscordClientCreateOptions::experimental_audio_system() {
}

String DiscordClientCreateOptions::api_base() {
}

String DiscordClientCreateOptions::web_base() {
}

Variant DiscordClientCreateOptions::cpu_affinity_mask() {
}

bool DiscordClientCreateOptions::experimental_android_prevent_comms_for_bluetooth() {
}

void DiscordClientCreateOptions::set_api_base(String api_base) {
	std::string p0 = std::string(api_base.utf8().get_data());
}

void DiscordClientCreateOptions::set_cpu_affinity_mask(Variant cpu_affinity_mask) {
	std::optional<uint64_t> p0;

	if (cpu_affinity_mask.get_type() ==) {
	}
}

void DiscordClientCreateOptions::set_experimental_android_prevent_comms_for_bluetooth(bool experimental_android_prevent_comms_for_bluetooth) {
	bool p0 = experimental_android_prevent_comms_for_bluetooth;
}

void DiscordClientCreateOptions::set_experimental_audio_system(DiscordAudioSystem experimental_audio_system) {
	TODO
}

void DiscordClientCreateOptions::set_web_base(String web_base) {
	std::string p0 = std::string(web_base.utf8().get_data());
}

// Overload functions.

// Binding.
void DiscordClientCreateOptions::_bind_methods() {
	ClassDB::bind_method(D_METHOD("api_base"),
			&DiscordClientCreateOptions::api_base);

	ClassDB::bind_method(D_METHOD("cpu_affinity_mask"),
			&DiscordClientCreateOptions::cpu_affinity_mask);

	ClassDB::bind_method(D_METHOD("experimental_android_prevent_comms_for_bluetooth"),
			&DiscordClientCreateOptions::experimental_android_prevent_comms_for_bluetooth);

	ClassDB::bind_method(D_METHOD("experimental_audio_system"),
			&DiscordClientCreateOptions::experimental_audio_system);

	ClassDB::bind_method(D_METHOD("set_api_base", "api_base"),
			&DiscordClientCreateOptions::set_api_base);

	ClassDB::bind_method(D_METHOD("set_cpu_affinity_mask", "cpu_affinity_mask"),
			&DiscordClientCreateOptions::set_cpu_affinity_mask);

	ClassDB::bind_method(D_METHOD("set_experimental_android_prevent_comms_for_bluetooth", "experimental_android_prevent_comms_for_bluetooth"),
			&DiscordClientCreateOptions::set_experimental_android_prevent_comms_for_bluetooth);

	ClassDB::bind_method(D_METHOD("set_experimental_audio_system", "experimental_audio_system"),
			&DiscordClientCreateOptions::set_experimental_audio_system);

	ClassDB::bind_method(D_METHOD("set_web_base", "web_base"),
			&DiscordClientCreateOptions::set_web_base);

	ClassDB::bind_method(D_METHOD("web_base"),
			&DiscordClientCreateOptions::web_base);
}
