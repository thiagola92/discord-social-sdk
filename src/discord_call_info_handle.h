#ifndef DISCORD_CALL_INFO_HANDLE_H
#define DISCORD_CALL_INFO_HANDLE_H

#include "discordpp.h"
#include "godot_cpp/classes/ref_counted.hpp"

namespace godot {

class DiscordCallInfoHandle : public RefCounted {
	GDCLASS(DiscordCallInfoHandle, RefCounted)

    DiscordCallInfoHandle();

private:
	discordpp::CallInfoHandle *call_info_handle;

protected:
	static void _bind_methods();

public:
	discordpp::CallInfoHandle *unwrap(); // Internal usage.

	DiscordCallInfoHandle(discordpp::CallInfoHandle *call_info_handle);
	~DiscordCallInfoHandle();
};

} //namespace godot

#endif
