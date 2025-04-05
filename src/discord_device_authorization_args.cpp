// AUTO-GENERATED
#include "discord_classes.h"

using namespace godot;

discordpp::DeviceAuthorizationArgs *DiscordDeviceAuthorizationArgs::unwrap() {
	return device_authorization_args;
}

uint64_t DiscordDeviceAuthorizationArgs::client_id() {
	auto r = device_authorization_args->ClientId();
	return r;
}

void DiscordDeviceAuthorizationArgs::set_client_id(uint64_t client_id) {
	device_authorization_args->SetClientId(client_id);
}

String DiscordDeviceAuthorizationArgs::scopes() {
	auto r = device_authorization_args->Scopes();
	return String(r.c_str());
}

void DiscordDeviceAuthorizationArgs::set_scopes(String scopes) {
	auto p0 = scopes.utf8().get_data();
	device_authorization_args->SetScopes(p0);
}

void DiscordDeviceAuthorizationArgs::_bind_methods() {
	ClassDB::bind_method(D_METHOD("client_id"),
			&DiscordDeviceAuthorizationArgs::client_id);

	ClassDB::bind_method(D_METHOD("set_client_id", "client_id"),
			&DiscordDeviceAuthorizationArgs::set_client_id);

	ClassDB::bind_method(D_METHOD("scopes"),
			&DiscordDeviceAuthorizationArgs::scopes);

	ClassDB::bind_method(D_METHOD("set_scopes", "scopes"),
			&DiscordDeviceAuthorizationArgs::set_scopes);
}

DiscordDeviceAuthorizationArgs::DiscordDeviceAuthorizationArgs() {
	this->device_authorization_args = memnew(discordpp::DeviceAuthorizationArgs);
}

DiscordDeviceAuthorizationArgs::DiscordDeviceAuthorizationArgs(discordpp::DeviceAuthorizationArgs *device_authorization_args) {
	this->device_authorization_args = device_authorization_args;
}

DiscordDeviceAuthorizationArgs::~DiscordDeviceAuthorizationArgs() {}
