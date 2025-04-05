// AUTO-GENERATED
#include "discord_classes.h"

using namespace godot;

discordpp::ActivityInvite *DiscordActivityInvite::unwrap() {
	return activity_invite;
}

uint64_t DiscordActivityInvite::sender_id() {
	auto r = activity_invite->SenderId();
	return r;
}

void DiscordActivityInvite::set_sender_id(uint64_t sender_id) {
	activity_invite->SetSenderId(sender_id);
}

uint64_t DiscordActivityInvite::channel_id() {
	auto r = activity_invite->ChannelId();
	return r;
}

void DiscordActivityInvite::set_channel_id(uint64_t channel_id) {
	activity_invite->SetChannelId(channel_id);
}

uint64_t DiscordActivityInvite::message_id() {
	auto r = activity_invite->MessageId();
	return r;
}

void DiscordActivityInvite::set_message_id(uint64_t message_id) {
	activity_invite->SetMessageId(message_id);
}

DiscordActivityActionTypes::Enum DiscordActivityInvite::type() {
	auto r = activity_invite->Type();
	return (DiscordActivityActionTypes::Enum)r;
}

void DiscordActivityInvite::set_type(DiscordActivityActionTypes::Enum type) {
	auto p0 = (discordpp::ActivityActionTypes)type;
	activity_invite->SetType(p0);
}

uint64_t DiscordActivityInvite::application_id() {
	auto r = activity_invite->ApplicationId();
	return r;
}

void DiscordActivityInvite::set_application_id(uint64_t application_id) {
	activity_invite->SetApplicationId(application_id);
}

String DiscordActivityInvite::party_id() {
	auto r = activity_invite->PartyId();
	return String(r.c_str());
}

void DiscordActivityInvite::set_party_id(String party_id) {
	auto p0 = party_id.utf8().get_data();
	activity_invite->SetPartyId(p0);
}

bool DiscordActivityInvite::is_valid() {
	auto r = activity_invite->IsValid();
	return r;
}

void DiscordActivityInvite::set_is_valid(bool is_valid) {
	activity_invite->SetIsValid(is_valid);
}

void DiscordActivityInvite::_bind_methods() {
	ClassDB::bind_method(D_METHOD("sender_id"),
			&DiscordActivityInvite::sender_id);

	ClassDB::bind_method(D_METHOD("set_sender_id", "sender_id"),
			&DiscordActivityInvite::set_sender_id);

	ClassDB::bind_method(D_METHOD("channel_id"),
			&DiscordActivityInvite::channel_id);

	ClassDB::bind_method(D_METHOD("set_channel_id", "channel_id"),
			&DiscordActivityInvite::set_channel_id);

	ClassDB::bind_method(D_METHOD("message_id"),
			&DiscordActivityInvite::message_id);

	ClassDB::bind_method(D_METHOD("set_message_id", "message_id"),
			&DiscordActivityInvite::set_message_id);

	ClassDB::bind_method(D_METHOD("type"),
			&DiscordActivityInvite::type);

	ClassDB::bind_method(D_METHOD("set_type", "type"),
			&DiscordActivityInvite::set_type);

	ClassDB::bind_method(D_METHOD("application_id"),
			&DiscordActivityInvite::application_id);

	ClassDB::bind_method(D_METHOD("set_application_id", "application_id"),
			&DiscordActivityInvite::set_application_id);

	ClassDB::bind_method(D_METHOD("party_id"),
			&DiscordActivityInvite::party_id);

	ClassDB::bind_method(D_METHOD("set_party_id", "party_id"),
			&DiscordActivityInvite::set_party_id);

	ClassDB::bind_method(D_METHOD("is_valid"),
			&DiscordActivityInvite::is_valid);

	ClassDB::bind_method(D_METHOD("set_is_valid", "is_valid"),
			&DiscordActivityInvite::set_is_valid);
}

DiscordActivityInvite::DiscordActivityInvite() {
	this->activity_invite = memnew(discordpp::ActivityInvite);
}

DiscordActivityInvite::DiscordActivityInvite(discordpp::ActivityInvite *activity_invite) {
	this->activity_invite = activity_invite;
}

DiscordActivityInvite::~DiscordActivityInvite() {}
