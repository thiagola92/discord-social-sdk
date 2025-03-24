#ifndef DISCORD_VADTHRESHOLD_SETTINGS_H
#define DISCORD_VADTHRESHOLD_SETTINGS_H

#include "discordpp.h"
#include "godot_cpp/classes/ref_counted.hpp"

namespace godot {

class DiscordVADThresholdSettings : public RefCounted {
	GDCLASS(DiscordVADThresholdSettings, RefCounted)

private:
	discordpp::VADThresholdSettings *vadthreshold_settings;

protected:
	static void _bind_methods();

public:
	discordpp::VADThresholdSettings *unwrap(); // Internal usage.

	// DiscordVADThresholdSettings();
	~DiscordVADThresholdSettings();
};

} //namespace godot

#endif
