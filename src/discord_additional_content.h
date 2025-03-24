#ifndef DISCORD_ADDITIONAL_CONTENT_H
#define DISCORD_ADDITIONAL_CONTENT_H

#include "discordpp.h"
#include "godot_cpp/classes/ref_counted.hpp"

namespace godot {

class DiscordAdditionalContent : public RefCounted {
	GDCLASS(DiscordAdditionalContent, RefCounted)

private:
	discordpp::AdditionalContent additional_content;

protected:
	static void _bind_methods();

public:
	discordpp::AdditionalContent *unwrap(); // Internal usage.

	DiscordAdditionalContent();
	~DiscordAdditionalContent();
};

} //namespace godot

#endif
