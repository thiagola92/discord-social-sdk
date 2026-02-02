
#include "discord_classes.h"

using namespace godot;

// Functions.

DiscordRelationshipType::Enum DiscordRelationshipHandle::discord_relationship_type() {
	auto r = obj->DiscordRelationshipType();
}

DiscordRelationshipType::Enum DiscordRelationshipHandle::game_relationship_type() {
	auto r = obj->GameRelationshipType();
}

Variant DiscordRelationshipHandle::user() {
	auto r = obj->User();
}

bool DiscordRelationshipHandle::is_spam_request() {
	auto r = obj->IsSpamRequest();
}

int64_t DiscordRelationshipHandle::id() {
	auto r = obj->Id();
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
