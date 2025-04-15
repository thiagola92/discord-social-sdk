
#ifndef DISCORD_CLASSES_H
#define DISCORD_CLASSES_H

#include "discord_enum.h"
#include "discordpp.h"
#include "godot_cpp/classes/node.hpp"
#include "godot_cpp/classes/ref_counted.hpp"
#include "godot_cpp/variant/typed_array.hpp"
#include "godot_cpp/variant/typed_dictionary.hpp"

namespace godot {

class Discordpp;
class DiscordppActivityInvite;
class DiscordppActivityAssets;
class DiscordppActivityTimestamps;
class DiscordppActivityParty;
class DiscordppActivitySecrets;
class DiscordppActivity;
class DiscordppClientResult;
class DiscordppAuthorizationCodeChallenge;
class DiscordppAuthorizationCodeVerifier;
class DiscordppAuthorizationArgs;
class DiscordppDeviceAuthorizationArgs;
class DiscordppVoiceStateHandle;
class DiscordppVADThresholdSettings;
class DiscordppCall;
class DiscordppChannelHandle;
class DiscordppGuildMinimal;
class DiscordppGuildChannel;
class DiscordppLinkedLobby;
class DiscordppLinkedChannel;
class DiscordppRelationshipHandle;
class DiscordppUserHandle;
class DiscordppLobbyMemberHandle;
class DiscordppLobbyHandle;
class DiscordppAdditionalContent;
class DiscordppMessageHandle;
class DiscordppAudioDevice;
class DiscordppClient;
class DiscordppCallInfoHandle;

class Discordpp : public RefCounted {
	GDCLASS(Discordpp, RefCounted)

private:
	Discordpp() {}

protected:
	static void _bind_methods();

public:
	String EnumToString0(DiscordppActivityActionTypes::Enum value);
	String EnumToString1(DiscordppActivityGamePlatforms::Enum value);
	String EnumToString2(DiscordppActivityPartyPrivacy::Enum value);
	String EnumToString3(DiscordppActivityTypes::Enum value);
	String EnumToString4(DiscordppAdditionalContentType::Enum value);
	String EnumToString5(DiscordppAudioModeType::Enum value);
	String EnumToString6(DiscordppAuthenticationCodeChallengeMethod::Enum value);
	String EnumToString7(DiscordppAuthenticationExternalAuthType::Enum value);
	String EnumToString8(DiscordppAuthorizationTokenType::Enum value);
	String EnumToString9(DiscordppCallError::Enum value);
	String EnumToString10(DiscordppCallStatus::Enum value);
	String EnumToString11(DiscordppChannelType::Enum value);
	String EnumToString12(DiscordppClientError::Enum value);
	String EnumToString13(DiscordppClientStatus::Enum value);
	String EnumToString14(DiscordppClientThread::Enum value);
	String EnumToString15(DiscordppDisclosureTypes::Enum value);
	String EnumToString16(DiscordppErrorType::Enum value);
	String EnumToString17(DiscordppHttpStatusCode::Enum value);
	String EnumToString18(DiscordppLoggingSeverity::Enum value);
	String EnumToString19(DiscordppRelationshipType::Enum value);
	String EnumToString20(DiscordppStatusType::Enum value);
	String EnumToString21(DiscordppUserHandleAvatarType::Enum value);
	void RunCallbacks();

	~Discordpp() {}
};

class DiscordppActivityInvite : public RefCounted {
	GDCLASS(DiscordppActivityInvite, RefCounted)

private:
	discordpp::ActivityInvite *obj;

protected:
	static void _bind_methods();

public:
	// Internal usage.
	discordpp::ActivityInvite *unwrap() {
		return obj;
	}

	void Drop();
	uint64_t SenderId();
	void SetSenderId(uint64_t SenderId);
	uint64_t ChannelId();
	void SetChannelId(uint64_t ChannelId);
	uint64_t MessageId();
	void SetMessageId(uint64_t MessageId);
	DiscordppActivityActionTypes::Enum Type();
	void SetType(DiscordppActivityActionTypes::Enum Type);
	uint64_t ApplicationId();
	void SetApplicationId(uint64_t ApplicationId);
	String PartyId();
	void SetPartyId(String PartyId);
	bool IsValid();
	void SetIsValid(bool IsValid);

	DiscordppActivityInvite() {
		this->obj = memnew(discordpp::ActivityInvite);
	}

	DiscordppActivityInvite(discordpp::ActivityInvite *obj) {
		this->obj = obj;
	}

	~DiscordppActivityInvite() {}
};

class DiscordppActivityAssets : public RefCounted {
	GDCLASS(DiscordppActivityAssets, RefCounted)

private:
	discordpp::ActivityAssets *obj;

protected:
	static void _bind_methods();

public:
	// Internal usage.
	discordpp::ActivityAssets *unwrap() {
		return obj;
	}

