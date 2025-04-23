
#include "discordpp_classes.h"

using namespace godot;

void DiscordppActivityInvite::Drop() {
	obj->Drop();
}

int64_t DiscordppActivityInvite::SenderId() {
	return obj->SenderId();
}

void DiscordppActivityInvite::SetSenderId(int64_t SenderId) {
	int64_t p0 = SenderId;

	obj->SetSenderId(p0);
}

int64_t DiscordppActivityInvite::ChannelId() {
	return obj->ChannelId();
}

void DiscordppActivityInvite::SetChannelId(int64_t ChannelId) {
	int64_t p0 = ChannelId;

	obj->SetChannelId(p0);
}

int64_t DiscordppActivityInvite::MessageId() {
	return obj->MessageId();
}

void DiscordppActivityInvite::SetMessageId(int64_t MessageId) {
	int64_t p0 = MessageId;

	obj->SetMessageId(p0);
}

DiscordppActivityActionTypes::Enum DiscordppActivityInvite::Type() {
	return (DiscordppActivityActionTypes::Enum)obj->Type();
}

void DiscordppActivityInvite::SetType(DiscordppActivityActionTypes::Enum Type) {
	discordpp::ActivityActionTypes p0 = (discordpp::ActivityActionTypes)Type;

	obj->SetType(p0);
}

int64_t DiscordppActivityInvite::ApplicationId() {
	return obj->ApplicationId();
}

void DiscordppActivityInvite::SetApplicationId(int64_t ApplicationId) {
	int64_t p0 = ApplicationId;

	obj->SetApplicationId(p0);
}

String DiscordppActivityInvite::PartyId() {
	return String(obj->PartyId().c_str());
}

void DiscordppActivityInvite::SetPartyId(String PartyId) {
	const char *p0 = PartyId.utf8().get_data();

	obj->SetPartyId(p0);
}

String DiscordppActivityInvite::SessionId() {
	return String(obj->SessionId().c_str());
}

void DiscordppActivityInvite::SetSessionId(String SessionId) {
	const char *p0 = SessionId.utf8().get_data();

	obj->SetSessionId(p0);
}

bool DiscordppActivityInvite::IsValid() {
	return obj->IsValid();
}

void DiscordppActivityInvite::SetIsValid(bool IsValid) {
	bool p0 = IsValid;

	obj->SetIsValid(p0);
}

void DiscordppActivityInvite::_bind_methods() {
	ClassDB::bind_method(D_METHOD("Drop"),
			&DiscordppActivityInvite::Drop);

	ClassDB::bind_method(D_METHOD("SenderId"),
			&DiscordppActivityInvite::SenderId);

	ClassDB::bind_method(D_METHOD("SetSenderId", "SenderId"),
			&DiscordppActivityInvite::SetSenderId);

	ClassDB::bind_method(D_METHOD("ChannelId"),
			&DiscordppActivityInvite::ChannelId);

	ClassDB::bind_method(D_METHOD("SetChannelId", "ChannelId"),
			&DiscordppActivityInvite::SetChannelId);

	ClassDB::bind_method(D_METHOD("MessageId"),
			&DiscordppActivityInvite::MessageId);

	ClassDB::bind_method(D_METHOD("SetMessageId", "MessageId"),
			&DiscordppActivityInvite::SetMessageId);

	ClassDB::bind_method(D_METHOD("Type"),
			&DiscordppActivityInvite::Type);

	ClassDB::bind_method(D_METHOD("SetType", "Type"),
			&DiscordppActivityInvite::SetType);

	ClassDB::bind_method(D_METHOD("ApplicationId"),
			&DiscordppActivityInvite::ApplicationId);

	ClassDB::bind_method(D_METHOD("SetApplicationId", "ApplicationId"),
			&DiscordppActivityInvite::SetApplicationId);

	ClassDB::bind_method(D_METHOD("PartyId"),
			&DiscordppActivityInvite::PartyId);

	ClassDB::bind_method(D_METHOD("SetPartyId", "PartyId"),
			&DiscordppActivityInvite::SetPartyId);

	ClassDB::bind_method(D_METHOD("SessionId"),
			&DiscordppActivityInvite::SessionId);

	ClassDB::bind_method(D_METHOD("SetSessionId", "SessionId"),
			&DiscordppActivityInvite::SetSessionId);

	ClassDB::bind_method(D_METHOD("IsValid"),
			&DiscordppActivityInvite::IsValid);

	ClassDB::bind_method(D_METHOD("SetIsValid", "IsValid"),
			&DiscordppActivityInvite::SetIsValid);
}
