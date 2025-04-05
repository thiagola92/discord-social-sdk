// AUTO-GENERATED
#ifndef DISCORD_CLASSES_H
#define DISCORD_CLASSES_H

#include "discordpp.h"
#include "discord_enum.h"
#include "godot_cpp/classes/node.hpp"
#include "godot_cpp/classes/ref_counted.hpp"
#include "godot_cpp/variant/typed_dictionary.hpp"
#include "godot_cpp/variant/typed_array.hpp"

namespace godot {

class DiscordActivity;
class DiscordActivityAssets;
class DiscordActivityInvite;
class DiscordActivityParty;
class DiscordActivitySecrets;
class DiscordActivityTimestamps;
class DiscordAdditionalContent;
class DiscordAudioDevice;
class DiscordCall;
class DiscordCallInfoHandle;
class DiscordChannelHandle;
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

    bool equals(DiscordAdditionalContent * rhs);
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

    bool equals(DiscordAudioDevice * rhs);
    String id();
    void set_id(String id);
    String name();
    void set_name(String name);
    bool is_default();
    void set_is_default(bool is_default);

    
    DiscordAudioDevice(discordpp::AudioDevice *audio_device);
    ~DiscordAudioDevice();
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
    DiscordVADThresholdSettings * get_vadthreshold();
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
    TypedArray<DiscordLobbyMemberHandle *> lobby_members();
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
    DiscordRelationshipHandle * relationship();
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
