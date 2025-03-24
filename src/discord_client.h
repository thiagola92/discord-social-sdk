#ifndef DISCORD_CLIENT_H
#define DISCORD_CLIENT_H

#include "discord_authorization_args.h"
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

	// Auth
	void authorize(DiscordAuthorizationArgs *args);
	// DiscordAuthorizationCodeVerifier CreateAuthorizationCodeVerifier();

	DiscordClient();
	~DiscordClient();
};

} // namespace godot

#endif
