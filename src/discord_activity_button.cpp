
#include "discord_classes.h"

using namespace godot;

// Functions.

String DiscordActivityButton::label() {
	auto r0 = obj->Label();

	String r1 = String(r0.c_str());

	return r1;
}

String DiscordActivityButton::url() {
	auto r0 = obj->Url();

	String r1 = String(r0.c_str());

	return r1;
}

void DiscordActivityButton::set_label(String label) {
	std::string p0 = std::string(label.utf8().get_data());
	obj->SetLabel(p0);
}

void DiscordActivityButton::set_url(String url) {
	std::string p0 = std::string(url.utf8().get_data());
	obj->SetUrl(p0);
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
