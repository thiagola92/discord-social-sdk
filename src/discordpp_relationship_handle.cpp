
#include "discordpp_classes.h"

using namespace godot;

void DiscordppRelationshipHandle::Drop() {
	obj->Drop();
}

DiscordppRelationshipType::Enum DiscordppRelationshipHandle::DiscordRelationshipType() {
	return (DiscordppRelationshipType::Enum)obj->DiscordRelationshipType();
}

DiscordppRelationshipType::Enum DiscordppRelationshipHandle::GameRelationshipType() {
	return (DiscordppRelationshipType::Enum)obj->GameRelationshipType();
}

int64_t DiscordppRelationshipHandle::Id() {
	return obj->Id();
}

Variant DiscordppRelationshipHandle::User() {
	auto r = obj->User();

	if (!r.has_value()) {
		return nullptr;
	}

	discordpp::UserHandle *t_r = memnew(discordpp::UserHandle(r.value()));
	return Variant(memnew(DiscordppUserHandle{ t_r }));
}

void DiscordppRelationshipHandle::_bind_methods() {
	ClassDB::bind_method(D_METHOD("Drop"),
			&DiscordppRelationshipHandle::Drop);

	ClassDB::bind_method(D_METHOD("DiscordRelationshipType"),
			&DiscordppRelationshipHandle::DiscordRelationshipType);

	ClassDB::bind_method(D_METHOD("GameRelationshipType"),
			&DiscordppRelationshipHandle::GameRelationshipType);

	ClassDB::bind_method(D_METHOD("Id"),
			&DiscordppRelationshipHandle::Id);

	ClassDB::bind_method(D_METHOD("User"),
			&DiscordppRelationshipHandle::User);
}
