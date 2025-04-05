// AUTO-GENERATED
#ifndef DISCORD_CLASSES_H
#define DISCORD_CLASSES_H

#include "discord_enum.h"
#include "discordpp.h"
#include "godot_cpp/classes/node.hpp"
#include "godot_cpp/classes/ref_counted.hpp"
#include "godot_cpp/variant/typed_array.hpp"
#include "godot_cpp/variant/typed_dictionary.hpp"

namespace godot {

class DiscordActivity;
class DiscordActivityAssets;
class DiscordActivityInvite;
class DiscordActivityParty;
class DiscordActivitySecrets;
class DiscordActivityTimestamps;
class DiscordAdditionalContent;
class DiscordAudioDevice;
class DiscordAuthorizationArgs;
class DiscordAuthorizationCodeChallenge;
class DiscordAuthorizationCodeVerifier;
class DiscordCall;
class DiscordCallInfoHandle;
class DiscordChannelHandle;
class DiscordClient;
class DiscordClientResult;
class DiscordDeviceAuthorizationArgs;
class DiscordGuildChannel;
class DiscordGuildMinimal;
class DiscordLinkedChannel;
class DiscordLinkedLobby;
class DiscordLobbyHandle;
class DiscordLobbyMemberHandle;
class DiscordMessageHandle;
class DiscordRelationshipHandle;
class DiscordUserHandle;
class DiscordVADThresholdSettings;
class DiscordVoiceStateHandle;

class DiscordActivity : public RefCounted {
	GDCLASS(DiscordActivity, RefCounted)

private:
	discordpp::Activity *activity;

protected:
	static void _bind_methods();

public:
	discordpp::Activity *unwrap(); // Internal usage.

	String name();
	void set_name(String name);
	DiscordActivityTypes::Enum type();
	void set_type(DiscordActivityTypes::Enum type);
	Variant state();
	void set_state(Variant state);
	Variant details();
	void set_details(Variant details);
	Variant application_id();
	void set_application_id(Variant application_id);
	Variant assets();
	void set_assets(Variant assets);
	Variant timestamps();
	void set_timestamps(Variant timestamps);
	Variant party();
	void set_party(Variant party);
	Variant secrets();
	void set_secrets(Variant secrets);
	DiscordActivityGamePlatforms::Enum supported_platforms();
	void set_supported_platforms(DiscordActivityGamePlatforms::Enum supported_platforms);

	DiscordActivity();
	DiscordActivity(discordpp::Activity *activity);
	~DiscordActivity();
};

class DiscordActivityAssets : public RefCounted {
	GDCLASS(DiscordActivityAssets, RefCounted)

private:
	discordpp::ActivityAssets *activity_assets;

protected:
	static void _bind_methods();

public:
	discordpp::ActivityAssets *unwrap(); // Internal usage.

	Variant large_image();
	void set_large_image(Variant large_image);
	Variant large_text();
	void set_large_text(Variant large_text);
	Variant small_image();
	void set_small_image(Variant small_image);
	Variant small_text();
	void set_small_text(Variant small_text);

	DiscordActivityAssets();
	DiscordActivityAssets(discordpp::ActivityAssets *activity_assets);
	~DiscordActivityAssets();
};

class DiscordActivityInvite : public RefCounted {
	GDCLASS(DiscordActivityInvite, RefCounted)

private:
	discordpp::ActivityInvite *activity_invite;

protected:
	static void _bind_methods();

public:
	discordpp::ActivityInvite *unwrap(); // Internal usage.

	uint64_t sender_id();
	void set_sender_id(uint64_t sender_id);
	uint64_t channel_id();
	void set_channel_id(uint64_t channel_id);
	uint64_t message_id();
	void set_message_id(uint64_t message_id);
	DiscordActivityActionTypes::Enum type();
	void set_type(DiscordActivityActionTypes::Enum type);
	uint64_t application_id();
	void set_application_id(uint64_t application_id);
	String party_id();
	void set_party_id(String party_id);
	bool is_valid();
	void set_is_valid(bool is_valid);

