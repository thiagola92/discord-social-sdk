
#include "discord_classes.h"

using namespace godot;

// Functions.

String DiscordAudioDevice::id() {
}

String DiscordAudioDevice::name() {
}

bool DiscordAudioDevice::equals(DiscordAudioDevice *rhs) {
	discordpp::AudioDevice p0 = *rhs->unwrap();
}

bool DiscordAudioDevice::is_default() {
}

void DiscordAudioDevice::set_id(String id) {
	std::string p0 = std::string(id.utf8().get_data());
}

void DiscordAudioDevice::set_is_default(bool is_default) {
	bool p0 = is_default;
}

void DiscordAudioDevice::set_name(String name) {
	std::string p0 = std::string(name.utf8().get_data());
}

// Overload functions.

// Binding.
void DiscordAudioDevice::_bind_methods() {
	ClassDB::bind_method(D_METHOD("equals", "rhs"),
			&DiscordAudioDevice::equals);

	ClassDB::bind_method(D_METHOD("id"),
			&DiscordAudioDevice::id);

	ClassDB::bind_method(D_METHOD("is_default"),
			&DiscordAudioDevice::is_default);

	ClassDB::bind_method(D_METHOD("name"),
			&DiscordAudioDevice::name);

	ClassDB::bind_method(D_METHOD("set_id", "id"),
			&DiscordAudioDevice::set_id);

	ClassDB::bind_method(D_METHOD("set_is_default", "is_default"),
			&DiscordAudioDevice::set_is_default);

	ClassDB::bind_method(D_METHOD("set_name", "name"),
			&DiscordAudioDevice::set_name);
}
