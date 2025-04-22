
#ifndef DISCORD_CLASSES_H
#define DISCORD_CLASSES_H

#include "discordpp.h"
#include "discordpp_enum.h"
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
	static void RunCallbacks();
	static String EnumToString21(DiscordppUserHandleAvatarType::Enum value);
	static String EnumToString20(DiscordppStatusType::Enum value);
	static String EnumToString19(DiscordppRelationshipType::Enum value);
	static String EnumToString18(DiscordppLoggingSeverity::Enum value);
	static String EnumToString17(DiscordppHttpStatusCode::Enum value);
	static String EnumToString16(DiscordppErrorType::Enum value);
	static String EnumToString15(DiscordppDisclosureTypes::Enum value);
	static String EnumToString14(DiscordppClientThread::Enum value);
	static String EnumToString13(DiscordppClientStatus::Enum value);
	static String EnumToString12(DiscordppClientError::Enum value);
	static String EnumToString11(DiscordppChannelType::Enum value);
	static String EnumToString10(DiscordppCallStatus::Enum value);
	static String EnumToString9(DiscordppCallError::Enum value);
	static String EnumToString8(DiscordppAuthorizationTokenType::Enum value);
	static String EnumToString7(DiscordppAuthenticationExternalAuthType::Enum value);
	static String EnumToString6(DiscordppAuthenticationCodeChallengeMethod::Enum value);
	static String EnumToString5(DiscordppAudioModeType::Enum value);
	static String EnumToString4(DiscordppAdditionalContentType::Enum value);
	static String EnumToString3(DiscordppActivityTypes::Enum value);
	static String EnumToString2(DiscordppActivityPartyPrivacy::Enum value);
	static String EnumToString1(DiscordppActivityGamePlatforms::Enum value);
	static String EnumToString0(DiscordppActivityActionTypes::Enum value);

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
	int64_t SenderId();
	void SetSenderId(int64_t SenderId);
	int64_t ChannelId();
	void SetChannelId(int64_t ChannelId);
	int64_t MessageId();
	void SetMessageId(int64_t MessageId);
	DiscordppActivityActionTypes::Enum Type();
	void SetType(DiscordppActivityActionTypes::Enum Type);
	int64_t ApplicationId();
	void SetApplicationId(int64_t ApplicationId);
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
	int64_t Start();
	void SetStart(int64_t Start);
	int64_t End();
	void SetEnd(int64_t End);

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
	int64_t CurrentSize();
	void SetCurrentSize(int64_t CurrentSize);
	int64_t MaxSize();
	void SetMaxSize(int64_t MaxSize);
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
	int64_t ErrorCode();
	void SetErrorCode(int64_t ErrorCode);
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
	int64_t ClientId();
	void SetClientId(int64_t ClientId);
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
	int64_t ClientId();
	void SetClientId(int64_t ClientId);
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
	static String ErrorToString(DiscordppCallError::Enum type);
	DiscordppAudioModeType::Enum GetAudioMode();
	int64_t GetChannelId();
	int64_t GetGuildId();
	bool GetLocalMute(int64_t userId);
	TypedArray<int64_t> GetParticipants();
	float GetParticipantVolume(int64_t userId);
	bool GetPTTActive();
	bool GetSelfDeaf();
	bool GetSelfMute();
	DiscordppCallStatus::Enum GetStatus();
	DiscordppVADThresholdSettings *GetVADThreshold();
	Variant GetVoiceStateHandle(int64_t userId);
	void SetAudioMode(DiscordppAudioModeType::Enum audioMode);
	void SetLocalMute(int64_t userId, bool mute);
	void SetOnVoiceStateChangedCallback(Callable cb);
	void SetParticipantChangedCallback(Callable cb);
	void SetParticipantVolume(int64_t userId, float volume);
	void SetPTTActive(bool active);
	void SetPTTReleaseDelay(int64_t releaseDelayMs);
	void SetSelfDeaf(bool deaf);
	void SetSelfMute(bool mute);
	void SetSpeakingStatusChangedCallback(Callable cb);
	void SetStatusChangedCallback(Callable cb);
	void SetVADThreshold(bool automatic, float threshold);
	static String StatusToString(DiscordppCallStatus::Enum type);

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
	int64_t Id();
	String Name();
	TypedArray<int64_t> Recipients();
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
	int64_t Id();
	void SetId(int64_t Id);
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
	int64_t Id();
	void SetId(int64_t Id);
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
	int64_t ApplicationId();
	void SetApplicationId(int64_t ApplicationId);
	int64_t LobbyId();
	void SetLobbyId(int64_t LobbyId);

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
	int64_t Id();
	void SetId(int64_t Id);
	String Name();
	void SetName(String Name);
	int64_t GuildId();
	void SetGuildId(int64_t GuildId);

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
	int64_t Id();
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
	static String AvatarTypeToString(DiscordppUserHandleAvatarType::Enum type);
	String AvatarUrl(DiscordppUserHandleAvatarType::Enum animatedType, DiscordppUserHandleAvatarType::Enum staticType);
	String DisplayName();
	Variant GameActivity();
	Variant GlobalName();
	int64_t Id();
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
	int64_t Id();
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
	Variant GetLobbyMemberHandle(int64_t memberId);
	int64_t Id();
	Variant LinkedChannel();
	TypedArray<int64_t> LobbyMemberIds();
	TypedArray<DiscordppLobbyMemberHandle> LobbyMembers();
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
	static String TypeToString(DiscordppAdditionalContentType::Enum type);
	DiscordppAdditionalContentType::Enum Type();
	void SetType(DiscordppAdditionalContentType::Enum Type);
	Variant Title();
	void SetTitle(Variant Title);
	int64_t Count();
	void SetCount(int64_t Count);

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
	int64_t AuthorId();
	Variant Channel();
	int64_t ChannelId();
	String Content();
	Variant DisclosureType();
	int64_t EditedTimestamp();
	int64_t Id();
	Variant Lobby();
	TypedDictionary<String, String> Metadata();
	String RawContent();
	Variant Recipient();
	int64_t RecipientId();
	bool SentFromGame();
	int64_t SentTimestamp();

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
	static String ErrorToString(DiscordppClientError::Enum type);
	static String GetDefaultAudioDeviceId();
	static String GetDefaultCommunicationScopes();
	static String GetDefaultPresenceScopes();
	static String GetVersionHash();
	static int64_t GetVersionMajor();
	static int64_t GetVersionMinor();
	static int64_t GetVersionPatch();
	static String StatusToString(DiscordppClientStatus::Enum type);
	static String ThreadToString(DiscordppClientThread::Enum type);
	void EndCall(int64_t channelId, Callable callback);
	void EndCalls(Callable callback);
	DiscordppCall *GetCall(int64_t channelId);
	TypedArray<DiscordppCall> GetCalls();
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
	void SetThreadPriority(DiscordppClientThread::Enum thread, int64_t priority);
	void SetVoiceParticipantChangedCallback(Callable cb);
	bool ShowAudioRoutePicker();
	DiscordppCall *StartCall(int64_t channelId);
	DiscordppCall *StartCallWithAudioCallbacks(int64_t lobbyId, Callable receivedCb, Callable capturedCb);
	void AbortAuthorize();
	void AbortGetTokenFromDevice();
	void Authorize(DiscordppAuthorizationArgs *args, Callable callback);
	void CloseAuthorizeDeviceScreen();
	DiscordppAuthorizationCodeVerifier *CreateAuthorizationCodeVerifier();
	void FetchCurrentUser(DiscordppAuthorizationTokenType::Enum tokenType, String token, Callable callback);
	void GetProvisionalToken(int64_t applicationId, DiscordppAuthenticationExternalAuthType::Enum externalAuthType, String externalAuthToken, Callable callback);
	void GetToken(int64_t applicationId, String code, String codeVerifier, String redirectUri, Callable callback);
	void GetTokenFromDevice(DiscordppDeviceAuthorizationArgs *args, Callable callback);
	void GetTokenFromDeviceProvisionalMerge(DiscordppDeviceAuthorizationArgs *args, DiscordppAuthenticationExternalAuthType::Enum externalAuthType, String externalAuthToken, Callable callback);
	void GetTokenFromProvisionalMerge(int64_t applicationId, String code, String codeVerifier, String redirectUri, DiscordppAuthenticationExternalAuthType::Enum externalAuthType, String externalAuthToken, Callable callback);
	bool IsAuthenticated();
	void OpenAuthorizeDeviceScreen(int64_t clientId, String userCode);
	void ProvisionalUserMergeCompleted(bool success);
	void RefreshToken(int64_t applicationId, String refreshToken, Callable callback);
	void SetAuthorizeDeviceScreenClosedCallback(Callable cb);
	void SetGameWindowPid(int64_t pid);
	void SetTokenExpirationCallback(Callable callback);
	void UpdateProvisionalAccountDisplayName(String name, Callable callback);
	void UpdateToken(DiscordppAuthorizationTokenType::Enum tokenType, String token, Callable callback);
	bool CanOpenMessageInDiscord(int64_t messageId);
	void DeleteUserMessage(int64_t recipientId, int64_t messageId, Callable cb);
	void EditUserMessage(int64_t recipientId, int64_t messageId, String content, Callable cb);
	Variant GetChannelHandle(int64_t channelId);
	Variant GetMessageHandle(int64_t messageId);
	void OpenMessageInDiscord(int64_t messageId, Callable provisionalUserMergeRequiredCallback, Callable callback);
	void SendLobbyMessage(int64_t lobbyId, String content, Callable cb);
	void SendLobbyMessageWithMetadata(int64_t lobbyId, String content, TypedDictionary<String, String> metadata, Callable cb);
	void SendUserMessage(int64_t recipientId, String content, Callable cb);
	void SendUserMessageWithMetadata(int64_t recipientId, String content, TypedDictionary<String, String> metadata, Callable cb);
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
	void GetGuildChannels(int64_t guildId, Callable cb);
	Variant GetLobbyHandle(int64_t lobbyId);
	TypedArray<int64_t> GetLobbyIds();
	void GetUserGuilds(Callable cb);
	void LeaveLobby(int64_t lobbyId, Callable callback);
	void LinkChannelToLobby(int64_t lobbyId, int64_t channelId, Callable callback);
	void SetLobbyCreatedCallback(Callable cb);
	void SetLobbyDeletedCallback(Callable cb);
	void SetLobbyMemberAddedCallback(Callable cb);
	void SetLobbyMemberRemovedCallback(Callable cb);
	void SetLobbyMemberUpdatedCallback(Callable cb);
	void SetLobbyUpdatedCallback(Callable cb);
	void UnlinkChannelFromLobby(int64_t lobbyId, Callable callback);
	void AcceptActivityInvite(DiscordppActivityInvite *invite, Callable cb);
	void ClearRichPresence();
	bool RegisterLaunchCommand(int64_t applicationId, String command);
	bool RegisterLaunchSteamApplication(int64_t applicationId, int64_t steamAppId);
	void SendActivityInvite(int64_t userId, String content, Callable cb);
	void SendActivityJoinRequest(int64_t userId, Callable cb);
	void SendActivityJoinRequestReply(DiscordppActivityInvite *invite, Callable cb);
	void SetActivityInviteCreatedCallback(Callable cb);
	void SetActivityInviteUpdatedCallback(Callable cb);
	void SetActivityJoinCallback(Callable cb);
	void SetOnlineStatus(DiscordppStatusType::Enum status, Callable callback);
	void UpdateRichPresence(DiscordppActivity *activity, Callable cb);
	void AcceptDiscordFriendRequest(int64_t userId, Callable cb);
	void AcceptGameFriendRequest(int64_t userId, Callable cb);
	void BlockUser(int64_t userId, Callable cb);
	void CancelDiscordFriendRequest(int64_t userId, Callable cb);
	void CancelGameFriendRequest(int64_t userId, Callable cb);
	DiscordppRelationshipHandle *GetRelationshipHandle(int64_t userId);
	TypedArray<DiscordppRelationshipHandle> GetRelationships();
	void RejectDiscordFriendRequest(int64_t userId, Callable cb);
	void RejectGameFriendRequest(int64_t userId, Callable cb);
	void RemoveDiscordAndGameFriend(int64_t userId, Callable cb);
	void RemoveGameFriend(int64_t userId, Callable cb);
	TypedArray<DiscordppUserHandle> SearchFriendsByUsername(String searchStr);
	void SendDiscordFriendRequest(String username, Callable cb);
	void SendDiscordFriendRequestById(int64_t userId, Callable cb);
	void SendGameFriendRequest(String username, Callable cb);
	void SendGameFriendRequestById(int64_t userId, Callable cb);
	void SetRelationshipCreatedCallback(Callable cb);
	void SetRelationshipDeletedCallback(Callable cb);
	void UnblockUser(int64_t userId, Callable cb);
	DiscordppUserHandle *GetCurrentUser();
	void GetDiscordClientConnectedUser(int64_t applicationId, Callable callback);
	Variant GetUser(int64_t userId);
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
	int64_t ChannelId();
	TypedArray<int64_t> GetParticipants();
	Variant GetVoiceStateHandle(int64_t userId);
	int64_t GuildId();

	DiscordppCallInfoHandle(discordpp::CallInfoHandle *obj) {
		this->obj = obj;
	}

	~DiscordppCallInfoHandle() {}
};

} //namespace godot

#endif