	void Drop();
	Variant LargeImage();
	void SetLargeImage(Variant LargeImage);
	Variant LargeText();
	void SetLargeText(Variant LargeText);
	Variant SmallImage();
	void SetSmallImage(Variant SmallImage);
	Variant SmallText();
	void SetSmallText(Variant SmallText);

	DiscordppActivityAssets() {
		this->obj = memnew(discordpp::ActivityAssets);
	}

	DiscordppActivityAssets(discordpp::ActivityAssets *obj) {
		this->obj = obj;
	}

	~DiscordppActivityAssets() {}
};

class DiscordppActivityTimestamps : public RefCounted {
	GDCLASS(DiscordppActivityTimestamps, RefCounted)

private:
	discordpp::ActivityTimestamps *obj;

protected:
	static void _bind_methods();

public:
	// Internal usage.
	discordpp::ActivityTimestamps *unwrap() {
		return obj;
	}

	void Drop();
	uint64_t Start();
	void SetStart(uint64_t Start);
	uint64_t End();
	void SetEnd(uint64_t End);

	DiscordppActivityTimestamps() {
		this->obj = memnew(discordpp::ActivityTimestamps);
	}

	DiscordppActivityTimestamps(discordpp::ActivityTimestamps *obj) {
		this->obj = obj;
	}

	~DiscordppActivityTimestamps() {}
};

class DiscordppActivityParty : public RefCounted {
	GDCLASS(DiscordppActivityParty, RefCounted)

private:
	discordpp::ActivityParty *obj;

protected:
	static void _bind_methods();

public:
	// Internal usage.
	discordpp::ActivityParty *unwrap() {
		return obj;
	}

	void Drop();
	String Id();
	void SetId(String Id);
	int32_t CurrentSize();
	void SetCurrentSize(int32_t CurrentSize);
	int32_t MaxSize();
	void SetMaxSize(int32_t MaxSize);
	DiscordppActivityPartyPrivacy::Enum Privacy();
	void SetPrivacy(DiscordppActivityPartyPrivacy::Enum Privacy);

	DiscordppActivityParty() {
		this->obj = memnew(discordpp::ActivityParty);
	}

	DiscordppActivityParty(discordpp::ActivityParty *obj) {
		this->obj = obj;
	}

	~DiscordppActivityParty() {}
};

class DiscordppActivitySecrets : public RefCounted {
	GDCLASS(DiscordppActivitySecrets, RefCounted)

private:
	discordpp::ActivitySecrets *obj;

protected:
	static void _bind_methods();

public:
	// Internal usage.
	discordpp::ActivitySecrets *unwrap() {
		return obj;
	}

	void Drop();
	String Join();
	void SetJoin(String Join);

	DiscordppActivitySecrets() {
		this->obj = memnew(discordpp::ActivitySecrets);
	}

	DiscordppActivitySecrets(discordpp::ActivitySecrets *obj) {
		this->obj = obj;
	}

	~DiscordppActivitySecrets() {}
};

class DiscordppActivity : public RefCounted {
	GDCLASS(DiscordppActivity, RefCounted)

private:
	discordpp::Activity *obj;

protected:
	static void _bind_methods();

public:
	// Internal usage.
	discordpp::Activity *unwrap() {
		return obj;
	}

	void Drop();
	bool Equals(DiscordppActivity *other);
	String Name();
	void SetName(String Name);
	DiscordppActivityTypes::Enum Type();
	void SetType(DiscordppActivityTypes::Enum Type);
	Variant State();
	void SetState(Variant State);
	Variant Details();
	void SetDetails(Variant Details);
	Variant ApplicationId();
	void SetApplicationId(Variant ApplicationId);
	Variant Assets();
	void SetAssets(Variant Assets);
	Variant Timestamps();
	void SetTimestamps(Variant Timestamps);
	Variant Party();
	void SetParty(Variant Party);
	Variant Secrets();
	void SetSecrets(Variant Secrets);
	DiscordppActivityGamePlatforms::Enum SupportedPlatforms();
	void SetSupportedPlatforms(DiscordppActivityGamePlatforms::Enum SupportedPlatforms);

	DiscordppActivity() {
		this->obj = memnew(discordpp::Activity);
	}

	DiscordppActivity(discordpp::Activity *obj) {
		this->obj = obj;
	}

	~DiscordppActivity() {}
};

class DiscordppClientResult : public RefCounted {
	GDCLASS(DiscordppClientResult, RefCounted)

private:
	discordpp::ClientResult *obj;
	DiscordppClientResult() {}

protected:
	static void _bind_methods();

public:
	// Internal usage.
	discordpp::ClientResult *unwrap() {
		return obj;
	}

