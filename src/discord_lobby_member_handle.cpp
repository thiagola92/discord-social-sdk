// AUTO-GENERATED
#include "discord_lobby_member_handle.h"

using namespace godot;

discordpp::LobbyMemberHandle *DiscordLobbyMemberHandle::unwrap() {
	return lobby_member_handle;
}

bool DiscordLobbyMemberHandle::can_link_lobby() {
	auto r = lobby_member_handle->CanLinkLobby();
	return r;
}

bool DiscordLobbyMemberHandle::connected() {
	auto r = lobby_member_handle->Connected();
	return r;
}

uint64_t DiscordLobbyMemberHandle::id() {
	auto r = lobby_member_handle->Id();
	return r;
}

TypedDictionary<String, String> DiscordLobbyMemberHandle::metadata() {
	auto r = lobby_member_handle->Metadata();
	auto t_r = TypedDictionary<String, String>();

	for (auto p_r : r) {
		t_r[String(p_r.first.c_str())] = String(p_r.second.c_str());
	}

	return t_r;
}

Variant DiscordLobbyMemberHandle::user() {
	auto r = lobby_member_handle->User();

	if (!r.has_value()) {
		return nullptr;
	}

	auto t_r = (discordpp::UserHandle *)memalloc(sizeof(discordpp::UserHandle));
	*t_r = r.value();
	return Variant(memnew(DiscordUserHandle{ t_r }));
}

void DiscordLobbyMemberHandle::_bind_methods() {
	ClassDB::bind_method(D_METHOD("can_link_lobby"),
			&DiscordLobbyMemberHandle::can_link_lobby);

	ClassDB::bind_method(D_METHOD("connected"),
			&DiscordLobbyMemberHandle::connected);

	ClassDB::bind_method(D_METHOD("id"),
			&DiscordLobbyMemberHandle::id);

	ClassDB::bind_method(D_METHOD("metadata"),
			&DiscordLobbyMemberHandle::metadata);

	ClassDB::bind_method(D_METHOD("user"),
			&DiscordLobbyMemberHandle::user);
}

DiscordLobbyMemberHandle::DiscordLobbyMemberHandle() {
}

DiscordLobbyMemberHandle::DiscordLobbyMemberHandle(discordpp::LobbyMemberHandle *lobby_member_handle) {
	this->lobby_member_handle = lobby_member_handle;
}

DiscordLobbyMemberHandle::~DiscordLobbyMemberHandle() {}
