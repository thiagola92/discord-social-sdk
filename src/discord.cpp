
#include "discord_classes.h"

using namespace godot;

// Functions.

void Discord::run_callbacks() {
	discordpp::RunCallbacks();
}

// Overload functions.

String Discord::enum_to_string(int value, String enum_type) {
	String p1 = enum_type;

	if (p1 == "discordpp::ActivityActionTypes") {
		discordpp::ActivityActionTypes p0 = (discordpp::ActivityActionTypes)value;
		auto r0 = discordpp::EnumToString(p0);

		String r1 = String(r0);

		return r1;
	}

	if (p1 == "discordpp::ActivityPartyPrivacy") {
		discordpp::ActivityPartyPrivacy p0 = (discordpp::ActivityPartyPrivacy)value;
		auto r0 = discordpp::EnumToString(p0);

		String r1 = String(r0);

		return r1;
	}

	if (p1 == "discordpp::ActivityTypes") {
		discordpp::ActivityTypes p0 = (discordpp::ActivityTypes)value;
		auto r0 = discordpp::EnumToString(p0);

		String r1 = String(r0);

		return r1;
	}

	if (p1 == "discordpp::StatusDisplayTypes") {
		discordpp::StatusDisplayTypes p0 = (discordpp::StatusDisplayTypes)value;
		auto r0 = discordpp::EnumToString(p0);

		String r1 = String(r0);

		return r1;
	}

	if (p1 == "discordpp::ActivityGamePlatforms") {
		discordpp::ActivityGamePlatforms p0 = (discordpp::ActivityGamePlatforms)value;
		auto r0 = discordpp::EnumToString(p0);

		String r1 = String(r0);

		return r1;
	}

	if (p1 == "discordpp::ErrorType") {
		discordpp::ErrorType p0 = (discordpp::ErrorType)value;
		auto r0 = discordpp::EnumToString(p0);

		String r1 = String(r0);

		return r1;
	}

	if (p1 == "discordpp::HttpStatusCode") {
		discordpp::HttpStatusCode p0 = (discordpp::HttpStatusCode)value;
		auto r0 = discordpp::EnumToString(p0);

		String r1 = String(r0);

		return r1;
	}

	if (p1 == "discordpp::AuthenticationCodeChallengeMethod") {
		discordpp::AuthenticationCodeChallengeMethod p0 = (discordpp::AuthenticationCodeChallengeMethod)value;
		auto r0 = discordpp::EnumToString(p0);

		String r1 = String(r0);

		return r1;
	}

	if (p1 == "discordpp::IntegrationType") {
		discordpp::IntegrationType p0 = (discordpp::IntegrationType)value;
		auto r0 = discordpp::EnumToString(p0);

		String r1 = String(r0);

		return r1;
	}

	if (p1 == "discordpp::ChannelType") {
		discordpp::ChannelType p0 = (discordpp::ChannelType)value;
		auto r0 = discordpp::EnumToString(p0);

		String r1 = String(r0);

		return r1;
	}

	if (p1 == "discordpp::AdditionalContentType") {
		discordpp::AdditionalContentType p0 = (discordpp::AdditionalContentType)value;
		auto r0 = discordpp::EnumToString(p0);

		String r1 = String(r0);

		return r1;
	}

	if (p1 == "discordpp::AudioSystem") {
		discordpp::AudioSystem p0 = (discordpp::AudioSystem)value;
		auto r0 = discordpp::EnumToString(p0);

		String r1 = String(r0);

		return r1;
	}

	if (p1 == "discordpp::Call::Error") {
		discordpp::Call::Error p0 = (discordpp::Call::Error)value;
		auto r0 = discordpp::EnumToString(p0);

		String r1 = String(r0);

		return r1;
	}

	if (p1 == "discordpp::AudioModeType") {
		discordpp::AudioModeType p0 = (discordpp::AudioModeType)value;
		auto r0 = discordpp::EnumToString(p0);

		String r1 = String(r0);

		return r1;
	}

	if (p1 == "discordpp::Call::Status") {
		discordpp::Call::Status p0 = (discordpp::Call::Status)value;
		auto r0 = discordpp::EnumToString(p0);

		String r1 = String(r0);

		return r1;
	}

	if (p1 == "discordpp::RelationshipType") {
		discordpp::RelationshipType p0 = (discordpp::RelationshipType)value;
		auto r0 = discordpp::EnumToString(p0);

		String r1 = String(r0);

		return r1;
	}

	if (p1 == "discordpp::ExternalIdentityProviderType") {
		discordpp::ExternalIdentityProviderType p0 = (discordpp::ExternalIdentityProviderType)value;
		auto r0 = discordpp::EnumToString(p0);

		String r1 = String(r0);

		return r1;
	}

	if (p1 == "discordpp::UserHandle::AvatarType") {
		discordpp::UserHandle::AvatarType p0 = (discordpp::UserHandle::AvatarType)value;
		auto r0 = discordpp::EnumToString(p0);

		String r1 = String(r0);

		return r1;
	}

	if (p1 == "discordpp::StatusType") {
		discordpp::StatusType p0 = (discordpp::StatusType)value;
		auto r0 = discordpp::EnumToString(p0);

		String r1 = String(r0);

		return r1;
	}

	if (p1 == "discordpp::DisclosureTypes") {
		discordpp::DisclosureTypes p0 = (discordpp::DisclosureTypes)value;
		auto r0 = discordpp::EnumToString(p0);

		String r1 = String(r0);

		return r1;
	}

	if (p1 == "discordpp::Client::Error") {
		discordpp::Client::Error p0 = (discordpp::Client::Error)value;
		auto r0 = discordpp::EnumToString(p0);

		String r1 = String(r0);

		return r1;
	}

	if (p1 == "discordpp::Client::Status") {
		discordpp::Client::Status p0 = (discordpp::Client::Status)value;
		auto r0 = discordpp::EnumToString(p0);

		String r1 = String(r0);

		return r1;
	}

	if (p1 == "discordpp::Client::Thread") {
		discordpp::Client::Thread p0 = (discordpp::Client::Thread)value;
		auto r0 = discordpp::EnumToString(p0);

		String r1 = String(r0);

		return r1;
	}

	if (p1 == "discordpp::AuthorizationTokenType") {
		discordpp::AuthorizationTokenType p0 = (discordpp::AuthorizationTokenType)value;
		auto r0 = discordpp::EnumToString(p0);

		String r1 = String(r0);

		return r1;
	}

	if (p1 == "discordpp::AuthenticationExternalAuthType") {
		discordpp::AuthenticationExternalAuthType p0 = (discordpp::AuthenticationExternalAuthType)value;
		auto r0 = discordpp::EnumToString(p0);

		String r1 = String(r0);

		return r1;
	}

	if (p1 == "discordpp::LoggingSeverity") {
		discordpp::LoggingSeverity p0 = (discordpp::LoggingSeverity)value;
		auto r0 = discordpp::EnumToString(p0);

		String r1 = String(r0);

		return r1;
	}

	if (p1 == "discordpp::RelationshipGroupType") {
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
