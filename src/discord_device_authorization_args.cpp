
#include "discord_classes.h"

using namespace godot;

void DiscordppDeviceAuthorizationArgs::Drop() {
	obj->Drop();
}

int64_t DiscordppDeviceAuthorizationArgs::ClientId() {
	return obj->ClientId();
}

void DiscordppDeviceAuthorizationArgs::SetClientId(int64_t ClientId) {
	auto p0 = ClientId;
	obj->SetClientId(p0);
}

String DiscordppDeviceAuthorizationArgs::Scopes() {
	return String(obj->Scopes().c_str());
}

void DiscordppDeviceAuthorizationArgs::SetScopes(String Scopes) {
	auto p0 = Scopes.utf8().get_data();
	obj->SetScopes(p0);
}

void DiscordppDeviceAuthorizationArgs::_bind_methods() {
	ClassDB::bind_method(D_METHOD("Drop"),
			&DiscordppDeviceAuthorizationArgs::Drop);

	ClassDB::bind_method(D_METHOD("ClientId"),
			&DiscordppDeviceAuthorizationArgs::ClientId);

	ClassDB::bind_method(D_METHOD("SetClientId", "ClientId"),
			&DiscordppDeviceAuthorizationArgs::SetClientId);

	ClassDB::bind_method(D_METHOD("Scopes"),
			&DiscordppDeviceAuthorizationArgs::Scopes);

	ClassDB::bind_method(D_METHOD("SetScopes", "Scopes"),
			&DiscordppDeviceAuthorizationArgs::SetScopes);
}
