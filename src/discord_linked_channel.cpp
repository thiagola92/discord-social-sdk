
#include "discord_classes.h"

using namespace godot;

// Functions.

String DiscordLinkedChannel::name() {
	auto r0 = obj->Name();

	String r1 = String(r0.c_str());

	return r1;
}

int64_t DiscordLinkedChannel::guild_id() {
	auto r0 = obj->GuildId();

	int64_t r1 = (int64_t)r0;

	return r1;
}

int64_t DiscordLinkedChannel::id() {
	auto r0 = obj->Id();

	int64_t r1 = (int64_t)r0;

	return r1;
}

void DiscordLinkedChannel::set_guild_id(int64_t guild_id) {
	int64_t p0 = guild_id;
	obj->SetGuildId(p0);
}

void DiscordLinkedChannel::set_id(int64_t id) {
	int64_t p0 = id;
	obj->SetId(p0);
}

void DiscordLinkedChannel::set_name(String name) {
	std::string p0 = std::string(name.utf8().get_data());
	obj->SetName(p0);
}

// Overload functions.

// Binding.
void DiscordLinkedChannel::_bind_methods() {
	ClassDB::bind_method(D_METHOD("guild_id"),
			&DiscordLinkedChannel::guild_id);

	ClassDB::bind_method(D_METHOD("id"),
			&DiscordLinkedChannel::id);

	ClassDB::bind_method(D_METHOD("name"),
			&DiscordLinkedChannel::name);

	ClassDB::bind_method(D_METHOD("set_guild_id", "guild_id"),
			&DiscordLinkedChannel::set_guild_id);

	ClassDB::bind_method(D_METHOD("set_id", "id"),
			&DiscordLinkedChannel::set_id);

	ClassDB::bind_method(D_METHOD("set_name", "name"),
			&DiscordLinkedChannel::set_name);
}
