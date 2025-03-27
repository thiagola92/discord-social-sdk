#include "discord_authorization_code_verifier.h"
#include "godot_cpp/core/memory.hpp"

using namespace godot;

discordpp::AuthorizationCodeVerifier *DiscordAuthorizationCodeVerifier::unwrap() {
	return authorization_code_verifier;
}

DiscordAuthorizationCodeChallenge *DiscordAuthorizationCodeVerifier::get_challenge() {
	auto cv = authorization_code_verifier->Challenge();
	return memnew(DiscordAuthorizationCodeChallenge(cv));
}

void DiscordAuthorizationCodeVerifier::set_challenge(DiscordAuthorizationCodeChallenge *challenge) {
	authorization_code_verifier->SetChallenge(*(challenge->unwrap()));
}

String DiscordAuthorizationCodeVerifier::get_verifier() {
	return String(authorization_code_verifier->Verifier().c_str());
}

void DiscordAuthorizationCodeVerifier::set_verifier(String verifier) {
	authorization_code_verifier->SetVerifier(verifier.utf8().get_data());
}

void DiscordAuthorizationCodeVerifier::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_challenge"),
			&DiscordAuthorizationCodeVerifier::get_challenge);

	ClassDB::bind_method(D_METHOD("set_challenge", "challenge"),
			&DiscordAuthorizationCodeVerifier::set_challenge);

	ClassDB::bind_method(D_METHOD("get_verifier"),
			&DiscordAuthorizationCodeVerifier::get_verifier);

	ClassDB::bind_method(D_METHOD("set_verifier", "verifier"),
			&DiscordAuthorizationCodeVerifier::set_verifier);
}

DiscordAuthorizationCodeVerifier::DiscordAuthorizationCodeVerifier() {}

DiscordAuthorizationCodeVerifier::DiscordAuthorizationCodeVerifier(discordpp::AuthorizationCodeVerifier *authorization_code_verifier) {
	this->authorization_code_verifier = authorization_code_verifier;
}

DiscordAuthorizationCodeVerifier::~DiscordAuthorizationCodeVerifier() {}
