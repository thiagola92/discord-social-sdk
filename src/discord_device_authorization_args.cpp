
#include "discord_classes.h"

using namespace godot;

// Functions.

String DiscordDeviceAuthorizationArgs::scopes() {
	auto r0 = obj->Scopes();

	String r1 = String(r0.c_str());

	return r1;
}

int64_t DiscordDeviceAuthorizationArgs::client_id() {
	auto r0 = obj->ClientId();

	int64_t r1 = (int64_t)r0;

	return r1;
}

void DiscordDeviceAuthorizationArgs::set_client_id(int64_t client_id) {
	int64_t p0 = client_id;
	obj->SetClientId(p0);
}

void DiscordDeviceAuthorizationArgs::set_scopes(String scopes) {
	std::string p0 = std::string(scopes.utf8().get_data());
	obj->SetScopes(p0);
}

// Overload functions.

// Binding.
void DiscordDeviceAuthorizationArgs::_bind_methods() {
	ClassDB::bind_method(D_METHOD("client_id"),
			&DiscordDeviceAuthorizationArgs::client_id);

	ClassDB::bind_method(D_METHOD("scopes"),
			&DiscordDeviceAuthorizationArgs::scopes);

	ClassDB::bind_method(D_METHOD("set_client_id", "client_id"),
			&DiscordDeviceAuthorizationArgs::set_client_id);

	ClassDB::bind_method(D_METHOD("set_scopes", "scopes"),
			&DiscordDeviceAuthorizationArgs::set_scopes);
}
