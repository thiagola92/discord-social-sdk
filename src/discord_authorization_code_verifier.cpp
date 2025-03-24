#include "discord_authorization_code_verifier.h"

using namespace godot;

discordpp::AuthorizationCodeVerifier *DiscordAuthorizationCodeVerifier::unwrap() {
	return authorization_code_verifier;
}

void DiscordAuthorizationCodeVerifier::_bind_methods() {
	//
}

DiscordAuthorizationCodeVerifier::DiscordAuthorizationCodeVerifier(discordpp::AuthorizationCodeVerifier *authorization_code_verifier) {}

DiscordAuthorizationCodeVerifier::~DiscordAuthorizationCodeVerifier() {}
