
#include "discord_classes.h"

using namespace godot;

// Functions.

DiscordAuthorizationCodeVerifier DiscordClient::create_authorization_code_verifier() {
}

DiscordCall DiscordClient::get_call(int64_t channel_id) {
	int64_t p0 = channel_id;
}

DiscordCall DiscordClient::start_call(int64_t channel_id) {
	int64_t p0 = channel_id;
}

DiscordCall DiscordClient::start_call_with_audio_callbacks(int64_t lobby_id, Callable received_cb, Callable captured_cb) {
	int64_t p0 = lobby_id;
	TODOTODO
}

DiscordClientStatus DiscordClient::get_status() {
}

DiscordRelationshipHandle DiscordClient::get_relationship_handle(int64_t user_id) {
	int64_t p0 = user_id;
}

DiscordUserHandle DiscordClient::get_current_user() {
}

String DiscordClient::error_to_string(DiscordClientError type){
	TODO
}

String DiscordClient::get_default_audio_device_id() {
}

String DiscordClient::get_default_communication_scopes() {
}

String DiscordClient::get_default_presence_scopes() {
}

String DiscordClient::get_version_hash() {
}

String DiscordClient::status_to_string(DiscordClientStatus type){
	TODO
}

String DiscordClient::thread_to_string(DiscordClientThread type){
	TODO
}

TypedArray<DiscordCall> DiscordClient::get_calls() {
}

TypedArray<DiscordRelationshipHandle> DiscordClient::get_relationships() {
}

TypedArray<DiscordRelationshipHandle> DiscordClient::get_relationships_by_group(DiscordRelationshipGroupType group_type){
	TODO
}

TypedArray<DiscordUserHandle> DiscordClient::search_friends_by_username(String search_str) {
	std::string p0 = std::string(search_str.utf8().get_data());
}

TypedArray<int64_t> DiscordClient::get_lobby_ids() {
}

Variant DiscordClient::get_channel_handle(int64_t channel_id) {
	int64_t p0 = channel_id;
}

Variant DiscordClient::get_current_user_v() {
}

Variant DiscordClient::get_lobby_handle(int64_t lobby_id) {
	int64_t p0 = lobby_id;
}

Variant DiscordClient::get_message_handle(int64_t message_id) {
	int64_t p0 = message_id;
}

Variant DiscordClient::get_user(int64_t user_id) {
	int64_t p0 = user_id;
}

bool DiscordClient::can_open_message_in_discord(int64_t message_id) {
	int64_t p0 = message_id;
}

bool DiscordClient::get_self_deaf_all() {
}

bool DiscordClient::get_self_mute_all() {
}

bool DiscordClient::is_authenticated() {
}

bool DiscordClient::register_launch_command(int64_t application_id, String command) {
	int64_t p0 = application_id;
	std::string p1 = std::string(command.utf8().get_data());
}

bool DiscordClient::register_launch_steam_application(int64_t application_id, int64_t steam_app_id) {
	int64_t p0 = application_id;
	int64_t p1 = steam_app_id;
}

bool DiscordClient::set_log_dir(String path, DiscordLoggingSeverity min_severity) {
	std::string p0 = std::string(path.utf8().get_data());
	TODO
}

bool DiscordClient::set_speaker_mode(bool speaker_mode) {
	bool p0 = speaker_mode;
}

bool DiscordClient::show_audio_route_picker() {
}

float DiscordClient::get_input_volume() {
}

float DiscordClient::get_output_volume() {
}

int64_t DiscordClient::get_application_id() {
}

int64_t DiscordClient::get_version_major() {
}

int64_t DiscordClient::get_version_minor() {
}

int64_t DiscordClient::get_version_patch() {
}

void DiscordClient::abort_authorize() {
}

void DiscordClient::abort_get_token_from_device() {
}

void DiscordClient::accept_activity_invite(DiscordActivityInvite invite, Callable cb) {
	TODOTODO
}

void DiscordClient::accept_discord_friend_request(int64_t user_id, Callable cb) {
	int64_t p0 = user_id;
	TODO
}

void DiscordClient::accept_game_friend_request(int64_t user_id, Callable cb) {
	int64_t p0 = user_id;
	TODO
}

void DiscordClient::add_log_callback(Callable callback, DiscordLoggingSeverity min_severity) {
	TODOTODO
}

void DiscordClient::add_voice_log_callback(Callable callback, DiscordLoggingSeverity min_severity) {
	TODOTODO
}

void DiscordClient::authorize(DiscordAuthorizationArgs args, Callable callback) {
	TODOTODO
}

void DiscordClient::block_user(int64_t user_id, Callable cb) {
	int64_t p0 = user_id;
	TODO
}

void DiscordClient::cancel_discord_friend_request(int64_t user_id, Callable cb) {
	int64_t p0 = user_id;
	TODO
}

void DiscordClient::cancel_game_friend_request(int64_t user_id, Callable cb) {
	int64_t p0 = user_id;
	TODO
}

void DiscordClient::clear_rich_presence() {
}

void DiscordClient::close_authorize_device_screen() {
}

void DiscordClient::connect_discord() {
}

