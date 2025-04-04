// AUTO-GENERATED
#include "discord_activity.h"

using namespace godot;

discordpp::Activity *DiscordActivity::unwrap() {
	return activity;
}

String DiscordActivity::name() {
	auto r = activity->Name();
	return String(r.c_str());
}

void DiscordActivity::set_name(String name) {
	auto p0 = name.utf8().get_data();
	activity->SetName(p0);
}

DiscordActivityTypes::Enum DiscordActivity::type() {
	auto r = activity->Type();
	return (DiscordActivityTypes::Enum)r;
}

void DiscordActivity::set_type(DiscordActivityTypes::Enum type) {
	auto p0 = (discordpp::ActivityTypes)type;
	activity->SetType(p0);
}

Variant DiscordActivity::state() {
	auto r = activity->State();

	if (!r.has_value()) {
		return nullptr;
	}

	return Variant(r.value().c_str());
}

void DiscordActivity::set_state(Variant state) {
	std::optional<std::string> p0;

	if (state.get_type() == Variant::STRING) {
		p0 = state.stringify().utf8().get_data();
	}

	activity->SetState(p0);
}

Variant DiscordActivity::details() {
	auto r = activity->Details();

	if (!r.has_value()) {
		return nullptr;
	}

	return Variant(r.value().c_str());
}

void DiscordActivity::set_details(Variant details) {
	std::optional<std::string> p0;

	if (details.get_type() == Variant::STRING) {
		p0 = details.stringify().utf8().get_data();
	}

	activity->SetDetails(p0);
}

Variant DiscordActivity::application_id() {
	auto r = activity->ApplicationId();

	if (!r.has_value()) {
		return nullptr;
	}

	return Variant(r.value());
}

void DiscordActivity::set_application_id(Variant application_id) {
	std::optional<uint64_t> p0;

	if (application_id.get_type() == Variant::INT) {
		p0 = (uint64_t)application_id;
	}

	activity->SetApplicationId(p0);
}

Variant DiscordActivity::assets() {
	auto r = activity->Assets();

	if (!r.has_value()) {
		return nullptr;
	}

	auto t_r = (discordpp::ActivityAssets *)memalloc(sizeof(discordpp::ActivityAssets));
	*t_r = r.value();
	return Variant(memnew(DiscordActivityAssets{ t_r }));
}

void DiscordActivity::set_assets(Variant assets) {
	std::optional<discordpp::ActivityAssets> p0;

	if (assets.get_type() == Variant::OBJECT) {
		auto t_p0 = Object::cast_to<DiscordActivityAssets>(assets);
		auto t2_p0 = t_p0->unwrap();
		p0 = std::optional<discordpp::ActivityAssets>{ *t2_p0 };
	}

	activity->SetAssets(p0);
}

Variant DiscordActivity::timestamps() {
	auto r = activity->Timestamps();

	if (!r.has_value()) {
		return nullptr;
	}

	auto t_r = (discordpp::ActivityTimestamps *)memalloc(sizeof(discordpp::ActivityTimestamps));
	*t_r = r.value();
	return Variant(memnew(DiscordActivityTimestamps{ t_r }));
}

void DiscordActivity::set_timestamps(Variant timestamps) {
	std::optional<discordpp::ActivityTimestamps> p0;

	if (timestamps.get_type() == Variant::OBJECT) {
		auto t_p0 = Object::cast_to<DiscordActivityTimestamps>(timestamps);
		auto t2_p0 = t_p0->unwrap();
		p0 = std::optional<discordpp::ActivityTimestamps>{ *t2_p0 };
	}

	activity->SetTimestamps(p0);
}

Variant DiscordActivity::party() {
	auto r = activity->Party();

	if (!r.has_value()) {
		return nullptr;
	}

	auto t_r = (discordpp::ActivityParty *)memalloc(sizeof(discordpp::ActivityParty));
	*t_r = r.value();
	return Variant(memnew(DiscordActivityParty{ t_r }));
}

