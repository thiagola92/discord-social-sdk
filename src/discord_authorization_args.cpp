// AUTO-GENERATED
#include "discord_classes.h"

using namespace godot;

discordpp::AuthorizationArgs *DiscordAuthorizationArgs::unwrap() {
	return authorization_args;
}

uint64_t DiscordAuthorizationArgs::client_id() {
	auto r = authorization_args->ClientId();
	return r;
}

void DiscordAuthorizationArgs::set_client_id(uint64_t client_id) {
	authorization_args->SetClientId(client_id);
}

String DiscordAuthorizationArgs::scopes() {
	auto r = authorization_args->Scopes();
	return String(r.c_str());
}

void DiscordAuthorizationArgs::set_scopes(String scopes) {
	auto p0 = scopes.utf8().get_data();
	authorization_args->SetScopes(p0);
}

Variant DiscordAuthorizationArgs::state() {
	auto r = authorization_args->State();

	if (!r.has_value()) {
		return nullptr;
	}

	return Variant(r.value().c_str());
}

void DiscordAuthorizationArgs::set_state(Variant state) {
	std::optional<std::string> p0;

	if (state.get_type() == Variant::STRING) {
		p0 = state.stringify().utf8().get_data();
	}

	authorization_args->SetState(p0);
}

Variant DiscordAuthorizationArgs::nonce() {
	auto r = authorization_args->Nonce();

	if (!r.has_value()) {
		return nullptr;
	}

	return Variant(r.value().c_str());
}

void DiscordAuthorizationArgs::set_nonce(Variant nonce) {
	std::optional<std::string> p0;

	if (nonce.get_type() == Variant::STRING) {
		p0 = nonce.stringify().utf8().get_data();
	}

	authorization_args->SetNonce(p0);
}

Variant DiscordAuthorizationArgs::code_challenge() {
	auto r = authorization_args->CodeChallenge();

	if (!r.has_value()) {
		return nullptr;
	}

	auto t_r = (discordpp::AuthorizationCodeChallenge *)memalloc(sizeof(discordpp::AuthorizationCodeChallenge));
	*t_r = r.value();
	return Variant(memnew(DiscordAuthorizationCodeChallenge{ t_r }));
}

void DiscordAuthorizationArgs::set_code_challenge(Variant code_challenge) {
	std::optional<discordpp::AuthorizationCodeChallenge> p0;

	if (code_challenge.get_type() == Variant::OBJECT) {
		auto t_p0 = Object::cast_to<DiscordAuthorizationCodeChallenge>(code_challenge);
		auto t2_p0 = t_p0->unwrap();
		p0 = std::optional<discordpp::AuthorizationCodeChallenge>{ *t2_p0 };
	}

	authorization_args->SetCodeChallenge(p0);
}

void DiscordAuthorizationArgs::_bind_methods() {
	ClassDB::bind_method(D_METHOD("client_id"),
			&DiscordAuthorizationArgs::client_id);

	ClassDB::bind_method(D_METHOD("set_client_id", "client_id"),
			&DiscordAuthorizationArgs::set_client_id);

	ClassDB::bind_method(D_METHOD("scopes"),
			&DiscordAuthorizationArgs::scopes);

	ClassDB::bind_method(D_METHOD("set_scopes", "scopes"),
			&DiscordAuthorizationArgs::set_scopes);

	ClassDB::bind_method(D_METHOD("state"),
			&DiscordAuthorizationArgs::state);

	ClassDB::bind_method(D_METHOD("set_state", "state"),
			&DiscordAuthorizationArgs::set_state);

	ClassDB::bind_method(D_METHOD("nonce"),
			&DiscordAuthorizationArgs::nonce);

	ClassDB::bind_method(D_METHOD("set_nonce", "nonce"),
			&DiscordAuthorizationArgs::set_nonce);

	ClassDB::bind_method(D_METHOD("code_challenge"),
			&DiscordAuthorizationArgs::code_challenge);

	ClassDB::bind_method(D_METHOD("set_code_challenge", "code_challenge"),
			&DiscordAuthorizationArgs::set_code_challenge);
}

DiscordAuthorizationArgs::DiscordAuthorizationArgs() {
	this->authorization_args = memnew(discordpp::AuthorizationArgs);
}

DiscordAuthorizationArgs::DiscordAuthorizationArgs(discordpp::AuthorizationArgs *authorization_args) {
	this->authorization_args = authorization_args;
}

DiscordAuthorizationArgs::~DiscordAuthorizationArgs() {}
