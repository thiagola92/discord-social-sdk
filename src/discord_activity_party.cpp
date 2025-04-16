
#include "discord_classes.h"

using namespace godot;

void DiscordppActivityParty::Drop() {
	obj->Drop();
}

String DiscordppActivityParty::Id() {
	return String(obj->Id().c_str());
}

void DiscordppActivityParty::SetId(String Id) {
	auto p0 = Id.utf8().get_data();
	obj->SetId(p0);
}

int64_t DiscordppActivityParty::CurrentSize() {
	return obj->CurrentSize();
}

void DiscordppActivityParty::SetCurrentSize(int64_t CurrentSize) {
	auto p0 = CurrentSize;
	obj->SetCurrentSize(p0);
}

int64_t DiscordppActivityParty::MaxSize() {
	return obj->MaxSize();
}

void DiscordppActivityParty::SetMaxSize(int64_t MaxSize) {
	auto p0 = MaxSize;
	obj->SetMaxSize(p0);
}

DiscordppActivityPartyPrivacy::Enum DiscordppActivityParty::Privacy() {
	return (DiscordppActivityPartyPrivacy::Enum)obj->Privacy();
}

void DiscordppActivityParty::SetPrivacy(DiscordppActivityPartyPrivacy::Enum Privacy) {
	auto p0 = (discordpp::ActivityPartyPrivacy)Privacy;
	obj->SetPrivacy(p0);
}

void DiscordppActivityParty::_bind_methods() {
	ClassDB::bind_method(D_METHOD("Drop"),
			&DiscordppActivityParty::Drop);

	ClassDB::bind_method(D_METHOD("Id"),
			&DiscordppActivityParty::Id);

	ClassDB::bind_method(D_METHOD("SetId", "Id"),
			&DiscordppActivityParty::SetId);

	ClassDB::bind_method(D_METHOD("CurrentSize"),
			&DiscordppActivityParty::CurrentSize);

	ClassDB::bind_method(D_METHOD("SetCurrentSize", "CurrentSize"),
			&DiscordppActivityParty::SetCurrentSize);

	ClassDB::bind_method(D_METHOD("MaxSize"),
			&DiscordppActivityParty::MaxSize);

	ClassDB::bind_method(D_METHOD("SetMaxSize", "MaxSize"),
			&DiscordppActivityParty::SetMaxSize);

	ClassDB::bind_method(D_METHOD("Privacy"),
			&DiscordppActivityParty::Privacy);

	ClassDB::bind_method(D_METHOD("SetPrivacy", "Privacy"),
			&DiscordppActivityParty::SetPrivacy);
}
