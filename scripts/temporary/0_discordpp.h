

enum class DiscordObjectState {
	Invalid,
	Owned,
};

inline void RunCallbacks() {
	Discord_RunCallbacks();
}

enum class ActivityActionTypes {

	Join = 1,

	JoinRequest = 5,
};

enum class ActivityPartyPrivacy {

	Private = 0,

	Public = 1,
};

enum class ActivityTypes {

	Playing = 0,

	Streaming = 1,

	Listening = 2,

	Watching = 3,

	CustomStatus = 4,

	Competing = 5,

	HangStatus = 6,
};

enum class ActivityGamePlatforms {

	Desktop = 1,

	Xbox = 2,

	Samsung = 4,

	IOS = 8,

	Android = 16,

	Embedded = 32,

	PS4 = 64,

	PS5 = 128,
};

enum class ErrorType {

	None = 0,

	NetworkError = 1,

	HTTPError = 2,

	ClientNotReady = 3,

	Disabled = 4,

	ClientDestroyed = 5,

	ValidationError = 6,

	Aborted = 7,

	AuthorizationFailed = 8,

	RPCError = 9,
};

enum class HttpStatusCode {

	None = 0,

	Continue = 100,

	SwitchingProtocols = 101,

	Processing = 102,

	EarlyHints = 103,

	Ok = 200,

	Created = 201,

	Accepted = 202,

	NonAuthoritativeInfo = 203,

	NoContent = 204,

	ResetContent = 205,

	PartialContent = 206,

	MultiStatus = 207,

	AlreadyReported = 208,

	ImUsed = 209,

	MultipleChoices = 300,

	MovedPermanently = 301,

	Found = 302,

	SeeOther = 303,

	NotModified = 304,

	TemporaryRedirect = 307,

	PermanentRedirect = 308,

	BadRequest = 400,

	Unauthorized = 401,

	PaymentRequired = 402,

	Forbidden = 403,

	NotFound = 404,

	MethodNotAllowed = 405,

	NotAcceptable = 406,

	ProxyAuthRequired = 407,

	RequestTimeout = 408,

	Conflict = 409,

	Gone = 410,

	LengthRequired = 411,

	PreconditionFailed = 412,

	PayloadTooLarge = 413,

	UriTooLong = 414,

	UnsupportedMediaType = 415,

	RangeNotSatisfiable = 416,

	ExpectationFailed = 417,

	MisdirectedRequest = 421,

	UnprocessableEntity = 422,

	Locked = 423,

	FailedDependency = 424,

	TooEarly = 425,

	UpgradeRequired = 426,

	PreconditionRequired = 428,

	TooManyRequests = 429,

	RequestHeaderFieldsTooLarge = 431,

	InternalServerError = 500,

	NotImplemented = 501,

	BadGateway = 502,

	ServiceUnavailable = 503,

	GatewayTimeout = 504,

	HttpVersionNotSupported = 505,

	VariantAlsoNegotiates = 506,

	InsufficientStorage = 507,

	LoopDetected = 508,

	NotExtended = 510,

	NetworkAuthorizationRequired = 511,
};

enum class AuthenticationCodeChallengeMethod {

	S256 = 0,
};

enum class AdditionalContentType {

	Other = 0,

	Attachment = 1,

	Poll = 2,

	VoiceMessage = 3,

	Thread = 4,

	Embed = 5,

	Sticker = 6,
};

enum class AudioModeType {

	MODE_UNINIT = 0,

	MODE_VAD = 1,

	MODE_PTT = 2,
};

enum class ChannelType {

	GuildText = 0,

	Dm = 1,

	GuildVoice = 2,

	GroupDm = 3,

	GuildCategory = 4,

	GuildNews = 5,

	GuildStore = 6,

	GuildNewsThread = 10,

	GuildPublicThread = 11,

	GuildPrivateThread = 12,

	GuildStageVoice = 13,

	GuildDirectory = 14,

	GuildForum = 15,

	GuildMedia = 16,

	Lobby = 17,

	EphemeralDm = 18,
};

enum class RelationshipType {

	None = 0,

	Friend = 1,

	Blocked = 2,

	PendingIncoming = 3,

	PendingOutgoing = 4,

	Implicit = 5,

	Suggestion = 6,
};

enum class StatusType {

	Online = 0,

	Offline = 1,

	Blocked = 2,

	Idle = 3,

	Dnd = 4,

	Invisible = 5,

	Streaming = 6,

	Unknown = 7,
};

enum class DisclosureTypes {

	MessageDataVisibleOnDiscord = 3,
};

enum class AuthorizationTokenType {

	User = 0,

	Bearer = 1,
};

enum class AuthenticationExternalAuthType {

	OIDC = 0,

	EpicOnlineServicesAccessToken = 1,

	EpicOnlineServicesIdToken = 2,

	SteamSessionTicket = 3,
};

enum class LoggingSeverity {

	Verbose = 1,

	Info = 2,

	Warning = 3,

	Error = 4,

	None = 5,
};

class ActivityInvite {


	ActivityInvite(const ActivityInvite &rhs);

	explicit ActivityInvite();

	void Drop();

	uint64_t SenderId() const;
	void SetSenderId(uint64_t SenderId);

	uint64_t ChannelId() const;
	void SetChannelId(uint64_t ChannelId);

	uint64_t MessageId() const;
	void SetMessageId(uint64_t MessageId);

	discordpp::ActivityActionTypes Type() const;
	void SetType(discordpp::ActivityActionTypes Type);

	uint64_t ApplicationId() const;
	void SetApplicationId(uint64_t ApplicationId);

	std::string PartyId() const;
	void SetPartyId(std::string PartyId);

	bool IsValid() const;
	void SetIsValid(bool IsValid);
};

class ActivityAssets {


	ActivityAssets(const ActivityAssets &arg0);

	explicit ActivityAssets();

	void Drop();

	std::optional<std::string> LargeImage() const;
	void SetLargeImage(std::optional<std::string> LargeImage);

	std::optional<std::string> LargeText() const;
	void SetLargeText(std::optional<std::string> LargeText);

	std::optional<std::string> SmallImage() const;
	void SetSmallImage(std::optional<std::string> SmallImage);

	std::optional<std::string> SmallText() const;
	void SetSmallText(std::optional<std::string> SmallText);
};

class ActivityTimestamps {


	ActivityTimestamps(const ActivityTimestamps &arg0);

	explicit ActivityTimestamps();

	void Drop();

	uint64_t Start() const;
	void SetStart(uint64_t Start);

	uint64_t End() const;
	void SetEnd(uint64_t End);
};

class ActivityParty {


	ActivityParty(const ActivityParty &arg0);

	explicit ActivityParty();

	void Drop();

	std::string Id() const;
	void SetId(std::string Id);

	int32_t CurrentSize() const;
	void SetCurrentSize(int32_t CurrentSize);

	int32_t MaxSize() const;
	void SetMaxSize(int32_t MaxSize);

	discordpp::ActivityPartyPrivacy Privacy() const;
	void SetPrivacy(discordpp::ActivityPartyPrivacy Privacy);
};

class ActivitySecrets {


