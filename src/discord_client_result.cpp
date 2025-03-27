#include "discord_client_result.h"
#include <cstdint>

using namespace godot;

discordpp::ClientResult *DiscordClientResult::unwrap() {
	return client_result;
}

String DiscordClientResult::to_string() {
	return String(client_result->ToString().c_str());
}

DiscordErrorType::Enum DiscordClientResult::get_type() {
	return (DiscordErrorType::Enum)client_result->Type();
}

void DiscordClientResult::set_type(DiscordErrorType::Enum type) {
	client_result->SetType((discordpp::ErrorType)type);
}

String DiscordClientResult::get_error() {
	return String(client_result->Error().c_str());
}

void DiscordClientResult::set_error(String error) {
	client_result->SetError(error.utf8().get_data());
}

int32_t DiscordClientResult::get_error_code() {
	return client_result->ErrorCode();
}

void DiscordClientResult::set_error_code(int32_t error_code) {
	client_result->SetErrorCode(error_code);
}

DiscordHttpStatusCode::Enum DiscordClientResult::get_status() {
	return (DiscordHttpStatusCode::Enum)client_result->Status();
}

void DiscordClientResult::set_status(DiscordHttpStatusCode::Enum status) {
	client_result->SetStatus((discordpp::HttpStatusCode)status);
}

String DiscordClientResult::get_response_body() {
	return String(client_result->ResponseBody().c_str());
}

void DiscordClientResult::set_response_body(String response_body) {
	client_result->SetResponseBody(response_body.utf8().get_data());
}

bool DiscordClientResult::get_successful() {
	return client_result->Successful();
}

void DiscordClientResult::set_successful(bool successful) {
	client_result->SetSuccessful(successful);
}

bool DiscordClientResult::get_retryable() {
	return client_result->Retryable();
}

void DiscordClientResult::set_retryable(bool retryable) {
	client_result->SetRetryable(retryable);
}

float DiscordClientResult::get_retry_after() {
	return client_result->RetryAfter();
}

void DiscordClientResult::set_retry_after(float retry_after) {
	client_result->SetRetryAfter(retry_after);
}

void DiscordClientResult::_bind_methods() {
	ClassDB::bind_method(D_METHOD("to_string"),
			&DiscordClientResult::to_string);

	ClassDB::bind_method(D_METHOD("get_type"),
			&DiscordClientResult::get_type);

	ClassDB::bind_method(D_METHOD("set_type", "type"),
			&DiscordClientResult::set_type);

	ClassDB::bind_method(D_METHOD("get_error"),
			&DiscordClientResult::get_error);

	ClassDB::bind_method(D_METHOD("set_error", "error"),
			&DiscordClientResult::set_error);

	ClassDB::bind_method(D_METHOD("get_error_code"),
			&DiscordClientResult::get_error_code);

	ClassDB::bind_method(D_METHOD("set_error_code", "error_code"),
			&DiscordClientResult::set_error_code);

	ClassDB::bind_method(D_METHOD("get_status"),
			&DiscordClientResult::get_status);

	ClassDB::bind_method(D_METHOD("set_status", "status"),
			&DiscordClientResult::set_status);

	ClassDB::bind_method(D_METHOD("get_response_body"),
			&DiscordClientResult::get_response_body);

	ClassDB::bind_method(D_METHOD("set_response_body", "response_body"),
			&DiscordClientResult::set_response_body);

	ClassDB::bind_method(D_METHOD("get_successful"),
			&DiscordClientResult::get_successful);

	ClassDB::bind_method(D_METHOD("set_successful", "successful"),
			&DiscordClientResult::set_successful);

	ClassDB::bind_method(D_METHOD("get_retryable"),
			&DiscordClientResult::get_retryable);

	ClassDB::bind_method(D_METHOD("set_retryable", "retryable"),
			&DiscordClientResult::set_retryable);

	ClassDB::bind_method(D_METHOD("get_retry_after"),
			&DiscordClientResult::get_retry_after);

	ClassDB::bind_method(D_METHOD("set_retry_after", "retry_after"),
			&DiscordClientResult::set_retry_after);
}

DiscordClientResult::DiscordClientResult() {}

DiscordClientResult::DiscordClientResult(discordpp::ClientResult *client_result) {
	this->client_result = client_result;
}

DiscordClientResult::~DiscordClientResult() {}
