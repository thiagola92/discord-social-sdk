// AUTO-GENERATED
#include "discord_message_handle.h"

using namespace godot;

discordpp::MessageHandle *DiscordMessageHandle::unwrap() {
	return message_handle;
}

Variant DiscordMessageHandle::additional_content() {
	auto r = message_handle->AdditionalContent();

	if (!r.has_value()) {
		return nullptr;
	}

	auto t_r = (discordpp::AdditionalContent *)memalloc(sizeof(discordpp::AdditionalContent));
	*t_r = r.value();
	return Variant(memnew(DiscordAdditionalContent{ t_r }));
}

Variant DiscordMessageHandle::author() {
	auto r = message_handle->Author();

	if (!r.has_value()) {
		return nullptr;
	}

	auto t_r = (discordpp::UserHandle *)memalloc(sizeof(discordpp::UserHandle));
	*t_r = r.value();
	return Variant(memnew(DiscordUserHandle{ t_r }));
}

uint64_t DiscordMessageHandle::author_id() {
	auto r = message_handle->AuthorId();
	return r;
}

Variant DiscordMessageHandle::channel() {
	auto r = message_handle->Channel();

	if (!r.has_value()) {
		return nullptr;
	}

	auto t_r = (discordpp::ChannelHandle *)memalloc(sizeof(discordpp::ChannelHandle));
	*t_r = r.value();
	return Variant(memnew(DiscordChannelHandle{ t_r }));
}

uint64_t DiscordMessageHandle::channel_id() {
	auto r = message_handle->ChannelId();
	return r;
}

String DiscordMessageHandle::content() {
	auto r = message_handle->Content();
	return String(r.c_str());
}

Variant DiscordMessageHandle::disclosure_type() {
	auto r = message_handle->DisclosureType();

	if (!r.has_value()) {
		return nullptr;
	}

	return Variant((Discord<parser.VarType object at 0x7edc91b0f290>::Enum)r.value());
}

uint64_t DiscordMessageHandle::edited_timestamp() {
	auto r = message_handle->EditedTimestamp();
	return r;
}

uint64_t DiscordMessageHandle::id() {
	auto r = message_handle->Id();
	return r;
}

Variant DiscordMessageHandle::lobby() {
	auto r = message_handle->Lobby();

	if (!r.has_value()) {
		return nullptr;
	}

	auto t_r = (discordpp::LobbyHandle *)memalloc(sizeof(discordpp::LobbyHandle));
	*t_r = r.value();
	return Variant(memnew(DiscordLobbyHandle{ t_r }));
}

TypedDictionary<String, String> DiscordMessageHandle::metadata() {
	auto r = message_handle->Metadata();
	auto t_r = TypedDictionary<String, String>();

	for (auto p_r : r) {
		t_r[String(p_r.first.c_str())] = String(p_r.second.c_str());
	}

	return t_r;
}

String DiscordMessageHandle::raw_content() {
	auto r = message_handle->RawContent();
	return String(r.c_str());
}

Variant DiscordMessageHandle::recipient() {
	auto r = message_handle->Recipient();

	if (!r.has_value()) {
		return nullptr;
	}

	auto t_r = (discordpp::UserHandle *)memalloc(sizeof(discordpp::UserHandle));
	*t_r = r.value();
	return Variant(memnew(DiscordUserHandle{ t_r }));
}

uint64_t DiscordMessageHandle::recipient_id() {
	auto r = message_handle->RecipientId();
	return r;
}

bool DiscordMessageHandle::sent_from_game() {
	auto r = message_handle->SentFromGame();
	return r;
}

uint64_t DiscordMessageHandle::sent_timestamp() {
	auto r = message_handle->SentTimestamp();
	return r;
}

void DiscordMessageHandle::_bind_methods() {
	ClassDB::bind_method(D_METHOD("additional_content"),
			&DiscordMessageHandle::additional_content);

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

DiscordMessageHandle::DiscordMessageHandle() {}

DiscordMessageHandle::DiscordMessageHandle(discordpp::MessageHandle *message_handle) {
	this->message_handle = message_handle;
}

DiscordMessageHandle::~DiscordMessageHandle() {}
