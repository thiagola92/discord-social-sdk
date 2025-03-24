#ifndef DISCORD_AUTHORIZATION_CODE_VERIFIER_H
#define DISCORD_AUTHORIZATION_CODE_VERIFIER_H

#include "discordpp.h"
#include "godot_cpp/classes/ref_counted.hpp"

namespace godot {

class DiscordAuthorizationCodeVerifier : public RefCounted {
	GDCLASS(DiscordAuthorizationCodeVerifier, RefCounted)

private:
	discordpp::AuthorizationCodeVerifier code_verifier;

protected:
	static void _bind_methods();

public:
	discordpp::AuthorizationCodeVerifier *unwrap(); // Internal usage.

	DiscordAuthorizationCodeVerifier();
	~DiscordAuthorizationCodeVerifier();
};

} //namespace godot

#endif