	void Drop();
	String ToString();
	DiscordppErrorType::Enum Type();
	void SetType(DiscordppErrorType::Enum Type);
	String Error();
	void SetError(String Error);
	int32_t ErrorCode();
	void SetErrorCode(int32_t ErrorCode);
	DiscordppHttpStatusCode::Enum Status();
	void SetStatus(DiscordppHttpStatusCode::Enum Status);
	String ResponseBody();
	void SetResponseBody(String ResponseBody);
	bool Successful();
	void SetSuccessful(bool Successful);
	bool Retryable();
	void SetRetryable(bool Retryable);
	float RetryAfter();
	void SetRetryAfter(float RetryAfter);

	DiscordppClientResult(discordpp::ClientResult *obj) {
		this->obj = obj;
	}

	~DiscordppClientResult() {}
};

class DiscordppAuthorizationCodeChallenge : public RefCounted {
	GDCLASS(DiscordppAuthorizationCodeChallenge, RefCounted)

private:
	discordpp::AuthorizationCodeChallenge *obj;

protected:
	static void _bind_methods();

public:
	// Internal usage.
	discordpp::AuthorizationCodeChallenge *unwrap() {
		return obj;
	}

	void Drop();
	DiscordppAuthenticationCodeChallengeMethod::Enum Method();
	void SetMethod(DiscordppAuthenticationCodeChallengeMethod::Enum Method);
	String Challenge();
	void SetChallenge(String Challenge);

	DiscordppAuthorizationCodeChallenge() {
		this->obj = memnew(discordpp::AuthorizationCodeChallenge);
	}

	DiscordppAuthorizationCodeChallenge(discordpp::AuthorizationCodeChallenge *obj) {
		this->obj = obj;
	}

	~DiscordppAuthorizationCodeChallenge() {}
};

class DiscordppAuthorizationCodeVerifier : public RefCounted {
	GDCLASS(DiscordppAuthorizationCodeVerifier, RefCounted)

private:
	discordpp::AuthorizationCodeVerifier *obj;
	DiscordppAuthorizationCodeVerifier() {}

protected:
	static void _bind_methods();

public:
	// Internal usage.
	discordpp::AuthorizationCodeVerifier *unwrap() {
		return obj;
	}

	void Drop();
	DiscordppAuthorizationCodeChallenge *Challenge();
	void SetChallenge(DiscordppAuthorizationCodeChallenge *Challenge);
	String Verifier();
	void SetVerifier(String Verifier);

	DiscordppAuthorizationCodeVerifier(discordpp::AuthorizationCodeVerifier *obj) {
		this->obj = obj;
	}

	~DiscordppAuthorizationCodeVerifier() {}
};

class DiscordppAuthorizationArgs : public RefCounted {
	GDCLASS(DiscordppAuthorizationArgs, RefCounted)

private:
	discordpp::AuthorizationArgs *obj;

protected:
	static void _bind_methods();

public:
	// Internal usage.
	discordpp::AuthorizationArgs *unwrap() {
		return obj;
	}

	void Drop();
	uint64_t ClientId();
	void SetClientId(uint64_t ClientId);
	String Scopes();
	void SetScopes(String Scopes);
	Variant State();
	void SetState(Variant State);
	Variant Nonce();
	void SetNonce(Variant Nonce);
	Variant CodeChallenge();
	void SetCodeChallenge(Variant CodeChallenge);

	DiscordppAuthorizationArgs() {
		this->obj = memnew(discordpp::AuthorizationArgs);
	}

	DiscordppAuthorizationArgs(discordpp::AuthorizationArgs *obj) {
		this->obj = obj;
	}

	~DiscordppAuthorizationArgs() {}
};

class DiscordppDeviceAuthorizationArgs : public RefCounted {
	GDCLASS(DiscordppDeviceAuthorizationArgs, RefCounted)

private:
	discordpp::DeviceAuthorizationArgs *obj;

protected:
	static void _bind_methods();

public:
	// Internal usage.
	discordpp::DeviceAuthorizationArgs *unwrap() {
		return obj;
	}

	void Drop();
	uint64_t ClientId();
	void SetClientId(uint64_t ClientId);
	String Scopes();
	void SetScopes(String Scopes);

	DiscordppDeviceAuthorizationArgs() {
		this->obj = memnew(discordpp::DeviceAuthorizationArgs);
	}

	DiscordppDeviceAuthorizationArgs(discordpp::DeviceAuthorizationArgs *obj) {
		this->obj = obj;
	}

