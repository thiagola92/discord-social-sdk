// AUTO-GENERATED
#include "discord_classes.h"

using namespace godot;

discordpp::ActivitySecrets *DiscordActivitySecrets::unwrap() {
	return activity_secrets;
}

String DiscordActivitySecrets::join() {
	auto r = activity_secrets->Join();
	return String(r.c_str());
}

void DiscordActivitySecrets::set_join(String join) {
	auto p0 = join.utf8().get_data();
	activity_secrets->SetJoin(p0);
}

void DiscordActivitySecrets::_bind_methods() {
	ClassDB::bind_method(D_METHOD("join"),
			&DiscordActivitySecrets::join);

	ClassDB::bind_method(D_METHOD("set_join", "join"),
			&DiscordActivitySecrets::set_join);
}

DiscordActivitySecrets::DiscordActivitySecrets() {
	this->activity_secrets = memnew(discordpp::ActivitySecrets);
}

DiscordActivitySecrets::DiscordActivitySecrets(discordpp::ActivitySecrets *activity_secrets) {
	this->activity_secrets = activity_secrets;
}

DiscordActivitySecrets::~DiscordActivitySecrets() {}
