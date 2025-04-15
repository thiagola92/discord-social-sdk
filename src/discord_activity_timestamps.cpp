
#include "discord_classes.h"

using namespace godot;

void DiscordppActivityTimestamps::Drop() {
	obj->Drop();
}

uint64_t DiscordppActivityTimestamps::Start() {
	return obj->Start();
}

void DiscordppActivityTimestamps::SetStart(uint64_t Start) {
	auto p0 = Start;
	obj->SetStart(p0);
}

uint64_t DiscordppActivityTimestamps::End() {
	return obj->End();
}

void DiscordppActivityTimestamps::SetEnd(uint64_t End) {
	auto p0 = End;
	obj->SetEnd(p0);
}

void DiscordppActivityTimestamps::_bind_methods() {
	ClassDB::bind_method(D_METHOD("Drop"),
			&DiscordppActivityTimestamps::Drop);

	ClassDB::bind_method(D_METHOD("Start"),
			&DiscordppActivityTimestamps::Start);

	ClassDB::bind_method(D_METHOD("SetStart", "Start"),
			&DiscordppActivityTimestamps::SetStart);

	ClassDB::bind_method(D_METHOD("End"),
			&DiscordppActivityTimestamps::End);

	ClassDB::bind_method(D_METHOD("SetEnd", "End"),
			&DiscordppActivityTimestamps::SetEnd);
}
