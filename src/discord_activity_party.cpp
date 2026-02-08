
#include "discord_classes.h"

using namespace godot;

// Functions.

DiscordActivityPartyPrivacy::Enum DiscordActivityParty::privacy() {
	auto r0 = obj->Privacy();

	DiscordActivityPartyPrivacy::Enum r1 = (DiscordActivityPartyPrivacy::Enum)r0;

	return r1;
}

String DiscordActivityParty::id() {
	auto r0 = obj->Id();

	String r1 = String(r0.c_str());

	return r1;
}

int64_t DiscordActivityParty::current_size() {
	auto r0 = obj->CurrentSize();

	int64_t r1 = (int64_t)r0;

	return r1;
}

int64_t DiscordActivityParty::max_size() {
	auto r0 = obj->MaxSize();

	int64_t r1 = (int64_t)r0;

	return r1;
}

void DiscordActivityParty::set_current_size(int64_t current_size) {
	int64_t p0 = current_size;
	obj->SetCurrentSize(p0);
}

void DiscordActivityParty::set_id(String id) {
	std::string p0 = std::string(id.utf8().get_data());
	obj->SetId(p0);
}

void DiscordActivityParty::set_max_size(int64_t max_size) {
	int64_t p0 = max_size;
	obj->SetMaxSize(p0);
}

void DiscordActivityParty::set_privacy(DiscordActivityPartyPrivacy::Enum privacy) {
	discordpp::ActivityPartyPrivacy p0 = (discordpp::ActivityPartyPrivacy)privacy;
	obj->SetPrivacy(p0);
}

// Overload functions.

// Binding.
void DiscordActivityParty::_bind_methods() {
	ClassDB::bind_method(D_METHOD("current_size"),
			&DiscordActivityParty::current_size);

	ClassDB::bind_method(D_METHOD("id"),
			&DiscordActivityParty::id);

	ClassDB::bind_method(D_METHOD("max_size"),
			&DiscordActivityParty::max_size);

	ClassDB::bind_method(D_METHOD("privacy"),
			&DiscordActivityParty::privacy);

	ClassDB::bind_method(D_METHOD("set_current_size", "current_size"),
			&DiscordActivityParty::set_current_size);

	ClassDB::bind_method(D_METHOD("set_id", "id"),
			&DiscordActivityParty::set_id);

	ClassDB::bind_method(D_METHOD("set_max_size", "max_size"),
			&DiscordActivityParty::set_max_size);

	ClassDB::bind_method(D_METHOD("set_privacy", "privacy"),
			&DiscordActivityParty::set_privacy);
}
