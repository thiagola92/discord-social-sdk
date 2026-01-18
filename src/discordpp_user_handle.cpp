
#include "discordpp_classes.h"

using namespace godot;

void DiscordppUserHandle::Drop() {
	obj->Drop();
}

Variant DiscordppUserHandle::Avatar() {
	auto r = obj->Avatar();

	if (!r.has_value()) {
		return nullptr;
	}

	return Variant(r.value().c_str());
}

String DiscordppUserHandle::AvatarTypeToString(DiscordppUserHandleAvatarType::Enum type) {
	discordpp::UserHandle::AvatarType p0 = (discordpp::UserHandle::AvatarType)type;

	return String(discordpp::UserHandle::AvatarTypeToString(p0).c_str());
}

String DiscordppUserHandle::AvatarUrl(DiscordppUserHandleAvatarType::Enum animatedType, DiscordppUserHandleAvatarType::Enum staticType) {
	discordpp::UserHandle::AvatarType p0 = (discordpp::UserHandle::AvatarType)animatedType;
	discordpp::UserHandle::AvatarType p1 = (discordpp::UserHandle::AvatarType)staticType;

	return String(obj->AvatarUrl(p0, p1).c_str());
}

String DiscordppUserHandle::DisplayName() {
	return String(obj->DisplayName().c_str());
}

Variant DiscordppUserHandle::GameActivity() {
	auto r = obj->GameActivity();

	if (!r.has_value()) {
		return nullptr;
	}

	discordpp::Activity *t_r = memnew(discordpp::Activity(std::move(r.value())));
	return Variant(memnew(DiscordppActivity{ t_r }));
}

Variant DiscordppUserHandle::GlobalName() {
	auto r = obj->GlobalName();

	if (!r.has_value()) {
		return nullptr;
	}

	return Variant(r.value().c_str());
}

int64_t DiscordppUserHandle::Id() {
	return obj->Id();
}

bool DiscordppUserHandle::IsProvisional() {
	return obj->IsProvisional();
}

DiscordppRelationshipHandle *DiscordppUserHandle::Relationship() {
	discordpp::RelationshipHandle r = obj->Relationship();
	discordpp::RelationshipHandle *t_r = memnew(discordpp::RelationshipHandle(std::move(r)));
	return memnew(DiscordppRelationshipHandle{ t_r });
}

DiscordppStatusType::Enum DiscordppUserHandle::Status() {
	return (DiscordppStatusType::Enum)obj->Status();
}

TypedArray<DiscordppUserApplicationProfileHandle> DiscordppUserHandle::UserApplicationProfiles() {
	auto r = obj->UserApplicationProfiles();
	TypedArray<DiscordppUserApplicationProfileHandle> t_r = TypedArray<DiscordppUserApplicationProfileHandle>();

	for (auto i : r) {
		discordpp::UserApplicationProfileHandle *t_i = memnew(discordpp::UserApplicationProfileHandle(std::move(i)));
		t_r.push_back(memnew(DiscordppUserApplicationProfileHandle{ t_i }));
	}

	return t_r;
}

String DiscordppUserHandle::Username() {
	return String(obj->Username().c_str());
}

void DiscordppUserHandle::_bind_methods() {
	ClassDB::bind_method(D_METHOD("Drop"),
			&DiscordppUserHandle::Drop);

	ClassDB::bind_method(D_METHOD("Avatar"),
			&DiscordppUserHandle::Avatar);

	ClassDB::bind_static_method("DiscordppUserHandle", D_METHOD("AvatarTypeToString", "type"),
			&DiscordppUserHandle::AvatarTypeToString);

	ClassDB::bind_method(D_METHOD("AvatarUrl", "animatedType", "staticType"),
			&DiscordppUserHandle::AvatarUrl);

	ClassDB::bind_method(D_METHOD("DisplayName"),
			&DiscordppUserHandle::DisplayName);

	ClassDB::bind_method(D_METHOD("GameActivity"),
			&DiscordppUserHandle::GameActivity);

	ClassDB::bind_method(D_METHOD("GlobalName"),
			&DiscordppUserHandle::GlobalName);

	ClassDB::bind_method(D_METHOD("Id"),
			&DiscordppUserHandle::Id);

	ClassDB::bind_method(D_METHOD("IsProvisional"),
			&DiscordppUserHandle::IsProvisional);

	ClassDB::bind_method(D_METHOD("Relationship"),
			&DiscordppUserHandle::Relationship);

	ClassDB::bind_method(D_METHOD("Status"),
			&DiscordppUserHandle::Status);

	ClassDB::bind_method(D_METHOD("UserApplicationProfiles"),
			&DiscordppUserHandle::UserApplicationProfiles);

	ClassDB::bind_method(D_METHOD("Username"),
			&DiscordppUserHandle::Username);
}