	DiscordActivityInvite();
	DiscordActivityInvite(discordpp::ActivityInvite *activity_invite);
	~DiscordActivityInvite();
};

class DiscordActivityParty : public RefCounted {
	GDCLASS(DiscordActivityParty, RefCounted)

private:
	discordpp::ActivityParty *activity_party;

protected:
	static void _bind_methods();

public:
	discordpp::ActivityParty *unwrap(); // Internal usage.

	String id();
	void set_id(String id);
	int32_t current_size();
	void set_current_size(int32_t current_size);
	int32_t max_size();
	void set_max_size(int32_t max_size);
	DiscordActivityPartyPrivacy::Enum privacy();
	void set_privacy(DiscordActivityPartyPrivacy::Enum privacy);

	DiscordActivityParty();
	DiscordActivityParty(discordpp::ActivityParty *activity_party);
	~DiscordActivityParty();
};

class DiscordActivitySecrets : public RefCounted {
	GDCLASS(DiscordActivitySecrets, RefCounted)

private:
	discordpp::ActivitySecrets *activity_secrets;

protected:
	static void _bind_methods();

public:
	discordpp::ActivitySecrets *unwrap(); // Internal usage.

	String join();
	void set_join(String join);

	DiscordActivitySecrets();
	DiscordActivitySecrets(discordpp::ActivitySecrets *activity_secrets);
	~DiscordActivitySecrets();
};

class DiscordActivityTimestamps : public RefCounted {
	GDCLASS(DiscordActivityTimestamps, RefCounted)

private:
	discordpp::ActivityTimestamps *activity_timestamps;

protected:
	static void _bind_methods();

public:
	discordpp::ActivityTimestamps *unwrap(); // Internal usage.

	uint64_t start();
	void set_start(uint64_t start);
	uint64_t end();
	void set_end(uint64_t end);

	DiscordActivityTimestamps();
	DiscordActivityTimestamps(discordpp::ActivityTimestamps *activity_timestamps);
	~DiscordActivityTimestamps();
};

class DiscordAdditionalContent : public RefCounted {
	GDCLASS(DiscordAdditionalContent, RefCounted)

private:
	discordpp::AdditionalContent *additional_content;

protected:
	static void _bind_methods();

public:
	discordpp::AdditionalContent *unwrap(); // Internal usage.

	bool equals(DiscordAdditionalContent *rhs);
	DiscordAdditionalContentType::Enum type();
	void set_type(DiscordAdditionalContentType::Enum type);
	Variant title();
	void set_title(Variant title);
	uint8_t count();
	void set_count(uint8_t count);

	DiscordAdditionalContent();
	DiscordAdditionalContent(discordpp::AdditionalContent *additional_content);
	~DiscordAdditionalContent();
};

class DiscordAudioDevice : public RefCounted {
	GDCLASS(DiscordAudioDevice, RefCounted)

private:
	discordpp::AudioDevice *audio_device;

	DiscordAudioDevice();

protected:
	static void _bind_methods();

public:
	discordpp::AudioDevice *unwrap(); // Internal usage.

	bool equals(DiscordAudioDevice *rhs);
	String id();
	void set_id(String id);
	String name();
	void set_name(String name);
	bool is_default();
	void set_is_default(bool is_default);

	DiscordAudioDevice(discordpp::AudioDevice *audio_device);
	~DiscordAudioDevice();
};

class DiscordAuthorizationArgs : public RefCounted {
	GDCLASS(DiscordAuthorizationArgs, RefCounted)

private:
	discordpp::AuthorizationArgs *authorization_args;

protected:
	static void _bind_methods();

public:
	discordpp::AuthorizationArgs *unwrap(); // Internal usage.

	uint64_t client_id();
	void set_client_id(uint64_t client_id);
	String scopes();
	void set_scopes(String scopes);
	Variant state();
	void set_state(Variant state);
	Variant nonce();
	void set_nonce(Variant nonce);
	Variant code_challenge();
	void set_code_challenge(Variant code_challenge);

