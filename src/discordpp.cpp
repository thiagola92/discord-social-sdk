
#include "discord_classes.h"

using namespace godot;

void Discordpp::RunCallbacks() {
	discordpp::RunCallbacks();
}

String Discordpp::EnumToString21(DiscordppUserHandleAvatarType::Enum value) {
	discordpp::UserHandle::AvatarType p0 = (discordpp::UserHandle::AvatarType)value;

	return String(discordpp::EnumToString(p0));
}

String Discordpp::EnumToString20(DiscordppStatusType::Enum value) {
	discordpp::StatusType p0 = (discordpp::StatusType)value;

	return String(discordpp::EnumToString(p0));
}

String Discordpp::EnumToString19(DiscordppRelationshipType::Enum value) {
	discordpp::RelationshipType p0 = (discordpp::RelationshipType)value;

	return String(discordpp::EnumToString(p0));
}

String Discordpp::EnumToString18(DiscordppLoggingSeverity::Enum value) {
	discordpp::LoggingSeverity p0 = (discordpp::LoggingSeverity)value;

	return String(discordpp::EnumToString(p0));
}

String Discordpp::EnumToString17(DiscordppHttpStatusCode::Enum value) {
	discordpp::HttpStatusCode p0 = (discordpp::HttpStatusCode)value;

	return String(discordpp::EnumToString(p0));
}

String Discordpp::EnumToString16(DiscordppErrorType::Enum value) {
	discordpp::ErrorType p0 = (discordpp::ErrorType)value;

	return String(discordpp::EnumToString(p0));
}

String Discordpp::EnumToString15(DiscordppDisclosureTypes::Enum value) {
	discordpp::DisclosureTypes p0 = (discordpp::DisclosureTypes)value;

	return String(discordpp::EnumToString(p0));
}

String Discordpp::EnumToString14(DiscordppClientThread::Enum value) {
	discordpp::Client::Thread p0 = (discordpp::Client::Thread)value;

	return String(discordpp::EnumToString(p0));
}

String Discordpp::EnumToString13(DiscordppClientStatus::Enum value) {
	discordpp::Client::Status p0 = (discordpp::Client::Status)value;

	return String(discordpp::EnumToString(p0));
}

String Discordpp::EnumToString12(DiscordppClientError::Enum value) {
	discordpp::Client::Error p0 = (discordpp::Client::Error)value;

	return String(discordpp::EnumToString(p0));
}

String Discordpp::EnumToString11(DiscordppChannelType::Enum value) {
	discordpp::ChannelType p0 = (discordpp::ChannelType)value;

	return String(discordpp::EnumToString(p0));
}

String Discordpp::EnumToString10(DiscordppCallStatus::Enum value) {
	discordpp::Call::Status p0 = (discordpp::Call::Status)value;

	return String(discordpp::EnumToString(p0));
}

String Discordpp::EnumToString9(DiscordppCallError::Enum value) {
	discordpp::Call::Error p0 = (discordpp::Call::Error)value;

	return String(discordpp::EnumToString(p0));
}

String Discordpp::EnumToString8(DiscordppAuthorizationTokenType::Enum value) {
	discordpp::AuthorizationTokenType p0 = (discordpp::AuthorizationTokenType)value;

	return String(discordpp::EnumToString(p0));
}

String Discordpp::EnumToString7(DiscordppAuthenticationExternalAuthType::Enum value) {
	discordpp::AuthenticationExternalAuthType p0 = (discordpp::AuthenticationExternalAuthType)value;

	return String(discordpp::EnumToString(p0));
}

String Discordpp::EnumToString6(DiscordppAuthenticationCodeChallengeMethod::Enum value) {
	discordpp::AuthenticationCodeChallengeMethod p0 = (discordpp::AuthenticationCodeChallengeMethod)value;

	return String(discordpp::EnumToString(p0));
}

String Discordpp::EnumToString5(DiscordppAudioModeType::Enum value) {
	discordpp::AudioModeType p0 = (discordpp::AudioModeType)value;

	return String(discordpp::EnumToString(p0));
}

