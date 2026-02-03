
#include "discord_classes.h"

using namespace godot;

// Functions.

DiscordActivityPartyPrivacy::Enum DiscordActivityParty::privacy() {
	auto r = obj->Privacy();

	DiscordActivityPartyPrivacy::Enum cr = (DiscordActivityPartyPrivacy::Enum)r;
	return cr;
}

String DiscordActivityParty::id() {
	auto r = obj->Id();

	String cr = String(r.c_str());
	return cr;
}

int64_t DiscordActivityParty::current_size() {
	auto r = obj->CurrentSize();

	int64_t cr = (int64_t)r;
	return cr;
}

int64_t DiscordActivityParty::max_size() {
	auto r = obj->MaxSize();

	int64_t cr = (int64_t)r;
	return cr;
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
