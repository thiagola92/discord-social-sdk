// AUTO-GENERATED
#ifndef DISCORD_CHANNEL_HANDLE_H
#define DISCORD_CHANNEL_HANDLE_H

#include "discord_enum.h"
#include "discordpp.h"
#include "godot_cpp/classes/ref_counted.hpp"
#include "godot_cpp/variant/typed_array.hpp"
#include "godot_cpp/variant/typed_dictionary.hpp"

namespace godot {

class DiscordChannelHandle : public RefCounted {
	GDCLASS(DiscordChannelHandle, RefCounted)

private:
	discordpp::ChannelHandle *channel_handle;

	DiscordChannelHandle();

protected:
	static void _bind_methods();

public:
	discordpp::ChannelHandle *unwrap(); // Internal usage.

	uint64_t id();
	String name();
	TypedArray<uint64_t> recipients();
	DiscordChannelType::Enum type();

	DiscordChannelHandle(discordpp::ChannelHandle *channel_handle);
	~DiscordChannelHandle();
};

} //namespace godot

#endif
