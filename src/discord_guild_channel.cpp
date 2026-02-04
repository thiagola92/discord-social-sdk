
#include "discord_classes.h"

using namespace godot;

// Functions.

DiscordChannelType::Enum DiscordGuildChannel::type() {
	auto r0 = obj->Type();

	DiscordChannelType::Enum r1 = (DiscordChannelType::Enum)r0;

	return r1;
}

String DiscordGuildChannel::name() {
	auto r0 = obj->Name();

	String r1 = String(r0.c_str());

	return r1;
}

Variant DiscordGuildChannel::linked_lobby() {
	auto r0 = obj->LinkedLobby();

	Variant r1;

	if (!r0.has_value()) {
		r1 = nullptr;
	} else {
		auto r0_v = r0.value();

		discordpp::LinkedLobby *r1_v_t = memnew(discordpp::LinkedLobby(std::move(r0_v)));
		DiscordLinkedLobby *r1_v = memnew(DiscordLinkedLobby{ r1_v_t });

		r1 = Variant(r1_v);
	}

	return r1;
}

Variant DiscordGuildChannel::parent_id() {
	auto r0 = obj->ParentId();

	Variant r1;

	if (!r0.has_value()) {
		r1 = nullptr;
	} else {
		auto r0_v = r0.value();
		int64_t r1_v = (int64_t)r0_v;
		r1 = Variant(r1_v);
	}

	return r1;
}

bool DiscordGuildChannel::is_linkable() {
	auto r0 = obj->IsLinkable();

	bool r1 = r0;

	return r1;
}

bool DiscordGuildChannel::is_viewable_and_writeable_by_all_members() {
	auto r0 = obj->IsViewableAndWriteableByAllMembers();

	bool r1 = r0;

	return r1;
}

int64_t DiscordGuildChannel::id() {
	auto r0 = obj->Id();

	int64_t r1 = (int64_t)r0;

	return r1;
}

int64_t DiscordGuildChannel::position() {
	auto r0 = obj->Position();

	int64_t r1 = (int64_t)r0;

	return r1;
}

void DiscordGuildChannel::set_id(int64_t id) {
	int64_t p0 = id;
	obj->SetId(p0);
}

void DiscordGuildChannel::set_is_linkable(bool is_linkable) {
	bool p0 = is_linkable;
	obj->SetIsLinkable(p0);
}

void DiscordGuildChannel::set_is_viewable_and_writeable_by_all_members(bool is_viewable_and_writeable_by_all_members) {
	bool p0 = is_viewable_and_writeable_by_all_members;
	obj->SetIsViewableAndWriteableByAllMembers(p0);
}

void DiscordGuildChannel::set_linked_lobby(Variant linked_lobby) {
	std::optional<discordpp::LinkedLobby> p0;

	if (linked_lobby.get_type() == Variant::OBJECT) {
	}

	obj->SetLinkedLobby(p0);
}

void DiscordGuildChannel::set_name(String name) {
	std::string p0 = std::string(name.utf8().get_data());
	obj->SetName(p0);
}

void DiscordGuildChannel::set_parent_id(Variant parent_id) {
	std::optional<uint64_t> p0;

	if (parent_id.get_type() == Variant::INT) {
		p0 = parent_id;
	}

	obj->SetParentId(p0);
}

void DiscordGuildChannel::set_position(int64_t position) {
	int64_t p0 = position;
	obj->SetPosition(p0);
}

void DiscordGuildChannel::set_type(DiscordChannelType::Enum type) {
	discordpp::ChannelType p0 = (discordpp::ChannelType)type;
	obj->SetType(p0);
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
