#include "discord_additional_content.h"

using namespace godot;

discordpp::AdditionalContent *DiscordAdditionalContent::unwrap() {
	return &additional_content;
}

void DiscordAdditionalContent::_bind_methods() {
    //
}

DiscordAdditionalContent::DiscordAdditionalContent() {}

DiscordAdditionalContent::~DiscordAdditionalContent() {}
