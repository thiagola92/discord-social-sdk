
#include "discord_classes.h"

using namespace godot;

// Functions.

DiscordRelationshipHandle *DiscordUserHandle::relationship() {
	auto r0 = obj->Relationship();

	discordpp::RelationshipHandle *r1_t = memnew(discordpp::RelationshipHandle(std::move(r0)));
	DiscordRelationshipHandle *r1 = memnew(DiscordRelationshipHandle{ r1_t });

	return r1;
}

DiscordStatusType::Enum DiscordUserHandle::status() {
	auto r0 = obj->Status();

	DiscordStatusType::Enum r1 = (DiscordStatusType::Enum)r0;

	return r1;
}

String DiscordUserHandle::avatar_type_to_string(DiscordUserHandleAvatarType::Enum type) {
	discordpp::UserHandle::AvatarType p0 = (discordpp::UserHandle::AvatarType)type;
	auto r0 = discordpp::UserHandle::AvatarTypeToString(p0);

	String r1 = String(r0.c_str());

	return r1;
}

String DiscordUserHandle::avatar_url(DiscordUserHandleAvatarType::Enum animated_type, DiscordUserHandleAvatarType::Enum static_type) {
	discordpp::UserHandle::AvatarType p0 = (discordpp::UserHandle::AvatarType)animated_type;
	discordpp::UserHandle::AvatarType p1 = (discordpp::UserHandle::AvatarType)static_type;
	auto r0 = obj->AvatarUrl(p0, p1);

	String r1 = String(r0.c_str());

	return r1;
}

String DiscordUserHandle::display_name() {
	auto r0 = obj->DisplayName();

	String r1 = String(r0.c_str());

	return r1;
}

String DiscordUserHandle::username() {
	auto r0 = obj->Username();

	String r1 = String(r0.c_str());

	return r1;
}

TypedArray<DiscordUserApplicationProfileHandle> DiscordUserHandle::user_application_profiles() {
	auto r0 = obj->UserApplicationProfiles();

	TypedArray<DiscordUserApplicationProfileHandle> r1 = TypedArray<DiscordUserApplicationProfileHandle>();

	for (auto i : r0) {
		discordpp::UserApplicationProfileHandle *r1_t_t = memnew(discordpp::UserApplicationProfileHandle(std::move(i)));
		DiscordUserApplicationProfileHandle *r1_t = memnew(DiscordUserApplicationProfileHandle{ r1_t_t });

		r1.push_back(r1_t);
	}

	return r1;
}

Variant DiscordUserHandle::avatar() {
	auto r0 = obj->Avatar();

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

Variant DiscordUserHandle::game_activity() {
	auto r0 = obj->GameActivity();

	Variant r1;

	if (!r0.has_value()) {
		r1 = nullptr;
	} else {
		auto r0_v = r0.value();

		discordpp::Activity *r1_v_t = memnew(discordpp::Activity(std::move(r0_v)));
		DiscordActivity *r1_v = memnew(DiscordActivity{ r1_v_t });

		r1 = Variant(r1_v);
	}

	return r1;
}

Variant DiscordUserHandle::global_name() {
	auto r0 = obj->GlobalName();

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

bool DiscordUserHandle::is_provisional() {
	auto r0 = obj->IsProvisional();

	bool r1 = r0;

	return r1;
}

int64_t DiscordUserHandle::id() {
	auto r0 = obj->Id();

	int64_t r1 = (int64_t)r0;

	return r1;
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