	ActivitySecrets(const ActivitySecrets &arg0);

	explicit ActivitySecrets();

	void Drop();

	std::string Join() const;
	void SetJoin(std::string Join);
};

class Activity {


	Activity(const Activity &arg0);

	explicit Activity();

	void Drop();

	bool Equals(discordpp::Activity other) const;

	std::string Name() const;
	void SetName(std::string Name);

	discordpp::ActivityTypes Type() const;
	void SetType(discordpp::ActivityTypes Type);

	std::optional<std::string> State() const;
	void SetState(std::optional<std::string> State);

	std::optional<std::string> Details() const;
	void SetDetails(std::optional<std::string> Details);

	std::optional<uint64_t> ApplicationId() const;
	void SetApplicationId(std::optional<uint64_t> ApplicationId);

	std::optional<discordpp::ActivityAssets> Assets() const;
	void SetAssets(std::optional<discordpp::ActivityAssets> Assets);

	std::optional<discordpp::ActivityTimestamps> Timestamps() const;
	void SetTimestamps(std::optional<discordpp::ActivityTimestamps> Timestamps);

	std::optional<discordpp::ActivityParty> Party() const;
	void SetParty(std::optional<discordpp::ActivityParty> Party);

	std::optional<discordpp::ActivitySecrets> Secrets() const;
	void SetSecrets(std::optional<discordpp::ActivitySecrets> Secrets);

	discordpp::ActivityGamePlatforms SupportedPlatforms() const;
	void SetSupportedPlatforms(discordpp::ActivityGamePlatforms SupportedPlatforms);
};

class ClientResult {


	ClientResult(const ClientResult &arg0);

	void Drop();

	std::string ToString() const;

	discordpp::ErrorType Type() const;
	void SetType(discordpp::ErrorType Type);

	std::string Error() const;
	void SetError(std::string Error);

	int32_t ErrorCode() const;
	void SetErrorCode(int32_t ErrorCode);

	discordpp::HttpStatusCode Status() const;
	void SetStatus(discordpp::HttpStatusCode Status);

	std::string ResponseBody() const;
	void SetResponseBody(std::string ResponseBody);

	bool Successful() const;
	void SetSuccessful(bool Successful);

	bool Retryable() const;
	void SetRetryable(bool Retryable);

	float RetryAfter() const;
	void SetRetryAfter(float RetryAfter);
};

class AuthorizationCodeChallenge {


	AuthorizationCodeChallenge(const AuthorizationCodeChallenge &arg0);

	explicit AuthorizationCodeChallenge();

	void Drop();

	discordpp::AuthenticationCodeChallengeMethod Method() const;
	void SetMethod(discordpp::AuthenticationCodeChallengeMethod Method);

	std::string Challenge() const;
	void SetChallenge(std::string Challenge);
};

class AuthorizationCodeVerifier {


	AuthorizationCodeVerifier(const AuthorizationCodeVerifier &arg0);

	void Drop();

	discordpp::AuthorizationCodeChallenge Challenge() const;
	void SetChallenge(discordpp::AuthorizationCodeChallenge Challenge);

	std::string Verifier() const;
	void SetVerifier(std::string Verifier);
};

class AuthorizationArgs {


	AuthorizationArgs(const AuthorizationArgs &arg0);

	explicit AuthorizationArgs();

	void Drop();

	uint64_t ClientId() const;
	void SetClientId(uint64_t ClientId);

	std::string Scopes() const;
	void SetScopes(std::string Scopes);

	std::optional<std::string> State() const;
	void SetState(std::optional<std::string> State);

	std::optional<std::string> Nonce() const;
	void SetNonce(std::optional<std::string> Nonce);

	std::optional<discordpp::AuthorizationCodeChallenge> CodeChallenge() const;
	void SetCodeChallenge(std::optional<discordpp::AuthorizationCodeChallenge> CodeChallenge);
};

class DeviceAuthorizationArgs {


	DeviceAuthorizationArgs(const DeviceAuthorizationArgs &arg0);

	explicit DeviceAuthorizationArgs();

	void Drop();

	uint64_t ClientId() const;
	void SetClientId(uint64_t ClientId);

	std::string Scopes() const;
	void SetScopes(std::string Scopes);
};

class VoiceStateHandle {


	VoiceStateHandle(const VoiceStateHandle &other);

	void Drop();

	bool SelfDeaf() const;

	bool SelfMute() const;
};

class VADThresholdSettings {


	VADThresholdSettings(const VADThresholdSettings &) = delete;

	void Drop();

	float VadThreshold() const;
	void SetVadThreshold(float VadThreshold);

	bool Automatic() const;
	void SetAutomatic(bool Automatic);
};

class Call {

	enum class Error {

		None = 0,

		SignalingConnectionFailed = 1,

		SignalingUnexpectedClose = 2,

		VoiceConnectionFailed = 3,

		JoinTimeout = 4,

		Forbidden = 5,
	};

	enum class Status {

		Disconnected = 0,

		Joining = 1,

		Connecting = 2,

		SignalingConnected = 3,

		Connected = 4,

		Reconnecting = 5,

		Disconnecting = 6,
	};

	using OnVoiceStateChanged = std::function<void(uint64_t userId)>;

	using OnParticipantChanged = std::function<void(uint64_t userId, bool added)>;

	using OnSpeakingStatusChanged = std::function<void(uint64_t userId, bool isPlayingSound)>;

	using OnStatusChanged = std::function<
			void(discordpp::Call::Status status, discordpp::Call::Error error, int32_t errorDetail)>;

	Call(const Call &other);

	void Drop();

	static std::string ErrorToString(discordpp::Call::Error type);

	discordpp::AudioModeType GetAudioMode();

	uint64_t GetChannelId() const;

	uint64_t GetGuildId() const;

	bool GetLocalMute(uint64_t userId);

	std::vector<uint64_t> GetParticipants() const;

	float GetParticipantVolume(uint64_t userId);

	bool GetPTTActive();

	bool GetSelfDeaf();

	bool GetSelfMute();

	discordpp::Call::Status GetStatus() const;

	discordpp::VADThresholdSettings GetVADThreshold() const;

	std::optional<discordpp::VoiceStateHandle> GetVoiceStateHandle(uint64_t userId) const;

	void SetAudioMode(discordpp::AudioModeType audioMode);

	void SetLocalMute(uint64_t userId, bool mute);

	void SetOnVoiceStateChangedCallback(discordpp::Call::OnVoiceStateChanged cb);

	void SetParticipantChangedCallback(discordpp::Call::OnParticipantChanged cb);

	void SetParticipantVolume(uint64_t userId, float volume);

	void SetPTTActive(bool active);

	void SetPTTReleaseDelay(uint32_t releaseDelayMs);

	void SetSelfDeaf(bool deaf);

	void SetSelfMute(bool mute);

	void SetSpeakingStatusChangedCallback(discordpp::Call::OnSpeakingStatusChanged cb);

	void SetStatusChangedCallback(discordpp::Call::OnStatusChanged cb);

	void SetVADThreshold(bool automatic, float threshold);

	static std::string StatusToString(discordpp::Call::Status type);
};

class ChannelHandle {


