
#include "discord_classes.h"

using namespace godot;

// Functions.

void Discord::run_callbacks() {
	discordpp::RunCallbacks();
}

// Overload functions.

String Discord::enum_to_string(int64_t value, int64_t enum_id) {
	int64_t p1 = enum_id;

	if (p1 == DiscordActivityActionTypes::id) {
		discordpp::ActivityActionTypes p0 = (discordpp::ActivityActionTypes)value;
		auto r0 = discordpp::EnumToString(p0);

		String r1 = String(r0);

		return r1;
	}

	if (p1 == DiscordActivityPartyPrivacy::id) {
		discordpp::ActivityPartyPrivacy p0 = (discordpp::ActivityPartyPrivacy)value;
		auto r0 = discordpp::EnumToString(p0);

		String r1 = String(r0);

		return r1;
	}

	if (p1 == DiscordActivityTypes::id) {
		discordpp::ActivityTypes p0 = (discordpp::ActivityTypes)value;
		auto r0 = discordpp::EnumToString(p0);

		String r1 = String(r0);

		return r1;
	}

	if (p1 == DiscordStatusDisplayTypes::id) {
		discordpp::StatusDisplayTypes p0 = (discordpp::StatusDisplayTypes)value;
		auto r0 = discordpp::EnumToString(p0);

		String r1 = String(r0);

		return r1;
	}

	if (p1 == DiscordActivityGamePlatforms::id) {
		discordpp::ActivityGamePlatforms p0 = (discordpp::ActivityGamePlatforms)value;
		auto r0 = discordpp::EnumToString(p0);

		String r1 = String(r0);

		return r1;
	}

	if (p1 == DiscordErrorType::id) {
		discordpp::ErrorType p0 = (discordpp::ErrorType)value;
		auto r0 = discordpp::EnumToString(p0);

		String r1 = String(r0);

		return r1;
	}

	if (p1 == DiscordHttpStatusCode::id) {
		discordpp::HttpStatusCode p0 = (discordpp::HttpStatusCode)value;
		auto r0 = discordpp::EnumToString(p0);

		String r1 = String(r0);

		return r1;
	}

	if (p1 == DiscordAuthenticationCodeChallengeMethod::id) {
		discordpp::AuthenticationCodeChallengeMethod p0 = (discordpp::AuthenticationCodeChallengeMethod)value;
		auto r0 = discordpp::EnumToString(p0);

		String r1 = String(r0);

		return r1;
	}

	if (p1 == DiscordIntegrationType::id) {
		discordpp::IntegrationType p0 = (discordpp::IntegrationType)value;
		auto r0 = discordpp::EnumToString(p0);

		String r1 = String(r0);

		return r1;
	}

	if (p1 == DiscordChannelType::id) {
		discordpp::ChannelType p0 = (discordpp::ChannelType)value;
		auto r0 = discordpp::EnumToString(p0);

		String r1 = String(r0);

		return r1;
	}

	if (p1 == DiscordAdditionalContentType::id) {
		discordpp::AdditionalContentType p0 = (discordpp::AdditionalContentType)value;
		auto r0 = discordpp::EnumToString(p0);

		String r1 = String(r0);

		return r1;
	}

	if (p1 == DiscordAudioSystem::id) {
		discordpp::AudioSystem p0 = (discordpp::AudioSystem)value;
		auto r0 = discordpp::EnumToString(p0);

		String r1 = String(r0);

		return r1;
	}

	if (p1 == DiscordCallError::id) {
		discordpp::Call::Error p0 = (discordpp::Call::Error)value;
		auto r0 = discordpp::EnumToString(p0);

		String r1 = String(r0);

		return r1;
	}

	if (p1 == DiscordAudioModeType::id) {
		discordpp::AudioModeType p0 = (discordpp::AudioModeType)value;
		auto r0 = discordpp::EnumToString(p0);

		String r1 = String(r0);

		return r1;
	}

	if (p1 == DiscordCallStatus::id) {
		discordpp::Call::Status p0 = (discordpp::Call::Status)value;
		auto r0 = discordpp::EnumToString(p0);

		String r1 = String(r0);

		return r1;
	}

	if (p1 == DiscordRelationshipType::id) {
		discordpp::RelationshipType p0 = (discordpp::RelationshipType)value;
		auto r0 = discordpp::EnumToString(p0);

		String r1 = String(r0);

		return r1;
	}

	if (p1 == DiscordExternalIdentityProviderType::id) {
		discordpp::ExternalIdentityProviderType p0 = (discordpp::ExternalIdentityProviderType)value;
		auto r0 = discordpp::EnumToString(p0);

		String r1 = String(r0);

		return r1;
	}

	if (p1 == DiscordUserHandleAvatarType::id) {
		discordpp::UserHandle::AvatarType p0 = (discordpp::UserHandle::AvatarType)value;
		auto r0 = discordpp::EnumToString(p0);

		String r1 = String(r0);

		return r1;
	}

	if (p1 == DiscordStatusType::id) {
		discordpp::StatusType p0 = (discordpp::StatusType)value;
		auto r0 = discordpp::EnumToString(p0);

		String r1 = String(r0);

		return r1;
	}

	if (p1 == DiscordDisclosureTypes::id) {
		discordpp::DisclosureTypes p0 = (discordpp::DisclosureTypes)value;
		auto r0 = discordpp::EnumToString(p0);

		String r1 = String(r0);

		return r1;
	}

	if (p1 == DiscordClientError::id) {
		discordpp::Client::Error p0 = (discordpp::Client::Error)value;
		auto r0 = discordpp::EnumToString(p0);

		String r1 = String(r0);

		return r1;
	}

	if (p1 == DiscordClientStatus::id) {
		discordpp::Client::Status p0 = (discordpp::Client::Status)value;
		auto r0 = discordpp::EnumToString(p0);

		String r1 = String(r0);

		return r1;
	}

	if (p1 == DiscordClientThread::id) {
		discordpp::Client::Thread p0 = (discordpp::Client::Thread)value;
		auto r0 = discordpp::EnumToString(p0);

		String r1 = String(r0);

		return r1;
	}

	if (p1 == DiscordAuthorizationTokenType::id) {
		discordpp::AuthorizationTokenType p0 = (discordpp::AuthorizationTokenType)value;
		auto r0 = discordpp::EnumToString(p0);

		String r1 = String(r0);

		return r1;
	}

	if (p1 == DiscordAuthenticationExternalAuthType::id) {
		discordpp::AuthenticationExternalAuthType p0 = (discordpp::AuthenticationExternalAuthType)value;
		auto r0 = discordpp::EnumToString(p0);

		String r1 = String(r0);

		return r1;
	}

	if (p1 == DiscordLoggingSeverity::id) {
		discordpp::LoggingSeverity p0 = (discordpp::LoggingSeverity)value;
		auto r0 = discordpp::EnumToString(p0);

		String r1 = String(r0);

		return r1;
	}

	if (p1 == DiscordRelationshipGroupType::id) {
		discordpp::RelationshipGroupType p0 = (discordpp::RelationshipGroupType)value;
		auto r0 = discordpp::EnumToString(p0);

		String r1 = String(r0);

		return r1;
	}

	return "Not a valid enum_id";
}

// Binding.
void Discord::_bind_methods() {
	ClassDB::bind_static_method("Discord", D_METHOD("run_callbacks"),
			&Discord::run_callbacks);

	ClassDB::bind_static_method("Discord", D_METHOD("enum_to_string", "value", "enum_id"),
			&Discord::enum_to_string);
}
