
#include "discordpp_classes.h"

using namespace godot;

void DiscordppClientCreateOptions::Drop() {
	obj->Drop();
}

String DiscordppClientCreateOptions::WebBase() {
	return String(obj->WebBase().c_str());
}

void DiscordppClientCreateOptions::SetWebBase(String WebBase) {
	std::string p0 = std::string(WebBase.utf8().get_data());

	obj->SetWebBase(p0);
}

String DiscordppClientCreateOptions::ApiBase() {
	return String(obj->ApiBase().c_str());
}

void DiscordppClientCreateOptions::SetApiBase(String ApiBase) {
	std::string p0 = std::string(ApiBase.utf8().get_data());

	obj->SetApiBase(p0);
}

DiscordppAudioSystem::Enum DiscordppClientCreateOptions::ExperimentalAudioSystem() {
	return (DiscordppAudioSystem::Enum)obj->ExperimentalAudioSystem();
}

void DiscordppClientCreateOptions::SetExperimentalAudioSystem(DiscordppAudioSystem::Enum ExperimentalAudioSystem) {
	discordpp::AudioSystem p0 = (discordpp::AudioSystem)ExperimentalAudioSystem;

	obj->SetExperimentalAudioSystem(p0);
}

void DiscordppClientCreateOptions::_bind_methods() {
	ClassDB::bind_method(D_METHOD("Drop"),
			&DiscordppClientCreateOptions::Drop);

	ClassDB::bind_method(D_METHOD("WebBase"),
			&DiscordppClientCreateOptions::WebBase);

	ClassDB::bind_method(D_METHOD("SetWebBase", "WebBase"),
			&DiscordppClientCreateOptions::SetWebBase);

	ClassDB::bind_method(D_METHOD("ApiBase"),
			&DiscordppClientCreateOptions::ApiBase);

	ClassDB::bind_method(D_METHOD("SetApiBase", "ApiBase"),
			&DiscordppClientCreateOptions::SetApiBase);

	ClassDB::bind_method(D_METHOD("ExperimentalAudioSystem"),
			&DiscordppClientCreateOptions::ExperimentalAudioSystem);

	ClassDB::bind_method(D_METHOD("SetExperimentalAudioSystem", "ExperimentalAudioSystem"),
			&DiscordppClientCreateOptions::SetExperimentalAudioSystem);
}
