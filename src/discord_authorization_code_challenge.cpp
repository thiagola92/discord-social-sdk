// AUTO-GENERATED
#include "discord_classes.h"

using namespace godot;

discordpp::AuthorizationCodeChallenge *DiscordAuthorizationCodeChallenge::unwrap() {
	return authorization_code_challenge;
}

DiscordAuthenticationCodeChallengeMethod::Enum DiscordAuthorizationCodeChallenge::method() {
	auto r = authorization_code_challenge->Method();
	return (DiscordAuthenticationCodeChallengeMethod::Enum)r;
}

void DiscordAuthorizationCodeChallenge::set_method(DiscordAuthenticationCodeChallengeMethod::Enum method) {
	auto p0 = (discordpp::AuthenticationCodeChallengeMethod)method;
	authorization_code_challenge->SetMethod(p0);
}

String DiscordAuthorizationCodeChallenge::challenge() {
	auto r = authorization_code_challenge->Challenge();
	return String(r.c_str());
}

void DiscordAuthorizationCodeChallenge::set_challenge(String challenge) {
	auto p0 = challenge.utf8().get_data();
	authorization_code_challenge->SetChallenge(p0);
}

void DiscordAuthorizationCodeChallenge::_bind_methods() {
	ClassDB::bind_method(D_METHOD("method"),
			&DiscordAuthorizationCodeChallenge::method);

	ClassDB::bind_method(D_METHOD("set_method", "method"),
			&DiscordAuthorizationCodeChallenge::set_method);

	ClassDB::bind_method(D_METHOD("challenge"),
			&DiscordAuthorizationCodeChallenge::challenge);

	ClassDB::bind_method(D_METHOD("set_challenge", "challenge"),
			&DiscordAuthorizationCodeChallenge::set_challenge);
}

DiscordAuthorizationCodeChallenge::DiscordAuthorizationCodeChallenge() {
	this->authorization_code_challenge = memnew(discordpp::AuthorizationCodeChallenge);
}

DiscordAuthorizationCodeChallenge::DiscordAuthorizationCodeChallenge(discordpp::AuthorizationCodeChallenge *authorization_code_challenge) {
	this->authorization_code_challenge = authorization_code_challenge;
}

DiscordAuthorizationCodeChallenge::~DiscordAuthorizationCodeChallenge() {}
