// AUTO-GENERATED
#ifndef DISCORD_ACTIVITY_TIMESTAMPS_H
#define DISCORD_ACTIVITY_TIMESTAMPS_H

#include "discordpp.h"
#include "godot_cpp/classes/ref_counted.hpp"
#include "godot_cpp/variant/typed_array.hpp"
#include "godot_cpp/variant/typed_dictionary.hpp"

namespace godot {

class DiscordActivityTimestamps : public RefCounted {
	GDCLASS(DiscordActivityTimestamps, RefCounted)

private:
	discordpp::ActivityTimestamps *activity_timestamps;

protected:
	static void _bind_methods();

public:
	discordpp::ActivityTimestamps *unwrap(); // Internal usage.

	uint64_t start();
	void set_start(uint64_t start);
	uint64_t end();
	void set_end(uint64_t end);

	DiscordActivityTimestamps();
	DiscordActivityTimestamps(discordpp::ActivityTimestamps *activity_timestamps);
	~DiscordActivityTimestamps();
};

} //namespace godot

#endif
