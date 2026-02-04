
#include "discord_classes.h"

using namespace godot;

// Functions.

TypedArray<DiscordLobbyMemberHandle> DiscordLobbyHandle::lobby_members() {
	auto r = obj->LobbyMembers();

	TypedArray<DiscordLobbyMemberHandle> cr = TypedArray<DiscordLobbyMemberHandle>();

	for (auto i : r) {
		discordpp::LobbyMemberHandle *cr_t_t = memnew(discordpp::LobbyMemberHandle(std::move(i)));
		DiscordLobbyMemberHandle *cr_t = memnew(DiscordLobbyMemberHandle{ cr_t_t });

		cr.push_back(cr_t);
	}

	return cr;
}

TypedArray<int64_t> DiscordLobbyHandle::lobby_member_ids() {
	auto r = obj->LobbyMemberIds();

	TypedArray<int64_t> cr = TypedArray<int64_t>();

	for (auto i : r) {
		int64_t cr_t = (int64_t)i;
		cr.push_back(cr_t);
	}

	return cr;
}

TypedDictionary<String, String> DiscordLobbyHandle::metadata() {
	auto r = obj->Metadata();

	TypedDictionary<String, String> cr = TypedDictionary<String, String>();

	for (auto i : r) {
		String k = String(i.first.c_str());
		String v = String(i.second.c_str());
		cr[k] = v;
	}

	return cr;
}

Variant DiscordLobbyHandle::get_call_info_handle() {
	auto r = obj->GetCallInfoHandle();

	Variant cr;

	if (!r.has_value()) {
		cr = nullptr;
	} else {
		auto r_v = r.value();

		discordpp::CallInfoHandle *cr_v_t = memnew(discordpp::CallInfoHandle(std::move(r_v)));
		DiscordCallInfoHandle *cr_v = memnew(DiscordCallInfoHandle{ cr_v_t });

		cr = Variant(cr_v);
	}

	return cr;
}

Variant DiscordLobbyHandle::get_lobby_member_handle(int64_t member_id) {
	int64_t p0 = member_id;
	auto r = obj->GetLobbyMemberHandle(p0);

	Variant cr;

	if (!r.has_value()) {
		cr = nullptr;
	} else {
		auto r_v = r.value();

		discordpp::LobbyMemberHandle *cr_v_t = memnew(discordpp::LobbyMemberHandle(std::move(r_v)));
		DiscordLobbyMemberHandle *cr_v = memnew(DiscordLobbyMemberHandle{ cr_v_t });

		cr = Variant(cr_v);
	}

	return cr;
}

Variant DiscordLobbyHandle::linked_channel() {
	auto r = obj->LinkedChannel();

	Variant cr;

	if (!r.has_value()) {
		cr = nullptr;
	} else {
		auto r_v = r.value();

		discordpp::LinkedChannel *cr_v_t = memnew(discordpp::LinkedChannel(std::move(r_v)));
		DiscordLinkedChannel *cr_v = memnew(DiscordLinkedChannel{ cr_v_t });

		cr = Variant(cr_v);
	}

	return cr;
}

int64_t DiscordLobbyHandle::id() {
	auto r = obj->Id();

	int64_t cr = (int64_t)r;
	return cr;
}

// Overload functions.

// Binding.
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
