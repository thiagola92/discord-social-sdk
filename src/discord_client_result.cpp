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

void DiscordClientResult::_bind_methods() {
	//
}

DiscordClientResult::DiscordClientResult() {}

DiscordClientResult::DiscordClientResult(discordpp::ClientResult *client_result) {
	this->client_result = client_result;
}

DiscordClientResult::~DiscordClientResult() {}
