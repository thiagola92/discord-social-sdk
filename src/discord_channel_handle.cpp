// AUTO-GENERATED
#include "discord_channel_handle.h"

using namespace godot;

discordpp::ChannelHandle *DiscordChannelHandle::unwrap() {
	return channel_handle;
}

uint64_t DiscordChannelHandle::id() {
	auto r = channel_handle->Id();
	return r;
}

String DiscordChannelHandle::name() {
	auto r = channel_handle->Name();
	return String(r.c_str());
}

TypedArray<uint64_t> DiscordChannelHandle::recipients() {
	auto r = channel_handle->Recipients();
	auto t_r = TypedArray<uint64_t>();

	for (auto i_r : r) {
		t_r.push_back(i_r);
	}

	return t_r;
}

DiscordChannelType::Enum DiscordChannelHandle::type() {
	auto r = channel_handle->Type();
	return (DiscordChannelType::Enum)r;
}

void DiscordChannelHandle::_bind_methods() {
	ClassDB::bind_method(D_METHOD("id"),
			&DiscordChannelHandle::id);

	ClassDB::bind_method(D_METHOD("name"),
			&DiscordChannelHandle::name);

	ClassDB::bind_method(D_METHOD("recipients"),
			&DiscordChannelHandle::recipients);

	ClassDB::bind_method(D_METHOD("type"),
			&DiscordChannelHandle::type);
}

DiscordChannelHandle::DiscordChannelHandle() {}

DiscordChannelHandle::DiscordChannelHandle(discordpp::ChannelHandle *channel_handle) {
	this->channel_handle = channel_handle;
}

DiscordChannelHandle::~DiscordChannelHandle() {}
