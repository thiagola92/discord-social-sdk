#include "discord_client.h"

using namespace godot;

discordpp::Client *DiscordClient::unwrap() {
	return &client;
}

void DiscordClient::authorize(DiscordAuthorizationArgs *args) {
	auto code_verifier = client.CreateAuthorizationCodeVerifier();

	// client.Authorize(
	// 		args.args, [this, code_verifier](auto result, auto code, auto redirect_uri) {
	// 			if (result.Successful()) {
	// 				emit_signal("authorized");
	// 			} else {
	// 				emit_signal("rejected");
	// 			}
	// 		});
}

void DiscordClient::_bind_methods() {
	ADD_SIGNAL(MethodInfo("authorized"));
	ADD_SIGNAL(MethodInfo("rejected"));

	ClassDB::bind_method(D_METHOD("authorize", "args"),
			&DiscordClient::authorize);
}

DiscordClient::DiscordClient() {}

DiscordClient::~DiscordClient() {}