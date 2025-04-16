
#include "discord_classes.h"

using namespace godot;

void DiscordppClientResult::Drop() {
	obj->Drop();
}

String DiscordppClientResult::ToString() {
	return String(obj->ToString().c_str());
}

DiscordppErrorType::Enum DiscordppClientResult::Type() {
	return (DiscordppErrorType::Enum)obj->Type();
}

void DiscordppClientResult::SetType(DiscordppErrorType::Enum Type) {
	discordpp::ErrorType p0 = (discordpp::ErrorType)Type;

	obj->SetType(p0);
}

String DiscordppClientResult::Error() {
	return String(obj->Error().c_str());
}

void DiscordppClientResult::SetError(String Error) {
	const char *p0 = Error.utf8().get_data();

	obj->SetError(p0);
}

int64_t DiscordppClientResult::ErrorCode() {
	return obj->ErrorCode();
}

void DiscordppClientResult::SetErrorCode(int64_t ErrorCode) {
	int64_t p0 = ErrorCode;

	obj->SetErrorCode(p0);
}

DiscordppHttpStatusCode::Enum DiscordppClientResult::Status() {
	return (DiscordppHttpStatusCode::Enum)obj->Status();
}

void DiscordppClientResult::SetStatus(DiscordppHttpStatusCode::Enum Status) {
	discordpp::HttpStatusCode p0 = (discordpp::HttpStatusCode)Status;

	obj->SetStatus(p0);
}

String DiscordppClientResult::ResponseBody() {
	return String(obj->ResponseBody().c_str());
}

void DiscordppClientResult::SetResponseBody(String ResponseBody) {
	const char *p0 = ResponseBody.utf8().get_data();

	obj->SetResponseBody(p0);
}

bool DiscordppClientResult::Successful() {
	return obj->Successful();
}

void DiscordppClientResult::SetSuccessful(bool Successful) {
	bool p0 = Successful;

	obj->SetSuccessful(p0);
}

bool DiscordppClientResult::Retryable() {
	return obj->Retryable();
}

void DiscordppClientResult::SetRetryable(bool Retryable) {
	bool p0 = Retryable;

	obj->SetRetryable(p0);
}

float DiscordppClientResult::RetryAfter() {
	return obj->RetryAfter();
}

void DiscordppClientResult::SetRetryAfter(float RetryAfter) {
	float p0 = RetryAfter;

	obj->SetRetryAfter(p0);
}

void DiscordppClientResult::_bind_methods() {
	ClassDB::bind_method(D_METHOD("Drop"),
			&DiscordppClientResult::Drop);

	ClassDB::bind_method(D_METHOD("ToString"),
			&DiscordppClientResult::ToString);

	ClassDB::bind_method(D_METHOD("Type"),
			&DiscordppClientResult::Type);

	ClassDB::bind_method(D_METHOD("SetType", "Type"),
			&DiscordppClientResult::SetType);

	ClassDB::bind_method(D_METHOD("Error"),
			&DiscordppClientResult::Error);

	ClassDB::bind_method(D_METHOD("SetError", "Error"),
			&DiscordppClientResult::SetError);

	ClassDB::bind_method(D_METHOD("ErrorCode"),
			&DiscordppClientResult::ErrorCode);

	ClassDB::bind_method(D_METHOD("SetErrorCode", "ErrorCode"),
			&DiscordppClientResult::SetErrorCode);

	ClassDB::bind_method(D_METHOD("Status"),
			&DiscordppClientResult::Status);

	ClassDB::bind_method(D_METHOD("SetStatus", "Status"),
			&DiscordppClientResult::SetStatus);

	ClassDB::bind_method(D_METHOD("ResponseBody"),
			&DiscordppClientResult::ResponseBody);

	ClassDB::bind_method(D_METHOD("SetResponseBody", "ResponseBody"),
			&DiscordppClientResult::SetResponseBody);

	ClassDB::bind_method(D_METHOD("Successful"),
			&DiscordppClientResult::Successful);

	ClassDB::bind_method(D_METHOD("SetSuccessful", "Successful"),
			&DiscordppClientResult::SetSuccessful);

	ClassDB::bind_method(D_METHOD("Retryable"),
			&DiscordppClientResult::Retryable);

	ClassDB::bind_method(D_METHOD("SetRetryable", "Retryable"),
			&DiscordppClientResult::SetRetryable);

	ClassDB::bind_method(D_METHOD("RetryAfter"),
			&DiscordppClientResult::RetryAfter);

	ClassDB::bind_method(D_METHOD("SetRetryAfter", "RetryAfter"),
			&DiscordppClientResult::SetRetryAfter);
}
