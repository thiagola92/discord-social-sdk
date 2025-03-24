#ifndef DISCORD_USER_HANDLE_H
#define DISCORD_USER_HANDLE_H

#include "discordpp.h"
#include "godot_cpp/classes/ref_counted.hpp"

namespace godot {

class DiscordUserHandle : public RefCounted {
	GDCLASS(DiscordUserHandle, RefCounted)

    DiscordUserHandle();

private:
	discordpp::UserHandle *user_handle;

protected:
	static void _bind_methods();

public:
	discordpp::UserHandle *unwrap(); // Internal usage.

	DiscordUserHandle(discordpp::UserHandle *user_handle);
	~DiscordUserHandle();
};

} //namespace godot

#endif
