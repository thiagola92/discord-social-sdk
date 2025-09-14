
#include "discordpp_classes.h"

using namespace godot;

void DiscordppUserMessageSummary::Drop() {
	obj->Drop();
}

int64_t DiscordppUserMessageSummary::LastMessageId() {
	return obj->LastMessageId();
}

int64_t DiscordppUserMessageSummary::UserId() {
	return obj->UserId();
}

void DiscordppUserMessageSummary::_bind_methods() {
	ClassDB::bind_method(D_METHOD("Drop"),
			&DiscordppUserMessageSummary::Drop);

	ClassDB::bind_method(D_METHOD("LastMessageId"),
			&DiscordppUserMessageSummary::LastMessageId);

	ClassDB::bind_method(D_METHOD("UserId"),
			&DiscordppUserMessageSummary::UserId);
}
