
#include "discord_classes.h"

using namespace godot;

// Functions.

void Discord::run_callbacks() {
	discordpp::RunCallbacks();
}

// Overload functions.

String Discord::enum_to_string(int value, String enum_type) {
	String p1 = enum_type;

	if (p1 == "DiscordActivityActionTypes") {
		discordpp::ActivityActionTypes p0 = (discordpp::ActivityActionTypes)value;
		auto r0 = discordpp::EnumToString(p0);

		String r1 = String(r0);

		return r1;
	}

	if (p1 == "DiscordActivityPartyPrivacy") {
		discordpp::ActivityPartyPrivacy p0 = (discordpp::ActivityPartyPrivacy)value;
		auto r0 = discordpp::EnumToString(p0);

		String r1 = String(r0);

		return r1;
	}

	if (p1 == "DiscordActivityTypes") {
		discordpp::ActivityTypes p0 = (discordpp::ActivityTypes)value;
		auto r0 = discordpp::EnumToString(p0);

		String r1 = String(r0);

		return r1;
	}

	if (p1 == "DiscordStatusDisplayTypes") {
		discordpp::StatusDisplayTypes p0 = (discordpp::StatusDisplayTypes)value;
		auto r0 = discordpp::EnumToString(p0);

		String r1 = String(r0);

		return r1;
	}

	if (p1 == "DiscordActivityGamePlatforms") {
		discordpp::ActivityGamePlatforms p0 = (discordpp::ActivityGamePlatforms)value;
		auto r0 = discordpp::EnumToString(p0);

		String r1 = String(r0);

		return r1;
	}

	if (p1 == "DiscordErrorType") {
		discordpp::ErrorType p0 = (discordpp::ErrorType)value;
		auto r0 = discordpp::EnumToString(p0);

		String r1 = String(r0);

		return r1;
	}

	if (p1 == "DiscordHttpStatusCode") {
		discordpp::HttpStatusCode p0 = (discordpp::HttpStatusCode)value;
		auto r0 = discordpp::EnumToString(p0);

		String r1 = String(r0);

		return r1;
	}

	if (p1 == "DiscordAuthenticationCodeChallengeMethod") {
		discordpp::AuthenticationCodeChallengeMethod p0 = (discordpp::AuthenticationCodeChallengeMethod)value;
		auto r0 = discordpp::EnumToString(p0);

		String r1 = String(r0);

		return r1;
	}

	if (p1 == "DiscordIntegrationType") {
		discordpp::IntegrationType p0 = (discordpp::IntegrationType)value;
		auto r0 = discordpp::EnumToString(p0);

		String r1 = String(r0);

		return r1;
	}

	if (p1 == "DiscordChannelType") {
		discordpp::ChannelType p0 = (discordpp::ChannelType)value;
		auto r0 = discordpp::EnumToString(p0);

		String r1 = String(r0);

		return r1;
	}

	if (p1 == "DiscordAdditionalContentType") {
		discordpp::AdditionalContentType p0 = (discordpp::AdditionalContentType)value;
		auto r0 = discordpp::EnumToString(p0);

		String r1 = String(r0);

		return r1;
	}

	if (p1 == "DiscordAudioSystem") {
		discordpp::AudioSystem p0 = (discordpp::AudioSystem)value;
		auto r0 = discordpp::EnumToString(p0);

		String r1 = String(r0);

		return r1;
	}

	if (p1 == "DiscordCallError") {
		discordpp::Call::Error p0 = (discordpp::Call::Error)value;
		auto r0 = discordpp::EnumToString(p0);

		String r1 = String(r0);

		return r1;
	}

	if (p1 == "DiscordAudioModeType") {
		discordpp::AudioModeType p0 = (discordpp::AudioModeType)value;
		auto r0 = discordpp::EnumToString(p0);

		String r1 = String(r0);

		return r1;
	}

	if (p1 == "DiscordCallStatus") {
		discordpp::Call::Status p0 = (discordpp::Call::Status)value;
		auto r0 = discordpp::EnumToString(p0);

		String r1 = String(r0);

		return r1;
	}

	if (p1 == "DiscordRelationshipType") {
		discordpp::RelationshipType p0 = (discordpp::RelationshipType)value;
		auto r0 = discordpp::EnumToString(p0);

		String r1 = String(r0);

		return r1;
	}

	if (p1 == "DiscordExternalIdentityProviderType") {
		discordpp::ExternalIdentityProviderType p0 = (discordpp::ExternalIdentityProviderType)value;
		auto r0 = discordpp::EnumToString(p0);

		String r1 = String(r0);

		return r1;
	}

	if (p1 == "DiscordUserHandleAvatarType") {
		discordpp::UserHandle::AvatarType p0 = (discordpp::UserHandle::AvatarType)value;
		auto r0 = discordpp::EnumToString(p0);

		String r1 = String(r0);

		return r1;
	}

	if (p1 == "DiscordStatusType") {
		discordpp::StatusType p0 = (discordpp::StatusType)value;
		auto r0 = discordpp::EnumToString(p0);

		String r1 = String(r0);

		return r1;
	}

	if (p1 == "DiscordDisclosureTypes") {
		discordpp::DisclosureTypes p0 = (discordpp::DisclosureTypes)value;
		auto r0 = discordpp::EnumToString(p0);

		String r1 = String(r0);

		return r1;
	}

	if (p1 == "DiscordClientError") {
		discordpp::Client::Error p0 = (discordpp::Client::Error)value;
		auto r0 = discordpp::EnumToString(p0);

		String r1 = String(r0);

		return r1;
	}

	if (p1 == "DiscordClientStatus") {
		discordpp::Client::Status p0 = (discordpp::Client::Status)value;
		auto r0 = discordpp::EnumToString(p0);

		String r1 = String(r0);

		return r1;
	}

	if (p1 == "DiscordClientThread") {
		discordpp::Client::Thread p0 = (discordpp::Client::Thread)value;
		auto r0 = discordpp::EnumToString(p0);

		String r1 = String(r0);

		return r1;
	}

	if (p1 == "DiscordAuthorizationTokenType") {
		discordpp::AuthorizationTokenType p0 = (discordpp::AuthorizationTokenType)value;
		auto r0 = discordpp::EnumToString(p0);

		String r1 = String(r0);

		return r1;
	}

	if (p1 == "DiscordAuthenticationExternalAuthType") {
		discordpp::AuthenticationExternalAuthType p0 = (discordpp::AuthenticationExternalAuthType)value;
		auto r0 = discordpp::EnumToString(p0);

		String r1 = String(r0);

		return r1;
	}

	if (p1 == "DiscordLoggingSeverity") {
		discordpp::LoggingSeverity p0 = (discordpp::LoggingSeverity)value;
		auto r0 = discordpp::EnumToString(p0);

		String r1 = String(r0);

		return r1;
	}

	if (p1 == "DiscordRelationshipGroupType") {
		discordpp::RelationshipGroupType p0 = (discordpp::RelationshipGroupType)value;
		auto r0 = discordpp::EnumToString(p0);

		String r1 = String(r0);

		return r1;
	}

	return "";
}

// Binding.
void Discord::_bind_methods() {
	ClassDB::bind_static_method("Discord", D_METHOD("run_callbacks"),
			&Discord::run_callbacks);

	ClassDB::bind_static_method("Discord", D_METHOD("enum_to_string", "value", "enum_type"),
			&Discord::enum_to_string);
}
