// AUTO-GENERATED
#include "discord_guild_minimal.h"

using namespace godot;

discordpp::GuildMinimal *DiscordGuildMinimal::unwrap() {
	return guild_minimal;
}

uint64_t DiscordGuildMinimal::id() {
	auto r = guild_minimal->Id();
	return r;
}

void DiscordGuildMinimal::set_id(uint64_t id) {
	guild_minimal->SetId(id);
}

String DiscordGuildMinimal::name() {
	auto r = guild_minimal->Name();
	return String(r.c_str());
}

void DiscordGuildMinimal::set_name(String name) {
	auto p0 = name.utf8().get_data();
	guild_minimal->SetName(p0);
}

void DiscordGuildMinimal::_bind_methods() {
	ClassDB::bind_method(D_METHOD("id"),
			&DiscordGuildMinimal::id);

	ClassDB::bind_method(D_METHOD("set_id", "id"),
			&DiscordGuildMinimal::set_id);

	ClassDB::bind_method(D_METHOD("name"),
			&DiscordGuildMinimal::name);

	ClassDB::bind_method(D_METHOD("set_name", "name"),
			&DiscordGuildMinimal::set_name);
}

DiscordGuildMinimal::DiscordGuildMinimal() {
}

DiscordGuildMinimal::DiscordGuildMinimal(discordpp::GuildMinimal *guild_minimal) {
	this->guild_minimal = guild_minimal;
}

DiscordGuildMinimal::~DiscordGuildMinimal() {}
