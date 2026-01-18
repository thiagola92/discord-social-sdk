
#include "discordpp_classes.h"

using namespace godot;

void DiscordppUserApplicationProfileHandle::Drop() {
	obj->Drop();
}

String DiscordppUserApplicationProfileHandle::AvatarHash() {
	return String(obj->AvatarHash().c_str());
}

String DiscordppUserApplicationProfileHandle::Metadata() {
	return String(obj->Metadata().c_str());
}

Variant DiscordppUserApplicationProfileHandle::ProviderId() {
	auto r = obj->ProviderId();

	if (!r.has_value()) {
		return nullptr;
	}

	return Variant(r.value().c_str());
}

String DiscordppUserApplicationProfileHandle::ProviderIssuedUserId() {
	return String(obj->ProviderIssuedUserId().c_str());
}

DiscordppExternalIdentityProviderType::Enum DiscordppUserApplicationProfileHandle::ProviderType() {
	return (DiscordppExternalIdentityProviderType::Enum)obj->ProviderType();
}

String DiscordppUserApplicationProfileHandle::Username() {
	return String(obj->Username().c_str());
}

void DiscordppUserApplicationProfileHandle::_bind_methods() {
	ClassDB::bind_method(D_METHOD("Drop"),
			&DiscordppUserApplicationProfileHandle::Drop);

	ClassDB::bind_method(D_METHOD("AvatarHash"),
			&DiscordppUserApplicationProfileHandle::AvatarHash);

	ClassDB::bind_method(D_METHOD("Metadata"),
			&DiscordppUserApplicationProfileHandle::Metadata);

	ClassDB::bind_method(D_METHOD("ProviderId"),
			&DiscordppUserApplicationProfileHandle::ProviderId);

	ClassDB::bind_method(D_METHOD("ProviderIssuedUserId"),
			&DiscordppUserApplicationProfileHandle::ProviderIssuedUserId);

	ClassDB::bind_method(D_METHOD("ProviderType"),
			&DiscordppUserApplicationProfileHandle::ProviderType);

	ClassDB::bind_method(D_METHOD("Username"),
			&DiscordppUserApplicationProfileHandle::Username);
}
