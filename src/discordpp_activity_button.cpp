
#include "discordpp_classes.h"

using namespace godot;

void DiscordppActivityButton::Drop() {
	obj->Drop();
}

String DiscordppActivityButton::Label() {
	return String(obj->Label().c_str());
}

void DiscordppActivityButton::SetLabel(String Label) {
	std::string p0 = std::string(Label.utf8().get_data());

	obj->SetLabel(p0);
}

String DiscordppActivityButton::Url() {
	return String(obj->Url().c_str());
}

void DiscordppActivityButton::SetUrl(String Url) {
	std::string p0 = std::string(Url.utf8().get_data());

	obj->SetUrl(p0);
}

void DiscordppActivityButton::_bind_methods() {
	ClassDB::bind_method(D_METHOD("Drop"),
			&DiscordppActivityButton::Drop);

	ClassDB::bind_method(D_METHOD("Label"),
			&DiscordppActivityButton::Label);

	ClassDB::bind_method(D_METHOD("SetLabel", "Label"),
			&DiscordppActivityButton::SetLabel);

	ClassDB::bind_method(D_METHOD("Url"),
			&DiscordppActivityButton::Url);

	ClassDB::bind_method(D_METHOD("SetUrl", "Url"),
			&DiscordppActivityButton::SetUrl);
}