	~DiscordppDeviceAuthorizationArgs() {}
};

class DiscordppVoiceStateHandle : public RefCounted {
	GDCLASS(DiscordppVoiceStateHandle, RefCounted)

private:
	discordpp::VoiceStateHandle *obj;
	DiscordppVoiceStateHandle() {}

protected:
	static void _bind_methods();

public:
	// Internal usage.
	discordpp::VoiceStateHandle *unwrap() {
		return obj;
	}

	void Drop();
	bool SelfDeaf();
	bool SelfMute();

	DiscordppVoiceStateHandle(discordpp::VoiceStateHandle *obj) {
		this->obj = obj;
	}

	~DiscordppVoiceStateHandle() {}
};

class DiscordppVADThresholdSettings : public RefCounted {
	GDCLASS(DiscordppVADThresholdSettings, RefCounted)

private:
	discordpp::VADThresholdSettings *obj;
	DiscordppVADThresholdSettings() {}

protected:
	static void _bind_methods();

public:
	// Internal usage.
	discordpp::VADThresholdSettings *unwrap() {
		return obj;
	}

	void Drop();
	float VadThreshold();
	void SetVadThreshold(float VadThreshold);
	bool Automatic();
	void SetAutomatic(bool Automatic);

	DiscordppVADThresholdSettings(discordpp::VADThresholdSettings *obj) {
		this->obj = obj;
	}

	~DiscordppVADThresholdSettings() {}
};

class DiscordppCall : public RefCounted {
	GDCLASS(DiscordppCall, RefCounted)

private:
	discordpp::Call *obj;
	DiscordppCall() {}

protected:
	static void _bind_methods();

public:
	// Internal usage.
	discordpp::Call *unwrap() {
		return obj;
	}

	void Drop();
	String ErrorToString(DiscordppCallError::Enum type);
	DiscordppAudioModeType::Enum GetAudioMode();
	uint64_t GetChannelId();
	uint64_t GetGuildId();
	bool GetLocalMute(uint64_t userId);
	TypedArray<uint64_t> GetParticipants();
	float GetParticipantVolume(uint64_t userId);
	bool GetPTTActive();
	bool GetSelfDeaf();
	bool GetSelfMute();
	DiscordppCallStatus::Enum GetStatus();
	DiscordppVADThresholdSettings *GetVADThreshold();
	Variant GetVoiceStateHandle(uint64_t userId);
	void SetAudioMode(DiscordppAudioModeType::Enum audioMode);
	void SetLocalMute(uint64_t userId, bool mute);
	void SetOnVoiceStateChangedCallback(Callable cb);
	void SetParticipantChangedCallback(Callable cb);
	void SetParticipantVolume(uint64_t userId, float volume);
	void SetPTTActive(bool active);
	void SetPTTReleaseDelay(uint32_t releaseDelayMs);
	void SetSelfDeaf(bool deaf);
	void SetSelfMute(bool mute);
	void SetSpeakingStatusChangedCallback(Callable cb);
	void SetStatusChangedCallback(Callable cb);
	void SetVADThreshold(bool automatic, float threshold);
	String StatusToString(DiscordppCallStatus::Enum type);

	DiscordppCall(discordpp::Call *obj) {
		this->obj = obj;
	}

	~DiscordppCall() {}
};

class DiscordppChannelHandle : public RefCounted {
	GDCLASS(DiscordppChannelHandle, RefCounted)

private:
	discordpp::ChannelHandle *obj;
	DiscordppChannelHandle() {}

protected:
	static void _bind_methods();

public:
	// Internal usage.
	discordpp::ChannelHandle *unwrap() {
		return obj;
	}

	void Drop();
	uint64_t Id();
	String Name();
	TypedArray<uint64_t> Recipients();
	DiscordppChannelType::Enum Type();

	DiscordppChannelHandle(discordpp::ChannelHandle *obj) {
		this->obj = obj;
	}

	~DiscordppChannelHandle() {}
};

class DiscordppGuildMinimal : public RefCounted {
	GDCLASS(DiscordppGuildMinimal, RefCounted)

private:
	discordpp::GuildMinimal *obj;
	DiscordppGuildMinimal() {}

protected:
	static void _bind_methods();

public:
	// Internal usage.
	discordpp::GuildMinimal *unwrap() {
		return obj;
	}

	void Drop();
	uint64_t Id();
	void SetId(uint64_t Id);
	String Name();
	void SetName(String Name);

	DiscordppGuildMinimal(discordpp::GuildMinimal *obj) {
		this->obj = obj;
	}

	~DiscordppGuildMinimal() {}
};

class DiscordppGuildChannel : public RefCounted {
	GDCLASS(DiscordppGuildChannel, RefCounted)

private:
	discordpp::GuildChannel *obj;
	DiscordppGuildChannel() {}

protected:
	static void _bind_methods();

public:
	// Internal usage.
	discordpp::GuildChannel *unwrap() {
		return obj;
	}

