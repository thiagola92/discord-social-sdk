
#include "discord_classes.h"

using namespace godot;

// Functions.

DiscordExternalIdentityProviderType::Enum DiscordUserApplicationProfileHandle::provider_type() {
	auto r = obj->ProviderType();
}

String DiscordUserApplicationProfileHandle::avatar_hash() {
	auto r = obj->AvatarHash();
}

String DiscordUserApplicationProfileHandle::metadata() {
	auto r = obj->Metadata();
}

String DiscordUserApplicationProfileHandle::provider_issued_user_id() {
	auto r = obj->ProviderIssuedUserId();
}

String DiscordUserApplicationProfileHandle::username() {
	auto r = obj->Username();
}

Variant DiscordUserApplicationProfileHandle::provider_id() {
	auto r = obj->ProviderId();
}

// Overload functions.

// Binding.
void DiscordUserApplicationProfileHandle::_bind_methods() {
	ClassDB::bind_method(D_METHOD("avatar_hash"),
			&DiscordUserApplicationProfileHandle::avatar_hash);

	ClassDB::bind_method(D_METHOD("metadata"),
			&DiscordUserApplicationProfileHandle::metadata);

	ClassDB::bind_method(D_METHOD("provider_id"),
			&DiscordUserApplicationProfileHandle::provider_id);

	ClassDB::bind_method(D_METHOD("provider_issued_user_id"),
			&DiscordUserApplicationProfileHandle::provider_issued_user_id);

	ClassDB::bind_method(D_METHOD("provider_type"),
			&DiscordUserApplicationProfileHandle::provider_type);

	ClassDB::bind_method(D_METHOD("username"),
			&DiscordUserApplicationProfileHandle::username);
}
