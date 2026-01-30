
#ifndef DISCORD_CLASSES_H
#define DISCORD_CLASSES_H

#include "discord_enum.h"
#include "discordpp.h"
#include "godot_cpp/classes/node.hpp"
#include "godot_cpp/classes/ref_counted.hpp"
#include "godot_cpp/variant/typed_array.hpp"
#include "godot_cpp/variant/typed_dictionary.hpp"

namespace godot {

// Declarations.
class Discord;
class DiscordActivity;
class DiscordActivityAssets;
class DiscordActivityButton;
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
class DiscordClientCreateOptions;
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
class DiscordUserApplicationProfileHandle;
class DiscordUserHandle;
class DiscordUserMessageSummary;
class DiscordVADThresholdSettings;
class DiscordVoiceStateHandle;

// Definitions.

class Discord : public RefCounted {
	GDCLASS(Discord, RefCounted)

private:
	Discord() {}

protected:
	static void _bind_methods();

public:
	// Functions.
	void run_callbacks();

	// Overloading functions.
	String enum_to_string(int value, Variant enum_type);

	~Discord() {}
};

class DiscordActivity : public RefCounted {
	GDCLASS(DiscordActivity, RefCounted)

private:
	discordpp::Activity *obj;

protected:
	static void _bind_methods();

public:
	// Internal usage.
	discordpp::Activity *unwrap() {
		return obj;
	}

	void add_button(DiscordActivityButton button);
	bool equals(DiscordActivity other);
	TypedArray<DiscordActivityButton> get_buttons();
	String name();
	void set_name(String name);
	DiscordActivityTypes type();
	void set_type(DiscordActivityTypes type);
	Variant status_display_type();
	void set_status_display_type(Variant status_display_type);
	Variant state();
	void set_state(Variant state);
	Variant state_url();
	void set_state_url(Variant state_url);
	Variant details();
	void set_details(Variant details);
	Variant details_url();
	void set_details_url(Variant details_url);
	Variant application_id();
	void set_application_id(Variant application_id);
	Variant parent_application_id();
	void set_parent_application_id(Variant parent_application_id);
	Variant assets();
	void set_assets(Variant assets);
	Variant timestamps();
	void set_timestamps(Variant timestamps);
	Variant party();
	void set_party(Variant party);
	Variant secrets();
	void set_secrets(Variant secrets);
	DiscordActivityGamePlatforms supported_platforms();
	void set_supported_platforms(DiscordActivityGamePlatforms supported_platforms);

	DiscordActivity() {
		this->obj = memnew(discordpp::Activity);
	}

	// Internal usage.
	DiscordActivity(discordpp::Activity *obj) {
		this->obj = obj;
	}

	~DiscordActivity() {
		memdelete(this->obj);
	}
};

class DiscordActivityAssets : public RefCounted {
	GDCLASS(DiscordActivityAssets, RefCounted)

private:
	discordpp::ActivityAssets *obj;

protected:
	static void _bind_methods();

public:
	// Internal usage.
	discordpp::ActivityAssets *unwrap() {
		return obj;
	}

	Variant large_image();
	void set_large_image(Variant large_image);
	Variant large_text();
	void set_large_text(Variant large_text);
	Variant large_url();
	void set_large_url(Variant large_url);
	Variant small_image();
	void set_small_image(Variant small_image);
	Variant small_text();
	void set_small_text(Variant small_text);
	Variant small_url();
	void set_small_url(Variant small_url);
	Variant invite_cover_image();
	void set_invite_cover_image(Variant invite_cover_image);

	DiscordActivityAssets() {
		this->obj = memnew(discordpp::ActivityAssets);
	}

	// Internal usage.
	DiscordActivityAssets(discordpp::ActivityAssets *obj) {
		this->obj = obj;
	}

	~DiscordActivityAssets() {
		memdelete(this->obj);
	}
};

class DiscordActivityButton : public RefCounted {
	GDCLASS(DiscordActivityButton, RefCounted)

private:
	discordpp::ActivityButton *obj;

protected:
	static void _bind_methods();

public:
	// Internal usage.
	discordpp::ActivityButton *unwrap() {
		return obj;
	}

	String label();
	void set_label(String label);
	String url();
	void set_url(String url);

	DiscordActivityButton() {
		this->obj = memnew(discordpp::ActivityButton);
	}

	// Internal usage.
	DiscordActivityButton(discordpp::ActivityButton *obj) {
		this->obj = obj;
	}

	~DiscordActivityButton() {
		memdelete(this->obj);
	}
};

class DiscordActivityInvite : public RefCounted {
	GDCLASS(DiscordActivityInvite, RefCounted)

private:
	discordpp::ActivityInvite *obj;

protected:
	static void _bind_methods();

public:
	// Internal usage.
	discordpp::ActivityInvite *unwrap() {
		return obj;
	}

