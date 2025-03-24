#include "discord_guild_channel.h"

using namespace godot;

discordpp::GuildChannel *DiscordGuildChannel::unwrap() {
	return guild_channel;
}

void DiscordGuildChannel::_bind_methods() {
	//
}

// DiscordGuildChannel::DiscordGuildChannel() {}

DiscordGuildChannel::~DiscordGuildChannel() {}
