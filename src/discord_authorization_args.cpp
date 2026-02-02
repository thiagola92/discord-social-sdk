
#include "discord_classes.h"

using namespace godot;

// Functions.

String DiscordAuthorizationArgs::scopes() {
	auto r = obj->Scopes();
}

Variant DiscordAuthorizationArgs::code_challenge() {
	auto r = obj->CodeChallenge();
}

Variant DiscordAuthorizationArgs::custom_scheme_param() {
	auto r = obj->CustomSchemeParam();
}

Variant DiscordAuthorizationArgs::integration_type() {
	auto r = obj->IntegrationType();
}

Variant DiscordAuthorizationArgs::nonce() {
	auto r = obj->Nonce();
}

Variant DiscordAuthorizationArgs::state() {
	auto r = obj->State();
}

int64_t DiscordAuthorizationArgs::client_id() {
	auto r = obj->ClientId();
}

void DiscordAuthorizationArgs::set_client_id(int64_t client_id) {
	int64_t p0 = client_id;
	obj->SetClientId(p0);
}

void DiscordAuthorizationArgs::set_code_challenge(Variant code_challenge) {
	std::optional<discordpp::AuthorizationCodeChallenge> p0;

	if (code_challenge.get_type() == Variant::OBJECT) {
	}

	obj->SetCodeChallenge(p0);
}

void DiscordAuthorizationArgs::set_custom_scheme_param(Variant custom_scheme_param) {
	std::optional<std::string> p0;

	if (custom_scheme_param.get_type() == Variant::STRING) {
		p0 = custom_scheme_param.stringify().utf8().get_data();
	}

	obj->SetCustomSchemeParam(p0);
}

void DiscordAuthorizationArgs::set_integration_type(Variant integration_type) {
	std::optional<discordpp::IntegrationType> p0;

	if (integration_type.get_type() == Variant::OBJECT) {
	}

	obj->SetIntegrationType(p0);
}

void DiscordAuthorizationArgs::set_nonce(Variant nonce) {
	std::optional<std::string> p0;

	if (nonce.get_type() == Variant::STRING) {
		p0 = nonce.stringify().utf8().get_data();
	}

	obj->SetNonce(p0);
}

void DiscordAuthorizationArgs::set_scopes(String scopes) {
	std::string p0 = std::string(scopes.utf8().get_data());
	obj->SetScopes(p0);
}

void DiscordAuthorizationArgs::set_state(Variant state) {
	std::optional<std::string> p0;

	if (state.get_type() == Variant::STRING) {
		p0 = state.stringify().utf8().get_data();
	}

	obj->SetState(p0);
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