	ChannelHandle(const ChannelHandle &other);

	void Drop();

	uint64_t Id() const;

	std::string Name() const;

	std::vector<uint64_t> Recipients() const;

	discordpp::ChannelType Type() const;
};

class GuildMinimal {


	GuildMinimal(const GuildMinimal &arg0);

	void Drop();

	uint64_t Id() const;
	void SetId(uint64_t Id);

	std::string Name() const;
	void SetName(std::string Name);
};

class GuildChannel {


	GuildChannel(const GuildChannel &arg0);

	void Drop();

	uint64_t Id() const;
	void SetId(uint64_t Id);

	std::string Name() const;
	void SetName(std::string Name);

	bool IsLinkable() const;
	void SetIsLinkable(bool IsLinkable);

	bool IsViewableAndWriteableByAllMembers() const;
	void SetIsViewableAndWriteableByAllMembers(bool IsViewableAndWriteableByAllMembers);

	std::optional<discordpp::LinkedLobby> LinkedLobby() const;
	void SetLinkedLobby(std::optional<discordpp::LinkedLobby> LinkedLobby);
};

class LinkedLobby {


	LinkedLobby(const LinkedLobby &arg0);

	explicit LinkedLobby();

	void Drop();

	uint64_t ApplicationId() const;
	void SetApplicationId(uint64_t ApplicationId);

	uint64_t LobbyId() const;
	void SetLobbyId(uint64_t LobbyId);
};

class LinkedChannel {


	LinkedChannel(const LinkedChannel &arg0);

	void Drop();

	uint64_t Id() const;
	void SetId(uint64_t Id);

	std::string Name() const;
	void SetName(std::string Name);

	uint64_t GuildId() const;
	void SetGuildId(uint64_t GuildId);
};

class RelationshipHandle {


	RelationshipHandle(const RelationshipHandle &other);

	void Drop();

	discordpp::RelationshipType DiscordRelationshipType() const;

	discordpp::RelationshipType GameRelationshipType() const;

	uint64_t Id() const;

	std::optional<discordpp::UserHandle> User() const;
};

class UserHandle {

	enum class AvatarType {

		Gif = 0,

		Webp = 1,

		Png = 2,

		Jpeg = 3,
	};

	UserHandle(const UserHandle &arg0);

	void Drop();

	std::optional<std::string> Avatar() const;

	static std::string AvatarTypeToString(discordpp::UserHandle::AvatarType type);

	std::string AvatarUrl(discordpp::UserHandle::AvatarType animatedType,
			discordpp::UserHandle::AvatarType staticType) const;

	std::string DisplayName() const;

	std::optional<discordpp::Activity> GameActivity() const;

	std::optional<std::string> GlobalName() const;

	uint64_t Id() const;

	bool IsProvisional() const;

	discordpp::RelationshipHandle Relationship() const;

	discordpp::StatusType Status() const;

	std::string Username() const;
};

class LobbyMemberHandle {


	LobbyMemberHandle(const LobbyMemberHandle &other);

	void Drop();

	bool CanLinkLobby() const;

	bool Connected() const;

	uint64_t Id() const;

	std::unordered_map<std::string, std::string> Metadata() const;

	std::optional<discordpp::UserHandle> User() const;
};

class LobbyHandle {


	LobbyHandle(const LobbyHandle &other);

	void Drop();

	std::optional<discordpp::CallInfoHandle> GetCallInfoHandle() const;

	std::optional<discordpp::LobbyMemberHandle> GetLobbyMemberHandle(uint64_t memberId) const;

	uint64_t Id() const;

	std::optional<discordpp::LinkedChannel> LinkedChannel() const;

	std::vector<uint64_t> LobbyMemberIds() const;

	std::vector<discordpp::LobbyMemberHandle> LobbyMembers() const;

	std::unordered_map<std::string, std::string> Metadata() const;
};

class AdditionalContent {


	AdditionalContent(const AdditionalContent &arg0);

	explicit AdditionalContent();

	void Drop();

	bool Equals(discordpp::AdditionalContent rhs) const;

	static std::string TypeToString(discordpp::AdditionalContentType type);

	discordpp::AdditionalContentType Type() const;
	void SetType(discordpp::AdditionalContentType Type);

	std::optional<std::string> Title() const;
	void SetTitle(std::optional<std::string> Title);

	uint8_t Count() const;
	void SetCount(uint8_t Count);
};

class MessageHandle {


	MessageHandle(const MessageHandle &other);

	void Drop();

	std::optional<discordpp::AdditionalContent> AdditionalContent() const;

	std::optional<discordpp::UserHandle> Author() const;

	uint64_t AuthorId() const;

	std::optional<discordpp::ChannelHandle> Channel() const;

	uint64_t ChannelId() const;

	std::string Content() const;

	std::optional<discordpp::DisclosureTypes> DisclosureType() const;

	uint64_t EditedTimestamp() const;

	uint64_t Id() const;

	std::optional<discordpp::LobbyHandle> Lobby() const;

	std::unordered_map<std::string, std::string> Metadata() const;

	std::string RawContent() const;

	std::optional<discordpp::UserHandle> Recipient() const;

	uint64_t RecipientId() const;

	bool SentFromGame() const;

	uint64_t SentTimestamp() const;
};

class AudioDevice {


	AudioDevice(const AudioDevice &arg0);

	void Drop();

	bool Equals(discordpp::AudioDevice rhs);

	std::string Id() const;
	void SetId(std::string Id);

	std::string Name() const;
	void SetName(std::string Name);

	bool IsDefault() const;
	void SetIsDefault(bool IsDefault);
};

class Client {

	enum class Error {

		None = 0,

		ConnectionFailed = 1,

		UnexpectedClose = 2,

		ConnectionCanceled = 3,
	};

	enum class Status {

		Disconnected = 0,

		Connecting = 1,

		Connected = 2,

		Ready = 3,

		Reconnecting = 4,

		Disconnecting = 5,

		HttpWait = 6,
	};

	enum class Thread {

		Client = 0,

		Voice = 1,

		Network = 2,
	};

	using EndCallCallback = std::function<void()>;

	using EndCallsCallback = std::function<void()>;

	using GetCurrentInputDeviceCallback = std::function<void(discordpp::AudioDevice device)>;

	using GetCurrentOutputDeviceCallback = std::function<void(discordpp::AudioDevice device)>;

	using GetInputDevicesCallback =
			std::function<void(std::vector<discordpp::AudioDevice> devices)>;

	using GetOutputDevicesCallback =
			std::function<void(std::vector<discordpp::AudioDevice> devices)>;

	using DeviceChangeCallback =
			std::function<void(std::vector<discordpp::AudioDevice> inputDevices,
					std::vector<discordpp::AudioDevice> outputDevices)>;

	using SetInputDeviceCallback = std::function<void(discordpp::ClientResult result)>;

	using NoAudioInputCallback = std::function<void(bool inputDetected)>;

	using SetOutputDeviceCallback = std::function<void(discordpp::ClientResult result)>;

	using VoiceParticipantChangedCallback =
			std::function<void(uint64_t lobbyId, uint64_t memberId, bool added)>;