	int64_t sender_id();
	void set_sender_id(int64_t sender_id);
	int64_t channel_id();
	void set_channel_id(int64_t channel_id);
	int64_t message_id();
	void set_message_id(int64_t message_id);
	DiscordActivityActionTypes type();
	void set_type(DiscordActivityActionTypes type);
	int64_t application_id();
	void set_application_id(int64_t application_id);
	int64_t parent_application_id();
	void set_parent_application_id(int64_t parent_application_id);
	String party_id();
	void set_party_id(String party_id);
	String session_id();
	void set_session_id(String session_id);
	bool is_valid();
	void set_is_valid(bool is_valid);

	DiscordActivityInvite() {
		this->obj = memnew(discordpp::ActivityInvite);
	}

	// Internal usage.
	DiscordActivityInvite(discordpp::ActivityInvite *obj) {
		this->obj = obj;
	}

	~DiscordActivityInvite() {
		memdelete(this->obj);
	}
};

class DiscordActivityParty : public RefCounted {
	GDCLASS(DiscordActivityParty, RefCounted)

private:
	discordpp::ActivityParty *obj;

protected:
	static void _bind_methods();

public:
	// Internal usage.
	discordpp::ActivityParty *unwrap() {
		return obj;
	}

	String id();
	void set_id(String id);
	int64_t current_size();
	void set_current_size(int64_t current_size);
	int64_t max_size();
	void set_max_size(int64_t max_size);
	DiscordActivityPartyPrivacy privacy();
	void set_privacy(DiscordActivityPartyPrivacy privacy);

	DiscordActivityParty() {
		this->obj = memnew(discordpp::ActivityParty);
	}

	// Internal usage.
	DiscordActivityParty(discordpp::ActivityParty *obj) {
		this->obj = obj;
	}

	~DiscordActivityParty() {
		memdelete(this->obj);
	}
};

class DiscordActivitySecrets : public RefCounted {
	GDCLASS(DiscordActivitySecrets, RefCounted)

private:
	discordpp::ActivitySecrets *obj;

protected:
	static void _bind_methods();

public:
	// Internal usage.
	discordpp::ActivitySecrets *unwrap() {
		return obj;
	}

	String join();
	void set_join(String join);

	DiscordActivitySecrets() {
		this->obj = memnew(discordpp::ActivitySecrets);
	}

	// Internal usage.
	DiscordActivitySecrets(discordpp::ActivitySecrets *obj) {
		this->obj = obj;
	}

	~DiscordActivitySecrets() {
		memdelete(this->obj);
	}
};

class DiscordActivityTimestamps : public RefCounted {
	GDCLASS(DiscordActivityTimestamps, RefCounted)

private:
	discordpp::ActivityTimestamps *obj;

protected:
	static void _bind_methods();

public:
	// Internal usage.
	discordpp::ActivityTimestamps *unwrap() {
		return obj;
	}

	int64_t start();
	void set_start(int64_t start);
	int64_t end();
	void set_end(int64_t end);

	DiscordActivityTimestamps() {
		this->obj = memnew(discordpp::ActivityTimestamps);
	}

	// Internal usage.
	DiscordActivityTimestamps(discordpp::ActivityTimestamps *obj) {
		this->obj = obj;
	}

	~DiscordActivityTimestamps() {
		memdelete(this->obj);
	}
};

class DiscordAdditionalContent : public RefCounted {
	GDCLASS(DiscordAdditionalContent, RefCounted)

private:
	discordpp::AdditionalContent *obj;

protected:
	static void _bind_methods();

public:
	// Internal usage.
	discordpp::AdditionalContent *unwrap() {
		return obj;
	}

	bool equals(DiscordAdditionalContent rhs);
	DiscordAdditionalContentType type();
	void set_type(DiscordAdditionalContentType type);
	Variant title();
	void set_title(Variant title);
	int64_t count();
	void set_count(int64_t count);
	static String type_to_string(DiscordAdditionalContentType type);

	DiscordAdditionalContent() {
		this->obj = memnew(discordpp::AdditionalContent);
	}

	// Internal usage.
	DiscordAdditionalContent(discordpp::AdditionalContent *obj) {
		this->obj = obj;
	}

	~DiscordAdditionalContent() {
		memdelete(this->obj);
	}
};

class DiscordAudioDevice : public RefCounted {
	GDCLASS(DiscordAudioDevice, RefCounted)

private:
	discordpp::AudioDevice *obj;

	DiscordAudioDevice() {}

protected:
	static void _bind_methods();

public:
	// Internal usage.
	discordpp::AudioDevice *unwrap() {
		return obj;
	}

	bool equals(DiscordAudioDevice rhs);
	String id();
	void set_id(String id);
	String name();
	void set_name(String name);
	bool is_default();
	void set_is_default(bool is_default);

	// Internal usage.
	DiscordAudioDevice(discordpp::AudioDevice *obj) {
		this->obj = obj;
	}

	~DiscordAudioDevice() {
		memdelete(this->obj);
	}
};

class DiscordAuthorizationArgs : public RefCounted {
	GDCLASS(DiscordAuthorizationArgs, RefCounted)

private:
	discordpp::AuthorizationArgs *obj;

protected:
	static void _bind_methods();

public:
	// Internal usage.
	discordpp::AuthorizationArgs *unwrap() {
		return obj;
	}

