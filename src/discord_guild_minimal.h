#ifndef DISCORD_GUILD_MINIMAL_H
#define DISCORD_GUILD_MINIMAL_H

#include "discordpp.h"
#include "godot_cpp/classes/ref_counted.hpp"

namespace godot {

class DiscordGuildMinimal : public RefCounted {
	GDCLASS(DiscordGuildMinimal, RefCounted)

    DiscordGuildMinimal();

private:
	discordpp::GuildMinimal *guild_minimal;

protected:
	static void _bind_methods();

public:
	discordpp::GuildMinimal *unwrap(); // Internal usage.

	DiscordGuildMinimal(discordpp::GuildMinimal *guild_minimal);
	~DiscordGuildMinimal();
};

} //namespace godot

#endif
