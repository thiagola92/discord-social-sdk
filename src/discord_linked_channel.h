// AUTO-GENERATED
#ifndef DISCORD_LINKED_CHANNEL_H
#define DISCORD_LINKED_CHANNEL_H

#include "discordpp.h"
#include "godot_cpp/classes/ref_counted.hpp"
#include "godot_cpp/variant/typed_array.hpp"
#include "godot_cpp/variant/typed_dictionary.hpp"

namespace godot {

class DiscordLinkedChannel : public RefCounted {
	GDCLASS(DiscordLinkedChannel, RefCounted)

private:
	discordpp::LinkedChannel *linked_channel;

	DiscordLinkedChannel();

protected:
	static void _bind_methods();

public:
	discordpp::LinkedChannel *unwrap(); // Internal usage.

	uint64_t id();
	void set_id(uint64_t id);
	String name();
	void set_name(String name);
	uint64_t guild_id();
	void set_guild_id(uint64_t guild_id);

	DiscordLinkedChannel(discordpp::LinkedChannel *linked_channel);
	~DiscordLinkedChannel();
};

} //namespace godot

#endif
