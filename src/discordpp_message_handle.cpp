
#include "discordpp_classes.h"

using namespace godot;

void DiscordppMessageHandle::Drop() {
	obj->Drop();
}

Variant DiscordppMessageHandle::AdditionalContent() {
	auto r = obj->AdditionalContent();

	if (!r.has_value()) {
		return nullptr;
	}

	discordpp::AdditionalContent *t_r = memnew(discordpp::AdditionalContent(std::move(r.value())));
	return Variant(memnew(DiscordppAdditionalContent{ t_r }));
}

Variant DiscordppMessageHandle::ApplicationId() {
	auto r = obj->ApplicationId();

	if (!r.has_value()) {
		return nullptr;
	}

	return Variant(r.value());
}

Variant DiscordppMessageHandle::Author() {
	auto r = obj->Author();

	if (!r.has_value()) {
		return nullptr;
	}

	discordpp::UserHandle *t_r = memnew(discordpp::UserHandle(std::move(r.value())));
	return Variant(memnew(DiscordppUserHandle{ t_r }));
}

int64_t DiscordppMessageHandle::AuthorId() {
	return obj->AuthorId();
}

Variant DiscordppMessageHandle::Channel() {
	auto r = obj->Channel();

	if (!r.has_value()) {
		return nullptr;
	}

	discordpp::ChannelHandle *t_r = memnew(discordpp::ChannelHandle(std::move(r.value())));
	return Variant(memnew(DiscordppChannelHandle{ t_r }));
}

int64_t DiscordppMessageHandle::ChannelId() {
	return obj->ChannelId();
}

String DiscordppMessageHandle::Content() {
	return String(obj->Content().c_str());
}

Variant DiscordppMessageHandle::DisclosureType() {
	auto r = obj->DisclosureType();

	if (!r.has_value()) {
		return nullptr;
	}

	return Variant((DiscordppDisclosureTypes::Enum)r.value());
}

int64_t DiscordppMessageHandle::EditedTimestamp() {
	return obj->EditedTimestamp();
}

int64_t DiscordppMessageHandle::Id() {
	return obj->Id();
}

Variant DiscordppMessageHandle::Lobby() {
	auto r = obj->Lobby();

	if (!r.has_value()) {
		return nullptr;
	}

	discordpp::LobbyHandle *t_r = memnew(discordpp::LobbyHandle(std::move(r.value())));
	return Variant(memnew(DiscordppLobbyHandle{ t_r }));
}

TypedDictionary<String, String> DiscordppMessageHandle::Metadata() {
	auto r = obj->Metadata();
	TypedDictionary<String, String> t_r = TypedDictionary<String, String>();

	for (auto p_r : r) {
		t_r[String(p_r.first.c_str())] = String(p_r.second.c_str());
	}

	return t_r;
}

TypedDictionary<String, String> DiscordppMessageHandle::ModerationMetadata() {
	auto r = obj->ModerationMetadata();
	TypedDictionary<String, String> t_r = TypedDictionary<String, String>();

	for (auto p_r : r) {
		t_r[String(p_r.first.c_str())] = String(p_r.second.c_str());
	}

	return t_r;
}

String DiscordppMessageHandle::RawContent() {
	return String(obj->RawContent().c_str());
}

Variant DiscordppMessageHandle::Recipient() {
	auto r = obj->Recipient();

	if (!r.has_value()) {
		return nullptr;
	}

	discordpp::UserHandle *t_r = memnew(discordpp::UserHandle(std::move(r.value())));
	return Variant(memnew(DiscordppUserHandle{ t_r }));
}

int64_t DiscordppMessageHandle::RecipientId() {
	return obj->RecipientId();
}

bool DiscordppMessageHandle::SentFromGame() {
	return obj->SentFromGame();
}

int64_t DiscordppMessageHandle::SentTimestamp() {
	return obj->SentTimestamp();
}

void DiscordppMessageHandle::_bind_methods() {
	ClassDB::bind_method(D_METHOD("Drop"),
			&DiscordppMessageHandle::Drop);

	ClassDB::bind_method(D_METHOD("AdditionalContent"),
			&DiscordppMessageHandle::AdditionalContent);

	ClassDB::bind_method(D_METHOD("ApplicationId"),
			&DiscordppMessageHandle::ApplicationId);

	ClassDB::bind_method(D_METHOD("Author"),
			&DiscordppMessageHandle::Author);

	ClassDB::bind_method(D_METHOD("AuthorId"),
			&DiscordppMessageHandle::AuthorId);

	ClassDB::bind_method(D_METHOD("Channel"),
			&DiscordppMessageHandle::Channel);

	ClassDB::bind_method(D_METHOD("ChannelId"),
			&DiscordppMessageHandle::ChannelId);

	ClassDB::bind_method(D_METHOD("Content"),
			&DiscordppMessageHandle::Content);

	ClassDB::bind_method(D_METHOD("DisclosureType"),
			&DiscordppMessageHandle::DisclosureType);

	ClassDB::bind_method(D_METHOD("EditedTimestamp"),
			&DiscordppMessageHandle::EditedTimestamp);

	ClassDB::bind_method(D_METHOD("Id"),
			&DiscordppMessageHandle::Id);

	ClassDB::bind_method(D_METHOD("Lobby"),
			&DiscordppMessageHandle::Lobby);

	ClassDB::bind_method(D_METHOD("Metadata"),
			&DiscordppMessageHandle::Metadata);

	ClassDB::bind_method(D_METHOD("ModerationMetadata"),
			&DiscordppMessageHandle::ModerationMetadata);

	ClassDB::bind_method(D_METHOD("RawContent"),
			&DiscordppMessageHandle::RawContent);

	ClassDB::bind_method(D_METHOD("Recipient"),
			&DiscordppMessageHandle::Recipient);

	ClassDB::bind_method(D_METHOD("RecipientId"),
			&DiscordppMessageHandle::RecipientId);

	ClassDB::bind_method(D_METHOD("SentFromGame"),
			&DiscordppMessageHandle::SentFromGame);

	ClassDB::bind_method(D_METHOD("SentTimestamp"),
			&DiscordppMessageHandle::SentTimestamp);
}
