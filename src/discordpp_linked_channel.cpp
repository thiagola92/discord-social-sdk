
#include "discordpp_classes.h"

using namespace godot;

void DiscordppLinkedChannel::Drop() {
	obj->Drop();
}

int64_t DiscordppLinkedChannel::Id() {
	return obj->Id();
}

void DiscordppLinkedChannel::SetId(int64_t Id) {
	int64_t p0 = Id;

	obj->SetId(p0);
}

String DiscordppLinkedChannel::Name() {
	return String(obj->Name().c_str());
}

void DiscordppLinkedChannel::SetName(String Name) {
	std::string p0 = std::string(Name.utf8().get_data());

	obj->SetName(p0);
}

int64_t DiscordppLinkedChannel::GuildId() {
	return obj->GuildId();
}

void DiscordppLinkedChannel::SetGuildId(int64_t GuildId) {
	int64_t p0 = GuildId;

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
