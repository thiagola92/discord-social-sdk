#ifndef DISCORD_CHANNEL_HANDLE_H
#define DISCORD_CHANNEL_HANDLE_H

#include "discordpp.h"
#include "godot_cpp/classes/ref_counted.hpp"

namespace godot {

class DiscordChannelHandle : public RefCounted {
	GDCLASS(DiscordChannelHandle, RefCounted)

    DiscordChannelHandle();

private:
	discordpp::ChannelHandle *channel_handle;

protected:
	static void _bind_methods();

public:
	discordpp::ChannelHandle *unwrap(); // Internal usage.

	DiscordChannelHandle(discordpp::ChannelHandle *channel_handle);
	~DiscordChannelHandle();
};

} //namespace godot

#endif
