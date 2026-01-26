
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

	void add_button();
	void equals();
	void get_buttons();
	void name();
	void set_name();
	void type();
	void set_type();
	void status_display_type();
	void set_status_display_type();
	void state();
	void set_state();
	void state_url();
	void set_state_url();
	void details();
	void set_details();
	void details_url();
	void set_details_url();
	void application_id();
	void set_application_id();
	void parent_application_id();
	void set_parent_application_id();
	void assets();
	void set_assets();
	void timestamps();
	void set_timestamps();
	void party();
	void set_party();
	void secrets();
	void set_secrets();
	void supported_platforms();
	void set_supported_platforms();

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

	void large_image();
	void set_large_image();
	void large_text();
	void set_large_text();
	void large_url();
	void set_large_url();
	void small_image();
	void set_small_image();
	void small_text();
	void set_small_text();
	void small_url();
	void set_small_url();
	void invite_cover_image();
	void set_invite_cover_image();

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

	void label();
	void set_label();
	void url();
	void set_url();

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

	void sender_id();
	void set_sender_id();
	void channel_id();
	void set_channel_id();
	void message_id();
	void set_message_id();
	void type();
	void set_type();
	void application_id();
	void set_application_id();
	void parent_application_id();
	void set_parent_application_id();
	void party_id();
	void set_party_id();
	void session_id();
	void set_session_id();
	void is_valid();
	void set_is_valid();

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

	void id();
	void set_id();
	void current_size();
	void set_current_size();
	void max_size();
	void set_max_size();
	void privacy();
	void set_privacy();

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

	void join();
	void set_join();

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

	void start();
	void set_start();
	void end();
	void set_end();

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

	void equals();
	void type();
	void set_type();
	void title();
	void set_title();
	void count();
	void set_count();
	static void type_to_string();

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

	void equals();
	void id();
	void set_id();
	void name();
	void set_name();
	void is_default();
	void set_is_default();

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

	void client_id();
	void set_client_id();
	void scopes();
	void set_scopes();
	void state();
	void set_state();
	void nonce();
	void set_nonce();
	void code_challenge();
	void set_code_challenge();
	void integration_type();
	void set_integration_type();
	void custom_scheme_param();
	void set_custom_scheme_param();

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

	void method();
	void set_method();
	void challenge();
	void set_challenge();

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

	void challenge();
	void set_challenge();
	void verifier();
	void set_verifier();

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

	void get_audio_mode();
	void get_channel_id();
	void get_guild_id();
	void get_local_mute();
	void get_participants();
	void get_participant_volume();
	void get_pttactive();
	void get_pttrelease_delay();
	void get_self_deaf();
	void get_self_mute();
	void get_status();
	void get_vadthreshold();
	void get_voice_state_handle();
	void set_audio_mode();
	void set_local_mute();
	void set_on_voice_state_changed_callback();
	void set_participant_changed_callback();
	void set_participant_volume();
	void set_pttactive();
	void set_pttrelease_delay();
	void set_self_deaf();
	void set_self_mute();
	void set_speaking_status_changed_callback();
	void set_status_changed_callback();
	void set_vadthreshold();
	static void error_to_string();
	static void status_to_string();

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

	void channel_id();
	void get_participants();
	void get_voice_state_handle();
	void guild_id();

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

	void id();
	void name();
	void recipients();
	void type();

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

	void end_call();
	void end_calls();
	void get_call();
	void get_calls();
	void get_current_input_device();
	void get_current_output_device();
	void get_input_devices();
	void get_input_volume();
	void get_output_devices();
	void get_output_volume();
	void get_self_deaf_all();
	void get_self_mute_all();
	void set_aec_dump();
	void set_automatic_gain_control();
	void set_device_change_callback();
	void set_echo_cancellation();
	void set_engine_managed_audio_session();
	void set_input_device();
	void set_input_volume();
	void set_no_audio_input_callback();
	void set_no_audio_input_threshold();
	void set_noise_suppression();
	void set_opus_hardware_coding();
	void set_output_device();
	void set_output_volume();
	void set_self_deaf_all();
	void set_self_mute_all();
	void set_speaker_mode();
	void set_thread_priority();
	void set_voice_participant_changed_callback();
	void show_audio_route_picker();
	void start_call();
	void start_call_with_audio_callbacks();
	void abort_authorize();
	void abort_get_token_from_device();
	void authorize();
	void close_authorize_device_screen();
	void create_authorization_code_verifier();
	void exchange_child_token();
	void fetch_current_user();
	void get_provisional_token();
	void get_token();
	void get_token_from_device();
	void get_token_from_device_provisional_merge();
	void get_token_from_provisional_merge();
	void is_authenticated();
	void open_authorize_device_screen();
	void provisional_user_merge_completed();
	void refresh_token();
	void register_authorize_request_callback();
	void remove_authorize_request_callback();
	void revoke_token();
	void set_authorize_device_screen_closed_callback();
	void set_game_window_pid();
	void set_token_expiration_callback();
	void unmerge_into_provisional_account();
	void update_provisional_account_display_name();
	void update_token();
	void can_open_message_in_discord();
	void delete_user_message();
	void edit_user_message();
	void get_channel_handle();
	void get_lobby_messages_with_limit();
	void get_message_handle();
	void get_user_message_summaries();
	void get_user_messages_with_limit();
	void open_message_in_discord();
	void send_lobby_message();
	void send_lobby_message_with_metadata();
	void send_user_message();
	void send_user_message_with_metadata();
	void set_message_created_callback();
	void set_message_deleted_callback();
	void set_message_updated_callback();
	void set_showing_chat();
	void add_log_callback();
	void add_voice_log_callback();
	void connect_discord();
	void disconnect_discord();
	void get_status();
	void open_connected_games_settings_in_discord();
	void set_application_id();
	void set_log_dir();
	void set_status_changed_callback();
	void set_voice_log_dir();
	void create_or_join_lobby();
	void create_or_join_lobby_with_metadata();
	void get_guild_channels();
	void get_lobby_handle();
	void get_lobby_ids();
	void get_user_guilds();
	void join_linked_lobby_guild();
	void leave_lobby();
	void link_channel_to_lobby();
	void set_lobby_created_callback();
	void set_lobby_deleted_callback();
	void set_lobby_member_added_callback();
	void set_lobby_member_removed_callback();
	void set_lobby_member_updated_callback();
	void set_lobby_updated_callback();
	void unlink_channel_from_lobby();
	void is_discord_app_installed();
	void accept_activity_invite();
	void clear_rich_presence();
	void register_launch_command();
	void register_launch_steam_application();
	void send_activity_invite();
	void send_activity_join_request();
	void send_activity_join_request_reply();
	void set_activity_invite_created_callback();
	void set_activity_invite_updated_callback();
	void set_activity_join_callback();
	void set_activity_join_with_application_callback();
	void set_online_status();
	void update_rich_presence();
	void accept_discord_friend_request();
	void accept_game_friend_request();
	void block_user();
	void cancel_discord_friend_request();
	void cancel_game_friend_request();
	void get_relationship_handle();
	void get_relationships();
	void get_relationships_by_group();
	void reject_discord_friend_request();
	void reject_game_friend_request();
	void remove_discord_and_game_friend();
	void remove_game_friend();
	void search_friends_by_username();
	void send_discord_friend_request();
	void send_discord_friend_request_by_id();
	void send_game_friend_request();
	void send_game_friend_request_by_id();
	void set_relationship_created_callback();
	void set_relationship_deleted_callback();
	void unblock_user();
	void get_current_user_v();
	void get_discord_client_connected_user();
	void get_user();
	void set_relationship_groups_updated_callback();
	void set_user_updated_callback();
	void get_application_id();
	void get_current_user();
	void set_http_request_timeout();
	static void error_to_string();
	static void get_default_audio_device_id();
	static void get_default_communication_scopes();
	static void get_default_presence_scopes();
	static void get_version_hash();
	static void get_version_major();
	static void get_version_minor();
	static void get_version_patch();
	static void status_to_string();
	static void thread_to_string();

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

	void web_base();
	void set_web_base();
	void api_base();
	void set_api_base();
	void experimental_audio_system();
	void set_experimental_audio_system();
	void experimental_android_prevent_comms_for_bluetooth();
	void set_experimental_android_prevent_comms_for_bluetooth();
	void cpu_affinity_mask();
	void set_cpu_affinity_mask();

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

	void to_string_discord();
	void type();
	void set_type();
	void error();
	void set_error();
	void error_code();
	void set_error_code();
	void status();
	void set_status();
	void response_body();
	void set_response_body();
	void successful();
	void set_successful();
	void retryable();
	void set_retryable();
	void retry_after();
	void set_retry_after();

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

	void client_id();
	void set_client_id();
	void scopes();
	void set_scopes();

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

	void id();
	void set_id();
	void name();
	void set_name();
	void type();
	void set_type();
	void position();
	void set_position();
	void parent_id();
	void set_parent_id();
	void is_linkable();
	void set_is_linkable();
	void is_viewable_and_writeable_by_all_members();
	void set_is_viewable_and_writeable_by_all_members();
	void linked_lobby();
	void set_linked_lobby();

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

	void id();
	void set_id();
	void name();
	void set_name();

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

	void id();
	void set_id();
	void name();
	void set_name();
	void guild_id();
	void set_guild_id();

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

	void application_id();
	void set_application_id();
	void lobby_id();
	void set_lobby_id();

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

	void get_call_info_handle();
	void get_lobby_member_handle();
	void id();
	void linked_channel();
	void lobby_member_ids();
	void lobby_members();
	void metadata();

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

	void can_link_lobby();
	void connected();
	void id();
	void metadata();
	void user();

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

	void additional_content();
	void application_id();
	void author();
	void author_id();
	void channel();
	void channel_id();
	void content();
	void disclosure_type();
	void edited_timestamp();
	void id();
	void lobby();
	void metadata();
	void moderation_metadata();
	void raw_content();
	void recipient();
	void recipient_id();
	void sent_from_game();
	void sent_timestamp();

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

	void discord_relationship_type();
	void game_relationship_type();
	void id();
	void is_spam_request();
	void user();

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

	void avatar_hash();
	void metadata();
	void provider_id();
	void provider_issued_user_id();
	void provider_type();
	void username();

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

	void avatar();
	void avatar_url();
	void display_name();
	void game_activity();
	void global_name();
	void id();
	void is_provisional();
	void relationship();
	void status();
	void user_application_profiles();
	void username();
	static void avatar_type_to_string();

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

	void last_message_id();
	void user_id();

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

	void vad_threshold();
	void set_vad_threshold();
	void automatic();
	void set_automatic();

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

	void self_deaf();
	void self_mute();

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
