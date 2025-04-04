// AUTO-GENERATED
#ifndef DISCORD_MESSAGE_HANDLE_H
#define DISCORD_MESSAGE_HANDLE_H

#include "discord_additional_content.h"
#include "discord_channel_handle.h"
#include "discord_enum.h"
#include "discord_lobby_handle.h"
#include "discord_user_handle.h"
#include "discordpp.h"
#include "godot_cpp/classes/ref_counted.hpp"
#include "godot_cpp/variant/typed_array.hpp"
#include "godot_cpp/variant/typed_dictionary.hpp"

namespace godot {

class DiscordMessageHandle : public RefCounted {
	GDCLASS(DiscordMessageHandle, RefCounted)

private:
	discordpp::MessageHandle *message_handle;

	DiscordMessageHandle();

protected:
	static void _bind_methods();

public:
	discordpp::MessageHandle *unwrap(); // Internal usage.

	Variant additional_content();
	Variant author();
	uint64_t author_id();
	Variant channel();
	uint64_t channel_id();
	String content();
	Variant disclosure_type();
	uint64_t edited_timestamp();
	uint64_t id();
	Variant lobby();
	TypedDictionary<String, String> metadata();
	String raw_content();
	Variant recipient();
	uint64_t recipient_id();
	bool sent_from_game();
	uint64_t sent_timestamp();

	DiscordMessageHandle(discordpp::MessageHandle *message_handle);
	~DiscordMessageHandle();
};

} //namespace godot

#endif
