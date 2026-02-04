
#include "discord_classes.h"

using namespace godot;

// Functions.

Variant DiscordActivityAssets::invite_cover_image() {
	auto r0 = obj->InviteCoverImage();

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

Variant DiscordActivityAssets::large_image() {
	auto r0 = obj->LargeImage();

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

Variant DiscordActivityAssets::large_text() {
	auto r0 = obj->LargeText();

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

Variant DiscordActivityAssets::large_url() {
	auto r0 = obj->LargeUrl();

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

Variant DiscordActivityAssets::small_image() {
	auto r0 = obj->SmallImage();

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

Variant DiscordActivityAssets::small_text() {
	auto r0 = obj->SmallText();

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

Variant DiscordActivityAssets::small_url() {
	auto r0 = obj->SmallUrl();

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

void DiscordActivityAssets::set_invite_cover_image(Variant invite_cover_image) {
	std::optional<std::string> p0;

	if (invite_cover_image.get_type() == Variant::STRING) {
		p0 = invite_cover_image.stringify().utf8().get_data();
	}

	obj->SetInviteCoverImage(p0);
}

void DiscordActivityAssets::set_large_image(Variant large_image) {
	std::optional<std::string> p0;

	if (large_image.get_type() == Variant::STRING) {
		p0 = large_image.stringify().utf8().get_data();
	}

	obj->SetLargeImage(p0);
}

void DiscordActivityAssets::set_large_text(Variant large_text) {
	std::optional<std::string> p0;

	if (large_text.get_type() == Variant::STRING) {
		p0 = large_text.stringify().utf8().get_data();
	}

	obj->SetLargeText(p0);
}

void DiscordActivityAssets::set_large_url(Variant large_url) {
	std::optional<std::string> p0;

	if (large_url.get_type() == Variant::STRING) {
		p0 = large_url.stringify().utf8().get_data();
	}

	obj->SetLargeUrl(p0);
}

void DiscordActivityAssets::set_small_image(Variant small_image) {
	std::optional<std::string> p0;

	if (small_image.get_type() == Variant::STRING) {
		p0 = small_image.stringify().utf8().get_data();
	}

	obj->SetSmallImage(p0);
}

void DiscordActivityAssets::set_small_text(Variant small_text) {
	std::optional<std::string> p0;

	if (small_text.get_type() == Variant::STRING) {
		p0 = small_text.stringify().utf8().get_data();
	}

	obj->SetSmallText(p0);
}

void DiscordActivityAssets::set_small_url(Variant small_url) {
	std::optional<std::string> p0;

	if (small_url.get_type() == Variant::STRING) {
		p0 = small_url.stringify().utf8().get_data();
	}

	obj->SetSmallUrl(p0);
}

// Overload functions.

// Binding.
void DiscordActivityAssets::_bind_methods() {
	ClassDB::bind_method(D_METHOD("invite_cover_image"),
			&DiscordActivityAssets::invite_cover_image);

	ClassDB::bind_method(D_METHOD("large_image"),
			&DiscordActivityAssets::large_image);

	ClassDB::bind_method(D_METHOD("large_text"),
			&DiscordActivityAssets::large_text);

	ClassDB::bind_method(D_METHOD("large_url"),
			&DiscordActivityAssets::large_url);

	ClassDB::bind_method(D_METHOD("set_invite_cover_image", "invite_cover_image"),
			&DiscordActivityAssets::set_invite_cover_image);

	ClassDB::bind_method(D_METHOD("set_large_image", "large_image"),
			&DiscordActivityAssets::set_large_image);

	ClassDB::bind_method(D_METHOD("set_large_text", "large_text"),
			&DiscordActivityAssets::set_large_text);

	ClassDB::bind_method(D_METHOD("set_large_url", "large_url"),
			&DiscordActivityAssets::set_large_url);

	ClassDB::bind_method(D_METHOD("set_small_image", "small_image"),
			&DiscordActivityAssets::set_small_image);

	ClassDB::bind_method(D_METHOD("set_small_text", "small_text"),
			&DiscordActivityAssets::set_small_text);

	ClassDB::bind_method(D_METHOD("set_small_url", "small_url"),
			&DiscordActivityAssets::set_small_url);

	ClassDB::bind_method(D_METHOD("small_image"),
			&DiscordActivityAssets::small_image);

	ClassDB::bind_method(D_METHOD("small_text"),
			&DiscordActivityAssets::small_text);

	ClassDB::bind_method(D_METHOD("small_url"),
			&DiscordActivityAssets::small_url);
}
