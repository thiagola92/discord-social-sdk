#ifndef DISCORD_AUTHORIZATION_ARGS_H
#define DISCORD_AUTHORIZATION_ARGS_H

#include <discordpp.h>
#include <godot_cpp/classes/ref_counted.hpp>
#include <godot_cpp/classes/wrapped.hpp>

namespace godot {

class DiscordAuthorizationArgs : public RefCounted {
	GDCLASS(DiscordAuthorizationArgs, RefCounted)

private:
	discordpp::AuthorizationArgs args;

protected:
	static void _bind_methods();

public:
	uint64_t get_client_id();
	void set_client_id(uint64_t client_id);

	String get_scopes();
	void set_scopes(String scopes);

	Variant get_state();
	void set_state(Variant state);

	Variant get_nonce();
	void set_nonce(Variant nonce);

	Variant get_code_challenge();
	void set_code_challenge(Variant code_challenge);

	DiscordAuthorizationArgs();
	~DiscordAuthorizationArgs();
};

} // namespace godot

#endif