	using UserAudioReceivedCallback = std::function<void(uint64_t userId,
			int16_t const *data,
			uint64_t samplesPerChannel,
			int32_t sampleRate,
			uint64_t channels,
			bool &outShouldMute)>;

	using UserAudioCapturedCallback = std::function<
			void(int16_t const *data, uint64_t samplesPerChannel, int32_t sampleRate, uint64_t channels)>;

	using AuthorizationCallback = std::function<
			void(discordpp::ClientResult result, std::string code, std::string redirectUri)>;

	using FetchCurrentUserCallback =
			std::function<void(discordpp::ClientResult result, uint64_t id, std::string name)>;

	using TokenExchangeCallback = std::function<void(discordpp::ClientResult result,
			std::string accessToken,
			std::string refreshToken,
			discordpp::AuthorizationTokenType tokenType,
			int32_t expiresIn,
			std::string scopes)>;

	using AuthorizeDeviceScreenClosedCallback = std::function<void()>;

	using TokenExpirationCallback = std::function<void()>;

	using UpdateProvisionalAccountDisplayNameCallback =
			std::function<void(discordpp::ClientResult result)>;

	using UpdateTokenCallback = std::function<void(discordpp::ClientResult result)>;

	using DeleteUserMessageCallback = std::function<void(discordpp::ClientResult result)>;

	using EditUserMessageCallback = std::function<void(discordpp::ClientResult result)>;

	using ProvisionalUserMergeRequiredCallback = std::function<void()>;

	using OpenMessageInDiscordCallback = std::function<void(discordpp::ClientResult result)>;

	using SendUserMessageCallback =
			std::function<void(discordpp::ClientResult result, uint64_t messageId)>;

	using MessageCreatedCallback = std::function<void(uint64_t messageId)>;

	using MessageDeletedCallback = std::function<void(uint64_t messageId, uint64_t channelId)>;

	using MessageUpdatedCallback = std::function<void(uint64_t messageId)>;

	using LogCallback =
			std::function<void(std::string message, discordpp::LoggingSeverity severity)>;

	using OnStatusChanged = std::function<
			void(discordpp::Client::Status status, discordpp::Client::Error error, int32_t errorDetail)>;

	using CreateOrJoinLobbyCallback =
			std::function<void(discordpp::ClientResult result, uint64_t lobbyId)>;

	using GetGuildChannelsCallback =
			std::function<void(discordpp::ClientResult result,
					std::vector<discordpp::GuildChannel> guildChannels)>;

	using GetUserGuildsCallback = std::function<void(discordpp::ClientResult result,
			std::vector<discordpp::GuildMinimal> guilds)>;

	using LeaveLobbyCallback = std::function<void(discordpp::ClientResult result)>;

	using LinkOrUnlinkChannelCallback = std::function<void(discordpp::ClientResult result)>;

	using LobbyCreatedCallback = std::function<void(uint64_t lobbyId)>;

	using LobbyDeletedCallback = std::function<void(uint64_t lobbyId)>;

	using LobbyMemberAddedCallback = std::function<void(uint64_t lobbyId, uint64_t memberId)>;

	using LobbyMemberRemovedCallback = std::function<void(uint64_t lobbyId, uint64_t memberId)>;

	using LobbyMemberUpdatedCallback = std::function<void(uint64_t lobbyId, uint64_t memberId)>;

	using LobbyUpdatedCallback = std::function<void(uint64_t lobbyId)>;

	using AcceptActivityInviteCallback =
			std::function<void(discordpp::ClientResult result, std::string joinSecret)>;

	using SendActivityInviteCallback = std::function<void(discordpp::ClientResult result)>;

	using ActivityInviteCallback = std::function<void(discordpp::ActivityInvite invite)>;

	using ActivityJoinCallback = std::function<void(std::string joinSecret)>;

	using UpdateStatusCallback = std::function<void(discordpp::ClientResult result)>;

	using UpdateRichPresenceCallback = std::function<void(discordpp::ClientResult result)>;

	using UpdateRelationshipCallback = std::function<void(discordpp::ClientResult result)>;

	using SendFriendRequestCallback = std::function<void(discordpp::ClientResult result)>;

	using RelationshipCreatedCallback =
			std::function<void(uint64_t userId, bool isDiscordRelationshipUpdate)>;

	using RelationshipDeletedCallback =
			std::function<void(uint64_t userId, bool isDiscordRelationshipUpdate)>;

	using GetDiscordClientConnectedUserCallback =
			std::function<void(discordpp::ClientResult result,
					std::optional<discordpp::UserHandle> user)>;

	using UserUpdatedCallback = std::function<void(uint64_t userId)>;

	Client(const Client &) = delete;

	explicit Client();

	explicit Client(std::string apiBase, std::string webBase);

	void Drop();

	static std::string ErrorToString(discordpp::Client::Error type);

	static std::string GetDefaultAudioDeviceId();

	static std::string GetDefaultCommunicationScopes();

	static std::string GetDefaultPresenceScopes();

	static std::string GetVersionHash();

	static int32_t GetVersionMajor();

	static int32_t GetVersionMinor();

	static int32_t GetVersionPatch();

	static std::string StatusToString(discordpp::Client::Status type);

	static std::string ThreadToString(discordpp::Client::Thread type);


	void EndCall(uint64_t channelId, discordpp::Client::EndCallCallback callback);

	void EndCalls(discordpp::Client::EndCallsCallback callback);

	discordpp::Call GetCall(uint64_t channelId);

	std::vector<discordpp::Call> GetCalls();

	void GetCurrentInputDevice(discordpp::Client::GetCurrentInputDeviceCallback cb);

	void GetCurrentOutputDevice(discordpp::Client::GetCurrentOutputDeviceCallback cb);

	void GetInputDevices(discordpp::Client::GetInputDevicesCallback cb);

	float GetInputVolume();

	void GetOutputDevices(discordpp::Client::GetOutputDevicesCallback cb);

	float GetOutputVolume();

	bool GetSelfDeafAll() const;

	bool GetSelfMuteAll() const;

	void SetAutomaticGainControl(bool on);

	void SetDeviceChangeCallback(discordpp::Client::DeviceChangeCallback callback);

	void SetEchoCancellation(bool on);

	void SetInputDevice(std::string deviceId, discordpp::Client::SetInputDeviceCallback cb);

	void SetInputVolume(float inputVolume);

	void SetNoAudioInputCallback(discordpp::Client::NoAudioInputCallback callback);

	void SetNoAudioInputThreshold(float dBFSThreshold);

	void SetNoiseSuppression(bool on);

	void SetOpusHardwareCoding(bool encode, bool decode);

	void SetOutputDevice(std::string deviceId, discordpp::Client::SetOutputDeviceCallback cb);

	void SetOutputVolume(float outputVolume);

	void SetSelfDeafAll(bool deaf);

	void SetSelfMuteAll(bool mute);

	bool SetSpeakerMode(bool speakerMode);

	void SetThreadPriority(discordpp::Client::Thread thread, int32_t priority);

	void SetVoiceParticipantChangedCallback(discordpp::Client::VoiceParticipantChangedCallback cb);

	bool ShowAudioRoutePicker();

