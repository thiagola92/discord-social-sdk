
#include "discord_classes.h"

using namespace godot;

// Functions.

DiscordChannelType::Enum DiscordChannelHandle::type() {
	auto r0 = obj->Type();

	DiscordChannelType::Enum r1 = (DiscordChannelType::Enum)r0;

	return r1;
}

String DiscordChannelHandle::name() {
	auto r0 = obj->Name();

	String r1 = String(r0.c_str());

	return r1;
}

TypedArray<int64_t> DiscordChannelHandle::recipients() {
	auto r0 = obj->Recipients();

	TypedArray<int64_t> r1 = TypedArray<int64_t>();

	for (auto i : r0) {
		int64_t r1_t = (int64_t)i;
		r1.push_back(r1_t);
	}

	return r1;
}

int64_t DiscordChannelHandle::id() {
	auto r0 = obj->Id();

	int64_t r1 = (int64_t)r0;

	return r1;
}

// Overload functions.

// Binding.
void DiscordChannelHandle::_bind_methods() {
	ClassDB::bind_method(D_METHOD("id"),
			&DiscordChannelHandle::id);

	ClassDB::bind_method(D_METHOD("name"),
			&DiscordChannelHandle::name);

	ClassDB::bind_method(D_METHOD("recipients"),
			&DiscordChannelHandle::recipients);

	ClassDB::bind_method(D_METHOD("type"),
			&DiscordChannelHandle::type);
}
