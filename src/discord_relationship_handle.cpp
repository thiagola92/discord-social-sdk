// AUTO-GENERATED
#include "discord_classes.h"

using namespace godot;

discordpp::RelationshipHandle *DiscordRelationshipHandle::unwrap() {
	return relationship_handle;
}

DiscordRelationshipType::Enum DiscordRelationshipHandle::discord_relationship_type() {
	auto r = relationship_handle->DiscordRelationshipType();
	return (DiscordRelationshipType::Enum)r;
}

DiscordRelationshipType::Enum DiscordRelationshipHandle::game_relationship_type() {
	auto r = relationship_handle->GameRelationshipType();
	return (DiscordRelationshipType::Enum)r;
}

uint64_t DiscordRelationshipHandle::id() {
	auto r = relationship_handle->Id();
	return r;
}

Variant DiscordRelationshipHandle::user() {
	auto r = relationship_handle->User();

	if (!r.has_value()) {
		return nullptr;
	}

	auto t_r = (discordpp::UserHandle *)memalloc(sizeof(discordpp::UserHandle));
	*t_r = r.value();
	return Variant(memnew(DiscordUserHandle{ t_r }));
}

void DiscordRelationshipHandle::_bind_methods() {
	ClassDB::bind_method(D_METHOD("discord_relationship_type"),
			&DiscordRelationshipHandle::discord_relationship_type);

	ClassDB::bind_method(D_METHOD("game_relationship_type"),
			&DiscordRelationshipHandle::game_relationship_type);

	ClassDB::bind_method(D_METHOD("id"),
			&DiscordRelationshipHandle::id);

	ClassDB::bind_method(D_METHOD("user"),
			&DiscordRelationshipHandle::user);
}

DiscordRelationshipHandle::DiscordRelationshipHandle() {
}

DiscordRelationshipHandle::DiscordRelationshipHandle(discordpp::RelationshipHandle *relationship_handle) {
	this->relationship_handle = relationship_handle;
}

DiscordRelationshipHandle::~DiscordRelationshipHandle() {}
