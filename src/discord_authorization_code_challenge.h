#ifndef DISCORD_AUTHORIZATION_CODE_CHALLENGE_H
#define DISCORD_AUTHORIZATION_CODE_CHALLENGE_H

#include <discordpp.h>
#include <godot_cpp/classes/ref_counted.hpp>
#include <godot_cpp/classes/wrapped.hpp>

namespace godot {

class DiscordAuthorizationCodeChallenge : public RefCounted {
	GDCLASS(DiscordAuthorizationCodeChallenge, RefCounted)

private:
	discordpp::AuthorizationCodeChallenge code_challenge;

protected:
	static void _bind_methods();

public:
	// AuthenticationCodeChallengeMethod get_method();
	// void set_method(AuthenticationCodeChallengeMethod method);

	String get_challenge();
	void set_challenge(String challenge);

	DiscordAuthorizationCodeChallenge();
	// DiscordAuthorizationCodeChallenge(discordpp::AuthorizationCodeChallenge);
	~DiscordAuthorizationCodeChallenge();
};

} // namespace godot

#endif
