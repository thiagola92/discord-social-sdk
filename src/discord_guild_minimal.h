// AUTO-GENERATED
#ifndef DISCORD_GUILD_MINIMAL_H
#define DISCORD_GUILD_MINIMAL_H

#include "discordpp.h"
#include "godot_cpp/classes/ref_counted.hpp"

namespace godot {

class DiscordGuildMinimal : public RefCounted {
	GDCLASS(DiscordGuildMinimal, RefCounted)

private:
	discordpp::GuildMinimal *guild_minimal; // Doesn't have public empty contrusctor, needs to be a pointer.

	DiscordGuildMinimal();

protected:
	static void _bind_methods();

public:
	discordpp::GuildMinimal *unwrap(); // Internal usage.

	uint64_t id();
	void set_id(uint64_t id);
	String name();
	void set_name(String name);

	DiscordGuildMinimal(discordpp::GuildMinimal *guild_minimal);
	~DiscordGuildMinimal();
};

} //namespace godot

#endif
