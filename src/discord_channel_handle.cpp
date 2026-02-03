
#include "discord_classes.h"

using namespace godot;

// Functions.

DiscordChannelType::Enum DiscordChannelHandle::type() {
	auto r = obj->Type();

	DiscordChannelType::Enum cr = (DiscordChannelType::Enum)r;
	return cr;
}

String DiscordChannelHandle::name() {
	auto r = obj->Name();

	String cr = String(r.c_str());
	return cr;
}

TypedArray<int64_t> DiscordChannelHandle::recipients() {
	auto r = obj->Recipients();

	TypedArray<int64_t> cr = TypedArray<int64_t>();

	for (auto i : r) {
		int64_t cr_t = (int64_t)i;
		cr.push_back(cr_t);
	}

	return cr;
}

int64_t DiscordChannelHandle::id() {
	auto r = obj->Id();

	int64_t cr = (int64_t)r;
	return cr;
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
