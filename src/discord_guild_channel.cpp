// AUTO-GENERATED
#include "discord_classes.h"

using namespace godot;

discordpp::GuildChannel *DiscordGuildChannel::unwrap() {
	return guild_channel;
}

uint64_t DiscordGuildChannel::id() {
	auto r = guild_channel->Id();
	return r;
}

void DiscordGuildChannel::set_id(uint64_t id) {
	guild_channel->SetId(id);
}

String DiscordGuildChannel::name() {
	auto r = guild_channel->Name();
	return String(r.c_str());
}

void DiscordGuildChannel::set_name(String name) {
	auto p0 = name.utf8().get_data();
	guild_channel->SetName(p0);
}

bool DiscordGuildChannel::is_linkable() {
	auto r = guild_channel->IsLinkable();
	return r;
}

void DiscordGuildChannel::set_is_linkable(bool is_linkable) {
	guild_channel->SetIsLinkable(is_linkable);
}

bool DiscordGuildChannel::is_viewable_and_writeable_by_all_members() {
	auto r = guild_channel->IsViewableAndWriteableByAllMembers();
	return r;
}

void DiscordGuildChannel::set_is_viewable_and_writeable_by_all_members(bool is_viewable_and_writeable_by_all_members) {
	guild_channel->SetIsViewableAndWriteableByAllMembers(is_viewable_and_writeable_by_all_members);
}

Variant DiscordGuildChannel::linked_lobby() {
	auto r = guild_channel->LinkedLobby();

	if (!r.has_value()) {
		return nullptr;
	}

	auto t_r = (discordpp::LinkedLobby *)memalloc(sizeof(discordpp::LinkedLobby));
	*t_r = r.value();
	return Variant(memnew(DiscordLinkedLobby{ t_r }));
}

void DiscordGuildChannel::set_linked_lobby(Variant linked_lobby) {
	std::optional<discordpp::LinkedLobby> p0;

	if (linked_lobby.get_type() == Variant::OBJECT) {
		auto t_p0 = Object::cast_to<DiscordLinkedLobby>(linked_lobby);
		auto t2_p0 = t_p0->unwrap();
		p0 = std::optional<discordpp::LinkedLobby>{ *t2_p0 };
	}

	guild_channel->SetLinkedLobby(p0);
}

void DiscordGuildChannel::_bind_methods() {
	ClassDB::bind_method(D_METHOD("id"),
			&DiscordGuildChannel::id);

	ClassDB::bind_method(D_METHOD("set_id", "id"),
			&DiscordGuildChannel::set_id);

	ClassDB::bind_method(D_METHOD("name"),
			&DiscordGuildChannel::name);

	ClassDB::bind_method(D_METHOD("set_name", "name"),
			&DiscordGuildChannel::set_name);

	ClassDB::bind_method(D_METHOD("is_linkable"),
			&DiscordGuildChannel::is_linkable);

	ClassDB::bind_method(D_METHOD("set_is_linkable", "is_linkable"),
			&DiscordGuildChannel::set_is_linkable);

	ClassDB::bind_method(D_METHOD("is_viewable_and_writeable_by_all_members"),
			&DiscordGuildChannel::is_viewable_and_writeable_by_all_members);

	ClassDB::bind_method(D_METHOD("set_is_viewable_and_writeable_by_all_members", "is_viewable_and_writeable_by_all_members"),
			&DiscordGuildChannel::set_is_viewable_and_writeable_by_all_members);

	ClassDB::bind_method(D_METHOD("linked_lobby"),
			&DiscordGuildChannel::linked_lobby);

	ClassDB::bind_method(D_METHOD("set_linked_lobby", "linked_lobby"),
			&DiscordGuildChannel::set_linked_lobby);
}

DiscordGuildChannel::DiscordGuildChannel() {
}

DiscordGuildChannel::DiscordGuildChannel(discordpp::GuildChannel *guild_channel) {
	this->guild_channel = guild_channel;
}

DiscordGuildChannel::~DiscordGuildChannel() {}
