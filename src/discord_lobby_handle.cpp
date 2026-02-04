
#include "discord_classes.h"

using namespace godot;

// Functions.

TypedArray<DiscordLobbyMemberHandle> DiscordLobbyHandle::lobby_members() {
	auto r0 = obj->LobbyMembers();

	TypedArray<DiscordLobbyMemberHandle> r1 = TypedArray<DiscordLobbyMemberHandle>();

	for (auto i : r0) {
		discordpp::LobbyMemberHandle *r1_t_t = memnew(discordpp::LobbyMemberHandle(std::move(i)));
		DiscordLobbyMemberHandle *r1_t = memnew(DiscordLobbyMemberHandle{ r1_t_t });

		r1.push_back(r1_t);
	}

	return r1;
}

TypedArray<int64_t> DiscordLobbyHandle::lobby_member_ids() {
	auto r0 = obj->LobbyMemberIds();

	TypedArray<int64_t> r1 = TypedArray<int64_t>();

	for (auto i : r0) {
		int64_t r1_t = (int64_t)i;
		r1.push_back(r1_t);
	}

	return r1;
}

TypedDictionary<String, String> DiscordLobbyHandle::metadata() {
	auto r0 = obj->Metadata();

	TypedDictionary<String, String> r1 = TypedDictionary<String, String>();

	for (auto i : r0) {
		String k = String(i.first.c_str());
		String v = String(i.second.c_str());
		r1[k] = v;
	}

	return r1;
}

Variant DiscordLobbyHandle::get_call_info_handle() {
	auto r0 = obj->GetCallInfoHandle();

	Variant r1;

	if (!r0.has_value()) {
		r1 = nullptr;
	} else {
		auto r0_v = r0.value();

		discordpp::CallInfoHandle *r1_v_t = memnew(discordpp::CallInfoHandle(std::move(r0_v)));
		DiscordCallInfoHandle *r1_v = memnew(DiscordCallInfoHandle{ r1_v_t });

		r1 = Variant(r1_v);
	}

	return r1;
}

Variant DiscordLobbyHandle::get_lobby_member_handle(int64_t member_id) {
	int64_t p0 = member_id;
	auto r0 = obj->GetLobbyMemberHandle(p0);

	Variant r1;

	if (!r0.has_value()) {
		r1 = nullptr;
	} else {
		auto r0_v = r0.value();

		discordpp::LobbyMemberHandle *r1_v_t = memnew(discordpp::LobbyMemberHandle(std::move(r0_v)));
		DiscordLobbyMemberHandle *r1_v = memnew(DiscordLobbyMemberHandle{ r1_v_t });

		r1 = Variant(r1_v);
	}

	return r1;
}

Variant DiscordLobbyHandle::linked_channel() {
	auto r0 = obj->LinkedChannel();

	Variant r1;

	if (!r0.has_value()) {
		r1 = nullptr;
	} else {
		auto r0_v = r0.value();

		discordpp::LinkedChannel *r1_v_t = memnew(discordpp::LinkedChannel(std::move(r0_v)));
		DiscordLinkedChannel *r1_v = memnew(DiscordLinkedChannel{ r1_v_t });

		r1 = Variant(r1_v);
	}

	return r1;
}

int64_t DiscordLobbyHandle::id() {
	auto r0 = obj->Id();

	int64_t r1 = (int64_t)r0;

	return r1;
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
