
#include "discordpp_classes.h"

using namespace godot;

void Discordpp::RunCallbacks() {
	discordpp::RunCallbacks();
}

String Discordpp::EnumToStringActivityActionTypes(DiscordppActivityActionTypes::Enum value) {
	discordpp::ActivityActionTypes p0 = (discordpp::ActivityActionTypes)value;

	return String(discordpp::EnumToString(p0));
}

String Discordpp::EnumToStringActivityPartyPrivacy(DiscordppActivityPartyPrivacy::Enum value) {
	discordpp::ActivityPartyPrivacy p0 = (discordpp::ActivityPartyPrivacy)value;

	return String(discordpp::EnumToString(p0));
}

String Discordpp::EnumToStringActivityTypes(DiscordppActivityTypes::Enum value) {
	discordpp::ActivityTypes p0 = (discordpp::ActivityTypes)value;

	return String(discordpp::EnumToString(p0));
}

String Discordpp::EnumToStringStatusDisplayTypes(DiscordppStatusDisplayTypes::Enum value) {
	discordpp::StatusDisplayTypes p0 = (discordpp::StatusDisplayTypes)value;

	return String(discordpp::EnumToString(p0));
}

String Discordpp::EnumToStringActivityGamePlatforms(DiscordppActivityGamePlatforms::Enum value) {
	discordpp::ActivityGamePlatforms p0 = (discordpp::ActivityGamePlatforms)value;

	return String(discordpp::EnumToString(p0));
}

String Discordpp::EnumToStringErrorType(DiscordppErrorType::Enum value) {
	discordpp::ErrorType p0 = (discordpp::ErrorType)value;

	return String(discordpp::EnumToString(p0));
}

String Discordpp::EnumToStringHttpStatusCode(DiscordppHttpStatusCode::Enum value) {
	discordpp::HttpStatusCode p0 = (discordpp::HttpStatusCode)value;

	return String(discordpp::EnumToString(p0));
}

String Discordpp::EnumToStringAuthenticationCodeChallengeMethod(DiscordppAuthenticationCodeChallengeMethod::Enum value) {
	discordpp::AuthenticationCodeChallengeMethod p0 = (discordpp::AuthenticationCodeChallengeMethod)value;

	return String(discordpp::EnumToString(p0));
}

String Discordpp::EnumToStringIntegrationType(DiscordppIntegrationType::Enum value) {
	discordpp::IntegrationType p0 = (discordpp::IntegrationType)value;

	return String(discordpp::EnumToString(p0));
}

String Discordpp::EnumToStringChannelType(DiscordppChannelType::Enum value) {
	discordpp::ChannelType p0 = (discordpp::ChannelType)value;

	return String(discordpp::EnumToString(p0));
}

String Discordpp::EnumToStringAdditionalContentType(DiscordppAdditionalContentType::Enum value) {
	discordpp::AdditionalContentType p0 = (discordpp::AdditionalContentType)value;

	return String(discordpp::EnumToString(p0));
}

String Discordpp::EnumToStringAudioSystem(DiscordppAudioSystem::Enum value) {
	discordpp::AudioSystem p0 = (discordpp::AudioSystem)value;

	return String(discordpp::EnumToString(p0));
}

String Discordpp::EnumToStringCallError(DiscordppCallError::Enum value) {
	discordpp::Call::Error p0 = (discordpp::Call::Error)value;

	return String(discordpp::EnumToString(p0));
}

String Discordpp::EnumToStringAudioModeType(DiscordppAudioModeType::Enum value) {
	discordpp::AudioModeType p0 = (discordpp::AudioModeType)value;

	return String(discordpp::EnumToString(p0));
}

String Discordpp::EnumToStringCallStatus(DiscordppCallStatus::Enum value) {
	discordpp::Call::Status p0 = (discordpp::Call::Status)value;

	return String(discordpp::EnumToString(p0));
}

