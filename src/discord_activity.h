// AUTO-GENERATED
#ifndef DISCORD_ACTIVITY_H
#define DISCORD_ACTIVITY_H

#include "discord_activity_assets.h"
#include "discord_activity_party.h"
#include "discord_activity_secrets.h"
#include "discord_activity_timestamps.h"
#include "discord_enum.h"
#include "discordpp.h"
#include "godot_cpp/classes/ref_counted.hpp"

namespace godot {

class DiscordActivity : public RefCounted {
	GDCLASS(DiscordActivity, RefCounted)

private:
	discordpp::Activity activity;

protected:
	static void _bind_methods();

public:
	discordpp::Activity *unwrap(); // Internal usage.

	String name();
	void set_name(String name);
	DiscordActivityTypes::Enum type();
	void set_type(DiscordActivityTypes::Enum type);
	Variant state();
	void set_state(Variant state);
	Variant details();
	void set_details(Variant details);
	Variant application_id();
	void set_application_id(Variant application_id);
	Variant assets();
	void set_assets(Variant assets);
	Variant timestamps();
	void set_timestamps(Variant timestamps);
	Variant party();
	void set_party(Variant party);
	Variant secrets();
	void set_secrets(Variant secrets);
	DiscordActivityGamePlatforms::Enum supported_platforms();
	void set_supported_platforms(DiscordActivityGamePlatforms::Enum supported_platforms);

	DiscordActivity();
	DiscordActivity(discordpp::Activity activity);
	~DiscordActivity();
};

} //namespace godot

#endif