	DiscordAuthorizationArgs();
	DiscordAuthorizationArgs(discordpp::AuthorizationArgs *authorization_args);
	~DiscordAuthorizationArgs();
};

class DiscordAuthorizationCodeChallenge : public RefCounted {
	GDCLASS(DiscordAuthorizationCodeChallenge, RefCounted)

private:
	discordpp::AuthorizationCodeChallenge *authorization_code_challenge;

protected:
	static void _bind_methods();

public:
	discordpp::AuthorizationCodeChallenge *unwrap(); // Internal usage.

	DiscordAuthenticationCodeChallengeMethod::Enum method();
	void set_method(DiscordAuthenticationCodeChallengeMethod::Enum method);
	String challenge();
	void set_challenge(String challenge);

	DiscordAuthorizationCodeChallenge();
	DiscordAuthorizationCodeChallenge(discordpp::AuthorizationCodeChallenge *authorization_code_challenge);
	~DiscordAuthorizationCodeChallenge();
};

class DiscordAuthorizationCodeVerifier : public RefCounted {
	GDCLASS(DiscordAuthorizationCodeVerifier, RefCounted)

private:
	discordpp::AuthorizationCodeVerifier *authorization_code_verifier;

	DiscordAuthorizationCodeVerifier();

protected:
	static void _bind_methods();

public:
	discordpp::AuthorizationCodeVerifier *unwrap(); // Internal usage.

	DiscordAuthorizationCodeChallenge *challenge();
	void set_challenge(DiscordAuthorizationCodeChallenge *challenge);
	String verifier();
	void set_verifier(String verifier);

	DiscordAuthorizationCodeVerifier(discordpp::AuthorizationCodeVerifier *authorization_code_verifier);
	~DiscordAuthorizationCodeVerifier();
};

class DiscordCall : public Node {
	GDCLASS(DiscordCall, Node)

private:
	discordpp::Call *call;

	DiscordCall();

protected:
	static void _bind_methods();

public:
	discordpp::Call *unwrap(); // Internal usage.

	DiscordAudioModeType::Enum get_audio_mode();
	uint64_t get_channel_id();
	uint64_t get_guild_id();
	bool get_local_mute(uint64_t user_id);
	TypedArray<uint64_t> get_participants();
	float get_participant_volume(uint64_t user_id);
	bool get_pttactive();
	bool get_self_deaf();
	bool get_self_mute();
	DiscordCallStatus::Enum get_status();
	DiscordVADThresholdSettings *get_vadthreshold();
	Variant get_voice_state_handle(uint64_t user_id);
	void set_audio_mode(DiscordAudioModeType::Enum audio_mode);
	void set_local_mute(uint64_t user_id, bool mute);
	void set_on_voice_state_changed_callback();
	void set_participant_changed_callback();
	void set_participant_volume(uint64_t user_id, float volume);
	void set_pttactive(bool active);
	void set_pttrelease_delay(uint32_t release_delay_ms);
	void set_self_deaf(bool deaf);
	void set_self_mute(bool mute);
	void set_speaking_status_changed_callback();
	void set_status_changed_callback();
	void set_vadthreshold(bool automatic, float threshold);

	DiscordCall(discordpp::Call *call);
	~DiscordCall();
};

class DiscordCallInfoHandle : public RefCounted {
	GDCLASS(DiscordCallInfoHandle, RefCounted)

private:
	discordpp::CallInfoHandle *call_info_handle;

	DiscordCallInfoHandle();

protected:
	static void _bind_methods();

public:
	discordpp::CallInfoHandle *unwrap(); // Internal usage.

	uint64_t channel_id();
	TypedArray<uint64_t> get_participants();
	Variant get_voice_state_handle(uint64_t user_id);
	uint64_t guild_id();

	DiscordCallInfoHandle(discordpp::CallInfoHandle *call_info_handle);
	~DiscordCallInfoHandle();
};

class DiscordChannelHandle : public RefCounted {
	GDCLASS(DiscordChannelHandle, RefCounted)

private:
	discordpp::ChannelHandle *channel_handle;

	DiscordChannelHandle();

protected:
	static void _bind_methods();

public:
	discordpp::ChannelHandle *unwrap(); // Internal usage.

	uint64_t id();
	String name();
	TypedArray<uint64_t> recipients();
	DiscordChannelType::Enum type();