	int64_t client_id();
	void set_client_id(int64_t client_id);
	String scopes();
	void set_scopes(String scopes);
	Variant state();
	void set_state(Variant state);
	Variant nonce();
	void set_nonce(Variant nonce);
	Variant code_challenge();
	void set_code_challenge(Variant code_challenge);
	Variant integration_type();
	void set_integration_type(Variant integration_type);
	Variant custom_scheme_param();
	void set_custom_scheme_param(Variant custom_scheme_param);

	DiscordAuthorizationArgs() {
		this->obj = memnew(discordpp::AuthorizationArgs);
	}

	// Internal usage.
	DiscordAuthorizationArgs(discordpp::AuthorizationArgs *obj) {
		this->obj = obj;
	}

	~DiscordAuthorizationArgs() {
		memdelete(this->obj);
	}
};

class DiscordAuthorizationCodeChallenge : public RefCounted {
	GDCLASS(DiscordAuthorizationCodeChallenge, RefCounted)

private:
	discordpp::AuthorizationCodeChallenge *obj;

protected:
	static void _bind_methods();

public:
	// Internal usage.
	discordpp::AuthorizationCodeChallenge *unwrap() {
		return obj;
	}

	DiscordAuthenticationCodeChallengeMethod method();
	void set_method(DiscordAuthenticationCodeChallengeMethod method);
	String challenge();
	void set_challenge(String challenge);

	DiscordAuthorizationCodeChallenge() {
		this->obj = memnew(discordpp::AuthorizationCodeChallenge);
	}

	// Internal usage.
	DiscordAuthorizationCodeChallenge(discordpp::AuthorizationCodeChallenge *obj) {
		this->obj = obj;
	}

	~DiscordAuthorizationCodeChallenge() {
		memdelete(this->obj);
	}
};

class DiscordAuthorizationCodeVerifier : public RefCounted {
	GDCLASS(DiscordAuthorizationCodeVerifier, RefCounted)

private:
	discordpp::AuthorizationCodeVerifier *obj;

	DiscordAuthorizationCodeVerifier() {}

protected:
	static void _bind_methods();

public:
	// Internal usage.
	discordpp::AuthorizationCodeVerifier *unwrap() {
		return obj;
	}

	DiscordAuthorizationCodeChallenge challenge();
	void set_challenge(DiscordAuthorizationCodeChallenge challenge);
	String verifier();
	void set_verifier(String verifier);

	// Internal usage.
	DiscordAuthorizationCodeVerifier(discordpp::AuthorizationCodeVerifier *obj) {
		this->obj = obj;
	}

	~DiscordAuthorizationCodeVerifier() {
		memdelete(this->obj);
	}
};

class DiscordCall : public RefCounted {
	GDCLASS(DiscordCall, RefCounted)

private:
	discordpp::Call *obj;

	DiscordCall() {}

protected:
	static void _bind_methods();

public:
	// Internal usage.
	discordpp::Call *unwrap() {
		return obj;
	}

	DiscordAudioModeType get_audio_mode();
	int64_t get_channel_id();
	int64_t get_guild_id();
	bool get_local_mute(int64_t user_id);
	TypedArray<int64_t> get_participants();
	float get_participant_volume(int64_t user_id);
	bool get_pttactive();
	int64_t get_pttrelease_delay();
	bool get_self_deaf();
	bool get_self_mute();
	DiscordCallStatus get_status();
	DiscordVADThresholdSettings get_vadthreshold();
	Variant get_voice_state_handle(int64_t user_id);
	void set_audio_mode(DiscordAudioModeType audio_mode);
	void set_local_mute(int64_t user_id, bool mute);
	void set_on_voice_state_changed_callback(Callable cb);
	void set_participant_changed_callback(Callable cb);
	void set_participant_volume(int64_t user_id, float volume);
	void set_pttactive(bool active);
	void set_pttrelease_delay(int64_t release_delay_ms);
	void set_self_deaf(bool deaf);
	void set_self_mute(bool mute);
	void set_speaking_status_changed_callback(Callable cb);
	void set_status_changed_callback(Callable cb);
	void set_vadthreshold(bool automatic, float threshold);
	static String error_to_string(DiscordCallError type);
	static String status_to_string(DiscordCallStatus type);

	// Internal usage.
	DiscordCall(discordpp::Call *obj) {
		this->obj = obj;
	}

	~DiscordCall() {
		memdelete(this->obj);
	}
};

class DiscordCallInfoHandle : public RefCounted {
	GDCLASS(DiscordCallInfoHandle, RefCounted)

private:
	discordpp::CallInfoHandle *obj;

	DiscordCallInfoHandle() {}

protected:
	static void _bind_methods();

public:
	// Internal usage.
	discordpp::CallInfoHandle *unwrap() {
		return obj;
	}

