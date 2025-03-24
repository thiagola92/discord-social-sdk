#include "discord_call.h"

using namespace godot;

discordpp::Call *DiscordCall::unwrap() {
	return call;
}

void DiscordCall::_bind_methods() {
    //
}

DiscordCall::DiscordCall() {}

DiscordCall::DiscordCall(discordpp::Call *call) {
    this->call = call;
}

DiscordCall::~DiscordCall() {}
