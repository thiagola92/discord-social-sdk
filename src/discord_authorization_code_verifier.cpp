
#include "discord_classes.h"

using namespace godot;

// Functions.

DiscordAuthorizationCodeChallenge *DiscordAuthorizationCodeVerifier::challenge() {
	auto r = obj->Challenge();
}

String DiscordAuthorizationCodeVerifier::verifier() {
	auto r = obj->Verifier();
}

void DiscordAuthorizationCodeVerifier::set_challenge(DiscordAuthorizationCodeChallenge *challenge) {
	discordpp::AuthorizationCodeChallenge p0 = *challenge->unwrap();
	obj->SetChallenge(p0);
}

void DiscordAuthorizationCodeVerifier::set_verifier(String verifier) {
	std::string p0 = std::string(verifier.utf8().get_data());
	obj->SetVerifier(p0);
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
