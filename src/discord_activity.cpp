
#include "discord_classes.h"

using namespace godot;

// Functions.

DiscordActivityGamePlatforms DiscordActivity::supported_platforms() {
}

DiscordActivityTypes DiscordActivity::type() {
}

String DiscordActivity::name() {
}

TypedArray<DiscordActivityButton> DiscordActivity::get_buttons() {
}

Variant DiscordActivity::application_id() {
}

Variant DiscordActivity::assets() {
}

Variant DiscordActivity::details() {
}

Variant DiscordActivity::details_url() {
}

Variant DiscordActivity::parent_application_id() {
}

Variant DiscordActivity::party() {
}

Variant DiscordActivity::secrets() {
}

Variant DiscordActivity::state() {
}

Variant DiscordActivity::state_url() {
}

Variant DiscordActivity::status_display_type() {
}

Variant DiscordActivity::timestamps() {
}

bool DiscordActivity::equals(DiscordActivity other) {
	// TODO
}

void DiscordActivity::add_button(DiscordActivityButton button) {
	// TODO
}

void DiscordActivity::set_application_id(Variant application_id) {
	std::optional<uint64_t> p0;

	if (application_id.get_type() == Variant::INT) {
		p0 = application_id;
	}
}

void DiscordActivity::set_assets(Variant assets) {
	std::optional<discordpp::ActivityAssets> p0;

	if (assets.get_type() == Variant::OBJECT) {
	}
}

void DiscordActivity::set_details(Variant details) {
	std::optional<std::string> p0;

	if (details.get_type() == Variant::STRING) {
		p0 = details.stringify().utf8().get_data();
	}
}

void DiscordActivity::set_details_url(Variant details_url) {
	std::optional<std::string> p0;

	if (details_url.get_type() == Variant::STRING) {
		p0 = details_url.stringify().utf8().get_data();
	}
}

void DiscordActivity::set_name(String name) {
	std::string p0 = std::string(name.utf8().get_data());
}

void DiscordActivity::set_parent_application_id(Variant parent_application_id) {
	std::optional<uint64_t> p0;

	if (parent_application_id.get_type() == Variant::INT) {
		p0 = parent_application_id;
	}
}

void DiscordActivity::set_party(Variant party) {
	std::optional<discordpp::ActivityParty> p0;

	if (party.get_type() == Variant::OBJECT) {
	}
}

void DiscordActivity::set_secrets(Variant secrets) {
	std::optional<discordpp::ActivitySecrets> p0;

	if (secrets.get_type() == Variant::OBJECT) {
	}
}

void DiscordActivity::set_state(Variant state) {
	std::optional<std::string> p0;

	if (state.get_type() == Variant::STRING) {
		p0 = state.stringify().utf8().get_data();
	}
}

void DiscordActivity::set_state_url(Variant state_url) {
	std::optional<std::string> p0;

	if (state_url.get_type() == Variant::STRING) {
		p0 = state_url.stringify().utf8().get_data();
	}
}

void DiscordActivity::set_status_display_type(Variant status_display_type) {
	std::optional<discordpp::StatusDisplayTypes> p0;

	if (status_display_type.get_type() == Variant::OBJECT) {
	}
}

void DiscordActivity::set_supported_platforms(DiscordActivityGamePlatforms supported_platforms) {
	// TODO
}

void DiscordActivity::set_timestamps(Variant timestamps) {
	std::optional<discordpp::ActivityTimestamps> p0;

	if (timestamps.get_type() == Variant::OBJECT) {
	}
}

void DiscordActivity::set_type(DiscordActivityTypes type) {
	// TODO
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
