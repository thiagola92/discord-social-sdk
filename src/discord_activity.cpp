
#include "discord_classes.h"

using namespace godot;

// Functions.

DiscordActivityGamePlatforms::Enum DiscordActivity::supported_platforms() {
	auto r0 = obj->SupportedPlatforms();

	DiscordActivityGamePlatforms::Enum r1 = (DiscordActivityGamePlatforms::Enum)r0;

	return r1;
}

DiscordActivityTypes::Enum DiscordActivity::type() {
	auto r0 = obj->Type();

	DiscordActivityTypes::Enum r1 = (DiscordActivityTypes::Enum)r0;

	return r1;
}

String DiscordActivity::name() {
	auto r0 = obj->Name();

	String r1 = String(r0.c_str());

	return r1;
}

TypedArray<DiscordActivityButton> DiscordActivity::get_buttons() {
	auto r0 = obj->GetButtons();

	TypedArray<DiscordActivityButton> r1 = TypedArray<DiscordActivityButton>();

	for (auto i : r0) {
		discordpp::ActivityButton *r1_t_t = memnew(discordpp::ActivityButton(std::move(i)));
		DiscordActivityButton *r1_t = memnew(DiscordActivityButton{ r1_t_t });

		r1.push_back(r1_t);
	}

	return r1;
}

Variant DiscordActivity::application_id() {
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

Variant DiscordActivity::assets() {
	auto r0 = obj->Assets();

	Variant r1;

	if (!r0.has_value()) {
		r1 = nullptr;
	} else {
		auto r0_v = r0.value();

		discordpp::ActivityAssets *r1_v_t = memnew(discordpp::ActivityAssets(std::move(r0_v)));
		DiscordActivityAssets *r1_v = memnew(DiscordActivityAssets{ r1_v_t });

		r1 = Variant(r1_v);
	}

	return r1;
}

Variant DiscordActivity::details() {
	auto r0 = obj->Details();

	Variant r1;

	if (!r0.has_value()) {
		r1 = nullptr;
	} else {
		auto r0_v = r0.value();
		String r1_v = String(r0_v.c_str());
		r1 = Variant(r1_v);
	}

	return r1;
}

Variant DiscordActivity::details_url() {
	auto r0 = obj->DetailsUrl();

	Variant r1;

	if (!r0.has_value()) {
		r1 = nullptr;
	} else {
		auto r0_v = r0.value();
		String r1_v = String(r0_v.c_str());
		r1 = Variant(r1_v);
	}

	return r1;
}

Variant DiscordActivity::parent_application_id() {
	auto r0 = obj->ParentApplicationId();

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

Variant DiscordActivity::party() {
	auto r0 = obj->Party();

	Variant r1;

	if (!r0.has_value()) {
		r1 = nullptr;
	} else {
		auto r0_v = r0.value();

		discordpp::ActivityParty *r1_v_t = memnew(discordpp::ActivityParty(std::move(r0_v)));
		DiscordActivityParty *r1_v = memnew(DiscordActivityParty{ r1_v_t });

		r1 = Variant(r1_v);
	}

	return r1;
}

Variant DiscordActivity::secrets() {
	auto r0 = obj->Secrets();

	Variant r1;

	if (!r0.has_value()) {
		r1 = nullptr;
	} else {
		auto r0_v = r0.value();

		discordpp::ActivitySecrets *r1_v_t = memnew(discordpp::ActivitySecrets(std::move(r0_v)));
		DiscordActivitySecrets *r1_v = memnew(DiscordActivitySecrets{ r1_v_t });

		r1 = Variant(r1_v);
	}

	return r1;
}

Variant DiscordActivity::state() {
	auto r0 = obj->State();

	Variant r1;

	if (!r0.has_value()) {
		r1 = nullptr;
	} else {
		auto r0_v = r0.value();
		String r1_v = String(r0_v.c_str());
		r1 = Variant(r1_v);
	}

	return r1;
}

Variant DiscordActivity::state_url() {
	auto r0 = obj->StateUrl();

	Variant r1;

	if (!r0.has_value()) {
		r1 = nullptr;
	} else {
		auto r0_v = r0.value();
		String r1_v = String(r0_v.c_str());
		r1 = Variant(r1_v);
	}

	return r1;
}

Variant DiscordActivity::status_display_type() {
	auto r0 = obj->StatusDisplayType();

	Variant r1;

	if (!r0.has_value()) {
		r1 = nullptr;
	} else {
		auto r0_v = r0.value();
		DiscordStatusDisplayTypes::Enum r1_v = (DiscordStatusDisplayTypes::Enum)r0_v;
		r1 = Variant(r1_v);
	}

	return r1;
}

Variant DiscordActivity::timestamps() {
	auto r0 = obj->Timestamps();

	Variant r1;

	if (!r0.has_value()) {
		r1 = nullptr;
	} else {
		auto r0_v = r0.value();

		discordpp::ActivityTimestamps *r1_v_t = memnew(discordpp::ActivityTimestamps(std::move(r0_v)));
		DiscordActivityTimestamps *r1_v = memnew(DiscordActivityTimestamps{ r1_v_t });

		r1 = Variant(r1_v);
	}

	return r1;
}

bool DiscordActivity::equals(DiscordActivity *other) {
	discordpp::Activity p0 = *other->unwrap();
	auto r0 = obj->Equals(p0);

	bool r1 = r0;

	return r1;
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
		DiscordActivityAssets *p0_t = Object::cast_to<DiscordActivityAssets>(assets);
		p0 = std::optional<discordpp::ActivityAssets>{ *p0_t->unwrap() };
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
		DiscordActivityParty *p0_t = Object::cast_to<DiscordActivityParty>(party);
		p0 = std::optional<discordpp::ActivityParty>{ *p0_t->unwrap() };
	}

	obj->SetParty(p0);
}

void DiscordActivity::set_secrets(Variant secrets) {
	std::optional<discordpp::ActivitySecrets> p0;

	if (secrets.get_type() == Variant::OBJECT) {
		DiscordActivitySecrets *p0_t = Object::cast_to<DiscordActivitySecrets>(secrets);
		p0 = std::optional<discordpp::ActivitySecrets>{ *p0_t->unwrap() };
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
		p0 = std::optional<discordpp::StatusDisplayTypes>{ (discordpp::StatusDisplayTypes)(uint64_t)status_display_type };
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
		DiscordActivityTimestamps *p0_t = Object::cast_to<DiscordActivityTimestamps>(timestamps);
		p0 = std::optional<discordpp::ActivityTimestamps>{ *p0_t->unwrap() };
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
