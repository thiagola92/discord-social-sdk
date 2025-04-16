
#include "discord_classes.h"

using namespace godot;

void DiscordppActivity::Drop() {
	obj->Drop();
}

bool DiscordppActivity::Equals(DiscordppActivity *other) {
	discordpp::Activity p0 = *other->unwrap();

	return obj->Equals(p0);
}

String DiscordppActivity::Name() {
	return String(obj->Name().c_str());
}

void DiscordppActivity::SetName(String Name) {
	const char *p0 = Name.utf8().get_data();

	obj->SetName(p0);
}

DiscordppActivityTypes::Enum DiscordppActivity::Type() {
	return (DiscordppActivityTypes::Enum)obj->Type();
}

void DiscordppActivity::SetType(DiscordppActivityTypes::Enum Type) {
	discordpp::ActivityTypes p0 = (discordpp::ActivityTypes)Type;

	obj->SetType(p0);
}

Variant DiscordppActivity::State() {
	auto r = obj->State();

	if (!r.has_value()) {
		return nullptr;
	}

	return Variant(r.value().c_str());
}

void DiscordppActivity::SetState(Variant State) {
	std::optional<std::string> p0;

	if (State.get_type() == Variant::STRING) {
		p0 = State.stringify().utf8().get_data();
	}

	obj->SetState(p0);
}

Variant DiscordppActivity::Details() {
	auto r = obj->Details();

	if (!r.has_value()) {
		return nullptr;
	}

	return Variant(r.value().c_str());
}

void DiscordppActivity::SetDetails(Variant Details) {
	std::optional<std::string> p0;

	if (Details.get_type() == Variant::STRING) {
		p0 = Details.stringify().utf8().get_data();
	}

	obj->SetDetails(p0);
}

Variant DiscordppActivity::ApplicationId() {
	auto r = obj->ApplicationId();

	if (!r.has_value()) {
		return nullptr;
	}

	return Variant(r.value());
}

void DiscordppActivity::SetApplicationId(Variant ApplicationId) {
	std::optional<uint64_t> p0;

	if (ApplicationId.get_type() == Variant::INT) {
		p0 = ApplicationId;
	}

	obj->SetApplicationId(p0);
}

Variant DiscordppActivity::Assets() {
	auto r = obj->Assets();

	if (!r.has_value()) {
		return nullptr;
	}

	discordpp::ActivityAssets *t_r = (discordpp::ActivityAssets *)memalloc(sizeof(discordpp::ActivityAssets));
	*t_r = r.value();
	return Variant(memnew(DiscordppActivityAssets{ t_r }));
}

void DiscordppActivity::SetAssets(Variant Assets) {
	std::optional<discordpp::ActivityAssets> p0;

	if (Assets.get_type() == Variant::OBJECT) {
		DiscordppActivityAssets *t_p0 = Object::cast_to<DiscordppActivityAssets>(Assets);
		p0 = std::optional<discordpp::ActivityAssets>{ *t_p0->unwrap() };
	}

	obj->SetAssets(p0);
}

Variant DiscordppActivity::Timestamps() {
	auto r = obj->Timestamps();

	if (!r.has_value()) {
		return nullptr;
	}

	discordpp::ActivityTimestamps *t_r = (discordpp::ActivityTimestamps *)memalloc(sizeof(discordpp::ActivityTimestamps));
	*t_r = r.value();
	return Variant(memnew(DiscordppActivityTimestamps{ t_r }));
}

void DiscordppActivity::SetTimestamps(Variant Timestamps) {
	std::optional<discordpp::ActivityTimestamps> p0;

	if (Timestamps.get_type() == Variant::OBJECT) {
		DiscordppActivityTimestamps *t_p0 = Object::cast_to<DiscordppActivityTimestamps>(Timestamps);
		p0 = std::optional<discordpp::ActivityTimestamps>{ *t_p0->unwrap() };
	}

	obj->SetTimestamps(p0);
}

Variant DiscordppActivity::Party() {
	auto r = obj->Party();

	if (!r.has_value()) {
		return nullptr;
	}

	discordpp::ActivityParty *t_r = (discordpp::ActivityParty *)memalloc(sizeof(discordpp::ActivityParty));
	*t_r = r.value();
	return Variant(memnew(DiscordppActivityParty{ t_r }));
}

