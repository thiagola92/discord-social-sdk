#ifndef DISCORD_GUILD_CHANNEL_H
#define DISCORD_GUILD_CHANNEL_H

#include "discordpp.h"
#include "godot_cpp/classes/ref_counted.hpp"

namespace godot {

class DiscordGuildChannel : public RefCounted {
	GDCLASS(DiscordGuildChannel, RefCounted)

private:
	discordpp::GuildChannel *guild_channel;

protected:
	static void _bind_methods();

public:
	discordpp::GuildChannel *unwrap(); // Internal usage.

	// DiscordGuildChannel();
	~DiscordGuildChannel();
};

} //namespace godot

#endif
