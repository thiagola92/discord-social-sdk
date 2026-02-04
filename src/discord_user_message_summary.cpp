
#include "discord_classes.h"

using namespace godot;

// Functions.

int64_t DiscordUserMessageSummary::last_message_id() {
	auto r0 = obj->LastMessageId();

	int64_t r1 = (int64_t)r0;

	return r1;
}

int64_t DiscordUserMessageSummary::user_id() {
	auto r0 = obj->UserId();

	int64_t r1 = (int64_t)r0;

	return r1;
}

// Overload functions.

// Binding.
void DiscordUserMessageSummary::_bind_methods() {
	ClassDB::bind_method(D_METHOD("last_message_id"),
			&DiscordUserMessageSummary::last_message_id);

	ClassDB::bind_method(D_METHOD("user_id"),
			&DiscordUserMessageSummary::user_id);
}
