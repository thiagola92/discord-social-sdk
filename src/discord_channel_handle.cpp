
#include "discord_classes.h"

using namespace godot;

// Functions.

DiscordChannelType::Enum DiscordChannelHandle::type() {
}

String DiscordChannelHandle::name() {
}

TypedArray<int64_t> DiscordChannelHandle::recipients() {
}

int64_t DiscordChannelHandle::id() {
}

// Overload functions.

// Binding.
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