	void Drop();
	uint64_t Id();
	void SetId(uint64_t Id);
	String Name();
	void SetName(String Name);
	bool IsLinkable();
	void SetIsLinkable(bool IsLinkable);
	bool IsViewableAndWriteableByAllMembers();
	void SetIsViewableAndWriteableByAllMembers(bool IsViewableAndWriteableByAllMembers);
	Variant LinkedLobby();
	void SetLinkedLobby(Variant LinkedLobby);

	DiscordppGuildChannel(discordpp::GuildChannel *obj) {
		this->obj = obj;
	}

	~DiscordppGuildChannel() {}
};

class DiscordppLinkedLobby : public RefCounted {
	GDCLASS(DiscordppLinkedLobby, RefCounted)

private:
	discordpp::LinkedLobby *obj;

protected:
	static void _bind_methods();

public:
	// Internal usage.
	discordpp::LinkedLobby *unwrap() {
		return obj;
	}

	void Drop();
	uint64_t ApplicationId();
	void SetApplicationId(uint64_t ApplicationId);
	uint64_t LobbyId();
	void SetLobbyId(uint64_t LobbyId);

	DiscordppLinkedLobby() {
		this->obj = memnew(discordpp::LinkedLobby);
	}

	DiscordppLinkedLobby(discordpp::LinkedLobby *obj) {
		this->obj = obj;
	}

	~DiscordppLinkedLobby() {}
};

class DiscordppLinkedChannel : public RefCounted {
	GDCLASS(DiscordppLinkedChannel, RefCounted)

private:
	discordpp::LinkedChannel *obj;
	DiscordppLinkedChannel() {}

protected:
	static void _bind_methods();

public:
	// Internal usage.
	discordpp::LinkedChannel *unwrap() {
		return obj;
	}

	void Drop();
	uint64_t Id();
	void SetId(uint64_t Id);
	String Name();
	void SetName(String Name);
	uint64_t GuildId();
	void SetGuildId(uint64_t GuildId);

	DiscordppLinkedChannel(discordpp::LinkedChannel *obj) {
		this->obj = obj;
	}

	~DiscordppLinkedChannel() {}
};

class DiscordppRelationshipHandle : public RefCounted {
	GDCLASS(DiscordppRelationshipHandle, RefCounted)

private:
	discordpp::RelationshipHandle *obj;
	DiscordppRelationshipHandle() {}

protected:
	static void _bind_methods();

public:
	// Internal usage.
	discordpp::RelationshipHandle *unwrap() {
		return obj;
	}

	void Drop();
	DiscordppRelationshipType::Enum DiscordRelationshipType();
	DiscordppRelationshipType::Enum GameRelationshipType();
	uint64_t Id();
	Variant User();

	DiscordppRelationshipHandle(discordpp::RelationshipHandle *obj) {
		this->obj = obj;
	}

	~DiscordppRelationshipHandle() {}
};

class DiscordppUserHandle : public RefCounted {
	GDCLASS(DiscordppUserHandle, RefCounted)

private:
	discordpp::UserHandle *obj;
	DiscordppUserHandle() {}

protected:
	static void _bind_methods();

public:
	// Internal usage.
	discordpp::UserHandle *unwrap() {
		return obj;
	}

	void Drop();
	Variant Avatar();
	String AvatarTypeToString(DiscordppUserHandleAvatarType::Enum type);
	String AvatarUrl(DiscordppUserHandleAvatarType::Enum animatedType, DiscordppUserHandleAvatarType::Enum staticType);
	String DisplayName();
	Variant GameActivity();
	Variant GlobalName();
	uint64_t Id();
	bool IsProvisional();
	DiscordppRelationshipHandle *Relationship();
	DiscordppStatusType::Enum Status();
	String Username();

	DiscordppUserHandle(discordpp::UserHandle *obj) {
		this->obj = obj;
	}

	~DiscordppUserHandle() {}
};

class DiscordppLobbyMemberHandle : public RefCounted {
	GDCLASS(DiscordppLobbyMemberHandle, RefCounted)

private:
	discordpp::LobbyMemberHandle *obj;
	DiscordppLobbyMemberHandle() {}

protected:
	static void _bind_methods();

public:
	// Internal usage.
	discordpp::LobbyMemberHandle *unwrap() {
		return obj;
	}

	void Drop();
	bool CanLinkLobby();
	bool Connected();
	uint64_t Id();
	TypedDictionary<String, String> Metadata();
	Variant User();

	DiscordppLobbyMemberHandle(discordpp::LobbyMemberHandle *obj) {
		this->obj = obj;
	}

