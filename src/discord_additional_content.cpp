
#include "discord_classes.h"

using namespace godot;

// Functions.

DiscordAdditionalContentType::Enum DiscordAdditionalContent::type() {
	auto r0 = obj->Type();

	DiscordAdditionalContentType::Enum r1 = (DiscordAdditionalContentType::Enum)r0;

	return r1;
}

String DiscordAdditionalContent::type_to_string(DiscordAdditionalContentType::Enum type) {
	discordpp::AdditionalContentType p0 = (discordpp::AdditionalContentType)type;
	auto r0 = discordpp::AdditionalContent::TypeToString(p0);

	String r1 = String(r0.c_str());

	return r1;
}

Variant DiscordAdditionalContent::title() {
	auto r0 = obj->Title();

	Variant r1;

	if (!r0.has_value()) {
		r1 = nullptr;
	} else {
		auto r0_v = r0.value();
		String r1_v = String(r0_v.c_str());
		r1 = Variant(r1_v);
	}

	return r1;
}

bool DiscordAdditionalContent::equals(DiscordAdditionalContent *rhs) {
	discordpp::AdditionalContent p0 = *rhs->unwrap();
	auto r0 = obj->Equals(p0);

	bool r1 = r0;

	return r1;
}

int64_t DiscordAdditionalContent::count() {
	auto r0 = obj->Count();

	int64_t r1 = (int64_t)r0;

	return r1;
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
