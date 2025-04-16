
#include "discord_classes.h"

using namespace godot;

void DiscordppAudioDevice::Drop() {
	obj->Drop();
}

bool DiscordppAudioDevice::Equals(Ref<DiscordppAudioDevice> rhs) {
	auto p0 = *rhs->unwrap();

	return obj->Equals(p0);
}

String DiscordppAudioDevice::Id() {
	return String(obj->Id().c_str());
}

void DiscordppAudioDevice::SetId(String Id) {
	const char *p0 = Id.utf8().get_data();

	obj->SetId(p0);
}

String DiscordppAudioDevice::Name() {
	return String(obj->Name().c_str());
}

void DiscordppAudioDevice::SetName(String Name) {
	const char *p0 = Name.utf8().get_data();

	obj->SetName(p0);
}

bool DiscordppAudioDevice::IsDefault() {
	return obj->IsDefault();
}

void DiscordppAudioDevice::SetIsDefault(bool IsDefault) {
	bool p0 = IsDefault;

	obj->SetIsDefault(p0);
}

void DiscordppAudioDevice::_bind_methods() {
	ClassDB::bind_method(D_METHOD("Drop"),
			&DiscordppAudioDevice::Drop);

	ClassDB::bind_method(D_METHOD("Equals", "rhs"),
			&DiscordppAudioDevice::Equals);

	ClassDB::bind_method(D_METHOD("Id"),
			&DiscordppAudioDevice::Id);

	ClassDB::bind_method(D_METHOD("SetId", "Id"),
			&DiscordppAudioDevice::SetId);

	ClassDB::bind_method(D_METHOD("Name"),
			&DiscordppAudioDevice::Name);

	ClassDB::bind_method(D_METHOD("SetName", "Name"),
			&DiscordppAudioDevice::SetName);

	ClassDB::bind_method(D_METHOD("IsDefault"),
			&DiscordppAudioDevice::IsDefault);

	ClassDB::bind_method(D_METHOD("SetIsDefault", "IsDefault"),
			&DiscordppAudioDevice::SetIsDefault);
}