	~DiscordppLobbyMemberHandle() {}
};

class DiscordppLobbyHandle : public RefCounted {
	GDCLASS(DiscordppLobbyHandle, RefCounted)

private:
	discordpp::LobbyHandle *obj;
	DiscordppLobbyHandle() {}

protected:
	static void _bind_methods();

public:
	// Internal usage.
	discordpp::LobbyHandle *unwrap() {
		return obj;
	}

	void Drop();
	Variant GetCallInfoHandle();
	Variant GetLobbyMemberHandle(uint64_t memberId);
	uint64_t Id();
	Variant LinkedChannel();
	TypedArray<uint64_t> LobbyMemberIds();
	TypedArray<DiscordppLobbyMemberHandle *> LobbyMembers();
	TypedDictionary<String, String> Metadata();

	DiscordppLobbyHandle(discordpp::LobbyHandle *obj) {
		this->obj = obj;
	}

	~DiscordppLobbyHandle() {}
};

class DiscordppAdditionalContent : public RefCounted {
	GDCLASS(DiscordppAdditionalContent, RefCounted)

private:
	discordpp::AdditionalContent *obj;

protected:
	static void _bind_methods();

public:
	// Internal usage.
	discordpp::AdditionalContent *unwrap() {
		return obj;
	}

	void Drop();
	bool Equals(DiscordppAdditionalContent *rhs);
	String TypeToString(DiscordppAdditionalContentType::Enum type);
	DiscordppAdditionalContentType::Enum Type();
	void SetType(DiscordppAdditionalContentType::Enum Type);
	Variant Title();
	void SetTitle(Variant Title);
	uint8_t Count();
	void SetCount(uint8_t Count);

	DiscordppAdditionalContent() {
		this->obj = memnew(discordpp::AdditionalContent);
	}

	DiscordppAdditionalContent(discordpp::AdditionalContent *obj) {
		this->obj = obj;
	}

	~DiscordppAdditionalContent() {}
};

class DiscordppMessageHandle : public RefCounted {
	GDCLASS(DiscordppMessageHandle, RefCounted)

private:
	discordpp::MessageHandle *obj;
	DiscordppMessageHandle() {}

protected:
	static void _bind_methods();

public:
	// Internal usage.
	discordpp::MessageHandle *unwrap() {
		return obj;
	}

	void Drop();
	Variant AdditionalContent();
	Variant Author();
	uint64_t AuthorId();
	Variant Channel();
	uint64_t ChannelId();
	String Content();
	Variant DisclosureType();
	uint64_t EditedTimestamp();
	uint64_t Id();
	Variant Lobby();
	TypedDictionary<String, String> Metadata();
	String RawContent();
	Variant Recipient();
	uint64_t RecipientId();
	bool SentFromGame();
	uint64_t SentTimestamp();

	DiscordppMessageHandle(discordpp::MessageHandle *obj) {
		this->obj = obj;
	}

	~DiscordppMessageHandle() {}
};

class DiscordppAudioDevice : public RefCounted {
	GDCLASS(DiscordppAudioDevice, RefCounted)

private:
	discordpp::AudioDevice *obj;
	DiscordppAudioDevice() {}

protected:
	static void _bind_methods();

public:
	// Internal usage.
	discordpp::AudioDevice *unwrap() {
		return obj;
	}

	void Drop();
	bool Equals(DiscordppAudioDevice *rhs);
	String Id();
	void SetId(String Id);
	String Name();
	void SetName(String Name);
	bool IsDefault();
	void SetIsDefault(bool IsDefault);

	DiscordppAudioDevice(discordpp::AudioDevice *obj) {
		this->obj = obj;
	}

	~DiscordppAudioDevice() {}
};

class DiscordppClient : public RefCounted {
	GDCLASS(DiscordppClient, RefCounted)

private:
	discordpp::Client *obj;

protected:
	static void _bind_methods();

public:
	// Internal usage.
	discordpp::Client *unwrap() {
		return obj;
	}