void DiscordClient::create_or_join_lobby(String secret, Callable callback) {
	std::string p0 = std::string(secret.utf8().get_data());
	TODO
}

void DiscordClient::create_or_join_lobby_with_metadata(String secret, TypedDictionary<String, String> lobby_metadata, TypedDictionary<String, String> member_metadata, Callable callback) {
	std::string p0 = std::string(secret.utf8().get_data());
	TODOTODOTODO
}

void DiscordClient::delete_user_message(int64_t recipient_id, int64_t message_id, Callable cb) {
	int64_t p0 = recipient_id;
	int64_t p1 = message_id;
	TODO
}

void DiscordClient::disconnect_discord() {
}

void DiscordClient::edit_user_message(int64_t recipient_id, int64_t message_id, String content, Callable cb) {
	int64_t p0 = recipient_id;
	int64_t p1 = message_id;
	std::string p2 = std::string(content.utf8().get_data());
	TODO
}

void DiscordClient::end_call(int64_t channel_id, Callable callback) {
	int64_t p0 = channel_id;
	TODO
}

void DiscordClient::end_calls(Callable callback) {
	TODO
}

void DiscordClient::exchange_child_token(String parent_application_token, int64_t child_application_id, Callable callback) {
	std::string p0 = std::string(parent_application_token.utf8().get_data());
	int64_t p1 = child_application_id;
	TODO
}

void DiscordClient::fetch_current_user(DiscordAuthorizationTokenType token_type, String token, Callable callback) {
	TODOstd::string p1 = std::string(token.utf8().get_data());
	TODO
}

void DiscordClient::get_current_input_device(Callable cb) {
	TODO
}

void DiscordClient::get_current_output_device(Callable cb) {
	TODO
}

void DiscordClient::get_discord_client_connected_user(int64_t application_id, Callable callback) {
	int64_t p0 = application_id;
	TODO
}

void DiscordClient::get_guild_channels(int64_t guild_id, Callable cb) {
	int64_t p0 = guild_id;
	TODO
}

void DiscordClient::get_input_devices(Callable cb) {
	TODO
}

void DiscordClient::get_lobby_messages_with_limit(int64_t lobby_id, int64_t limit, Callable cb) {
	int64_t p0 = lobby_id;
	int64_t p1 = limit;
	TODO
}

void DiscordClient::get_output_devices(Callable cb) {
	TODO
}

void DiscordClient::get_provisional_token(int64_t application_id, DiscordAuthenticationExternalAuthType external_auth_type, String external_auth_token, Callable callback) {
	int64_t p0 = application_id;
	TODOstd::string p2 = std::string(external_auth_token.utf8().get_data());
	TODO
}

void DiscordClient::get_token(int64_t application_id, String code, String code_verifier, String redirect_uri, Callable callback) {
	int64_t p0 = application_id;
	std::string p1 = std::string(code.utf8().get_data());
	std::string p2 = std::string(code_verifier.utf8().get_data());
	std::string p3 = std::string(redirect_uri.utf8().get_data());
	TODO
}

void DiscordClient::get_token_from_device(DiscordDeviceAuthorizationArgs args, Callable callback) {
	TODOTODO
}

void DiscordClient::get_token_from_device_provisional_merge(DiscordDeviceAuthorizationArgs args, DiscordAuthenticationExternalAuthType external_auth_type, String external_auth_token, Callable callback) {
	TODOTODOstd::string p2 = std::string(external_auth_token.utf8().get_data());
	TODO
}

void DiscordClient::get_token_from_provisional_merge(int64_t application_id, String code, String code_verifier, String redirect_uri, DiscordAuthenticationExternalAuthType external_auth_type, String external_auth_token, Callable callback) {
	int64_t p0 = application_id;
	std::string p1 = std::string(code.utf8().get_data());
	std::string p2 = std::string(code_verifier.utf8().get_data());
	std::string p3 = std::string(redirect_uri.utf8().get_data());
	TODOstd::string p5 = std::string(external_auth_token.utf8().get_data());
	TODO
}

void DiscordClient::get_user_guilds(Callable cb) {
	TODO
}

void DiscordClient::get_user_message_summaries(Callable cb) {
	TODO
}

void DiscordClient::get_user_messages_with_limit(int64_t recipient_id, int64_t limit, Callable cb) {
	int64_t p0 = recipient_id;
	int64_t p1 = limit;
	TODO
}

void DiscordClient::is_discord_app_installed(Callable callback) {
	TODO
}

void DiscordClient::join_linked_lobby_guild(int64_t lobby_id, Callable provisional_user_merge_required_callback, Callable callback) {
	int64_t p0 = lobby_id;
	TODOTODO
}

void DiscordClient::leave_lobby(int64_t lobby_id, Callable callback) {
	int64_t p0 = lobby_id;
	TODO
}

void DiscordClient::link_channel_to_lobby(int64_t lobby_id, int64_t channel_id, Callable callback) {
	int64_t p0 = lobby_id;
	int64_t p1 = channel_id;
	TODO
}

void DiscordClient::open_authorize_device_screen(int64_t client_id, String user_code) {
	int64_t p0 = client_id;
	std::string p1 = std::string(user_code.utf8().get_data());
}

