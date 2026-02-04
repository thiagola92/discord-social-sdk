
#include "discord_classes.h"

using namespace godot;

// Functions.

String DiscordMessageHandle::content() {
	auto r = obj->Content();

	String cr = String(r.c_str());
	return cr;
}

String DiscordMessageHandle::raw_content() {
	auto r = obj->RawContent();

	String cr = String(r.c_str());
	return cr;
}

TypedDictionary<String, String> DiscordMessageHandle::metadata() {
	auto r = obj->Metadata();

	TypedDictionary<String, String> cr = TypedDictionary<String, String>();

	for (auto i : r) {
		String k = String(i.first.c_str());
		String v = String(i.second.c_str());
		cr[k] = v;
	}

	return cr;
}

TypedDictionary<String, String> DiscordMessageHandle::moderation_metadata() {
	auto r = obj->ModerationMetadata();

	TypedDictionary<String, String> cr = TypedDictionary<String, String>();

	for (auto i : r) {
		String k = String(i.first.c_str());
		String v = String(i.second.c_str());
		cr[k] = v;
	}

	return cr;
}

Variant DiscordMessageHandle::additional_content() {
	auto r = obj->AdditionalContent();

	Variant cr;

	if (!r.has_value()) {
		cr = nullptr;
	} else {
		auto r_v = r.value();

		discordpp::AdditionalContent *cr_v_t = memnew(discordpp::AdditionalContent(std::move(r_v)));
		DiscordAdditionalContent *cr_v = memnew(DiscordAdditionalContent{ cr_v_t });

		cr = Variant(cr_v);
	}

	return cr;
}

Variant DiscordMessageHandle::application_id() {
	auto r = obj->ApplicationId();

	Variant cr;

	if (!r.has_value()) {
		cr = nullptr;
	} else {
		auto r_v = r.value();
		int64_t cr_v = (int64_t)r_v;
		cr = Variant(cr_v);
	}

	return cr;
}

Variant DiscordMessageHandle::author() {
	auto r = obj->Author();

	Variant cr;

	if (!r.has_value()) {
		cr = nullptr;
	} else {
		auto r_v = r.value();

		discordpp::UserHandle *cr_v_t = memnew(discordpp::UserHandle(std::move(r_v)));
		DiscordUserHandle *cr_v = memnew(DiscordUserHandle{ cr_v_t });

		cr = Variant(cr_v);
	}

	return cr;
}

Variant DiscordMessageHandle::channel() {
	auto r = obj->Channel();

	Variant cr;

	if (!r.has_value()) {
		cr = nullptr;
	} else {
		auto r_v = r.value();

		discordpp::ChannelHandle *cr_v_t = memnew(discordpp::ChannelHandle(std::move(r_v)));
		DiscordChannelHandle *cr_v = memnew(DiscordChannelHandle{ cr_v_t });

		cr = Variant(cr_v);
	}

	return cr;
}

Variant DiscordMessageHandle::disclosure_type() {
	auto r = obj->DisclosureType();

	Variant cr;

	if (!r.has_value()) {
		cr = nullptr;
	} else {
		auto r_v = r.value();

		discordpp::DisclosureTypes *cr_v_t = memnew(discordpp::DisclosureTypes(std::move(r_v)));
		DiscordDisclosureTypes *cr_v = memnew(DiscordDisclosureTypes{ cr_v_t });

		cr = Variant(cr_v);
	}

	return cr;
}

Variant DiscordMessageHandle::lobby() {
	auto r = obj->Lobby();

	Variant cr;

	if (!r.has_value()) {
		cr = nullptr;
	} else {
		auto r_v = r.value();

		discordpp::LobbyHandle *cr_v_t = memnew(discordpp::LobbyHandle(std::move(r_v)));
		DiscordLobbyHandle *cr_v = memnew(DiscordLobbyHandle{ cr_v_t });

		cr = Variant(cr_v);
	}

	return cr;
}

Variant DiscordMessageHandle::recipient() {
	auto r = obj->Recipient();

	Variant cr;

	if (!r.has_value()) {
		cr = nullptr;
	} else {
		auto r_v = r.value();

		discordpp::UserHandle *cr_v_t = memnew(discordpp::UserHandle(std::move(r_v)));
		DiscordUserHandle *cr_v = memnew(DiscordUserHandle{ cr_v_t });

		cr = Variant(cr_v);
	}

	return cr;
}

bool DiscordMessageHandle::sent_from_game() {
	auto r = obj->SentFromGame();

	bool cr = r;
	return cr;
}

int64_t DiscordMessageHandle::author_id() {
	auto r = obj->AuthorId();

	int64_t cr = (int64_t)r;
	return cr;
}

int64_t DiscordMessageHandle::channel_id() {
	auto r = obj->ChannelId();

	int64_t cr = (int64_t)r;
	return cr;
}

int64_t DiscordMessageHandle::edited_timestamp() {
	auto r = obj->EditedTimestamp();

	int64_t cr = (int64_t)r;
	return cr;
}

int64_t DiscordMessageHandle::id() {
	auto r = obj->Id();

	int64_t cr = (int64_t)r;
	return cr;
}

int64_t DiscordMessageHandle::recipient_id() {
	auto r = obj->RecipientId();

	int64_t cr = (int64_t)r;
	return cr;
}

int64_t DiscordMessageHandle::sent_timestamp() {
	auto r = obj->SentTimestamp();

	int64_t cr = (int64_t)r;
	return cr;
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
