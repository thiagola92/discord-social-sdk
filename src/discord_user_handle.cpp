// AUTO-GENERATED
#include "discord_user_handle.h"

using namespace godot;

discordpp::UserHandle *DiscordUserHandle::unwrap() {
	return user_handle;
}

Variant DiscordUserHandle::avatar() {
	auto r = user_handle->Avatar();

	if (!r.has_value()) {
		return nullptr;
	}

	return Variant(r.value().c_str());
}

String DiscordUserHandle::avatar_url(DiscordUserHandle::AvatarType::Enum animated_type, DiscordUserHandle::AvatarType::Enum static_type) {
	auto p0 = (discordpp::UserHandle::AvatarType)animated_type;
	auto p1 = (discordpp::UserHandle::AvatarType)static_type;
	auto r = user_handle->AvatarUrl(p0, p1);
	return String(r.c_str());
}

String DiscordUserHandle::display_name() {
	auto r = user_handle->DisplayName();
	return String(r.c_str());
}

Variant DiscordUserHandle::game_activity() {
	auto r = user_handle->GameActivity();

	if (!r.has_value()) {
		return nullptr;
	}

	auto t_r = (discordpp::Activity *)memalloc(sizeof(discordpp::Activity));
	*t_r = r.value();
	return Variant(memnew(DiscordActivity{ t_r }));
}

Variant DiscordUserHandle::global_name() {
	auto r = user_handle->GlobalName();

	if (!r.has_value()) {
		return nullptr;
	}

	return Variant(r.value().c_str());
}

uint64_t DiscordUserHandle::id() {
	auto r = user_handle->Id();
	return r;
}

bool DiscordUserHandle::is_provisional() {
	auto r = user_handle->IsProvisional();
	return r;
}

DiscordRelationshipHandle *DiscordUserHandle::relationship() {
	auto r = user_handle->Relationship();
	auto t_r = (discordpp::RelationshipHandle *)memalloc(sizeof(discordpp::RelationshipHandle));
	*t_r = r;
	return memnew(DiscordRelationshipHandle{ t_r });
}

DiscordStatusType::Enum DiscordUserHandle::status() {
	auto r = user_handle->Status();
	return (DiscordStatusType::Enum)r;
}

String DiscordUserHandle::username() {
	auto r = user_handle->Username();
	return String(r.c_str());
}

void DiscordUserHandle::_bind_methods() {
	ClassDB::bind_method(D_METHOD("avatar"),
			&DiscordUserHandle::avatar);

	ClassDB::bind_method(D_METHOD("avatar_url", "animated_type", "static_type"),
			&DiscordUserHandle::avatar_url);

	ClassDB::bind_method(D_METHOD("display_name"),
			&DiscordUserHandle::display_name);

	ClassDB::bind_method(D_METHOD("game_activity"),
			&DiscordUserHandle::game_activity);

	ClassDB::bind_method(D_METHOD("global_name"),
			&DiscordUserHandle::global_name);

	ClassDB::bind_method(D_METHOD("id"),
			&DiscordUserHandle::id);

	ClassDB::bind_method(D_METHOD("is_provisional"),
			&DiscordUserHandle::is_provisional);

	ClassDB::bind_method(D_METHOD("relationship"),
			&DiscordUserHandle::relationship);

	ClassDB::bind_method(D_METHOD("status"),
			&DiscordUserHandle::status);

	ClassDB::bind_method(D_METHOD("username"),
			&DiscordUserHandle::username);
}

DiscordUserHandle::DiscordUserHandle() {}

DiscordUserHandle::DiscordUserHandle(discordpp::UserHandle *user_handle) {
	this->user_handle = user_handle;
}

DiscordUserHandle::~DiscordUserHandle() {}
