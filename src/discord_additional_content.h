// AUTO-GENERATED
#ifndef DISCORD_ADDITIONAL_CONTENT_H
#define DISCORD_ADDITIONAL_CONTENT_H

#include "discord_additional_content.h"
#include "discord_enum.h"
#include "discordpp.h"
#include "godot_cpp/classes/ref_counted.hpp"
#include "godot_cpp/variant/typed_array.hpp"
#include "godot_cpp/variant/typed_dictionary.hpp"

namespace godot {

class DiscordAdditionalContent : public RefCounted {
	GDCLASS(DiscordAdditionalContent, RefCounted)

private:
	discordpp::AdditionalContent *additional_content;

protected:
	static void _bind_methods();

public:
	discordpp::AdditionalContent *unwrap(); // Internal usage.

	bool equals(DiscordAdditionalContent *rhs);
	DiscordAdditionalContentType::Enum type();
	void set_type(DiscordAdditionalContentType::Enum type);
	Variant title();
	void set_title(Variant title);
	uint8_t count();
	void set_count(uint8_t count);

	DiscordAdditionalContent();
	DiscordAdditionalContent(discordpp::AdditionalContent *additional_content);
	~DiscordAdditionalContent();
};

} //namespace godot

#endif
