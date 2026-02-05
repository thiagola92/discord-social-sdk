
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
	static void run_callbacks();

	// Overloading functions.
	static String enum_to_string(int64_t value, int64_t enum_type);

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

	// Constructors.
	DiscordActivity() {
		this->obj = memnew(discordpp::Activity);
	}

	// Functions.
	DiscordActivityGamePlatforms::Enum supported_platforms();
	DiscordActivityTypes::Enum type();
	String name();
	TypedArray<DiscordActivityButton> get_buttons();
	Variant application_id();
	Variant assets();
	Variant details();
	Variant details_url();
	Variant parent_application_id();
	Variant party();
	Variant secrets();
	Variant state();
	Variant state_url();
	Variant status_display_type();
	Variant timestamps();
	bool equals(DiscordActivity *other);
	void add_button(DiscordActivityButton *button);
	void set_application_id(Variant application_id);
	void set_assets(Variant assets);
	void set_details(Variant details);
	void set_details_url(Variant details_url);
	void set_name(String name);
	void set_parent_application_id(Variant parent_application_id);
	void set_party(Variant party);
	void set_secrets(Variant secrets);
	void set_state(Variant state);
	void set_state_url(Variant state_url);
	void set_status_display_type(Variant status_display_type);
	void set_supported_platforms(DiscordActivityGamePlatforms::Enum supported_platforms);
	void set_timestamps(Variant timestamps);
	void set_type(DiscordActivityTypes::Enum type);

	// Overloading functions.

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

	// Constructors.
	DiscordActivityAssets() {
		this->obj = memnew(discordpp::ActivityAssets);
	}

	// Functions.
	Variant invite_cover_image();
	Variant large_image();
	Variant large_text();
	Variant large_url();
	Variant small_image();
	Variant small_text();
	Variant small_url();
	void set_invite_cover_image(Variant invite_cover_image);
	void set_large_image(Variant large_image);
	void set_large_text(Variant large_text);
	void set_large_url(Variant large_url);
	void set_small_image(Variant small_image);
	void set_small_text(Variant small_text);
	void set_small_url(Variant small_url);

	// Overloading functions.

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

	// Constructors.
	DiscordActivityButton() {
		this->obj = memnew(discordpp::ActivityButton);
	}

	// Functions.
	String label();
	String url();
	void set_label(String label);
	void set_url(String url);

	// Overloading functions.

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

	// Constructors.
	DiscordActivityInvite() {
		this->obj = memnew(discordpp::ActivityInvite);
	}

	// Functions.
	DiscordActivityActionTypes::Enum type();
	String party_id();
	String session_id();
	bool is_valid();
	int64_t application_id();
	int64_t channel_id();
	int64_t message_id();
	int64_t parent_application_id();
	int64_t sender_id();
	void set_application_id(int64_t application_id);
	void set_channel_id(int64_t channel_id);
	void set_is_valid(bool is_valid);
	void set_message_id(int64_t message_id);
	void set_parent_application_id(int64_t parent_application_id);
	void set_party_id(String party_id);
	void set_sender_id(int64_t sender_id);
	void set_session_id(String session_id);
	void set_type(DiscordActivityActionTypes::Enum type);

	// Overloading functions.

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

	// Constructors.
	DiscordActivityParty() {
		this->obj = memnew(discordpp::ActivityParty);
	}

	// Functions.
	DiscordActivityPartyPrivacy::Enum privacy();
	String id();
	int64_t current_size();
	int64_t max_size();
	void set_current_size(int64_t current_size);
	void set_id(String id);
	void set_max_size(int64_t max_size);
	void set_privacy(DiscordActivityPartyPrivacy::Enum privacy);

	// Overloading functions.

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

	// Constructors.
	DiscordActivitySecrets() {
		this->obj = memnew(discordpp::ActivitySecrets);
	}

	// Functions.
	String join();
	void set_join(String join);

	// Overloading functions.

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

	// Constructors.
	DiscordActivityTimestamps() {
		this->obj = memnew(discordpp::ActivityTimestamps);
	}

	// Functions.
	int64_t end();
	int64_t start();
	void set_end(int64_t end);
	void set_start(int64_t start);

	// Overloading functions.

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

	// Constructors.
	DiscordAdditionalContent() {
		this->obj = memnew(discordpp::AdditionalContent);
	}

	// Functions.
	DiscordAdditionalContentType::Enum type();
	Variant title();
	bool equals(DiscordAdditionalContent *rhs);
	int64_t count();
	static String type_to_string(DiscordAdditionalContentType::Enum type);
	void set_count(int64_t count);
	void set_title(Variant title);
	void set_type(DiscordAdditionalContentType::Enum type);

	// Overloading functions.

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

	// Constructors.

	// Functions.
	String id();
	String name();
	bool equals(DiscordAudioDevice *rhs);
	bool is_default();
	void set_id(String id);
	void set_is_default(bool is_default);
	void set_name(String name);

	// Overloading functions.

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

	// Constructors.
	DiscordAuthorizationArgs() {
		this->obj = memnew(discordpp::AuthorizationArgs);
	}

	// Functions.
	String scopes();
	Variant code_challenge();
	Variant custom_scheme_param();
	Variant integration_type();
	Variant nonce();
	Variant state();
	int64_t client_id();
	void set_client_id(int64_t client_id);
	void set_code_challenge(Variant code_challenge);
	void set_custom_scheme_param(Variant custom_scheme_param);
	void set_integration_type(Variant integration_type);
	void set_nonce(Variant nonce);
	void set_scopes(String scopes);
	void set_state(Variant state);

	// Overloading functions.

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

	// Constructors.
	DiscordAuthorizationCodeChallenge() {
		this->obj = memnew(discordpp::AuthorizationCodeChallenge);
	}

	// Functions.
	DiscordAuthenticationCodeChallengeMethod::Enum method();
	String challenge();
	void set_challenge(String challenge);
	void set_method(DiscordAuthenticationCodeChallengeMethod::Enum method);

	// Overloading functions.

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

	// Constructors.

	// Functions.
	DiscordAuthorizationCodeChallenge *challenge();
	String verifier();
	void set_challenge(DiscordAuthorizationCodeChallenge *challenge);
	void set_verifier(String verifier);

	// Overloading functions.

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

	// Constructors.

	// Functions.
	DiscordAudioModeType::Enum get_audio_mode();
	DiscordCallStatus::Enum get_status();
	DiscordVADThresholdSettings *get_vadthreshold();
	TypedArray<int64_t> get_participants();
	Variant get_voice_state_handle(int64_t user_id);
	bool get_local_mute(int64_t user_id);
	bool get_pttactive();
	bool get_self_deaf();
	bool get_self_mute();
	float get_participant_volume(int64_t user_id);
	int64_t get_channel_id();
	int64_t get_guild_id();
	int64_t get_pttrelease_delay();
	static String error_to_string(DiscordCallError::Enum type);
	static String status_to_string(DiscordCallStatus::Enum type);
	void set_audio_mode(DiscordAudioModeType::Enum audio_mode);
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

	// Overloading functions.

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

	// Constructors.

	// Functions.
	TypedArray<int64_t> get_participants();
	Variant get_voice_state_handle(int64_t user_id);
	int64_t channel_id();
	int64_t guild_id();

	// Overloading functions.

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

	// Constructors.

	// Functions.
	DiscordChannelType::Enum type();
	String name();
	TypedArray<int64_t> recipients();
	int64_t id();

	// Overloading functions.

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

	// Constructors.
	DiscordClient() {
		this->obj = memnew(discordpp::Client);
	}

	// Functions.
	DiscordAuthorizationCodeVerifier *create_authorization_code_verifier();
	DiscordCall *get_call(int64_t channel_id);
	DiscordCall *start_call(int64_t channel_id);
	DiscordCall *start_call_with_audio_callbacks(int64_t lobby_id, Callable received_cb, Callable captured_cb);
	DiscordClientStatus::Enum get_status();
	DiscordRelationshipHandle *get_relationship_handle(int64_t user_id);
	DiscordUserHandle *get_current_user();
	TypedArray<DiscordCall> get_calls();
	TypedArray<DiscordRelationshipHandle> get_relationships();
	TypedArray<DiscordRelationshipHandle> get_relationships_by_group(DiscordRelationshipGroupType::Enum group_type);
	TypedArray<DiscordUserHandle> search_friends_by_username(String search_str);
	TypedArray<int64_t> get_lobby_ids();
	Variant get_channel_handle(int64_t channel_id);
	Variant get_current_user_v2();
	Variant get_lobby_handle(int64_t lobby_id);
	Variant get_message_handle(int64_t message_id);
	Variant get_user(int64_t user_id);
	bool can_open_message_in_discord(int64_t message_id);
	bool get_self_deaf_all();
	bool get_self_mute_all();
	bool is_authenticated();
	bool register_launch_command(int64_t application_id, String command);
	bool register_launch_steam_application(int64_t application_id, int64_t steam_app_id);
	bool set_log_dir(String path, DiscordLoggingSeverity::Enum min_severity);
	bool set_speaker_mode(bool speaker_mode);
	bool show_audio_route_picker();
	float get_input_volume();
	float get_output_volume();
	int64_t get_application_id();
	static String error_to_string(DiscordClientError::Enum type);
	static String get_default_audio_device_id();
	static String get_default_communication_scopes();
	static String get_default_presence_scopes();
	static String get_version_hash();
	static String status_to_string(DiscordClientStatus::Enum type);
	static String thread_to_string(DiscordClientThread::Enum type);
	static int64_t get_version_major();
	static int64_t get_version_minor();
	static int64_t get_version_patch();
	void abort_authorize();
	void abort_get_token_from_device();
	void accept_activity_invite(DiscordActivityInvite *invite, Callable cb);
	void accept_discord_friend_request(int64_t user_id, Callable cb);
	void accept_game_friend_request(int64_t user_id, Callable cb);
	void add_log_callback(Callable callback, DiscordLoggingSeverity::Enum min_severity);
	void add_voice_log_callback(Callable callback, DiscordLoggingSeverity::Enum min_severity);
	void authorize(DiscordAuthorizationArgs *args, Callable callback);
	void block_user(int64_t user_id, Callable cb);
	void cancel_discord_friend_request(int64_t user_id, Callable cb);
	void cancel_game_friend_request(int64_t user_id, Callable cb);
	void clear_rich_presence();
	void close_authorize_device_screen();
	void connect_discord();
	void create_or_join_lobby(String secret, Callable callback);
	void create_or_join_lobby_with_metadata(String secret, TypedDictionary<String, String> lobby_metadata, TypedDictionary<String, String> member_metadata, Callable callback);
	void delete_user_message(int64_t recipient_id, int64_t message_id, Callable cb);
	void disconnect_discord();
	void edit_user_message(int64_t recipient_id, int64_t message_id, String content, Callable cb);
	void end_call(int64_t channel_id, Callable callback);
	void end_calls(Callable callback);
	void exchange_child_token(String parent_application_token, int64_t child_application_id, Callable callback);
	void fetch_current_user(DiscordAuthorizationTokenType::Enum token_type, String token, Callable callback);
	void get_current_input_device(Callable cb);
	void get_current_output_device(Callable cb);
	void get_discord_client_connected_user(int64_t application_id, Callable callback);
	void get_guild_channels(int64_t guild_id, Callable cb);
	void get_input_devices(Callable cb);
	void get_lobby_messages_with_limit(int64_t lobby_id, int64_t limit, Callable cb);
	void get_output_devices(Callable cb);
	void get_provisional_token(int64_t application_id, DiscordAuthenticationExternalAuthType::Enum external_auth_type, String external_auth_token, Callable callback);
	void get_token(int64_t application_id, String code, String code_verifier, String redirect_uri, Callable callback);
	void get_token_from_device(DiscordDeviceAuthorizationArgs *args, Callable callback);
	void get_token_from_device_provisional_merge(DiscordDeviceAuthorizationArgs *args, DiscordAuthenticationExternalAuthType::Enum external_auth_type, String external_auth_token, Callable callback);
	void get_token_from_provisional_merge(int64_t application_id, String code, String code_verifier, String redirect_uri, DiscordAuthenticationExternalAuthType::Enum external_auth_type, String external_auth_token, Callable callback);
	void get_user_guilds(Callable cb);
	void get_user_message_summaries(Callable cb);
	void get_user_messages_with_limit(int64_t recipient_id, int64_t limit, Callable cb);
	void is_discord_app_installed(Callable callback);
	void join_linked_lobby_guild(int64_t lobby_id, Callable provisional_user_merge_required_callback, Callable callback);
	void leave_lobby(int64_t lobby_id, Callable callback);
	void link_channel_to_lobby(int64_t lobby_id, int64_t channel_id, Callable callback);
	void open_authorize_device_screen(int64_t client_id, String user_code);
	void open_connected_games_settings_in_discord(Callable callback);
	void open_message_in_discord(int64_t message_id, Callable provisional_user_merge_required_callback, Callable callback);
	void provisional_user_merge_completed(bool success);
	void refresh_token(int64_t application_id, String refresh_token, Callable callback);
	void register_authorize_request_callback(Callable callback);
	void reject_discord_friend_request(int64_t user_id, Callable cb);
	void reject_game_friend_request(int64_t user_id, Callable cb);
	void remove_authorize_request_callback();
	void remove_discord_and_game_friend(int64_t user_id, Callable cb);
	void remove_game_friend(int64_t user_id, Callable cb);
	void revoke_token(int64_t application_id, String token, Callable callback);
	void send_activity_invite(int64_t user_id, String content, Callable cb);
	void send_activity_join_request(int64_t user_id, Callable cb);
	void send_activity_join_request_reply(DiscordActivityInvite *invite, Callable cb);
	void send_discord_friend_request(String username, Callable cb);
	void send_discord_friend_request_by_id(int64_t user_id, Callable cb);
	void send_game_friend_request(String username, Callable cb);
	void send_game_friend_request_by_id(int64_t user_id, Callable cb);
	void send_lobby_message(int64_t lobby_id, String content, Callable cb);
	void send_lobby_message_with_metadata(int64_t lobby_id, String content, TypedDictionary<String, String> metadata, Callable cb);
	void send_user_message(int64_t recipient_id, String content, Callable cb);
	void send_user_message_with_metadata(int64_t recipient_id, String content, TypedDictionary<String, String> metadata, Callable cb);
	void set_activity_invite_created_callback(Callable cb);
	void set_activity_invite_updated_callback(Callable cb);
	void set_activity_join_callback(Callable cb);
	void set_activity_join_with_application_callback(Callable cb);
	void set_aec_dump(bool on);
	void set_application_id(int64_t application_id);
	void set_authorize_device_screen_closed_callback(Callable cb);
	void set_automatic_gain_control(bool on);
	void set_device_change_callback(Callable callback);
	void set_echo_cancellation(bool on);
	void set_engine_managed_audio_session(bool is_engine_managed);
	void set_game_window_pid(int64_t pid);
	void set_http_request_timeout(int64_t http_timeout_in_milliseconds);
	void set_input_device(String device_id, Callable cb);
	void set_input_volume(float input_volume);
	void set_lobby_created_callback(Callable cb);
	void set_lobby_deleted_callback(Callable cb);
	void set_lobby_member_added_callback(Callable cb);
	void set_lobby_member_removed_callback(Callable cb);
	void set_lobby_member_updated_callback(Callable cb);
	void set_lobby_updated_callback(Callable cb);
	void set_message_created_callback(Callable cb);
	void set_message_deleted_callback(Callable cb);
	void set_message_updated_callback(Callable cb);
	void set_no_audio_input_callback(Callable callback);
	void set_no_audio_input_threshold(float d_bfsthreshold);
	void set_noise_suppression(bool on);
	void set_online_status(DiscordStatusType::Enum status, Callable callback);
	void set_opus_hardware_coding(bool encode, bool decode);
	void set_output_device(String device_id, Callable cb);
	void set_output_volume(float output_volume);
	void set_relationship_created_callback(Callable cb);
	void set_relationship_deleted_callback(Callable cb);
	void set_relationship_groups_updated_callback(Callable cb);
	void set_self_deaf_all(bool deaf);
	void set_self_mute_all(bool mute);
	void set_showing_chat(bool showing_chat);
	void set_status_changed_callback(Callable cb);
	void set_thread_priority(DiscordClientThread::Enum thread, int64_t priority);
	void set_token_expiration_callback(Callable callback);
	void set_user_updated_callback(Callable cb);
	void set_voice_log_dir(String path, DiscordLoggingSeverity::Enum min_severity);
	void set_voice_participant_changed_callback(Callable cb);
	void unblock_user(int64_t user_id, Callable cb);
	void unlink_channel_from_lobby(int64_t lobby_id, Callable callback);
	void unmerge_into_provisional_account(int64_t application_id, DiscordAuthenticationExternalAuthType::Enum external_auth_type, String external_auth_token, Callable callback);
	void update_provisional_account_display_name(String name, Callable callback);
	void update_rich_presence(DiscordActivity *activity, Callable cb);
	void update_token(DiscordAuthorizationTokenType::Enum token_type, String token, Callable callback);

	// Overloading functions.

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

	// Constructors.
	DiscordClientCreateOptions() {
		this->obj = memnew(discordpp::ClientCreateOptions);
	}

	// Functions.
	DiscordAudioSystem::Enum experimental_audio_system();
	String api_base();
	String web_base();
	Variant cpu_affinity_mask();
	bool experimental_android_prevent_comms_for_bluetooth();
	void set_api_base(String api_base);
	void set_cpu_affinity_mask(Variant cpu_affinity_mask);
	void set_experimental_android_prevent_comms_for_bluetooth(bool experimental_android_prevent_comms_for_bluetooth);
	void set_experimental_audio_system(DiscordAudioSystem::Enum experimental_audio_system);
	void set_web_base(String web_base);

	// Overloading functions.

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

	// Constructors.

	// Functions.
	DiscordErrorType::Enum type();
	DiscordHttpStatusCode::Enum status();
	String error();
	String response_body();
	String to_string_discord();
	bool retryable();
	bool successful();
	float retry_after();
	int64_t error_code();
	void set_error(String error);
	void set_error_code(int64_t error_code);
	void set_response_body(String response_body);
	void set_retry_after(float retry_after);
	void set_retryable(bool retryable);
	void set_status(DiscordHttpStatusCode::Enum status);
	void set_successful(bool successful);
	void set_type(DiscordErrorType::Enum type);

	// Overloading functions.

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

	// Constructors.
	DiscordDeviceAuthorizationArgs() {
		this->obj = memnew(discordpp::DeviceAuthorizationArgs);
	}

	// Functions.
	String scopes();
	int64_t client_id();
	void set_client_id(int64_t client_id);
	void set_scopes(String scopes);

	// Overloading functions.

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

	// Constructors.

	// Functions.
	DiscordChannelType::Enum type();
	String name();
	Variant linked_lobby();
	Variant parent_id();
	bool is_linkable();
	bool is_viewable_and_writeable_by_all_members();
	int64_t id();
	int64_t position();
	void set_id(int64_t id);
	void set_is_linkable(bool is_linkable);
	void set_is_viewable_and_writeable_by_all_members(bool is_viewable_and_writeable_by_all_members);
	void set_linked_lobby(Variant linked_lobby);
	void set_name(String name);
	void set_parent_id(Variant parent_id);
	void set_position(int64_t position);
	void set_type(DiscordChannelType::Enum type);

	// Overloading functions.

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

	// Constructors.

	// Functions.
	String name();
	int64_t id();
	void set_id(int64_t id);
	void set_name(String name);

	// Overloading functions.

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

	// Constructors.

	// Functions.
	String name();
	int64_t guild_id();
	int64_t id();
	void set_guild_id(int64_t guild_id);
	void set_id(int64_t id);
	void set_name(String name);

	// Overloading functions.

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

	// Constructors.
	DiscordLinkedLobby() {
		this->obj = memnew(discordpp::LinkedLobby);
	}

	// Functions.
	int64_t application_id();
	int64_t lobby_id();
	void set_application_id(int64_t application_id);
	void set_lobby_id(int64_t lobby_id);

	// Overloading functions.

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

	// Constructors.

	// Functions.
	TypedArray<DiscordLobbyMemberHandle> lobby_members();
	TypedArray<int64_t> lobby_member_ids();
	TypedDictionary<String, String> metadata();
	Variant get_call_info_handle();
	Variant get_lobby_member_handle(int64_t member_id);
	Variant linked_channel();
	int64_t id();

	// Overloading functions.

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

	// Constructors.

	// Functions.
	TypedDictionary<String, String> metadata();
	Variant user();
	bool can_link_lobby();
	bool connected();
	int64_t id();

	// Overloading functions.

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

	// Constructors.

	// Functions.
	String content();
	String raw_content();
	TypedDictionary<String, String> metadata();
	TypedDictionary<String, String> moderation_metadata();
	Variant additional_content();
	Variant application_id();
	Variant author();
	Variant channel();
	Variant disclosure_type();
	Variant lobby();
	Variant recipient();
	bool sent_from_game();
	int64_t author_id();
	int64_t channel_id();
	int64_t edited_timestamp();
	int64_t id();
	int64_t recipient_id();
	int64_t sent_timestamp();

	// Overloading functions.

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

	// Constructors.

	// Functions.
	DiscordRelationshipType::Enum discord_relationship_type();
	DiscordRelationshipType::Enum game_relationship_type();
	Variant user();
	bool is_spam_request();
	int64_t id();

	// Overloading functions.

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

	// Constructors.

	// Functions.
	DiscordExternalIdentityProviderType::Enum provider_type();
	String avatar_hash();
	String metadata();
	String provider_issued_user_id();
	String username();
	Variant provider_id();

	// Overloading functions.

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

	// Constructors.

	// Functions.
	DiscordRelationshipHandle *relationship();
	DiscordStatusType::Enum status();
	String avatar_url(DiscordUserHandleAvatarType::Enum animated_type, DiscordUserHandleAvatarType::Enum static_type);
	String display_name();
	String username();
	TypedArray<DiscordUserApplicationProfileHandle> user_application_profiles();
	Variant avatar();
	Variant game_activity();
	Variant global_name();
	bool is_provisional();
	int64_t id();
	static String avatar_type_to_string(DiscordUserHandleAvatarType::Enum type);

	// Overloading functions.

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

	// Constructors.

	// Functions.
	int64_t last_message_id();
	int64_t user_id();

	// Overloading functions.

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

	// Constructors.

	// Functions.
	bool automatic();
	float vad_threshold();
	void set_automatic(bool automatic);
	void set_vad_threshold(float vad_threshold);

	// Overloading functions.

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

	// Constructors.

	// Functions.
	bool self_deaf();
	bool self_mute();

	// Overloading functions.

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
