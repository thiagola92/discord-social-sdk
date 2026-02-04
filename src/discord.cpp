
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
		auto r = discordpp::EnumToString(p0);

		String cr = String(r);
		return cr;
	}

	if (p1 == "discordpp::ActivityActionTypes") {
		discordpp::ActivityPartyPrivacy p0 = (discordpp::ActivityPartyPrivacy)value;
		auto r = discordpp::EnumToString(p0);

		String cr = String(r);
		return cr;
	}

	if (p1 == "discordpp::ActivityActionTypes") {
		discordpp::ActivityTypes p0 = (discordpp::ActivityTypes)value;
		auto r = discordpp::EnumToString(p0);

		String cr = String(r);
		return cr;
	}

	if (p1 == "discordpp::ActivityActionTypes") {
		discordpp::StatusDisplayTypes p0 = (discordpp::StatusDisplayTypes)value;
		auto r = discordpp::EnumToString(p0);

		String cr = String(r);
		return cr;
	}

	if (p1 == "discordpp::ActivityActionTypes") {
		discordpp::ActivityGamePlatforms p0 = (discordpp::ActivityGamePlatforms)value;
		auto r = discordpp::EnumToString(p0);

		String cr = String(r);
		return cr;
	}

	if (p1 == "discordpp::ActivityActionTypes") {
		discordpp::ErrorType p0 = (discordpp::ErrorType)value;
		auto r = discordpp::EnumToString(p0);

		String cr = String(r);
		return cr;
	}

	if (p1 == "discordpp::ActivityActionTypes") {
		discordpp::HttpStatusCode p0 = (discordpp::HttpStatusCode)value;
		auto r = discordpp::EnumToString(p0);

		String cr = String(r);
		return cr;
	}

	if (p1 == "discordpp::ActivityActionTypes") {
		discordpp::AuthenticationCodeChallengeMethod p0 = (discordpp::AuthenticationCodeChallengeMethod)value;
		auto r = discordpp::EnumToString(p0);

		String cr = String(r);
		return cr;
	}

	if (p1 == "discordpp::ActivityActionTypes") {
		discordpp::IntegrationType p0 = (discordpp::IntegrationType)value;
		auto r = discordpp::EnumToString(p0);

		String cr = String(r);
		return cr;
	}

	if (p1 == "discordpp::ActivityActionTypes") {
		discordpp::ChannelType p0 = (discordpp::ChannelType)value;
		auto r = discordpp::EnumToString(p0);

		String cr = String(r);
		return cr;
	}

	if (p1 == "discordpp::ActivityActionTypes") {
		discordpp::AdditionalContentType p0 = (discordpp::AdditionalContentType)value;
		auto r = discordpp::EnumToString(p0);

		String cr = String(r);
		return cr;
	}

	if (p1 == "discordpp::ActivityActionTypes") {
		discordpp::AudioSystem p0 = (discordpp::AudioSystem)value;
		auto r = discordpp::EnumToString(p0);

		String cr = String(r);
		return cr;
	}

	if (p1 == "discordpp::ActivityActionTypes") {
		discordpp::Call::Error p0 = (discordpp::Call::Error)value;
		auto r = discordpp::EnumToString(p0);

		String cr = String(r);
		return cr;
	}

	if (p1 == "discordpp::ActivityActionTypes") {
		discordpp::AudioModeType p0 = (discordpp::AudioModeType)value;
		auto r = discordpp::EnumToString(p0);

		String cr = String(r);
		return cr;
	}

	if (p1 == "discordpp::ActivityActionTypes") {
		discordpp::Call::Status p0 = (discordpp::Call::Status)value;
		auto r = discordpp::EnumToString(p0);

		String cr = String(r);
		return cr;
	}

	if (p1 == "discordpp::ActivityActionTypes") {
		discordpp::RelationshipType p0 = (discordpp::RelationshipType)value;
		auto r = discordpp::EnumToString(p0);

		String cr = String(r);
		return cr;
	}

	if (p1 == "discordpp::ActivityActionTypes") {
		discordpp::ExternalIdentityProviderType p0 = (discordpp::ExternalIdentityProviderType)value;
		auto r = discordpp::EnumToString(p0);

		String cr = String(r);
		return cr;
	}

	if (p1 == "discordpp::ActivityActionTypes") {
		discordpp::UserHandle::AvatarType p0 = (discordpp::UserHandle::AvatarType)value;
		auto r = discordpp::EnumToString(p0);

		String cr = String(r);
		return cr;
	}

	if (p1 == "discordpp::ActivityActionTypes") {
		discordpp::StatusType p0 = (discordpp::StatusType)value;
		auto r = discordpp::EnumToString(p0);

		String cr = String(r);
		return cr;
	}

	if (p1 == "discordpp::ActivityActionTypes") {
		discordpp::DisclosureTypes p0 = (discordpp::DisclosureTypes)value;
		auto r = discordpp::EnumToString(p0);

		String cr = String(r);
		return cr;
	}

	if (p1 == "discordpp::ActivityActionTypes") {
		discordpp::Client::Error p0 = (discordpp::Client::Error)value;
		auto r = discordpp::EnumToString(p0);

		String cr = String(r);
		return cr;
	}

	if (p1 == "discordpp::ActivityActionTypes") {
		discordpp::Client::Status p0 = (discordpp::Client::Status)value;
		auto r = discordpp::EnumToString(p0);

		String cr = String(r);
		return cr;
	}

	if (p1 == "discordpp::ActivityActionTypes") {
		discordpp::Client::Thread p0 = (discordpp::Client::Thread)value;
		auto r = discordpp::EnumToString(p0);

		String cr = String(r);
		return cr;
	}

	if (p1 == "discordpp::ActivityActionTypes") {
		discordpp::AuthorizationTokenType p0 = (discordpp::AuthorizationTokenType)value;
		auto r = discordpp::EnumToString(p0);

		String cr = String(r);
		return cr;
	}

	if (p1 == "discordpp::ActivityActionTypes") {
		discordpp::AuthenticationExternalAuthType p0 = (discordpp::AuthenticationExternalAuthType)value;
		auto r = discordpp::EnumToString(p0);

		String cr = String(r);
		return cr;
	}

	if (p1 == "discordpp::ActivityActionTypes") {
		discordpp::LoggingSeverity p0 = (discordpp::LoggingSeverity)value;
		auto r = discordpp::EnumToString(p0);

		String cr = String(r);
		return cr;
	}

	if (p1 == "discordpp::ActivityActionTypes") {
		discordpp::RelationshipGroupType p0 = (discordpp::RelationshipGroupType)value;
		auto r = discordpp::EnumToString(p0);

		String cr = String(r);
		return cr;
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
