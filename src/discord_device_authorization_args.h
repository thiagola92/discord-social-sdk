// AUTO-GENERATED
#ifndef DISCORD_DEVICE_AUTHORIZATION_ARGS_H
#define DISCORD_DEVICE_AUTHORIZATION_ARGS_H

#include "discordpp.h"
#include "godot_cpp/classes/ref_counted.hpp"
#include "godot_cpp/variant/typed_array.hpp"
#include "godot_cpp/variant/typed_dictionary.hpp"

namespace godot {

class DiscordDeviceAuthorizationArgs : public RefCounted {
	GDCLASS(DiscordDeviceAuthorizationArgs, RefCounted)

private:
	discordpp::DeviceAuthorizationArgs *device_authorization_args;

protected:
	static void _bind_methods();

public:
	discordpp::DeviceAuthorizationArgs *unwrap(); // Internal usage.

	uint64_t client_id();
	void set_client_id(uint64_t client_id);
	String scopes();
	void set_scopes(String scopes);

	DiscordDeviceAuthorizationArgs();
	DiscordDeviceAuthorizationArgs(discordpp::DeviceAuthorizationArgs *device_authorization_args);
	~DiscordDeviceAuthorizationArgs();
};

} //namespace godot

#endif
