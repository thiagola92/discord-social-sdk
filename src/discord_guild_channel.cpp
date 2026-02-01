
#include "discord_classes.h"

using namespace godot;

// Functions.

DiscordChannelType DiscordGuildChannel::type() {
}

String DiscordGuildChannel::name() {
}

Variant DiscordGuildChannel::linked_lobby() {
}

Variant DiscordGuildChannel::parent_id() {
}

bool DiscordGuildChannel::is_linkable() {
}

bool DiscordGuildChannel::is_viewable_and_writeable_by_all_members() {
}

int64_t DiscordGuildChannel::id() {
}

int64_t DiscordGuildChannel::position() {
}

void DiscordGuildChannel::set_id(int64_t id) {
	int64_t p0 = id;
}

void DiscordGuildChannel::set_is_linkable(bool is_linkable) {
	bool p0 = is_linkable;
}

void DiscordGuildChannel::set_is_viewable_and_writeable_by_all_members(bool is_viewable_and_writeable_by_all_members) {
	bool p0 = is_viewable_and_writeable_by_all_members;
}

void DiscordGuildChannel::set_linked_lobby(Variant linked_lobby) {
	std::optional<discordpp::LinkedLobby> p0;

	if (linked_lobby.get_type() == Variant::OBJECT) {
	}
}

void DiscordGuildChannel::set_name(String name) {
	std::string p0 = std::string(name.utf8().get_data());
}

void DiscordGuildChannel::set_parent_id(Variant parent_id) {
	std::optional<uint64_t> p0;

	if (parent_id.get_type() == Variant::INT) {
		p0 = parent_id;
	}
}

void DiscordGuildChannel::set_position(int64_t position) {
	int64_t p0 = position;
}

void DiscordGuildChannel::set_type(DiscordChannelType type) {
	// TODO
}

// Overload functions.

// Binding.
void DiscordGuildChannel::_bind_methods() {
	ClassDB::bind_method(D_METHOD("id"),
			&DiscordGuildChannel::id);

	ClassDB::bind_method(D_METHOD("is_linkable"),
			&DiscordGuildChannel::is_linkable);

	ClassDB::bind_method(D_METHOD("is_viewable_and_writeable_by_all_members"),
			&DiscordGuildChannel::is_viewable_and_writeable_by_all_members);

	ClassDB::bind_method(D_METHOD("linked_lobby"),
			&DiscordGuildChannel::linked_lobby);

	ClassDB::bind_method(D_METHOD("name"),
			&DiscordGuildChannel::name);

	ClassDB::bind_method(D_METHOD("parent_id"),
			&DiscordGuildChannel::parent_id);

	ClassDB::bind_method(D_METHOD("position"),
			&DiscordGuildChannel::position);

	ClassDB::bind_method(D_METHOD("set_id", "id"),
			&DiscordGuildChannel::set_id);

	ClassDB::bind_method(D_METHOD("set_is_linkable", "is_linkable"),
			&DiscordGuildChannel::set_is_linkable);

	ClassDB::bind_method(D_METHOD("set_is_viewable_and_writeable_by_all_members", "is_viewable_and_writeable_by_all_members"),
			&DiscordGuildChannel::set_is_viewable_and_writeable_by_all_members);

	ClassDB::bind_method(D_METHOD("set_linked_lobby", "linked_lobby"),
			&DiscordGuildChannel::set_linked_lobby);

	ClassDB::bind_method(D_METHOD("set_name", "name"),
			&DiscordGuildChannel::set_name);

	ClassDB::bind_method(D_METHOD("set_parent_id", "parent_id"),
			&DiscordGuildChannel::set_parent_id);

	ClassDB::bind_method(D_METHOD("set_position", "position"),
			&DiscordGuildChannel::set_position);

	ClassDB::bind_method(D_METHOD("set_type", "type"),
			&DiscordGuildChannel::set_type);

	ClassDB::bind_method(D_METHOD("type"),
			&DiscordGuildChannel::type);
}
