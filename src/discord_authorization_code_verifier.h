#ifndef DISCORD_AUTHORIZATION_CODE_VERIFIER_H
#define DISCORD_AUTHORIZATION_CODE_VERIFIER_H

#include "discord_authorization_code_challenge.h"
#include "discordpp.h"
#include "godot_cpp/classes/ref_counted.hpp"

namespace godot {

class DiscordAuthorizationCodeVerifier : public RefCounted {
	GDCLASS(DiscordAuthorizationCodeVerifier, RefCounted)

	DiscordAuthorizationCodeVerifier();

private:
	discordpp::AuthorizationCodeVerifier *authorization_code_verifier;

protected:
	static void _bind_methods();

public:
	discordpp::AuthorizationCodeVerifier *unwrap(); // Internal usage.

	DiscordAuthorizationCodeChallenge *get_challenge();
	void set_challenge(DiscordAuthorizationCodeChallenge *challenge);

	String get_verifier();
	void set_verifier(String verifier);

	DiscordAuthorizationCodeVerifier(discordpp::AuthorizationCodeVerifier *authorization_code_verifier);
	~DiscordAuthorizationCodeVerifier();
};

} //namespace godot

#endif
