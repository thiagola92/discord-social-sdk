#ifndef DISCORD_ACTIVITY_TIMESTAMPS_H
#define DISCORD_ACTIVITY_TIMESTAMPS_H

#include "discordpp.h"
#include "godot_cpp/classes/ref_counted.hpp"

namespace godot {

class DiscordActivityTimestamps : public RefCounted {
	GDCLASS(DiscordActivityTimestamps, RefCounted)

private:
	discordpp::ActivityTimestamps activity_timestamps;

protected:
	static void _bind_methods();

public:
	discordpp::ActivityTimestamps *unwrap(); // Internal usage.

	DiscordActivityTimestamps();
	~DiscordActivityTimestamps();
};

} //namespace godot

#endif