	discordpp::Call StartCall(uint64_t channelId);

	discordpp::Call StartCallWithAudioCallbacks(
			uint64_t lobbyId,
			discordpp::Client::UserAudioReceivedCallback receivedCb,
			discordpp::Client::UserAudioCapturedCallback capturedCb);


	void AbortAuthorize();

	void AbortGetTokenFromDevice();

	void Authorize(discordpp::AuthorizationArgs args,
			discordpp::Client::AuthorizationCallback callback);

	void CloseAuthorizeDeviceScreen();

	discordpp::AuthorizationCodeVerifier CreateAuthorizationCodeVerifier();

	void FetchCurrentUser(discordpp::AuthorizationTokenType tokenType,
			std::string const &token,
			discordpp::Client::FetchCurrentUserCallback callback);

	void GetProvisionalToken(uint64_t applicationId,
			discordpp::AuthenticationExternalAuthType externalAuthType,
			std::string const &externalAuthToken,
			discordpp::Client::TokenExchangeCallback callback);

	void GetToken(uint64_t applicationId,
			std::string const &code,
			std::string const &codeVerifier,
			std::string const &redirectUri,
			discordpp::Client::TokenExchangeCallback callback);

	void GetTokenFromDevice(discordpp::DeviceAuthorizationArgs args,
			discordpp::Client::TokenExchangeCallback callback);

	void GetTokenFromDeviceProvisionalMerge(
			discordpp::DeviceAuthorizationArgs args,
			discordpp::AuthenticationExternalAuthType externalAuthType,
			std::string const &externalAuthToken,
			discordpp::Client::TokenExchangeCallback callback);

	void GetTokenFromProvisionalMerge(uint64_t applicationId,
			std::string const &code,
			std::string const &codeVerifier,
			std::string const &redirectUri,
			discordpp::AuthenticationExternalAuthType externalAuthType,
			std::string const &externalAuthToken,
			discordpp::Client::TokenExchangeCallback callback);

	bool IsAuthenticated();

	void OpenAuthorizeDeviceScreen(uint64_t clientId, std::string const &userCode);

	void ProvisionalUserMergeCompleted(bool success);

	void RefreshToken(uint64_t applicationId,
			std::string const &refreshToken,
			discordpp::Client::TokenExchangeCallback callback);

	void SetAuthorizeDeviceScreenClosedCallback(
			discordpp::Client::AuthorizeDeviceScreenClosedCallback cb);

	void SetGameWindowPid(int32_t pid);

	void SetTokenExpirationCallback(discordpp::Client::TokenExpirationCallback callback);

	void UpdateProvisionalAccountDisplayName(
			std::string const &name,
			discordpp::Client::UpdateProvisionalAccountDisplayNameCallback callback);

	void UpdateToken(discordpp::AuthorizationTokenType tokenType,
			std::string token,
			discordpp::Client::UpdateTokenCallback callback);


	bool CanOpenMessageInDiscord(uint64_t messageId);

	void DeleteUserMessage(uint64_t recipientId,
			uint64_t messageId,
			discordpp::Client::DeleteUserMessageCallback cb);

	void EditUserMessage(uint64_t recipientId,
			uint64_t messageId,
			std::string const &content,
			discordpp::Client::EditUserMessageCallback cb);

	std::optional<discordpp::ChannelHandle> GetChannelHandle(uint64_t channelId) const;

	std::optional<discordpp::MessageHandle> GetMessageHandle(uint64_t messageId) const;

	void OpenMessageInDiscord(
			uint64_t messageId,
			discordpp::Client::ProvisionalUserMergeRequiredCallback provisionalUserMergeRequiredCallback,
			discordpp::Client::OpenMessageInDiscordCallback callback);

	void SendLobbyMessage(uint64_t lobbyId,
			std::string const &content,
			discordpp::Client::SendUserMessageCallback cb);

	void SendLobbyMessageWithMetadata(uint64_t lobbyId,
			std::string const &content,
			std::unordered_map<std::string, std::string> const &metadata,
			discordpp::Client::SendUserMessageCallback cb);

	void SendUserMessage(uint64_t recipientId,
			std::string const &content,
			discordpp::Client::SendUserMessageCallback cb);

	void SendUserMessageWithMetadata(uint64_t recipientId,
			std::string const &content,
			std::unordered_map<std::string, std::string> const &metadata,
			discordpp::Client::SendUserMessageCallback cb);

	void SetMessageCreatedCallback(discordpp::Client::MessageCreatedCallback cb);

	void SetMessageDeletedCallback(discordpp::Client::MessageDeletedCallback cb);

	void SetMessageUpdatedCallback(discordpp::Client::MessageUpdatedCallback cb);

	void SetShowingChat(bool showingChat);


	void AddLogCallback(discordpp::Client::LogCallback callback,
			discordpp::LoggingSeverity minSeverity);

	void AddVoiceLogCallback(discordpp::Client::LogCallback callback,
			discordpp::LoggingSeverity minSeverity);

	void Connect();

	void Disconnect();

	discordpp::Client::Status GetStatus() const;

	bool SetLogDir(std::string const &path, discordpp::LoggingSeverity minSeverity);

	void SetStatusChangedCallback(discordpp::Client::OnStatusChanged cb);

	void SetVoiceLogDir(std::string const &path, discordpp::LoggingSeverity minSeverity);


	void CreateOrJoinLobby(std::string const &secret,
			discordpp::Client::CreateOrJoinLobbyCallback callback);

	void CreateOrJoinLobbyWithMetadata(
			std::string const &secret,
			std::unordered_map<std::string, std::string> const &lobbyMetadata,
			std::unordered_map<std::string, std::string> const &memberMetadata,
			discordpp::Client::CreateOrJoinLobbyCallback callback);

	void GetGuildChannels(uint64_t guildId, discordpp::Client::GetGuildChannelsCallback cb);

	std::optional<discordpp::LobbyHandle> GetLobbyHandle(uint64_t lobbyId) const;

	std::vector<uint64_t> GetLobbyIds() const;

	void GetUserGuilds(discordpp::Client::GetUserGuildsCallback cb);

	void LeaveLobby(uint64_t lobbyId, discordpp::Client::LeaveLobbyCallback callback);

	void LinkChannelToLobby(uint64_t lobbyId,
			uint64_t channelId,
			discordpp::Client::LinkOrUnlinkChannelCallback callback);

	void SetLobbyCreatedCallback(discordpp::Client::LobbyCreatedCallback cb);

	void SetLobbyDeletedCallback(discordpp::Client::LobbyDeletedCallback cb);

	void SetLobbyMemberAddedCallback(discordpp::Client::LobbyMemberAddedCallback cb);

	void SetLobbyMemberRemovedCallback(discordpp::Client::LobbyMemberRemovedCallback cb);

	void SetLobbyMemberUpdatedCallback(discordpp::Client::LobbyMemberUpdatedCallback cb);

	void SetLobbyUpdatedCallback(discordpp::Client::LobbyUpdatedCallback cb);

	void UnlinkChannelFromLobby(uint64_t lobbyId,
			discordpp::Client::LinkOrUnlinkChannelCallback callback);


