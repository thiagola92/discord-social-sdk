#include "discord_authorization_code_challenge.h"

using namespace godot;

discordpp::AuthorizationCodeChallenge *DiscordAuthorizationCodeChallenge::unwrap() {
	return &code_challenge;
}

String DiscordAuthorizationCodeChallenge::get_challenge() {
	return String(code_challenge.Challenge().c_str());
}

void DiscordAuthorizationCodeChallenge::set_challenge(String challenge) {
	code_challenge.SetChallenge(challenge.utf8().get_data());
}

void DiscordAuthorizationCodeChallenge::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_challenge"),
			&DiscordAuthorizationCodeChallenge::get_challenge);
	ClassDB::bind_method(D_METHOD("set_challenge", "challenge"),
			&DiscordAuthorizationCodeChallenge::set_challenge);
}

DiscordAuthorizationCodeChallenge::DiscordAuthorizationCodeChallenge() {}

DiscordAuthorizationCodeChallenge::DiscordAuthorizationCodeChallenge(discordpp::AuthorizationCodeChallenge code_challenge) {
	this->code_challenge = code_challenge;
}

DiscordAuthorizationCodeChallenge::~DiscordAuthorizationCodeChallenge() {}