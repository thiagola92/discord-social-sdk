
#include "discord_classes.h"

using namespace godot;

void DiscordppLobbyHandle::Drop() {
	obj->Drop();
}

Variant DiscordppLobbyHandle::GetCallInfoHandle() {
	auto r = obj->GetCallInfoHandle();

	if (!r.has_value()) {
		return nullptr;
	}

	discordpp::CallInfoHandle *t_r = (discordpp::CallInfoHandle *)memalloc(sizeof(discordpp::CallInfoHandle));
	*t_r = r.value();
	return Variant(memnew(DiscordppCallInfoHandle{ t_r }));
}

Variant DiscordppLobbyHandle::GetLobbyMemberHandle(int64_t memberId) {
	int64_t p0 = memberId;

	auto r = obj->GetLobbyMemberHandle(p0);

	if (!r.has_value()) {
		return nullptr;
	}

	discordpp::LobbyMemberHandle *t_r = (discordpp::LobbyMemberHandle *)memalloc(sizeof(discordpp::LobbyMemberHandle));
	*t_r = r.value();
	return Variant(memnew(DiscordppLobbyMemberHandle{ t_r }));
}

int64_t DiscordppLobbyHandle::Id() {
	return obj->Id();
}

Variant DiscordppLobbyHandle::LinkedChannel() {
	auto r = obj->LinkedChannel();

	if (!r.has_value()) {
		return nullptr;
	}

	discordpp::LinkedChannel *t_r = (discordpp::LinkedChannel *)memalloc(sizeof(discordpp::LinkedChannel));
	*t_r = r.value();
	return Variant(memnew(DiscordppLinkedChannel{ t_r }));
}

TypedArray<int64_t> DiscordppLobbyHandle::LobbyMemberIds() {
	auto r = obj->LobbyMemberIds();
	auto t_r = TypedArray<int64_t>();

	for (auto i_r : r) {
		t_r.push_back(i_r);
	}

	return t_r;
}

TypedArray<Ref<DiscordppLobbyMemberHandle>> DiscordppLobbyHandle::LobbyMembers() {
	auto r = obj->LobbyMembers();
	auto t_r = TypedArray<Ref<DiscordppLobbyMemberHandle>>();

	for (auto i_r : r) {
		t_r.push_back(memnew(DiscordppLobbyMemberHandle{ &i_r }));
	}

	return t_r;
}

TypedDictionary<String, String> DiscordppLobbyHandle::Metadata() {
	auto r = obj->Metadata();
	auto t_r = TypedDictionary<String, String>();

	for (auto p_r : r) {
		t_r[String(p_r.first.c_str())] = String(p_r.second.c_str());
	}

	return t_r;
}

void DiscordppLobbyHandle::_bind_methods() {
	ClassDB::bind_method(D_METHOD("Drop"),
			&DiscordppLobbyHandle::Drop);

	ClassDB::bind_method(D_METHOD("GetCallInfoHandle"),
			&DiscordppLobbyHandle::GetCallInfoHandle);

	ClassDB::bind_method(D_METHOD("GetLobbyMemberHandle", "memberId"),
			&DiscordppLobbyHandle::GetLobbyMemberHandle);

	ClassDB::bind_method(D_METHOD("Id"),
			&DiscordppLobbyHandle::Id);

	ClassDB::bind_method(D_METHOD("LinkedChannel"),
			&DiscordppLobbyHandle::LinkedChannel);

	ClassDB::bind_method(D_METHOD("LobbyMemberIds"),
			&DiscordppLobbyHandle::LobbyMemberIds);

	ClassDB::bind_method(D_METHOD("LobbyMembers"),
			&DiscordppLobbyHandle::LobbyMembers);

	ClassDB::bind_method(D_METHOD("Metadata"),
			&DiscordppLobbyHandle::Metadata);
}
