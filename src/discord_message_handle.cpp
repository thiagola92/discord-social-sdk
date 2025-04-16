
#include "discord_classes.h"

using namespace godot;

void DiscordppMessageHandle::Drop() {
	obj->Drop();
}

Variant DiscordppMessageHandle::AdditionalContent() {
	auto r = obj->AdditionalContent();

	if (!r.has_value()) {
		return nullptr;
	}

	discordpp::AdditionalContent *t_r = (discordpp::AdditionalContent *)memalloc(sizeof(discordpp::AdditionalContent));
	*t_r = r.value();
	return Variant(memnew(DiscordppAdditionalContent{ t_r }));
}

Variant DiscordppMessageHandle::Author() {
	auto r = obj->Author();

	if (!r.has_value()) {
		return nullptr;
	}

	discordpp::UserHandle *t_r = (discordpp::UserHandle *)memalloc(sizeof(discordpp::UserHandle));
	*t_r = r.value();
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

	discordpp::ChannelHandle *t_r = (discordpp::ChannelHandle *)memalloc(sizeof(discordpp::ChannelHandle));
	*t_r = r.value();
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

	discordpp::DisclosureTypes *t_r = (discordpp::DisclosureTypes *)memalloc(sizeof(discordpp::DisclosureTypes));
	*t_r = r.value();
	return Variant(memnew(DiscordppDisclosureTypes::Enum{ t_r }));
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

	discordpp::LobbyHandle *t_r = (discordpp::LobbyHandle *)memalloc(sizeof(discordpp::LobbyHandle));
	*t_r = r.value();
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

String DiscordppMessageHandle::RawContent() {
	return String(obj->RawContent().c_str());
}

Variant DiscordppMessageHandle::Recipient() {
	auto r = obj->Recipient();

	if (!r.has_value()) {
		return nullptr;
	}

	discordpp::UserHandle *t_r = (discordpp::UserHandle *)memalloc(sizeof(discordpp::UserHandle));
	*t_r = r.value();
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
