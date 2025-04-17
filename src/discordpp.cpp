
#include "discord_classes.h"

using namespace godot;

void Discordpp::RunCallbacks() {
	obj->RunCallbacks();
}

String Discordpp::EnumToString21(DiscordppUserHandleAvatarType::Enum value) {
	discordpp::UserHandle::AvatarType p0 = (discordpp::UserHandle::AvatarType)value;

	return String(obj->EnumToString(p0).c_str());
}

String Discordpp::EnumToString20(DiscordppStatusType::Enum value) {
	discordpp::StatusType p0 = (discordpp::StatusType)value;

	return String(obj->EnumToString(p0).c_str());
}

String Discordpp::EnumToString19(DiscordppRelationshipType::Enum value) {
	discordpp::RelationshipType p0 = (discordpp::RelationshipType)value;

	return String(obj->EnumToString(p0).c_str());
}

String Discordpp::EnumToString18(DiscordppLoggingSeverity::Enum value) {
	discordpp::LoggingSeverity p0 = (discordpp::LoggingSeverity)value;

	return String(obj->EnumToString(p0).c_str());
}

String Discordpp::EnumToString17(DiscordppHttpStatusCode::Enum value) {
	discordpp::HttpStatusCode p0 = (discordpp::HttpStatusCode)value;

	return String(obj->EnumToString(p0).c_str());
}

String Discordpp::EnumToString16(DiscordppErrorType::Enum value) {
	discordpp::ErrorType p0 = (discordpp::ErrorType)value;

	return String(obj->EnumToString(p0).c_str());
}

String Discordpp::EnumToString15(DiscordppDisclosureTypes::Enum value) {
	discordpp::DisclosureTypes p0 = (discordpp::DisclosureTypes)value;

	return String(obj->EnumToString(p0).c_str());
}

String Discordpp::EnumToString14(DiscordppClientThread::Enum value) {
	discordpp::Client::Thread p0 = (discordpp::Client::Thread)value;

	return String(obj->EnumToString(p0).c_str());
}

String Discordpp::EnumToString13(DiscordppClientStatus::Enum value) {
	discordpp::Client::Status p0 = (discordpp::Client::Status)value;

	return String(obj->EnumToString(p0).c_str());
}

String Discordpp::EnumToString12(DiscordppClientError::Enum value) {
	discordpp::Client::Error p0 = (discordpp::Client::Error)value;

	return String(obj->EnumToString(p0).c_str());
}

String Discordpp::EnumToString11(DiscordppChannelType::Enum value) {
	discordpp::ChannelType p0 = (discordpp::ChannelType)value;

	return String(obj->EnumToString(p0).c_str());
}

String Discordpp::EnumToString10(DiscordppCallStatus::Enum value) {
	discordpp::Call::Status p0 = (discordpp::Call::Status)value;

	return String(obj->EnumToString(p0).c_str());
}

String Discordpp::EnumToString9(DiscordppCallError::Enum value) {
	discordpp::Call::Error p0 = (discordpp::Call::Error)value;

	return String(obj->EnumToString(p0).c_str());
}

String Discordpp::EnumToString8(DiscordppAuthorizationTokenType::Enum value) {
	discordpp::AuthorizationTokenType p0 = (discordpp::AuthorizationTokenType)value;

	return String(obj->EnumToString(p0).c_str());
}

String Discordpp::EnumToString7(DiscordppAuthenticationExternalAuthType::Enum value) {
	discordpp::AuthenticationExternalAuthType p0 = (discordpp::AuthenticationExternalAuthType)value;

	return String(obj->EnumToString(p0).c_str());
}

String Discordpp::EnumToString6(DiscordppAuthenticationCodeChallengeMethod::Enum value) {
	discordpp::AuthenticationCodeChallengeMethod p0 = (discordpp::AuthenticationCodeChallengeMethod)value;

	return String(obj->EnumToString(p0).c_str());
}

