#ifndef DISCORD_CLIENT_H
#define DISCORD_CLIENT_H

#include "discord_authorization_args.h"
#include "discord_authorization_code_verifier.h"
#include "godot_cpp/classes/node.hpp"

namespace godot {

class DiscordClient : public Node {
	GDCLASS(DiscordClient, Node)

private:
	discordpp::Client client;

protected:
	static void _bind_methods();

public:
	discordpp::Client *unwrap(); // Internal usage.

	// Godot Methods
	void _process(float delta);

	// Auth
	void authorize(DiscordAuthorizationArgs *args);
	DiscordAuthorizationCodeVerifier *create_authorization_code_verifier();

	// Core
	void add_log_callback(DiscordLoggingSeverity::Enum min_severity);

	DiscordClient();
	~DiscordClient();
};

} // namespace godot

#endif