String Discordpp::EnumToStringRelationshipType(DiscordppRelationshipType::Enum value) {
	discordpp::RelationshipType p0 = (discordpp::RelationshipType)value;

	return String(discordpp::EnumToString(p0));
}

String Discordpp::EnumToStringExternalIdentityProviderType(DiscordppExternalIdentityProviderType::Enum value) {
	discordpp::ExternalIdentityProviderType p0 = (discordpp::ExternalIdentityProviderType)value;

	return String(discordpp::EnumToString(p0));
}

String Discordpp::EnumToStringUserHandleAvatarType(DiscordppUserHandleAvatarType::Enum value) {
	discordpp::UserHandle::AvatarType p0 = (discordpp::UserHandle::AvatarType)value;

	return String(discordpp::EnumToString(p0));
}

String Discordpp::EnumToStringStatusType(DiscordppStatusType::Enum value) {
	discordpp::StatusType p0 = (discordpp::StatusType)value;

	return String(discordpp::EnumToString(p0));
}

String Discordpp::EnumToStringDisclosureTypes(DiscordppDisclosureTypes::Enum value) {
	discordpp::DisclosureTypes p0 = (discordpp::DisclosureTypes)value;

	return String(discordpp::EnumToString(p0));
}

String Discordpp::EnumToStringClientError(DiscordppClientError::Enum value) {
	discordpp::Client::Error p0 = (discordpp::Client::Error)value;

	return String(discordpp::EnumToString(p0));
}

String Discordpp::EnumToStringClientStatus(DiscordppClientStatus::Enum value) {
	discordpp::Client::Status p0 = (discordpp::Client::Status)value;

	return String(discordpp::EnumToString(p0));
}

String Discordpp::EnumToStringClientThread(DiscordppClientThread::Enum value) {
	discordpp::Client::Thread p0 = (discordpp::Client::Thread)value;

	return String(discordpp::EnumToString(p0));
}

String Discordpp::EnumToStringAuthorizationTokenType(DiscordppAuthorizationTokenType::Enum value) {
	discordpp::AuthorizationTokenType p0 = (discordpp::AuthorizationTokenType)value;

	return String(discordpp::EnumToString(p0));
}

String Discordpp::EnumToStringAuthenticationExternalAuthType(DiscordppAuthenticationExternalAuthType::Enum value) {
	discordpp::AuthenticationExternalAuthType p0 = (discordpp::AuthenticationExternalAuthType)value;

	return String(discordpp::EnumToString(p0));
}

String Discordpp::EnumToStringLoggingSeverity(DiscordppLoggingSeverity::Enum value) {
	discordpp::LoggingSeverity p0 = (discordpp::LoggingSeverity)value;

	return String(discordpp::EnumToString(p0));
}

String Discordpp::EnumToStringRelationshipGroupType(DiscordppRelationshipGroupType::Enum value) {
	discordpp::RelationshipGroupType p0 = (discordpp::RelationshipGroupType)value;

	return String(discordpp::EnumToString(p0));
}

