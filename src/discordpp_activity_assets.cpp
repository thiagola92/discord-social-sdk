
#include "discordpp_classes.h"

using namespace godot;

void DiscordppActivityAssets::Drop() {
	obj->Drop();
}

Variant DiscordppActivityAssets::LargeImage() {
	auto r = obj->LargeImage();

	if (!r.has_value()) {
		return nullptr;
	}

	return Variant(r.value().c_str());
}

void DiscordppActivityAssets::SetLargeImage(Variant LargeImage) {
	std::optional<std::string> p0;

	if (LargeImage.get_type() == Variant::STRING) {
		p0 = LargeImage.stringify().utf8().get_data();
	}

	obj->SetLargeImage(p0);
}

Variant DiscordppActivityAssets::LargeText() {
	auto r = obj->LargeText();

	if (!r.has_value()) {
		return nullptr;
	}

	return Variant(r.value().c_str());
}

void DiscordppActivityAssets::SetLargeText(Variant LargeText) {
	std::optional<std::string> p0;

	if (LargeText.get_type() == Variant::STRING) {
		p0 = LargeText.stringify().utf8().get_data();
	}

	obj->SetLargeText(p0);
}

Variant DiscordppActivityAssets::LargeUrl() {
	auto r = obj->LargeUrl();

	if (!r.has_value()) {
		return nullptr;
	}

	return Variant(r.value().c_str());
}

void DiscordppActivityAssets::SetLargeUrl(Variant LargeUrl) {
	std::optional<std::string> p0;

	if (LargeUrl.get_type() == Variant::STRING) {
		p0 = LargeUrl.stringify().utf8().get_data();
	}

	obj->SetLargeUrl(p0);
}

Variant DiscordppActivityAssets::SmallImage() {
	auto r = obj->SmallImage();

	if (!r.has_value()) {
		return nullptr;
	}

	return Variant(r.value().c_str());
}

void DiscordppActivityAssets::SetSmallImage(Variant SmallImage) {
	std::optional<std::string> p0;

	if (SmallImage.get_type() == Variant::STRING) {
		p0 = SmallImage.stringify().utf8().get_data();
	}

	obj->SetSmallImage(p0);
}

Variant DiscordppActivityAssets::SmallText() {
	auto r = obj->SmallText();

	if (!r.has_value()) {
		return nullptr;
	}

	return Variant(r.value().c_str());
}

void DiscordppActivityAssets::SetSmallText(Variant SmallText) {
	std::optional<std::string> p0;

	if (SmallText.get_type() == Variant::STRING) {
		p0 = SmallText.stringify().utf8().get_data();
	}

	obj->SetSmallText(p0);
}

Variant DiscordppActivityAssets::SmallUrl() {
	auto r = obj->SmallUrl();

	if (!r.has_value()) {
		return nullptr;
	}

	return Variant(r.value().c_str());
}

void DiscordppActivityAssets::SetSmallUrl(Variant SmallUrl) {
	std::optional<std::string> p0;

	if (SmallUrl.get_type() == Variant::STRING) {
		p0 = SmallUrl.stringify().utf8().get_data();
	}

	obj->SetSmallUrl(p0);
}

Variant DiscordppActivityAssets::InviteCoverImage() {
	auto r = obj->InviteCoverImage();

	if (!r.has_value()) {
		return nullptr;
	}

	return Variant(r.value().c_str());
}

void DiscordppActivityAssets::SetInviteCoverImage(Variant InviteCoverImage) {
	std::optional<std::string> p0;

	if (InviteCoverImage.get_type() == Variant::STRING) {
		p0 = InviteCoverImage.stringify().utf8().get_data();
	}

	obj->SetInviteCoverImage(p0);
}

void DiscordppActivityAssets::_bind_methods() {
	ClassDB::bind_method(D_METHOD("Drop"),
			&DiscordppActivityAssets::Drop);

	ClassDB::bind_method(D_METHOD("LargeImage"),
			&DiscordppActivityAssets::LargeImage);

	ClassDB::bind_method(D_METHOD("SetLargeImage", "LargeImage"),
			&DiscordppActivityAssets::SetLargeImage);

	ClassDB::bind_method(D_METHOD("LargeText"),
			&DiscordppActivityAssets::LargeText);

	ClassDB::bind_method(D_METHOD("SetLargeText", "LargeText"),
			&DiscordppActivityAssets::SetLargeText);

	ClassDB::bind_method(D_METHOD("LargeUrl"),
			&DiscordppActivityAssets::LargeUrl);

	ClassDB::bind_method(D_METHOD("SetLargeUrl", "LargeUrl"),
			&DiscordppActivityAssets::SetLargeUrl);

	ClassDB::bind_method(D_METHOD("SmallImage"),
			&DiscordppActivityAssets::SmallImage);

	ClassDB::bind_method(D_METHOD("SetSmallImage", "SmallImage"),
			&DiscordppActivityAssets::SetSmallImage);

	ClassDB::bind_method(D_METHOD("SmallText"),
			&DiscordppActivityAssets::SmallText);

	ClassDB::bind_method(D_METHOD("SetSmallText", "SmallText"),
			&DiscordppActivityAssets::SetSmallText);

	ClassDB::bind_method(D_METHOD("SmallUrl"),
			&DiscordppActivityAssets::SmallUrl);

	ClassDB::bind_method(D_METHOD("SetSmallUrl", "SmallUrl"),
			&DiscordppActivityAssets::SetSmallUrl);

	ClassDB::bind_method(D_METHOD("InviteCoverImage"),
			&DiscordppActivityAssets::InviteCoverImage);

	ClassDB::bind_method(D_METHOD("SetInviteCoverImage", "InviteCoverImage"),
			&DiscordppActivityAssets::SetInviteCoverImage);
}
