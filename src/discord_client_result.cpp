#include "discord_client_result.h"

using namespace godot;

discordpp::ClientResult *DiscordClientResult::unwrap() {
	return client_result;
}

void DiscordClientResult::_bind_methods() {
    //
}

DiscordClientResult::DiscordClientResult() {}

DiscordClientResult::DiscordClientResult(discordpp::ClientResult *client_result) {
    this->client_result = client_result;
}

DiscordClientResult::~DiscordClientResult() {}
