#ifndef DISCORD_CLIENT_RESULT_H
#define DISCORD_CLIENT_RESULT_H

#include "discord_enum.h"
#include "discordpp.h"
#include "godot_cpp/classes/ref_counted.hpp"

namespace godot {

class DiscordClientResult : public RefCounted {
	GDCLASS(DiscordClientResult, RefCounted)

	DiscordClientResult();

private:
	// Doesn't have empty contrusctor, needs to be a pointer.
	discordpp::ClientResult *client_result;

protected:
	static void _bind_methods();

public:
	discordpp::ClientResult *unwrap(); // Internal usage.

	String to_string();
	DiscordErrorType::Enum get_type();
	void set_type(DiscordErrorType::Enum type);
	String get_error();
	void set_error(String error);
	int32_t get_error_code();
	void set_error_code(int32_t error_code);
	DiscordHttpStatusCode::Enum get_status();
	void set_status(DiscordHttpStatusCode::Enum status);
	String get_response_body();
	void set_response_body(String response_body);
	bool get_successful();
	void set_successful(bool successful);
	bool get_retryable();
	void set_retryable(bool retryable);
	float get_retry_after();
	void set_retry_after(float retry_after);

	DiscordClientResult(discordpp::ClientResult *client_result);
	~DiscordClientResult();
};

} //namespace godot

#endif
