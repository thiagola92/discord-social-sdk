#include "discord_authorization_args.h"
#include "discord_authorization_code_challenge.h"
#include "discord_enum.h"
#include "godot_cpp/variant/variant.hpp"

#include <godot_cpp/core/class_db.hpp>
#include <optional>
#include <string>

using namespace godot;

uint64_t DiscordAuthorizationArgs::get_client_id() {
	return args.ClientId();
}

void DiscordAuthorizationArgs::set_client_id(uint64_t client_id) {
	args.SetClientId(client_id);
}

String DiscordAuthorizationArgs::get_scopes() {
	return String(args.Scopes().c_str());
}

void DiscordAuthorizationArgs::set_scopes(String scopes) {
	args.SetScopes(scopes.utf8().get_data());
}

Variant DiscordAuthorizationArgs::get_state() {
	auto state = args.State();

	if (state.has_value()) {
		return Variant(state.value().c_str());
	}

	return Variant(nullptr);
}

void DiscordAuthorizationArgs::set_state(Variant state) {
	if (state.get_type() == Variant::STRING) {
		args.SetState({ state.stringify().utf8().get_data() });
		return;
	}

	args.SetState({});
}

Variant DiscordAuthorizationArgs::get_nonce() {
	auto nonce = args.Nonce();

	if (nonce.has_value()) {
		return Variant(nonce.value().c_str());
	}

	return Variant(nullptr);
}

void DiscordAuthorizationArgs::set_nonce(Variant nonce) {
	if (nonce.get_type() == Variant::STRING) {
		args.SetNonce({ nonce.stringify().utf8().get_data() });
		return;
	}

	args.SetNonce({});
}

Variant DiscordAuthorizationArgs::get_code_challenge() {
	auto code_challenge = args.CodeChallenge();

	if (code_challenge.has_value()) {
		// auto c = DiscordAuthorizationCodeChallenge(code_challenge.value());
		// return &c;
	}

	return Variant(nullptr);
}

void DiscordAuthorizationArgs::set_code_challenge(Variant code_challenge) {
	if (code_challenge.get_type() == Variant::OBJECT) {
		// args.SetCodeChallenge({ code_challenge.utf8().get_data() });
		return;
	}

	args.SetCodeChallenge({});
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
}

DiscordAuthorizationArgs::DiscordAuthorizationArgs() {}

DiscordAuthorizationArgs::~DiscordAuthorizationArgs() {}