	int64_t channel_id();
	TypedArray<int64_t> get_participants();
	Variant get_voice_state_handle(int64_t user_id);
	int64_t guild_id();

	// Internal usage.
	DiscordCallInfoHandle(discordpp::CallInfoHandle *obj) {
		this->obj = obj;
	}

	~DiscordCallInfoHandle() {
		memdelete(this->obj);
	}
};

class DiscordChannelHandle : public RefCounted {
	GDCLASS(DiscordChannelHandle, RefCounted)

private:
	discordpp::ChannelHandle *obj;

	DiscordChannelHandle() {}

protected:
	static void _bind_methods();

public:
	// Internal usage.
	discordpp::ChannelHandle *unwrap() {
		return obj;
	}

	int64_t id();
	String name();
	TypedArray<int64_t> recipients();
	DiscordChannelType type();

	// Internal usage.
	DiscordChannelHandle(discordpp::ChannelHandle *obj) {
		this->obj = obj;
	}

	~DiscordChannelHandle() {
		memdelete(this->obj);
	}
};

class DiscordClient : public RefCounted {
	GDCLASS(DiscordClient, RefCounted)

private:
	discordpp::Client *obj;

protected:
	static void _bind_methods();

public:
	// Internal usage.
	discordpp::Client *unwrap() {
		return obj;
	}

