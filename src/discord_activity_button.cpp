
#include "discord_classes.h"

using namespace godot;

// Functions.

String DiscordActivityButton::label() {
}

String DiscordActivityButton::url() {
}

void DiscordActivityButton::set_label(String label) {
	std::string p0 = std::string(label.utf8().get_data());
}

void DiscordActivityButton::set_url(String url) {
	std::string p0 = std::string(url.utf8().get_data());
}

// Overload functions.

// Binding.
void DiscordActivityButton::_bind_methods() {
	ClassDB::bind_method(D_METHOD("label"),
			&DiscordActivityButton::label);

	ClassDB::bind_method(D_METHOD("set_label", "label"),
			&DiscordActivityButton::set_label);

	ClassDB::bind_method(D_METHOD("set_url", "url"),
			&DiscordActivityButton::set_url);

	ClassDB::bind_method(D_METHOD("url"),
			&DiscordActivityButton::url);
}
