
#include "discord_classes.h"

using namespace godot;

void DiscordppGuildMinimal::Drop() {
	obj->Drop();
}

uint64_t DiscordppGuildMinimal::Id() {
	return obj->Id();
}

void DiscordppGuildMinimal::SetId(uint64_t Id) {
	auto p0 = Id;
	obj->SetId(p0);
}

String DiscordppGuildMinimal::Name() {
	return String(obj->Name().c_str());
}

void DiscordppGuildMinimal::SetName(String Name) {
	auto p0 = Name.utf8().get_data();
	obj->SetName(p0);
}

void DiscordppGuildMinimal::_bind_methods() {
	ClassDB::bind_method(D_METHOD("Drop"),
			&DiscordppGuildMinimal::Drop);

	ClassDB::bind_method(D_METHOD("Id"),
			&DiscordppGuildMinimal::Id);

	ClassDB::bind_method(D_METHOD("SetId", "Id"),
			&DiscordppGuildMinimal::SetId);

	ClassDB::bind_method(D_METHOD("Name"),
			&DiscordppGuildMinimal::Name);

	ClassDB::bind_method(D_METHOD("SetName", "Name"),
			&DiscordppGuildMinimal::SetName);
}
