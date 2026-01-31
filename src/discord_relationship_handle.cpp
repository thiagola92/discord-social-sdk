
#include "discord_classes.h"

using namespace godot;

// Functions.

DiscordRelationshipType DiscordRelationshipHandle::discord_relationship_type() {
}

DiscordRelationshipType DiscordRelationshipHandle::game_relationship_type() {
}

Variant DiscordRelationshipHandle::user() {
}

bool DiscordRelationshipHandle::is_spam_request() {
}

int64_t DiscordRelationshipHandle::id() {
}

// Overload functions.

// Binding.
void DiscordRelationshipHandle::_bind_methods() {
	ClassDB::bind_method(D_METHOD("discord_relationship_type"),
			&DiscordRelationshipHandle::discord_relationship_type);

	ClassDB::bind_method(D_METHOD("game_relationship_type"),
			&DiscordRelationshipHandle::game_relationship_type);

	ClassDB::bind_method(D_METHOD("id"),
			&DiscordRelationshipHandle::id);

	ClassDB::bind_method(D_METHOD("is_spam_request"),
			&DiscordRelationshipHandle::is_spam_request);

	ClassDB::bind_method(D_METHOD("user"),
			&DiscordRelationshipHandle::user);
}