	void AcceptActivityInvite(discordpp::ActivityInvite invite,
			discordpp::Client::AcceptActivityInviteCallback cb);

	void ClearRichPresence();

	bool RegisterLaunchCommand(uint64_t applicationId, std::string command);

	bool RegisterLaunchSteamApplication(uint64_t applicationId, uint32_t steamAppId);

	void SendActivityInvite(uint64_t userId,
			std::string const &content,
			discordpp::Client::SendActivityInviteCallback cb);

	void SendActivityJoinRequest(uint64_t userId, discordpp::Client::SendActivityInviteCallback cb);

	void SendActivityJoinRequestReply(discordpp::ActivityInvite invite,
			discordpp::Client::SendActivityInviteCallback cb);

	void SetActivityInviteCreatedCallback(discordpp::Client::ActivityInviteCallback cb);

	void SetActivityInviteUpdatedCallback(discordpp::Client::ActivityInviteCallback cb);

	void SetActivityJoinCallback(discordpp::Client::ActivityJoinCallback cb);

	void SetOnlineStatus(discordpp::StatusType status,
			discordpp::Client::UpdateStatusCallback callback);

	void UpdateRichPresence(discordpp::Activity activity,
			discordpp::Client::UpdateRichPresenceCallback cb);


	void AcceptDiscordFriendRequest(uint64_t userId,
			discordpp::Client::UpdateRelationshipCallback cb);

	void AcceptGameFriendRequest(uint64_t userId, discordpp::Client::UpdateRelationshipCallback cb);

	void BlockUser(uint64_t userId, discordpp::Client::UpdateRelationshipCallback cb);

	void CancelDiscordFriendRequest(uint64_t userId,
			discordpp::Client::UpdateRelationshipCallback cb);

	void CancelGameFriendRequest(uint64_t userId, discordpp::Client::UpdateRelationshipCallback cb);

	discordpp::RelationshipHandle GetRelationshipHandle(uint64_t userId) const;

	std::vector<discordpp::RelationshipHandle> GetRelationships() const;

	void RejectDiscordFriendRequest(uint64_t userId,
			discordpp::Client::UpdateRelationshipCallback cb);

	void RejectGameFriendRequest(uint64_t userId, discordpp::Client::UpdateRelationshipCallback cb);

	void RemoveDiscordAndGameFriend(uint64_t userId,
			discordpp::Client::UpdateRelationshipCallback cb);

	void RemoveGameFriend(uint64_t userId, discordpp::Client::UpdateRelationshipCallback cb);

	std::vector<discordpp::UserHandle> SearchFriendsByUsername(std::string searchStr) const;

	void SendDiscordFriendRequest(std::string const &username,
			discordpp::Client::SendFriendRequestCallback cb);

	void SendDiscordFriendRequestById(uint64_t userId,
			discordpp::Client::UpdateRelationshipCallback cb);

	void SendGameFriendRequest(std::string const &username,
			discordpp::Client::SendFriendRequestCallback cb);

	void SendGameFriendRequestById(uint64_t userId,
			discordpp::Client::UpdateRelationshipCallback cb);

	void SetRelationshipCreatedCallback(discordpp::Client::RelationshipCreatedCallback cb);

	void SetRelationshipDeletedCallback(discordpp::Client::RelationshipDeletedCallback cb);

	void UnblockUser(uint64_t userId, discordpp::Client::UpdateRelationshipCallback cb);


	discordpp::UserHandle GetCurrentUser() const;

	void GetDiscordClientConnectedUser(
			uint64_t applicationId,
			discordpp::Client::GetDiscordClientConnectedUserCallback callback) const;

	std::optional<discordpp::UserHandle> GetUser(uint64_t userId) const;

	void SetUserUpdatedCallback(discordpp::Client::UserUpdatedCallback cb);
};

class CallInfoHandle {


	CallInfoHandle(const CallInfoHandle &other);

	void Drop();

	uint64_t ChannelId() const;

	std::vector<uint64_t> GetParticipants() const;

	std::optional<discordpp::VoiceStateHandle> GetVoiceStateHandle(uint64_t userId) const;

