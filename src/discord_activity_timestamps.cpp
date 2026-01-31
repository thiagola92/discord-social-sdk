
#include "discord_classes.h"

using namespace godot;

// Functions.

int64_t DiscordActivityTimestamps::end() {
}

int64_t DiscordActivityTimestamps::start() {
}

void DiscordActivityTimestamps::set_end(int64_t end) {
	int64_t p0 = end;
}

void DiscordActivityTimestamps::set_start(int64_t start) {
	int64_t p0 = start;
}

// Overload functions.

// Binding.
void DiscordActivityTimestamps::_bind_methods() {
	ClassDB::bind_method(D_METHOD("end"),
			&DiscordActivityTimestamps::end);

	ClassDB::bind_method(D_METHOD("set_end", "end"),
			&DiscordActivityTimestamps::set_end);

	ClassDB::bind_method(D_METHOD("set_start", "start"),
			&DiscordActivityTimestamps::set_start);

	ClassDB::bind_method(D_METHOD("start"),
			&DiscordActivityTimestamps::start);
}