void DiscordClient::open_connected_games_settings_in_discord(Callable callback) {
	TODO
}

void DiscordClient::open_message_in_discord(int64_t message_id, Callable provisional_user_merge_required_callback, Callable callback) {
	int64_t p0 = message_id;
	TODOTODO
}

void DiscordClient::provisional_user_merge_completed(bool success) {
	bool p0 = success;
}

void DiscordClient::refresh_token(int64_t application_id, String refresh_token, Callable callback) {
	int64_t p0 = application_id;
	std::string p1 = std::string(refresh_token.utf8().get_data());
	TODO
}

void DiscordClient::register_authorize_request_callback(Callable callback) {
	TODO
}

void DiscordClient::reject_discord_friend_request(int64_t user_id, Callable cb) {
	int64_t p0 = user_id;
	TODO
}

void DiscordClient::reject_game_friend_request(int64_t user_id, Callable cb) {
	int64_t p0 = user_id;
	TODO
}

void DiscordClient::remove_authorize_request_callback() {
}

void DiscordClient::remove_discord_and_game_friend(int64_t user_id, Callable cb) {
	int64_t p0 = user_id;
	TODO
}

void DiscordClient::remove_game_friend(int64_t user_id, Callable cb) {
	int64_t p0 = user_id;
	TODO
}

void DiscordClient::revoke_token(int64_t application_id, String token, Callable callback) {
	int64_t p0 = application_id;
	std::string p1 = std::string(token.utf8().get_data());
	TODO
}

void DiscordClient::send_activity_invite(int64_t user_id, String content, Callable cb) {
	int64_t p0 = user_id;
	std::string p1 = std::string(content.utf8().get_data());
	TODO
}

void DiscordClient::send_activity_join_request(int64_t user_id, Callable cb) {
	int64_t p0 = user_id;
	TODO
}

void DiscordClient::send_activity_join_request_reply(DiscordActivityInvite invite, Callable cb) {
	TODOTODO
}

void DiscordClient::send_discord_friend_request(String username, Callable cb) {
	std::string p0 = std::string(username.utf8().get_data());
	TODO
}

void DiscordClient::send_discord_friend_request_by_id(int64_t user_id, Callable cb) {
	int64_t p0 = user_id;
	TODO
}

void DiscordClient::send_game_friend_request(String username, Callable cb) {
	std::string p0 = std::string(username.utf8().get_data());
	TODO
}

void DiscordClient::send_game_friend_request_by_id(int64_t user_id, Callable cb) {
	int64_t p0 = user_id;
	TODO
}

void DiscordClient::send_lobby_message(int64_t lobby_id, String content, Callable cb) {
	int64_t p0 = lobby_id;
	std::string p1 = std::string(content.utf8().get_data());
	TODO
}

void DiscordClient::send_lobby_message_with_metadata(int64_t lobby_id, String content, TypedDictionary<String, String> metadata, Callable cb) {
	int64_t p0 = lobby_id;
	std::string p1 = std::string(content.utf8().get_data());
	TODOTODO
}

void DiscordClient::send_user_message(int64_t recipient_id, String content, Callable cb) {
	int64_t p0 = recipient_id;
	std::string p1 = std::string(content.utf8().get_data());
	TODO
}

void DiscordClient::send_user_message_with_metadata(int64_t recipient_id, String content, TypedDictionary<String, String> metadata, Callable cb) {
	int64_t p0 = recipient_id;
	std::string p1 = std::string(content.utf8().get_data());
	TODOTODO
}

void DiscordClient::set_activity_invite_created_callback(Callable cb) {
	TODO
}

void DiscordClient::set_activity_invite_updated_callback(Callable cb) {
	TODO
}

void DiscordClient::set_activity_join_callback(Callable cb) {
	TODO
}

void DiscordClient::set_activity_join_with_application_callback(Callable cb) {
	TODO
}

void DiscordClient::set_aec_dump(bool on) {
	bool p0 = on;
}

void DiscordClient::set_application_id(int64_t application_id) {
	int64_t p0 = application_id;
}

void DiscordClient::set_authorize_device_screen_closed_callback(Callable cb) {
	TODO
}

void DiscordClient::set_automatic_gain_control(bool on) {
	bool p0 = on;
}

void DiscordClient::set_device_change_callback(Callable callback) {
	TODO
}

void DiscordClient::set_echo_cancellation(bool on) {
	bool p0 = on;
}

void DiscordClient::set_engine_managed_audio_session(bool is_engine_managed) {
	bool p0 = is_engine_managed;
}

void DiscordClient::set_game_window_pid(int64_t pid) {
	int64_t p0 = pid;
}

void DiscordClient::set_http_request_timeout(int64_t http_timeout_in_milliseconds) {
	int64_t p0 = http_timeout_in_milliseconds;
}

void DiscordClient::set_input_device(String device_id, Callable cb) {
	std::string p0 = std::string(device_id.utf8().get_data());
	TODO
}

void DiscordClient::set_input_volume(float input_volume) {
	float p0 = input_volume;
}

void DiscordClient::set_lobby_created_callback(Callable cb) {
	TODO
}

void DiscordClient::set_lobby_deleted_callback(Callable cb) {
	TODO
}