	uint64_t GuildId() const;
};
inline const char *EnumToString(discordpp::ActivityActionTypes value) {
	switch (value) {
		case discordpp::ActivityActionTypes::Join:
			return "Join";
		case discordpp::ActivityActionTypes::JoinRequest:
			return "JoinRequest";
		default:
			return "unknown";
	}
}
inline const char *EnumToString(discordpp::ActivityPartyPrivacy value) {
	switch (value) {
		case discordpp::ActivityPartyPrivacy::Private:
			return "Private";
		case discordpp::ActivityPartyPrivacy::Public:
			return "Public";
		default:
			return "unknown";
	}
}
inline const char *EnumToString(discordpp::ActivityTypes value) {
	switch (value) {
		case discordpp::ActivityTypes::Playing:
			return "Playing";
		case discordpp::ActivityTypes::Streaming:
			return "Streaming";
		case discordpp::ActivityTypes::Listening:
			return "Listening";
		case discordpp::ActivityTypes::Watching:
			return "Watching";
		case discordpp::ActivityTypes::CustomStatus:
			return "CustomStatus";
		case discordpp::ActivityTypes::Competing:
			return "Competing";
		case discordpp::ActivityTypes::HangStatus:
			return "HangStatus";
		default:
			return "unknown";
	}
}
inline const char *EnumToString(discordpp::ActivityGamePlatforms value) {
	switch (value) {
		case discordpp::ActivityGamePlatforms::Desktop:
			return "Desktop";
		case discordpp::ActivityGamePlatforms::Xbox:
			return "Xbox";
		case discordpp::ActivityGamePlatforms::Samsung:
			return "Samsung";
		case discordpp::ActivityGamePlatforms::IOS:
			return "IOS";
		case discordpp::ActivityGamePlatforms::Android:
			return "Android";
		case discordpp::ActivityGamePlatforms::Embedded:
			return "Embedded";
		case discordpp::ActivityGamePlatforms::PS4:
			return "PS4";
		case discordpp::ActivityGamePlatforms::PS5:
			return "PS5";
		default:
			return "unknown";
	}
}
inline const char *EnumToString(discordpp::ErrorType value) {
	switch (value) {
		case discordpp::ErrorType::None:
			return "None";
		case discordpp::ErrorType::NetworkError:
			return "NetworkError";
		case discordpp::ErrorType::HTTPError:
			return "HTTPError";
		case discordpp::ErrorType::ClientNotReady:
			return "ClientNotReady";
		case discordpp::ErrorType::Disabled:
			return "Disabled";
		case discordpp::ErrorType::ClientDestroyed:
			return "ClientDestroyed";
		case discordpp::ErrorType::ValidationError:
			return "ValidationError";
		case discordpp::ErrorType::Aborted:
			return "Aborted";
		case discordpp::ErrorType::AuthorizationFailed:
			return "AuthorizationFailed";
		case discordpp::ErrorType::RPCError:
			return "RPCError";
		default:
			return "unknown";
	}
}
inline const char *EnumToString(discordpp::HttpStatusCode value) {
	switch (value) {
		case discordpp::HttpStatusCode::None:
			return "None";
		case discordpp::HttpStatusCode::Continue:
			return "Continue";
		case discordpp::HttpStatusCode::SwitchingProtocols:
			return "SwitchingProtocols";
		case discordpp::HttpStatusCode::Processing:
			return "Processing";
		case discordpp::HttpStatusCode::EarlyHints:
			return "EarlyHints";
		case discordpp::HttpStatusCode::Ok:
			return "Ok";
		case discordpp::HttpStatusCode::Created:
			return "Created";
		case discordpp::HttpStatusCode::Accepted:
			return "Accepted";
		case discordpp::HttpStatusCode::NonAuthoritativeInfo:
			return "NonAuthoritativeInfo";
		case discordpp::HttpStatusCode::NoContent:
			return "NoContent";
		case discordpp::HttpStatusCode::ResetContent:
			return "ResetContent";
		case discordpp::HttpStatusCode::PartialContent:
			return "PartialContent";
		case discordpp::HttpStatusCode::MultiStatus:
			return "MultiStatus";
		case discordpp::HttpStatusCode::AlreadyReported:
			return "AlreadyReported";
		case discordpp::HttpStatusCode::ImUsed:
			return "ImUsed";
		case discordpp::HttpStatusCode::MultipleChoices:
			return "MultipleChoices";
		case discordpp::HttpStatusCode::MovedPermanently:
			return "MovedPermanently";
		case discordpp::HttpStatusCode::Found:
			return "Found";
		case discordpp::HttpStatusCode::SeeOther:
			return "SeeOther";
		case discordpp::HttpStatusCode::NotModified:
			return "NotModified";
		case discordpp::HttpStatusCode::TemporaryRedirect:
			return "TemporaryRedirect";
		case discordpp::HttpStatusCode::PermanentRedirect:
			return "PermanentRedirect";
		case discordpp::HttpStatusCode::BadRequest:
			return "BadRequest";
		case discordpp::HttpStatusCode::Unauthorized:
			return "Unauthorized";
		case discordpp::HttpStatusCode::PaymentRequired:
			return "PaymentRequired";
		case discordpp::HttpStatusCode::Forbidden:
			return "Forbidden";
		case discordpp::HttpStatusCode::NotFound:
			return "NotFound";
		case discordpp::HttpStatusCode::MethodNotAllowed:
			return "MethodNotAllowed";
		case discordpp::HttpStatusCode::NotAcceptable:
			return "NotAcceptable";
		case discordpp::HttpStatusCode::ProxyAuthRequired:
			return "ProxyAuthRequired";
		case discordpp::HttpStatusCode::RequestTimeout:
			return "RequestTimeout";
		case discordpp::HttpStatusCode::Conflict:
			return "Conflict";
		case discordpp::HttpStatusCode::Gone:
			return "Gone";
		case discordpp::HttpStatusCode::LengthRequired:
			return "LengthRequired";
		case discordpp::HttpStatusCode::PreconditionFailed:
			return "PreconditionFailed";
		case discordpp::HttpStatusCode::PayloadTooLarge:
			return "PayloadTooLarge";
		case discordpp::HttpStatusCode::UriTooLong:
			return "UriTooLong";
		case discordpp::HttpStatusCode::UnsupportedMediaType:
			return "UnsupportedMediaType";
		case discordpp::HttpStatusCode::RangeNotSatisfiable:
			return "RangeNotSatisfiable";
		case discordpp::HttpStatusCode::ExpectationFailed:
			return "ExpectationFailed";
		case discordpp::HttpStatusCode::MisdirectedRequest:
			return "MisdirectedRequest";
		case discordpp::HttpStatusCode::UnprocessableEntity:
			return "UnprocessableEntity";
		case discordpp::HttpStatusCode::Locked:
			return "Locked";
		case discordpp::HttpStatusCode::FailedDependency:
			return "FailedDependency";
		case discordpp::HttpStatusCode::TooEarly:
			return "TooEarly";
		case discordpp::HttpStatusCode::UpgradeRequired:
			return "UpgradeRequired";
		case discordpp::HttpStatusCode::PreconditionRequired:
			return "PreconditionRequired";
		case discordpp::HttpStatusCode::TooManyRequests:
			return "TooManyRequests";
		case discordpp::HttpStatusCode::RequestHeaderFieldsTooLarge:
			return "RequestHeaderFieldsTooLarge";
		case discordpp::HttpStatusCode::InternalServerError:
			return "InternalServerError";
		case discordpp::HttpStatusCode::NotImplemented:
			return "NotImplemented";
		case discordpp::HttpStatusCode::BadGateway:
			return "BadGateway";
		case discordpp::HttpStatusCode::ServiceUnavailable:
			return "ServiceUnavailable";
		case discordpp::HttpStatusCode::GatewayTimeout:
			return "GatewayTimeout";
		case discordpp::HttpStatusCode::HttpVersionNotSupported:
			return "HttpVersionNotSupported";
		case discordpp::HttpStatusCode::VariantAlsoNegotiates:
			return "VariantAlsoNegotiates";
		case discordpp::HttpStatusCode::InsufficientStorage:
			return "InsufficientStorage";
		case discordpp::HttpStatusCode::LoopDetected:
			return "LoopDetected";
		case discordpp::HttpStatusCode::NotExtended:
			return "NotExtended";
		case discordpp::HttpStatusCode::NetworkAuthorizationRequired:
			return "NetworkAuthorizationRequired";
		default:
			return "unknown";
	}
}
inline const char *EnumToString(discordpp::AuthenticationCodeChallengeMethod value) {
	switch (value) {
		case discordpp::AuthenticationCodeChallengeMethod::S256:
			return "S256";
		default:
			return "unknown";
	}
}
inline const char *EnumToString(discordpp::AdditionalContentType value) {
	switch (value) {
		case discordpp::AdditionalContentType::Other:
			return "Other";
		case discordpp::AdditionalContentType::Attachment:
			return "Attachment";
		case discordpp::AdditionalContentType::Poll:
			return "Poll";
		case discordpp::AdditionalContentType::VoiceMessage:
			return "VoiceMessage";
		case discordpp::AdditionalContentType::Thread:
			return "Thread";
		case discordpp::AdditionalContentType::Embed:
			return "Embed";
		case discordpp::AdditionalContentType::Sticker:
			return "Sticker";
		default:
			return "unknown";
	}
}
inline const char *EnumToString(discordpp::Call::Error value) {
	switch (value) {
		case discordpp::Call::Error::None:
			return "None";
		case discordpp::Call::Error::SignalingConnectionFailed:
			return "SignalingConnectionFailed";
		case discordpp::Call::Error::SignalingUnexpectedClose:
			return "SignalingUnexpectedClose";
		case discordpp::Call::Error::VoiceConnectionFailed:
			return "VoiceConnectionFailed";
		case discordpp::Call::Error::JoinTimeout:
			return "JoinTimeout";
		case discordpp::Call::Error::Forbidden:
			return "Forbidden";
		default:
			return "unknown";
	}
}
inline const char *EnumToString(discordpp::AudioModeType value) {
	switch (value) {
		case discordpp::AudioModeType::MODE_UNINIT:
			return "MODE_UNINIT";
		case discordpp::AudioModeType::MODE_VAD:
			return "MODE_VAD";
		case discordpp::AudioModeType::MODE_PTT:
			return "MODE_PTT";
		default:
			return "unknown";
	}
}
inline const char *EnumToString(discordpp::Call::Status value) {
	switch (value) {
		case discordpp::Call::Status::Disconnected:
			return "Disconnected";
		case discordpp::Call::Status::Joining:
			return "Joining";
		case discordpp::Call::Status::Connecting:
			return "Connecting";
		case discordpp::Call::Status::SignalingConnected:
			return "SignalingConnected";
		case discordpp::Call::Status::Connected:
			return "Connected";
		case discordpp::Call::Status::Reconnecting:
			return "Reconnecting";
		case discordpp::Call::Status::Disconnecting:
			return "Disconnecting";
		default:
			return "unknown";
	}
}
inline const char *EnumToString(discordpp::ChannelType value) {
	switch (value) {
		case discordpp::ChannelType::GuildText:
			return "GuildText";
		case discordpp::ChannelType::Dm:
			return "Dm";
		case discordpp::ChannelType::GuildVoice:
			return "GuildVoice";
		case discordpp::ChannelType::GroupDm:
			return "GroupDm";
		case discordpp::ChannelType::GuildCategory:
			return "GuildCategory";
		case discordpp::ChannelType::GuildNews:
			return "GuildNews";
		case discordpp::ChannelType::GuildStore:
			return "GuildStore";
		case discordpp::ChannelType::GuildNewsThread:
			return "GuildNewsThread";
		case discordpp::ChannelType::GuildPublicThread:
			return "GuildPublicThread";
		case discordpp::ChannelType::GuildPrivateThread:
			return "GuildPrivateThread";
		case discordpp::ChannelType::GuildStageVoice:
			return "GuildStageVoice";
		case discordpp::ChannelType::GuildDirectory:
			return "GuildDirectory";
		case discordpp::ChannelType::GuildForum:
			return "GuildForum";
		case discordpp::ChannelType::GuildMedia:
			return "GuildMedia";
		case discordpp::ChannelType::Lobby:
			return "Lobby";
		case discordpp::ChannelType::EphemeralDm:
			return "EphemeralDm";
		default:
			return "unknown";
	}
}
inline const char *EnumToString(discordpp::RelationshipType value) {
	switch (value) {
		case discordpp::RelationshipType::None:
			return "None";
		case discordpp::RelationshipType::Friend:
			return "Friend";
		case discordpp::RelationshipType::Blocked:
			return "Blocked";
		case discordpp::RelationshipType::PendingIncoming:
			return "PendingIncoming";
		case discordpp::RelationshipType::PendingOutgoing:
			return "PendingOutgoing";
		case discordpp::RelationshipType::Implicit:
			return "Implicit";
		case discordpp::RelationshipType::Suggestion:
			return "Suggestion";
		default:
			return "unknown";
	}
}
inline const char *EnumToString(discordpp::UserHandle::AvatarType value) {
	switch (value) {
		case discordpp::UserHandle::AvatarType::Gif:
			return "Gif";
		case discordpp::UserHandle::AvatarType::Webp:
			return "Webp";
		case discordpp::UserHandle::AvatarType::Png:
			return "Png";
		case discordpp::UserHandle::AvatarType::Jpeg:
			return "Jpeg";
		default:
			return "unknown";
	}
}
inline const char *EnumToString(discordpp::StatusType value) {
	switch (value) {
		case discordpp::StatusType::Online:
			return "Online";
		case discordpp::StatusType::Offline:
			return "Offline";
		case discordpp::StatusType::Blocked:
			return "Blocked";
		case discordpp::StatusType::Idle:
			return "Idle";
		case discordpp::StatusType::Dnd:
			return "Dnd";
		case discordpp::StatusType::Invisible:
			return "Invisible";
		case discordpp::StatusType::Streaming:
			return "Streaming";
		case discordpp::StatusType::Unknown:
			return "Unknown";
		default:
			return "unknown";
	}
}
inline const char *EnumToString(discordpp::DisclosureTypes value) {
	switch (value) {
		case discordpp::DisclosureTypes::MessageDataVisibleOnDiscord:
			return "MessageDataVisibleOnDiscord";
		default:
			return "unknown";
	}
}
inline const char *EnumToString(discordpp::Client::Error value) {
	switch (value) {
		case discordpp::Client::Error::None:
			return "None";
		case discordpp::Client::Error::ConnectionFailed:
			return "ConnectionFailed";
		case discordpp::Client::Error::UnexpectedClose:
			return "UnexpectedClose";
		case discordpp::Client::Error::ConnectionCanceled:
			return "ConnectionCanceled";
		default:
			return "unknown";
	}
}
inline const char *EnumToString(discordpp::Client::Status value) {
	switch (value) {
		case discordpp::Client::Status::Disconnected:
			return "Disconnected";
		case discordpp::Client::Status::Connecting:
			return "Connecting";
		case discordpp::Client::Status::Connected:
			return "Connected";
		case discordpp::Client::Status::Ready:
			return "Ready";
		case discordpp::Client::Status::Reconnecting:
			return "Reconnecting";
		case discordpp::Client::Status::Disconnecting:
			return "Disconnecting";
		case discordpp::Client::Status::HttpWait:
			return "HttpWait";
		default:
			return "unknown";
	}
}
inline const char *EnumToString(discordpp::Client::Thread value) {
	switch (value) {
		case discordpp::Client::Thread::Client:
			return "Client";
		case discordpp::Client::Thread::Voice:
			return "Voice";
		case discordpp::Client::Thread::Network:
			return "Network";
		default:
			return "unknown";
	}
}
inline const char *EnumToString(discordpp::AuthorizationTokenType value) {
	switch (value) {
		case discordpp::AuthorizationTokenType::User:
			return "User";
		case discordpp::AuthorizationTokenType::Bearer:
			return "Bearer";
		default:
			return "unknown";
	}
}
inline const char *EnumToString(discordpp::AuthenticationExternalAuthType value) {
	switch (value) {
		case discordpp::AuthenticationExternalAuthType::OIDC:
			return "OIDC";
		case discordpp::AuthenticationExternalAuthType::EpicOnlineServicesAccessToken:
			return "EpicOnlineServicesAccessToken";
		case discordpp::AuthenticationExternalAuthType::EpicOnlineServicesIdToken:
			return "EpicOnlineServicesIdToken";
		case discordpp::AuthenticationExternalAuthType::SteamSessionTicket:
			return "SteamSessionTicket";
		default:
			return "unknown";
	}
}
inline const char *EnumToString(discordpp::LoggingSeverity value) {
	switch (value) {
		case discordpp::LoggingSeverity::Verbose:
			return "Verbose";
		case discordpp::LoggingSeverity::Info:
			return "Info";
		case discordpp::LoggingSeverity::Warning:
			return "Warning";
		case discordpp::LoggingSeverity::Error:
			return "Error";
		case discordpp::LoggingSeverity::None:
			return "None";
		default:
			return "unknown";
	}
}