
#include "discordpp_classes.h"

using namespace godot;

void DiscordppAuthorizationCodeVerifier::Drop() {
	obj->Drop();
}

DiscordppAuthorizationCodeChallenge *DiscordppAuthorizationCodeVerifier::Challenge() {
	discordpp::AuthorizationCodeChallenge r = obj->Challenge();
	discordpp::AuthorizationCodeChallenge *t_r = memnew(discordpp::AuthorizationCodeChallenge(std::move(r)));
	return memnew(DiscordppAuthorizationCodeChallenge{ t_r });
}

void DiscordppAuthorizationCodeVerifier::SetChallenge(DiscordppAuthorizationCodeChallenge *Challenge) {
	discordpp::AuthorizationCodeChallenge p0 = *Challenge->unwrap();

	obj->SetChallenge(p0);
}

String DiscordppAuthorizationCodeVerifier::Verifier() {
	return String(obj->Verifier().c_str());
}

void DiscordppAuthorizationCodeVerifier::SetVerifier(String Verifier) {
	std::string p0 = std::string(Verifier.utf8().get_data());

	obj->SetVerifier(p0);
}

void DiscordppAuthorizationCodeVerifier::_bind_methods() {
	ClassDB::bind_method(D_METHOD("Drop"),
			&DiscordppAuthorizationCodeVerifier::Drop);

	ClassDB::bind_method(D_METHOD("Challenge"),
			&DiscordppAuthorizationCodeVerifier::Challenge);

	ClassDB::bind_method(D_METHOD("SetChallenge", "Challenge"),
			&DiscordppAuthorizationCodeVerifier::SetChallenge);

	ClassDB::bind_method(D_METHOD("Verifier"),
			&DiscordppAuthorizationCodeVerifier::Verifier);

	ClassDB::bind_method(D_METHOD("SetVerifier", "Verifier"),
			&DiscordppAuthorizationCodeVerifier::SetVerifier);
}
