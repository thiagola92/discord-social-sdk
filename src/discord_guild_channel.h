// AUTO-GENERATED
#ifndef DISCORD_GUILD_CHANNEL_H
#define DISCORD_GUILD_CHANNEL_H

#include "discord_linked_lobby.h"
#include "discordpp.h"
#include "godot_cpp/classes/ref_counted.hpp"

namespace godot {

class DiscordGuildChannel : public RefCounted {
	GDCLASS(DiscordGuildChannel, RefCounted)

private:
	discordpp::GuildChannel *guild_channel; // Doesn't have public empty contrusctor, needs to be a pointer.

	DiscordGuildChannel();

protected:
	static void _bind_methods();

public:
	discordpp::GuildChannel *unwrap(); // Internal usage.

	uint64_t id();
	void set_id(uint64_t id);
	String name();
	void set_name(String name);
	bool is_linkable();
	void set_is_linkable(bool is_linkable);
	bool is_viewable_and_writeable_by_all_members();
	void set_is_viewable_and_writeable_by_all_members(bool is_viewable_and_writeable_by_all_members);
	Variant linked_lobby();
	void set_linked_lobby(Variant linked_lobby);

	DiscordGuildChannel(discordpp::GuildChannel *guild_channel);
	~DiscordGuildChannel();
};

} //namespace godot

#endif
