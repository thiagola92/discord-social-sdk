// AUTO-GENERATED
#include "discord_activity_assets.h"

using namespace godot;

discordpp::ActivityAssets *DiscordActivityAssets::unwrap() {
	return &activity_assets;
}

Variant DiscordActivityAssets::large_image() {
	auto r = activity_assets.LargeImage();

	if (!r.has_value()) {
		return nullptr;
	}

	return Variant(r.value().c_str());
}

void DiscordActivityAssets::set_large_image(Variant large_image) {
	std::optional<std::string> p0;

	if (large_image.get_type() == Variant::STRING) {
		p0 = large_image.stringify().utf8().get_data();
	}

	activity_assets.SetLargeImage(p0);
}

Variant DiscordActivityAssets::large_text() {
	auto r = activity_assets.LargeText();

	if (!r.has_value()) {
		return nullptr;
	}

	return Variant(r.value().c_str());
}

void DiscordActivityAssets::set_large_text(Variant large_text) {
	std::optional<std::string> p0;

	if (large_text.get_type() == Variant::STRING) {
		p0 = large_text.stringify().utf8().get_data();
	}

	activity_assets.SetLargeText(p0);
}

Variant DiscordActivityAssets::small_image() {
	auto r = activity_assets.SmallImage();

	if (!r.has_value()) {
		return nullptr;
	}

	return Variant(r.value().c_str());
}

void DiscordActivityAssets::set_small_image(Variant small_image) {
	std::optional<std::string> p0;

	if (small_image.get_type() == Variant::STRING) {
		p0 = small_image.stringify().utf8().get_data();
	}

	activity_assets.SetSmallImage(p0);
}

Variant DiscordActivityAssets::small_text() {
	auto r = activity_assets.SmallText();

	if (!r.has_value()) {
		return nullptr;
	}

	return Variant(r.value().c_str());
}

void DiscordActivityAssets::set_small_text(Variant small_text) {
	std::optional<std::string> p0;

	if (small_text.get_type() == Variant::STRING) {
		p0 = small_text.stringify().utf8().get_data();
	}

	activity_assets.SetSmallText(p0);
}

void DiscordActivityAssets::_bind_methods() {
	ClassDB::bind_method(D_METHOD("large_image"),
			&DiscordActivityAssets::large_image);

	ClassDB::bind_method(D_METHOD("set_large_image", "large_image"),
			&DiscordActivityAssets::set_large_image);

	ClassDB::bind_method(D_METHOD("large_text"),
			&DiscordActivityAssets::large_text);

	ClassDB::bind_method(D_METHOD("set_large_text", "large_text"),
			&DiscordActivityAssets::set_large_text);

	ClassDB::bind_method(D_METHOD("small_image"),
			&DiscordActivityAssets::small_image);

	ClassDB::bind_method(D_METHOD("set_small_image", "small_image"),
			&DiscordActivityAssets::set_small_image);

	ClassDB::bind_method(D_METHOD("small_text"),
			&DiscordActivityAssets::small_text);

	ClassDB::bind_method(D_METHOD("set_small_text", "small_text"),
			&DiscordActivityAssets::set_small_text);
}

DiscordActivityAssets::DiscordActivityAssets() {}

DiscordActivityAssets::DiscordActivityAssets(discordpp::ActivityAssets activity_assets) {
	this->activity_assets = activity_assets;
}

DiscordActivityAssets::~DiscordActivityAssets() {}
