// AUTO-GENERATED
#ifndef DISCORD_VADTHRESHOLD_SETTINGS_H
#define DISCORD_VADTHRESHOLD_SETTINGS_H

#include "discordpp.h"
#include "godot_cpp/classes/ref_counted.hpp"
#include "godot_cpp/variant/typed_array.hpp"
#include "godot_cpp/variant/typed_dictionary.hpp"

namespace godot {

class DiscordVADThresholdSettings : public RefCounted {
	GDCLASS(DiscordVADThresholdSettings, RefCounted)

private:
	discordpp::VADThresholdSettings *vadthreshold_settings;

	DiscordVADThresholdSettings();

protected:
	static void _bind_methods();

public:
	discordpp::VADThresholdSettings *unwrap(); // Internal usage.

	float vad_threshold();
	void set_vad_threshold(float vad_threshold);
	bool automatic();
	void set_automatic(bool automatic);

	DiscordVADThresholdSettings(discordpp::VADThresholdSettings *vadthreshold_settings);
	~DiscordVADThresholdSettings();
};

} //namespace godot

#endif
