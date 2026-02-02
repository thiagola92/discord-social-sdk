
#include "discord_classes.h"

using namespace godot;

// Functions.

DiscordActivityActionTypes::Enum DiscordActivityInvite::type() {
	auto r = obj->Type();
}

String DiscordActivityInvite::party_id() {
	auto r = obj->PartyId();
}

String DiscordActivityInvite::session_id() {
	auto r = obj->SessionId();
}

bool DiscordActivityInvite::is_valid() {
	auto r = obj->IsValid();
}

int64_t DiscordActivityInvite::application_id() {
	auto r = obj->ApplicationId();
}

int64_t DiscordActivityInvite::channel_id() {
	auto r = obj->ChannelId();
}

int64_t DiscordActivityInvite::message_id() {
	auto r = obj->MessageId();
}

int64_t DiscordActivityInvite::parent_application_id() {
	auto r = obj->ParentApplicationId();
}

int64_t DiscordActivityInvite::sender_id() {
	auto r = obj->SenderId();
}

void DiscordActivityInvite::set_application_id(int64_t application_id) {
	int64_t p0 = application_id;
	obj->SetApplicationId(p0);
}

void DiscordActivityInvite::set_channel_id(int64_t channel_id) {
	int64_t p0 = channel_id;
	obj->SetChannelId(p0);
}

void DiscordActivityInvite::set_is_valid(bool is_valid) {
	bool p0 = is_valid;
	obj->SetIsValid(p0);
}

void DiscordActivityInvite::set_message_id(int64_t message_id) {
	int64_t p0 = message_id;
	obj->SetMessageId(p0);
}

void DiscordActivityInvite::set_parent_application_id(int64_t parent_application_id) {
	int64_t p0 = parent_application_id;
	obj->SetParentApplicationId(p0);
}

void DiscordActivityInvite::set_party_id(String party_id) {
	std::string p0 = std::string(party_id.utf8().get_data());
	obj->SetPartyId(p0);
}

void DiscordActivityInvite::set_sender_id(int64_t sender_id) {
	int64_t p0 = sender_id;
	obj->SetSenderId(p0);
}

void DiscordActivityInvite::set_session_id(String session_id) {
	std::string p0 = std::string(session_id.utf8().get_data());
	obj->SetSessionId(p0);
}

void DiscordActivityInvite::set_type(DiscordActivityActionTypes::Enum type) {
	discordpp::ActivityActionTypes p0 = (discordpp::ActivityActionTypes)type;
	obj->SetType(p0);
}

// Overload functions.

// Binding.
void DiscordActivityInvite::_bind_methods() {
	ClassDB::bind_method(D_METHOD("application_id"),
			&DiscordActivityInvite::application_id);

	ClassDB::bind_method(D_METHOD("channel_id"),
			&DiscordActivityInvite::channel_id);

	ClassDB::bind_method(D_METHOD("is_valid"),
			&DiscordActivityInvite::is_valid);

	ClassDB::bind_method(D_METHOD("message_id"),
			&DiscordActivityInvite::message_id);

	ClassDB::bind_method(D_METHOD("parent_application_id"),
			&DiscordActivityInvite::parent_application_id);

	ClassDB::bind_method(D_METHOD("party_id"),
			&DiscordActivityInvite::party_id);

	ClassDB::bind_method(D_METHOD("sender_id"),
			&DiscordActivityInvite::sender_id);

	ClassDB::bind_method(D_METHOD("session_id"),
			&DiscordActivityInvite::session_id);

	ClassDB::bind_method(D_METHOD("set_application_id", "application_id"),
			&DiscordActivityInvite::set_application_id);

	ClassDB::bind_method(D_METHOD("set_channel_id", "channel_id"),
			&DiscordActivityInvite::set_channel_id);

	ClassDB::bind_method(D_METHOD("set_is_valid", "is_valid"),
			&DiscordActivityInvite::set_is_valid);

	ClassDB::bind_method(D_METHOD("set_message_id", "message_id"),
			&DiscordActivityInvite::set_message_id);

	ClassDB::bind_method(D_METHOD("set_parent_application_id", "parent_application_id"),
			&DiscordActivityInvite::set_parent_application_id);

	ClassDB::bind_method(D_METHOD("set_party_id", "party_id"),
			&DiscordActivityInvite::set_party_id);

	ClassDB::bind_method(D_METHOD("set_sender_id", "sender_id"),
			&DiscordActivityInvite::set_sender_id);

	ClassDB::bind_method(D_METHOD("set_session_id", "session_id"),
			&DiscordActivityInvite::set_session_id);

	ClassDB::bind_method(D_METHOD("set_type", "type"),
			&DiscordActivityInvite::set_type);

	ClassDB::bind_method(D_METHOD("type"),
			&DiscordActivityInvite::type);
}
