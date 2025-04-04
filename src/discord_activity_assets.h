// AUTO-GENERATED
#ifndef DISCORD_ACTIVITY_ASSETS_H
#define DISCORD_ACTIVITY_ASSETS_H

#include "discordpp.h"
#include "godot_cpp/classes/ref_counted.hpp"
#include "godot_cpp/variant/typed_array.hpp"
#include "godot_cpp/variant/typed_dictionary.hpp"

namespace godot {

class DiscordActivityAssets : public RefCounted {
	GDCLASS(DiscordActivityAssets, RefCounted)

private:
	discordpp::ActivityAssets *activity_assets;

protected:
	static void _bind_methods();

public:
	discordpp::ActivityAssets *unwrap(); // Internal usage.

	Variant large_image();
	void set_large_image(Variant large_image);
	Variant large_text();
	void set_large_text(Variant large_text);
	Variant small_image();
	void set_small_image(Variant small_image);
	Variant small_text();
	void set_small_text(Variant small_text);

	DiscordActivityAssets();
	DiscordActivityAssets(discordpp::ActivityAssets *activity_assets);
	~DiscordActivityAssets();
};

} //namespace godot

#endif