	void end_call(int64_t channel_id, Callable callback);
	void end_calls(Callable callback);
	DiscordCall get_call(int64_t channel_id);
	TypedArray<DiscordCall> get_calls();
	void get_current_input_device(Callable cb);
	void get_current_output_device(Callable cb);
	void get_input_devices(Callable cb);
	float get_input_volume();
	void get_output_devices(Callable cb);
	float get_output_volume();
	bool get_self_deaf_all();
	bool get_self_mute_all();
	void set_aec_dump(bool on);
	void set_automatic_gain_control(bool on);
	void set_device_change_callback(Callable callback);
	void set_echo_cancellation(bool on);
	void set_engine_managed_audio_session(bool is_engine_managed);
	void set_input_device(String device_id, Callable cb);
	void set_input_volume(float input_volume);
	void set_no_audio_input_callback(Callable callback);
	void set_no_audio_input_threshold(float d_bfsthreshold);
	void set_noise_suppression(bool on);
	void set_opus_hardware_coding(bool encode, bool decode);
	void set_output_device(String device_id, Callable cb);
	void set_output_volume(float output_volume);
	void set_self_deaf_all(bool deaf);
	void set_self_mute_all(bool mute);
	bool set_speaker_mode(bool speaker_mode);
	void set_thread_priority(DiscordClientThread thread, int64_t priority);
	void set_voice_participant_changed_callback(Callable cb);
	bool show_audio_route_picker();
	DiscordCall start_call(int64_t channel_id);
	DiscordCall start_call_with_audio_callbacks(int64_t lobby_id, Callable received_cb, Callable captured_cb);
	void abort_authorize();
	void abort_get_token_from_device();
	void authorize(DiscordAuthorizationArgs args, Callable callback);
	void close_authorize_device_screen();
	DiscordAuthorizationCodeVerifier create_authorization_code_verifier();
	void exchange_child_token(String parent_application_token, int64_t child_application_id, Callable callback);
	void fetch_current_user(DiscordAuthorizationTokenType token_type, String token, Callable callback);
	void get_provisional_token(int64_t application_id, DiscordAuthenticationExternalAuthType external_auth_type, String external_auth_token, Callable callback);
	void get_token(int64_t application_id, String code, String code_verifier, String redirect_uri, Callable callback);
	void get_token_from_device(DiscordDeviceAuthorizationArgs args, Callable callback);
	void get_token_from_device_provisional_merge(DiscordDeviceAuthorizationArgs args, DiscordAuthenticationExternalAuthType external_auth_type, String external_auth_token, Callable callback);
	void get_token_from_provisional_merge(int64_t application_id, String code, String code_verifier, String redirect_uri, DiscordAuthenticationExternalAuthType external_auth_type, String external_auth_token, Callable callback);
	bool is_authenticated();
	void open_authorize_device_screen(int64_t client_id, String user_code);
	void provisional_user_merge_completed(bool success);
	void refresh_token(int64_t application_id, String refresh_token, Callable callback);
	void register_authorize_request_callback(Callable callback);
	void remove_authorize_request_callback();
	void revoke_token(int64_t application_id, String token, Callable callback);
	void set_authorize_device_screen_closed_callback(Callable cb);
	void set_game_window_pid(int64_t pid);
	void set_token_expiration_callback(Callable callback);
	void unmerge_into_provisional_account(int64_t application_id, DiscordAuthenticationExternalAuthType external_auth_type, String external_auth_token, Callable callback);
	void update_provisional_account_display_name(String name, Callable callback);
	void update_token(DiscordAuthorizationTokenType token_type, String token, Callable callback);
	bool can_open_message_in_discord(int64_t message_id);
	void delete_user_message(int64_t recipient_id, int64_t message_id, Callable cb);
	void edit_user_message(int64_t recipient_id, int64_t message_id, String content, Callable cb);
	Variant get_channel_handle(int64_t channel_id);
	void get_lobby_messages_with_limit(int64_t lobby_id, int64_t limit, Callable cb);
	Variant get_message_handle(int64_t message_id);
	void get_user_message_summaries(Callable cb);
	void get_user_messages_with_limit(int64_t recipient_id, int64_t limit, Callable cb);
	void open_message_in_discord(int64_t message_id, Callable provisional_user_merge_required_callback, Callable callback);
	void send_lobby_message(int64_t lobby_id, String content, Callable cb);
	void send_lobby_message_with_metadata(int64_t lobby_id, String content, TypedDictionary<String, String> metadata, Callable cb);
	void send_user_message(int64_t recipient_id, String content, Callable cb);
	void send_user_message_with_metadata(int64_t recipient_id, String content, TypedDictionary<String, String> metadata, Callable cb);
	void set_message_created_callback(Callable cb);
	void set_message_deleted_callback(Callable cb);
	void set_message_updated_callback(Callable cb);
	void set_showing_chat(bool showing_chat);
	void add_log_callback(Callable callback, DiscordLoggingSeverity min_severity);
	void add_voice_log_callback(Callable callback, DiscordLoggingSeverity min_severity);
	void connect_discord();
	void disconnect_discord();
	DiscordClientStatus get_status();
	void open_connected_games_settings_in_discord(Callable callback);
	void set_application_id(int64_t application_id);
	bool set_log_dir(String path, DiscordLoggingSeverity min_severity);
	void set_status_changed_callback(Callable cb);
	void set_voice_log_dir(String path, DiscordLoggingSeverity min_severity);
	void create_or_join_lobby(String secret, Callable callback);
	void create_or_join_lobby_with_metadata(String secret, TypedDictionary<String, String> lobby_metadata, TypedDictionary<String, String> member_metadata, Callable callback);
	void get_guild_channels(int64_t guild_id, Callable cb);
	Variant get_lobby_handle(int64_t lobby_id);
	TypedArray<int64_t> get_lobby_ids();
	void get_user_guilds(Callable cb);
	void join_linked_lobby_guild(int64_t lobby_id, Callable provisional_user_merge_required_callback, Callable callback);
	void leave_lobby(int64_t lobby_id, Callable callback);
	void link_channel_to_lobby(int64_t lobby_id, int64_t channel_id, Callable callback);
	void set_lobby_created_callback(Callable cb);
	void set_lobby_deleted_callback(Callable cb);
	void set_lobby_member_added_callback(Callable cb);
	void set_lobby_member_removed_callback(Callable cb);
	void set_lobby_member_updated_callback(Callable cb);
	void set_lobby_updated_callback(Callable cb);
	void unlink_channel_from_lobby(int64_t lobby_id, Callable callback);
	void is_discord_app_installed(Callable callback);
	void accept_activity_invite(DiscordActivityInvite invite, Callable cb);
	void clear_rich_presence();
	bool register_launch_command(int64_t application_id, String command);
	bool register_launch_steam_application(int64_t application_id, int64_t steam_app_id);
	void send_activity_invite(int64_t user_id, String content, Callable cb);
	void send_activity_join_request(int64_t user_id, Callable cb);
	void send_activity_join_request_reply(DiscordActivityInvite invite, Callable cb);
	void set_activity_invite_created_callback(Callable cb);
	void set_activity_invite_updated_callback(Callable cb);
	void set_activity_join_callback(Callable cb);
	void set_activity_join_with_application_callback(Callable cb);
	void set_online_status(DiscordStatusType status, Callable callback);
	void update_rich_presence(DiscordActivity activity, Callable cb);
	void accept_discord_friend_request(int64_t user_id, Callable cb);
	void accept_game_friend_request(int64_t user_id, Callable cb);
	void block_user(int64_t user_id, Callable cb);
	void cancel_discord_friend_request(int64_t user_id, Callable cb);
	void cancel_game_friend_request(int64_t user_id, Callable cb);
	DiscordRelationshipHandle get_relationship_handle(int64_t user_id);
	TypedArray<DiscordRelationshipHandle> get_relationships();
	TypedArray<DiscordRelationshipHandle> get_relationships_by_group(DiscordRelationshipGroupType group_type);
	void reject_discord_friend_request(int64_t user_id, Callable cb);
	void reject_game_friend_request(int64_t user_id, Callable cb);
	void remove_discord_and_game_friend(int64_t user_id, Callable cb);
	void remove_game_friend(int64_t user_id, Callable cb);
	TypedArray<DiscordUserHandle> search_friends_by_username(String search_str);
	void send_discord_friend_request(String username, Callable cb);
	void send_discord_friend_request_by_id(int64_t user_id, Callable cb);
	void send_game_friend_request(String username, Callable cb);
	void send_game_friend_request_by_id(int64_t user_id, Callable cb);
	void set_relationship_created_callback(Callable cb);
	void set_relationship_deleted_callback(Callable cb);
	void unblock_user(int64_t user_id, Callable cb);
	Variant get_current_user_v();
	void get_discord_client_connected_user(int64_t application_id, Callable callback);
	Variant get_user(int64_t user_id);
	void set_relationship_groups_updated_callback(Callable cb);
	void set_user_updated_callback(Callable cb);
	int64_t get_application_id();
	DiscordUserHandle get_current_user();
	void set_http_request_timeout(int64_t http_timeout_in_milliseconds);
	static String error_to_string(DiscordClientError type);
	static String get_default_audio_device_id();
	static String get_default_communication_scopes();
	static String get_default_presence_scopes();
	static String get_version_hash();
	static int64_t get_version_major();
	static int64_t get_version_minor();
	static int64_t get_version_patch();
	static String status_to_string(DiscordClientStatus type);
	static String thread_to_string(DiscordClientThread type);

