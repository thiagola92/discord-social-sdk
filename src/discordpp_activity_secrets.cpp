
#include "discordpp_classes.h"

using namespace godot;

void DiscordppActivitySecrets::Drop() {
	obj->Drop();
}

String DiscordppActivitySecrets::Join() {
	return String(obj->Join().c_str());
}

void DiscordppActivitySecrets::SetJoin(String Join) {
	std::string p0 = std::string(Join.utf8().get_data());

	obj->SetJoin(p0);
}

void DiscordppActivitySecrets::_bind_methods() {
	ClassDB::bind_method(D_METHOD("Drop"),
			&DiscordppActivitySecrets::Drop);

	ClassDB::bind_method(D_METHOD("Join"),
			&DiscordppActivitySecrets::Join);

	ClassDB::bind_method(D_METHOD("SetJoin", "Join"),
			&DiscordppActivitySecrets::SetJoin);
}
