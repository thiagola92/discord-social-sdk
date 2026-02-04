
#include "discord_classes.h"

using namespace godot;

// Functions.

DiscordAuthenticationCodeChallengeMethod::Enum DiscordAuthorizationCodeChallenge::method() {
	auto r0 = obj->Method();

	DiscordAuthenticationCodeChallengeMethod::Enum r1 = (DiscordAuthenticationCodeChallengeMethod::Enum)r0;

	return r1;
}

String DiscordAuthorizationCodeChallenge::challenge() {
	auto r0 = obj->Challenge();

	String r1 = String(r0.c_str());

	return r1;
}

void DiscordAuthorizationCodeChallenge::set_challenge(String challenge) {
	std::string p0 = std::string(challenge.utf8().get_data());
	obj->SetChallenge(p0);
}

void DiscordAuthorizationCodeChallenge::set_method(DiscordAuthenticationCodeChallengeMethod::Enum method) {
	discordpp::AuthenticationCodeChallengeMethod p0 = (discordpp::AuthenticationCodeChallengeMethod)method;
	obj->SetMethod(p0);
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
