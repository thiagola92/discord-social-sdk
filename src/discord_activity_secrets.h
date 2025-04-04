// AUTO-GENERATED
#ifndef DISCORD_ACTIVITY_SECRETS_H
#define DISCORD_ACTIVITY_SECRETS_H

#include "discordpp.h"
#include "godot_cpp/classes/ref_counted.hpp"
#include "godot_cpp/variant/typed_array.hpp"
#include "godot_cpp/variant/typed_dictionary.hpp"

namespace godot {

class DiscordActivitySecrets : public RefCounted {
	GDCLASS(DiscordActivitySecrets, RefCounted)

private:
	discordpp::ActivitySecrets *activity_secrets;

protected:
	static void _bind_methods();

public:
	discordpp::ActivitySecrets *unwrap(); // Internal usage.

	String join();
	void set_join(String join);

	DiscordActivitySecrets();
	DiscordActivitySecrets(discordpp::ActivitySecrets *activity_secrets);
	~DiscordActivitySecrets();
};

} //namespace godot

#endif
