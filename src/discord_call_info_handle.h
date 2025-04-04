// AUTO-GENERATED
#ifndef DISCORD_CALL_INFO_HANDLE_H
#define DISCORD_CALL_INFO_HANDLE_H

#include "discord_voice_state_handle.h"
#include "discordpp.h"
#include "godot_cpp/classes/ref_counted.hpp"

namespace godot {

class DiscordCallInfoHandle : public RefCounted {
	GDCLASS(DiscordCallInfoHandle, RefCounted)

private:
	discordpp::CallInfoHandle *call_info_handle; // Doesn't have public empty contrusctor, needs to be a pointer.

	DiscordCallInfoHandle();

protected:
	static void _bind_methods();

public:
	discordpp::CallInfoHandle *unwrap(); // Internal usage.

	uint64_t channel_id();
	TypedArray<uint64_t> get_participants();
	Variant get_voice_state_handle(uint64_t user_id);
	uint64_t guild_id();

	DiscordCallInfoHandle(discordpp::CallInfoHandle *call_info_handle);
	~DiscordCallInfoHandle();
};

} //namespace godot

#endif
