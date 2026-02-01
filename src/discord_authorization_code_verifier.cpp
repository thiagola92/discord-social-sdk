
#include "discord_classes.h"

using namespace godot;

// Functions.

DiscordAuthorizationCodeChallenge DiscordAuthorizationCodeVerifier::challenge() {
}

String DiscordAuthorizationCodeVerifier::verifier() {
}

void DiscordAuthorizationCodeVerifier::set_challenge(DiscordAuthorizationCodeChallenge challenge) {
	// TODO object
}

void DiscordAuthorizationCodeVerifier::set_verifier(String verifier) {
	std::string p0 = std::string(verifier.utf8().get_data());
}

// Overload functions.

// Binding.
void DiscordAuthorizationCodeVerifier::_bind_methods() {
	ClassDB::bind_method(D_METHOD("challenge"),
			&DiscordAuthorizationCodeVerifier::challenge);

	ClassDB::bind_method(D_METHOD("set_challenge", "challenge"),
			&DiscordAuthorizationCodeVerifier::set_challenge);

	ClassDB::bind_method(D_METHOD("set_verifier", "verifier"),
			&DiscordAuthorizationCodeVerifier::set_verifier);

	ClassDB::bind_method(D_METHOD("verifier"),
			&DiscordAuthorizationCodeVerifier::verifier);
}
