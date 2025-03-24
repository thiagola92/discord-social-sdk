#include "discord_call_info_handle.h"

using namespace godot;

discordpp::CallInfoHandle *DiscordCallInfoHandle::unwrap() {
	return call_info_handle;
}

void DiscordCallInfoHandle::_bind_methods() {
    //
}

DiscordCallInfoHandle::DiscordCallInfoHandle() {}

DiscordCallInfoHandle::DiscordCallInfoHandle(discordpp::CallInfoHandle *call_info_handle) {
    this->call_info_handle = call_info_handle;
}

DiscordCallInfoHandle::~DiscordCallInfoHandle() {}
