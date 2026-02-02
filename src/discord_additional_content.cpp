
#include "discord_classes.h"

using namespace godot;

// Functions.

DiscordAdditionalContentType::Enum DiscordAdditionalContent::type() {
	auto r = obj->Type();
}

String DiscordAdditionalContent::type_to_string(DiscordAdditionalContentType::Enum type) {
	discordpp::AdditionalContentType p0 = (discordpp::AdditionalContentType)type;
	auto r = discordpp::AdditionalContent::TypeToString(p0);
}

Variant DiscordAdditionalContent::title() {
	auto r = obj->Title();
}

bool DiscordAdditionalContent::equals(DiscordAdditionalContent *rhs) {
	discordpp::AdditionalContent p0 = *rhs->unwrap();
	auto r = obj->Equals(p0);
}

int64_t DiscordAdditionalContent::count() {
	auto r = obj->Count();
}

void DiscordAdditionalContent::set_count(int64_t count) {
	int64_t p0 = count;
	obj->SetCount(p0);
}

void DiscordAdditionalContent::set_title(Variant title) {
	std::optional<std::string> p0;

	if (title.get_type() == Variant::STRING) {
		p0 = title.stringify().utf8().get_data();
	}

	obj->SetTitle(p0);
}

void DiscordAdditionalContent::set_type(DiscordAdditionalContentType::Enum type) {
	discordpp::AdditionalContentType p0 = (discordpp::AdditionalContentType)type;
	obj->SetType(p0);
}

// Overload functions.

// Binding.
void DiscordAdditionalContent::_bind_methods() {
	ClassDB::bind_method(D_METHOD("count"),
			&DiscordAdditionalContent::count);

	ClassDB::bind_method(D_METHOD("equals", "rhs"),
			&DiscordAdditionalContent::equals);

	ClassDB::bind_method(D_METHOD("set_count", "count"),
			&DiscordAdditionalContent::set_count);

	ClassDB::bind_method(D_METHOD("set_title", "title"),
			&DiscordAdditionalContent::set_title);

	ClassDB::bind_method(D_METHOD("set_type", "type"),
			&DiscordAdditionalContent::set_type);

	ClassDB::bind_method(D_METHOD("title"),
			&DiscordAdditionalContent::title);

	ClassDB::bind_method(D_METHOD("type"),
			&DiscordAdditionalContent::type);

	ClassDB::bind_static_method("DiscordAdditionalContent", D_METHOD("type_to_string", "type"),
			&DiscordAdditionalContent::type_to_string);
}
