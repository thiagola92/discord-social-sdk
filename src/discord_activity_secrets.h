#ifndef DISCORD_ACTIVITY_SECRETS_H
#define DISCORD_ACTIVITY_SECRETS_H

#include "discordpp.h"
#include "godot_cpp/classes/ref_counted.hpp"

namespace godot {

class DiscordActivitySecrets : public RefCounted {
	GDCLASS(DiscordActivitySecrets, RefCounted)

private:
	discordpp::ActivitySecrets activity_secrets;

protected:
	static void _bind_methods();

public:
	discordpp::ActivitySecrets *unwrap(); // Internal usage.

	DiscordActivitySecrets();
	~DiscordActivitySecrets();
};

} //namespace godot

#endif
