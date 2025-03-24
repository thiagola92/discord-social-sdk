#ifndef DISCORD_ACTIVITY_H
#define DISCORD_ACTIVITY_H

#include "discordpp.h"
#include "godot_cpp/classes/ref_counted.hpp"

namespace godot {

class DiscordActivity : public RefCounted {
	GDCLASS(DiscordActivity, RefCounted)

private:
	discordpp::Activity activity;

protected:
	static void _bind_methods();

public:
	discordpp::Activity *unwrap(); // Internal usage.

	DiscordActivity();
	~DiscordActivity();
};

} //namespace godot

#endif
