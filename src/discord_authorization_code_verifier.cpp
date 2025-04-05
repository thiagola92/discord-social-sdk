// AUTO-GENERATED
#include "discord_classes.h"

using namespace godot;

discordpp::AuthorizationCodeVerifier *DiscordAuthorizationCodeVerifier::unwrap() {
	return authorization_code_verifier;
}

DiscordAuthorizationCodeChallenge *DiscordAuthorizationCodeVerifier::challenge() {
	auto r = authorization_code_verifier->Challenge();
	auto t_r = (discordpp::AuthorizationCodeChallenge *)memalloc(sizeof(discordpp::AuthorizationCodeChallenge));
	*t_r = r;
	return memnew(DiscordAuthorizationCodeChallenge{ t_r });
}

void DiscordAuthorizationCodeVerifier::set_challenge(DiscordAuthorizationCodeChallenge *challenge) {
	auto p0 = *challenge->unwrap();
	authorization_code_verifier->SetChallenge(p0);
}

String DiscordAuthorizationCodeVerifier::verifier() {
	auto r = authorization_code_verifier->Verifier();
	return String(r.c_str());
}

void DiscordAuthorizationCodeVerifier::set_verifier(String verifier) {
	auto p0 = verifier.utf8().get_data();
	authorization_code_verifier->SetVerifier(p0);
}

void DiscordAuthorizationCodeVerifier::_bind_methods() {
	ClassDB::bind_method(D_METHOD("challenge"),
			&DiscordAuthorizationCodeVerifier::challenge);

	ClassDB::bind_method(D_METHOD("set_challenge", "challenge"),
			&DiscordAuthorizationCodeVerifier::set_challenge);

	ClassDB::bind_method(D_METHOD("verifier"),
			&DiscordAuthorizationCodeVerifier::verifier);

	ClassDB::bind_method(D_METHOD("set_verifier", "verifier"),
			&DiscordAuthorizationCodeVerifier::set_verifier);
}

DiscordAuthorizationCodeVerifier::DiscordAuthorizationCodeVerifier() {
}

DiscordAuthorizationCodeVerifier::DiscordAuthorizationCodeVerifier(discordpp::AuthorizationCodeVerifier *authorization_code_verifier) {
	this->authorization_code_verifier = authorization_code_verifier;
}

DiscordAuthorizationCodeVerifier::~DiscordAuthorizationCodeVerifier() {}
