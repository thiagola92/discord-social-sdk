// AUTO-GENERATED
#ifndef DISCORD_USER_HANDLE_H
#define DISCORD_USER_HANDLE_H

#include "discord_activity.h"
#include "discord_enum.h"
#include "discord_relationship_handle.h"
#include "discordpp.h"
#include "godot_cpp/classes/ref_counted.hpp"
#include "godot_cpp/variant/typed_array.hpp"
#include "godot_cpp/variant/typed_dictionary.hpp"

namespace godot {

class DiscordUserHandle : public RefCounted {
	GDCLASS(DiscordUserHandle, RefCounted)

private:
	discordpp::UserHandle *user_handle;

	DiscordUserHandle();

protected:
	static void _bind_methods();

public:
	discordpp::UserHandle *unwrap(); // Internal usage.

	Variant avatar();
	String avatar_url(DiscordUserHandleAvatarType::Enum animated_type, DiscordUserHandleAvatarType::Enum static_type);
	String display_name();
	Variant game_activity();
	Variant global_name();
	uint64_t id();
	bool is_provisional();
	DiscordRelationshipHandle *relationship();
	DiscordStatusType::Enum status();
	String username();

	DiscordUserHandle(discordpp::UserHandle *user_handle);
	~DiscordUserHandle();
};

} //namespace godot

#endif
