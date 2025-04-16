
#include "discord_classes.h"

using namespace godot;

void DiscordppChannelHandle::Drop() {
	obj->Drop();
}

int64_t DiscordppChannelHandle::Id() {
	return obj->Id();
}

String DiscordppChannelHandle::Name() {
	return String(obj->Name().c_str());
}

TypedArray<int64_t> DiscordppChannelHandle::Recipients() {
	auto r = obj->Recipients();
	TypedArray<int64_t> t_r = TypedArray<int64_t>();

	for (auto i : r) {
		t_r.push_back((int64_t)i);
	}

	return t_r;
}

DiscordppChannelType::Enum DiscordppChannelHandle::Type() {
	return (DiscordppChannelType::Enum)obj->Type();
}

void DiscordppChannelHandle::_bind_methods() {
	ClassDB::bind_method(D_METHOD("Drop"),
			&DiscordppChannelHandle::Drop);

	ClassDB::bind_method(D_METHOD("Id"),
			&DiscordppChannelHandle::Id);

	ClassDB::bind_method(D_METHOD("Name"),
			&DiscordppChannelHandle::Name);

	ClassDB::bind_method(D_METHOD("Recipients"),
			&DiscordppChannelHandle::Recipients);

	ClassDB::bind_method(D_METHOD("Type"),
			&DiscordppChannelHandle::Type);
}
