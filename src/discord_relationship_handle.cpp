#include "discord_relationship_handle.h"

using namespace godot;

discordpp::RelationshipHandle *DiscordRelationshipHandle::unwrap() {
	return relationship_handle;
}

void DiscordRelationshipHandle::_bind_methods() {
	//
}

// DiscordRelationshipHandle::DiscordRelationshipHandle() {}

DiscordRelationshipHandle::~DiscordRelationshipHandle() {}
