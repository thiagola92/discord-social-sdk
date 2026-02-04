
#include "discord_classes.h"

using namespace godot;

// Functions.

String DiscordMessageHandle::content() {
	auto r0 = obj->Content();

	String r1 = String(r0.c_str());

	return r1;
}

String DiscordMessageHandle::raw_content() {
	auto r0 = obj->RawContent();

	String r1 = String(r0.c_str());

	return r1;
}

TypedDictionary<String, String> DiscordMessageHandle::metadata() {
	auto r0 = obj->Metadata();

	TypedDictionary<String, String> r1 = TypedDictionary<String, String>();

	for (auto i : r0) {
		String k = String(i.first.c_str());
		String v = String(i.second.c_str());
		r1[k] = v;
	}

	return r1;
}

TypedDictionary<String, String> DiscordMessageHandle::moderation_metadata() {
	auto r0 = obj->ModerationMetadata();

	TypedDictionary<String, String> r1 = TypedDictionary<String, String>();

	for (auto i : r0) {
		String k = String(i.first.c_str());
		String v = String(i.second.c_str());
		r1[k] = v;
	}

	return r1;
}

Variant DiscordMessageHandle::additional_content() {
	auto r0 = obj->AdditionalContent();

	Variant r1;

	if (!r0.has_value()) {
		r1 = nullptr;
	} else {
		auto r0_v = r0.value();

		discordpp::AdditionalContent *r1_v_t = memnew(discordpp::AdditionalContent(std::move(r0_v)));
		DiscordAdditionalContent *r1_v = memnew(DiscordAdditionalContent{ r1_v_t });

		r1 = Variant(r1_v);
	}

	return r1;
}

Variant DiscordMessageHandle::application_id() {
	auto r0 = obj->ApplicationId();

	Variant r1;

	if (!r0.has_value()) {
		r1 = nullptr;
	} else {
		auto r0_v = r0.value();
		int64_t r1_v = (int64_t)r0_v;
		r1 = Variant(r1_v);
	}

	return r1;
}

Variant DiscordMessageHandle::author() {
	auto r0 = obj->Author();

	Variant r1;

	if (!r0.has_value()) {
		r1 = nullptr;
	} else {
		auto r0_v = r0.value();

		discordpp::UserHandle *r1_v_t = memnew(discordpp::UserHandle(std::move(r0_v)));
		DiscordUserHandle *r1_v = memnew(DiscordUserHandle{ r1_v_t });

		r1 = Variant(r1_v);
	}

	return r1;
}

Variant DiscordMessageHandle::channel() {
	auto r0 = obj->Channel();

	Variant r1;

	if (!r0.has_value()) {
		r1 = nullptr;
	} else {
		auto r0_v = r0.value();

		discordpp::ChannelHandle *r1_v_t = memnew(discordpp::ChannelHandle(std::move(r0_v)));
		DiscordChannelHandle *r1_v = memnew(DiscordChannelHandle{ r1_v_t });

		r1 = Variant(r1_v);
	}

	return r1;
}

Variant DiscordMessageHandle::disclosure_type() {
	auto r0 = obj->DisclosureType();

	Variant r1;

	if (!r0.has_value()) {
		r1 = nullptr;
	} else {
		auto r0_v = r0.value();
		DiscordDisclosureTypes::Enum r1_v = (DiscordDisclosureTypes::Enum)r0_v;
		r1 = Variant(r1_v);
	}

	return r1;
}

Variant DiscordMessageHandle::lobby() {
	auto r0 = obj->Lobby();

	Variant r1;

	if (!r0.has_value()) {
		r1 = nullptr;
	} else {
		auto r0_v = r0.value();

		discordpp::LobbyHandle *r1_v_t = memnew(discordpp::LobbyHandle(std::move(r0_v)));
		DiscordLobbyHandle *r1_v = memnew(DiscordLobbyHandle{ r1_v_t });

		r1 = Variant(r1_v);
	}

	return r1;
}

Variant DiscordMessageHandle::recipient() {
	auto r0 = obj->Recipient();

	Variant r1;

	if (!r0.has_value()) {
		r1 = nullptr;
	} else {
		auto r0_v = r0.value();

		discordpp::UserHandle *r1_v_t = memnew(discordpp::UserHandle(std::move(r0_v)));
		DiscordUserHandle *r1_v = memnew(DiscordUserHandle{ r1_v_t });

		r1 = Variant(r1_v);
	}

	return r1;
}

bool DiscordMessageHandle::sent_from_game() {
	auto r0 = obj->SentFromGame();

	bool r1 = r0;

	return r1;
}

int64_t DiscordMessageHandle::author_id() {
	auto r0 = obj->AuthorId();

	int64_t r1 = (int64_t)r0;

	return r1;
}

int64_t DiscordMessageHandle::channel_id() {
	auto r0 = obj->ChannelId();

	int64_t r1 = (int64_t)r0;

	return r1;
}

int64_t DiscordMessageHandle::edited_timestamp() {
	auto r0 = obj->EditedTimestamp();

	int64_t r1 = (int64_t)r0;

	return r1;
}

int64_t DiscordMessageHandle::id() {
	auto r0 = obj->Id();

	int64_t r1 = (int64_t)r0;

	return r1;
}

int64_t DiscordMessageHandle::recipient_id() {
	auto r0 = obj->RecipientId();

	int64_t r1 = (int64_t)r0;

	return r1;
}

int64_t DiscordMessageHandle::sent_timestamp() {
	auto r0 = obj->SentTimestamp();

	int64_t r1 = (int64_t)r0;

	return r1;
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
