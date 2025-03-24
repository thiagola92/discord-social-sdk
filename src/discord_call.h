#ifndef DISCORD_CALL_H
#define DISCORD_CALL_H

#include "discordpp.h"
#include "godot_cpp/classes/ref_counted.hpp"

namespace godot {

class DiscordCall : public RefCounted {
	GDCLASS(DiscordCall, RefCounted)

    DiscordCall();

private:
	discordpp::Call *call;

protected:
	static void _bind_methods();

public:
	discordpp::Call *unwrap(); // Internal usage.

	DiscordCall(discordpp::Call *call);
	~DiscordCall();
};

} //namespace godot

#endif
