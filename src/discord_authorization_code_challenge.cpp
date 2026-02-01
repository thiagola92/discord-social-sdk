
#include "discord_classes.h"

using namespace godot;

// Functions.

DiscordAuthenticationCodeChallengeMethod::Enum DiscordAuthorizationCodeChallenge::method() {
}

String DiscordAuthorizationCodeChallenge::challenge() {
}

void DiscordAuthorizationCodeChallenge::set_challenge(String challenge) {
	std::string p0 = std::string(challenge.utf8().get_data());
}

void DiscordAuthorizationCodeChallenge::set_method(DiscordAuthenticationCodeChallengeMethod::Enum method) {
	discordpp::AuthenticationCodeChallengeMethod p0 = (discordpp::AuthenticationCodeChallengeMethod)method;
}

// Overload functions.

// Binding.
void DiscordAuthorizationCodeChallenge::_bind_methods() {
	ClassDB::bind_method(D_METHOD("challenge"),
			&DiscordAuthorizationCodeChallenge::challenge);

	ClassDB::bind_method(D_METHOD("method"),
			&DiscordAuthorizationCodeChallenge::method);

	ClassDB::bind_method(D_METHOD("set_challenge", "challenge"),
			&DiscordAuthorizationCodeChallenge::set_challenge);

	ClassDB::bind_method(D_METHOD("set_method", "method"),
			&DiscordAuthorizationCodeChallenge::set_method);
}
