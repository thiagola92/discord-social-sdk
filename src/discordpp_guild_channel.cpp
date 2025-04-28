
#include "discordpp_classes.h"

using namespace godot;

void DiscordppGuildChannel::Drop() {
	obj->Drop();
}

int64_t DiscordppGuildChannel::Id() {
	return obj->Id();
}

void DiscordppGuildChannel::SetId(int64_t Id) {
	int64_t p0 = Id;

	obj->SetId(p0);
}

String DiscordppGuildChannel::Name() {
	return String(obj->Name().c_str());
}

void DiscordppGuildChannel::SetName(String Name) {
	std::string p0 = std::string(Name.utf8().get_data());

	obj->SetName(p0);
}

bool DiscordppGuildChannel::IsLinkable() {
	return obj->IsLinkable();
}

void DiscordppGuildChannel::SetIsLinkable(bool IsLinkable) {
	bool p0 = IsLinkable;

	obj->SetIsLinkable(p0);
}

bool DiscordppGuildChannel::IsViewableAndWriteableByAllMembers() {
	return obj->IsViewableAndWriteableByAllMembers();
}

void DiscordppGuildChannel::SetIsViewableAndWriteableByAllMembers(bool IsViewableAndWriteableByAllMembers) {
	bool p0 = IsViewableAndWriteableByAllMembers;

	obj->SetIsViewableAndWriteableByAllMembers(p0);
}

Variant DiscordppGuildChannel::LinkedLobby() {
	auto r = obj->LinkedLobby();

	if (!r.has_value()) {
		return nullptr;
	}

	discordpp::LinkedLobby *t_r = memnew(discordpp::LinkedLobby(std::move(r.value())));
	return Variant(memnew(DiscordppLinkedLobby{ t_r }));
}

void DiscordppGuildChannel::SetLinkedLobby(Variant LinkedLobby) {
	std::optional<discordpp::LinkedLobby> p0;

	if (LinkedLobby.get_type() == Variant::OBJECT) {
		DiscordppLinkedLobby *t_p0 = Object::cast_to<DiscordppLinkedLobby>(LinkedLobby);
		p0 = std::optional<discordpp::LinkedLobby>{ *t_p0->unwrap() };
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
