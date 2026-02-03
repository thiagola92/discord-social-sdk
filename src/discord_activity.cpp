
#include "discord_classes.h"

using namespace godot;

// Functions.

DiscordActivityGamePlatforms::Enum DiscordActivity::supported_platforms() {
	auto r = obj->SupportedPlatforms();

	DiscordActivityGamePlatforms::Enum cr = (DiscordActivityGamePlatforms::Enum)r;
	return cr;
}

DiscordActivityTypes::Enum DiscordActivity::type() {
	auto r = obj->Type();

	DiscordActivityTypes::Enum cr = (DiscordActivityTypes::Enum)r;
	return cr;
}

String DiscordActivity::name() {
	auto r = obj->Name();

	String cr = String(r.c_str());
	return cr;
}

TypedArray<DiscordActivityButton> DiscordActivity::get_buttons() {
	auto r = obj->GetButtons();

	TypedArray<DiscordActivityButton> cr = TypedArray<DiscordActivityButton>();

	for (auto i : r) {
		discordpp::ActivityButton *cr_t_t = memnew(discordpp::ActivityButton(std::move(i)));
		DiscordActivityButton *cr_t = memnew(DiscordActivityButton{ cr_t_t });

		cr.push_back(cr_t);
	}

	return cr;
}

Variant DiscordActivity::application_id() {
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

Variant DiscordActivity::assets() {
	auto r = obj->Assets();

	Variant cr;

	if (!r.has_value()) {
		cr = nullptr;
	} else {
		auto r_v = r.value();

		discordpp::ActivityAssets *cr_v_t = memnew(discordpp::ActivityAssets(std::move(r_v)));
		DiscordActivityAssets *cr_v = memnew(DiscordActivityAssets{ cr_v_t });

		cr = Variant(cr_v);
	}

	return cr;
}

Variant DiscordActivity::details() {
	auto r = obj->Details();

	Variant cr;

	if (!r.has_value()) {
		cr = nullptr;
	} else {
		auto r_v = r.value();
		String cr_v = String(r_v.c_str());
		cr = Variant(cr_v);
	}

	return cr;
}

Variant DiscordActivity::details_url() {
	auto r = obj->DetailsUrl();

	Variant cr;

	if (!r.has_value()) {
		cr = nullptr;
	} else {
		auto r_v = r.value();
		String cr_v = String(r_v.c_str());
		cr = Variant(cr_v);
	}

	return cr;
}

Variant DiscordActivity::parent_application_id() {
	auto r = obj->ParentApplicationId();

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

Variant DiscordActivity::party() {
	auto r = obj->Party();

	Variant cr;

	if (!r.has_value()) {
		cr = nullptr;
	} else {
		auto r_v = r.value();

		discordpp::ActivityParty *cr_v_t = memnew(discordpp::ActivityParty(std::move(r_v)));
		DiscordActivityParty *cr_v = memnew(DiscordActivityParty{ cr_v_t });

		cr = Variant(cr_v);
	}

	return cr;
}

Variant DiscordActivity::secrets() {
	auto r = obj->Secrets();

	Variant cr;

	if (!r.has_value()) {
		cr = nullptr;
	} else {
		auto r_v = r.value();

		discordpp::ActivitySecrets *cr_v_t = memnew(discordpp::ActivitySecrets(std::move(r_v)));
		DiscordActivitySecrets *cr_v = memnew(DiscordActivitySecrets{ cr_v_t });

		cr = Variant(cr_v);
	}

	return cr;
}

Variant DiscordActivity::state() {
	auto r = obj->State();

	Variant cr;

	if (!r.has_value()) {
		cr = nullptr;
	} else {
		auto r_v = r.value();
		String cr_v = String(r_v.c_str());
		cr = Variant(cr_v);
	}

	return cr;
}

Variant DiscordActivity::state_url() {
	auto r = obj->StateUrl();

	Variant cr;

	if (!r.has_value()) {
		cr = nullptr;
	} else {
		auto r_v = r.value();
		String cr_v = String(r_v.c_str());
		cr = Variant(cr_v);
	}

	return cr;
}

Variant DiscordActivity::status_display_type() {
	auto r = obj->StatusDisplayType();

	Variant cr;

	if (!r.has_value()) {
		cr = nullptr;
	} else {
		auto r_v = r.value();

		discordpp::StatusDisplayTypes *cr_v_t = memnew(discordpp::StatusDisplayTypes(std::move(r_v)));
		DiscordStatusDisplayTypes *cr_v = memnew(DiscordStatusDisplayTypes{ cr_v_t });

		cr = Variant(cr_v);
	}

	return cr;
}

Variant DiscordActivity::timestamps() {
	auto r = obj->Timestamps();

	Variant cr;

	if (!r.has_value()) {
		cr = nullptr;
	} else {
		auto r_v = r.value();

		discordpp::ActivityTimestamps *cr_v_t = memnew(discordpp::ActivityTimestamps(std::move(r_v)));
		DiscordActivityTimestamps *cr_v = memnew(DiscordActivityTimestamps{ cr_v_t });

		cr = Variant(cr_v);
	}

	return cr;
}

bool DiscordActivity::equals(DiscordActivity *other) {
	discordpp::Activity p0 = *other->unwrap();
	auto r = obj->Equals(p0);

	bool cr = r;
	return cr;
}

void DiscordActivity::add_button(DiscordActivityButton *button) {
	discordpp::ActivityButton p0 = *button->unwrap();
	obj->AddButton(p0);
}

void DiscordActivity::set_application_id(Variant application_id) {
	std::optional<uint64_t> p0;

	if (application_id.get_type() == Variant::INT) {
		p0 = application_id;
	}

	obj->SetApplicationId(p0);
}

void DiscordActivity::set_assets(Variant assets) {
	std::optional<discordpp::ActivityAssets> p0;

	if (assets.get_type() == Variant::OBJECT) {
	}

	obj->SetAssets(p0);
}

void DiscordActivity::set_details(Variant details) {
	std::optional<std::string> p0;

	if (details.get_type() == Variant::STRING) {
		p0 = details.stringify().utf8().get_data();
	}

	obj->SetDetails(p0);
}

void DiscordActivity::set_details_url(Variant details_url) {
	std::optional<std::string> p0;

	if (details_url.get_type() == Variant::STRING) {
		p0 = details_url.stringify().utf8().get_data();
	}

	obj->SetDetailsUrl(p0);
}

void DiscordActivity::set_name(String name) {
	std::string p0 = std::string(name.utf8().get_data());
	obj->SetName(p0);
}

void DiscordActivity::set_parent_application_id(Variant parent_application_id) {
	std::optional<uint64_t> p0;

	if (parent_application_id.get_type() == Variant::INT) {
		p0 = parent_application_id;
	}

	obj->SetParentApplicationId(p0);
}

void DiscordActivity::set_party(Variant party) {
	std::optional<discordpp::ActivityParty> p0;

	if (party.get_type() == Variant::OBJECT) {
	}

	obj->SetParty(p0);
}

void DiscordActivity::set_secrets(Variant secrets) {
	std::optional<discordpp::ActivitySecrets> p0;

	if (secrets.get_type() == Variant::OBJECT) {
	}

	obj->SetSecrets(p0);
}

void DiscordActivity::set_state(Variant state) {
	std::optional<std::string> p0;

	if (state.get_type() == Variant::STRING) {
		p0 = state.stringify().utf8().get_data();
	}

	obj->SetState(p0);
}

void DiscordActivity::set_state_url(Variant state_url) {
	std::optional<std::string> p0;

	if (state_url.get_type() == Variant::STRING) {
		p0 = state_url.stringify().utf8().get_data();
	}

	obj->SetStateUrl(p0);
}

void DiscordActivity::set_status_display_type(Variant status_display_type) {
	std::optional<discordpp::StatusDisplayTypes> p0;

	if (status_display_type.get_type() == Variant::OBJECT) {
	}

	obj->SetStatusDisplayType(p0);
}

void DiscordActivity::set_supported_platforms(DiscordActivityGamePlatforms::Enum supported_platforms) {
	discordpp::ActivityGamePlatforms p0 = (discordpp::ActivityGamePlatforms)supported_platforms;
	obj->SetSupportedPlatforms(p0);
}

void DiscordActivity::set_timestamps(Variant timestamps) {
	std::optional<discordpp::ActivityTimestamps> p0;

	if (timestamps.get_type() == Variant::OBJECT) {
	}

	obj->SetTimestamps(p0);
}

void DiscordActivity::set_type(DiscordActivityTypes::Enum type) {
	discordpp::ActivityTypes p0 = (discordpp::ActivityTypes)type;
	obj->SetType(p0);
}

// Overload functions.

// Binding.
void DiscordActivity::_bind_methods() {
	ClassDB::bind_method(D_METHOD("add_button", "button"),
			&DiscordActivity::add_button);

	ClassDB::bind_method(D_METHOD("application_id"),
			&DiscordActivity::application_id);

	ClassDB::bind_method(D_METHOD("assets"),
			&DiscordActivity::assets);

	ClassDB::bind_method(D_METHOD("details"),
			&DiscordActivity::details);

	ClassDB::bind_method(D_METHOD("details_url"),
			&DiscordActivity::details_url);

	ClassDB::bind_method(D_METHOD("equals", "other"),
			&DiscordActivity::equals);

	ClassDB::bind_method(D_METHOD("get_buttons"),
			&DiscordActivity::get_buttons);

	ClassDB::bind_method(D_METHOD("name"),
			&DiscordActivity::name);

	ClassDB::bind_method(D_METHOD("parent_application_id"),
			&DiscordActivity::parent_application_id);

	ClassDB::bind_method(D_METHOD("party"),
			&DiscordActivity::party);

	ClassDB::bind_method(D_METHOD("secrets"),
			&DiscordActivity::secrets);

	ClassDB::bind_method(D_METHOD("set_application_id", "application_id"),
			&DiscordActivity::set_application_id);

	ClassDB::bind_method(D_METHOD("set_assets", "assets"),
			&DiscordActivity::set_assets);

	ClassDB::bind_method(D_METHOD("set_details", "details"),
			&DiscordActivity::set_details);

	ClassDB::bind_method(D_METHOD("set_details_url", "details_url"),
			&DiscordActivity::set_details_url);

	ClassDB::bind_method(D_METHOD("set_name", "name"),
			&DiscordActivity::set_name);

	ClassDB::bind_method(D_METHOD("set_parent_application_id", "parent_application_id"),
			&DiscordActivity::set_parent_application_id);

	ClassDB::bind_method(D_METHOD("set_party", "party"),
			&DiscordActivity::set_party);

	ClassDB::bind_method(D_METHOD("set_secrets", "secrets"),
			&DiscordActivity::set_secrets);

	ClassDB::bind_method(D_METHOD("set_state", "state"),
			&DiscordActivity::set_state);

	ClassDB::bind_method(D_METHOD("set_state_url", "state_url"),
			&DiscordActivity::set_state_url);

	ClassDB::bind_method(D_METHOD("set_status_display_type", "status_display_type"),
			&DiscordActivity::set_status_display_type);

	ClassDB::bind_method(D_METHOD("set_supported_platforms", "supported_platforms"),
			&DiscordActivity::set_supported_platforms);

	ClassDB::bind_method(D_METHOD("set_timestamps", "timestamps"),
			&DiscordActivity::set_timestamps);

	ClassDB::bind_method(D_METHOD("set_type", "type"),
			&DiscordActivity::set_type);

	ClassDB::bind_method(D_METHOD("state"),
			&DiscordActivity::state);

	ClassDB::bind_method(D_METHOD("state_url"),
			&DiscordActivity::state_url);

	ClassDB::bind_method(D_METHOD("status_display_type"),
			&DiscordActivity::status_display_type);

	ClassDB::bind_method(D_METHOD("supported_platforms"),
			&DiscordActivity::supported_platforms);

	ClassDB::bind_method(D_METHOD("timestamps"),
			&DiscordActivity::timestamps);

	ClassDB::bind_method(D_METHOD("type"),
			&DiscordActivity::type);
}