void DiscordppActivity::SetParty(Variant Party) {
	std::optional<discordpp::ActivityParty> p0;

	if (Party.get_type() == Variant::OBJECT) {
		DiscordppActivityParty *t_p0 = Object::cast_to<DiscordppActivityParty>(Party);
		p0 = std::optional<discordpp::ActivityParty>{ *t_p0->unwrap() };
	}

	obj->SetParty(p0);
}

Variant DiscordppActivity::Secrets() {
	auto r = obj->Secrets();

	if (!r.has_value()) {
		return nullptr;
	}

	discordpp::ActivitySecrets *t_r = (discordpp::ActivitySecrets *)memalloc(sizeof(discordpp::ActivitySecrets));
	*t_r = r.value();
	return Variant(memnew(DiscordppActivitySecrets{ t_r }));
}

void DiscordppActivity::SetSecrets(Variant Secrets) {
	std::optional<discordpp::ActivitySecrets> p0;

	if (Secrets.get_type() == Variant::OBJECT) {
		DiscordppActivitySecrets *t_p0 = Object::cast_to<DiscordppActivitySecrets>(Secrets);
		p0 = std::optional<discordpp::ActivitySecrets>{ *t_p0->unwrap() };
	}

	obj->SetSecrets(p0);
}

DiscordppActivityGamePlatforms::Enum DiscordppActivity::SupportedPlatforms() {
	return (DiscordppActivityGamePlatforms::Enum)obj->SupportedPlatforms();
}

void DiscordppActivity::SetSupportedPlatforms(DiscordppActivityGamePlatforms::Enum SupportedPlatforms) {
	discordpp::ActivityGamePlatforms p0 = (discordpp::ActivityGamePlatforms)SupportedPlatforms;

	obj->SetSupportedPlatforms(p0);
}

void DiscordppActivity::_bind_methods() {
	ClassDB::bind_method(D_METHOD("Drop"),
			&DiscordppActivity::Drop);

	ClassDB::bind_method(D_METHOD("Equals", "other"),
			&DiscordppActivity::Equals);

	ClassDB::bind_method(D_METHOD("Name"),
			&DiscordppActivity::Name);

	ClassDB::bind_method(D_METHOD("SetName", "Name"),
			&DiscordppActivity::SetName);

	ClassDB::bind_method(D_METHOD("Type"),
			&DiscordppActivity::Type);

	ClassDB::bind_method(D_METHOD("SetType", "Type"),
			&DiscordppActivity::SetType);

	ClassDB::bind_method(D_METHOD("State"),
			&DiscordppActivity::State);

	ClassDB::bind_method(D_METHOD("SetState", "State"),
			&DiscordppActivity::SetState);

	ClassDB::bind_method(D_METHOD("Details"),
			&DiscordppActivity::Details);

	ClassDB::bind_method(D_METHOD("SetDetails", "Details"),
			&DiscordppActivity::SetDetails);

	ClassDB::bind_method(D_METHOD("ApplicationId"),
			&DiscordppActivity::ApplicationId);

	ClassDB::bind_method(D_METHOD("SetApplicationId", "ApplicationId"),
			&DiscordppActivity::SetApplicationId);

	ClassDB::bind_method(D_METHOD("Assets"),
			&DiscordppActivity::Assets);

	ClassDB::bind_method(D_METHOD("SetAssets", "Assets"),
			&DiscordppActivity::SetAssets);

	ClassDB::bind_method(D_METHOD("Timestamps"),
			&DiscordppActivity::Timestamps);

	ClassDB::bind_method(D_METHOD("SetTimestamps", "Timestamps"),
			&DiscordppActivity::SetTimestamps);

	ClassDB::bind_method(D_METHOD("Party"),
			&DiscordppActivity::Party);

	ClassDB::bind_method(D_METHOD("SetParty", "Party"),
			&DiscordppActivity::SetParty);

	ClassDB::bind_method(D_METHOD("Secrets"),
			&DiscordppActivity::Secrets);

	ClassDB::bind_method(D_METHOD("SetSecrets", "Secrets"),
			&DiscordppActivity::SetSecrets);

	ClassDB::bind_method(D_METHOD("SupportedPlatforms"),
			&DiscordppActivity::SupportedPlatforms);

	ClassDB::bind_method(D_METHOD("SetSupportedPlatforms", "SupportedPlatforms"),
			&DiscordppActivity::SetSupportedPlatforms);
}