	DiscordChannelHandle(discordpp::ChannelHandle *channel_handle);
	~DiscordChannelHandle();
};

class DiscordClient : public Node {
	GDCLASS(DiscordClient, Node)

private:
	discordpp::Client *client;

protected:
	static void _bind_methods();

public:
	discordpp::Client *unwrap(); // Internal usage.
	void _process(double delta);

	void end_call(uint64_t channel_id);
	void end_calls();
	DiscordCall *get_call(uint64_t channel_id);
	TypedArray<DiscordCall> get_calls();
	void get_current_input_device();
	void get_current_output_device();
	void get_input_devices();
	float get_input_volume();
	void get_output_devices();
	float get_output_volume();
	bool get_self_deaf_all();
	bool get_self_mute_all();
	void set_automatic_gain_control(bool on);
	void set_device_change_callback();
	void set_echo_cancellation(bool on);
	void set_input_device(String device_id);
	void set_input_volume(float input_volume);
	void set_no_audio_input_callback();
	void set_no_audio_input_threshold(float d_bfsthreshold);
	void set_noise_suppression(bool on);
	void set_opus_hardware_coding(bool encode, bool decode);
	void set_output_device(String device_id);
	void set_output_volume(float output_volume);
	void set_self_deaf_all(bool deaf);
	void set_self_mute_all(bool mute);
	bool set_speaker_mode(bool speaker_mode);
	void set_thread_priority(DiscordClientThread::Enum thread, int32_t priority);
	void set_voice_participant_changed_callback();
	bool show_audio_route_picker();
	DiscordCall *start_call(uint64_t channel_id);
	DiscordCall *start_call_with_audio_callbacks(uint64_t lobby_id);
	void abort_authorize();
	void abort_get_token_from_device();
	void authorize(DiscordAuthorizationArgs *args);
	void close_authorize_device_screen();
	DiscordAuthorizationCodeVerifier *create_authorization_code_verifier();
	void fetch_current_user(DiscordAuthorizationTokenType::Enum token_type, String token);
	void get_provisional_token(uint64_t application_id, DiscordAuthenticationExternalAuthType::Enum external_auth_type, String external_auth_token);
	void get_token(uint64_t application_id, String code, String code_verifier, String redirect_uri);
	void get_token_from_device(DiscordDeviceAuthorizationArgs *args);
	void get_token_from_device_provisional_merge(DiscordDeviceAuthorizationArgs *args, DiscordAuthenticationExternalAuthType::Enum external_auth_type, String external_auth_token);
	void get_token_from_provisional_merge(uint64_t application_id, String code, String code_verifier, String redirect_uri, DiscordAuthenticationExternalAuthType::Enum external_auth_type, String external_auth_token);
	bool is_authenticated();
	void open_authorize_device_screen(uint64_t client_id, String user_code);
	void provisional_user_merge_completed(bool success);
	void refresh_token(uint64_t application_id, String refresh_token);
	void set_authorize_device_screen_closed_callback();
	void set_game_window_pid(int32_t pid);
	void set_token_expiration_callback();
	void update_provisional_account_display_name(String name);
	void update_token(DiscordAuthorizationTokenType::Enum token_type, String token);
	bool can_open_message_in_discord(uint64_t message_id);
	void delete_user_message(uint64_t recipient_id, uint64_t message_id);
	void edit_user_message(uint64_t recipient_id, uint64_t message_id, String content);
	Variant get_channel_handle(uint64_t channel_id);
	Variant get_message_handle(uint64_t message_id);
	void open_message_in_discord(uint64_t message_id);
	void send_lobby_message(uint64_t lobby_id, String content);
	void send_lobby_message_with_metadata(uint64_t lobby_id, String content, TypedDictionary<String, String> metadata);
	void send_user_message(uint64_t recipient_id, String content);
	void send_user_message_with_metadata(uint64_t recipient_id, String content, TypedDictionary<String, String> metadata);
	void set_message_created_callback();
	void set_message_deleted_callback();
	void set_message_updated_callback();
	void set_showing_chat(bool showing_chat);
	void add_log_callback(DiscordLoggingSeverity::Enum min_severity);
	void add_voice_log_callback(DiscordLoggingSeverity::Enum min_severity);
	void connect();
	void disconnect();
	DiscordClientStatus::Enum get_status();
	bool set_log_dir(String path, DiscordLoggingSeverity::Enum min_severity);
	void set_status_changed_callback();
	void set_voice_log_dir(String path, DiscordLoggingSeverity::Enum min_severity);
	void create_or_join_lobby(String secret);
	void create_or_join_lobby_with_metadata(String secret, TypedDictionary<String, String> lobby_metadata, TypedDictionary<String, String> member_metadata);
	void get_guild_channels(uint64_t guild_id);
	Variant get_lobby_handle(uint64_t lobby_id);
	TypedArray<uint64_t> get_lobby_ids();
	void get_user_guilds();
	void leave_lobby(uint64_t lobby_id);
	void link_channel_to_lobby(uint64_t lobby_id, uint64_t channel_id);
	void set_lobby_created_callback();
	void set_lobby_deleted_callback();
	void set_lobby_member_added_callback();
	void set_lobby_member_removed_callback();
	void set_lobby_member_updated_callback();
	void set_lobby_updated_callback();
	void unlink_channel_from_lobby(uint64_t lobby_id);
	void accept_activity_invite(DiscordActivityInvite *invite);
	void clear_rich_presence();
	bool register_launch_command(uint64_t application_id, String command);
	bool register_launch_steam_application(uint64_t application_id, uint32_t steam_app_id);
	void send_activity_invite(uint64_t user_id, String content);
	void send_activity_join_request(uint64_t user_id);
	void send_activity_join_request_reply(DiscordActivityInvite *invite);
	void set_activity_invite_created_callback();
	void set_activity_invite_updated_callback();
	void set_activity_join_callback();
	void set_online_status(DiscordStatusType::Enum status);
	void update_rich_presence(DiscordActivity *activity);
	void accept_discord_friend_request(uint64_t user_id);
	void accept_game_friend_request(uint64_t user_id);
	void block_user(uint64_t user_id);
	void cancel_discord_friend_request(uint64_t user_id);
	void cancel_game_friend_request(uint64_t user_id);
	DiscordRelationshipHandle *get_relationship_handle(uint64_t user_id);
	TypedArray<DiscordRelationshipHandle> get_relationships();
	void reject_discord_friend_request(uint64_t user_id);
	void reject_game_friend_request(uint64_t user_id);
	void remove_discord_and_game_friend(uint64_t user_id);
	void remove_game_friend(uint64_t user_id);
	TypedArray<DiscordUserHandle> search_friends_by_username(String search_str);
	void send_discord_friend_request(String username);
	void send_discord_friend_request_by_id(uint64_t user_id);
	void send_game_friend_request(String username);
	void send_game_friend_request_by_id(uint64_t user_id);
	void set_relationship_created_callback();
	void set_relationship_deleted_callback();
	void unblock_user(uint64_t user_id);
	DiscordUserHandle *get_current_user();
	void get_discord_client_connected_user(uint64_t application_id);
	Variant get_user(uint64_t user_id);
	void set_user_updated_callback();

