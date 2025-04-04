// AUTO-GENERATED
#include "discord_additional_content.h"

using namespace godot;

discordpp::AdditionalContent *DiscordAdditionalContent::unwrap() {
	return &additional_content;
}

bool DiscordAdditionalContent::equals(DiscordAdditionalContent *rhs) {
	auto p0 = *rhs->unwrap();
	auto r = additional_content.Equals(p0);
	return r;
}

DiscordAdditionalContentType::Enum DiscordAdditionalContent::type() {
	auto r = additional_content.Type();
	return (DiscordAdditionalContentType::Enum)r;
}

void DiscordAdditionalContent::set_type(DiscordAdditionalContentType::Enum type) {
	auto p0 = (discordpp::AdditionalContentType)type;
	additional_content.SetType(p0);
}

Variant DiscordAdditionalContent::title() {
	auto r = additional_content.Title();

	if (!r.has_value()) {
		return nullptr;
	}

	return Variant(r.value().c_str());
}

void DiscordAdditionalContent::set_title(Variant title) {
	std::optional<std::string> p0;

	if (title.get_type() == Variant::STRING) {
		p0 = title.stringify().utf8().get_data();
	}

	additional_content.SetTitle(p0);
}

uint8_t DiscordAdditionalContent::count() {
	auto r = additional_content.Count();
	return r;
}

void DiscordAdditionalContent::set_count(uint8_t count) {
	additional_content.SetCount(count);
}

void DiscordAdditionalContent::_bind_methods() {
	ClassDB::bind_method(D_METHOD("equals", "rhs"),
			&DiscordAdditionalContent::equals);

	ClassDB::bind_method(D_METHOD("type"),
			&DiscordAdditionalContent::type);

	ClassDB::bind_method(D_METHOD("set_type", "type"),
			&DiscordAdditionalContent::set_type);

	ClassDB::bind_method(D_METHOD("title"),
			&DiscordAdditionalContent::title);

	ClassDB::bind_method(D_METHOD("set_title", "title"),
			&DiscordAdditionalContent::set_title);

	ClassDB::bind_method(D_METHOD("count"),
			&DiscordAdditionalContent::count);

	ClassDB::bind_method(D_METHOD("set_count", "count"),
			&DiscordAdditionalContent::set_count);
}

DiscordAdditionalContent::DiscordAdditionalContent() {}

DiscordAdditionalContent::DiscordAdditionalContent(discordpp::AdditionalContent additional_content) {
	this->additional_content = additional_content;
}

DiscordAdditionalContent::~DiscordAdditionalContent() {}
