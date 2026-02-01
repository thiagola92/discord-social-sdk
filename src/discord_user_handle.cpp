
#include "discord_classes.h"

using namespace godot;

// Functions.

DiscordRelationshipHandle *DiscordUserHandle::relationship() {
}

DiscordStatusType::Enum DiscordUserHandle::status() {
}

String DiscordUserHandle::avatar_type_to_string(DiscordUserHandleAvatarType::Enum type) {
	discordpp::UserHandle::AvatarType p0 = (discordpp::UserHandle::AvatarType)type;
}

String DiscordUserHandle::avatar_url(DiscordUserHandleAvatarType::Enum animated_type, DiscordUserHandleAvatarType::Enum static_type) {
	discordpp::UserHandle::AvatarType p0 = (discordpp::UserHandle::AvatarType)animated_type;
	discordpp::UserHandle::AvatarType p1 = (discordpp::UserHandle::AvatarType)static_type;
}

String DiscordUserHandle::display_name() {
}

String DiscordUserHandle::username() {
}

TypedArray<DiscordUserApplicationProfileHandle> DiscordUserHandle::user_application_profiles() {
}

Variant DiscordUserHandle::avatar() {
}

Variant DiscordUserHandle::game_activity() {
}

Variant DiscordUserHandle::global_name() {
}

bool DiscordUserHandle::is_provisional() {
}

int64_t DiscordUserHandle::id() {
}

// Overload functions.

// Binding.
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

	ClassDB::bind_method(D_METHOD("user_application_profiles"),
			&DiscordUserHandle::user_application_profiles);

	ClassDB::bind_method(D_METHOD("username"),
			&DiscordUserHandle::username);

	ClassDB::bind_static_method("DiscordUserHandle", D_METHOD("avatar_type_to_string", "type"),
			&DiscordUserHandle::avatar_type_to_string);
}
