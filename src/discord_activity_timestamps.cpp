// AUTO-GENERATED
#include "discord_activity_timestamps.h"

using namespace godot;

discordpp::ActivityTimestamps *DiscordActivityTimestamps::unwrap() {
	return activity_timestamps;
}

uint64_t DiscordActivityTimestamps::start() {
	auto r = activity_timestamps->Start();
	return r;
}

void DiscordActivityTimestamps::set_start(uint64_t start) {
	activity_timestamps->SetStart(start);
}

uint64_t DiscordActivityTimestamps::end() {
	auto r = activity_timestamps->End();
	return r;
}

void DiscordActivityTimestamps::set_end(uint64_t end) {
	activity_timestamps->SetEnd(end);
}

void DiscordActivityTimestamps::_bind_methods() {
	ClassDB::bind_method(D_METHOD("start"),
			&DiscordActivityTimestamps::start);

	ClassDB::bind_method(D_METHOD("set_start", "start"),
			&DiscordActivityTimestamps::set_start);

	ClassDB::bind_method(D_METHOD("end"),
			&DiscordActivityTimestamps::end);

	ClassDB::bind_method(D_METHOD("set_end", "end"),
			&DiscordActivityTimestamps::set_end);
}

DiscordActivityTimestamps::DiscordActivityTimestamps() {
	this->activity_timestamps = memnew(discordpp::ActivityTimestamps);
}

DiscordActivityTimestamps::DiscordActivityTimestamps(discordpp::ActivityTimestamps *activity_timestamps) {
	this->activity_timestamps = activity_timestamps;
}

DiscordActivityTimestamps::~DiscordActivityTimestamps() {}
