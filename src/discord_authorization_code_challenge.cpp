
#include "discord_classes.h"

using namespace godot;

void DiscordppAuthorizationCodeChallenge::Drop() {
	obj->Drop();
}

DiscordppAuthenticationCodeChallengeMethod::Enum DiscordppAuthorizationCodeChallenge::Method() {
	return (DiscordppAuthenticationCodeChallengeMethod::Enum)obj->Method();
}

void DiscordppAuthorizationCodeChallenge::SetMethod(DiscordppAuthenticationCodeChallengeMethod::Enum Method) {
	discordpp::AuthenticationCodeChallengeMethod p0 = (discordpp::AuthenticationCodeChallengeMethod)Method;

	obj->SetMethod(p0);
}

String DiscordppAuthorizationCodeChallenge::Challenge() {
	return String(obj->Challenge().c_str());
}

void DiscordppAuthorizationCodeChallenge::SetChallenge(String Challenge) {
	const char *p0 = Challenge.utf8().get_data();

	obj->SetChallenge(p0);
}

void DiscordppAuthorizationCodeChallenge::_bind_methods() {
	ClassDB::bind_method(D_METHOD("Drop"),
			&DiscordppAuthorizationCodeChallenge::Drop);

	ClassDB::bind_method(D_METHOD("Method"),
			&DiscordppAuthorizationCodeChallenge::Method);

	ClassDB::bind_method(D_METHOD("SetMethod", "Method"),
			&DiscordppAuthorizationCodeChallenge::SetMethod);

	ClassDB::bind_method(D_METHOD("Challenge"),
			&DiscordppAuthorizationCodeChallenge::Challenge);

	ClassDB::bind_method(D_METHOD("SetChallenge", "Challenge"),
			&DiscordppAuthorizationCodeChallenge::SetChallenge);
}