void Discordpp::_bind_methods() {
	ClassDB::bind_static_method("Discordpp", D_METHOD("RunCallbacks"),
			&Discordpp::RunCallbacks);

	ClassDB::bind_static_method("Discordpp", D_METHOD("EnumToStringActivityActionTypes", "value"),
			&Discordpp::EnumToStringActivityActionTypes);

	ClassDB::bind_static_method("Discordpp", D_METHOD("EnumToStringActivityPartyPrivacy", "value"),
			&Discordpp::EnumToStringActivityPartyPrivacy);

	ClassDB::bind_static_method("Discordpp", D_METHOD("EnumToStringActivityTypes", "value"),
			&Discordpp::EnumToStringActivityTypes);

	ClassDB::bind_static_method("Discordpp", D_METHOD("EnumToStringStatusDisplayTypes", "value"),
			&Discordpp::EnumToStringStatusDisplayTypes);

	ClassDB::bind_static_method("Discordpp", D_METHOD("EnumToStringActivityGamePlatforms", "value"),
			&Discordpp::EnumToStringActivityGamePlatforms);

	ClassDB::bind_static_method("Discordpp", D_METHOD("EnumToStringErrorType", "value"),
			&Discordpp::EnumToStringErrorType);

	ClassDB::bind_static_method("Discordpp", D_METHOD("EnumToStringHttpStatusCode", "value"),
			&Discordpp::EnumToStringHttpStatusCode);

	ClassDB::bind_static_method("Discordpp", D_METHOD("EnumToStringAuthenticationCodeChallengeMethod", "value"),
			&Discordpp::EnumToStringAuthenticationCodeChallengeMethod);

	ClassDB::bind_static_method("Discordpp", D_METHOD("EnumToStringIntegrationType", "value"),
			&Discordpp::EnumToStringIntegrationType);

	ClassDB::bind_static_method("Discordpp", D_METHOD("EnumToStringChannelType", "value"),
			&Discordpp::EnumToStringChannelType);

	ClassDB::bind_static_method("Discordpp", D_METHOD("EnumToStringAdditionalContentType", "value"),
			&Discordpp::EnumToStringAdditionalContentType);

	ClassDB::bind_static_method("Discordpp", D_METHOD("EnumToStringAudioSystem", "value"),
			&Discordpp::EnumToStringAudioSystem);

	ClassDB::bind_static_method("Discordpp", D_METHOD("EnumToStringCallError", "value"),
			&Discordpp::EnumToStringCallError);

	ClassDB::bind_static_method("Discordpp", D_METHOD("EnumToStringAudioModeType", "value"),
			&Discordpp::EnumToStringAudioModeType);

	ClassDB::bind_static_method("Discordpp", D_METHOD("EnumToStringCallStatus", "value"),
			&Discordpp::EnumToStringCallStatus);

	ClassDB::bind_static_method("Discordpp", D_METHOD("EnumToStringRelationshipType", "value"),
			&Discordpp::EnumToStringRelationshipType);

	ClassDB::bind_static_method("Discordpp", D_METHOD("EnumToStringExternalIdentityProviderType", "value"),
			&Discordpp::EnumToStringExternalIdentityProviderType);

	ClassDB::bind_static_method("Discordpp", D_METHOD("EnumToStringUserHandleAvatarType", "value"),
			&Discordpp::EnumToStringUserHandleAvatarType);

	ClassDB::bind_static_method("Discordpp", D_METHOD("EnumToStringStatusType", "value"),
			&Discordpp::EnumToStringStatusType);

	ClassDB::bind_static_method("Discordpp", D_METHOD("EnumToStringDisclosureTypes", "value"),
			&Discordpp::EnumToStringDisclosureTypes);

	ClassDB::bind_static_method("Discordpp", D_METHOD("EnumToStringClientError", "value"),
			&Discordpp::EnumToStringClientError);

	ClassDB::bind_static_method("Discordpp", D_METHOD("EnumToStringClientStatus", "value"),
			&Discordpp::EnumToStringClientStatus);

	ClassDB::bind_static_method("Discordpp", D_METHOD("EnumToStringClientThread", "value"),
			&Discordpp::EnumToStringClientThread);

	ClassDB::bind_static_method("Discordpp", D_METHOD("EnumToStringAuthorizationTokenType", "value"),
			&Discordpp::EnumToStringAuthorizationTokenType);

	ClassDB::bind_static_method("Discordpp", D_METHOD("EnumToStringAuthenticationExternalAuthType", "value"),
			&Discordpp::EnumToStringAuthenticationExternalAuthType);

	ClassDB::bind_static_method("Discordpp", D_METHOD("EnumToStringLoggingSeverity", "value"),
			&Discordpp::EnumToStringLoggingSeverity);

	ClassDB::bind_static_method("Discordpp", D_METHOD("EnumToStringRelationshipGroupType", "value"),
			&Discordpp::EnumToStringRelationshipGroupType);
}