String Discordpp::EnumToString5(DiscordppAudioModeType::Enum value) {
	discordpp::AudioModeType p0 = (discordpp::AudioModeType)value;

	return String(obj->EnumToString(p0).c_str());
}

String Discordpp::EnumToString4(DiscordppAdditionalContentType::Enum value) {
	discordpp::AdditionalContentType p0 = (discordpp::AdditionalContentType)value;

	return String(obj->EnumToString(p0).c_str());
}

String Discordpp::EnumToString3(DiscordppActivityTypes::Enum value) {
	discordpp::ActivityTypes p0 = (discordpp::ActivityTypes)value;

	return String(obj->EnumToString(p0).c_str());
}

String Discordpp::EnumToString2(DiscordppActivityPartyPrivacy::Enum value) {
	discordpp::ActivityPartyPrivacy p0 = (discordpp::ActivityPartyPrivacy)value;

	return String(obj->EnumToString(p0).c_str());
}

String Discordpp::EnumToString1(DiscordppActivityGamePlatforms::Enum value) {
	discordpp::ActivityGamePlatforms p0 = (discordpp::ActivityGamePlatforms)value;

	return String(obj->EnumToString(p0).c_str());
}

String Discordpp::EnumToString0(DiscordppActivityActionTypes::Enum value) {
	discordpp::ActivityActionTypes p0 = (discordpp::ActivityActionTypes)value;

	return String(obj->EnumToString(p0).c_str());
}

void Discordpp::_bind_methods() {
	ClassDB::bind_method(D_METHOD("RunCallbacks"),
			&Discordpp::RunCallbacks);

	ClassDB::bind_method(D_METHOD("EnumToString", "value"),
			&Discordpp::EnumToString);

	ClassDB::bind_method(D_METHOD("EnumToString", "value"),
			&Discordpp::EnumToString);

	ClassDB::bind_method(D_METHOD("EnumToString", "value"),
			&Discordpp::EnumToString);

	ClassDB::bind_method(D_METHOD("EnumToString", "value"),
			&Discordpp::EnumToString);

	ClassDB::bind_method(D_METHOD("EnumToString", "value"),
			&Discordpp::EnumToString);

	ClassDB::bind_method(D_METHOD("EnumToString", "value"),
			&Discordpp::EnumToString);

	ClassDB::bind_method(D_METHOD("EnumToString", "value"),
			&Discordpp::EnumToString);

	ClassDB::bind_method(D_METHOD("EnumToString", "value"),
			&Discordpp::EnumToString);

	ClassDB::bind_method(D_METHOD("EnumToString", "value"),
			&Discordpp::EnumToString);

	ClassDB::bind_method(D_METHOD("EnumToString", "value"),
			&Discordpp::EnumToString);

	ClassDB::bind_method(D_METHOD("EnumToString", "value"),
			&Discordpp::EnumToString);

	ClassDB::bind_method(D_METHOD("EnumToString", "value"),
			&Discordpp::EnumToString);

	ClassDB::bind_method(D_METHOD("EnumToString", "value"),
			&Discordpp::EnumToString);

	ClassDB::bind_method(D_METHOD("EnumToString", "value"),
			&Discordpp::EnumToString);

	ClassDB::bind_method(D_METHOD("EnumToString", "value"),
			&Discordpp::EnumToString);

	ClassDB::bind_method(D_METHOD("EnumToString", "value"),
			&Discordpp::EnumToString);

	ClassDB::bind_method(D_METHOD("EnumToString", "value"),
			&Discordpp::EnumToString);

	ClassDB::bind_method(D_METHOD("EnumToString", "value"),
			&Discordpp::EnumToString);

	ClassDB::bind_method(D_METHOD("EnumToString", "value"),
			&Discordpp::EnumToString);

	ClassDB::bind_method(D_METHOD("EnumToString", "value"),
			&Discordpp::EnumToString);

	ClassDB::bind_method(D_METHOD("EnumToString", "value"),
			&Discordpp::EnumToString);

	ClassDB::bind_method(D_METHOD("EnumToString", "value"),
			&Discordpp::EnumToString);
}