	void Drop();
	String ErrorToString(DiscordppClientError::Enum type);
	String GetDefaultAudioDeviceId();
	String GetDefaultCommunicationScopes();
	String GetDefaultPresenceScopes();
	String GetVersionHash();
	static int32_t GetVersionMajor();
	static int32_t GetVersionMinor();
	static int32_t GetVersionPatch();
	String StatusToString(DiscordppClientStatus::Enum type);
	String ThreadToString(DiscordppClientThread::Enum type);
	void EndCall(uint64_t channelId, Callable callback);
	void EndCalls(Callable callback);
	DiscordppCall *GetCall(uint64_t channelId);
	TypedArray<DiscordppCall *> GetCalls();
	void GetCurrentInputDevice(Callable cb);
	void GetCurrentOutputDevice(Callable cb);
	void GetInputDevices(Callable cb);
	float GetInputVolume();
	void GetOutputDevices(Callable cb);
	float GetOutputVolume();
	bool GetSelfDeafAll();
	bool GetSelfMuteAll();
	void SetAutomaticGainControl(bool on);
	void SetDeviceChangeCallback(Callable callback);
	void SetEchoCancellation(bool on);
	void SetInputDevice(String deviceId, Callable cb);
	void SetInputVolume(float inputVolume);
	void SetNoAudioInputCallback(Callable callback);
	void SetNoAudioInputThreshold(float dBFSThreshold);
	void SetNoiseSuppression(bool on);
	void SetOpusHardwareCoding(bool encode, bool decode);
	void SetOutputDevice(String deviceId, Callable cb);
	void SetOutputVolume(float outputVolume);
	void SetSelfDeafAll(bool deaf);
	void SetSelfMuteAll(bool mute);
	bool SetSpeakerMode(bool speakerMode);
	void SetThreadPriority(DiscordppClientThread::Enum thread, int32_t priority);
	void SetVoiceParticipantChangedCallback(Callable cb);
	bool ShowAudioRoutePicker();
	DiscordppCall *StartCall(uint64_t channelId);
	DiscordppCall *StartCallWithAudioCallbacks(uint64_t lobbyId, Callable receivedCb, Callable capturedCb);
	void AbortAuthorize();
	void AbortGetTokenFromDevice();
	void Authorize(DiscordppAuthorizationArgs *args, Callable callback);
	void CloseAuthorizeDeviceScreen();
	DiscordppAuthorizationCodeVerifier *CreateAuthorizationCodeVerifier();
	void FetchCurrentUser(DiscordppAuthorizationTokenType::Enum tokenType, String token, Callable callback);
	void GetProvisionalToken(uint64_t applicationId, DiscordppAuthenticationExternalAuthType::Enum externalAuthType, String externalAuthToken, Callable callback);
	void GetToken(uint64_t applicationId, String code, String codeVerifier, String redirectUri, Callable callback);
	void GetTokenFromDevice(DiscordppDeviceAuthorizationArgs *args, Callable callback);
	void GetTokenFromDeviceProvisionalMerge(DiscordppDeviceAuthorizationArgs *args, DiscordppAuthenticationExternalAuthType::Enum externalAuthType, String externalAuthToken, Callable callback);
	void GetTokenFromProvisionalMerge(uint64_t applicationId, String code, String codeVerifier, String redirectUri, DiscordppAuthenticationExternalAuthType::Enum externalAuthType, String externalAuthToken, Callable callback);
	bool IsAuthenticated();
	void OpenAuthorizeDeviceScreen(uint64_t clientId, String userCode);
	void ProvisionalUserMergeCompleted(bool success);
	void RefreshToken(uint64_t applicationId, String refreshToken, Callable callback);
	void SetAuthorizeDeviceScreenClosedCallback(Callable cb);
	void SetGameWindowPid(int32_t pid);
	void SetTokenExpirationCallback(Callable callback);
	void UpdateProvisionalAccountDisplayName(String name, Callable callback);
	void UpdateToken(DiscordppAuthorizationTokenType::Enum tokenType, String token, Callable callback);
	bool CanOpenMessageInDiscord(uint64_t messageId);
	void DeleteUserMessage(uint64_t recipientId, uint64_t messageId, Callable cb);
	void EditUserMessage(uint64_t recipientId, uint64_t messageId, String content, Callable cb);
	Variant GetChannelHandle(uint64_t channelId);
	Variant GetMessageHandle(uint64_t messageId);
	void OpenMessageInDiscord(uint64_t messageId, Callable provisionalUserMergeRequiredCallback, Callable callback);
	void SendLobbyMessage(uint64_t lobbyId, String content, Callable cb);
	void SendLobbyMessageWithMetadata(uint64_t lobbyId, String content, TypedDictionary<String, String> metadata, Callable cb);
	void SendUserMessage(uint64_t recipientId, String content, Callable cb);
	void SendUserMessageWithMetadata(uint64_t recipientId, String content, TypedDictionary<String, String> metadata, Callable cb);
	void SetMessageCreatedCallback(Callable cb);
	void SetMessageDeletedCallback(Callable cb);
	void SetMessageUpdatedCallback(Callable cb);
	void SetShowingChat(bool showingChat);
	void AddLogCallback(Callable callback, DiscordppLoggingSeverity::Enum minSeverity);
	void AddVoiceLogCallback(Callable callback, DiscordppLoggingSeverity::Enum minSeverity);
	void Connect();
	void Disconnect();
	DiscordppClientStatus::Enum GetStatus();
	bool SetLogDir(String path, DiscordppLoggingSeverity::Enum minSeverity);
	void SetStatusChangedCallback(Callable cb);
	void SetVoiceLogDir(String path, DiscordppLoggingSeverity::Enum minSeverity);
	void CreateOrJoinLobby(String secret, Callable callback);
	void CreateOrJoinLobbyWithMetadata(String secret, TypedDictionary<String, String> lobbyMetadata, TypedDictionary<String, String> memberMetadata, Callable callback);
	void GetGuildChannels(uint64_t guildId, Callable cb);
	Variant GetLobbyHandle(uint64_t lobbyId);
	TypedArray<uint64_t> GetLobbyIds();
	void GetUserGuilds(Callable cb);
	void LeaveLobby(uint64_t lobbyId, Callable callback);
	void LinkChannelToLobby(uint64_t lobbyId, uint64_t channelId, Callable callback);
	void SetLobbyCreatedCallback(Callable cb);
	void SetLobbyDeletedCallback(Callable cb);
	void SetLobbyMemberAddedCallback(Callable cb);
	void SetLobbyMemberRemovedCallback(Callable cb);
	void SetLobbyMemberUpdatedCallback(Callable cb);
	void SetLobbyUpdatedCallback(Callable cb);
	void UnlinkChannelFromLobby(uint64_t lobbyId, Callable callback);
	void AcceptActivityInvite(DiscordppActivityInvite *invite, Callable cb);
	void ClearRichPresence();
	bool RegisterLaunchCommand(uint64_t applicationId, String command);
	bool RegisterLaunchSteamApplication(uint64_t applicationId, uint32_t steamAppId);
	void SendActivityInvite(uint64_t userId, String content, Callable cb);
	void SendActivityJoinRequest(uint64_t userId, Callable cb);
	void SendActivityJoinRequestReply(DiscordppActivityInvite *invite, Callable cb);
	void SetActivityInviteCreatedCallback(Callable cb);
	void SetActivityInviteUpdatedCallback(Callable cb);
	void SetActivityJoinCallback(Callable cb);
	void SetOnlineStatus(DiscordppStatusType::Enum status, Callable callback);
	void UpdateRichPresence(DiscordppActivity *activity, Callable cb);
	void AcceptDiscordFriendRequest(uint64_t userId, Callable cb);
	void AcceptGameFriendRequest(uint64_t userId, Callable cb);
	void BlockUser(uint64_t userId, Callable cb);
	void CancelDiscordFriendRequest(uint64_t userId, Callable cb);
	void CancelGameFriendRequest(uint64_t userId, Callable cb);
	DiscordppRelationshipHandle *GetRelationshipHandle(uint64_t userId);
	TypedArray<DiscordppRelationshipHandle *> GetRelationships();
	void RejectDiscordFriendRequest(uint64_t userId, Callable cb);
	void RejectGameFriendRequest(uint64_t userId, Callable cb);
	void RemoveDiscordAndGameFriend(uint64_t userId, Callable cb);
	void RemoveGameFriend(uint64_t userId, Callable cb);
	TypedArray<DiscordppUserHandle *> SearchFriendsByUsername(String searchStr);
	void SendDiscordFriendRequest(String username, Callable cb);
	void SendDiscordFriendRequestById(uint64_t userId, Callable cb);
	void SendGameFriendRequest(String username, Callable cb);
	void SendGameFriendRequestById(uint64_t userId, Callable cb);
	void SetRelationshipCreatedCallback(Callable cb);
	void SetRelationshipDeletedCallback(Callable cb);
	void UnblockUser(uint64_t userId, Callable cb);
	DiscordppUserHandle *GetCurrentUser();
	void GetDiscordClientConnectedUser(uint64_t applicationId, Callable callback);
	Variant GetUser(uint64_t userId);
	void SetUserUpdatedCallback(Callable cb);

	DiscordppClient() {
		this->obj = memnew(discordpp::Client);
	}

	DiscordppClient(discordpp::Client *obj) {
		this->obj = obj;
	}

	~DiscordppClient() {}
};

class DiscordppCallInfoHandle : public RefCounted {
	GDCLASS(DiscordppCallInfoHandle, RefCounted)

private:
	discordpp::CallInfoHandle *obj;
	DiscordppCallInfoHandle() {}

protected:
	static void _bind_methods();

public:
	// Internal usage.
	discordpp::CallInfoHandle *unwrap() {
		return obj;
	}

	void Drop();
	uint64_t ChannelId();
	TypedArray<uint64_t> GetParticipants();
	Variant GetVoiceStateHandle(uint64_t userId);
	uint64_t GuildId();

	DiscordppCallInfoHandle(discordpp::CallInfoHandle *obj) {
		this->obj = obj;
	}

	~DiscordppCallInfoHandle() {}
};

} //namespace godot

#endif
