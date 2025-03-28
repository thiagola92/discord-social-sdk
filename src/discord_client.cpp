#include "discord_client.h"
#include "discord_client_result.h"
#include "discordpp.h"
#include "godot_cpp/classes/global_constants.hpp"
#include "godot_cpp/core/memory.hpp"

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
				auto r = memnew(DiscordClientResult{ &result });
				this->emit_signal("authorization_callback", r, String(code.c_str()), String(redirect_uri.c_str()));
			});
}

DiscordAuthorizationCodeVerifier *DiscordClient::create_authorization_code_verifier() {
	auto cv = (discordpp::AuthorizationCodeVerifier *)memalloc(sizeof(discordpp::AuthorizationCodeVerifier));
	*cv = client.CreateAuthorizationCodeVerifier();
	return memnew(DiscordAuthorizationCodeVerifier{ cv });
}

void DiscordClient::_bind_methods() {
	ADD_SIGNAL(MethodInfo("authorization_callback", PropertyInfo(Variant::OBJECT, "result", PROPERTY_HINT_RESOURCE_TYPE, "DiscordClientResult"), PropertyInfo(Variant::STRING, "code"), PropertyInfo(Variant::STRING, "redirect_uri")));

	ClassDB::bind_method(D_METHOD("authorize", "args"),
			&DiscordClient::authorize);

	ClassDB::bind_method(D_METHOD("create_authorization_code_verifier"),
			&DiscordClient::create_authorization_code_verifier);
}

DiscordClient::DiscordClient() {}

DiscordClient::~DiscordClient() {}