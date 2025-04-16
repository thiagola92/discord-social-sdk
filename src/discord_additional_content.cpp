
#include "discord_classes.h"

using namespace godot;

void DiscordppAdditionalContent::Drop() {
	obj->Drop();
}

bool DiscordppAdditionalContent::Equals(Ref<DiscordppAdditionalContent> rhs) {
	auto p0 = *rhs->unwrap();

	return obj->Equals(p0);
}

String DiscordppAdditionalContent::TypeToString(DiscordppAdditionalContentType::Enum type) {
	auto p0 = (discordpp::AdditionalContentType)type;

	return String(obj->TypeToString(p0).c_str());
}

DiscordppAdditionalContentType::Enum DiscordppAdditionalContent::Type() {
	return (DiscordppAdditionalContentType::Enum)obj->Type();
}

void DiscordppAdditionalContent::SetType(DiscordppAdditionalContentType::Enum Type) {
	auto p0 = (discordpp::AdditionalContentType)Type;

	obj->SetType(p0);
}

Variant DiscordppAdditionalContent::Title() {
	auto r = obj->Title();

	if (!r.has_value()) {
		return nullptr;
	}

	return Variant(r.value().c_str());
}

void DiscordppAdditionalContent::SetTitle(Variant Title) {
	std::optional<std::string> p0;

	if (Title.get_type() == Variant::STRING) {
		p0 = Title.stringify().utf8().get_data();
	}

	obj->SetTitle(p0);
}

int64_t DiscordppAdditionalContent::Count() {
	return obj->Count();
}

void DiscordppAdditionalContent::SetCount(int64_t Count) {
	int64_t p0 = Count;

	obj->SetCount(p0);
}

void DiscordppAdditionalContent::_bind_methods() {
	ClassDB::bind_method(D_METHOD("Drop"),
			&DiscordppAdditionalContent::Drop);

	ClassDB::bind_method(D_METHOD("Equals", "rhs"),
			&DiscordppAdditionalContent::Equals);

	ClassDB::bind_method(D_METHOD("TypeToString", "type"),
			&DiscordppAdditionalContent::TypeToString);

	ClassDB::bind_method(D_METHOD("Type"),
			&DiscordppAdditionalContent::Type);

	ClassDB::bind_method(D_METHOD("SetType", "Type"),
			&DiscordppAdditionalContent::SetType);

	ClassDB::bind_method(D_METHOD("Title"),
			&DiscordppAdditionalContent::Title);

	ClassDB::bind_method(D_METHOD("SetTitle", "Title"),
			&DiscordppAdditionalContent::SetTitle);

	ClassDB::bind_method(D_METHOD("Count"),
			&DiscordppAdditionalContent::Count);

	ClassDB::bind_method(D_METHOD("SetCount", "Count"),
			&DiscordppAdditionalContent::SetCount);
}
