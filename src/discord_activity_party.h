#ifndef DISCORD_ACTIVITY_PARTY_H
#define DISCORD_ACTIVITY_PARTY_H

#include "discordpp.h"
#include "godot_cpp/classes/ref_counted.hpp"

namespace godot {

class DiscordActivityParty : public RefCounted {
	GDCLASS(DiscordActivityParty, RefCounted)

private:
	discordpp::ActivityParty activity_party;

protected:
	static void _bind_methods();

public:
	discordpp::ActivityParty *unwrap(); // Internal usage.

	DiscordActivityParty();
	~DiscordActivityParty();
};

} //namespace godot

#endif