	DiscordClient();
	DiscordClient(discordpp::Client *client);
	~DiscordClient();
};

class DiscordClientResult : public RefCounted {
	GDCLASS(DiscordClientResult, RefCounted)

private:
	discordpp::ClientResult *client_result;

	DiscordClientResult();

protected:
	static void _bind_methods();

public:
	discordpp::ClientResult *unwrap(); // Internal usage.

	String to_string();
	DiscordErrorType::Enum type();
	void set_type(DiscordErrorType::Enum type);
	String error();
	void set_error(String error);
	int32_t error_code();
	void set_error_code(int32_t error_code);
	DiscordHttpStatusCode::Enum status();
	void set_status(DiscordHttpStatusCode::Enum status);
	String response_body();
	void set_response_body(String response_body);
	bool successful();
	void set_successful(bool successful);
	bool retryable();
	void set_retryable(bool retryable);
	float retry_after();
	void set_retry_after(float retry_after);

	DiscordClientResult(discordpp::ClientResult *client_result);
	~DiscordClientResult();
};

class DiscordDeviceAuthorizationArgs : public RefCounted {
	GDCLASS(DiscordDeviceAuthorizationArgs, RefCounted)

private:
	discordpp::DeviceAuthorizationArgs *device_authorization_args;

protected:
	static void _bind_methods();

public:
	discordpp::DeviceAuthorizationArgs *unwrap(); // Internal usage.

