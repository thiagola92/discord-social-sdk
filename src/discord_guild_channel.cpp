
#include "discord_classes.h"

using namespace godot;

void DiscordppGuildChannel::Drop() {
	obj->Drop();
}

uint64_t DiscordppGuildChannel::Id() {
	return obj->Id();
}

void DiscordppGuildChannel::SetId(uint64_t Id) {
	auto p0 = Id;
	obj->SetId(p0);
}

String DiscordppGuildChannel::Name() {
	return String(obj->Name().c_str());
}

void DiscordppGuildChannel::SetName(String Name) {
	auto p0 = Name.utf8().get_data();
	obj->SetName(p0);
}

bool DiscordppGuildChannel::IsLinkable() {
	return obj->IsLinkable();
}

void DiscordppGuildChannel::SetIsLinkable(bool IsLinkable) {
	auto p0 = IsLinkable;
	obj->SetIsLinkable(p0);
}

bool DiscordppGuildChannel::IsViewableAndWriteableByAllMembers() {
	return obj->IsViewableAndWriteableByAllMembers();
}

void DiscordppGuildChannel::SetIsViewableAndWriteableByAllMembers(bool IsViewableAndWriteableByAllMembers) {
	auto p0 = IsViewableAndWriteableByAllMembers;
	obj->SetIsViewableAndWriteableByAllMembers(p0);
}

Variant DiscordppGuildChannel::LinkedLobby() {
	auto r = obj->LinkedLobby();

	if (!r.has_value()) {
		return nullptr;
	}

	auto t_r = (discordpp::LinkedLobby *)memalloc(sizeof(discordpp::LinkedLobby));
	*t_r = r.value();
	return Variant(memnew(DiscordppLinkedLobby{ t_r }));
}

void DiscordppGuildChannel::SetLinkedLobby(Variant LinkedLobby) {
	std::optional<discordpp::LinkedLobby> p0;

	if (LinkedLobby.get_type() == Variant::OBJECT) {
		auto t_p0 = Object::cast_to<DiscordppLinkedLobby>(LinkedLobby);
		auto t2_p0 = t_p0->unwrap();
		p0 = std::optional<discordpp::LinkedLobby>{ *t2_p0 };
	}

	obj->SetLinkedLobby(p0);
}

void DiscordppGuildChannel::_bind_methods() {
	ClassDB::bind_method(D_METHOD("Drop"),
			&DiscordppGuildChannel::Drop);

	ClassDB::bind_method(D_METHOD("Id"),
			&DiscordppGuildChannel::Id);

	ClassDB::bind_method(D_METHOD("SetId", "Id"),
			&DiscordppGuildChannel::SetId);

	ClassDB::bind_method(D_METHOD("Name"),
			&DiscordppGuildChannel::Name);

	ClassDB::bind_method(D_METHOD("SetName", "Name"),
			&DiscordppGuildChannel::SetName);

	ClassDB::bind_method(D_METHOD("IsLinkable"),
			&DiscordppGuildChannel::IsLinkable);

	ClassDB::bind_method(D_METHOD("SetIsLinkable", "IsLinkable"),
			&DiscordppGuildChannel::SetIsLinkable);

	ClassDB::bind_method(D_METHOD("IsViewableAndWriteableByAllMembers"),
			&DiscordppGuildChannel::IsViewableAndWriteableByAllMembers);

	ClassDB::bind_method(D_METHOD("SetIsViewableAndWriteableByAllMembers", "IsViewableAndWriteableByAllMembers"),
			&DiscordppGuildChannel::SetIsViewableAndWriteableByAllMembers);

	ClassDB::bind_method(D_METHOD("LinkedLobby"),
			&DiscordppGuildChannel::LinkedLobby);

	ClassDB::bind_method(D_METHOD("SetLinkedLobby", "LinkedLobby"),
			&DiscordppGuildChannel::SetLinkedLobby);
}