void DiscordActivity::set_party(Variant party) {
	std::optional<discordpp::ActivityParty> p0;

	if (party.get_type() == Variant::OBJECT) {
		auto t_p0 = Object::cast_to<DiscordActivityParty>(party);
		auto t2_p0 = t_p0->unwrap();
		p0 = std::optional<discordpp::ActivityParty>{ *t2_p0 };
	}

	activity->SetParty(p0);
}

Variant DiscordActivity::secrets() {
	auto r = activity->Secrets();

	if (!r.has_value()) {
		return nullptr;
	}

	auto t_r = (discordpp::ActivitySecrets *)memalloc(sizeof(discordpp::ActivitySecrets));
	*t_r = r.value();
	return Variant(memnew(DiscordActivitySecrets{ t_r }));
}

void DiscordActivity::set_secrets(Variant secrets) {
	std::optional<discordpp::ActivitySecrets> p0;

	if (secrets.get_type() == Variant::OBJECT) {
		auto t_p0 = Object::cast_to<DiscordActivitySecrets>(secrets);
		auto t2_p0 = t_p0->unwrap();
		p0 = std::optional<discordpp::ActivitySecrets>{ *t2_p0 };
	}

	activity->SetSecrets(p0);
}

DiscordActivityGamePlatforms::Enum DiscordActivity::supported_platforms() {
	auto r = activity->SupportedPlatforms();
	return (DiscordActivityGamePlatforms::Enum)r;
}

void DiscordActivity::set_supported_platforms(DiscordActivityGamePlatforms::Enum supported_platforms) {
	auto p0 = (discordpp::ActivityGamePlatforms)supported_platforms;
	activity->SetSupportedPlatforms(p0);
}

void DiscordActivity::_bind_methods() {
	ClassDB::bind_method(D_METHOD("name"),
			&DiscordActivity::name);

	ClassDB::bind_method(D_METHOD("set_name", "name"),
			&DiscordActivity::set_name);

	ClassDB::bind_method(D_METHOD("type"),
			&DiscordActivity::type);

	ClassDB::bind_method(D_METHOD("set_type", "type"),
			&DiscordActivity::set_type);

	ClassDB::bind_method(D_METHOD("state"),
			&DiscordActivity::state);

	ClassDB::bind_method(D_METHOD("set_state", "state"),
			&DiscordActivity::set_state);

	ClassDB::bind_method(D_METHOD("details"),
			&DiscordActivity::details);

	ClassDB::bind_method(D_METHOD("set_details", "details"),
			&DiscordActivity::set_details);

	ClassDB::bind_method(D_METHOD("application_id"),
			&DiscordActivity::application_id);

	ClassDB::bind_method(D_METHOD("set_application_id", "application_id"),
			&DiscordActivity::set_application_id);

	ClassDB::bind_method(D_METHOD("assets"),
			&DiscordActivity::assets);

	ClassDB::bind_method(D_METHOD("set_assets", "assets"),
			&DiscordActivity::set_assets);

	ClassDB::bind_method(D_METHOD("timestamps"),
			&DiscordActivity::timestamps);

	ClassDB::bind_method(D_METHOD("set_timestamps", "timestamps"),
			&DiscordActivity::set_timestamps);

	ClassDB::bind_method(D_METHOD("party"),
			&DiscordActivity::party);

	ClassDB::bind_method(D_METHOD("set_party", "party"),
			&DiscordActivity::set_party);

	ClassDB::bind_method(D_METHOD("secrets"),
			&DiscordActivity::secrets);

	ClassDB::bind_method(D_METHOD("set_secrets", "secrets"),
			&DiscordActivity::set_secrets);

	ClassDB::bind_method(D_METHOD("supported_platforms"),
			&DiscordActivity::supported_platforms);

	ClassDB::bind_method(D_METHOD("set_supported_platforms", "supported_platforms"),
			&DiscordActivity::set_supported_platforms);
}

DiscordActivity::DiscordActivity() {
	this->activity = memnew(discordpp::Activity);
}

DiscordActivity::DiscordActivity(discordpp::Activity *activity) {
	this->activity = activity;
}

DiscordActivity::~DiscordActivity() {}
