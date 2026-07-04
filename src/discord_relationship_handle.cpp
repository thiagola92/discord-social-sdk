
#include "discord_classes.h"

using namespace godot;

// Functions.

DiscordRelationshipType::Enum DiscordRelationshipHandle::discord_relationship_type() {
	auto r0 = obj->DiscordRelationshipType();

	DiscordRelationshipType::Enum r1 = (DiscordRelationshipType::Enum)r0;

	return r1;
}

DiscordRelationshipType::Enum DiscordRelationshipHandle::game_relationship_type() {
	auto r0 = obj->GameRelationshipType();

	DiscordRelationshipType::Enum r1 = (DiscordRelationshipType::Enum)r0;

	return r1;
}

Variant DiscordRelationshipHandle::user() {
	auto r0 = obj->User();

	Variant r1;

	if (!r0.has_value()) {
		r1 = nullptr;
	} else {
		auto r0_v = r0.value();

		discordpp::UserHandle *r1_v_t = memnew(discordpp::UserHandle(std::move(r0_v)));
		DiscordUserHandle *r1_v = memnew(DiscordUserHandle{ r1_v_t });

		r1 = Variant(r1_v);
	}

	return r1;
}

bool DiscordRelationshipHandle::is_spam_request() {
	auto r0 = obj->IsSpamRequest();

	bool r1 = r0;

	return r1;
}

int64_t DiscordRelationshipHandle::id() {
	auto r0 = obj->Id();

	int64_t r1 = (int64_t)r0;

	return r1;
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
