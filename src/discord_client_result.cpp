
#include "discord_classes.h"

using namespace godot;

// Functions.

DiscordErrorType::Enum DiscordClientResult::type() {
	auto r = obj->Type();

	DiscordErrorType::Enum cr = (DiscordErrorType::Enum)r;
	return cr;
}

DiscordHttpStatusCode::Enum DiscordClientResult::status() {
	auto r = obj->Status();

	DiscordHttpStatusCode::Enum cr = (DiscordHttpStatusCode::Enum)r;
	return cr;
}

String DiscordClientResult::error() {
	auto r = obj->Error();

	String cr = String(r.c_str());
	return cr;
}

String DiscordClientResult::response_body() {
	auto r = obj->ResponseBody();

	String cr = String(r.c_str());
	return cr;
}

String DiscordClientResult::to_string_discord() {
	auto r = obj->ToString();

	String cr = String(r.c_str());
	return cr;
}

bool DiscordClientResult::retryable() {
	auto r = obj->Retryable();

	bool cr = r;
	return cr;
}

bool DiscordClientResult::successful() {
	auto r = obj->Successful();

	bool cr = r;
	return cr;
}

float DiscordClientResult::retry_after() {
	auto r = obj->RetryAfter();

	float cr = (float)r;
	return cr;
}

int64_t DiscordClientResult::error_code() {
	auto r = obj->ErrorCode();

	int64_t cr = (int64_t)r;
	return cr;
}

void DiscordClientResult::set_error(String error) {
	std::string p0 = std::string(error.utf8().get_data());
	obj->SetError(p0);
}

void DiscordClientResult::set_error_code(int64_t error_code) {
	int64_t p0 = error_code;
	obj->SetErrorCode(p0);
}

void DiscordClientResult::set_response_body(String response_body) {
	std::string p0 = std::string(response_body.utf8().get_data());
	obj->SetResponseBody(p0);
}

void DiscordClientResult::set_retry_after(float retry_after) {
	float p0 = retry_after;
	obj->SetRetryAfter(p0);
}

void DiscordClientResult::set_retryable(bool retryable) {
	bool p0 = retryable;
	obj->SetRetryable(p0);
}

void DiscordClientResult::set_status(DiscordHttpStatusCode::Enum status) {
	discordpp::HttpStatusCode p0 = (discordpp::HttpStatusCode)status;
	obj->SetStatus(p0);
}

void DiscordClientResult::set_successful(bool successful) {
	bool p0 = successful;
	obj->SetSuccessful(p0);
}

void DiscordClientResult::set_type(DiscordErrorType::Enum type) {
	discordpp::ErrorType p0 = (discordpp::ErrorType)type;
	obj->SetType(p0);
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
