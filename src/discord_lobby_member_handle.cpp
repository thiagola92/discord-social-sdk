
#include "discord_classes.h"

using namespace godot;

// Functions.

TypedDictionary<String, String> DiscordLobbyMemberHandle::metadata() {
	auto r0 = obj->Metadata();

	TypedDictionary<String, String> r1 = TypedDictionary<String, String>();

	for (auto i : r0) {
		String k = String(i.first.c_str());
		String v = String(i.second.c_str());
		r1[k] = v;
	}

	return r1;
}

Variant DiscordLobbyMemberHandle::user() {
	auto r0 = obj->User();

	Variant r1;

	if (!r0.has_value()) {
		r1 = nullptr;
	} else {
		auto r0_v = r0.value();

		discordpp::UserHandle *r1_v_t = memnew(discordpp::UserHandle(std::move(r0_v)));
		DiscordUserHandle *r1_v = memnew(DiscordUserHandle{ r1_v_t });

		r1 = Variant(r1_v);
	}

	return r1;
}

bool DiscordLobbyMemberHandle::can_link_lobby() {
	auto r0 = obj->CanLinkLobby();

	bool r1 = r0;

	return r1;
}

bool DiscordLobbyMemberHandle::connected() {
	auto r0 = obj->Connected();

	bool r1 = r0;

	return r1;
}

int64_t DiscordLobbyMemberHandle::id() {
	auto r0 = obj->Id();

	int64_t r1 = (int64_t)r0;

	return r1;
}

// Overload functions.

// Binding.
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
