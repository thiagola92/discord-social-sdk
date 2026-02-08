
#include "discord_classes.h"

using namespace godot;

// Functions.

DiscordExternalIdentityProviderType::Enum DiscordUserApplicationProfileHandle::provider_type() {
	auto r0 = obj->ProviderType();

	DiscordExternalIdentityProviderType::Enum r1 = (DiscordExternalIdentityProviderType::Enum)r0;

	return r1;
}

String DiscordUserApplicationProfileHandle::avatar_hash() {
	auto r0 = obj->AvatarHash();

	String r1 = String(r0.c_str());

	return r1;
}

String DiscordUserApplicationProfileHandle::metadata() {
	auto r0 = obj->Metadata();

	String r1 = String(r0.c_str());

	return r1;
}

String DiscordUserApplicationProfileHandle::provider_issued_user_id() {
	auto r0 = obj->ProviderIssuedUserId();

	String r1 = String(r0.c_str());

	return r1;
}

String DiscordUserApplicationProfileHandle::username() {
	auto r0 = obj->Username();

	String r1 = String(r0.c_str());

	return r1;
}

Variant DiscordUserApplicationProfileHandle::provider_id() {
	auto r0 = obj->ProviderId();

	Variant r1;

	if (!r0.has_value()) {
		r1 = nullptr;
	} else {
		auto r0_v = r0.value();
		String r1_v = String(r0_v.c_str());
		r1 = Variant(r1_v);
	}

	return r1;
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
