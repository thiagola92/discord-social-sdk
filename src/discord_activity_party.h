// AUTO-GENERATED
#ifndef DISCORD_ACTIVITY_PARTY_H
#define DISCORD_ACTIVITY_PARTY_H

#include "discord_enum.h"
#include "discordpp.h"
#include "godot_cpp/classes/ref_counted.hpp"
#include "godot_cpp/variant/typed_array.hpp"
#include "godot_cpp/variant/typed_dictionary.hpp"

namespace godot {

class DiscordActivityParty : public RefCounted {
	GDCLASS(DiscordActivityParty, RefCounted)

private:
	discordpp::ActivityParty *activity_party;

protected:
	static void _bind_methods();

public:
	discordpp::ActivityParty *unwrap(); // Internal usage.

	String id();
	void set_id(String id);
	int32_t current_size();
	void set_current_size(int32_t current_size);
	int32_t max_size();
	void set_max_size(int32_t max_size);
	DiscordActivityPartyPrivacy::Enum privacy();
	void set_privacy(DiscordActivityPartyPrivacy::Enum privacy);

	DiscordActivityParty();
	DiscordActivityParty(discordpp::ActivityParty *activity_party);
	~DiscordActivityParty();
};

} //namespace godot

#endif
