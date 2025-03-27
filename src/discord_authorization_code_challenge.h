#ifndef DISCORD_AUTHORIZATION_CODE_CHALLENGE_H
#define DISCORD_AUTHORIZATION_CODE_CHALLENGE_H

#include "discord_enum.h"
#include "discordpp.h"
#include "godot_cpp/classes/ref_counted.hpp"

namespace godot {

class DiscordAuthorizationCodeChallenge : public RefCounted {
	GDCLASS(DiscordAuthorizationCodeChallenge, RefCounted)

private:
	discordpp::AuthorizationCodeChallenge authorization_code_challenge;

protected:
	static void _bind_methods();

public:
	discordpp::AuthorizationCodeChallenge *unwrap(); // Internal usage.

	DiscordAuthenticationCodeChallengeMethod::Enum get_method();
	void set_method(DiscordAuthenticationCodeChallengeMethod::Enum method);
	String get_challenge();
	void set_challenge(String challenge);

	DiscordAuthorizationCodeChallenge();
	DiscordAuthorizationCodeChallenge(discordpp::AuthorizationCodeChallenge authorization_code_challenge);
	~DiscordAuthorizationCodeChallenge();
};

} // namespace godot

#endif