	uint64_t client_id();
	void set_client_id(uint64_t client_id);
	String scopes();
	void set_scopes(String scopes);

	DiscordDeviceAuthorizationArgs();
	DiscordDeviceAuthorizationArgs(discordpp::DeviceAuthorizationArgs *device_authorization_args);
	~DiscordDeviceAuthorizationArgs();
};

class DiscordGuildChannel : public RefCounted {
	GDCLASS(DiscordGuildChannel, RefCounted)

private:
	discordpp::GuildChannel *guild_channel;

	DiscordGuildChannel();

protected:
	static void _bind_methods();

public:
	discordpp::GuildChannel *unwrap(); // Internal usage.

	uint64_t id();
	void set_id(uint64_t id);
	String name();
	void set_name(String name);
	bool is_linkable();
	void set_is_linkable(bool is_linkable);
	bool is_viewable_and_writeable_by_all_members();
	void set_is_viewable_and_writeable_by_all_members(bool is_viewable_and_writeable_by_all_members);
	Variant linked_lobby();
	void set_linked_lobby(Variant linked_lobby);

	DiscordGuildChannel(discordpp::GuildChannel *guild_channel);
	~DiscordGuildChannel();
};

class DiscordGuildMinimal : public RefCounted {
	GDCLASS(DiscordGuildMinimal, RefCounted)

private:
	discordpp::GuildMinimal *guild_minimal;

	DiscordGuildMinimal();

protected:
	static void _bind_methods();

public:
	discordpp::GuildMinimal *unwrap(); // Internal usage.

	uint64_t id();
	void set_id(uint64_t id);
	String name();
	void set_name(String name);

	DiscordGuildMinimal(discordpp::GuildMinimal *guild_minimal);
	~DiscordGuildMinimal();
};

class DiscordLinkedChannel : public RefCounted {
	GDCLASS(DiscordLinkedChannel, RefCounted)

private:
	discordpp::LinkedChannel *linked_channel;

	DiscordLinkedChannel();

protected:
	static void _bind_methods();

public:
	discordpp::LinkedChannel *unwrap(); // Internal usage.

	uint64_t id();
	void set_id(uint64_t id);
	String name();
	void set_name(String name);
	uint64_t guild_id();
	void set_guild_id(uint64_t guild_id);

	DiscordLinkedChannel(discordpp::LinkedChannel *linked_channel);
	~DiscordLinkedChannel();
};

class DiscordLinkedLobby : public RefCounted {
	GDCLASS(DiscordLinkedLobby, RefCounted)

private:
	discordpp::LinkedLobby *linked_lobby;

protected:
	static void _bind_methods();

public:
	discordpp::LinkedLobby *unwrap(); // Internal usage.

	uint64_t application_id();
	void set_application_id(uint64_t application_id);
	uint64_t lobby_id();
	void set_lobby_id(uint64_t lobby_id);

	DiscordLinkedLobby();
	DiscordLinkedLobby(discordpp::LinkedLobby *linked_lobby);
	~DiscordLinkedLobby();
};

class DiscordLobbyHandle : public RefCounted {
	GDCLASS(DiscordLobbyHandle, RefCounted)

private:
	discordpp::LobbyHandle *lobby_handle;

	DiscordLobbyHandle();

protected:
	static void _bind_methods();

public:
	discordpp::LobbyHandle *unwrap(); // Internal usage.

	Variant get_call_info_handle();
	Variant get_lobby_member_handle(uint64_t member_id);
	uint64_t id();
	Variant linked_channel();
	TypedArray<uint64_t> lobby_member_ids();
	TypedArray<DiscordLobbyMemberHandle> lobby_members();
	TypedDictionary<String, String> metadata();

	DiscordLobbyHandle(discordpp::LobbyHandle *lobby_handle);
	~DiscordLobbyHandle();
};

class DiscordLobbyMemberHandle : public RefCounted {
	GDCLASS(DiscordLobbyMemberHandle, RefCounted)

private:
	discordpp::LobbyMemberHandle *lobby_member_handle;

