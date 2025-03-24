#ifndef DISCORD_LINKED_CHANNEL_H
#define DISCORD_LINKED_CHANNEL_H

#include "discordpp.h"
#include "godot_cpp/classes/ref_counted.hpp"

namespace godot {

class DiscordLinkedChannel : public RefCounted {
	GDCLASS(DiscordLinkedChannel, RefCounted)

    DiscordLinkedChannel();

private:
	discordpp::LinkedChannel *linked_channel;

protected:
	static void _bind_methods();

public:
	discordpp::LinkedChannel *unwrap(); // Internal usage.

	DiscordLinkedChannel(discordpp::LinkedChannel *linked_channel);
	~DiscordLinkedChannel();
};

} //namespace godot

#endif
