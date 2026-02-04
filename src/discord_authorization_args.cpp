
#include "discord_classes.h"

using namespace godot;

// Functions.

String DiscordAuthorizationArgs::scopes() {
	auto r0 = obj->Scopes();

	String r1 = String(r0.c_str());

	return r1;
}

Variant DiscordAuthorizationArgs::code_challenge() {
	auto r0 = obj->CodeChallenge();

	Variant r1;

	if (!r0.has_value()) {
		r1 = nullptr;
	} else {
		auto r0_v = r0.value();

		discordpp::AuthorizationCodeChallenge *r1_v_t = memnew(discordpp::AuthorizationCodeChallenge(std::move(r0_v)));
		DiscordAuthorizationCodeChallenge *r1_v = memnew(DiscordAuthorizationCodeChallenge{ r1_v_t });

		r1 = Variant(r1_v);
	}

	return r1;
}

Variant DiscordAuthorizationArgs::custom_scheme_param() {
	auto r0 = obj->CustomSchemeParam();

	Variant r1;

	if (!r0.has_value()) {
		r1 = nullptr;
	} else {
		auto r0_v = r0.value();
		String r1_v = String(r0_v.c_str());
		r1 = Variant(r1_v);
	}

	return r1;
}

Variant DiscordAuthorizationArgs::integration_type() {
	auto r0 = obj->IntegrationType();

	Variant r1;

	if (!r0.has_value()) {
		r1 = nullptr;
	} else {
		auto r0_v = r0.value();
		DiscordIntegrationType::Enum r1_v = (DiscordIntegrationType::Enum)r0_v;
		r1 = Variant(r1_v);
	}

	return r1;
}

Variant DiscordAuthorizationArgs::nonce() {
	auto r0 = obj->Nonce();

	Variant r1;

	if (!r0.has_value()) {
		r1 = nullptr;
	} else {
		auto r0_v = r0.value();
		String r1_v = String(r0_v.c_str());
		r1 = Variant(r1_v);
	}

	return r1;
}

Variant DiscordAuthorizationArgs::state() {
	auto r0 = obj->State();

	Variant r1;

	if (!r0.has_value()) {
		r1 = nullptr;
	} else {
		auto r0_v = r0.value();
		String r1_v = String(r0_v.c_str());
		r1 = Variant(r1_v);
	}

	return r1;
}

int64_t DiscordAuthorizationArgs::client_id() {
	auto r0 = obj->ClientId();

	int64_t r1 = (int64_t)r0;

	return r1;
}

void DiscordAuthorizationArgs::set_client_id(int64_t client_id) {
	int64_t p0 = client_id;
	obj->SetClientId(p0);
}

void DiscordAuthorizationArgs::set_code_challenge(Variant code_challenge) {
	std::optional<discordpp::AuthorizationCodeChallenge> p0;

	if (code_challenge.get_type() == Variant::OBJECT) {
		DiscordAuthorizationCodeChallenge *p0_t = Object::cast_to<DiscordAuthorizationCodeChallenge>(code_challenge);
		p0 = std::optional<discordpp::AuthorizationCodeChallenge>{ *p0_t->unwrap() };
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
		p0 = std::optional<discordpp::IntegrationType>{ (discordpp::IntegrationType)(uint64_t)integration_type };
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