	DiscordLobbyMemberHandle();

protected:
	static void _bind_methods();

public:
	discordpp::LobbyMemberHandle *unwrap(); // Internal usage.

	bool can_link_lobby();
	bool connected();
	uint64_t id();
	TypedDictionary<String, String> metadata();
	Variant user();

	DiscordLobbyMemberHandle(discordpp::LobbyMemberHandle *lobby_member_handle);
	~DiscordLobbyMemberHandle();
};

class DiscordMessageHandle : public RefCounted {
	GDCLASS(DiscordMessageHandle, RefCounted)

private:
	discordpp::MessageHandle *message_handle;

	DiscordMessageHandle();

protected:
	static void _bind_methods();

public:
	discordpp::MessageHandle *unwrap(); // Internal usage.

	Variant additional_content();
	Variant author();
	uint64_t author_id();
	Variant channel();
	uint64_t channel_id();
	String content();
	Variant disclosure_type();
	uint64_t edited_timestamp();
	uint64_t id();
	Variant lobby();
	TypedDictionary<String, String> metadata();
	String raw_content();
	Variant recipient();
	uint64_t recipient_id();
	bool sent_from_game();
	uint64_t sent_timestamp();

	DiscordMessageHandle(discordpp::MessageHandle *message_handle);
	~DiscordMessageHandle();
};

class DiscordRelationshipHandle : public RefCounted {
	GDCLASS(DiscordRelationshipHandle, RefCounted)

private:
	discordpp::RelationshipHandle *relationship_handle;

	DiscordRelationshipHandle();

protected:
	static void _bind_methods();

public:
	discordpp::RelationshipHandle *unwrap(); // Internal usage.

	DiscordRelationshipType::Enum discord_relationship_type();
	DiscordRelationshipType::Enum game_relationship_type();
	uint64_t id();
	Variant user();

	DiscordRelationshipHandle(discordpp::RelationshipHandle *relationship_handle);
	~DiscordRelationshipHandle();
};

class DiscordUserHandle : public RefCounted {
	GDCLASS(DiscordUserHandle, RefCounted)

private:
	discordpp::UserHandle *user_handle;

	DiscordUserHandle();

protected:
	static void _bind_methods();

public:
	discordpp::UserHandle *unwrap(); // Internal usage.

	Variant avatar();
	String avatar_url(DiscordUserHandleAvatarType::Enum animated_type, DiscordUserHandleAvatarType::Enum static_type);
	String display_name();
	Variant game_activity();
	Variant global_name();
	uint64_t id();
	bool is_provisional();
	DiscordRelationshipHandle *relationship();
	DiscordStatusType::Enum status();
	String username();

	DiscordUserHandle(discordpp::UserHandle *user_handle);
	~DiscordUserHandle();
};

class DiscordVADThresholdSettings : public RefCounted {
	GDCLASS(DiscordVADThresholdSettings, RefCounted)

private:
	discordpp::VADThresholdSettings *vadthreshold_settings;

	DiscordVADThresholdSettings();

protected:
	static void _bind_methods();

public:
	discordpp::VADThresholdSettings *unwrap(); // Internal usage.

	float vad_threshold();
	void set_vad_threshold(float vad_threshold);
	bool automatic();
	void set_automatic(bool automatic);

	DiscordVADThresholdSettings(discordpp::VADThresholdSettings *vadthreshold_settings);
	~DiscordVADThresholdSettings();
};

class DiscordVoiceStateHandle : public RefCounted {
	GDCLASS(DiscordVoiceStateHandle, RefCounted)

private:
	discordpp::VoiceStateHandle *voice_state_handle;

	DiscordVoiceStateHandle();

protected:
	static void _bind_methods();

public:
	discordpp::VoiceStateHandle *unwrap(); // Internal usage.

	bool self_deaf();
	bool self_mute();

	DiscordVoiceStateHandle(discordpp::VoiceStateHandle *voice_state_handle);
	~DiscordVoiceStateHandle();
};

} //namespace godot

#endif
