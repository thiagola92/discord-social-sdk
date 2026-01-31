
#include "discord_classes.h"

using namespace godot;

// Functions.

String DiscordAuthorizationArgs::scopes() {
}

Variant DiscordAuthorizationArgs::code_challenge() {
}

Variant DiscordAuthorizationArgs::custom_scheme_param() {
}

Variant DiscordAuthorizationArgs::integration_type() {
}

Variant DiscordAuthorizationArgs::nonce() {
}

Variant DiscordAuthorizationArgs::state() {
}

int64_t DiscordAuthorizationArgs::client_id() {
}

void DiscordAuthorizationArgs::set_client_id(int64_t client_id) {
	int64_t p0 = client_id;
}

void DiscordAuthorizationArgs::set_code_challenge(Variant code_challenge) {
	std::optional<discordpp::AuthorizationCodeChallenge> p0;

	if (code_challenge.get_type() ==) {
	}
}

void DiscordAuthorizationArgs::set_custom_scheme_param(Variant custom_scheme_param) {
	std::optional<std::string> p0;

	if (custom_scheme_param.get_type() ==) {
	}
}

void DiscordAuthorizationArgs::set_integration_type(Variant integration_type) {
	std::optional<discordpp::IntegrationType> p0;

	if (integration_type.get_type() ==) {
	}
}

void DiscordAuthorizationArgs::set_nonce(Variant nonce) {
	std::optional<std::string> p0;

	if (nonce.get_type() ==) {
	}
}

void DiscordAuthorizationArgs::set_scopes(String scopes) {
	std::string p0 = std::string(scopes.utf8().get_data());
}

void DiscordAuthorizationArgs::set_state(Variant state) {
	std::optional<std::string> p0;

	if (state.get_type() ==) {
	}
}

// Overload functions.

// Binding.
void DiscordAuthorizationArgs::_bind_methods() {
	ClassDB::bind_method(D_METHOD("client_id"),
			&DiscordAuthorizationArgs::client_id);

	ClassDB::bind_method(D_METHOD("code_challenge"),
			&DiscordAuthorizationArgs::code_challenge);

	ClassDB::bind_method(D_METHOD("custom_scheme_param"),
			&DiscordAuthorizationArgs::custom_scheme_param);

	ClassDB::bind_method(D_METHOD("integration_type"),
			&DiscordAuthorizationArgs::integration_type);

	ClassDB::bind_method(D_METHOD("nonce"),
			&DiscordAuthorizationArgs::nonce);

	ClassDB::bind_method(D_METHOD("scopes"),
			&DiscordAuthorizationArgs::scopes);

	ClassDB::bind_method(D_METHOD("set_client_id", "client_id"),
			&DiscordAuthorizationArgs::set_client_id);

	ClassDB::bind_method(D_METHOD("set_code_challenge", "code_challenge"),
			&DiscordAuthorizationArgs::set_code_challenge);

	ClassDB::bind_method(D_METHOD("set_custom_scheme_param", "custom_scheme_param"),
			&DiscordAuthorizationArgs::set_custom_scheme_param);

	ClassDB::bind_method(D_METHOD("set_integration_type", "integration_type"),
			&DiscordAuthorizationArgs::set_integration_type);

	ClassDB::bind_method(D_METHOD("set_nonce", "nonce"),
			&DiscordAuthorizationArgs::set_nonce);

	ClassDB::bind_method(D_METHOD("set_scopes", "scopes"),
			&DiscordAuthorizationArgs::set_scopes);

	ClassDB::bind_method(D_METHOD("set_state", "state"),
			&DiscordAuthorizationArgs::set_state);

	ClassDB::bind_method(D_METHOD("state"),
			&DiscordAuthorizationArgs::state);
}
