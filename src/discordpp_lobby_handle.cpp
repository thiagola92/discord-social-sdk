
#include "discordpp_classes.h"

using namespace godot;

void DiscordppLobbyHandle::Drop() {
	obj->Drop();
}

Variant DiscordppLobbyHandle::GetCallInfoHandle() {
	auto r = obj->GetCallInfoHandle();

	if (!r.has_value()) {
		return nullptr;
	}

	discordpp::CallInfoHandle *t_r = memnew(discordpp::CallInfoHandle(std::move(r.value())));
	return Variant(memnew(DiscordppCallInfoHandle{ t_r }));
}

Variant DiscordppLobbyHandle::GetLobbyMemberHandle(int64_t memberId) {
	int64_t p0 = memberId;

	auto r = obj->GetLobbyMemberHandle(p0);

	if (!r.has_value()) {
		return nullptr;
	}

	discordpp::LobbyMemberHandle *t_r = memnew(discordpp::LobbyMemberHandle(std::move(r.value())));
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

	discordpp::LinkedChannel *t_r = memnew(discordpp::LinkedChannel(std::move(r.value())));
	return Variant(memnew(DiscordppLinkedChannel{ t_r }));
}

TypedArray<int64_t> DiscordppLobbyHandle::LobbyMemberIds() {
	auto r = obj->LobbyMemberIds();
	TypedArray<int64_t> t_r = TypedArray<int64_t>();

	for (auto i : r) {
		t_r.push_back((int64_t)i);
	}

	return t_r;
}

TypedArray<DiscordppLobbyMemberHandle> DiscordppLobbyHandle::LobbyMembers() {
	auto r = obj->LobbyMembers();
	TypedArray<DiscordppLobbyMemberHandle> t_r = TypedArray<DiscordppLobbyMemberHandle>();

	for (auto i : r) {
		discordpp::LobbyMemberHandle *t_i = memnew(discordpp::LobbyMemberHandle(std::move(i)));
		t_r.push_back(memnew(DiscordppLobbyMemberHandle{ t_i }));
	}

	return t_r;
}

TypedDictionary<String, String> DiscordppLobbyHandle::Metadata() {
	auto r = obj->Metadata();
	TypedDictionary<String, String> t_r = TypedDictionary<String, String>();

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
