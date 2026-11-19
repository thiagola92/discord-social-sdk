
#include "discord_classes.h"

using namespace godot;

// Functions.

DiscordDiscordClientGuildVoiceSpeakingState::Enum DiscordDiscordClientGuildVoiceMember::speaking() {
	auto r0 = obj->Speaking();

	DiscordDiscordClientGuildVoiceSpeakingState::Enum r1 = (DiscordDiscordClientGuildVoiceSpeakingState::Enum)r0;

	return r1;
}

String DiscordDiscordClientGuildVoiceMember::display_name() {
	auto r0 = obj->DisplayName();

	String r1 = String::utf8(r0.c_str(), r0.length());

	return r1;
}

String DiscordDiscordClientGuildVoiceMember::username() {
	auto r0 = obj->Username();

	String r1 = String::utf8(r0.c_str(), r0.length());

	return r1;
}

Variant DiscordDiscordClientGuildVoiceMember::avatar_hash() {
	auto r0 = obj->AvatarHash();

	Variant r1;

	if (!r0.has_value()) {
		r1 = nullptr;
	} else {
		auto r0_v = r0.value();
		String r1_v = String::utf8(r0_v.c_str(), r0_v.length());
		r1 = Variant(r1_v);
	}

	return r1;
}

bool DiscordDiscordClientGuildVoiceMember::deaf() {
	auto r0 = obj->Deaf();

	bool r1 = r0;

	return r1;
}

bool DiscordDiscordClientGuildVoiceMember::mute() {
	auto r0 = obj->Mute();

	bool r1 = r0;

	return r1;
}

bool DiscordDiscordClientGuildVoiceMember::self_deaf() {
	auto r0 = obj->SelfDeaf();

	bool r1 = r0;

	return r1;
}

bool DiscordDiscordClientGuildVoiceMember::self_mute() {
	auto r0 = obj->SelfMute();

	bool r1 = r0;

	return r1;
}

int64_t DiscordDiscordClientGuildVoiceMember::user_id() {
	auto r0 = obj->UserId();

	int64_t r1 = (int64_t)r0;

	return r1;
}

void DiscordDiscordClientGuildVoiceMember::set_avatar_hash(Variant avatar_hash) {
	std::optional<std::string> p0;

	if (avatar_hash.get_type() == Variant::STRING) {
		p0 = avatar_hash.stringify().utf8().get_data();
	} else if (avatar_hash.get_type() != Variant::NIL) {
		ERR_PRINT("Invalid type passed as argument");
	}

	obj->SetAvatarHash(p0);
}

void DiscordDiscordClientGuildVoiceMember::set_deaf(bool deaf) {
	bool p0 = deaf;
	obj->SetDeaf(p0);
}

void DiscordDiscordClientGuildVoiceMember::set_display_name(String display_name) {
	std::string p0 = std::string(display_name.utf8().get_data());
	obj->SetDisplayName(p0);
}

void DiscordDiscordClientGuildVoiceMember::set_mute(bool mute) {
	bool p0 = mute;
	obj->SetMute(p0);
}

void DiscordDiscordClientGuildVoiceMember::set_self_deaf(bool self_deaf) {
	bool p0 = self_deaf;
	obj->SetSelfDeaf(p0);
}

void DiscordDiscordClientGuildVoiceMember::set_self_mute(bool self_mute) {
	bool p0 = self_mute;
	obj->SetSelfMute(p0);
}

void DiscordDiscordClientGuildVoiceMember::set_speaking(DiscordDiscordClientGuildVoiceSpeakingState::Enum speaking) {
	discordpp::DiscordClientGuildVoiceSpeakingState p0 = (discordpp::DiscordClientGuildVoiceSpeakingState)speaking;
	obj->SetSpeaking(p0);
}

void DiscordDiscordClientGuildVoiceMember::set_user_id(int64_t user_id) {
	int64_t p0 = user_id;
	obj->SetUserId(p0);
}

void DiscordDiscordClientGuildVoiceMember::set_username(String username) {
	std::string p0 = std::string(username.utf8().get_data());
	obj->SetUsername(p0);
}

// Overload functions.

// Binding.
void DiscordDiscordClientGuildVoiceMember::_bind_methods() {
	ClassDB::bind_method(D_METHOD("avatar_hash"),
			&DiscordDiscordClientGuildVoiceMember::avatar_hash);

	ClassDB::bind_method(D_METHOD("deaf"),
			&DiscordDiscordClientGuildVoiceMember::deaf);

	ClassDB::bind_method(D_METHOD("display_name"),
			&DiscordDiscordClientGuildVoiceMember::display_name);

	ClassDB::bind_method(D_METHOD("mute"),
			&DiscordDiscordClientGuildVoiceMember::mute);

	ClassDB::bind_method(D_METHOD("self_deaf"),
			&DiscordDiscordClientGuildVoiceMember::self_deaf);

	ClassDB::bind_method(D_METHOD("self_mute"),
			&DiscordDiscordClientGuildVoiceMember::self_mute);

	ClassDB::bind_method(D_METHOD("set_avatar_hash", "avatar_hash"),
			&DiscordDiscordClientGuildVoiceMember::set_avatar_hash);

	ClassDB::bind_method(D_METHOD("set_deaf", "deaf"),
			&DiscordDiscordClientGuildVoiceMember::set_deaf);

	ClassDB::bind_method(D_METHOD("set_display_name", "display_name"),
			&DiscordDiscordClientGuildVoiceMember::set_display_name);

	ClassDB::bind_method(D_METHOD("set_mute", "mute"),
			&DiscordDiscordClientGuildVoiceMember::set_mute);

	ClassDB::bind_method(D_METHOD("set_self_deaf", "self_deaf"),
			&DiscordDiscordClientGuildVoiceMember::set_self_deaf);

	ClassDB::bind_method(D_METHOD("set_self_mute", "self_mute"),
			&DiscordDiscordClientGuildVoiceMember::set_self_mute);

	ClassDB::bind_method(D_METHOD("set_speaking", "speaking"),
			&DiscordDiscordClientGuildVoiceMember::set_speaking);

	ClassDB::bind_method(D_METHOD("set_user_id", "user_id"),
			&DiscordDiscordClientGuildVoiceMember::set_user_id);

	ClassDB::bind_method(D_METHOD("set_username", "username"),
			&DiscordDiscordClientGuildVoiceMember::set_username);

	ClassDB::bind_method(D_METHOD("speaking"),
			&DiscordDiscordClientGuildVoiceMember::speaking);

	ClassDB::bind_method(D_METHOD("user_id"),
			&DiscordDiscordClientGuildVoiceMember::user_id);

	ClassDB::bind_method(D_METHOD("username"),
			&DiscordDiscordClientGuildVoiceMember::username);
}
