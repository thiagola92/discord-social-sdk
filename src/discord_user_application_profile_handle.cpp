
#include "discord_classes.h"

using namespace godot;

// Functions.

DiscordExternalIdentityProviderType DiscordUserApplicationProfileHandle::provider_type() {
}

String DiscordUserApplicationProfileHandle::avatar_hash() {
}

String DiscordUserApplicationProfileHandle::metadata() {
}

String DiscordUserApplicationProfileHandle::provider_issued_user_id() {
}

String DiscordUserApplicationProfileHandle::username() {
}

Variant DiscordUserApplicationProfileHandle::provider_id() {
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
