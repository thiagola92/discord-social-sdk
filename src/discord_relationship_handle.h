#ifndef DISCORD_RELATIONSHIP_HANDLE_H
#define DISCORD_RELATIONSHIP_HANDLE_H

#include "discordpp.h"
#include "godot_cpp/classes/ref_counted.hpp"

namespace godot {

class DiscordRelationshipHandle : public RefCounted {
	GDCLASS(DiscordRelationshipHandle, RefCounted)

private:
	discordpp::RelationshipHandle *relationship_handle;

protected:
	static void _bind_methods();

public:
	discordpp::RelationshipHandle *unwrap(); // Internal usage.

	// DiscordRelationshipHandle();
	~DiscordRelationshipHandle();
};

} //namespace godot

#endif
