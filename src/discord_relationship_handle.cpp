
#include "discord_classes.h"

using namespace godot;

// Functions.

DiscordRelationshipType::Enum DiscordRelationshipHandle::discord_relationship_type() {
	auto r = obj->DiscordRelationshipType();

	DiscordRelationshipType::Enum cr = (DiscordRelationshipType::Enum)r;
	return cr;
}

DiscordRelationshipType::Enum DiscordRelationshipHandle::game_relationship_type() {
	auto r = obj->GameRelationshipType();

	DiscordRelationshipType::Enum cr = (DiscordRelationshipType::Enum)r;
	return cr;
}

Variant DiscordRelationshipHandle::user() {
	auto r = obj->User();

	Variant cr;

	if (!r.has_value()) {
		cr = nullptr;
	} else {
		auto r_v = r.value();

		discordpp::UserHandle *cr_v_t = memnew(discordpp::UserHandle(std::move(r_v)));
		DiscordUserHandle *cr_v = memnew(DiscordUserHandle{ cr_v_t });

		cr = Variant(cr_v);
	}

	return cr;
}

bool DiscordRelationshipHandle::is_spam_request() {
	auto r = obj->IsSpamRequest();

	bool cr = r;
	return cr;
}

int64_t DiscordRelationshipHandle::id() {
	auto r = obj->Id();

	int64_t cr = (int64_t)r;
	return cr;
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
