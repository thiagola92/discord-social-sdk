#include "discord_authorization_code_challenge.h"

#include <godot_cpp/core/class_db.hpp>
#include <string>

using namespace godot;

String DiscordAuthorizationCodeChallenge::get_challenge() {
	return String(code_challenge.Challenge().c_str());
}

void DiscordAuthorizationCodeChallenge::set_challenge(String challenge) {
	code_challenge.SetChallenge(challenge.utf8().get_data());
}

void DiscordAuthorizationCodeChallenge::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_challenge"),
			&DiscordAuthorizationCodeChallenge::get_challenge);
	ClassDB::bind_method(D_METHOD("set_challenge", "challenge"),
			&DiscordAuthorizationCodeChallenge::set_challenge);
}

DiscordAuthorizationCodeChallenge::DiscordAuthorizationCodeChallenge() {}

DiscordAuthorizationCodeChallenge::~DiscordAuthorizationCodeChallenge() {}