
#include "discord_classes.h"

using namespace godot;

// Functions.

DiscordChannelType::Enum DiscordGuildChannel::type() {
	auto r = obj->Type();

	DiscordChannelType::Enum cr = (DiscordChannelType::Enum)r;
	return cr;
}

String DiscordGuildChannel::name() {
	auto r = obj->Name();

	String cr = String(r.c_str());
	return cr;
}

Variant DiscordGuildChannel::linked_lobby() {
	auto r = obj->LinkedLobby();

	Variant cr;

	if (!r.has_value()) {
		cr = nullptr;
	} else {
		auto r_v = r.value();

		discordpp::LinkedLobby *cr_v_t = memnew(discordpp::LinkedLobby(std::move(r_v)));
		DiscordLinkedLobby *cr_v = memnew(DiscordLinkedLobby{ cr_v_t });

		cr = Variant(cr_v);
	}

	return cr;
}

Variant DiscordGuildChannel::parent_id() {
	auto r = obj->ParentId();

	Variant cr;

	if (!r.has_value()) {
		cr = nullptr;
	} else {
		auto r_v = r.value();
		int64_t cr_v = (int64_t)r_v;
		cr = Variant(cr_v);
	}

	return cr;
}

bool DiscordGuildChannel::is_linkable() {
	auto r = obj->IsLinkable();

	bool cr = r;
	return cr;
}

bool DiscordGuildChannel::is_viewable_and_writeable_by_all_members() {
	auto r = obj->IsViewableAndWriteableByAllMembers();

	bool cr = r;
	return cr;
}

int64_t DiscordGuildChannel::id() {
	auto r = obj->Id();

	int64_t cr = (int64_t)r;
	return cr;
}

int64_t DiscordGuildChannel::position() {
	auto r = obj->Position();

	int64_t cr = (int64_t)r;
	return cr;
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
