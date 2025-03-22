// https://discord.com/developers/docs/social-sdk/classdiscordpp_1_1Client.html
#ifndef DISCORD_CLIENT_H
#define DISCORD_CLIENT_H

#include "discord_authorization_args.h"

#include <discordpp.h>
#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/classes/wrapped.hpp>

namespace godot {

class DiscordClient : public Node {
	GDCLASS(DiscordClient, Node)

private:
	discordpp::Client client;

protected:
	static void _bind_methods();

public:
	discordpp::Client *unwrap(); // Internal usage.

	DiscordClient();
	~DiscordClient();

	void authorize(DiscordAuthorizationArgs *args);
};

} // namespace godot

#endif
