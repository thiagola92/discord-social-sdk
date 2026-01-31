
#include "discord_classes.h"

using namespace godot;

// Functions.

DiscordErrorType DiscordClientResult::type() {
}

DiscordHttpStatusCode DiscordClientResult::status() {
}

String DiscordClientResult::error() {
}

String DiscordClientResult::response_body() {
}

String DiscordClientResult::to_string_discord() {
}

bool DiscordClientResult::retryable() {
}

bool DiscordClientResult::successful() {
}

float DiscordClientResult::retry_after() {
}

int64_t DiscordClientResult::error_code() {
}

void DiscordClientResult::set_error(String error) {
	std::string p0 = std::string(error.utf8().get_data());
}

void DiscordClientResult::set_error_code(int64_t error_code) {
	int64_t p0 = error_code;
}

void DiscordClientResult::set_response_body(String response_body) {
	std::string p0 = std::string(response_body.utf8().get_data());
}

void DiscordClientResult::set_retry_after(float retry_after) {
	float p0 = retry_after;
}

void DiscordClientResult::set_retryable(bool retryable) {
	bool p0 = retryable;
}

void DiscordClientResult::set_status(DiscordHttpStatusCode status) {
	TODO
}

void DiscordClientResult::set_successful(bool successful) {
	bool p0 = successful;
}

void DiscordClientResult::set_type(DiscordErrorType type) {
	TODO
}

// Overload functions.

// Binding.
void DiscordClientResult::_bind_methods() {
	ClassDB::bind_method(D_METHOD("error"),
			&DiscordClientResult::error);

	ClassDB::bind_method(D_METHOD("error_code"),
			&DiscordClientResult::error_code);

	ClassDB::bind_method(D_METHOD("response_body"),
			&DiscordClientResult::response_body);

	ClassDB::bind_method(D_METHOD("retry_after"),
			&DiscordClientResult::retry_after);

	ClassDB::bind_method(D_METHOD("retryable"),
			&DiscordClientResult::retryable);

	ClassDB::bind_method(D_METHOD("set_error", "error"),
			&DiscordClientResult::set_error);

	ClassDB::bind_method(D_METHOD("set_error_code", "error_code"),
			&DiscordClientResult::set_error_code);

	ClassDB::bind_method(D_METHOD("set_response_body", "response_body"),
			&DiscordClientResult::set_response_body);

	ClassDB::bind_method(D_METHOD("set_retry_after", "retry_after"),
			&DiscordClientResult::set_retry_after);

	ClassDB::bind_method(D_METHOD("set_retryable", "retryable"),
			&DiscordClientResult::set_retryable);

	ClassDB::bind_method(D_METHOD("set_status", "status"),
			&DiscordClientResult::set_status);

	ClassDB::bind_method(D_METHOD("set_successful", "successful"),
			&DiscordClientResult::set_successful);

	ClassDB::bind_method(D_METHOD("set_type", "type"),
			&DiscordClientResult::set_type);

	ClassDB::bind_method(D_METHOD("status"),
			&DiscordClientResult::status);

	ClassDB::bind_method(D_METHOD("successful"),
			&DiscordClientResult::successful);

	ClassDB::bind_method(D_METHOD("to_string_discord"),
			&DiscordClientResult::to_string_discord);

	ClassDB::bind_method(D_METHOD("type"),
			&DiscordClientResult::type);
}