String Discordpp::EnumToString4(DiscordppAdditionalContentType::Enum value) {
	discordpp::AdditionalContentType p0 = (discordpp::AdditionalContentType)value;

	return String(discordpp::EnumToString(p0));
}

String Discordpp::EnumToString3(DiscordppActivityTypes::Enum value) {
	discordpp::ActivityTypes p0 = (discordpp::ActivityTypes)value;

	return String(discordpp::EnumToString(p0));
}

String Discordpp::EnumToString2(DiscordppActivityPartyPrivacy::Enum value) {
	discordpp::ActivityPartyPrivacy p0 = (discordpp::ActivityPartyPrivacy)value;

	return String(discordpp::EnumToString(p0));
}

String Discordpp::EnumToString1(DiscordppActivityGamePlatforms::Enum value) {
	discordpp::ActivityGamePlatforms p0 = (discordpp::ActivityGamePlatforms)value;

	return String(discordpp::EnumToString(p0));
}

String Discordpp::EnumToString0(DiscordppActivityActionTypes::Enum value) {
	discordpp::ActivityActionTypes p0 = (discordpp::ActivityActionTypes)value;

	return String(discordpp::EnumToString(p0));
}

void Discordpp::_bind_methods() {
	ClassDB::bind_method(D_METHOD("RunCallbacks"),
			&Discordpp::RunCallbacks);

	ClassDB::bind_method(D_METHOD("EnumToString21", "value"),
			&Discordpp::EnumToString21);

	ClassDB::bind_method(D_METHOD("EnumToString20", "value"),
			&Discordpp::EnumToString20);

	ClassDB::bind_method(D_METHOD("EnumToString19", "value"),
			&Discordpp::EnumToString19);

	ClassDB::bind_method(D_METHOD("EnumToString18", "value"),
			&Discordpp::EnumToString18);

	ClassDB::bind_method(D_METHOD("EnumToString17", "value"),
			&Discordpp::EnumToString17);

	ClassDB::bind_method(D_METHOD("EnumToString16", "value"),
			&Discordpp::EnumToString16);

	ClassDB::bind_method(D_METHOD("EnumToString15", "value"),
			&Discordpp::EnumToString15);

	ClassDB::bind_method(D_METHOD("EnumToString14", "value"),
			&Discordpp::EnumToString14);

	ClassDB::bind_method(D_METHOD("EnumToString13", "value"),
			&Discordpp::EnumToString13);

	ClassDB::bind_method(D_METHOD("EnumToString12", "value"),
			&Discordpp::EnumToString12);

	ClassDB::bind_method(D_METHOD("EnumToString11", "value"),
			&Discordpp::EnumToString11);

	ClassDB::bind_method(D_METHOD("EnumToString10", "value"),
			&Discordpp::EnumToString10);

	ClassDB::bind_method(D_METHOD("EnumToString9", "value"),
			&Discordpp::EnumToString9);

	ClassDB::bind_method(D_METHOD("EnumToString8", "value"),
			&Discordpp::EnumToString8);

	ClassDB::bind_method(D_METHOD("EnumToString7", "value"),
			&Discordpp::EnumToString7);

	ClassDB::bind_method(D_METHOD("EnumToString6", "value"),
			&Discordpp::EnumToString6);

	ClassDB::bind_method(D_METHOD("EnumToString5", "value"),
			&Discordpp::EnumToString5);

	ClassDB::bind_method(D_METHOD("EnumToString4", "value"),
			&Discordpp::EnumToString4);

	ClassDB::bind_method(D_METHOD("EnumToString3", "value"),
			&Discordpp::EnumToString3);

	ClassDB::bind_method(D_METHOD("EnumToString2", "value"),
			&Discordpp::EnumToString2);

	ClassDB::bind_method(D_METHOD("EnumToString1", "value"),
			&Discordpp::EnumToString1);

	ClassDB::bind_method(D_METHOD("EnumToString0", "value"),
			&Discordpp::EnumToString0);
}
