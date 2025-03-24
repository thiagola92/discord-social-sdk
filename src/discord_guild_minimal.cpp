#include "discord_guild_minimal.h"

using namespace godot;

discordpp::GuildMinimal *DiscordGuildMinimal::unwrap() {
	return guild_minimal;
}

void DiscordGuildMinimal::_bind_methods() {
    //
}

DiscordGuildMinimal::DiscordGuildMinimal() {}

DiscordGuildMinimal::DiscordGuildMinimal(discordpp::GuildMinimal *guild_minimal) {
    this->guild_minimal = guild_minimal;
}

DiscordGuildMinimal::~DiscordGuildMinimal() {}