	DiscordClient() {
		this->obj = memnew(discordpp::Client);
	}

	// Internal usage.
	DiscordClient(discordpp::Client *obj) {
		this->obj = obj;
	}

	~DiscordClient() {
		memdelete(this->obj);
	}
};

class DiscordClientCreateOptions : public RefCounted {
	GDCLASS(DiscordClientCreateOptions, RefCounted)

private:
	discordpp::ClientCreateOptions *obj;

protected:
	static void _bind_methods();

public:
	// Internal usage.
	discordpp::ClientCreateOptions *unwrap() {
		return obj;
	}

	String web_base();
	void set_web_base(String web_base);
	String api_base();
	void set_api_base(String api_base);
	DiscordAudioSystem experimental_audio_system();
	void set_experimental_audio_system(DiscordAudioSystem experimental_audio_system);
	bool experimental_android_prevent_comms_for_bluetooth();
	void set_experimental_android_prevent_comms_for_bluetooth(bool experimental_android_prevent_comms_for_bluetooth);
	Variant cpu_affinity_mask();
	void set_cpu_affinity_mask(Variant cpu_affinity_mask);

	DiscordClientCreateOptions() {
		this->obj = memnew(discordpp::ClientCreateOptions);
	}

	// Internal usage.
	DiscordClientCreateOptions(discordpp::ClientCreateOptions *obj) {
		this->obj = obj;
	}

	~DiscordClientCreateOptions() {
		memdelete(this->obj);
	}
};

class DiscordClientResult : public RefCounted {
	GDCLASS(DiscordClientResult, RefCounted)

private:
	discordpp::ClientResult *obj;

	DiscordClientResult() {}

protected:
	static void _bind_methods();

public:
	// Internal usage.
	discordpp::ClientResult *unwrap() {
		return obj;
	}

	String to_string_discord();
	DiscordErrorType type();
	void set_type(DiscordErrorType type);
	String error();
	void set_error(String error);
	int64_t error_code();
	void set_error_code(int64_t error_code);
	DiscordHttpStatusCode status();
	void set_status(DiscordHttpStatusCode status);
	String response_body();
	void set_response_body(String response_body);
	bool successful();
	void set_successful(bool successful);
	bool retryable();
	void set_retryable(bool retryable);
	float retry_after();
	void set_retry_after(float retry_after);

	// Internal usage.
	DiscordClientResult(discordpp::ClientResult *obj) {
		this->obj = obj;
	}

	~DiscordClientResult() {
		memdelete(this->obj);
	}
};

class DiscordDeviceAuthorizationArgs : public RefCounted {
	GDCLASS(DiscordDeviceAuthorizationArgs, RefCounted)

private:
	discordpp::DeviceAuthorizationArgs *obj;

protected:
	static void _bind_methods();

public:
	// Internal usage.
	discordpp::DeviceAuthorizationArgs *unwrap() {
		return obj;
	}

	int64_t client_id();
	void set_client_id(int64_t client_id);
	String scopes();
	void set_scopes(String scopes);

	DiscordDeviceAuthorizationArgs() {
		this->obj = memnew(discordpp::DeviceAuthorizationArgs);
	}

	// Internal usage.
	DiscordDeviceAuthorizationArgs(discordpp::DeviceAuthorizationArgs *obj) {
		this->obj = obj;
	}

	~DiscordDeviceAuthorizationArgs() {
		memdelete(this->obj);
	}
};

class DiscordGuildChannel : public RefCounted {
	GDCLASS(DiscordGuildChannel, RefCounted)

private:
	discordpp::GuildChannel *obj;

	DiscordGuildChannel() {}

protected:
	static void _bind_methods();

public:
	// Internal usage.
	discordpp::GuildChannel *unwrap() {
		return obj;
	}

	int64_t id();
	void set_id(int64_t id);
	String name();
	void set_name(String name);
	DiscordChannelType type();
	void set_type(DiscordChannelType type);
	int64_t position();
	void set_position(int64_t position);
	Variant parent_id();
	void set_parent_id(Variant parent_id);
	bool is_linkable();
	void set_is_linkable(bool is_linkable);
	bool is_viewable_and_writeable_by_all_members();
	void set_is_viewable_and_writeable_by_all_members(bool is_viewable_and_writeable_by_all_members);
	Variant linked_lobby();
	void set_linked_lobby(Variant linked_lobby);

