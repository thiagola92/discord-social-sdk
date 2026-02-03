
#include "discord_classes.h"

using namespace godot;

// Functions.

DiscordAudioSystem::Enum DiscordClientCreateOptions::experimental_audio_system() {
	auto r = obj->ExperimentalAudioSystem();

	DiscordAudioSystem::Enum cr = (DiscordAudioSystem::Enum)r;
	return cr;
}

String DiscordClientCreateOptions::api_base() {
	auto r = obj->ApiBase();

	String cr = String(r.c_str());
	return cr;
}

String DiscordClientCreateOptions::web_base() {
	auto r = obj->WebBase();

	String cr = String(r.c_str());
	return cr;
}

Variant DiscordClientCreateOptions::cpu_affinity_mask() {
	auto r = obj->CpuAffinityMask();

	Variant cr;

	if (!r.has_value()) {
		cr = nullptr;
	} else {
		auto r_v = r.value();
		int64_t cr_v = (int64_t)r_v;
		cr = Variant(cr_v);
	}

	return cr;
}

bool DiscordClientCreateOptions::experimental_android_prevent_comms_for_bluetooth() {
	auto r = obj->ExperimentalAndroidPreventCommsForBluetooth();

	bool cr = r;
	return cr;
}

void DiscordClientCreateOptions::set_api_base(String api_base) {
	std::string p0 = std::string(api_base.utf8().get_data());
	obj->SetApiBase(p0);
}

void DiscordClientCreateOptions::set_cpu_affinity_mask(Variant cpu_affinity_mask) {
	std::optional<uint64_t> p0;

	if (cpu_affinity_mask.get_type() == Variant::INT) {
		p0 = cpu_affinity_mask;
	}

	obj->SetCpuAffinityMask(p0);
}

void DiscordClientCreateOptions::set_experimental_android_prevent_comms_for_bluetooth(bool experimental_android_prevent_comms_for_bluetooth) {
	bool p0 = experimental_android_prevent_comms_for_bluetooth;
	obj->SetExperimentalAndroidPreventCommsForBluetooth(p0);
}

void DiscordClientCreateOptions::set_experimental_audio_system(DiscordAudioSystem::Enum experimental_audio_system) {
	discordpp::AudioSystem p0 = (discordpp::AudioSystem)experimental_audio_system;
	obj->SetExperimentalAudioSystem(p0);
}

void DiscordClientCreateOptions::set_web_base(String web_base) {
	std::string p0 = std::string(web_base.utf8().get_data());
	obj->SetWebBase(p0);
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
