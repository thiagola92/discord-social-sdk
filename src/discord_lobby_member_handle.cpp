
#include "discord_classes.h"

using namespace godot;

void DiscordppLobbyMemberHandle::Drop() {
	obj->Drop();
}

bool DiscordppLobbyMemberHandle::CanLinkLobby() {
	return obj->CanLinkLobby();
}

bool DiscordppLobbyMemberHandle::Connected() {
	return obj->Connected();
}

uint64_t DiscordppLobbyMemberHandle::Id() {
	return obj->Id();
}

TypedDictionary<String, String> DiscordppLobbyMemberHandle::Metadata() {
	auto r = obj->Metadata();
	auto t_r = TypedDictionary<String, String>();

	for (auto p_r : r) {
		t_r[String(p_r.first_c_str())] = String(p_r.second.c_str());
	}

	return t_r;
}

Variant DiscordppLobbyMemberHandle::User() {
	auto r = obj->User();

	if (!r.has_value()) {
		return nullptr;
	}

	auto t_r = (discordpp::UserHandle *)memalloc(sizeof(discordpp::UserHandle));
	*t_r = r.value();
	return Variant(memnew(DiscordppUserHandle{ t_r }));
}

void DiscordppLobbyMemberHandle::_bind_methods() {
	ClassDB::bind_method(D_METHOD("Drop"),
			&DiscordppLobbyMemberHandle::Drop);

	ClassDB::bind_method(D_METHOD("CanLinkLobby"),
			&DiscordppLobbyMemberHandle::CanLinkLobby);

	ClassDB::bind_method(D_METHOD("Connected"),
			&DiscordppLobbyMemberHandle::Connected);

	ClassDB::bind_method(D_METHOD("Id"),
			&DiscordppLobbyMemberHandle::Id);

	ClassDB::bind_method(D_METHOD("Metadata"),
			&DiscordppLobbyMemberHandle::Metadata);

	ClassDB::bind_method(D_METHOD("User"),
			&DiscordppLobbyMemberHandle::User);
}
