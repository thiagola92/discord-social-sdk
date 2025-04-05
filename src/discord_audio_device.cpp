// AUTO-GENERATED
#include "discord_classes.h"

using namespace godot;

discordpp::AudioDevice *DiscordAudioDevice::unwrap() {
	return audio_device;
}

bool DiscordAudioDevice::equals(DiscordAudioDevice *rhs) {
	auto p0 = *rhs->unwrap();
	auto r = audio_device->Equals(p0);
	return r;
}

String DiscordAudioDevice::id() {
	auto r = audio_device->Id();
	return String(r.c_str());
}

void DiscordAudioDevice::set_id(String id) {
	auto p0 = id.utf8().get_data();
	audio_device->SetId(p0);
}

String DiscordAudioDevice::name() {
	auto r = audio_device->Name();
	return String(r.c_str());
}

void DiscordAudioDevice::set_name(String name) {
	auto p0 = name.utf8().get_data();
	audio_device->SetName(p0);
}

bool DiscordAudioDevice::is_default() {
	auto r = audio_device->IsDefault();
	return r;
}

void DiscordAudioDevice::set_is_default(bool is_default) {
	audio_device->SetIsDefault(is_default);
}

void DiscordAudioDevice::_bind_methods() {
	ClassDB::bind_method(D_METHOD("equals", "rhs"),
			&DiscordAudioDevice::equals);

	ClassDB::bind_method(D_METHOD("id"),
			&DiscordAudioDevice::id);

	ClassDB::bind_method(D_METHOD("set_id", "id"),
			&DiscordAudioDevice::set_id);

	ClassDB::bind_method(D_METHOD("name"),
			&DiscordAudioDevice::name);

	ClassDB::bind_method(D_METHOD("set_name", "name"),
			&DiscordAudioDevice::set_name);

	ClassDB::bind_method(D_METHOD("is_default"),
			&DiscordAudioDevice::is_default);

	ClassDB::bind_method(D_METHOD("set_is_default", "is_default"),
			&DiscordAudioDevice::set_is_default);
}

DiscordAudioDevice::DiscordAudioDevice() {
}

DiscordAudioDevice::DiscordAudioDevice(discordpp::AudioDevice *audio_device) {
	this->audio_device = audio_device;
}

DiscordAudioDevice::~DiscordAudioDevice() {}
