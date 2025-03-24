#include "discord_authorization_args.h"

using namespace godot;

discordpp::AuthorizationArgs *DiscordAuthorizationArgs::unwrap() {
	return &authorization_args;
}

uint64_t DiscordAuthorizationArgs::get_client_id() {
	return authorization_args.ClientId();
}

void DiscordAuthorizationArgs::set_client_id(uint64_t client_id) {
	authorization_args.SetClientId(client_id);
}

String DiscordAuthorizationArgs::get_scopes() {
	return String(authorization_args.Scopes().c_str());
}

void DiscordAuthorizationArgs::set_scopes(String scopes) {
	authorization_args.SetScopes(scopes.utf8().get_data());
}

Variant DiscordAuthorizationArgs::get_state() {
	auto state = authorization_args.State();

	if (state.has_value()) {
		return Variant(state.value().c_str());
	}

	return nullptr;
}

void DiscordAuthorizationArgs::set_state(Variant state) {
	if (state.get_type() == Variant::STRING) {
		authorization_args.SetState({ state.stringify().utf8().get_data() });
		return;
	}

	authorization_args.SetState({});
}

Variant DiscordAuthorizationArgs::get_nonce() {
	auto nonce = authorization_args.Nonce();

	if (nonce.has_value()) {
		return Variant(nonce.value().c_str());
	}

	return nullptr;
}

void DiscordAuthorizationArgs::set_nonce(Variant nonce) {
	if (nonce.get_type() == Variant::STRING) {
		authorization_args.SetNonce({ nonce.stringify().utf8().get_data() });
		return;
	}

	authorization_args.SetNonce({});
}

Variant DiscordAuthorizationArgs::get_code_challenge() {
	auto code_challenge = authorization_args.CodeChallenge();

	if (code_challenge.has_value()) {
		return memnew(DiscordAuthorizationCodeChallenge(code_challenge.value()));
	}

	return nullptr;
}

void DiscordAuthorizationArgs::set_code_challenge(Variant code_challenge) {
	if (code_challenge.get_type() == Variant::OBJECT) {
		auto cc = Object::cast_to<DiscordAuthorizationCodeChallenge>(code_challenge)->unwrap();
		authorization_args.SetCodeChallenge(std::optional<discordpp::AuthorizationCodeChallenge>{ *cc });
		return;
	}

	authorization_args.SetCodeChallenge({});
}

void DiscordAuthorizationArgs::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_client_id"),
			&DiscordAuthorizationArgs::get_client_id);
	ClassDB::bind_method(D_METHOD("set_client_id", "client_id"),
			&DiscordAuthorizationArgs::set_client_id);

	ClassDB::bind_method(D_METHOD("get_scopes"),
			&DiscordAuthorizationArgs::get_scopes);
	ClassDB::bind_method(D_METHOD("set_scopes", "scopes"),
			&DiscordAuthorizationArgs::set_scopes);

	ClassDB::bind_method(D_METHOD("get_state"),
			&DiscordAuthorizationArgs::get_state);
	ClassDB::bind_method(D_METHOD("set_state", "state"),
			&DiscordAuthorizationArgs::set_state);

	ClassDB::bind_method(D_METHOD("get_nonce"),
			&DiscordAuthorizationArgs::get_nonce);
	ClassDB::bind_method(D_METHOD("set_nonce", "nonce"),
			&DiscordAuthorizationArgs::set_nonce);

	ClassDB::bind_method(D_METHOD("get_code_challenge"),
			&DiscordAuthorizationArgs::get_code_challenge);
	ClassDB::bind_method(D_METHOD("set_code_challenge", "code_challenge"),
			&DiscordAuthorizationArgs::set_code_challenge);
}

DiscordAuthorizationArgs::DiscordAuthorizationArgs() {}

DiscordAuthorizationArgs::~DiscordAuthorizationArgs() {}