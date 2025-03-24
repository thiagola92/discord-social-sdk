#ifndef DISCORD_CLIENT_RESULT_H
#define DISCORD_CLIENT_RESULT_H

#include "discordpp.h"
#include "godot_cpp/classes/ref_counted.hpp"

namespace godot {

class DiscordClientResult : public RefCounted {
	GDCLASS(DiscordClientResult, RefCounted)

private:
	discordpp::ClientResult client_result;

protected:
	static void _bind_methods();

public:
	discordpp::ClientResult *unwrap(); // Internal usage.

	DiscordClientResult();
	~DiscordClientResult();
};

} //namespace godot

#endif