	// Internal usage.
	DiscordGuildChannel(discordpp::GuildChannel *obj) {
		this->obj = obj;
	}

	~DiscordGuildChannel() {
		memdelete(this->obj);
	}
};

class DiscordGuildMinimal : public RefCounted {
	GDCLASS(DiscordGuildMinimal, RefCounted)

private:
	discordpp::GuildMinimal *obj;

	DiscordGuildMinimal() {}

protected:
	static void _bind_methods();

public:
	// Internal usage.
	discordpp::GuildMinimal *unwrap() {
		return obj;
	}

	int64_t id();
	void set_id(int64_t id);
	String name();
	void set_name(String name);

	// Internal usage.
	DiscordGuildMinimal(discordpp::GuildMinimal *obj) {
		this->obj = obj;
	}

	~DiscordGuildMinimal() {
		memdelete(this->obj);
	}
};

class DiscordLinkedChannel : public RefCounted {
	GDCLASS(DiscordLinkedChannel, RefCounted)

private:
	discordpp::LinkedChannel *obj;

	DiscordLinkedChannel() {}

protected:
	static void _bind_methods();

public:
	// Internal usage.
	discordpp::LinkedChannel *unwrap() {
		return obj;
	}

	int64_t id();
	void set_id(int64_t id);
	String name();
	void set_name(String name);
	int64_t guild_id();
	void set_guild_id(int64_t guild_id);

	// Internal usage.
	DiscordLinkedChannel(discordpp::LinkedChannel *obj) {
		this->obj = obj;
	}

	~DiscordLinkedChannel() {
		memdelete(this->obj);
	}
};

class DiscordLinkedLobby : public RefCounted {
	GDCLASS(DiscordLinkedLobby, RefCounted)

private:
	discordpp::LinkedLobby *obj;

protected:
	static void _bind_methods();

public:
	// Internal usage.
	discordpp::LinkedLobby *unwrap() {
		return obj;
	}

	int64_t application_id();
	void set_application_id(int64_t application_id);
	int64_t lobby_id();
	void set_lobby_id(int64_t lobby_id);

	DiscordLinkedLobby() {
		this->obj = memnew(discordpp::LinkedLobby);
	}

	// Internal usage.
	DiscordLinkedLobby(discordpp::LinkedLobby *obj) {
		this->obj = obj;
	}

	~DiscordLinkedLobby() {
		memdelete(this->obj);
	}
};

class DiscordLobbyHandle : public RefCounted {
	GDCLASS(DiscordLobbyHandle, RefCounted)

private:
	discordpp::LobbyHandle *obj;

	DiscordLobbyHandle() {}

protected:
	static void _bind_methods();

public:
	// Internal usage.
	discordpp::LobbyHandle *unwrap() {
		return obj;
	}

	Variant get_call_info_handle();
	Variant get_lobby_member_handle(int64_t member_id);
	int64_t id();
	Variant linked_channel();
	TypedArray<int64_t> lobby_member_ids();
	TypedArray<DiscordLobbyMemberHandle> lobby_members();
	TypedDictionary<String, String> metadata();

	// Internal usage.
	DiscordLobbyHandle(discordpp::LobbyHandle *obj) {
		this->obj = obj;
	}

	~DiscordLobbyHandle() {
		memdelete(this->obj);
	}
};

class DiscordLobbyMemberHandle : public RefCounted {
	GDCLASS(DiscordLobbyMemberHandle, RefCounted)

private:
	discordpp::LobbyMemberHandle *obj;

	DiscordLobbyMemberHandle() {}

protected:
	static void _bind_methods();

public:
	// Internal usage.
	discordpp::LobbyMemberHandle *unwrap() {
		return obj;
	}

	bool can_link_lobby();
	bool connected();
	int64_t id();
	TypedDictionary<String, String> metadata();
	Variant user();

	// Internal usage.
	DiscordLobbyMemberHandle(discordpp::LobbyMemberHandle *obj) {
		this->obj = obj;
	}

	~DiscordLobbyMemberHandle() {
		memdelete(this->obj);
	}
};

class DiscordMessageHandle : public RefCounted {
	GDCLASS(DiscordMessageHandle, RefCounted)

private:
	discordpp::MessageHandle *obj;

	DiscordMessageHandle() {}

protected:
	static void _bind_methods();

public:
	// Internal usage.
	discordpp::MessageHandle *unwrap() {
		return obj;
	}

	Variant additional_content();
	Variant application_id();
	Variant author();
	int64_t author_id();
	Variant channel();
	int64_t channel_id();
	String content();
	Variant disclosure_type();
	int64_t edited_timestamp();
	int64_t id();
	Variant lobby();
	TypedDictionary<String, String> metadata();
	TypedDictionary<String, String> moderation_metadata();
	String raw_content();
	Variant recipient();
	int64_t recipient_id();
	bool sent_from_game();
	int64_t sent_timestamp();

