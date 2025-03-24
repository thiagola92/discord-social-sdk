#ifndef DISCORD_MESSAGE_HANDLE_H
#define DISCORD_MESSAGE_HANDLE_H

#include "discordpp.h"
#include "godot_cpp/classes/ref_counted.hpp"

namespace godot {

class DiscordMessageHandle : public RefCounted {
	GDCLASS(DiscordMessageHandle, RefCounted)

private:
	discordpp::MessageHandle *message_handle;

protected:
	static void _bind_methods();

public:
	discordpp::MessageHandle *unwrap(); // Internal usage.

	// DiscordMessageHandle();
	~DiscordMessageHandle();
};

} //namespace godot

#endif
