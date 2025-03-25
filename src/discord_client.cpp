#include "discord_client.h"
#include "discordpp.h"
#include "godot_cpp/core/memory.hpp"
#include "godot_cpp/core/print_string.hpp"

using namespace godot;

discordpp::Client *DiscordClient::unwrap() {
	return &client;
}

void DiscordClient::_process(float delta) {
	discordpp::RunCallbacks();
}

void DiscordClient::authorize(DiscordAuthorizationArgs *args) {
	client.Authorize(
			*args->unwrap(), [this](discordpp::ClientResult result, std::string code, std::string redirect_uri) {
				if (result.Successful()) {
					this->emit_signal("authorized");
				} else {
					this->emit_signal("rejected");
				}
			});
}

DiscordAuthorizationCodeVerifier *DiscordClient::create_authorization_code_verifier() {
	auto cv = (discordpp::AuthorizationCodeVerifier *)memalloc(sizeof(discordpp::AuthorizationCodeVerifier));
	*cv = client.CreateAuthorizationCodeVerifier();
	return memnew(DiscordAuthorizationCodeVerifier(cv));
}

void DiscordClient::_bind_methods() {
	ADD_SIGNAL(MethodInfo("authorized"));
	ADD_SIGNAL(MethodInfo("rejected"));

	ClassDB::bind_method(D_METHOD("authorize", "args"),
			&DiscordClient::authorize);

	ClassDB::bind_method(D_METHOD("create_authorization_code_verifier"),
			&DiscordClient::create_authorization_code_verifier);
}

DiscordClient::DiscordClient() {}

DiscordClient::~DiscordClient() {}