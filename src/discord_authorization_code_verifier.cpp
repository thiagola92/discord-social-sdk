
#include "discord_classes.h"

using namespace godot;

// Functions.

DiscordAuthorizationCodeChallenge *DiscordAuthorizationCodeVerifier::challenge() {
	auto r0 = obj->Challenge();

	discordpp::AuthorizationCodeChallenge *r1_t = memnew(discordpp::AuthorizationCodeChallenge(std::move(r0)));
	DiscordAuthorizationCodeChallenge *r1 = memnew(DiscordAuthorizationCodeChallenge{ r1_t });

	return r1;
}

String DiscordAuthorizationCodeVerifier::verifier() {
	auto r0 = obj->Verifier();

	String r1 = String(r0.c_str());

	return r1;
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
