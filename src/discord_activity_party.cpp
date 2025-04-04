// AUTO-GENERATED
#include "discord_activity_party.h"

using namespace godot;

discordpp::ActivityParty *DiscordActivityParty::unwrap() {
	return activity_party;
}

String DiscordActivityParty::id() {
	auto r = activity_party->Id();
	return String(r.c_str());
}

void DiscordActivityParty::set_id(String id) {
	auto p0 = id.utf8().get_data();
	activity_party->SetId(p0);
}

int32_t DiscordActivityParty::current_size() {
	auto r = activity_party->CurrentSize();
	return r;
}

void DiscordActivityParty::set_current_size(int32_t current_size) {
	activity_party->SetCurrentSize(current_size);
}

int32_t DiscordActivityParty::max_size() {
	auto r = activity_party->MaxSize();
	return r;
}

void DiscordActivityParty::set_max_size(int32_t max_size) {
	activity_party->SetMaxSize(max_size);
}

DiscordActivityPartyPrivacy::Enum DiscordActivityParty::privacy() {
	auto r = activity_party->Privacy();
	return (DiscordActivityPartyPrivacy::Enum)r;
}

void DiscordActivityParty::set_privacy(DiscordActivityPartyPrivacy::Enum privacy) {
	auto p0 = (discordpp::ActivityPartyPrivacy)privacy;
	activity_party->SetPrivacy(p0);
}

void DiscordActivityParty::_bind_methods() {
	ClassDB::bind_method(D_METHOD("id"),
			&DiscordActivityParty::id);

	ClassDB::bind_method(D_METHOD("set_id", "id"),
			&DiscordActivityParty::set_id);

	ClassDB::bind_method(D_METHOD("current_size"),
			&DiscordActivityParty::current_size);

	ClassDB::bind_method(D_METHOD("set_current_size", "current_size"),
			&DiscordActivityParty::set_current_size);

	ClassDB::bind_method(D_METHOD("max_size"),
			&DiscordActivityParty::max_size);

	ClassDB::bind_method(D_METHOD("set_max_size", "max_size"),
			&DiscordActivityParty::set_max_size);

	ClassDB::bind_method(D_METHOD("privacy"),
			&DiscordActivityParty::privacy);

	ClassDB::bind_method(D_METHOD("set_privacy", "privacy"),
			&DiscordActivityParty::set_privacy);
}

DiscordActivityParty::DiscordActivityParty() {
	this->activity_party = memnew(discordpp::ActivityParty);
}

DiscordActivityParty::DiscordActivityParty(discordpp::ActivityParty *activity_party) {
	this->activity_party = activity_party;
}

DiscordActivityParty::~DiscordActivityParty() {}
