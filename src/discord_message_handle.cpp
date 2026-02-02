
#include "discord_classes.h"

using namespace godot;

// Functions.

String DiscordMessageHandle::content() {
	auto r = obj->Content();
}

String DiscordMessageHandle::raw_content() {
	auto r = obj->RawContent();
}

TypedDictionary<String, String> DiscordMessageHandle::metadata() {
	auto r = obj->Metadata();
}

TypedDictionary<String, String> DiscordMessageHandle::moderation_metadata() {
	auto r = obj->ModerationMetadata();
}

Variant DiscordMessageHandle::additional_content() {
	auto r = obj->AdditionalContent();
}

Variant DiscordMessageHandle::application_id() {
	auto r = obj->ApplicationId();
}

Variant DiscordMessageHandle::author() {
	auto r = obj->Author();
}

Variant DiscordMessageHandle::channel() {
	auto r = obj->Channel();
}

Variant DiscordMessageHandle::disclosure_type() {
	auto r = obj->DisclosureType();
}

Variant DiscordMessageHandle::lobby() {
	auto r = obj->Lobby();
}

Variant DiscordMessageHandle::recipient() {
	auto r = obj->Recipient();
}

bool DiscordMessageHandle::sent_from_game() {
	auto r = obj->SentFromGame();
}

int64_t DiscordMessageHandle::author_id() {
	auto r = obj->AuthorId();
}

int64_t DiscordMessageHandle::channel_id() {
	auto r = obj->ChannelId();
}

int64_t DiscordMessageHandle::edited_timestamp() {
	auto r = obj->EditedTimestamp();
}

int64_t DiscordMessageHandle::id() {
	auto r = obj->Id();
}

int64_t DiscordMessageHandle::recipient_id() {
	auto r = obj->RecipientId();
}

int64_t DiscordMessageHandle::sent_timestamp() {
	auto r = obj->SentTimestamp();
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
