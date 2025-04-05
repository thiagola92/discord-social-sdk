// AUTO-GENERATED
#include "discord_classes.h"

using namespace godot;

discordpp::ClientResult *DiscordClientResult::unwrap() {
	return client_result;
}

String DiscordClientResult::to_string() {
	auto r = client_result->ToString();
	return String(r.c_str());
}

DiscordErrorType::Enum DiscordClientResult::type() {
	auto r = client_result->Type();
	return (DiscordErrorType::Enum)r;
}

void DiscordClientResult::set_type(DiscordErrorType::Enum type) {
	auto p0 = (discordpp::ErrorType)type;
	client_result->SetType(p0);
}

String DiscordClientResult::error() {
	auto r = client_result->Error();
	return String(r.c_str());
}

void DiscordClientResult::set_error(String error) {
	auto p0 = error.utf8().get_data();
	client_result->SetError(p0);
}

int32_t DiscordClientResult::error_code() {
	auto r = client_result->ErrorCode();
	return r;
}

void DiscordClientResult::set_error_code(int32_t error_code) {
	client_result->SetErrorCode(error_code);
}

DiscordHttpStatusCode::Enum DiscordClientResult::status() {
	auto r = client_result->Status();
	return (DiscordHttpStatusCode::Enum)r;
}

void DiscordClientResult::set_status(DiscordHttpStatusCode::Enum status) {
	auto p0 = (discordpp::HttpStatusCode)status;
	client_result->SetStatus(p0);
}

String DiscordClientResult::response_body() {
	auto r = client_result->ResponseBody();
	return String(r.c_str());
}

void DiscordClientResult::set_response_body(String response_body) {
	auto p0 = response_body.utf8().get_data();
	client_result->SetResponseBody(p0);
}

bool DiscordClientResult::successful() {
	auto r = client_result->Successful();
	return r;
}

void DiscordClientResult::set_successful(bool successful) {
	client_result->SetSuccessful(successful);
}

bool DiscordClientResult::retryable() {
	auto r = client_result->Retryable();
	return r;
}

void DiscordClientResult::set_retryable(bool retryable) {
	client_result->SetRetryable(retryable);
}

float DiscordClientResult::retry_after() {
	auto r = client_result->RetryAfter();
	return r;
}

void DiscordClientResult::set_retry_after(float retry_after) {
	client_result->SetRetryAfter(retry_after);
}

void DiscordClientResult::_bind_methods() {
	ClassDB::bind_method(D_METHOD("to_string"),
			&DiscordClientResult::to_string);

	ClassDB::bind_method(D_METHOD("type"),
			&DiscordClientResult::type);

	ClassDB::bind_method(D_METHOD("set_type", "type"),
			&DiscordClientResult::set_type);

	ClassDB::bind_method(D_METHOD("error"),
			&DiscordClientResult::error);

	ClassDB::bind_method(D_METHOD("set_error", "error"),
			&DiscordClientResult::set_error);

	ClassDB::bind_method(D_METHOD("error_code"),
			&DiscordClientResult::error_code);

	ClassDB::bind_method(D_METHOD("set_error_code", "error_code"),
			&DiscordClientResult::set_error_code);

	ClassDB::bind_method(D_METHOD("status"),
			&DiscordClientResult::status);

	ClassDB::bind_method(D_METHOD("set_status", "status"),
			&DiscordClientResult::set_status);

	ClassDB::bind_method(D_METHOD("response_body"),
			&DiscordClientResult::response_body);

	ClassDB::bind_method(D_METHOD("set_response_body", "response_body"),
			&DiscordClientResult::set_response_body);

	ClassDB::bind_method(D_METHOD("successful"),
			&DiscordClientResult::successful);

	ClassDB::bind_method(D_METHOD("set_successful", "successful"),
			&DiscordClientResult::set_successful);

	ClassDB::bind_method(D_METHOD("retryable"),
			&DiscordClientResult::retryable);

	ClassDB::bind_method(D_METHOD("set_retryable", "retryable"),
			&DiscordClientResult::set_retryable);

	ClassDB::bind_method(D_METHOD("retry_after"),
			&DiscordClientResult::retry_after);

	ClassDB::bind_method(D_METHOD("set_retry_after", "retry_after"),
			&DiscordClientResult::set_retry_after);
}

DiscordClientResult::DiscordClientResult() {
}

DiscordClientResult::DiscordClientResult(discordpp::ClientResult *client_result) {
	this->client_result = client_result;
}

DiscordClientResult::~DiscordClientResult() {}