void DiscordClient::set_lobby_member_added_callback(Callable cb) {
	TODO
}

void DiscordClient::set_lobby_member_removed_callback(Callable cb) {
	TODO
}

void DiscordClient::set_lobby_member_updated_callback(Callable cb) {
	TODO
}

void DiscordClient::set_lobby_updated_callback(Callable cb) {
	TODO
}

void DiscordClient::set_message_created_callback(Callable cb) {
	TODO
}

void DiscordClient::set_message_deleted_callback(Callable cb) {
	TODO
}

void DiscordClient::set_message_updated_callback(Callable cb) {
	TODO
}

void DiscordClient::set_no_audio_input_callback(Callable callback) {
	TODO
}

void DiscordClient::set_no_audio_input_threshold(float d_bfsthreshold) {
	float p0 = d_bfsthreshold;
}

void DiscordClient::set_noise_suppression(bool on) {
	bool p0 = on;
}

void DiscordClient::set_online_status(DiscordStatusType status, Callable callback) {
	TODOTODO
}

void DiscordClient::set_opus_hardware_coding(bool encode, bool decode) {
	bool p0 = encode;
	bool p1 = decode;
}

void DiscordClient::set_output_device(String device_id, Callable cb) {
	std::string p0 = std::string(device_id.utf8().get_data());
	TODO
}

void DiscordClient::set_output_volume(float output_volume) {
	float p0 = output_volume;
}

void DiscordClient::set_relationship_created_callback(Callable cb) {
	TODO
}

void DiscordClient::set_relationship_deleted_callback(Callable cb) {
	TODO
}

void DiscordClient::set_relationship_groups_updated_callback(Callable cb) {
	TODO
}

void DiscordClient::set_self_deaf_all(bool deaf) {
	bool p0 = deaf;
}

void DiscordClient::set_self_mute_all(bool mute) {
	bool p0 = mute;
}

void DiscordClient::set_showing_chat(bool showing_chat) {
	bool p0 = showing_chat;
}

void DiscordClient::set_status_changed_callback(Callable cb) {
	TODO
}

void DiscordClient::set_thread_priority(DiscordClientThread thread, int64_t priority) {
	TODOint64_t p1 = priority;
}

void DiscordClient::set_token_expiration_callback(Callable callback) {
	TODO
}

void DiscordClient::set_user_updated_callback(Callable cb) {
	TODO
}

void DiscordClient::set_voice_log_dir(String path, DiscordLoggingSeverity min_severity) {
	std::string p0 = std::string(path.utf8().get_data());
	TODO
}

void DiscordClient::set_voice_participant_changed_callback(Callable cb) {
	TODO
}

void DiscordClient::unblock_user(int64_t user_id, Callable cb) {
	int64_t p0 = user_id;
	TODO
}

void DiscordClient::unlink_channel_from_lobby(int64_t lobby_id, Callable callback) {
	int64_t p0 = lobby_id;
	TODO
}

void DiscordClient::unmerge_into_provisional_account(int64_t application_id, DiscordAuthenticationExternalAuthType external_auth_type, String external_auth_token, Callable callback) {
	int64_t p0 = application_id;
	TODOstd::string p2 = std::string(external_auth_token.utf8().get_data());
	TODO
}

void DiscordClient::update_provisional_account_display_name(String name, Callable callback) {
	std::string p0 = std::string(name.utf8().get_data());
	TODO
}

void DiscordClient::update_rich_presence(DiscordActivity activity, Callable cb) {
	TODOTODO
}

void DiscordClient::update_token(DiscordAuthorizationTokenType token_type, String token, Callable callback) {
	TODOstd::string p1 = std::string(token.utf8().get_data());
	TODO
}

// Overload functions.

