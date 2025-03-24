#ifndef DISCORD_ACTIVITY_INVITE_H
#define DISCORD_ACTIVITY_INVITE_H

#include "discordpp.h"
#include "godot_cpp/classes/ref_counted.hpp"

namespace godot {

class DiscordActivityInvite : public RefCounted {
	GDCLASS(DiscordActivityInvite, RefCounted)

private:
	discordpp::ActivityInvite activity_invite;

protected:
	static void _bind_methods();

public:
	discordpp::ActivityInvite *unwrap(); // Internal usage.

	DiscordActivityInvite();
	~DiscordActivityInvite();
};

} //namespace godot

#endif
