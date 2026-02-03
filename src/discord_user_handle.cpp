
#include "discord_classes.h"

using namespace godot;

// Functions.

DiscordRelationshipHandle *DiscordUserHandle::relationship() {
	auto r = obj->Relationship();

	discordpp::RelationshipHandle *cr_t = memnew(discordpp::RelationshipHandle(std::move(r)));
	DiscordRelationshipHandle *cr = memnew(DiscordRelationshipHandle{ cr_t });

	return cr;
}

DiscordStatusType::Enum DiscordUserHandle::status() {
	auto r = obj->Status();

	DiscordStatusType::Enum cr = (DiscordStatusType::Enum)r;
	return cr;
}

String DiscordUserHandle::avatar_type_to_string(DiscordUserHandleAvatarType::Enum type) {
	discordpp::UserHandle::AvatarType p0 = (discordpp::UserHandle::AvatarType)type;
	auto r = discordpp::UserHandle::AvatarTypeToString(p0);

	String cr = String(r.c_str());
	return cr;
}

String DiscordUserHandle::avatar_url(DiscordUserHandleAvatarType::Enum animated_type, DiscordUserHandleAvatarType::Enum static_type) {
	discordpp::UserHandle::AvatarType p0 = (discordpp::UserHandle::AvatarType)animated_type;
	discordpp::UserHandle::AvatarType p1 = (discordpp::UserHandle::AvatarType)static_type;
	auto r = obj->AvatarUrl(p0, p1);

	String cr = String(r.c_str());
	return cr;
}

String DiscordUserHandle::display_name() {
	auto r = obj->DisplayName();

	String cr = String(r.c_str());
	return cr;
}

String DiscordUserHandle::username() {
	auto r = obj->Username();

	String cr = String(r.c_str());
	return cr;
}

TypedArray<DiscordUserApplicationProfileHandle> DiscordUserHandle::user_application_profiles() {
	auto r = obj->UserApplicationProfiles();

	TypedArray<DiscordUserApplicationProfileHandle> cr = TypedArray<DiscordUserApplicationProfileHandle>();

	for (auto i : r) {
		discordpp::UserApplicationProfileHandle *cr_t_t = memnew(discordpp::UserApplicationProfileHandle(std::move(i)));
		DiscordUserApplicationProfileHandle *cr_t = memnew(DiscordUserApplicationProfileHandle{ cr_t_t });

		cr.push_back(cr_t);
	}

	return cr;
}

Variant DiscordUserHandle::avatar() {
	auto r = obj->Avatar();

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

Variant DiscordUserHandle::game_activity() {
	auto r = obj->GameActivity();

	Variant cr;

	if (!r.has_value()) {
		cr = nullptr;
	} else {
		auto r_v = r.value();

		discordpp::Activity *cr_v_t = memnew(discordpp::Activity(std::move(r_v)));
		DiscordActivity *cr_v = memnew(DiscordActivity{ cr_v_t });

		cr = Variant(cr_v);
	}

	return cr;
}

Variant DiscordUserHandle::global_name() {
	auto r = obj->GlobalName();

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

bool DiscordUserHandle::is_provisional() {
	auto r = obj->IsProvisional();

	bool cr = r;
	return cr;
}

int64_t DiscordUserHandle::id() {
	auto r = obj->Id();

	int64_t cr = (int64_t)r;
	return cr;
}

// Overload functions.

// Binding.
void DiscordUserHandle::_bind_methods() {
	ClassDB::bind_method(D_METHOD("avatar"),
			&DiscordUserHandle::avatar);

	ClassDB::bind_method(D_METHOD("avatar_url", "animated_type", "static_type"),
			&DiscordUserHandle::avatar_url);

	ClassDB::bind_method(D_METHOD("display_name"),
			&DiscordUserHandle::display_name);

	ClassDB::bind_method(D_METHOD("game_activity"),
			&DiscordUserHandle::game_activity);

	ClassDB::bind_method(D_METHOD("global_name"),
			&DiscordUserHandle::global_name);

	ClassDB::bind_method(D_METHOD("id"),
			&DiscordUserHandle::id);

	ClassDB::bind_method(D_METHOD("is_provisional"),
			&DiscordUserHandle::is_provisional);

	ClassDB::bind_method(D_METHOD("relationship"),
			&DiscordUserHandle::relationship);

	ClassDB::bind_method(D_METHOD("status"),
			&DiscordUserHandle::status);

	ClassDB::bind_method(D_METHOD("user_application_profiles"),
			&DiscordUserHandle::user_application_profiles);

	ClassDB::bind_method(D_METHOD("username"),
			&DiscordUserHandle::username);

	ClassDB::bind_static_method("DiscordUserHandle", D_METHOD("avatar_type_to_string", "type"),
			&DiscordUserHandle::avatar_type_to_string);
}
