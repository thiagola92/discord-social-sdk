#include "discord_device_authorization_args.h"

using namespace godot;

discordpp::DeviceAuthorizationArgs *DiscordDeviceAuthorizationArgs::unwrap() {
	return &device_authorization_args;
}

void DiscordDeviceAuthorizationArgs::_bind_methods() {
    //
}

DiscordDeviceAuthorizationArgs::DiscordDeviceAuthorizationArgs() {}

DiscordDeviceAuthorizationArgs::~DiscordDeviceAuthorizationArgs() {}
