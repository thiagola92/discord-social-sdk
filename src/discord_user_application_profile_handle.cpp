
#include "discord_classes.h"

using namespace godot;

// Functions.

DiscordExternalIdentityProviderType::Enum DiscordUserApplicationProfileHandle::provider_type() {
	auto r = obj->ProviderType();

	DiscordExternalIdentityProviderType::Enum cr = (DiscordExternalIdentityProviderType::Enum)r;
	return cr;
}

String DiscordUserApplicationProfileHandle::avatar_hash() {
	auto r = obj->AvatarHash();

	String cr = String(r.c_str());
	return cr;
}

String DiscordUserApplicationProfileHandle::metadata() {
	auto r = obj->Metadata();

	String cr = String(r.c_str());
	return cr;
}

String DiscordUserApplicationProfileHandle::provider_issued_user_id() {
	auto r = obj->ProviderIssuedUserId();

	String cr = String(r.c_str());
	return cr;
}

String DiscordUserApplicationProfileHandle::username() {
	auto r = obj->Username();

	String cr = String(r.c_str());
	return cr;
}

Variant DiscordUserApplicationProfileHandle::provider_id() {
	auto r = obj->ProviderId();

	Variant cr;

	if (!r.has_value()) {
		cr = nullptr;
	} else {
		auto r_v = r.value();
		String cr_v = String(r_v.c_str());
		cr = Variant(cr_v);
	}

	return cr;
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
