
#include "discord_classes.h"

using namespace godot;

void DiscordppLinkedChannel::Drop() {
	obj->Drop();
}

uint64_t DiscordppLinkedChannel::Id() {
	return obj->Id();
}

void DiscordppLinkedChannel::SetId(uint64_t Id) {
	auto p0 = Id;
	obj->SetId(p0);
}

String DiscordppLinkedChannel::Name() {
	return String(obj->Name().c_str());
}

void DiscordppLinkedChannel::SetName(String Name) {
	auto p0 = Name.utf8().get_data();
	obj->SetName(p0);
}

uint64_t DiscordppLinkedChannel::GuildId() {
	return obj->GuildId();
}

void DiscordppLinkedChannel::SetGuildId(uint64_t GuildId) {
	auto p0 = GuildId;
	obj->SetGuildId(p0);
}

void DiscordppLinkedChannel::_bind_methods() {
	ClassDB::bind_method(D_METHOD("Drop"),
			&DiscordppLinkedChannel::Drop);

	ClassDB::bind_method(D_METHOD("Id"),
			&DiscordppLinkedChannel::Id);

	ClassDB::bind_method(D_METHOD("SetId", "Id"),
			&DiscordppLinkedChannel::SetId);

	ClassDB::bind_method(D_METHOD("Name"),
			&DiscordppLinkedChannel::Name);

	ClassDB::bind_method(D_METHOD("SetName", "Name"),
			&DiscordppLinkedChannel::SetName);

	ClassDB::bind_method(D_METHOD("GuildId"),
			&DiscordppLinkedChannel::GuildId);

	ClassDB::bind_method(D_METHOD("SetGuildId", "GuildId"),
			&DiscordppLinkedChannel::SetGuildId);
}
