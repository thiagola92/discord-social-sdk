// AUTO-GENERATED
#include "discord_lobby_handle.h"

using namespace godot;

discordpp::LobbyHandle *DiscordLobbyHandle::unwrap() {
	return lobby_handle;
}

Variant DiscordLobbyHandle::get_call_info_handle() {
	auto r = lobby_handle->GetCallInfoHandle();

	if (!r.has_value()) {
		return nullptr;
	}

	auto t_r = (discordpp::CallInfoHandle *)memalloc(sizeof(discordpp::CallInfoHandle));
	*t_r = r.value();
	return Variant(memnew(DiscordCallInfoHandle{ t_r }));
}

Variant DiscordLobbyHandle::get_lobby_member_handle(uint64_t member_id) {
	auto r = lobby_handle->GetLobbyMemberHandle(member_id);

	if (!r.has_value()) {
		return nullptr;
	}

	auto t_r = (discordpp::LobbyMemberHandle *)memalloc(sizeof(discordpp::LobbyMemberHandle));
	*t_r = r.value();
	return Variant(memnew(DiscordLobbyMemberHandle{ t_r }));
}

uint64_t DiscordLobbyHandle::id() {
	auto r = lobby_handle->Id();
	return r;
}

Variant DiscordLobbyHandle::linked_channel() {
	auto r = lobby_handle->LinkedChannel();

	if (!r.has_value()) {
		return nullptr;
	}

	auto t_r = (discordpp::LinkedChannel *)memalloc(sizeof(discordpp::LinkedChannel));
	*t_r = r.value();
	return Variant(memnew(DiscordLinkedChannel{ t_r }));
}

TypedArray<uint64_t> DiscordLobbyHandle::lobby_member_ids() {
	auto r = lobby_handle->LobbyMemberIds();
	auto t_r = TypedArray<uint64_t>();

	for (auto i_r : r) {
		t_r.push_back(i_r);
	}

	return t_r;
}

TypedArray<DiscordLobbyMemberHandle *> DiscordLobbyHandle::lobby_members() {
	auto r = lobby_handle->LobbyMembers();
	auto t_r = TypedArray<DiscordLobbyMemberHandle *>();

	for (auto i_r : r) {
		t_r.push_back(memnew(DiscordLobbyMemberHandle{ r }));
	}

	return t_r;
}

TypedDictionary<String, String> DiscordLobbyHandle::metadata() {
	auto r = lobby_handle->Metadata();
	auto t_r = TypedDictionary<String, String>();

	for (auto p_r : r) {
		t_r[String(p_r.first.c_str())] = String(p_r.second.c_str());
	}

	return t_r;
}

void DiscordLobbyHandle::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_call_info_handle"),
			&DiscordLobbyHandle::get_call_info_handle);

	ClassDB::bind_method(D_METHOD("get_lobby_member_handle", "member_id"),
			&DiscordLobbyHandle::get_lobby_member_handle);

	ClassDB::bind_method(D_METHOD("id"),
			&DiscordLobbyHandle::id);

	ClassDB::bind_method(D_METHOD("linked_channel"),
			&DiscordLobbyHandle::linked_channel);

	ClassDB::bind_method(D_METHOD("lobby_member_ids"),
			&DiscordLobbyHandle::lobby_member_ids);

	ClassDB::bind_method(D_METHOD("lobby_members"),
			&DiscordLobbyHandle::lobby_members);

	ClassDB::bind_method(D_METHOD("metadata"),
			&DiscordLobbyHandle::metadata);
}

DiscordLobbyHandle::DiscordLobbyHandle() {}

DiscordLobbyHandle::DiscordLobbyHandle(discordpp::LobbyHandle *lobby_handle) {
	this->lobby_handle = lobby_handle;
}

DiscordLobbyHandle::~DiscordLobbyHandle() {}
