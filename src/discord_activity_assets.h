#ifndef DISCORD_ACTIVITY_ASSETS_H
#define DISCORD_ACTIVITY_ASSETS_H

#include "discordpp.h"
#include "godot_cpp/classes/ref_counted.hpp"

namespace godot {

class DiscordActivityAssets : public RefCounted {
	GDCLASS(DiscordActivityAssets, RefCounted)

private:
	discordpp::ActivityAssets activity_assets;

protected:
	static void _bind_methods();

public:
	discordpp::ActivityAssets *unwrap(); // Internal usage.

	DiscordActivityAssets();
	~DiscordActivityAssets();
};

} //namespace godot

#endif
