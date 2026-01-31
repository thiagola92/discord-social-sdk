
#include "discord_classes.h"

using namespace godot;

// Functions.

String DiscordMessageHandle::content() {
}

String DiscordMessageHandle::raw_content() {
}

TypedDictionary<String, String> DiscordMessageHandle::metadata() {
}

TypedDictionary<String, String> DiscordMessageHandle::moderation_metadata() {
}

Variant DiscordMessageHandle::additional_content() {
}

Variant DiscordMessageHandle::application_id() {
}

Variant DiscordMessageHandle::author() {
}

Variant DiscordMessageHandle::channel() {
}

Variant DiscordMessageHandle::disclosure_type() {
}

Variant DiscordMessageHandle::lobby() {
}

Variant DiscordMessageHandle::recipient() {
}

bool DiscordMessageHandle::sent_from_game() {
}

int64_t DiscordMessageHandle::author_id() {
}

int64_t DiscordMessageHandle::channel_id() {
}

int64_t DiscordMessageHandle::edited_timestamp() {
}

int64_t DiscordMessageHandle::id() {
}

int64_t DiscordMessageHandle::recipient_id() {
}

int64_t DiscordMessageHandle::sent_timestamp() {
}

// Overload functions.

// Binding.
void DiscordMessageHandle::_bind_methods() {
	ClassDB::bind_method(D_METHOD("additional_content"),
			&DiscordMessageHandle::additional_content);

	ClassDB::bind_method(D_METHOD("application_id"),
			&DiscordMessageHandle::application_id);

	ClassDB::bind_method(D_METHOD("author"),
			&DiscordMessageHandle::author);

	ClassDB::bind_method(D_METHOD("author_id"),
			&DiscordMessageHandle::author_id);

	ClassDB::bind_method(D_METHOD("channel"),
			&DiscordMessageHandle::channel);

	ClassDB::bind_method(D_METHOD("channel_id"),
			&DiscordMessageHandle::channel_id);

	ClassDB::bind_method(D_METHOD("content"),
			&DiscordMessageHandle::content);

	ClassDB::bind_method(D_METHOD("disclosure_type"),
			&DiscordMessageHandle::disclosure_type);

	ClassDB::bind_method(D_METHOD("edited_timestamp"),
			&DiscordMessageHandle::edited_timestamp);

	ClassDB::bind_method(D_METHOD("id"),
			&DiscordMessageHandle::id);

	ClassDB::bind_method(D_METHOD("lobby"),
			&DiscordMessageHandle::lobby);

	ClassDB::bind_method(D_METHOD("metadata"),
			&DiscordMessageHandle::metadata);

	ClassDB::bind_method(D_METHOD("moderation_metadata"),
			&DiscordMessageHandle::moderation_metadata);

	ClassDB::bind_method(D_METHOD("raw_content"),
			&DiscordMessageHandle::raw_content);

	ClassDB::bind_method(D_METHOD("recipient"),
			&DiscordMessageHandle::recipient);

	ClassDB::bind_method(D_METHOD("recipient_id"),
			&DiscordMessageHandle::recipient_id);

	ClassDB::bind_method(D_METHOD("sent_from_game"),
			&DiscordMessageHandle::sent_from_game);

	ClassDB::bind_method(D_METHOD("sent_timestamp"),
			&DiscordMessageHandle::sent_timestamp);
}
