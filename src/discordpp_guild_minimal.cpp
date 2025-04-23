
#include "discordpp_classes.h"

using namespace godot;

void DiscordppGuildMinimal::Drop() {
	obj->Drop();
}

int64_t DiscordppGuildMinimal::Id() {
	return obj->Id();
}

void DiscordppGuildMinimal::SetId(int64_t Id) {
	int64_t p0 = Id;

	obj->SetId(p0);
}

String DiscordppGuildMinimal::Name() {
	return String(obj->Name().c_str());
}

void DiscordppGuildMinimal::SetName(String Name) {
	std::string p0 = std::string(Name.utf8().get_data());

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
