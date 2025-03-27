#include "discord_authorization_code_challenge.h"

using namespace godot;

discordpp::AuthorizationCodeChallenge *DiscordAuthorizationCodeChallenge::unwrap() {
	return &authorization_code_challenge;
}

DiscordAuthenticationCodeChallengeMethod::Enum DiscordAuthorizationCodeChallenge::get_method() {
	return (DiscordAuthenticationCodeChallengeMethod::Enum)authorization_code_challenge.Method();
}

void DiscordAuthorizationCodeChallenge::set_method(DiscordAuthenticationCodeChallengeMethod::Enum method) {
	authorization_code_challenge.SetMethod((discordpp::AuthenticationCodeChallengeMethod)method);
}

String DiscordAuthorizationCodeChallenge::get_challenge() {
	return String(authorization_code_challenge.Challenge().c_str());
}

void DiscordAuthorizationCodeChallenge::set_challenge(String challenge) {
	authorization_code_challenge.SetChallenge(challenge.utf8().get_data());
}

void DiscordAuthorizationCodeChallenge::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_method"),
			&DiscordAuthorizationCodeChallenge::get_method);

	ClassDB::bind_method(D_METHOD("set_method", "method"),
			&DiscordAuthorizationCodeChallenge::set_method);

	ClassDB::bind_method(D_METHOD("get_challenge"),
			&DiscordAuthorizationCodeChallenge::get_challenge);

	ClassDB::bind_method(D_METHOD("set_challenge", "challenge"),
			&DiscordAuthorizationCodeChallenge::set_challenge);
}

DiscordAuthorizationCodeChallenge::DiscordAuthorizationCodeChallenge() {}

DiscordAuthorizationCodeChallenge::DiscordAuthorizationCodeChallenge(discordpp::AuthorizationCodeChallenge authorization_code_challenge) {
	this->authorization_code_challenge = authorization_code_challenge;
}

DiscordAuthorizationCodeChallenge::~DiscordAuthorizationCodeChallenge() {}