// Binding.
void DiscordClient::_bind_methods() {
	ClassDB::bind_method(D_METHOD("abort_authorize"),
			&DiscordClient::abort_authorize);

	ClassDB::bind_method(D_METHOD("abort_get_token_from_device"),
			&DiscordClient::abort_get_token_from_device);

	ClassDB::bind_method(D_METHOD("accept_activity_invite", "invite", "cb"),
			&DiscordClient::accept_activity_invite);

	ClassDB::bind_method(D_METHOD("accept_discord_friend_request", "user_id", "cb"),
			&DiscordClient::accept_discord_friend_request);

	ClassDB::bind_method(D_METHOD("accept_game_friend_request", "user_id", "cb"),
			&DiscordClient::accept_game_friend_request);

	ClassDB::bind_method(D_METHOD("add_log_callback", "callback", "min_severity"),
			&DiscordClient::add_log_callback);

	ClassDB::bind_method(D_METHOD("add_voice_log_callback", "callback", "min_severity"),
			&DiscordClient::add_voice_log_callback);

	ClassDB::bind_method(D_METHOD("authorize", "args", "callback"),
			&DiscordClient::authorize);

	ClassDB::bind_method(D_METHOD("block_user", "user_id", "cb"),
			&DiscordClient::block_user);

	ClassDB::bind_method(D_METHOD("can_open_message_in_discord", "message_id"),
			&DiscordClient::can_open_message_in_discord);

	ClassDB::bind_method(D_METHOD("cancel_discord_friend_request", "user_id", "cb"),
			&DiscordClient::cancel_discord_friend_request);

	ClassDB::bind_method(D_METHOD("cancel_game_friend_request", "user_id", "cb"),
			&DiscordClient::cancel_game_friend_request);

	ClassDB::bind_method(D_METHOD("clear_rich_presence"),
			&DiscordClient::clear_rich_presence);

	ClassDB::bind_method(D_METHOD("close_authorize_device_screen"),
			&DiscordClient::close_authorize_device_screen);

	ClassDB::bind_method(D_METHOD("connect_discord"),
			&DiscordClient::connect_discord);

	ClassDB::bind_method(D_METHOD("create_authorization_code_verifier"),
			&DiscordClient::create_authorization_code_verifier);

	ClassDB::bind_method(D_METHOD("create_or_join_lobby", "secret", "callback"),
			&DiscordClient::create_or_join_lobby);

	ClassDB::bind_method(D_METHOD("create_or_join_lobby_with_metadata", "secret", "lobby_metadata", "member_metadata", "callback"),
			&DiscordClient::create_or_join_lobby_with_metadata);

	ClassDB::bind_method(D_METHOD("delete_user_message", "recipient_id", "message_id", "cb"),
			&DiscordClient::delete_user_message);

	ClassDB::bind_method(D_METHOD("disconnect_discord"),
			&DiscordClient::disconnect_discord);

	ClassDB::bind_method(D_METHOD("edit_user_message", "recipient_id", "message_id", "content", "cb"),
			&DiscordClient::edit_user_message);

	ClassDB::bind_method(D_METHOD("end_call", "channel_id", "callback"),
			&DiscordClient::end_call);

	ClassDB::bind_method(D_METHOD("end_calls", "callback"),
			&DiscordClient::end_calls);

	ClassDB::bind_method(D_METHOD("exchange_child_token", "parent_application_token", "child_application_id", "callback"),
			&DiscordClient::exchange_child_token);

	ClassDB::bind_method(D_METHOD("fetch_current_user", "token_type", "token", "callback"),
			&DiscordClient::fetch_current_user);

	ClassDB::bind_method(D_METHOD("get_application_id"),
			&DiscordClient::get_application_id);

	ClassDB::bind_method(D_METHOD("get_call", "channel_id"),
			&DiscordClient::get_call);

	ClassDB::bind_method(D_METHOD("get_calls"),
			&DiscordClient::get_calls);

	ClassDB::bind_method(D_METHOD("get_channel_handle", "channel_id"),
			&DiscordClient::get_channel_handle);

	ClassDB::bind_method(D_METHOD("get_current_input_device", "cb"),
			&DiscordClient::get_current_input_device);

	ClassDB::bind_method(D_METHOD("get_current_output_device", "cb"),
			&DiscordClient::get_current_output_device);

	ClassDB::bind_method(D_METHOD("get_current_user"),
			&DiscordClient::get_current_user);

	ClassDB::bind_method(D_METHOD("get_current_user_v"),
			&DiscordClient::get_current_user_v);

	ClassDB::bind_method(D_METHOD("get_discord_client_connected_user", "application_id", "callback"),
			&DiscordClient::get_discord_client_connected_user);

	ClassDB::bind_method(D_METHOD("get_guild_channels", "guild_id", "cb"),
			&DiscordClient::get_guild_channels);

	ClassDB::bind_method(D_METHOD("get_input_devices", "cb"),
			&DiscordClient::get_input_devices);

	ClassDB::bind_method(D_METHOD("get_input_volume"),
			&DiscordClient::get_input_volume);

	ClassDB::bind_method(D_METHOD("get_lobby_handle", "lobby_id"),
			&DiscordClient::get_lobby_handle);

	ClassDB::bind_method(D_METHOD("get_lobby_ids"),
			&DiscordClient::get_lobby_ids);

	ClassDB::bind_method(D_METHOD("get_lobby_messages_with_limit", "lobby_id", "limit", "cb"),
			&DiscordClient::get_lobby_messages_with_limit);

	ClassDB::bind_method(D_METHOD("get_message_handle", "message_id"),
			&DiscordClient::get_message_handle);

	ClassDB::bind_method(D_METHOD("get_output_devices", "cb"),
			&DiscordClient::get_output_devices);

	ClassDB::bind_method(D_METHOD("get_output_volume"),
			&DiscordClient::get_output_volume);

	ClassDB::bind_method(D_METHOD("get_provisional_token", "application_id", "external_auth_type", "external_auth_token", "callback"),
			&DiscordClient::get_provisional_token);

	ClassDB::bind_method(D_METHOD("get_relationship_handle", "user_id"),
			&DiscordClient::get_relationship_handle);

	ClassDB::bind_method(D_METHOD("get_relationships"),
			&DiscordClient::get_relationships);

	ClassDB::bind_method(D_METHOD("get_relationships_by_group", "group_type"),
			&DiscordClient::get_relationships_by_group);

	ClassDB::bind_method(D_METHOD("get_self_deaf_all"),
			&DiscordClient::get_self_deaf_all);

	ClassDB::bind_method(D_METHOD("get_self_mute_all"),
			&DiscordClient::get_self_mute_all);

	ClassDB::bind_method(D_METHOD("get_status"),
			&DiscordClient::get_status);

	ClassDB::bind_method(D_METHOD("get_token", "application_id", "code", "code_verifier", "redirect_uri", "callback"),
			&DiscordClient::get_token);

	ClassDB::bind_method(D_METHOD("get_token_from_device", "args", "callback"),
			&DiscordClient::get_token_from_device);

	ClassDB::bind_method(D_METHOD("get_token_from_device_provisional_merge", "args", "external_auth_type", "external_auth_token", "callback"),
			&DiscordClient::get_token_from_device_provisional_merge);

	ClassDB::bind_method(D_METHOD("get_token_from_provisional_merge", "application_id", "code", "code_verifier", "redirect_uri", "external_auth_type", "external_auth_token", "callback"),
			&DiscordClient::get_token_from_provisional_merge);

	ClassDB::bind_method(D_METHOD("get_user", "user_id"),
			&DiscordClient::get_user);

	ClassDB::bind_method(D_METHOD("get_user_guilds", "cb"),
			&DiscordClient::get_user_guilds);

	ClassDB::bind_method(D_METHOD("get_user_message_summaries", "cb"),
			&DiscordClient::get_user_message_summaries);

	ClassDB::bind_method(D_METHOD("get_user_messages_with_limit", "recipient_id", "limit", "cb"),
			&DiscordClient::get_user_messages_with_limit);

	ClassDB::bind_method(D_METHOD("is_authenticated"),
			&DiscordClient::is_authenticated);

	ClassDB::bind_method(D_METHOD("is_discord_app_installed", "callback"),
			&DiscordClient::is_discord_app_installed);

	ClassDB::bind_method(D_METHOD("join_linked_lobby_guild", "lobby_id", "provisional_user_merge_required_callback", "callback"),
			&DiscordClient::join_linked_lobby_guild);

	ClassDB::bind_method(D_METHOD("leave_lobby", "lobby_id", "callback"),
			&DiscordClient::leave_lobby);

	ClassDB::bind_method(D_METHOD("link_channel_to_lobby", "lobby_id", "channel_id", "callback"),
			&DiscordClient::link_channel_to_lobby);

	ClassDB::bind_method(D_METHOD("open_authorize_device_screen", "client_id", "user_code"),
			&DiscordClient::open_authorize_device_screen);

	ClassDB::bind_method(D_METHOD("open_connected_games_settings_in_discord", "callback"),
			&DiscordClient::open_connected_games_settings_in_discord);

	ClassDB::bind_method(D_METHOD("open_message_in_discord", "message_id", "provisional_user_merge_required_callback", "callback"),
			&DiscordClient::open_message_in_discord);

	ClassDB::bind_method(D_METHOD("provisional_user_merge_completed", "success"),
			&DiscordClient::provisional_user_merge_completed);

	ClassDB::bind_method(D_METHOD("refresh_token", "application_id", "refresh_token", "callback"),
			&DiscordClient::refresh_token);

	ClassDB::bind_method(D_METHOD("register_authorize_request_callback", "callback"),
			&DiscordClient::register_authorize_request_callback);

	ClassDB::bind_method(D_METHOD("register_launch_command", "application_id", "command"),
			&DiscordClient::register_launch_command);

	ClassDB::bind_method(D_METHOD("register_launch_steam_application", "application_id", "steam_app_id"),
			&DiscordClient::register_launch_steam_application);

	ClassDB::bind_method(D_METHOD("reject_discord_friend_request", "user_id", "cb"),
			&DiscordClient::reject_discord_friend_request);

	ClassDB::bind_method(D_METHOD("reject_game_friend_request", "user_id", "cb"),
			&DiscordClient::reject_game_friend_request);

	ClassDB::bind_method(D_METHOD("remove_authorize_request_callback"),
			&DiscordClient::remove_authorize_request_callback);

	ClassDB::bind_method(D_METHOD("remove_discord_and_game_friend", "user_id", "cb"),
			&DiscordClient::remove_discord_and_game_friend);

	ClassDB::bind_method(D_METHOD("remove_game_friend", "user_id", "cb"),
			&DiscordClient::remove_game_friend);

	ClassDB::bind_method(D_METHOD("revoke_token", "application_id", "token", "callback"),
			&DiscordClient::revoke_token);

	ClassDB::bind_method(D_METHOD("search_friends_by_username", "search_str"),
			&DiscordClient::search_friends_by_username);

	ClassDB::bind_method(D_METHOD("send_activity_invite", "user_id", "content", "cb"),
			&DiscordClient::send_activity_invite);

	ClassDB::bind_method(D_METHOD("send_activity_join_request", "user_id", "cb"),
			&DiscordClient::send_activity_join_request);

	ClassDB::bind_method(D_METHOD("send_activity_join_request_reply", "invite", "cb"),
			&DiscordClient::send_activity_join_request_reply);

	ClassDB::bind_method(D_METHOD("send_discord_friend_request", "username", "cb"),
			&DiscordClient::send_discord_friend_request);

	ClassDB::bind_method(D_METHOD("send_discord_friend_request_by_id", "user_id", "cb"),
			&DiscordClient::send_discord_friend_request_by_id);

	ClassDB::bind_method(D_METHOD("send_game_friend_request", "username", "cb"),
			&DiscordClient::send_game_friend_request);

	ClassDB::bind_method(D_METHOD("send_game_friend_request_by_id", "user_id", "cb"),
			&DiscordClient::send_game_friend_request_by_id);

	ClassDB::bind_method(D_METHOD("send_lobby_message", "lobby_id", "content", "cb"),
			&DiscordClient::send_lobby_message);

	ClassDB::bind_method(D_METHOD("send_lobby_message_with_metadata", "lobby_id", "content", "metadata", "cb"),
			&DiscordClient::send_lobby_message_with_metadata);

	ClassDB::bind_method(D_METHOD("send_user_message", "recipient_id", "content", "cb"),
			&DiscordClient::send_user_message);

	ClassDB::bind_method(D_METHOD("send_user_message_with_metadata", "recipient_id", "content", "metadata", "cb"),
			&DiscordClient::send_user_message_with_metadata);

	ClassDB::bind_method(D_METHOD("set_activity_invite_created_callback", "cb"),
			&DiscordClient::set_activity_invite_created_callback);

	ClassDB::bind_method(D_METHOD("set_activity_invite_updated_callback", "cb"),
			&DiscordClient::set_activity_invite_updated_callback);

	ClassDB::bind_method(D_METHOD("set_activity_join_callback", "cb"),
			&DiscordClient::set_activity_join_callback);

	ClassDB::bind_method(D_METHOD("set_activity_join_with_application_callback", "cb"),
			&DiscordClient::set_activity_join_with_application_callback);

	ClassDB::bind_method(D_METHOD("set_aec_dump", "on"),
			&DiscordClient::set_aec_dump);

	ClassDB::bind_method(D_METHOD("set_application_id", "application_id"),
			&DiscordClient::set_application_id);

	ClassDB::bind_method(D_METHOD("set_authorize_device_screen_closed_callback", "cb"),
			&DiscordClient::set_authorize_device_screen_closed_callback);

	ClassDB::bind_method(D_METHOD("set_automatic_gain_control", "on"),
			&DiscordClient::set_automatic_gain_control);

	ClassDB::bind_method(D_METHOD("set_device_change_callback", "callback"),
			&DiscordClient::set_device_change_callback);

	ClassDB::bind_method(D_METHOD("set_echo_cancellation", "on"),
			&DiscordClient::set_echo_cancellation);

	ClassDB::bind_method(D_METHOD("set_engine_managed_audio_session", "is_engine_managed"),
			&DiscordClient::set_engine_managed_audio_session);

	ClassDB::bind_method(D_METHOD("set_game_window_pid", "pid"),
			&DiscordClient::set_game_window_pid);

	ClassDB::bind_method(D_METHOD("set_http_request_timeout", "http_timeout_in_milliseconds"),
			&DiscordClient::set_http_request_timeout);

	ClassDB::bind_method(D_METHOD("set_input_device", "device_id", "cb"),
			&DiscordClient::set_input_device);

	ClassDB::bind_method(D_METHOD("set_input_volume", "input_volume"),
			&DiscordClient::set_input_volume);

	ClassDB::bind_method(D_METHOD("set_lobby_created_callback", "cb"),
			&DiscordClient::set_lobby_created_callback);

	ClassDB::bind_method(D_METHOD("set_lobby_deleted_callback", "cb"),
			&DiscordClient::set_lobby_deleted_callback);

	ClassDB::bind_method(D_METHOD("set_lobby_member_added_callback", "cb"),
			&DiscordClient::set_lobby_member_added_callback);

	ClassDB::bind_method(D_METHOD("set_lobby_member_removed_callback", "cb"),
			&DiscordClient::set_lobby_member_removed_callback);

	ClassDB::bind_method(D_METHOD("set_lobby_member_updated_callback", "cb"),
			&DiscordClient::set_lobby_member_updated_callback);

	ClassDB::bind_method(D_METHOD("set_lobby_updated_callback", "cb"),
			&DiscordClient::set_lobby_updated_callback);

	ClassDB::bind_method(D_METHOD("set_log_dir", "path", "min_severity"),
			&DiscordClient::set_log_dir);

	ClassDB::bind_method(D_METHOD("set_message_created_callback", "cb"),
			&DiscordClient::set_message_created_callback);

	ClassDB::bind_method(D_METHOD("set_message_deleted_callback", "cb"),
			&DiscordClient::set_message_deleted_callback);

	ClassDB::bind_method(D_METHOD("set_message_updated_callback", "cb"),
			&DiscordClient::set_message_updated_callback);

	ClassDB::bind_method(D_METHOD("set_no_audio_input_callback", "callback"),
			&DiscordClient::set_no_audio_input_callback);

	ClassDB::bind_method(D_METHOD("set_no_audio_input_threshold", "d_bfsthreshold"),
			&DiscordClient::set_no_audio_input_threshold);

	ClassDB::bind_method(D_METHOD("set_noise_suppression", "on"),
			&DiscordClient::set_noise_suppression);

	ClassDB::bind_method(D_METHOD("set_online_status", "status", "callback"),
			&DiscordClient::set_online_status);

	ClassDB::bind_method(D_METHOD("set_opus_hardware_coding", "encode", "decode"),
			&DiscordClient::set_opus_hardware_coding);

	ClassDB::bind_method(D_METHOD("set_output_device", "device_id", "cb"),
			&DiscordClient::set_output_device);

	ClassDB::bind_method(D_METHOD("set_output_volume", "output_volume"),
			&DiscordClient::set_output_volume);

	ClassDB::bind_method(D_METHOD("set_relationship_created_callback", "cb"),
			&DiscordClient::set_relationship_created_callback);

	ClassDB::bind_method(D_METHOD("set_relationship_deleted_callback", "cb"),
			&DiscordClient::set_relationship_deleted_callback);

	ClassDB::bind_method(D_METHOD("set_relationship_groups_updated_callback", "cb"),
			&DiscordClient::set_relationship_groups_updated_callback);

	ClassDB::bind_method(D_METHOD("set_self_deaf_all", "deaf"),
			&DiscordClient::set_self_deaf_all);

	ClassDB::bind_method(D_METHOD("set_self_mute_all", "mute"),
			&DiscordClient::set_self_mute_all);

	ClassDB::bind_method(D_METHOD("set_showing_chat", "showing_chat"),
			&DiscordClient::set_showing_chat);

	ClassDB::bind_method(D_METHOD("set_speaker_mode", "speaker_mode"),
			&DiscordClient::set_speaker_mode);

	ClassDB::bind_method(D_METHOD("set_status_changed_callback", "cb"),
			&DiscordClient::set_status_changed_callback);

	ClassDB::bind_method(D_METHOD("set_thread_priority", "thread", "priority"),
			&DiscordClient::set_thread_priority);

	ClassDB::bind_method(D_METHOD("set_token_expiration_callback", "callback"),
			&DiscordClient::set_token_expiration_callback);

	ClassDB::bind_method(D_METHOD("set_user_updated_callback", "cb"),
			&DiscordClient::set_user_updated_callback);

	ClassDB::bind_method(D_METHOD("set_voice_log_dir", "path", "min_severity"),
			&DiscordClient::set_voice_log_dir);

	ClassDB::bind_method(D_METHOD("set_voice_participant_changed_callback", "cb"),
			&DiscordClient::set_voice_participant_changed_callback);

	ClassDB::bind_method(D_METHOD("show_audio_route_picker"),
			&DiscordClient::show_audio_route_picker);

	ClassDB::bind_method(D_METHOD("start_call", "channel_id"),
			&DiscordClient::start_call);

	ClassDB::bind_method(D_METHOD("start_call_with_audio_callbacks", "lobby_id", "received_cb", "captured_cb"),
			&DiscordClient::start_call_with_audio_callbacks);

	ClassDB::bind_method(D_METHOD("unblock_user", "user_id", "cb"),
			&DiscordClient::unblock_user);

	ClassDB::bind_method(D_METHOD("unlink_channel_from_lobby", "lobby_id", "callback"),
			&DiscordClient::unlink_channel_from_lobby);

	ClassDB::bind_method(D_METHOD("unmerge_into_provisional_account", "application_id", "external_auth_type", "external_auth_token", "callback"),
			&DiscordClient::unmerge_into_provisional_account);

	ClassDB::bind_method(D_METHOD("update_provisional_account_display_name", "name", "callback"),
			&DiscordClient::update_provisional_account_display_name);

	ClassDB::bind_method(D_METHOD("update_rich_presence", "activity", "cb"),
			&DiscordClient::update_rich_presence);

	ClassDB::bind_method(D_METHOD("update_token", "token_type", "token", "callback"),
			&DiscordClient::update_token);

	ClassDB::bind_static_method("DiscordClient", D_METHOD("error_to_string", "type"),
			&DiscordClient::error_to_string);

	ClassDB::bind_static_method("DiscordClient", D_METHOD("get_default_audio_device_id"),
			&DiscordClient::get_default_audio_device_id);

	ClassDB::bind_static_method("DiscordClient", D_METHOD("get_default_communication_scopes"),
			&DiscordClient::get_default_communication_scopes);

	ClassDB::bind_static_method("DiscordClient", D_METHOD("get_default_presence_scopes"),
			&DiscordClient::get_default_presence_scopes);

	ClassDB::bind_static_method("DiscordClient", D_METHOD("get_version_hash"),
			&DiscordClient::get_version_hash);

	ClassDB::bind_static_method("DiscordClient", D_METHOD("get_version_major"),
			&DiscordClient::get_version_major);

	ClassDB::bind_static_method("DiscordClient", D_METHOD("get_version_minor"),
			&DiscordClient::get_version_minor);

	ClassDB::bind_static_method("DiscordClient", D_METHOD("get_version_patch"),
			&DiscordClient::get_version_patch);

	ClassDB::bind_static_method("DiscordClient", D_METHOD("status_to_string", "type"),
			&DiscordClient::status_to_string);

	ClassDB::bind_static_method("DiscordClient", D_METHOD("thread_to_string", "type"),
			&DiscordClient::thread_to_string);
}
