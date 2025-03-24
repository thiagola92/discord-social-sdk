#ifndef DISCORD_DEVICE_AUTHORIZATION_ARGS_H
#define DISCORD_DEVICE_AUTHORIZATION_ARGS_H

#include "discordpp.h"
#include "godot_cpp/classes/ref_counted.hpp"

namespace godot {

class DiscordDeviceAuthorizationArgs : public RefCounted {
	GDCLASS(DiscordDeviceAuthorizationArgs, RefCounted)

private:
	discordpp::DeviceAuthorizationArgs device_authorization_args;

protected:
	static void _bind_methods();

public:
	discordpp::DeviceAuthorizationArgs *unwrap(); // Internal usage.

	DiscordDeviceAuthorizationArgs();
	~DiscordDeviceAuthorizationArgs();
};

} //namespace godot

#endif
