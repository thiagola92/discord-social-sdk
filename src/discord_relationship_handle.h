// AUTO-GENERATED
#ifndef DISCORD_RELATIONSHIP_HANDLE_H
#define DISCORD_RELATIONSHIP_HANDLE_H

#include "discord_enum.h"
#include "discord_user_handle.h"
#include "discordpp.h"
#include "godot_cpp/classes/ref_counted.hpp"

namespace godot {

class DiscordRelationshipHandle : public RefCounted {
	GDCLASS(DiscordRelationshipHandle, RefCounted)

private:
	discordpp::RelationshipHandle *relationship_handle; // Doesn't have public empty contrusctor, needs to be a pointer.

	DiscordRelationshipHandle();

protected:
	static void _bind_methods();

public:
	discordpp::RelationshipHandle *unwrap(); // Internal usage.

	DiscordRelationshipType::Enum discord_relationship_type();
	DiscordRelationshipType::Enum game_relationship_type();
	uint64_t id();
	Variant user();

	DiscordRelationshipHandle(discordpp::RelationshipHandle *relationship_handle);
	~DiscordRelationshipHandle();
};

} //namespace godot

#endif