	// Internal usage.
	DiscordMessageHandle(discordpp::MessageHandle *obj) {
		this->obj = obj;
	}

	~DiscordMessageHandle() {
		memdelete(this->obj);
	}
};

class DiscordRelationshipHandle : public RefCounted {
	GDCLASS(DiscordRelationshipHandle, RefCounted)

private:
	discordpp::RelationshipHandle *obj;

	DiscordRelationshipHandle() {}

protected:
	static void _bind_methods();

public:
	// Internal usage.
	discordpp::RelationshipHandle *unwrap() {
		return obj;
	}

	DiscordRelationshipType discord_relationship_type();
	DiscordRelationshipType game_relationship_type();
	int64_t id();
	bool is_spam_request();
	Variant user();

	// Internal usage.
	DiscordRelationshipHandle(discordpp::RelationshipHandle *obj) {
		this->obj = obj;
	}

	~DiscordRelationshipHandle() {
		memdelete(this->obj);
	}
};

class DiscordUserApplicationProfileHandle : public RefCounted {
	GDCLASS(DiscordUserApplicationProfileHandle, RefCounted)

private:
	discordpp::UserApplicationProfileHandle *obj;

	DiscordUserApplicationProfileHandle() {}

protected:
	static void _bind_methods();

public:
	// Internal usage.
	discordpp::UserApplicationProfileHandle *unwrap() {
		return obj;
	}

	String avatar_hash();
	String metadata();
	Variant provider_id();
	String provider_issued_user_id();
	DiscordExternalIdentityProviderType provider_type();
	String username();

	// Internal usage.
	DiscordUserApplicationProfileHandle(discordpp::UserApplicationProfileHandle *obj) {
		this->obj = obj;
	}

	~DiscordUserApplicationProfileHandle() {
		memdelete(this->obj);
	}
};

class DiscordUserHandle : public RefCounted {
	GDCLASS(DiscordUserHandle, RefCounted)

private:
	discordpp::UserHandle *obj;

	DiscordUserHandle() {}

protected:
	static void _bind_methods();

public:
	// Internal usage.
	discordpp::UserHandle *unwrap() {
		return obj;
	}

	Variant avatar();
	String avatar_url(DiscordUserHandleAvatarType animated_type, DiscordUserHandleAvatarType static_type);
	String display_name();
	Variant game_activity();
	Variant global_name();
	int64_t id();
	bool is_provisional();
	DiscordRelationshipHandle relationship();
	DiscordStatusType status();
	TypedArray<DiscordUserApplicationProfileHandle> user_application_profiles();
	String username();
	static String avatar_type_to_string(DiscordUserHandleAvatarType type);

	// Internal usage.
	DiscordUserHandle(discordpp::UserHandle *obj) {
		this->obj = obj;
	}

	~DiscordUserHandle() {
		memdelete(this->obj);
	}
};

class DiscordUserMessageSummary : public RefCounted {
	GDCLASS(DiscordUserMessageSummary, RefCounted)

private:
	discordpp::UserMessageSummary *obj;

	DiscordUserMessageSummary() {}

protected:
	static void _bind_methods();

public:
	// Internal usage.
	discordpp::UserMessageSummary *unwrap() {
		return obj;
	}

	int64_t last_message_id();
	int64_t user_id();

	// Internal usage.
	DiscordUserMessageSummary(discordpp::UserMessageSummary *obj) {
		this->obj = obj;
	}

	~DiscordUserMessageSummary() {
		memdelete(this->obj);
	}
};

class DiscordVADThresholdSettings : public RefCounted {
	GDCLASS(DiscordVADThresholdSettings, RefCounted)

private:
	discordpp::VADThresholdSettings *obj;

	DiscordVADThresholdSettings() {}

protected:
	static void _bind_methods();

public:
	// Internal usage.
	discordpp::VADThresholdSettings *unwrap() {
		return obj;
	}

	float vad_threshold();
	void set_vad_threshold(float vad_threshold);
	bool automatic();
	void set_automatic(bool automatic);

	// Internal usage.
	DiscordVADThresholdSettings(discordpp::VADThresholdSettings *obj) {
		this->obj = obj;
	}

	~DiscordVADThresholdSettings() {
		memdelete(this->obj);
	}
};

class DiscordVoiceStateHandle : public RefCounted {
	GDCLASS(DiscordVoiceStateHandle, RefCounted)

private:
	discordpp::VoiceStateHandle *obj;

	DiscordVoiceStateHandle() {}

protected:
	static void _bind_methods();

public:
	// Internal usage.
	discordpp::VoiceStateHandle *unwrap() {
		return obj;
	}

	bool self_deaf();
	bool self_mute();

	// Internal usage.
	DiscordVoiceStateHandle(discordpp::VoiceStateHandle *obj) {
		this->obj = obj;
	}

	~DiscordVoiceStateHandle() {
		memdelete(this->obj);
	}
};

} //namespace godot

#endif
