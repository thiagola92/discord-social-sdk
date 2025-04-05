// AUTO-GENERATED
#include "discord_classes.h"

using namespace godot;

discordpp::LinkedChannel *DiscordLinkedChannel::unwrap() {
	return linked_channel;
}

uint64_t DiscordLinkedChannel::id() {
	auto r = linked_channel->Id();
	return r;
}

void DiscordLinkedChannel::set_id(uint64_t id) {
	linked_channel->SetId(id);
}

String DiscordLinkedChannel::name() {
	auto r = linked_channel->Name();
	return String(r.c_str());
}

void DiscordLinkedChannel::set_name(String name) {
	auto p0 = name.utf8().get_data();
	linked_channel->SetName(p0);
}

uint64_t DiscordLinkedChannel::guild_id() {
	auto r = linked_channel->GuildId();
	return r;
}

void DiscordLinkedChannel::set_guild_id(uint64_t guild_id) {
	linked_channel->SetGuildId(guild_id);
}

void DiscordLinkedChannel::_bind_methods() {
	ClassDB::bind_method(D_METHOD("id"),
			&DiscordLinkedChannel::id);

	ClassDB::bind_method(D_METHOD("set_id", "id"),
			&DiscordLinkedChannel::set_id);

	ClassDB::bind_method(D_METHOD("name"),
			&DiscordLinkedChannel::name);

	ClassDB::bind_method(D_METHOD("set_name", "name"),
			&DiscordLinkedChannel::set_name);

	ClassDB::bind_method(D_METHOD("guild_id"),
			&DiscordLinkedChannel::guild_id);

	ClassDB::bind_method(D_METHOD("set_guild_id", "guild_id"),
			&DiscordLinkedChannel::set_guild_id);
}

DiscordLinkedChannel::DiscordLinkedChannel() {
}

DiscordLinkedChannel::DiscordLinkedChannel(discordpp::LinkedChannel *linked_channel) {
	this->linked_channel = linked_channel;
}

DiscordLinkedChannel::~DiscordLinkedChannel() {}
