// AUTO-GENERATED
#ifndef DISCORD_ACTIVITY_INVITE_H
#define DISCORD_ACTIVITY_INVITE_H

#include "discord_enum.h"
#include "discordpp.h"
#include "godot_cpp/classes/ref_counted.hpp"
#include "godot_cpp/variant/typed_array.hpp"
#include "godot_cpp/variant/typed_dictionary.hpp"

namespace godot {

class DiscordActivityInvite : public RefCounted {
	GDCLASS(DiscordActivityInvite, RefCounted)

private:
	discordpp::ActivityInvite *activity_invite;

protected:
	static void _bind_methods();

public:
	discordpp::ActivityInvite *unwrap(); // Internal usage.

	uint64_t sender_id();
	void set_sender_id(uint64_t sender_id);
	uint64_t channel_id();
	void set_channel_id(uint64_t channel_id);
	uint64_t message_id();
	void set_message_id(uint64_t message_id);
	DiscordActivityActionTypes::Enum type();
	void set_type(DiscordActivityActionTypes::Enum type);
	uint64_t application_id();
	void set_application_id(uint64_t application_id);
	String party_id();
	void set_party_id(String party_id);
	bool is_valid();
	void set_is_valid(bool is_valid);

	DiscordActivityInvite();
	DiscordActivityInvite(discordpp::ActivityInvite *activity_invite);
	~DiscordActivityInvite();
};

} //namespace godot

#endif
