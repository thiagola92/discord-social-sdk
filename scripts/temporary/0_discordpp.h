
/// Represents the memory state of a Discord object.
enum class DiscordObjectState {
	/// The object has been freed
	Invalid,
	/// The object is owned by the C++ wrapper and methods can be called on it
	Owned,
};

/// Runs pending callbacks from the Discord SDK.
/// You should call this function periodically to process callbacks, e.g. once per frame.
inline void RunCallbacks() {
	Discord_RunCallbacks();
}

/// \brief ActivityActionTypes represents the type of invite being sent to a user.
/// There are essentially two types of invites:
/// 1: A user with an existing activity party can invite another user to join that existing party
/// 2: A user can request to join the existing activity party of another user
/// See https://discord.com/developers/docs/rich-presence/overview for more information.
enum class ActivityActionTypes {

	/// \brief Join
	Join = 1,

	/// \brief JoinRequest
	JoinRequest = 5,
};

/// \brief Allows your game to control the privacy of the party the user is in.
enum class ActivityPartyPrivacy {

	/// \brief The party is private (or unknown), which means that the user is in a party but it is
	/// not
	/// joinable without sending a request to join the party.
	/// This is the default value. You will also receive this value when receiving other users'
	/// activities as the party privacy for other users is not exposed.
	Private = 0,

	/// \brief The party is public, which means that the user is in a party which *could* be
	/// joinable by
	/// either friends or mutual voice participants without sending a request to join the party.
	/// This depends on a user's desired Discord account privacy settings.
	Public = 1,
};

/// \brief Discord RichPresence supports multiple types of activities that a user can be doing.
/// For the SDK, the only activity type that is really relevant is `Playing`.
/// The others are provided for completeness.
/// See https://discord.com/developers/docs/rich-presence/overview for more information.
enum class ActivityTypes {

	/// \brief Playing
	Playing = 0,

	/// \brief Streaming
	Streaming = 1,

	/// \brief Listening
	Listening = 2,

	/// \brief Watching
	Watching = 3,

	/// \brief CustomStatus
	CustomStatus = 4,

	/// \brief Competing
	Competing = 5,

	/// \brief HangStatus
	HangStatus = 6,
};

/// \brief Controls which Discord RichPresence field is displayed in the user's status.
/// See https://discord.com/developers/docs/rich-presence/overview for more information.
enum class StatusDisplayTypes {

	/// \brief Name
	Name = 0,

	/// \brief State
	State = 1,

	/// \brief Details
	Details = 2,
};

/// \brief Represents the type of platforms that an activity invite can be accepted on.
enum class ActivityGamePlatforms {

	/// \brief Desktop
	Desktop = 1,

	/// \brief Xbox
	Xbox = 2,

	/// \brief Samsung
	Samsung = 4,

	/// \brief IOS
	IOS = 8,

	/// \brief Android
	Android = 16,

	/// \brief Embedded
	Embedded = 32,

	/// \brief PS4
	PS4 = 64,

	/// \brief PS5
	PS5 = 128,
};

/// \brief Enum representing various types of errors the SDK returns.
enum class ErrorType {

	/// \brief No error, the operation was successful.
	None = 0,

	/// \brief The user is offline or there was some network issue that prevented an underlying
	/// HTTP call from succeeding.
	NetworkError = 1,

	/// \brief An HTTP call was made to Discord's servers but a non success HTTP status code was
	/// returned.
	/// In some cases this may be retryable, and if so ClientResult::Retryable will be true.
	/// In most cases though the failure is due to a validation or permissions error, and the
	/// request is not retryable. ClientResult::Error and ClientResult::ErrorCode will have more
	/// information.
	HTTPError = 2,

	/// \brief An operation such as sending a friend request or joining a lobby was attempted but
	/// the
	/// Client is not yet ready. Wait for Client::Status to change to Client::Status::Ready before
	/// trying again.
	/// Also be sure to call Client::Connect to begin the process of connecting to Discord's
	/// servers, otherwise
	/// the Client will never become ready.
	ClientNotReady = 3,

	/// \brief An operation was temporarily disabled for stability reasons.
	Disabled = 4,

	/// \brief The Client has been destroyed and so this operation cannot complete.
	ClientDestroyed = 5,

	/// \brief Used when an SDK method is called but the inputs don't pass local validation. For
	/// example
	/// if one attempts to accept a friend request when there is no pending friend request for that
	/// user,
	/// this ErrorType would be used.
	/// The specific validation error will be included in the `error` field, and no other
	/// ClientResult fields will be set.
	ValidationError = 6,

	/// \brief The user or developer aborted an operation, such as an authorization flow.
	Aborted = 7,

	/// \brief An authorization function failed, but not necessarily as the result of an HTTP call
	/// that
	/// returned an error.
	AuthorizationFailed = 8,

	/// \brief An RPC call was made to Discord's desktop application, but it returned a non-success
	/// result.
	/// The error and errorCode fields should both be set with more information.
	RPCError = 9,
};

/// \brief Enum that represents the various HTTP status codes that can be returned.
/// You can read more about these at: https://developer.mozilla.org/en-US/docs/Web/HTTP/Status
/// For convenience, we have defined a couple of enum values that are non-standard HTTP codes to
/// represent certain types of errors.
enum class HttpStatusCode {

	/// \brief None
	None = 0,

	/// \brief Continue
	Continue = 100,

	/// \brief SwitchingProtocols
	SwitchingProtocols = 101,

	/// \brief Processing
	Processing = 102,

	/// \brief EarlyHints
	EarlyHints = 103,

	/// \brief Ok
	Ok = 200,

	/// \brief Created
	Created = 201,

	/// \brief Accepted
	Accepted = 202,

	/// \brief NonAuthoritativeInfo
	NonAuthoritativeInfo = 203,

	/// \brief NoContent
	NoContent = 204,

	/// \brief ResetContent
	ResetContent = 205,

	/// \brief PartialContent
	PartialContent = 206,

	/// \brief MultiStatus
	MultiStatus = 207,

	/// \brief AlreadyReported
	AlreadyReported = 208,

	/// \brief ImUsed
	ImUsed = 209,

	/// \brief MultipleChoices
	MultipleChoices = 300,

	/// \brief MovedPermanently
	MovedPermanently = 301,

	/// \brief Found
	Found = 302,

	/// \brief SeeOther
	SeeOther = 303,

	/// \brief NotModified
	NotModified = 304,

	/// \brief TemporaryRedirect
	TemporaryRedirect = 307,

	/// \brief PermanentRedirect
	PermanentRedirect = 308,

	/// \brief BadRequest
	BadRequest = 400,

	/// \brief Unauthorized
	Unauthorized = 401,

	/// \brief PaymentRequired
	PaymentRequired = 402,

	/// \brief Forbidden
	Forbidden = 403,

	/// \brief NotFound
	NotFound = 404,

	/// \brief MethodNotAllowed
	MethodNotAllowed = 405,

	/// \brief NotAcceptable
	NotAcceptable = 406,

	/// \brief ProxyAuthRequired
	ProxyAuthRequired = 407,

	/// \brief RequestTimeout
	RequestTimeout = 408,

	/// \brief Conflict
	Conflict = 409,

	/// \brief Gone
	Gone = 410,

	/// \brief LengthRequired
	LengthRequired = 411,

	/// \brief PreconditionFailed
	PreconditionFailed = 412,

	/// \brief PayloadTooLarge
	PayloadTooLarge = 413,

	/// \brief UriTooLong
	UriTooLong = 414,

	/// \brief UnsupportedMediaType
	UnsupportedMediaType = 415,

	/// \brief RangeNotSatisfiable
	RangeNotSatisfiable = 416,

	/// \brief ExpectationFailed
	ExpectationFailed = 417,

	/// \brief MisdirectedRequest
	MisdirectedRequest = 421,

	/// \brief UnprocessableEntity
	UnprocessableEntity = 422,

	/// \brief Locked
	Locked = 423,

	/// \brief FailedDependency
	FailedDependency = 424,

	/// \brief TooEarly
	TooEarly = 425,

	/// \brief UpgradeRequired
	UpgradeRequired = 426,

	/// \brief PreconditionRequired
	PreconditionRequired = 428,

	/// \brief TooManyRequests
	TooManyRequests = 429,

	/// \brief RequestHeaderFieldsTooLarge
	RequestHeaderFieldsTooLarge = 431,

	/// \brief InternalServerError
	InternalServerError = 500,

	/// \brief NotImplemented
	NotImplemented = 501,

	/// \brief BadGateway
	BadGateway = 502,

	/// \brief ServiceUnavailable
	ServiceUnavailable = 503,

	/// \brief GatewayTimeout
	GatewayTimeout = 504,

	/// \brief HttpVersionNotSupported
	HttpVersionNotSupported = 505,

	/// \brief VariantAlsoNegotiates
	VariantAlsoNegotiates = 506,

	/// \brief InsufficientStorage
	InsufficientStorage = 507,

	/// \brief LoopDetected
	LoopDetected = 508,

	/// \brief NotExtended
	NotExtended = 510,

	/// \brief NetworkAuthorizationRequired
	NetworkAuthorizationRequired = 511,
};

/// \brief Represents the crypto method used to generate a code challenge.
/// The only method used by the SDK is sha256.
enum class AuthenticationCodeChallengeMethod {

	/// \brief S256
	S256 = 0,
};

/// \brief Represents the type of integration the app will be installed as.
enum class IntegrationType {

	/// \brief GuildInstall
	GuildInstall = 0,

	/// \brief UserInstall
	UserInstall = 1,
};

/// \brief Represents the type of additional content contained in a message.
enum class AdditionalContentType {

	/// \brief Other
	Other = 0,

	/// \brief Attachment
	Attachment = 1,

	/// \brief Poll
	Poll = 2,

	/// \brief VoiceMessage
	VoiceMessage = 3,

	/// \brief Thread
	Thread = 4,

	/// \brief Embed
	Embed = 5,

	/// \brief Sticker
	Sticker = 6,
};

/// \brief The Discord Voice audio system to use.
enum class AudioSystem {

	/// \brief Use the standard audio system.
	Standard = 0,

	/// \brief Use the game audio system.
	Game = 1,
};

/// \brief Represents whether a voice call is using push to talk or auto voice detection
enum class AudioModeType {

	/// \brief MODE_UNINIT
	MODE_UNINIT = 0,

	/// \brief MODE_VAD
	MODE_VAD = 1,

	/// \brief MODE_PTT
	MODE_PTT = 2,
};

/// \brief Enum that represents the various channel types on Discord.
/// For more information see: https://discord.com/developers/docs/resources/channel
enum class ChannelType {

	/// \brief GuildText
	GuildText = 0,

	/// \brief Dm
	Dm = 1,

	/// \brief GuildVoice
	GuildVoice = 2,

	/// \brief GroupDm
	GroupDm = 3,

	/// \brief GuildCategory
	GuildCategory = 4,

	/// \brief GuildNews
	GuildNews = 5,

	/// \brief GuildStore
	GuildStore = 6,

	/// \brief GuildNewsThread
	GuildNewsThread = 10,

	/// \brief GuildPublicThread
	GuildPublicThread = 11,

	/// \brief GuildPrivateThread
	GuildPrivateThread = 12,

	/// \brief GuildStageVoice
	GuildStageVoice = 13,

	/// \brief GuildDirectory
	GuildDirectory = 14,

	/// \brief GuildForum
	GuildForum = 15,

	/// \brief GuildMedia
	GuildMedia = 16,

	/// \brief Lobby
	Lobby = 17,

	/// \brief EphemeralDm
	EphemeralDm = 18,
};

/// \brief Enum that represents the possible types of relationships that can exist between two users
enum class RelationshipType {

	/// \brief The user has no relationship with the other user.
	None = 0,

	/// \brief The user is friends with the other user.
	Friend = 1,

	/// \brief The current user has blocked the target user, and so certain actions such as sending
	/// messages between these users will not work.
	Blocked = 2,

	/// \brief The current user has received a friend request from the target user, but it is not
	/// yet
	/// accepted.
	PendingIncoming = 3,

	/// \brief The current user has sent a friend request to the target user, but it is not yet
	/// accepted.
	PendingOutgoing = 4,

	/// \brief The Implicit type is documented for visibility, but should be unused in the SDK.
	Implicit = 5,

	/// \brief The Suggestion type is documented for visibility, but should be unused in the SDK.
	Suggestion = 6,
};

/// \brief Enum that specifies the various online statuses for a user.
/// Generally a user is online or offline, but in Discord users are able to further customize their
/// status such as turning on "Do not Disturb" mode or "Dnd" to silence notifications.
enum class StatusType {

	/// \brief The user is online and recently active.
	Online = 0,

	/// \brief The user is offline and not connected to Discord.
	Offline = 1,

	/// \brief Blocked
	Blocked = 2,

	/// \brief The user is online, but has not been active for a while and may be away from their
	/// computer.
	Idle = 3,

	/// \brief The user is online, but wishes to suppress notifications for the time being.
	Dnd = 4,

	/// \brief The user is online, but wishes to appear as if they are offline to other users.
	Invisible = 5,

	/// \brief The user is online and is actively streaming content.
	Streaming = 6,

	/// \brief Unknown
	Unknown = 7,
};

/// \brief Enum that represents various informational disclosures that Discord may make to users, so
/// that the game can identity them and customize their rendering as desired.
/// See MessageHandle for more details.
enum class DisclosureTypes {

	/// \brief This disclosure type happens the first time a user sends a message in game, and that
	/// message
	/// will be able to be viewed on Discord, so the user knows their content is being copied out of
	/// the game.
	MessageDataVisibleOnDiscord = 3,
};

/// \brief Represents the type of auth token used by the SDK, either the normal tokens produced by
/// the Discord desktop app, or an oauth2 bearer token. Only the latter can be used by the SDK.
enum class AuthorizationTokenType {

	/// \brief User
	User = 0,

	/// \brief Bearer
	Bearer = 1,
};

/// \brief Represents the various identity providers that can be used to authenticate a provisional
/// account user for public clients.
enum class AuthenticationExternalAuthType {

	/// \brief OIDC
	OIDC = 0,

	/// \brief EpicOnlineServicesAccessToken
	EpicOnlineServicesAccessToken = 1,

	/// \brief EpicOnlineServicesIdToken
	EpicOnlineServicesIdToken = 2,

	/// \brief SteamSessionTicket
	SteamSessionTicket = 3,

	/// \brief UnityServicesIdToken
	UnityServicesIdToken = 4,
};

/// \brief Enum that represents the various log levels supported by the SDK.
enum class LoggingSeverity {

	/// \brief Verbose
	Verbose = 1,

	/// \brief Info
	Info = 2,

	/// \brief Warning
	Warning = 3,

	/// \brief Error
	Error = 4,

	/// \brief None
	None = 5,
};

/// \brief Enum that represents the logical groups of relationships based on online status and game
/// activity
enum class RelationshipGroupType {

	/// \brief Users who are online and currently playing the game
	OnlinePlayingGame = 0,

	/// \brief Users who are online but not playing the game
	OnlineElsewhere = 1,

	/// \brief Users who are offline
	Offline = 2,
};

/// \brief When one user invites another to join their game on Discord, it will send a message to
/// that user. The SDK will parse those messages for you automatically, and this struct contains all
/// of the relevant invite information which is needed to later accept that invite.
class ActivityInvite {

	/// Copy constructor for ActivityInvite
	ActivityInvite(const ActivityInvite &rhs);

	explicit ActivityInvite();

	void Drop();

	/// \brief The user id of the user who sent the invite.
	uint64_t SenderId() const;
	/// Setter for ActivityInvite::SenderId.
	void SetSenderId(uint64_t SenderId);

	/// \brief The id of the Discord channel in which the invite was sent.
	uint64_t ChannelId() const;
	/// Setter for ActivityInvite::ChannelId.
	void SetChannelId(uint64_t ChannelId);

	/// \brief The id of the Discord message that contains the invite.
	uint64_t MessageId() const;
	/// Setter for ActivityInvite::MessageId.
	void SetMessageId(uint64_t MessageId);

	/// \brief The type of invite that was sent.
	discordpp::ActivityActionTypes Type() const;
	/// Setter for ActivityInvite::Type.
	void SetType(discordpp::ActivityActionTypes Type);

	/// \brief The target application of the invite.
	uint64_t ApplicationId() const;
	/// Setter for ActivityInvite::ApplicationId.
	void SetApplicationId(uint64_t ApplicationId);

	/// \brief The application id of the parent - this is only applicable if there is a parent
	/// for a publisher's suite of applications.
	uint64_t ParentApplicationId() const;
	/// Setter for ActivityInvite::ParentApplicationId.
	void SetParentApplicationId(uint64_t ParentApplicationId);

	/// \brief The id of the party the invite was sent for.
	std::string PartyId() const;
	/// Setter for ActivityInvite::PartyId.
	void SetPartyId(std::string PartyId);

	/// \brief The session id of the user who sent the invite.
	std::string SessionId() const;
	/// Setter for ActivityInvite::SessionId.
	void SetSessionId(std::string SessionId);

	/// \brief Whether or not this invite is currently joinable. An invite becomes invalid if it was
	/// sent more than 6 hours ago or if the sender is no longer playing the game the invite is for.
	bool IsValid() const;
	/// Setter for ActivityInvite::IsValid.
	void SetIsValid(bool IsValid);
};

/// \brief Struct which controls what your rich presence looks like in
/// the Discord client. If you don't specify any values, the icon
/// and name of your application will be used as defaults.
/// Image assets can be either the unique identifier for an image
/// you uploaded to your application via the `Rich Presence` page in
/// the Developer portal, or they can be an external image URL.
/// As an example, if I uploaded an asset and name it `goofy-icon`,
/// I could set either image field to the string `goofy-icon`. Alternatively,
/// if my icon was hosted at `http://my-site.com/goofy.jpg`, I could
/// pass that URL into either image field.
/// See https://discord.com/developers/docs/rich-presence/overview#adding-custom-art-assets
/// for more information on using custom art assets, as well as for visual
/// examples of what each field does.
class ActivityAssets {

	/// Copy constructor for ActivityAssets
	ActivityAssets(const ActivityAssets &arg0);

	explicit ActivityAssets();

	void Drop();

	/// \brief The primary image identifier or URL, rendered as a large square icon on a user's rich
	/// presence.
	/// If specified, must be a string between 1 and 300 characters.
	std::optional<std::string> LargeImage() const;
	/// Setter for ActivityAssets::LargeImage.
	void SetLargeImage(std::optional<std::string> LargeImage);

	/// \brief A tooltip string that is shown when the user hovers over the large image.
	/// If specified, must be a string between 2 and 128 characters.
	std::optional<std::string> LargeText() const;
	/// Setter for ActivityAssets::LargeText.
	void SetLargeText(std::optional<std::string> LargeText);

	/// \brief A URL that opens when the user clicks/taps the large image.
	/// If specified, must be a string between 1 and 256 characters.
	std::optional<std::string> LargeUrl() const;
	/// Setter for ActivityAssets::LargeUrl.
	void SetLargeUrl(std::optional<std::string> LargeUrl);

	/// \brief The secondary image, rendered as a small circle over the `largeImage`.
	/// If specified, must be a string between 1 and 300 characters.
	std::optional<std::string> SmallImage() const;
	/// Setter for ActivityAssets::SmallImage.
	void SetSmallImage(std::optional<std::string> SmallImage);

	/// \brief A tooltip string that is shown when the user hovers over the small image.
	/// If specified, must be a string between 2 and 128 characters.
	std::optional<std::string> SmallText() const;
	/// Setter for ActivityAssets::SmallText.
	void SetSmallText(std::optional<std::string> SmallText);

	/// \brief A URL that opens when the user clicks/taps the small image.
	/// If specified, must be a string between 1 and 256 characters.
	std::optional<std::string> SmallUrl() const;
	/// Setter for ActivityAssets::SmallUrl.
	void SetSmallUrl(std::optional<std::string> SmallUrl);
};

/// \brief \see Activity
class ActivityTimestamps {

	/// Copy constructor for ActivityTimestamps
	ActivityTimestamps(const ActivityTimestamps &arg0);

	explicit ActivityTimestamps();

	void Drop();

	/// \brief The time the activity started, in milliseconds since Unix epoch.
	/// The SDK will try to convert seconds to milliseconds if a small-ish value is passed in.
	/// If specified, the Discord client will render a count up timer showing how long the user has
	/// been playing this activity.
	uint64_t Start() const;
	/// Setter for ActivityTimestamps::Start.
	void SetStart(uint64_t Start);

	/// \brief The time the activity will end at, in milliseconds since Unix epoch.
	/// The SDK will try to convert seconds to milliseconds if a small-ish value is passed in.
	/// If specified, the Discord client will render a countdown timer showing how long until the
	/// activity ends.
	uint64_t End() const;
	/// Setter for ActivityTimestamps::End.
	void SetEnd(uint64_t End);
};

/// \brief \see Activity
class ActivityParty {

	/// Copy constructor for ActivityParty
	ActivityParty(const ActivityParty &arg0);

	explicit ActivityParty();

	void Drop();

	/// \brief Specifies the id of the party. "Party" is used colloquially to refer to a group of
	/// players in a shared context. This could be a lobby id, server id, team id, etc.
	/// All party members should specify a RichPresence update using
	/// the same party id so that the Discord client knows how to group them together. If specified,
	/// must be a string between 2 and 128 characters.
	std::string Id() const;
	/// Setter for ActivityParty::Id.
	void SetId(std::string Id);

	/// \brief The number of people currently in the party, must be at least 1.
	int32_t CurrentSize() const;
	/// Setter for ActivityParty::CurrentSize.
	void SetCurrentSize(int32_t CurrentSize);

	/// \brief The maximum number of people that can be in the party, must be at least 0. When 0,
	/// the UI will not display a maximum.
	int32_t MaxSize() const;
	/// Setter for ActivityParty::MaxSize.
	void SetMaxSize(int32_t MaxSize);

	/// \brief The privacy of the party.
	discordpp::ActivityPartyPrivacy Privacy() const;
	/// Setter for ActivityParty::Privacy.
	void SetPrivacy(discordpp::ActivityPartyPrivacy Privacy);
};

/// \brief \see Activity
class ActivitySecrets {

	/// Copy constructor for ActivitySecrets
	ActivitySecrets(const ActivitySecrets &arg0);

	explicit ActivitySecrets();

	void Drop();

	/// \brief A secret string that is shared with users who are accepted into the party so the game
	/// knows how to join the user to the party. For example you might specify an internal game
	/// server ID or a Discord lobby ID or secret. If specified, must be a string between 2 and 128
	/// characters.
	std::string Join() const;
	/// Setter for ActivitySecrets::Join.
	void SetJoin(std::string Join);
};

/// \brief \see Activity
class ActivityButton {

	/// Copy constructor for ActivityButton
	ActivityButton(const ActivityButton &arg0);

	explicit ActivityButton();

	void Drop();

	/// \brief The label of the button.
	std::string Label() const;
	/// Setter for ActivityButton::Label.
	void SetLabel(std::string Label);

	/// \brief The url of the button.
	std::string Url() const;
	/// Setter for ActivityButton::Url.
	void SetUrl(std::string Url);
};

/// \brief An Activity represents one "thing" a user is doing on Discord and is part of their rich
/// presence.
/// Additional information is located on the Discord Developer Portal:
/// - https://discord.com/developers/docs/rich-presence/overview
/// - https://discord.com/developers/docs/developer-tools/game-sdk#activities
/// - https://discord.com/developers/docs/rich-presence/best-practices
/// While RichPresence supports multiple types of activities, the only activity type that is really
/// relevant for the SDK is ActivityTypes::Playing. Additionally, the SDK will only expose
/// Activities that are associated with the current game (or application). So for example, a field
/// like `name` below, will always be set to the current game's name from the view of the SDK.
/// ## Customization
/// When an activity shows up on Discord, it will look something like this:
/// 1. Playing "game name"
/// 2. Capture the flag | 2 - 1
/// 3. In a group (2 of 3)
/// You can control how lines 2 and 3 are rendered in Discord, here's the breakdown:
/// - Line 1, `Playing "game name"` is powered by the name of your game (or application) on Discord.
/// - Line 2, `Capture the flag | 2 - 1` is powered by the `details` field in the activity, and this
/// should generally try to describe what the _player_ is currently doing. You can even include
/// dynamic data such as a match score here.
/// - Line 3, `In a group (2 of 3)` describes the _party_ the player is in. "Party" is used to refer
/// to a group of players in a shared context, such as a lobby, server, team, etc. The first half,
/// `In a group` is powered by the `state` field in the activity, and the second half, `(2 of 3)` is
/// powered by the `party` field in the activity and describes how many people are in the current
/// party and how big the party can get.
/// This diagram visually shows the field mapping:
/// \image html "rich_presence.png" "Rich presence field diagram" width=1070px
/// You can also specify up to two custom buttons to display on the rich presence.
/// These buttons will open the URL in the user's default browser.
/// \code
///     discordpp::ActivityButton button;
///     button.SetLabel("Button 1");
///     button.SetUrl("https://example.com");
///     activity.AddButton(button);
/// \endcode
/// ## Invites / Joinable Activities
/// Other users can be invited to join the current player's activity (or request to join it too),
/// but that does require certain fields to be set:
/// 1. ActivityParty must be set and have a non-empty ActivityParty::Id field. All users in the
/// party should set the same id field too!
/// 2. ActivityParty must specify the size of the group, and there must be room in the group for
/// another person to join.
/// 3. ActivitySecrets::Join must be set to a non-empty string. The join secret is only shared with
/// users who are accepted into the party by an existing member, so it is truly a secret. You can
/// use this so that when the user is accepted your game knows how to join them to the party. For
/// example it could be an internal game ID, or a Discord lobby ID/secret that the client could
/// join.
/// There is additional information about game invites here:
/// https://support.discord.com/hc/en-us/articles/115001557452-Game-Invites
/// ### Mobile Invites
/// Activity invites are handled via a deep link. To enable users to join your game via an invite in
/// the Discord client, you must do two things:
/// 1. Set your deep link URL in the Discord developer portal. This will be available on the General
/// tab of your application once Social Layer integration is enabled for your app.
/// 2. Set the desired supported platforms when reporting the activity info in your rich presence,
/// e.g.:
/// \code
///     activity.SetSupportedPlatforms(
///         ActivityGamePlatforms.Desktop |
///         ActivityGamePlatforms.IOS |
///         ActivityGamePlatforms.Android);
/// \endcode
/// When the user accepts the invite, the Discord client will open:
/// `[your url]/_discord/join?secret=[the join secret you set]`
/// ### Example Invites Flow
/// If you are using Discord lobbies for your game, a neat flow would look like this:
/// - When a user starts playing the game, they create a lobby with a random secret string, using
/// Client::CreateOrJoinLobby
/// - That user publishes their RichPresence with the join secret set to the lobby secret, along
/// with party size information
/// - Another use can then see that RichPresence on Discord and join off of it
/// - Once accepted the new user receives the join secret and their client can call
/// CreateOrJoinLobby(joinSecret) to join the lobby
/// - Finally the original user can notice that the lobby membership has changed and so they publish
/// a new RichPresence update containing the updating party size information.
/// ### Invites Code Example
/// \code
/// // User A
/// // 1. Create a lobby with secret
/// std::string lobbySecret = "foo";
/// client->CreateOrJoinLobby(lobbySecret, [=](discordpp::ClientResult result, uint64_t lobbyId) {
///     // 2. Update rich presence with join secret
///     discordpp::Activity activity{};
///     // set name, state, party size ...
///     discordpp::ActivitySecrets secrets{};
///     secrets.SetJoin(lobbySecret);
///     activity.SetSecrets(secrets);
///     client->UpdateRichPresence(std::move(activity), [](discordpp::ClientResult result) {});
/// });
/// // 3. Some time later, send an invite
/// client->SendActivityInvite(USER_B_ID, "come play with me", [](auto result) {});
/// // User B
/// // 4. Monitor for new invites. Alternatively, you can use
/// // Client::SetActivityInviteUpdatedCallback to get updates on existing invites.
/// client->SetActivityInviteCreatedCallback([client](auto invite) {
///     // 5. When an invite is received, ask the user if they want to accept it.
///     // If they choose to do so then go ahead and invoke AcceptActivityInvite
///     client->AcceptActivityInvite(invite,
///         [client](discordpp::ClientResult result, std::string secret) {
///         if (result.Successful()) {
///             // 5. Join the lobby using the joinSecret
///             client->CreateOrJoinLobby(secret, [](discordpp::ClientResult result, uint64_t
///             lobbyId) {
///                 // Successfully joined lobby!
///             });
///         }
///     });
/// });
/// \endcode
/// ### Join Requests Code Example
/// Users can also request to join each others parties. This code snippet shows how that flow might
/// look:
/// \code
/// // User A
/// // 1. Create a lobby with secret
/// std::string lobbySecret = "foo";
/// client->CreateOrJoinLobby(lobbySecret, [=](discordpp::ClientResult result, uint64_t lobbyId) {
///     // 2. Update rich presence with join secret
///     discordpp::Activity activity{};
///     // set name, state, party size ...
///     discordpp::ActivitySecrets secrets{};
///     secrets.SetJoin(lobbySecret);
///     activity.SetSecrets(secrets);
///     client->UpdateRichPresence(std::move(activity), [](discordpp::ClientResult result) {});
/// });
/// // User B
/// // 3. Request to join User A's party
/// client->SendActivityJoinRequest(USER_A_ID, [](auto result) {});
/// // User A
/// // Monitor for new invites:
/// client->SetActivityInviteCreatedCallback([client](auto invite) {
///     // 5. The game can now show that User A has received a request to join their party
///     // If User A is ok with that, they can reply back:
///     // Note: invite.type will be ActivityActionTypes::JoinRequest in this example
///     client->SendActivityJoinRequestReply(invite, [](auto result) {});
/// });
/// // User B
/// // 6. Same as before, user B can monitor for invites
/// client->SetActivityInviteCreatedCallback([client](auto invite) {
///     // 7. When an invite is received, ask the user if they want to accept it.
///     // If they choose to do so then go ahead and invoke AcceptActivityInvite
///     client->AcceptActivityInvite(invite,
///         [client](discordpp::ClientResult result, std::string secret) {
///         if (result.Successful()) {
///             // 5. Join the lobby using the joinSecret
///             client->CreateOrJoinLobby(secret, [](auto result, uint64_t lobbyId) {
///                 // Successfully joined lobby!
///             });
///         }
///     });
/// });
/// \endcode
class Activity {

	/// Copy constructor for Activity
	Activity(const Activity &arg0);

	explicit Activity();

	void Drop();

	/// \brief Adds a custom button to the rich presence
	void AddButton(discordpp::ActivityButton button);

	/// \brief Compares each field of the Activity struct for equality.
	bool Equals(discordpp::Activity other) const;

	/// \brief Returns the custom buttons for the rich presence
	std::vector<discordpp::ActivityButton> GetButtons() const;

	/// \brief The name of the game or application that the activity is associated with.
	/// This field cannot be set by the SDK, and will always be the name of the current game.
	std::string Name() const;
	/// Setter for Activity::Name.
	void SetName(std::string Name);

	/// \brief The type of activity this is.
	/// This should almost always be set to `Playing`
	discordpp::ActivityTypes Type() const;
	/// Setter for Activity::Type.
	void SetType(discordpp::ActivityTypes Type);

	/// \brief Controls which field is used for the user's status message
	/// See the docs on the Activity struct for more info.
	std::optional<discordpp::StatusDisplayTypes> StatusDisplayType() const;
	/// Setter for Activity::StatusDisplayType.
	void SetStatusDisplayType(std::optional<discordpp::StatusDisplayTypes> StatusDisplayType);

	/// \brief The state _of the party_ for this activity.
	/// See the docs on the Activity struct for more info.
	/// If specified, must be a string between 2 and 128 characters.
	std::optional<std::string> State() const;
	/// Setter for Activity::State.
	void SetState(std::optional<std::string> State);

	/// \brief A URL that opens when the user clicks/taps the state text.
	/// See the docs on the Activity struct for more info.
	/// If specified, must be a string between 2 and 256 characters.
	std::optional<std::string> StateUrl() const;
	/// Setter for Activity::StateUrl.
	void SetStateUrl(std::optional<std::string> StateUrl);

	/// \brief The state _of the what the user is doing_ for this activity.
	/// See the docs on the Activity struct for more info.
	/// If specified, must be a string between 2 and 128 characters.
	std::optional<std::string> Details() const;
	/// Setter for Activity::Details.
	void SetDetails(std::optional<std::string> Details);

	/// \brief A URL that opens when the user clicks/taps the details text.
	/// See the docs on the Activity struct for more info.
	/// If specified, must be a string between 2 and 256 characters.
	std::optional<std::string> DetailsUrl() const;
	/// Setter for Activity::DetailsUrl.
	void SetDetailsUrl(std::optional<std::string> DetailsUrl);

	/// \brief The application ID of the game that the activity is associated with.
	/// This field cannot be set by the SDK, and will always be the application ID of the current
	/// game or a game from the same publisher.
	std::optional<uint64_t> ApplicationId() const;
	/// Setter for Activity::ApplicationId.
	void SetApplicationId(std::optional<uint64_t> ApplicationId);

	/// \brief The application ID of the parent application that the activity is associated with if
	/// it exists. This is to help identify a collection of games that are from the same publisher.
	/// This field cannot be set by the SDK, and will always be the application ID of the game's
	/// parent or unset if the game has no parent.
	std::optional<uint64_t> ParentApplicationId() const;
	/// Setter for Activity::ParentApplicationId.
	void SetParentApplicationId(std::optional<uint64_t> ParentApplicationId);

	/// \brief Images used to customize how the Activity is displayed in the Discord client.
	std::optional<discordpp::ActivityAssets> Assets() const;
	/// Setter for Activity::Assets.
	void SetAssets(std::optional<discordpp::ActivityAssets> Assets);

	/// \brief The timestamps struct can be used to render either:
	/// - a "time remaining" countdown timer (by specifying the `end` value)
	/// - a "time elapsed" countup timer (by specifying the `start` value)
	std::optional<discordpp::ActivityTimestamps> Timestamps() const;
	/// Setter for Activity::Timestamps.
	void SetTimestamps(std::optional<discordpp::ActivityTimestamps> Timestamps);

	/// \brief The party struct is used to indicate the size and members of the people the current
	/// user is playing with.
	std::optional<discordpp::ActivityParty> Party() const;
	/// Setter for Activity::Party.
	void SetParty(std::optional<discordpp::ActivityParty> Party);

	/// \brief The secrets struct is used in combination with the party struct to make an Activity
	/// joinable.
	std::optional<discordpp::ActivitySecrets> Secrets() const;
	/// Setter for Activity::Secrets.
	void SetSecrets(std::optional<discordpp::ActivitySecrets> Secrets);

	/// \brief If an activity is joinable, but only on certain platforms, this field can be used to
	/// indicate which platforms the activity is joinable on. For example if a game is available on
	/// both PC and Mobile, but PC users cannot join Mobile users and vice versa, this field can be
	/// used so that an activity only shows as joinable on Discord if the user is on the appropriate
	/// platform.
	discordpp::ActivityGamePlatforms SupportedPlatforms() const;
	/// Setter for Activity::SupportedPlatforms.
	void SetSupportedPlatforms(discordpp::ActivityGamePlatforms SupportedPlatforms);
};

/// \brief Struct that stores information about the result of an SDK function call.
/// Functions can fail for a few reasons including:
/// - The Client is not yet ready and able to perform the action.
/// - The inputs passed to the function are invalid.
/// - The function makes an API call to Discord's backend which returns an error.
/// - The user is offline.
/// The ClientResult::Type field is used to to distinguish between the above types of failures
class ClientResult {

	/// Copy constructor for ClientResult
	ClientResult(const ClientResult &arg0);

	void Drop();

	/// \brief Returns the error message if any of the ClientResult.
	std::string ToString() const;

	/// \brief The type of error that occurred. See ErrorType for more information.
	discordpp::ErrorType Type() const;
	/// Setter for ClientResult::Type.
	void SetType(discordpp::ErrorType Type);

	/// \brief A description of the error that occurred.
	std::string Error() const;
	/// Setter for ClientResult::Error.
	void SetError(std::string Error);

	/// \brief A more detailed error code for this failure. Currently the only use of this is when
	/// an API request is made to Discord's backend and that fails with a specific error, that error
	/// will be included in this field.
	/// Many of these error codes are documented at:
	/// https://discord.com/developers/docs/topics/opcodes-and-status-codes#json
	/// This will only be set if the type of error is ErrorType::HTTPError
	int32_t ErrorCode() const;
	/// Setter for ClientResult::ErrorCode.
	void SetErrorCode(int32_t ErrorCode);

	/// \brief The HTTP status code of the API call.
	/// This will only be set if the type of error is ErrorType::HTTPError
	discordpp::HttpStatusCode Status() const;
	/// Setter for ClientResult::Status.
	void SetStatus(discordpp::HttpStatusCode Status);

	/// \brief The full HTTP response body, which will usually be a JSON string.
	/// The error format here is a bit more complicated because Discord's API tries to
	/// make it clear which field from the request is causing the error. Documentation on the format
	/// of these errors is here: https://discord.com/developers/docs/reference#error-messages
	/// This will only be set if the type of error is ErrorType::HTTPError
	std::string ResponseBody() const;
	/// Setter for ClientResult::ResponseBody.
	void SetResponseBody(std::string ResponseBody);

	/// \brief Equivalent to type == ErrorType::None
	bool Successful() const;
	/// Setter for ClientResult::Successful.
	void SetSuccessful(bool Successful);

	/// \brief Indicates if, although an API request failed, it is safe and recommended to retry it.
	bool Retryable() const;
	/// Setter for ClientResult::Retryable.
	void SetRetryable(bool Retryable);

	/// \brief When a user is being rate limited by Discord (and so status == 429), this field
	/// should be set and is the number of seconds to wait before trying again.
	float RetryAfter() const;
	/// Setter for ClientResult::RetryAfter.
	void SetRetryAfter(float RetryAfter);
};

/// \brief Struct that encapsulates the challenge part of the code verification flow.
class AuthorizationCodeChallenge {

	/// Copy constructor for AuthorizationCodeChallenge
	AuthorizationCodeChallenge(const AuthorizationCodeChallenge &arg0);

	explicit AuthorizationCodeChallenge();

	void Drop();

	/// \brief The method used to generate the challenge. The only method used by the SDK is sha256.
	discordpp::AuthenticationCodeChallengeMethod Method() const;
	/// Setter for AuthorizationCodeChallenge::Method.
	void SetMethod(discordpp::AuthenticationCodeChallengeMethod Method);

	/// \brief The challenge value
	std::string Challenge() const;
	/// Setter for AuthorizationCodeChallenge::Challenge.
	void SetChallenge(std::string Challenge);
};

/// \brief Struct that encapsulates both parts of the code verification flow.
class AuthorizationCodeVerifier {

	/// Copy constructor for AuthorizationCodeVerifier
	AuthorizationCodeVerifier(const AuthorizationCodeVerifier &arg0);

	void Drop();

	/// \brief The challenge part of the code verification flow.
	discordpp::AuthorizationCodeChallenge Challenge() const;
	/// Setter for AuthorizationCodeVerifier::Challenge.
	void SetChallenge(discordpp::AuthorizationCodeChallenge Challenge);

	/// \brief The verifier part of the code verification flow.
	std::string Verifier() const;
	/// Setter for AuthorizationCodeVerifier::Verifier.
	void SetVerifier(std::string Verifier);
};

/// \brief Arguments to the Client::Authorize function.
class AuthorizationArgs {

	/// Copy constructor for AuthorizationArgs
	AuthorizationArgs(const AuthorizationArgs &arg0);

	explicit AuthorizationArgs();

	void Drop();

	/// \brief Optional. The Discord application ID for your game. Defaults to the value set by
	/// Client::SetApplicationId.
	uint64_t ClientId() const;
	/// Setter for AuthorizationArgs::ClientId.
	void SetClientId(uint64_t ClientId);

	/// \brief Scopes is a space separated string of the oauth scopes your game is requesting.
	/// Most games should just pass in Client::GetDefaultCommunicationScopes or
	/// Client::GetDefaultPresenceScopes which will include these scopes, respectively:
	/// `openid sdk.social_layer` or `openid sdk.social_layer_presence`
	/// `sdk.social_layer` and `sdk.social_layer_presence` automatically expand to include all the
	/// necessary scopes for the integration.
	/// You can pass in additional scopes if you need to, but as a general rule you should only
	/// request the scopes you actually need, and the user will need to grant access to those
	/// additional scopes as well.
	std::string Scopes() const;
	/// Setter for AuthorizationArgs::Scopes.
	void SetScopes(std::string Scopes);

	/// \brief See https://discord.com/developers/docs/topics/oauth2#state-and-security for details
	/// on this field.
	/// We recommend leaving this unset, and the SDK will automatically generate a secure
	/// random value for you.
	std::optional<std::string> State() const;
	/// Setter for AuthorizationArgs::State.
	void SetState(std::optional<std::string> State);

	/// \brief The nonce field is generally only useful for backend integrations using ID tokens.
	/// For more information, see:
	/// https://openid.net/specs/openid-connect-core-1_0.html#rfc.section.2~nonce:~:text=auth_time%20response%20parameter.)-,nonce,-String%20value%20used
	std::optional<std::string> Nonce() const;
	/// Setter for AuthorizationArgs::Nonce.
	void SetNonce(std::optional<std::string> Nonce);

	/// \brief If using the Client::GetToken flow, you will need to generate a code challenge and
	/// verifier.
	/// Use Client::CreateAuthorizationCodeVerifier to generate these values and pass the challenge
	/// property here.
	std::optional<discordpp::AuthorizationCodeChallenge> CodeChallenge() const;
	/// Setter for AuthorizationArgs::CodeChallenge.
	void SetCodeChallenge(std::optional<discordpp::AuthorizationCodeChallenge> CodeChallenge);

	/// \brief The type of integration the app will be installed as.
	/// https://discord.com/developers/docs/resources/application#installation-context
	std::optional<discordpp::IntegrationType> IntegrationType() const;
	/// Setter for AuthorizationArgs::IntegrationType.
	void SetIntegrationType(std::optional<discordpp::IntegrationType> IntegrationType);

	/// \brief Custom URI scheme for mobile redirects.
	/// This allows games to specify a completely custom URI scheme for OAuth redirects.
	/// For example, setting this to "mygame" will result in a URI scheme like:
	/// mygame:/authorize/callback
	/// If not provided, defaults to the standard Discord format:
	/// discord-123456789:/authorize/callback
	/// This is particularly useful for distinguishing between multiple games from the same
	/// developer or for avoiding conflicts with other apps.
	std::optional<std::string> CustomSchemeParam() const;
	/// Setter for AuthorizationArgs::CustomSchemeParam.
	void SetCustomSchemeParam(std::optional<std::string> CustomSchemeParam);
};

/// \brief Arguments to the Client::GetTokenFromDevice function.
class DeviceAuthorizationArgs {

	/// Copy constructor for DeviceAuthorizationArgs
	DeviceAuthorizationArgs(const DeviceAuthorizationArgs &arg0);

	explicit DeviceAuthorizationArgs();

	void Drop();

	/// \brief Optional. The Discord application ID for your game. Defaults to the value set by
	/// Client::SetApplicationId.
	uint64_t ClientId() const;
	/// Setter for DeviceAuthorizationArgs::ClientId.
	void SetClientId(uint64_t ClientId);

	/// \brief Scopes is a space separated string of the oauth scopes your game is requesting.
	/// Most games should just pass in Client::GetDefaultCommunicationScopes or
	/// Client::GetDefaultPresenceScopes which will include these scopes, respectively:
	/// `openid sdk.social_layer` or `openid sdk.social_layer_presence`
	/// `sdk.social_layer` and `sdk.social_layer_presence` automatically expand to include all the
	/// necessary scopes for the integration.
	/// You can pass in additional scopes if you need to, but as a general rule you should only
	/// request the scopes you actually need, and the user will need to grant access to those
	/// additional scopes as well.
	std::string Scopes() const;
	/// Setter for DeviceAuthorizationArgs::Scopes.
	void SetScopes(std::string Scopes);
};

/// \brief A VoiceStateHandle represents the state of a single participant in a Discord voice call.
/// The main use case for VoiceStateHandle in the SDK is communicate whether a user has muted or
/// defeaned themselves.
/// Handle objects in the SDK hold a reference both to the underlying data, and to the SDK instance.
/// Changes to the underlying data will generally be available on existing handles objects without
/// having to re-create them. If the SDK instance is destroyed, but you still have a reference to a
/// handle object, note that it will return the default value for all method calls (ie an empty
/// string for methods that return a string).
class VoiceStateHandle {

	/// Copy constructor for VoiceStateHandle
	VoiceStateHandle(const VoiceStateHandle &other);

	void Drop();

	/// \brief Returns true if the given user has deafened themselves so that no one else in the
	/// call can hear them and so that they do not hear anyone else in the call either.
	bool SelfDeaf() const;

	/// \brief Returns true if the given user has muted themselves so that no one else in the call
	/// can hear them.
	bool SelfMute() const;
};

/// \brief Settings for the void auto detection threshold for picking up activity from a user's mic.
class VADThresholdSettings {

	VADThresholdSettings(const VADThresholdSettings &) = delete;

	void Drop();

	/// \brief The current void auto detection threshold value, has a range of -100, 0 and defaults
	/// to -60.
	float VadThreshold() const;
	/// Setter for VADThresholdSettings::VadThreshold.
	void SetVadThreshold(float VadThreshold);

	/// \brief Whether or not Discord is currently automatically setting and detecting the
	/// appropriate threshold to use.
	bool Automatic() const;
	/// Setter for VADThresholdSettings::Automatic.
	void SetAutomatic(bool Automatic);
};

/// \brief Class that manages an active voice session in a Lobby.
class Call {
	/// \brief Enum that represents any network errors with the Call.
	enum class Error {

		/// \brief None
		None = 0,

		/// \brief SignalingConnectionFailed
		SignalingConnectionFailed = 1,

		/// \brief SignalingUnexpectedClose
		SignalingUnexpectedClose = 2,

		/// \brief VoiceConnectionFailed
		VoiceConnectionFailed = 3,

		/// \brief JoinTimeout
		JoinTimeout = 4,

		/// \brief Forbidden
		Forbidden = 5,
	};

	/// \brief Enum that respresents the state of the Call's network connection.
	enum class Status {

		/// \brief Disconnected
		Disconnected = 0,

		/// \brief Joining
		Joining = 1,

		/// \brief Connecting
		Connecting = 2,

		/// \brief SignalingConnected
		SignalingConnected = 3,

		/// \brief Connected
		Connected = 4,

		/// \brief Reconnecting
		Reconnecting = 5,

		/// \brief Disconnecting
		Disconnecting = 6,
	};

	/// \brief Callback function for Call::SetOnVoiceStateChangedCallback.
	using OnVoiceStateChanged = std::function<void(uint64_t userId)>;

	/// \brief Callback function for Call::SetParticipantChangedCallback.
	using OnParticipantChanged = std::function<void(uint64_t userId, bool added)>;

	/// \brief Callback function for Call::SetSpeakingStatusChangedCallback.
	using OnSpeakingStatusChanged = std::function<void(uint64_t userId, bool isPlayingSound)>;

	/// \brief Callback function for Call::SetStatusChangedCallback.
	using OnStatusChanged = std::function<
			void(discordpp::Call::Status status, discordpp::Call::Error error, int32_t errorDetail)>;

	/// Copy constructor for Call
	Call(const Call &other);

	void Drop();

	/// \brief Converts the Error enum to a string.
	static std::string ErrorToString(discordpp::Call::Error type);

	/// \brief Returns whether the call is configured to use voice auto detection or push to talk
	/// for the current user.
	discordpp::AudioModeType GetAudioMode();

	/// \brief Returns the ID of the lobby with which this call is associated.
	uint64_t GetChannelId() const;

	/// \brief Returns the ID of the lobby with which this call is associated.
	uint64_t GetGuildId() const;

	/// \brief Returns whether the current user has locally muted the given userId for themselves.
	bool GetLocalMute(uint64_t userId);

	/// \brief Returns a list of all of the user IDs of the participants in the call.
	std::vector<uint64_t> GetParticipants() const;

	/// \brief Returns the locally set playout volume of the given userId.
	/// Does not affect the volume of this user for any other connected clients. The range of volume
	/// is [0, 200], where 100 indicate default audio volume of the playback device.
	float GetParticipantVolume(uint64_t userId);

	/// \brief Returns whether push to talk is currently active, meaning the user is currently
	/// pressing their configured push to talk key.
	bool GetPTTActive();

	/// \brief Returns the time that PTT is active after the user releases the PTT key and
	/// SetPTTActive(false) is called.
	uint32_t GetPTTReleaseDelay();

	/// \brief Returns whether the current user is deafened.
	bool GetSelfDeaf();

	/// \brief Returns whether the current user's microphone is muted.
	bool GetSelfMute();

	/// \brief Returns the current call status.
	/// A call is not ready to be used until the status changes to "Connected".
	discordpp::Call::Status GetStatus() const;

	/// \brief Returns the current configuration for void auto detection thresholds. See the
	/// description of the VADThreshold struct for specifics.
	discordpp::VADThresholdSettings GetVADThreshold() const;

	/// \brief Returns a reference to the VoiceStateHandle for the user ID of the given call
	/// participant.
	/// The VoiceStateHandle allows other users to know if the target user has muted or deafened
	/// themselves.
	std::optional<discordpp::VoiceStateHandle> GetVoiceStateHandle(uint64_t userId) const;

	/// \brief Sets whether to use voice auto detection or push to talk for the current user on this
	/// call.
	/// If using push to talk you should call SetPTTActive() whenever the user presses their
	/// confused push to talk key.
	void SetAudioMode(discordpp::AudioModeType audioMode);

	/// \brief Locally mutes the given userId, so that the current user cannot hear them anymore.
	/// Does not affect whether the given user is muted for any other connected clients.
	void SetLocalMute(uint64_t userId, bool mute);

	/// \brief Sets a callback function to generally be invoked whenever a field on a
	/// VoiceStateHandle object for a user would have changed.
	/// For example when a user mutes themselves, all other connected clients will invoke the
	/// VoiceStateChanged callback, because the "self mute" field will be true now. The callback is
	/// generally not invoked when users join or leave channels.
	void SetOnVoiceStateChangedCallback(discordpp::Call::OnVoiceStateChanged cb);

	/// \brief Sets a callback function to be invoked whenever some joins or leaves a voice call.
	void SetParticipantChangedCallback(discordpp::Call::OnParticipantChanged cb);

	/// \brief Locally changes the playout volume of the given userId.
	/// Does not affect the volume of this user for any other connected clients. The range of volume
	/// is [0, 200], where 100 indicate default audio volume of the playback device.
	void SetParticipantVolume(uint64_t userId, float volume);

	/// \brief When push to talk is enabled, this should be called whenever the user pushes or
	/// releases their configured push to talk key. This key must be configured in the game, the SDK
	/// does not handle keybinds itself.
	void SetPTTActive(bool active);

	/// \brief If set, extends the time that PTT is active after the user releases the PTT key and
	/// SetPTTActive(false) is called.
	/// Defaults to no release delay, but we recommend setting to 20ms, which is what Discord uses.
	void SetPTTReleaseDelay(uint32_t releaseDelayMs);

	/// \brief Mutes all audio from the currently active call for the current user.
	/// They will not be able to hear any other participants,
	/// and no other participants will be able to hear the current user either.
	void SetSelfDeaf(bool deaf);

	/// \brief Mutes the current user's microphone so that no other participant in their active
	/// calls can hear them.
	void SetSelfMute(bool mute);

	/// \brief Sets a callback function to be invoked whenever a user starts or stops speaking and
	/// is passed in the userId and whether they are currently speaking.
	/// It can be invoked in other cases as well, such as if the priority speaker changes or if the
	/// user plays a soundboard sound.
	void SetSpeakingStatusChangedCallback(discordpp::Call::OnSpeakingStatusChanged cb);

	/// \brief Sets a callback function to be invoked when the call status changes, such as when it
	/// fully connects or starts reconnecting.
	void SetStatusChangedCallback(discordpp::Call::OnStatusChanged cb);

	/// \brief Customizes the void auto detection thresholds for picking up activity from a user's
	/// mic.
	/// - When automatic is set to True, Discord will automatically detect the appropriate threshold
	/// to use.
	/// - When automatic is set to False, the given threshold value will be used. Threshold has a
	/// range of -100, 0, and defaults to -60.
	void SetVADThreshold(bool automatic, float threshold);

	/// \brief Converts the Status enum to a string.
	static std::string StatusToString(discordpp::Call::Status type);
};

/// \brief All messages sent on Discord are done so in a Channel. MessageHandle::ChannelId will
/// contain the ID of the channel a message was sent in, and Client::GetChannelHandle will return an
/// instance of this class.
/// Handle objects in the SDK hold a reference both to the underlying data, and to the SDK instance.
/// Changes to the underlying data will generally be available on existing handles objects without
/// having to re-create them. If the SDK instance is destroyed, but you still have a reference to a
/// handle object, note that it will return the default value for all method calls (ie an empty
/// string for methods that return a string).
class ChannelHandle {

	/// Copy constructor for ChannelHandle
	ChannelHandle(const ChannelHandle &other);

	void Drop();

	/// \brief Returns the ID of the channel.
	uint64_t Id() const;

	/// \brief Returns the name of the channel.
	/// Generally only channels in servers have names, although Discord may generate a display name
	/// for some channels as well.
	std::string Name() const;

	/// \brief For DMs and GroupDMs, returns the user IDs of the members of the channel.
	/// For all other channels returns an empty list.
	std::vector<uint64_t> Recipients() const;

	/// \brief Returns the type of the channel.
	discordpp::ChannelType Type() const;
};

/// \brief Represents a guild (also knowns as a Discord server), that the current user is a member
/// of, that contains channels that can be linked to a lobby.
class GuildMinimal {

	/// Copy constructor for GuildMinimal
	GuildMinimal(const GuildMinimal &arg0);

	void Drop();

	/// \brief The id of the guild.
	uint64_t Id() const;
	/// Setter for GuildMinimal::Id.
	void SetId(uint64_t Id);

	/// \brief The name of the guild.
	std::string Name() const;
	/// Setter for GuildMinimal::Name.
	void SetName(std::string Name);
};

/// \brief Represents a channel in a guild that the current user is a member of and may be able to
/// be linked to a lobby.
class GuildChannel {

	/// Copy constructor for GuildChannel
	GuildChannel(const GuildChannel &arg0);

	void Drop();

	/// \brief The id of the channel.
	uint64_t Id() const;
	/// Setter for GuildChannel::Id.
	void SetId(uint64_t Id);

	/// \brief The name of the channel.
	std::string Name() const;
	/// Setter for GuildChannel::Name.
	void SetName(std::string Name);

	/// \brief Whether the current user is able to link this channel to a lobby.
	/// For this to be true:
	/// - The channel must be a guild text channel
	/// - The channel may not be marked as NSFW
	/// - The channel must not be currently linked to a different lobby
	/// - The user must have the following permissions in the channel in order to link it:
	///   - Manage Channels
	///   - View Channel
	///   - Send Messages
	bool IsLinkable() const;
	/// Setter for GuildChannel::IsLinkable.
	void SetIsLinkable(bool IsLinkable);

	/// \brief Whether the channel is "fully public" which means every member of the guild is able
	/// to view and send messages in that channel.
	/// Discord allows lobbies to be linked to private channels
	/// in a server, which enables things like a private admin chat.
	/// However there is no permission synchronization between the game and Discord, so it is the
	/// responsibility of the game to restrict access to the lobby. Every member of the lobby will
	/// be able to view and send messages in the lobby/channel, regardless of whether that user
	/// would have permission to do so in Discord.
	/// This may be more complexity than a game wants to take on, so instead you can only allow
	/// linking of channels that are fully public in the server so there is no confusion.
	bool IsViewableAndWriteableByAllMembers() const;
	/// Setter for GuildChannel::IsViewableAndWriteableByAllMembers.
	void SetIsViewableAndWriteableByAllMembers(bool IsViewableAndWriteableByAllMembers);

	/// \brief Information about the currently linked lobby, if any.
	/// Currently Discord enforces that a channel can only be linked to a single lobby.
	std::optional<discordpp::LinkedLobby> LinkedLobby() const;
	/// Setter for GuildChannel::LinkedLobby.
	void SetLinkedLobby(std::optional<discordpp::LinkedLobby> LinkedLobby);
};

/// \brief Struct that stores information about the lobby linked to a channel.
class LinkedLobby {

	/// Copy constructor for LinkedLobby
	LinkedLobby(const LinkedLobby &arg0);

	explicit LinkedLobby();

	void Drop();

	/// \brief The ID of the application that owns the lobby.
	uint64_t ApplicationId() const;
	/// Setter for LinkedLobby::ApplicationId.
	void SetApplicationId(uint64_t ApplicationId);

	/// \brief The ID of the lobby.
	uint64_t LobbyId() const;
	/// Setter for LinkedLobby::LobbyId.
	void SetLobbyId(uint64_t LobbyId);
};

/// \brief Struct that stores information about the channel that a lobby is linked to.
class LinkedChannel {

	/// Copy constructor for LinkedChannel
	LinkedChannel(const LinkedChannel &arg0);

	void Drop();

	/// \brief The id of the linked channel.
	uint64_t Id() const;
	/// Setter for LinkedChannel::Id.
	void SetId(uint64_t Id);

	/// \brief The name of the linked channel.
	std::string Name() const;
	/// Setter for LinkedChannel::Name.
	void SetName(std::string Name);

	/// \brief The id of the guild (aka server) that owns the linked channel.
	uint64_t GuildId() const;
	/// Setter for LinkedChannel::GuildId.
	void SetGuildId(uint64_t GuildId);
};

/// \brief A RelationshipHandle represents the relationship between the current user and a target
/// user on Discord. Relationships include friends, blocked users, and friend invites.
/// The SDK supports two types of relationships:
/// - Discord: These are relationships that persist across games and on the Discord client.
/// Both users will be able to see whether each other is online regardless of whether they are in
/// the same game or not.
/// - Game: These are per-game relationships and do not carry over to other games. The two users
/// will only be able to see if the other is online if they are playing a game in which they are
/// friends.
/// If someone is a game friend they can later choose to "upgrade" to a full Discord friend. In this
/// case, the user has two relationships at the same time, which is why there are two different type
/// fields on RelationshipHandle. In this example, their RelationshipHandle::DiscordRelationshipType
/// would be set to RelationshipType::PendingIncoming or RelationshipType::PendingOutgoing (based on
/// whether they are receiving or sending the invite respectively), and their
/// RelationshipHandle::GameRelationshipType would remain as RelationshipType::Friend.
/// When a user blocks another user, it is always stored on the
/// RelationshipHandle::DiscordRelationshipType field, and will persist across games. It is not
/// possible to block a user in only one game.
/// See the @ref friends documentation for more information.
/// Note: While the SDK allows you to manage a user's relationships, you should never take an action
/// without their explicit consent. You should not automatically send or accept friend requests.
/// Only invoke APIs to manage relationships in response to a user action such as clicking a "Send
/// Friend Request" button.
/// Handle objects in the SDK hold a reference both to the underlying data, and to the SDK instance.
/// Changes to the underlying data will generally be available on existing handles objects without
/// having to re-create them. If the SDK instance is destroyed, but you still have a reference to a
/// handle object, note that it will return the default value for all method calls (ie an empty
/// string for methods that return a string).
class RelationshipHandle {

	/// Copy constructor for RelationshipHandle
	RelationshipHandle(const RelationshipHandle &other);

	void Drop();

	/// \brief Returns the type of the Discord relationship.
	discordpp::RelationshipType DiscordRelationshipType() const;

	/// \brief Returns the type of the Game relationship.
	discordpp::RelationshipType GameRelationshipType() const;

	/// \brief Returns the ID of the target user in this relationship.
	uint64_t Id() const;

	/// \brief Returns whether this relationship is a spam request.
	bool IsSpamRequest() const;

	/// \brief Returns a handle to the target user in this relationship, if one is available.
	/// This would be the user with the same ID as the one returned by the Id() method.
	std::optional<discordpp::UserHandle> User() const;
};

/// \brief A UserHandle represents a single user on Discord that the SDK knows about and contains
/// basic account information for them such as id, name, and avatar, as well as their "status"
/// information which includes both whether they are online/offline/etc as well as whether they are
/// playing this game.
/// Handle objects in the SDK hold a reference both to the underlying data, and to the SDK instance.
/// Changes to the underlying data will generally be available on existing handles objects without
/// having to re-create them. If the SDK instance is destroyed, but you still have a reference to a
/// handle object, note that it will return the default value for all method calls (ie an empty
/// string for methods that return a string).
class UserHandle {
	/// \brief The desired type of avatar url to generate for a User.
	enum class AvatarType {

		/// \brief Gif
		Gif = 0,

		/// \brief Webp
		Webp = 1,

		/// \brief Png
		Png = 2,

		/// \brief Jpeg
		Jpeg = 3,
	};

	/// Copy constructor for UserHandle
	UserHandle(const UserHandle &arg0);

	void Drop();

	/// \brief Returns the hash of the user's Discord profile avatar, if one is set.
	std::optional<std::string> Avatar() const;

	/// \brief Converts the AvatarType enum to a string.
	static std::string AvatarTypeToString(discordpp::UserHandle::AvatarType type);

	/// \brief Returns a CDN url to the user's Discord profile avatar.
	/// If the user does not have an avatar set, a url to one of Discord's default avatars is
	/// returned instead.
	std::string AvatarUrl(discordpp::UserHandle::AvatarType animatedType,
			discordpp::UserHandle::AvatarType staticType) const;

	/// \brief Returns the user's preferred name, if one is set, otherwise returns their unique
	/// username.
	std::string DisplayName() const;

	/// \brief Returns the user's rich presence activity that is associated with the current game,
	/// if one is set.
	/// On Discord, users can have multiple rich presence activities at once, but the SDK will only
	/// expose the activity that is associated with your game. You can use this to know about the
	/// party the user is in, if any, and what the user is doing in the game.
	/// For more information see the Activity class and check out
	/// https://discord.com/developers/docs/rich-presence/overview
	std::optional<discordpp::Activity> GameActivity() const;

	/// \brief Returns the preferred display name of this user, if one is set.
	/// Discord's public API refers to this as a "global name" instead of "display name".
	/// Discord users can set their preferred name to almost any string.
	/// For more information about usernames on Discord, see:
	/// https://discord.com/developers/docs/resources/user
	std::optional<std::string> GlobalName() const;

	/// \brief Returns the ID of this user.
	/// If this returns 0 then the UserHandle is no longer valid.
	uint64_t Id() const;

	/// \brief Returns true if this user is a provisional account.
	bool IsProvisional() const;

	/// \brief Returns a reference to the RelationshipHandle between the currently authenticated
	/// user and this user, if any.
	discordpp::RelationshipHandle Relationship() const;

	/// \brief Returns the user's online/offline/idle status.
	discordpp::StatusType Status() const;

	/// \brief Returns the globally unique username of this user.
	/// For provisional accounts this is an auto-generated string.
	/// For more information about usernames on Discord, see:
	/// https://discord.com/developers/docs/resources/user
	std::string Username() const;
};

/// \brief A LobbyMemberHandle represents the state of a single user in a Lobby.
/// The SDK separates lobby membership into two concepts:
/// 1. Has the user been added to the lobby by the game developer?
/// If the LobbyMemberHandle exists for a user/lobby pair, then the user has been added to the
/// lobby.
/// 2. Does the user have an active game session that is connected to the lobby and will receive any
/// lobby messages? It is possible for a game developer to add a user to a lobby while they are
/// offline. Also users may temporarily disconnect and rejoin later. So the `Connected` boolean
/// tells you whether the user is actively connected to the lobby.
/// Handle objects in the SDK hold a reference both to the underlying data, and to the SDK instance.
/// Changes to the underlying data will generally be available on existing handles objects without
/// having to re-create them. If the SDK instance is destroyed, but you still have a reference to a
/// handle object, note that it will return the default value for all method calls (ie an empty
/// string for methods that return a string).
class LobbyMemberHandle {

	/// Copy constructor for LobbyMemberHandle
	LobbyMemberHandle(const LobbyMemberHandle &other);

	void Drop();

	/// \brief Returns true if the user is allowed to link a channel to this lobby.
	/// Under the hood this checks if the LobbyMemberFlags::CanLinkLobby flag is set.
	/// This flag can only be set via the server API, add_lobby_member
	/// The use case for this is for games that want to restrict a lobby so that only the
	/// clan/guild/group leader is allowed to manage the linked channel for the lobby.
	bool CanLinkLobby() const;

	/// \brief Returns true if the user is currently connected to the lobby.
	bool Connected() const;

	/// \brief The user id of the lobby member.
	uint64_t Id() const;

	/// \brief Metadata is a set of string key/value pairs that the game developer can use.
	/// A common use case may be to store the game's internal user ID for this user so that every
	/// member of a lobby knows the discord user ID and the game's internal user ID mapping for each
	/// user.
	std::unordered_map<std::string, std::string> Metadata() const;

	/// \brief The UserHandle of the lobby member.
	std::optional<discordpp::UserHandle> User() const;
};

/// \brief A LobbyHandle represents a single lobby in the SDK. A lobby can be thought of as
/// just an arbitrary, developer-controlled group of users that can communicate with each other.
/// ## Managing Lobbies
/// Lobbies can be managed through a set of @ref server_apis that are documented elsewhere, which
/// allow you to create lobbies, add and remove users from lobbies, and delete them.
/// There is also an API to create lobbies without any server side component using the
/// Client::CreateOrJoinLobby function, which accepts a game-generated secret and will join the user
/// to the lobby associated with that secret, creating it if necessary.
/// NOTE: When using this API the secret will auto-expire in 30 days, at which point the existing
/// lobby can no longer be joined, but will still exist. We recommend using this for short term
/// lobbies and not permanent lobbies. Use the Server API for more permanent lobbies.
/// Members of a lobby are not automatically removed when they close the game or temporarily
/// disconnect. When the SDK connects, it will attempt to re-connect to any lobbies it is currently
/// a member of.
/// # Lobby Auto-Deletion
/// Lobbies are generally ephemeral and will be auto-deleted if they have been idle (meaning no
/// users are actively connected to them) for some amount of time. The default is to auto delete
/// after 5 minutes, but this can be customized when creating the lobby. As long as one user is
/// connected to the lobby though it will not be auto-deleted (meaning they have the SDK running and
/// status is set to Ready). Additionally, lobbies that are linked to a channel on Discord will not
/// be auto deleted.
/// You can also use the @ref server_apis to customize this timeout, it can be raised to as high as
/// 7 days, meaning the lobby only gets deleted if no one connects to it for an entire week. This
/// should give a good amount of permanence to lobbies when needed, but there may be rare cases
/// where a lobby does need to be "rebuilt" if everyone is offline for an extended period.
/// # Membership Limits
/// Lobbies may have a maximum of 1,000 members, and each user may be in a maximum of 200 lobbies
/// per game.
/// ## Audio
/// Lobbies support voice calls. Although a lobby is allowed to have 1,000 members, you should not
/// try to start voice calls in lobbies that large. We strongly recommend sticking to around 25
/// members or fewer for voice calls.
/// See Client::StartCall for more information on how to start a voice call in a lobby.
/// ## Channel Linking
/// Lobbies can be linked to a channel on Discord, which allows messages sent in one place to show
/// up in the other. Any lobby can be linked to a channel, but only lobby members with the
/// LobbyMemberFlags::CanLinkLobby flag are allowed to a link a lobby. This flag must be set using
/// the server APIs, which allows you to ensure that only clan/guild/group leaders can link lobbies
/// to Discord channels.
/// To setup a link you'll need to use methods in the Client class to fetch the servers (aka guilds)
/// and channels a user is a member of and setup the link. The Client::GetUserGuilds and
/// Client::GetGuildChannels methods are used to fetch the servers and channels respectively. You
/// can use these to show a UI for the user to pick which server and channel they want to link to.
/// Not all channels are linkable. To be linked:
/// - The channel must be a guild text channel
/// - The channel may not be marked as NSFW
/// - The channel must not be currently linked to a different lobby
/// - The user must have the following permissions in the channel in order to link it:
///   - Manage Channels
///   - View Channel
///   - Send Messages
/// ### Linking Private Channels
/// Discord is allowing all channels the user has access to in a server to be linked in game, even
/// if that channel is private to other members of the server. This means that a user could choose
/// to link a private "admins chat" channel (assuming they are an admin) in game if they wanted.
/// It's not really possible for the game to know which users should have access to that channel or
/// not though. So in this implementation, every member of a lobby will be able to view all messages
/// sent in the linked channel and reply to them. If you are going to allow private channels to be
/// linked in game, you must make sure that users are aware that their private channel will be
/// viewable by everyone in the lobby!
/// To help you identify which channels are public or private, we have added a
/// isViewableAndWriteableByAllMembers boolean which is described more in GuildChannel. You can use
/// that to just not allow private channels to be linked, or to know when to show a clear warning,
/// it's up to you!
/// ## Misc
/// Handle objects in the SDK hold a reference both to the underlying data, and to the SDK instance.
/// Changes to the underlying data will generally be available on existing handles objects without
/// having to re-create them. If the SDK instance is destroyed, but you still have a reference to a
/// handle object, note that it will return the default value for all method calls (ie an empty
/// string for methods that return a string).
class LobbyHandle {

	/// Copy constructor for LobbyHandle
	LobbyHandle(const LobbyHandle &other);

	void Drop();

	/// \brief Returns a reference to the CallInfoHandle if there is an active voice call in this
	/// lobby.
	/// This can allow you to display which lobby members are in voice, even if the current user has
	/// not yet joined the voice call.
	std::optional<discordpp::CallInfoHandle> GetCallInfoHandle() const;

	/// \brief Returns a reference to the LobbyMemberHandle for the given user ID, if they are a
	/// member of this lobby.
	std::optional<discordpp::LobbyMemberHandle> GetLobbyMemberHandle(uint64_t memberId) const;

	/// \brief Returns the id of the lobby.
	uint64_t Id() const;

	/// \brief Returns information about the channel linked to this lobby, if any.
	std::optional<discordpp::LinkedChannel> LinkedChannel() const;

	/// \brief Returns a list of the user IDs that are members of this lobby.
	std::vector<uint64_t> LobbyMemberIds() const;

	/// \brief Returns a list of the LobbyMemberHandle objects for each member of this lobby.
	std::vector<discordpp::LobbyMemberHandle> LobbyMembers() const;

	/// \brief Returns any developer supplied metadata for this lobby.
	/// Metadata is simple string key/value pairs and is a way to associate internal game
	/// information with the lobby so each lobby member can have easy access to.
	std::unordered_map<std::string, std::string> Metadata() const;
};

/// \brief Contains information about non-text content in a message that likely cannot be rendered
/// in game such as images, videos, embeds, polls, and more.
class AdditionalContent {

	/// Copy constructor for AdditionalContent
	AdditionalContent(const AdditionalContent &arg0);

	explicit AdditionalContent();

	void Drop();

	/// \brief Compares each field of the AdditionalContent struct for equality.
	bool Equals(discordpp::AdditionalContent rhs) const;

	/// \brief Converts the AdditionalContentType enum to a string.
	static std::string TypeToString(discordpp::AdditionalContentType type);

	/// \brief Represents the type of additional content in the message.
	discordpp::AdditionalContentType Type() const;
	/// Setter for AdditionalContent::Type.
	void SetType(discordpp::AdditionalContentType Type);

	/// \brief When the additional content is a poll or thread, this field will contain the name of
	/// the poll or thread.
	std::optional<std::string> Title() const;
	/// Setter for AdditionalContent::Title.
	void SetTitle(std::optional<std::string> Title);

	/// \brief Represents the number of pieces of additional content so you could for example
	/// renders "2 additional images".
	uint8_t Count() const;
	/// Setter for AdditionalContent::Count.
	void SetCount(uint8_t Count);
};

/// \brief A MessageHandle represents a single message received by the SDK.
/// # Chat types
/// The SDK supports two types of chat:
/// 1. 1 on 1 chat between two users
/// 2. Chat within a lobby
/// You can determine the context a message was sent in with the MessageHandle::Channel and
/// ChannelHandle::Type methods. The SDK should only be receiving messages in the following channel
/// types:
/// - DM
/// - Ephemeral DM
/// - Lobby
/// # Syncing with Discord
/// In some situations messages sent from the SDK will also show up in Discord.
/// In general this will happen for:
/// - 1 on 1 chat when at least one of the users is a full Discord user
/// - Lobby chat when the lobby is linked to a Discord channel
/// Additionally the message must have been sent by a user who is not banned on the Discord side.
/// # Legal disclosures
/// As a convenience for game developers, the first time a user sends a message in game, and that
/// message will show up on the Discord client, the SDK will inject a "fake" message into the chat,
/// that contains a basic English explanation of what is happening to the user. You can identify
/// these messages with the MessageHandle::DisclosureType method. We encourage you to customize the
/// rendering of these messages, possibly changing the wording, translating them, and making them
/// look more "official". You can choose to avoid rendering these as well.
/// # History
/// The SDK keeps the 25 most recent messages in each channel in memory, but it does not have access
/// to any historical messages sent before the SDK was connected. A MessageHandle will keep working
/// though even after the SDK has discarded the message for being too old, you just won't be able to
/// create a new MessageHandle objects for that message.
/// # Unrenderable Content
/// Messages sent on Discord can contain content that may not be renderable in game, such as images,
/// videos, embeds, polls, and more. The game isn't expected to render these, but instead show a
/// small notice so the user is aware there is more content and a way to view that content on
/// Discord. The MessageHandle::AdditionalContent method will contain data about the non-text
/// content in this message.
/// There is also more information about the struct of messages on Discord here:
/// https://discord.com/developers/docs/resources/message
/// Note: While the SDK allows you to send messages on behalf of a user, you must only do so in
/// response to a user action. You should never automatically send messages.
/// Handle objects in the SDK hold a reference both to the underlying data, and to the SDK instance.
/// Changes to the underlying data will generally be available on existing handles objects without
/// having to re-create them. If the SDK instance is destroyed, but you still have a reference to a
/// handle object, note that it will return the default value for all method calls (ie an empty
/// string for methods that return a string).
class MessageHandle {

	/// Copy constructor for MessageHandle
	MessageHandle(const MessageHandle &other);

	void Drop();

	/// \brief If the message contains non-text content, such as images, videos, embeds, polls, etc,
	/// this method will return information about that content.
	std::optional<discordpp::AdditionalContent> AdditionalContent() const;

	/// \brief Returns the application ID associated with this message, if any. You can use
	/// this to identify if the mesage was sent from another child application in
	/// your catalog.
	/// Note: Parent / child applications are in limited access and the SentFromGame
	/// field should be relied on for the common case.
	std::optional<uint64_t> ApplicationId() const;

	/// \brief Returns the UserHandle for the author of this message.
	std::optional<discordpp::UserHandle> Author() const;

	/// \brief Returns the user ID of the user who sent this message.
	uint64_t AuthorId() const;

	/// \brief Returns the ChannelHandle for the channel this message was sent in.
	std::optional<discordpp::ChannelHandle> Channel() const;

	/// \brief Returns the channel ID this message was sent in.
	uint64_t ChannelId() const;

	/// \brief Returns the content of this message, if any.
	/// A message can be blank if it was sent from Discord but only contains content such as image
	/// attachments. Certain types of markup, such as markup for emojis and mentions, will be auto
	/// replaced with a more human readable form, such as `@username` or `:emoji_name:`.
	std::string Content() const;

	/// \brief If this is an auto-generated message that is explaining some integration behavior to
	/// users, this method will return the type of disclosure so you can customize it.
	std::optional<discordpp::DisclosureTypes> DisclosureType() const;

	/// \brief The timestamp in millis since the epoch when the message was most recently edited.
	/// Returns 0 if the message has not been edited yet.
	uint64_t EditedTimestamp() const;

	/// \brief Returns the ID of this message.
	uint64_t Id() const;

	/// \brief Returns the LobbyHandle this message was sent in, if it was sent in a lobby.
	std::optional<discordpp::LobbyHandle> Lobby() const;

	/// \brief Returns any metadata the developer included with this message.
	/// Metadata is just a set of simple string key/value pairs.
	/// An example use case might be to include a character name so you can customize how a message
	/// renders in game.
	std::unordered_map<std::string, std::string> Metadata() const;

	/// \brief Returns the content of this message, if any, but without replacing any markup from
	/// emojis and mentions.
	/// A message can be blank if it was sent from Discord but only contains content such as image
	/// attachments.
	std::string RawContent() const;

	/// \brief Returns the UserHandle for the other participant in a DM, if this message was sent in
	/// a DM.
	std::optional<discordpp::UserHandle> Recipient() const;

	/// \brief When this message was sent in a DM or Ephemeral DM, this method will return the ID of
	/// the other user in that DM.
	uint64_t RecipientId() const;

	/// \brief Returns true if this message was sent in-game, otherwise false (i.e. from Discord
	/// itself). If you are using parent / child applications, this will be true if the message was
	/// sent from any child application.
	bool SentFromGame() const;

	/// \brief The timestamp in millis since the epoch when the message was sent.
	uint64_t SentTimestamp() const;
};

/// \brief Represents a single input or output audio device available to the user.
/// Discord will initialize the audio engine with the system default input and output devices.
/// You can change the device through the Client by passing the id of the desired audio device.
class AudioDevice {

	/// Copy constructor for AudioDevice
	AudioDevice(const AudioDevice &arg0);

	void Drop();

	/// \brief Compares the ID of two AudioDevice objects for equality.
	bool Equals(discordpp::AudioDevice rhs);

	/// \brief The ID of the audio device.
	std::string Id() const;
	/// Setter for AudioDevice::Id.
	void SetId(std::string Id);

	/// \brief The display name of the audio device.
	std::string Name() const;
	/// Setter for AudioDevice::Name.
	void SetName(std::string Name);

	/// \brief Whether the audio device is the system default device.
	bool IsDefault() const;
	/// Setter for AudioDevice::IsDefault.
	void SetIsDefault(bool IsDefault);
};

/// \brief Represents a summary of a DM conversation with a user.
class UserMessageSummary {

	/// Copy constructor for UserMessageSummary
	UserMessageSummary(const UserMessageSummary &arg0);

	void Drop();

	/// \brief Returns the ID of the last message sent in the DM conversation.
	uint64_t LastMessageId() const;

	/// \brief Returns the ID of the other user in the DM conversation.
	uint64_t UserId() const;
};

/// \brief Options for creating a new Client instance.
/// This class may be used to set advanced initialization-time options on Client.
class ClientCreateOptions {

	/// Copy constructor for ClientCreateOptions
	ClientCreateOptions(const ClientCreateOptions &arg0);

	explicit ClientCreateOptions();

	void Drop();

	/// \brief The base URL for the Discord web application.
	std::string WebBase() const;
	/// Setter for ClientCreateOptions::WebBase.
	void SetWebBase(std::string WebBase);

	/// \brief The base URL for the Discord API.
	std::string ApiBase() const;
	/// Setter for ClientCreateOptions::ApiBase.
	void SetApiBase(std::string ApiBase);

	/// \brief The audio system to use. Defaults to AudioSystem::Standard.
	/// This is an experimental API which may be removed or changed in a future release.
	/// The game audio system alters the behavior of Discord Voice on mobile platforms
	/// to use standard media-type streams instead of voice-specific audio APIs when
	/// possible. Currently this will be used on iOS 18.2+ on devices which return true
	/// from `-[AVAudioSession isEchoCancelledInputAvailable]` and on Android devices.
	discordpp::AudioSystem ExperimentalAudioSystem() const;
	/// Setter for ClientCreateOptions::ExperimentalAudioSystem.
	void SetExperimentalAudioSystem(discordpp::AudioSystem ExperimentalAudioSystem);

	/// \brief Whether to prevent communications mode on Android when Bluetooth is connected.
	/// This is an experimental API which may be removed or changed in a future release.
	/// When set to true, the SDK will not enter communications mode when Bluetooth is connected.
	/// This setting is only meaningful on Android. It allows you to retain full quality stereo
	/// audio playback when in-call and avoids mixing issues caused by Bluetooth Absolute Volume,
	/// but will use the device microphone instead of the headset one.
	bool ExperimentalAndroidPreventCommsForBluetooth() const;
	/// Setter for ClientCreateOptions::ExperimentalAndroidPreventCommsForBluetooth.
	void SetExperimentalAndroidPreventCommsForBluetooth(
			bool ExperimentalAndroidPreventCommsForBluetooth);
};

/// \brief The Client class is the main entry point for the Discord SDK. All functionality is
/// exposed through this class.
/// See @ref getting_started "Getting Started" for more information on how to use the Client class.
class Client {
	/// \brief Represents an error state for the socket connection that the Discord SDK maintains
	/// with the Discord backend.
	/// Generic network failures will use the ConnectionFailed and ConnectionCanceled
	/// enum values. Other errors such as if the user's auth token is invalid or out of
	/// date will be UnexpectedClose and you should look at the other Error fields for the specific
	/// details.
	enum class Error {

		/// \brief None
		None = 0,

		/// \brief ConnectionFailed
		ConnectionFailed = 1,

		/// \brief UnexpectedClose
		UnexpectedClose = 2,

		/// \brief ConnectionCanceled
		ConnectionCanceled = 3,
	};

	/// \brief This enum refers to the status of the internal websocket the SDK uses to communicate
	/// with Discord There are ~2 phases for "launching" the client:
	/// 1. The socket has to connect to Discord and exchange an auth token. This is indicated by the
	/// `Connecting` and `Connected` values.
	/// 2. The socket has to receive an initial payload of data that describes the current user,
	/// what lobbies they are in, who their friends are, etc. This is the `Ready` status.
	/// Many Client functions will not work until the status changes to `Ready`, such as
	/// GetCurrentUser().
	/// Status::Ready is the one you want to wait for!
	/// Additionally, sometimes the socket will be disconnected, such as through temporary network
	/// blips. But it will try to automatically reconnect, as indicated by the `Reconnecting`
	/// status.
	enum class Status {

		/// \brief Disconnected
		Disconnected = 0,

		/// \brief Connecting
		Connecting = 1,

		/// \brief Connected
		Connected = 2,

		/// \brief Ready
		Ready = 3,

		/// \brief Reconnecting
		Reconnecting = 4,

		/// \brief Disconnecting
		Disconnecting = 5,

		/// \brief HttpWait
		HttpWait = 6,
	};

	/// \brief Represents the type of thread to control thread priority on.
	enum class Thread {

		/// \brief Client
		Client = 0,

		/// \brief Voice
		Voice = 1,

		/// \brief Network
		Network = 2,
	};

	/// \brief Callback invoked when Client::EndCall completes.
	using EndCallCallback = std::function<void()>;

	/// \brief Callback invoked when Client::EndCalls completes.
	using EndCallsCallback = std::function<void()>;

	/// \brief Callback function for Client::GetCurrentInputDevice.
	using GetCurrentInputDeviceCallback = std::function<void(discordpp::AudioDevice device)>;

	/// \brief Callback function for Client::GetCurrentOutputDevice.
	using GetCurrentOutputDeviceCallback = std::function<void(discordpp::AudioDevice device)>;

	/// \brief Callback function for Client::GetInputDevices.
	using GetInputDevicesCallback =
			std::function<void(std::vector<discordpp::AudioDevice> devices)>;

	/// \brief Callback function for Client::GetOutputDevices.
	using GetOutputDevicesCallback =
			std::function<void(std::vector<discordpp::AudioDevice> devices)>;

	/// \brief Callback function for Client::SetDeviceChangeCallback.
	using DeviceChangeCallback =
			std::function<void(std::vector<discordpp::AudioDevice> inputDevices,
					std::vector<discordpp::AudioDevice> outputDevices)>;

	/// \brief Callback function for Client::SetInputDevice.
	using SetInputDeviceCallback = std::function<void(discordpp::ClientResult result)>;

	/// \brief Callback function for Client::SetNoAudioInputCallback.
	using NoAudioInputCallback = std::function<void(bool inputDetected)>;

	/// \brief Callback function for Client::SetOutputDevice.
	using SetOutputDeviceCallback = std::function<void(discordpp::ClientResult result)>;

	/// \brief Callback function for Client::SetVoiceParticipantChangedCallback.
	using VoiceParticipantChangedCallback =
			std::function<void(uint64_t lobbyId, uint64_t memberId, bool added)>;

	/// \brief Callback function for Client::StartCallWithAudioCallbacks.
	/// The audio samples in `data` can be modified in-place to achieve simple DSP effects.
	using UserAudioReceivedCallback = std::function<void(uint64_t userId,
			int16_t *data,
			uint64_t samplesPerChannel,
			int32_t sampleRate,
			uint64_t channels,
			bool &outShouldMute)>;

	/// \brief Callback function for Client::StartCallWithAudioCallbacks.
	/// The audio samples in `data` can be modified in-place to achieve simple DSP effects.
	using UserAudioCapturedCallback = std::function<
			void(int16_t *data, uint64_t samplesPerChannel, int32_t sampleRate, uint64_t channels)>;

	/// \brief Callback invoked when the Authorize function completes.
	/// The first arg contains any error message encountered during the authorization flow, such as
	/// if the user cancelled the authorization. The second arg, code, contains an authorization
	/// _code_. This alone cannot be used to authorize with Discord, and instead must be exchanged
	/// for an access token later.
	using AuthorizationCallback = std::function<
			void(discordpp::ClientResult result, std::string code, std::string redirectUri)>;

	/// \brief Callback function for Client::ExchangeChildToken.
	using ExchangeChildTokenCallback =
			std::function<void(discordpp::ClientResult result,
					std::string accessToken,
					discordpp::AuthorizationTokenType tokenType,
					int32_t expiresIn,
					std::string scopes)>;

	/// \brief Callback function for Client::FetchCurrentUser.
	using FetchCurrentUserCallback =
			std::function<void(discordpp::ClientResult result, uint64_t id, std::string name)>;

	/// \brief Callback function for the token exchange APIs such as Client::GetToken
	using TokenExchangeCallback = std::function<void(discordpp::ClientResult result,
			std::string accessToken,
			std::string refreshToken,
			discordpp::AuthorizationTokenType tokenType,
			int32_t expiresIn,
			std::string scopes)>;

	/// \brief Callback function for the Client::RevokeToken method.
	using RevokeTokenCallback = std::function<void(discordpp::ClientResult result)>;

	/// \brief Callback function for Client::SetAuthorizeDeviceScreenClosedCallback.
	using AuthorizeDeviceScreenClosedCallback = std::function<void()>;

	/// \brief Callback function for Client::SetTokenExpirationCallback
	using TokenExpirationCallback = std::function<void()>;

	/// \brief Callback function for the Client::UnmergeIntoProvisionalAccount method.
	using UnmergeIntoProvisionalAccountCallback =
			std::function<void(discordpp::ClientResult result)>;

	/// \brief Callback function for Client::UpdateProvisionalAccountDisplayName
	using UpdateProvisionalAccountDisplayNameCallback =
			std::function<void(discordpp::ClientResult result)>;

	/// \brief Callback invoked when Client::UpdateToken completes. Once this is done it is safe to
	/// call Client::Connect.
	using UpdateTokenCallback = std::function<void(discordpp::ClientResult result)>;

	/// \brief Callback function for Client::DeleteUserMessage.
	using DeleteUserMessageCallback = std::function<void(discordpp::ClientResult result)>;

	/// \brief Callback function for Client::EditUserMessage.
	using EditUserMessageCallback = std::function<void(discordpp::ClientResult result)>;

	/// \brief Callback function for Client::GetLobbyMessagesWithLimit.
	using GetLobbyMessagesCallback =
			std::function<void(discordpp::ClientResult result,
					std::vector<discordpp::MessageHandle> messages)>;

	/// \brief Callback function for Client::GetUserMessageSummaries.
	using UserMessageSummariesCallback =
			std::function<void(discordpp::ClientResult result,
					std::vector<discordpp::UserMessageSummary> summaries)>;

	/// \brief Callback function for Client::GetUserMessagesWithLimit.
	using UserMessagesWithLimitCallback =
			std::function<void(discordpp::ClientResult result,
					std::vector<discordpp::MessageHandle> messages)>;

	/// \brief Callback function for when Client::ProvisionalUserMergeCompleted completes.
	using ProvisionalUserMergeRequiredCallback = std::function<void()>;

	/// \brief Callback function for when Client::OpenMessageInDiscord completes.
	using OpenMessageInDiscordCallback = std::function<void(discordpp::ClientResult result)>;

	/// \brief This is used for all kinds of 'send message' calls despite the name, to make sure
	/// engine bindings use the same delegate type declaration for all of them, which makes things
	/// nicer. `SendMessageCallback` was unavailable because it's a macro on Windows.
	using SendUserMessageCallback =
			std::function<void(discordpp::ClientResult result, uint64_t messageId)>;

	/// \brief Callback function for Client::SetMessageCreatedCallback.
	using MessageCreatedCallback = std::function<void(uint64_t messageId)>;

	/// \brief Callback function for Client::SetMessageDeletedCallback.
	using MessageDeletedCallback = std::function<void(uint64_t messageId, uint64_t channelId)>;

	/// \brief Callback function for Client::SetMessageUpdatedCallback.
	using MessageUpdatedCallback = std::function<void(uint64_t messageId)>;

	/// \brief Callback function invoked when a new log message is generated.
	using LogCallback =
			std::function<void(std::string message, discordpp::LoggingSeverity severity)>;

	/// \brief Callback function for when Client::OpenConnectedGamesSettingsInDiscord completes.
	using OpenConnectedGamesSettingsInDiscordCallback =
			std::function<void(discordpp::ClientResult result)>;

	/// \brief Callback function for Client::SetStatusChangedCallback.
	/// errorDetail will usually be one of the error code described here:
	/// https://discord.com/developers/docs/topics/opcodes-and-status-codes#gateway-gateway-close-event-codes
	using OnStatusChanged = std::function<
			void(discordpp::Client::Status status, discordpp::Client::Error error, int32_t errorDetail)>;

	/// \brief Callback function for Client::CreateOrJoinLobby
	using CreateOrJoinLobbyCallback =
			std::function<void(discordpp::ClientResult result, uint64_t lobbyId)>;

	/// \brief Callback function for Client::GetGuildChannels.
	using GetGuildChannelsCallback =
			std::function<void(discordpp::ClientResult result,
					std::vector<discordpp::GuildChannel> guildChannels)>;

	/// \brief Callback function for Client::GetUserGuilds.
	using GetUserGuildsCallback = std::function<void(discordpp::ClientResult result,
			std::vector<discordpp::GuildMinimal> guilds)>;

	/// \brief Callback function for Client::JoinLinkedLobbyGuild.
	using JoinLinkedLobbyGuildCallback =
			std::function<void(discordpp::ClientResult result, std::string inviteUrl)>;

	/// \brief Callback function for Client::LeaveLobby.
	using LeaveLobbyCallback = std::function<void(discordpp::ClientResult result)>;

	/// \brief Callback function for Client::LinkChannelToLobby.
	using LinkOrUnlinkChannelCallback = std::function<void(discordpp::ClientResult result)>;

	/// \brief Callback function for Client::SetLobbyCreatedCallback.
	using LobbyCreatedCallback = std::function<void(uint64_t lobbyId)>;

	/// \brief Callback function for Client::SetLobbyDeletedCallback.
	using LobbyDeletedCallback = std::function<void(uint64_t lobbyId)>;

	/// \brief Callback function for Client::SetLobbyMemberAddedCallback.
	using LobbyMemberAddedCallback = std::function<void(uint64_t lobbyId, uint64_t memberId)>;

	/// \brief Callback function for Client::SetLobbyMemberRemovedCallback.
	using LobbyMemberRemovedCallback = std::function<void(uint64_t lobbyId, uint64_t memberId)>;

	/// \brief Callback function for Client::SetLobbyMemberUpdatedCallback.
	using LobbyMemberUpdatedCallback = std::function<void(uint64_t lobbyId, uint64_t memberId)>;

	/// \brief Callback function for Client::SetLobbyUpdatedCallback.
	using LobbyUpdatedCallback = std::function<void(uint64_t lobbyId)>;

	/// \brief Callback function for Client::AcceptActivityInvite.
	using AcceptActivityInviteCallback =
			std::function<void(discordpp::ClientResult result, std::string joinSecret)>;

	/// \brief Callback function for Client::SendActivityInvite, Client::SendActivityJoinRequest,
	/// and Client::SendActivityJoinRequestReply.
	using SendActivityInviteCallback = std::function<void(discordpp::ClientResult result)>;

	/// \brief Callback function for Client::SetActivityInviteCreatedCallback and
	/// Client::SetActivityInviteUpdatedCallback.
	using ActivityInviteCallback = std::function<void(discordpp::ActivityInvite invite)>;

	/// \brief Callback function for Client::SetActivityJoinCallback
	using ActivityJoinCallback = std::function<void(std::string joinSecret)>;

	/// \brief Callback function for Client::SetActivityJoinWithApplicationCallback
	using ActivityJoinWithApplicationCallback =
			std::function<void(uint64_t applicationId, std::string joinSecret)>;

	/// \brief Callback function for when Client::SetOnlineStatus completes.
	using UpdateStatusCallback = std::function<void(discordpp::ClientResult result)>;

	/// \brief Callback function for when Client::UpdateRichPresence completes.
	using UpdateRichPresenceCallback = std::function<void(discordpp::ClientResult result)>;

	/// \brief Callback function for most other Relationship functions such as
	/// Client::SendDiscordFriendRequestById.
	using UpdateRelationshipCallback = std::function<void(discordpp::ClientResult result)>;

	/// \brief Callback function for Client::SendDiscordFriendRequest and
	/// Client::SendGameFriendRequest.
	using SendFriendRequestCallback = std::function<void(discordpp::ClientResult result)>;

	/// \brief Callback function for Client::SetRelationshipCreatedCallback.
	/// `isDiscordRelationshipUpdate` will be true if the relationship created with the `userId` is
	/// a Discord relationship, and false if it's an in-game relationship.
	using RelationshipCreatedCallback =
			std::function<void(uint64_t userId, bool isDiscordRelationshipUpdate)>;

	/// \brief Callback function for Client::SetRelationshipDeletedCallback.
	/// `isDiscordRelationshipUpdate` will be true if the relationship deleted with the `userId` is
	/// a Discord relationship, and false if it's an in-game relationship.
	using RelationshipDeletedCallback =
			std::function<void(uint64_t userId, bool isDiscordRelationshipUpdate)>;

	/// \brief Callback function for when Client::GetDiscordClientConnectedUser completes.
	using GetDiscordClientConnectedUserCallback =
			std::function<void(discordpp::ClientResult result,
					std::optional<discordpp::UserHandle> user)>;

	/// \brief Callback function for Client::SetRelationshipGroupsUpdatedCallback.
	using RelationshipGroupsUpdatedCallback = std::function<void(uint64_t userId)>;

	/// \brief Callback function for Client::SetUserUpdatedCallback.
	using UserUpdatedCallback = std::function<void(uint64_t userId)>;

	Client(const Client &) = delete;

	/// \brief Creates a new instance of the Client.
	explicit Client();

	/// \brief Creates a new instance of the Client but allows customizing the Discord URL to use.
	explicit Client(std::string apiBase, std::string webBase);

	/// \brief Creates a new instance of the Client with custom options.
	explicit Client(discordpp::ClientCreateOptions options);

	void Drop();

	/// \brief Converts the Error enum to a string.
	static std::string ErrorToString(discordpp::Client::Error type);

	/// \brief This function is used to get the application ID for the client. This is used to
	/// identify the application to the Discord client. This is used for things like
	/// authentication, rich presence, and activity invites when *not* connected with
	/// Client::Connect. When calling Client::Connect, the application ID is set automatically
	uint64_t GetApplicationId();

	/// \brief Returns the ID of the system default audio device if the user has not explicitly
	/// chosen one.
	static std::string GetDefaultAudioDeviceId();

	/// \brief Returns the default set of OAuth2 scopes that should be used with the Discord SDK
	/// when making use of the full SDK capabilities, including communications-related features
	/// (e.g. user DMs, lobbies, voice chat). If your application does not make use of these
	/// features, you should use Client::GetDefaultPresenceScopes instead.
	/// Communications-related features are currently in limited access and are not available to
	/// all applications, however, they can be demoed in limited capacity by all applications. If
	/// you are interested in using these features in your game, please reach out to the Discord
	/// team.
	/// It's ok to further customize your requested oauth2 scopes to add additional scopes if you
	/// have legitimate usages for them. However, we strongly recommend always using
	/// Client::GetDefaultCommunicationScopes or Client::GetDefaultPresenceScopes as a baseline to
	/// enable a better authorization experience for users!
	static std::string GetDefaultCommunicationScopes();

	/// \brief Returns the default set of OAuth2 scopes that should be used with the Discord SDK
	/// when leveraging baseline presence-related features (e.g. friends list, rich presence,
	/// provisional accounts, activity invites). If your application is using
	/// communications-related features, which are currently available in limited access, you should
	/// use Client::GetDefaultCommunicationScopes instead.
	/// It's ok to further customize your requested oauth2 scopes to add additional scopes if you
	/// have legitimate usages for them. However, we strongly recommend always using
	/// Client::GetDefaultCommunicationScopes or Client::GetDefaultPresenceScopes as a baseline to
	/// enable a better authorization experience for users!
	static std::string GetDefaultPresenceScopes();

	/// \brief Returns the git commit hash this version was built from.
	static std::string GetVersionHash();

	/// \brief Returns the major version of the Discord Social SDK.
	static int32_t GetVersionMajor();

	/// \brief Returns the minor version of the Discord Social SDK.
	static int32_t GetVersionMinor();

	/// \brief Returns the patch version of the Discord Social SDK.
	static int32_t GetVersionPatch();

	/// \brief This function is used to override the default HTTP timeout for the websocket client.
	void SetHttpRequestTimeout(int32_t httpTimeoutInMilliseconds);

	/// \brief Converts the Status enum to a string.
	static std::string StatusToString(discordpp::Client::Status type);

	/// \brief Converts the Thread enum to a string.
	static std::string ThreadToString(discordpp::Client::Thread type);


	/// \brief Ends any active call, if any. Any references you have to Call objects are invalid
	/// after they are ended, and can be immediately freed.
	void EndCall(uint64_t channelId, discordpp::Client::EndCallCallback callback);

	/// \brief Ends any active call, if any. Any references you have to Call objects are invalid
	/// after they are ended, and can be immediately freed.
	void EndCalls(discordpp::Client::EndCallsCallback callback);

	/// \brief Returns a reference to the currently active call, if any.
	discordpp::Call GetCall(uint64_t channelId);

	/// \brief Returns a reference to all currently active calls, if any.
	std::vector<discordpp::Call> GetCalls();

	/// \brief Asynchronously fetches the current audio input device in use by the client.
	void GetCurrentInputDevice(discordpp::Client::GetCurrentInputDeviceCallback cb);

	/// \brief Asynchronously fetches the current audio output device in use by the client.
	void GetCurrentOutputDevice(discordpp::Client::GetCurrentOutputDeviceCallback cb);

	/// \brief Asynchronously fetches the list of audio input devices available to the user.
	void GetInputDevices(discordpp::Client::GetInputDevicesCallback cb);

	/// \brief Returns the input volume for the current user's microphone.
	/// Input volume is specified as a percentage in the range [0, 100] which represents the
	/// perceptual loudness.
	float GetInputVolume();

	/// \brief Asynchronously fetches the list of audio output devices available to the user.
	void GetOutputDevices(discordpp::Client::GetOutputDevicesCallback cb);

	/// \brief Returns the output volume for the current user.
	/// Output volume specified as a percentage in the range [0, 200] which represents the
	/// perceptual loudness.
	float GetOutputVolume();

	/// \brief Returns whether the current user is deafened in all calls.
	bool GetSelfDeafAll() const;

	/// \brief Returns whether the current user's microphone is muted in all calls.
	bool GetSelfMuteAll() const;

	/// \brief Enables or disables AEC diagnostic recording.
	/// Used to diagnose issues with acoustic echo cancellation. The input and output waveform data
	/// will be written to the log directory.
	void SetAecDump(bool on);

	/// \brief When enabled, automatically adjusts the microphone volume to keep it clear and
	/// consistent.
	/// Defaults to on.
	/// Generally this shouldn't need to be used unless you are building a voice settings UI for the
	/// user to control, similar to Discord's voice settings.
	void SetAutomaticGainControl(bool on);

	/// \brief Sets a callback function to be invoked when Discord detects a change in the available
	/// audio devices.
	void SetDeviceChangeCallback(discordpp::Client::DeviceChangeCallback callback);

	/// \brief Enables or disables the basic echo cancellation provided by the WebRTC library.
	/// Defaults to on.
	/// Generally this shouldn't need to be used unless you are building a voice settings UI for the
	/// user to control, similar to Discord's voice settings.
	void SetEchoCancellation(bool on);

	/// \brief On mobile devices, set whether the audio environment is managed by the engine or the
	/// SDK. On Android, this entails AudioManager state and on iOS, this entails AVAudioSession
	/// activation.
	/// This method must be called before connecting to any Calls if the
	/// application manages audio on its own, otherwise audio management
	/// will be ended by the voice engine when the last Call is ended.
	/// The Unity plugin automatically calls this method if the native Unity
	/// audio engine is enabled in the project settings.
	void SetEngineManagedAudioSession(bool isEngineManaged);

	/// \brief Asynchronously changes the audio input device in use by the client to the specified
	/// device. You can find the list of device IDs that can be passed in with the
	/// Client::GetInputDevices function.
	void SetInputDevice(std::string deviceId, discordpp::Client::SetInputDeviceCallback cb);

	/// \brief Sets the microphone volume for the current user.
	/// Input volume is specified as a percentage in the range [0, 100] which represents the
	/// perceptual loudness.
	void SetInputVolume(float inputVolume);

	/// \brief Callback function invoked when the above threshold is set and there is a change in
	/// whether audio is being detected.
	void SetNoAudioInputCallback(discordpp::Client::NoAudioInputCallback callback);

	/// \brief Threshold that can be set to indicate when no audio is being received by the user's
	/// mic.
	/// An example of when this may be useful: When push to talk is being used and the user pushes
	/// their talk key, but something is configured wrong and no audio is being received, this
	/// threshold and callback can be used to detect that situation and notify the user. The
	/// threshold is specified in DBFS, or decibels relative to full scale, and the range is
	/// [-100.0, 100.0] It defaults to -100.0, so is disabled.
	void SetNoAudioInputThreshold(float dBFSThreshold);

	/// \brief Enables basic background noise suppression.
	/// Defaults to on.
	/// Generally this shouldn't need to be used unless you are building a voice settings UI for the
	/// user to control, similar to Discord's voice settings.
	void SetNoiseSuppression(bool on);

	/// \brief Enables or disables hardware encoding and decoding for audio, if it is available.
	/// Defaults to on.
	/// This must be called immediately after constructing the Client. If called too late an error
	/// will be logged and the setting will not take effect.
	void SetOpusHardwareCoding(bool encode, bool decode);

	/// \brief Asynchronously changes the audio output device in use by the client to the specified
	/// device. You can find the list of device IDs that can be passed in with the
	/// Client::GetOutputDevices function.
	void SetOutputDevice(std::string deviceId, discordpp::Client::SetOutputDeviceCallback cb);

	/// \brief Sets the speaker volume for the current user.
	/// Output volume specified as a percentage in the range [0, 200] which represents the
	/// perceptual loudness.
	void SetOutputVolume(float outputVolume);

	/// \brief Mutes all audio from the currently active call for the current user in all calls.
	/// They will not be able to hear any other participants,
	/// and no other participants will be able to hear the current user either.
	/// Note: This overrides the per-call setting.
	void SetSelfDeafAll(bool deaf);

	/// \brief Mutes the current user's microphone so that no other participant in their active
	/// calls can hear them in all calls. Note: This overrides the per-call setting.
	void SetSelfMuteAll(bool mute);
	bool SetSpeakerMode(bool speakerMode);

	/// \brief Allows setting the priority of various SDK threads.
	/// The threads that can be controlled are:
	/// - Client: This is the main thread for the SDK where most of the data processing happens
	/// - Network: This is the thread that receives voice data from lobby calls
	/// - Voice: This is the thread that the voice engine runs on and processes all audio data
	void SetThreadPriority(discordpp::Client::Thread thread, int32_t priority);

	/// \brief Callback invoked whenever a user in a lobby joins or leaves a voice call.
	/// The main use case for this is to enable displaying which users are in voice in a lobby
	/// even if the current user is not in voice yet, and thus does not have a Call object to bind
	/// to.
	void SetVoiceParticipantChangedCallback(discordpp::Client::VoiceParticipantChangedCallback cb);

	/// \brief On iOS devices, show the system audio route picker.
	bool ShowAudioRoutePicker();

	/// \brief Starts or joins a call in the lobby specified by channelId (For a lobby, simply
	/// pass in the lobbyId).
	/// On iOS, your application is responsible for enabling the appropriate background audio mode
	/// in your Info.plist. VoiceBuildPostProcessor in the sample demonstrates how to do this
	/// automatically in your Unity build process.
	/// On macOS, you should set the NSMicrophoneUsageDescription key in your Info.plist.
	/// Returns null if the user is already in the given voice channel.
	discordpp::Call StartCall(uint64_t channelId);

	/// \brief Starts or joins a call in the specified lobby.
	/// The audio received callback is invoked whenever incoming audio is received in a call. If
	/// the developer sets outShouldMute to true during the callback, the audio data will be muted
	/// after the callback is invoked, which is useful if the developer is utilizing the incoming
	/// audio and playing it through their own audio engine or playback. The audio samples
	/// in `data` can be modified in-place for simple DSP effects.
	/// The audio captured callback is invoked whenever local audio is captured before it is
	/// processed and transmitted which may be useful for voice moderation, etc.
	/// On iOS, your application is responsible for enabling the appropriate background audio mode
	/// in your Info.plist. VoiceBuildPostProcessor in the sample demonstrates how to do this
	/// automatically in your Unity build process.
	/// On macOS, you should set the NSMicrophoneUsageDescription key in your Info.plist.
	/// Returns null if the user is already in the given voice channel.
	discordpp::Call StartCallWithAudioCallbacks(
			uint64_t lobbyId,
			discordpp::Client::UserAudioReceivedCallback receivedCb,
			discordpp::Client::UserAudioCapturedCallback capturedCb);


	/// \brief This will abort the authorize flow if it is in progress and tear down any associated
	/// state.
	/// NOTE: this *will not* close authorization windows presented to the user.
	void AbortAuthorize();

	/// \brief This function is used to abort/cleanup the device authorization flow.
	void AbortGetTokenFromDevice();

	/// \brief Initiates an OAuth2 flow for a user to "sign in with Discord". This flow is intended
	/// for desktop and mobile devices. If you are implementing for the console, leverage the device
	/// auth flow instead (Client::GetTokenFromDevice or Client::OpenAuthorizeDeviceScreen).
	/// ## Overview
	/// If you're not familiar with OAuth2, some basic background: At a high level the goal of
	/// OAuth2 is to allow a user to connect two applications together and share data between them.
	/// In this case, allowing a game to access some of their Discord data. The high level flow is:
	/// - This function, Authorize, is invoked to start the OAuth2 process, and the user is sent to
	/// Discord
	/// - On Discord, the user sees a prompt to authorize the connection, and that prompt explains
	/// what data and functionality the game is requesting.
	/// - Once the user approves the connection, they are redirected back to your application with a
	/// secret code.
	/// - You can then exchange that secret code to get back an access token which can be used to
	/// authenticate with the SDK.
	/// ## Public vs Confidential Clients
	/// Normal OAuth2 requires a backend server to handle exchanging the "code" for a "token" (the
	/// last step mentioned above). Not all games have backend servers or their own identity system
	/// though, and for early testing of the SDK that can take some time to setup.
	/// If desired, you can instead change your Discord application in the developer portal (on the
	/// OAuth2 tab), to be a "public" client. This will allow you to exchange the code for a token
	/// without a backend server, by using the GetToken function below. You can also change this
	/// setting back once you have a backend in place later too.
	/// ## Overlay
	/// To streamline the authentication process, the SDK will attempt to use the Discord overlay if
	/// it is enabled. This will allow the user to authenticate without leaving the game, enabling a
	/// more seamless experience.
	/// You should check to see if the Discord overlay works with your game before shipping. It's
	/// ok if it doesn't though, the SDK will fall back to using a browser window. Once you're ready
	/// to ship, you can work with us to have the overlay enabled by default for your game too.
	/// If your game's main window is not the same process that the SDK is running in, then you need
	/// to tell the SDK the PID of the window that the overlay should attach to. You can do this by
	/// calling Client::SetGameWindowPid.
	/// ## Redirects
	/// For the Authorize function to work, you must configure a redirect url in your Discord
	/// application in the developer portal, (it is located on the OAuth2 tab).
	/// - For desktop applications, add `http://127.0.0.1/callback`
	/// - For mobile applications, add `discord-APP_ID:/authorize/callback`
	/// The SDK will then spin up a local webserver to handle the OAuth2 redirects for you as
	/// well to streamline your integration.
	/// ## Security
	/// This function accepts an args object, and two of those values are important for security:
	/// - To prevent CSRF attacks during auth, the SDK automatically attaches a state and checks it
	/// for you when performing the authorization. You can override state if you want for your own
	/// flow, but please be mindful to keep it a secure, random value.
	/// - If you are using the Client::GetToken function you will need to provide a "code challenge"
	/// or "code verifier". We'll spare you the boring details of how that works (woo… crypto), as
	/// we've made a simple function to create these for you,
	/// Client::CreateAuthorizationCodeVerifier. That returns a struct with two items, a `challenge`
	/// value to pass into this function and a `verifier` value to pass into Client::GetToken.
	/// ## Callbacks & Code Exchange
	/// When this flow completes, the given callback function will be invoked with a "code". That
	/// code must be exchanged for an actual authorization token before it can be used. To start,
	/// you can use the Client::GetToken function to perform this exchange. Longer term private apps
	/// will want to move to the server side API for this, since that enables provisional accounts
	/// to "upgrade" to full Discord accounts.
	/// ## Android
	/// You must add the appropriate intent filter to your `AndroidManifest.xml`.
	/// `AndroidBuildPostProcessor` in the sample demonstrates how to do this automatically.
	/// If you'd like to manage it yourself, the required entry in your `<application>` looks like
	/// this:
	/// ```xml
	/// <activity android:name="com.discord.socialsdk.AuthenticationActivity"
	/// android:exported="true">
	///   <intent-filter>
	///     <action android:name="android.intent.action.VIEW" />
	///     <category android:name="android.intent.category.DEFAULT" />
	///     <category android:name="android.intent.category.BROWSABLE" />
	///     <data android:scheme="discord-1234567890123456789" />
	///   </intent-filter>
	/// </activity>
	/// ```
	/// Replace the numbers after `discord-` with your Application ID from the Discord developer
	/// portal.
	/// Android support (specifically the builtin auth flow) requires the androidx.browser library
	/// as a dependency of your app. The sample uses Google External Dependency Manager to add this
	/// to the Gradle build for the project, but you may use any means of your choosing to add this
	/// dependency. We currently depend on version 1.8.0 of this library.
	/// For more information see: https://discord.com/developers/docs/topics/oauth2
	void Authorize(discordpp::AuthorizationArgs args,
			discordpp::Client::AuthorizationCallback callback);

	/// \brief This function is used to hide the device authorization screen and is used for the
	/// case where the user is on a limited input device, such as a console or smart TV. This
	/// function should be used in conjunction with a backend server to handle the device
	/// authorization flow. For a public client, you can use Client::AbortGetTokenFromDevice
	/// instead.
	void CloseAuthorizeDeviceScreen();

	/// \brief Helper function that can create a code challenge and verifier for use in the
	/// Client::Authorize + Client::GetToken flow. This returns a struct with two items, a
	/// `challenge` value to pass into Client::Authorize and a `verifier` value to pass into
	/// GetToken.
	discordpp::AuthorizationCodeVerifier CreateAuthorizationCodeVerifier();

	/// \brief Exchanges a parent application token for a child application token.
	/// This is used to get a token for a child application that is linked to the parent
	/// application. This is only relevant if you have an applications set up in a parent/child
	/// relationship, which is applicable if you are a publisher with multiple games under the
	/// same account system. Access to this feature is currently limited.
	/// NOTE: This function only works for public clients. Public clients are ones that do not have
	/// a backend server or their own concept of user accounts and simply rely on a separate system
	/// for authentication like Steam/Epic.
	/// When first testing the SDK, it can be a lot easier to use a public client to get a proof of
	/// concept going, and change it to a confidential client later. You can toggle that setting on
	/// the OAuth2 page for your application in the Discord developer portal,
	/// https://discord.com/developers/applications
	void ExchangeChildToken(std::string const &parentApplicationToken,
			uint64_t childApplicationId,
			discordpp::Client::ExchangeChildTokenCallback callback);

	/// \brief Fetches basic information about the user associated with the given auth token.
	/// This can allow you to check if an auth token is valid or not.
	/// This does not require the client to be connected or to have it's own authentication token,
	/// so it can be called immediately after the client connects.
	void FetchCurrentUser(discordpp::AuthorizationTokenType tokenType,
			std::string const &token,
			discordpp::Client::FetchCurrentUserCallback callback);

	/// \brief Provisional accounts are a way for users that have not signed up for Discord to still
	/// access SDK functionality. They are "placeholder" Discord accounts for the user that are
	/// owned and managed by your game. Provisional accounts exist so that your users can engage
	/// with Discord APIs and systems without the friction of creating their own Discord account.
	/// Provisional accounts and their data are unique per Discord application.
	/// This function generates a Discord access token. You pass in the "identity" of the user, and
	/// it generates a new Discord account that is tied to that identity. There are multiple ways of
	/// specifying that identity, including using Steam/Epic services, or using your own identity
	/// system.
	/// The callback function will be invoked with an access token that expires in 1 hour. Refresh
	/// tokens are not supported for provisional accounts, so that will be an empty string. You
	/// will need to call this function again to get a new access token when the old one expires.
	/// NOTE: When the token expires the SDK will still continue to receive updates such as new
	/// messages sent in a lobby, and any voice calls will continue to be active. But any new
	/// actions taken will fail such as sending a messaging or adding a friend. You can get a new
	/// token and pass it to UpdateToken without interrupting the user's experience.
	/// It is suggested that these provisional tokens are not stored, and instead to just invoke
	/// this function each time the game is launched and when these tokens are about to expire.
	/// However, should you choose to store it, it is recommended to differentiate these provisional
	/// account tokens from "full" Discord account tokens.
	/// NOTE: This function only works for public clients. Public clients are ones that do not have
	/// a backend server or their own concept of user accounts and simply rely on a separate system
	/// for authentication like Steam/Epic.
	/// When first testing the SDK, it can be a lot easier to use a public client to get a proof of
	/// concept going, and change it to a confidential client later. You can toggle that setting on
	/// the OAuth2 page for your application in the Discord developer portal,
	/// https://discord.com/developers/applications
	void GetProvisionalToken(uint64_t applicationId,
			discordpp::AuthenticationExternalAuthType externalAuthType,
			std::string const &externalAuthToken,
			discordpp::Client::TokenExchangeCallback callback);

	/// \brief Exchanges an authorization code that was returned from the Client::Authorize function
	/// for an access token which can be used to authenticate with the SDK.
	/// The callback function will be invoked with two tokens:
	/// - An access token which can be used to authenticate with the SDK, but expires after 7 days.
	/// - A refresh token, which cannot be used to authenticate, but can be used to get a new access
	/// token later. Refresh tokens do not currently expire.
	/// It will also include when the access token expires in seconds.
	/// You will want to store this value as well and refresh the token when it gets close to
	/// expiring (for example if the user launches the game and the token expires within 24 hours,
	/// it would be good to refresh it).
	/// For more information see https://discord.com/developers/docs/topics/oauth2
	/// NOTE: This function only works for public clients. Public clients are ones that do not have
	/// a backend server or their own concept of user accounts and simply rely on a separate system
	/// for authentication like Steam/Epic.
	/// When first testing the SDK, it can be a lot easier to use a public client to get a proof of
	/// concept going, and change it to a confidential client later. You can toggle that setting on
	/// the OAuth2 page for your application in the Discord developer portal,
	/// https://discord.com/developers/applications
	void GetToken(uint64_t applicationId,
			std::string const &code,
			std::string const &codeVerifier,
			std::string const &redirectUri,
			discordpp::Client::TokenExchangeCallback callback);

	/// \brief This function is a combination of Client::Authorize and Client::GetToken, but is used
	/// for the case where the user is on a limited input device, such as a console or smart TV.
	/// The callback function will be invoked with two tokens:
	/// - An access token which can be used to authenticate with the SDK, but expires after 7 days.
	/// - A refresh token, which cannot be used to authenticate, but can be used to get a new access
	/// token later. Refresh tokens do not currently expire.
	/// It will also include when the access token expires in seconds.
	/// You will want to store this value as well and refresh the token when it gets close to
	/// expiring (for example if the user launches the game and the token expires within 24 hours,
	/// it would be good to refresh it).
	/// For more information see https://discord.com/developers/docs/topics/oauth2
	/// NOTE: This function only works for public clients. Public clients are ones that do not have
	/// a backend server or their own concept of user accounts and simply rely on a separate system
	/// for authentication like Steam/Epic. If you have a backend server for auth, you can use
	/// Client::OpenAuthorizeDeviceScreen and Client::CloseAuthorizeDeviceScreen to show/hide the UI
	/// for the device auth flow.
	/// When first testing the SDK, it can be a lot easier to use a public client to get a proof of
	/// concept going, and change it to a confidential client later. You can toggle that setting on
	/// the OAuth2 page for your application in the Discord developer portal,
	/// https://discord.com/developers/applications
	void GetTokenFromDevice(discordpp::DeviceAuthorizationArgs args,
			discordpp::Client::TokenExchangeCallback callback);

	/// \brief This function is a combination of Client::Authorize and
	/// Client::GetTokenFromProvisionalMerge, but is used for the case where the user is on a
	/// limited input device, such as a console or smart TV.
	/// This function should be used whenever a user with a provisional account wants to link to an
	/// existing Discord account or "upgrade" their provisional account into a "full" Discord
	/// account.
	/// In this case, data from the provisional account should be "migrated" to the Discord
	/// account, a process we call "account merging". Specifically relationships, DMs, and lobby
	/// memberships are transferred to the Discord account.
	/// The provisional account will be deleted once this merging process completes. If the user
	/// later unlinks, then a new provisional account with a new unique ID is created.
	/// The account merging process starts the same as the normal login flow, by invoking the
	/// GetTokenFromDevice. But instead of calling GetTokenFromDevice, call this function and pass
	/// in the provisional user's identity as well.
	/// The Discord backend can then find both the provisional account with that identity and the
	/// new Discord account and merge any data as necessary.
	/// See the documentation for GetTokenFromDevice for more details on the callback. Note that the
	/// callback will be invoked when the token exchange completes, but the process of merging
	/// accounts happens asynchronously so will not be complete yet.
	/// NOTE: This function only works for public clients. Public clients are ones that do not have
	/// a backend server or their own concept of user accounts and simply rely on a separate system
	/// for authentication like Steam/Epic. If you have a backend server for auth, you can use
	/// Client::OpenAuthorizeDeviceScreen and Client::CloseAuthorizeDeviceScreen to show/hide the UI
	/// for the device auth flow.
	/// When first testing the SDK, it can be a lot easier to use a public client to get a proof of
	/// concept going, and change it to a confidential client later. You can toggle that setting on
	/// the OAuth2 page for your application in the Discord developer portal,
	/// https://discord.com/developers/applications
	void GetTokenFromDeviceProvisionalMerge(
			discordpp::DeviceAuthorizationArgs args,
			discordpp::AuthenticationExternalAuthType externalAuthType,
			std::string const &externalAuthToken,
			discordpp::Client::TokenExchangeCallback callback);

	/// \brief This function should be used with the Client::Authorize function whenever a user with
	/// a provisional account wants to link to an existing Discord account or "upgrade" their
	/// provisional account into a "full" Discord account.
	/// In this case, data from the provisional account should be "migrated" to the Discord
	/// account, a process we call "account merging". Specifically relationships, DMs, and lobby
	/// memberships are transferred to the Discord account.
	/// The provisional account will be deleted once this merging process completes. If the user
	/// later unlinks, then a new provisional account with a new unique ID is created.
	/// The account merging process starts the same as the normal login flow, by invoking the
	/// Authorize method to get an authorization code back. But instead of calling GetToken, call
	/// this function and pass in the provisional user's identity as well.
	/// The Discord backend can then find both the provisional account with that identity and the
	/// new Discord account and merge any data as necessary.
	/// See the documentation for GetToken for more details on the callback. Note that the callback
	/// will be invoked when the token exchange completes, but the process of merging accounts
	/// happens asynchronously so will not be complete yet.
	/// NOTE: This function only works for public clients. Public clients are ones that do not have
	/// a backend server or their own concept of user accounts and simply rely on a separate system
	/// for authentication like Steam/Epic.
	/// When first testing the SDK, it can be a lot easier to use a public client to get a proof of
	/// concept going, and change it to a confidential client later. You can toggle that setting on
	/// the OAuth2 page for your application in the Discord developer portal,
	/// https://discord.com/developers/applications
	void GetTokenFromProvisionalMerge(uint64_t applicationId,
			std::string const &code,
			std::string const &codeVerifier,
			std::string const &redirectUri,
			discordpp::AuthenticationExternalAuthType externalAuthType,
			std::string const &externalAuthToken,
			discordpp::Client::TokenExchangeCallback callback);

	/// \brief Returns true if the SDK has a non-empty OAuth2 token set, regardless of whether that
	/// token is valid or not.
	bool IsAuthenticated();

	/// \brief This function is used to show the device authorization screen and is used for the
	/// case where the user is on a limited input device, such as a console or smart TV. This
	/// function should be used in conjunction with a backend server to handle the device
	/// authorization flow. For a public client, you can use Client::GetTokenFromDevice instead.
	void OpenAuthorizeDeviceScreen(uint64_t clientId, std::string const &userCode);

	/// \brief Some functions don't work for provisional accounts, and require the user
	/// merge their account into a full Discord account before proceeding. This
	/// callback is invoked when an account merge must take place before
	/// proceeding. The developer is responsible for initiating the account merge,
	/// and then calling Client::ProvisionalUserMergeCompleted to signal to the SDK that
	/// the pending operation can continue with the new account.
	void ProvisionalUserMergeCompleted(bool success);

	/// \brief Generates a new access token for the current user from a refresh token.
	/// Once this is called, the old access and refresh tokens are both invalidated and cannot be
	/// used again. The callback function will be invoked with a new access and refresh token. See
	/// GetToken for more details.
	/// NOTE: This function only works for public clients. Public clients are ones that do not have
	/// a backend server or their own concept of user accounts and simply rely on a separate system
	/// for authentication like Steam/Epic.
	/// When first testing the SDK, it can be a lot easier to use a public client to get a proof of
	/// concept going, and change it to a confidential client later. You can toggle that setting on
	/// the OAuth2 page for your application in the Discord developer portal,
	/// https://discord.com/developers/applications
	void RefreshToken(uint64_t applicationId,
			std::string const &refreshToken,
			discordpp::Client::TokenExchangeCallback callback);

	/// \brief Revoke all application access/refresh tokens associated with a user with any valid
	/// access/refresh token. This will invalidate all tokens and they cannot be used again. This
	/// is useful if you want to log the user out of the game and invalidate their session.
	/// NOTE: This function only works for public clients. Public clients are ones that do not have
	/// a backend server or their own concept of user accounts and simply rely on a separate system
	/// for authentication like Steam/Epic.
	/// When first testing the SDK, it can be a lot easier to use a public client to get a proof of
	/// concept going, and change it to a confidential client later. You can toggle that setting on
	/// the OAuth2 page for your application in the Discord developer portal,
	/// https://discord.com/developers/applications
	void RevokeToken(uint64_t applicationId,
			std::string const &token,
			discordpp::Client::RevokeTokenCallback callback);

	/// \brief Sets a callback function to be invoked when the device authorization screen is
	/// closed.
	void SetAuthorizeDeviceScreenClosedCallback(
			discordpp::Client::AuthorizeDeviceScreenClosedCallback cb);

	/// \brief When users are linking their account with Discord, which involves an OAuth2 flow,
	/// the SDK can streamline it by using Discord's overlay so the interaction happens entirely
	/// in-game. If your game's main window is not the same process as the one running the
	/// integration you may need to set the window PID using this method. It defaults to the current
	/// pid.
	void SetGameWindowPid(int32_t pid);

	/// \brief Get a notification when the current token is about to expire or expired.
	/// This callback is invoked when the SDK detects that the last token passed to
	/// Client::UpdateToken is nearing expiration or has expired. This is a signal to the developer
	/// to refresh the token. The callback is invoked once per token, and will not be invoked again
	/// until a new token is passed to Client::UpdateToken.
	/// If the token is refreshed before the expiration callback is invoked, call
	/// Client::UpdateToken to pass in the new token and reconfigure the token expiration.
	/// If your client is disconnected (the token was expired when connecting or was revoked while
	/// connected), the expiration callback will not be invoked.
	void SetTokenExpirationCallback(discordpp::Client::TokenExpirationCallback callback);

	/// \brief This function is used to unlink/unmerge a external identity from a Discord account.
	/// This is useful if the user wants to unlink their external identity from their Discord
	/// account and create a new provisional account for that identity. This will invalidate all
	/// access/refresh tokens for the user and they cannot be used again.
	/// This function should be used with the Client::GetProvisionalToken function to get a
	/// provisional token for the newly created provisional account.
	/// NOTE: This function only works for public clients. Public clients are ones that do not have
	/// a backend server or their own concept of user accounts and simply rely on a separate system
	/// for authentication like Steam/Epic.
	/// When first testing the SDK, it can be a lot easier to use a public client to get a proof of
	/// concept going, and change it to a confidential client later. You can toggle that setting on
	/// the OAuth2 page for your application in the Discord developer portal,
	/// https://discord.com/developers/applications
	void UnmergeIntoProvisionalAccount(
			uint64_t applicationId,
			discordpp::AuthenticationExternalAuthType externalAuthType,
			std::string const &externalAuthToken,
			discordpp::Client::UnmergeIntoProvisionalAccountCallback callback);

	/// \brief Updates the display name of a provisional account to the specified name.
	/// This should generally be invoked whenever the SDK starts and whenever a provisional account
	/// changes their name, since the auto-generated name for provisional accounts is just a random
	/// string.
	void UpdateProvisionalAccountDisplayName(
			std::string const &name,
			discordpp::Client::UpdateProvisionalAccountDisplayNameCallback callback);

	/// \brief Asynchronously sets a new auth token for this client to use.
	/// If your client is already connected, this function *may* trigger a reconnect.
	/// If your client is not connected, this function will only update the auth token, and so you
	/// must invoke Client::Connect as well. You should wait for the given callback function to be
	/// invoked though so that the next Client::Connect attempt uses the updated token.
	void UpdateToken(discordpp::AuthorizationTokenType tokenType,
			std::string token,
			discordpp::Client::UpdateTokenCallback callback);


	/// \brief Returns true if the given message is able to be viewed in a Discord client.
	/// Not all chat messages are replicated to Discord. For example lobby chat and some DMs
	/// are ephemeral and not persisted on Discord so cannot be opened. This function checks those
	/// conditions and makes sure the message is viewable in Discord.
	bool CanOpenMessageInDiscord(uint64_t messageId);

	/// \brief Deletes the specified message sent by the current user to the specified recipient.
	void DeleteUserMessage(uint64_t recipientId,
			uint64_t messageId,
			discordpp::Client::DeleteUserMessageCallback cb);

	/// \brief Edits the specified message sent by the current user to the specified recipient.
	/// All of the same restrictions apply as for sending a message, see SendUserMessage for more.
	void EditUserMessage(uint64_t recipientId,
			uint64_t messageId,
			std::string const &content,
			discordpp::Client::EditUserMessageCallback cb);

	/// \brief Returns a reference to the Discord channel object for the given ID.
	/// All messages in Discord are sent in a channel, so the most common use for this will be
	/// to look up the channel a message was sent in.
	/// For convience this API will also work with lobbies, so the three possible return values
	/// for the SDK are a DM, an Ephemeral DM, and a Lobby.
	std::optional<discordpp::ChannelHandle> GetChannelHandle(uint64_t channelId) const;

	/// \brief Retrieves recent messages from the specified lobby.
	/// Returns a list of MessageHandle representing the recent messages in the lobby,
	/// with a maximum of 200 messages and up to 72 hours.
	/// The messages are returned in reverse chronological order (newest first).
	/// This function requires the current user to be a member of the lobby.
	/// Note: This function makes an HTTP request to Discord's API to retrieve messages, as opposed
	/// to only returning messages that are cached locally by the SDK.
	/// Retrieves recent messages from the specified lobby with the specified limit.
	void GetLobbyMessagesWithLimit(uint64_t lobbyId,
			int32_t limit,
			discordpp::Client::GetLobbyMessagesCallback cb);

	/// \brief Returns a reference to the Discord message object for the given ID.
	/// The SDK keeps the 25 most recent messages in each channel in memory.
	/// Messages sent before the SDK was started cannot be accessed with this.
	std::optional<discordpp::MessageHandle> GetMessageHandle(uint64_t messageId) const;

	/// \brief Retrieves message conversation summaries for all users the current user has DM
	/// conversations with.
	/// The callback will be invoked with a list of UserMessageSummary objects containing:
	/// - userId: The ID of the user this conversation is with
	/// - lastMessageId: The ID of the most recent message in this conversation
	void GetUserMessageSummaries(discordpp::Client::UserMessageSummariesCallback cb);

	/// \brief Retrieves messages from the DM conversation with the specified user.
	/// Returns a list of MessageHandle representing the recent messages in the conversation with
	/// the recipient, with a maximum number specified by the limit parameter. The messages are
	/// returned in reverse chronological order (newest first). This function checks the local cache
	/// first and only makes an HTTP request to Discord's API if there are not enough cached
	/// messages available.
	/// If limit is greater than 0, restricts the number of messages returned. If limit is 0
	/// or negative, the limit parameter is omitted from the request. This is intended for
	/// games to load message history when users open a DM conversation.
	void GetUserMessagesWithLimit(uint64_t recipientId,
			int32_t limit,
			discordpp::Client::UserMessagesWithLimitCallback cb);

	/// \brief Opens the given message in the Discord client.
	/// This is useful when a message is sent that contains content that cannot be viewed in
	/// Discord. You can call this function in the click handler for any CTA you show to view the
	/// message in Discord.
	void OpenMessageInDiscord(
			uint64_t messageId,
			discordpp::Client::ProvisionalUserMergeRequiredCallback provisionalUserMergeRequiredCallback,
			discordpp::Client::OpenMessageInDiscordCallback callback);

	/// \brief Sends a message in a lobby chat to all members of the lobby.
	/// The content of the message is restricted to 2,000 characters maximum.
	/// See https://discord.com/developers/docs/resources/message for more details.
	/// The content of the message can also contain special markup for formatting if desired, see
	/// https://discord.com/developers/docs/reference#message-formatting for more details.
	/// If the lobby is linked to a channel, the message will also be sent to that channel on
	/// Discord.
	void SendLobbyMessage(uint64_t lobbyId,
			std::string const &content,
			discordpp::Client::SendUserMessageCallback cb);

	/// \brief Variant of Client::SendLobbyMessage that also accepts metadata to be sent with the
	/// message.
	/// Metadata is just simple string key/value pairs.
	/// An example use case for this might be to include the name of the character that sent a
	/// message.
	void SendLobbyMessageWithMetadata(uint64_t lobbyId,
			std::string const &content,
			std::unordered_map<std::string, std::string> const &metadata,
			discordpp::Client::SendUserMessageCallback cb);

	/// \brief Sends a direct message to the specified user.
	/// The content of the message is restricted to 2,000 characters maximum.
	/// See https://discord.com/developers/docs/resources/message for more details.
	/// The content of the message can also contain special markup for formatting if desired, see
	/// https://discord.com/developers/docs/reference#message-formatting for more details.
	/// A message can be sent between two users in the following situations:
	/// - Both users are online and in the game and have not blocked each other
	/// - Both users are friends with each other
	/// - Both users share a mutual Discord server and have previously DM'd each other on Discord
	void SendUserMessage(uint64_t recipientId,
			std::string const &content,
			discordpp::Client::SendUserMessageCallback cb);

	/// \brief Variant of Client::SendUserMessage that also accepts metadata to be sent with the
	/// message.
	/// Metadata is just simple string key/value pairs.
	/// An example use case for this might be to include the name of the character that sent a
	/// message.
	void SendUserMessageWithMetadata(uint64_t recipientId,
			std::string const &content,
			std::unordered_map<std::string, std::string> const &metadata,
			discordpp::Client::SendUserMessageCallback cb);

	/// \brief Sets a callback to be invoked whenever a new message is received in either a lobby or
	/// a DM.
	/// From the messageId you can fetch the MessageHandle and then the ChannelHandle to determine
	/// the location the message was sent as well.
	/// If the user has the Discord desktop application open on the same machine as the game, then
	/// they will hear notifications from the Discord application, even though they are able to see
	/// those messages in game. So to avoid double-notifying users, you should call
	/// Client::SetShowingChat whenever the chat is shown or hidden to suppress those duplicate
	/// notifications.
	void SetMessageCreatedCallback(discordpp::Client::MessageCreatedCallback cb);

	/// \brief Sets a callback to be invoked whenever a message is deleted.
	/// Some messages sent from in game, as well as all messages sent from a connected user's
	/// Discord client can be edited and deleted in the Discord client. So it is valuable to
	/// implement support for this callback so that if a user edits or deletes a message in the
	/// Discord client, it is reflected in game as well.
	void SetMessageDeletedCallback(discordpp::Client::MessageDeletedCallback cb);

	/// \brief Sets a callback to be invoked whenever a message is edited.
	/// Some messages sent from in game, as well as all messages sent from a connected user's
	/// Discord client can be edited and deleted in the Discord client. So it is valuable to
	/// implement support for this callback so that if a user edits or deletes a message in the
	/// Discord client, it is reflected in game as well.
	void SetMessageUpdatedCallback(discordpp::Client::MessageUpdatedCallback cb);

	/// \brief Sets whether chat messages are currently being shown in the game.
	/// If the user has the Discord desktop application open on the same machine as the game, then
	/// they will hear notifications from the Discord application, even though they are able to see
	/// those messages in game. So to avoid double-notifying users, you can call this function
	/// whenever the chat is shown or hidden to suppress those duplicate notifications.
	/// Keep in mind, if the game stops showing chat for a period of time, or the game loses focus
	/// because the user switches to a different app, it is important to call this function again so
	/// that the user's notifications get re-enabled in Discord during this time.
	void SetShowingChat(bool showingChat);


	/// \brief Adds a callback function to be invoked for each new log message generated by the SDK.
	/// This function explicitly excludes most logs for voice and webrtc activity since those are
	/// generally much noisier and you may want to pick a different log level for those. So it will
	/// instead include logs for things such as lobbies, relationships, presence, and
	/// authentication.
	/// We strongly recommend invoking this function immediately after constructing the Client
	/// object.
	void AddLogCallback(discordpp::Client::LogCallback callback,
			discordpp::LoggingSeverity minSeverity);

	/// \brief Adds a callback function to be invoked for each new log message generated by the
	/// voice subsystem of the SDK, including the underlying webrtc infrastructure.
	/// We strongly recommend invoking this function immediately after constructing the Client
	/// object.
	void AddVoiceLogCallback(discordpp::Client::LogCallback callback,
			discordpp::LoggingSeverity minSeverity);

	/// \brief Asynchronously connects the client to Discord.
	/// If a client is disconnecting, this will wait for the disconnect before reconnecting.
	/// You should use the Client::SetStatusChangedCallback and Client::GetStatus functions to
	/// receive updates on the client status. The Client is only safe to use once the status changes
	/// to Status::Ready.
	void Connect();

	/// \brief Asynchronously disconnects the client.
	/// You can leverage Client::SetStatusChangedCallback and Client::GetStatus to receive updates
	/// on the client status. It is fully disconnected when the status changes to
	/// Client::Status::Disconnected.
	void Disconnect();

	/// \brief Returns the current status of the client, see the Status enum for an explanation of
	/// the possible values.
	discordpp::Client::Status GetStatus() const;

	/// \brief Opens the Connected Games settings in the Discord client, which is where
	/// users can manage their settings related to games using the Discord Social SDK.
	/// If the client isn't connected or the user is a provisional account, this function does
	/// nothing.
	/// It is always a no-op for console platforms.
	void OpenConnectedGamesSettingsInDiscord(
			discordpp::Client::OpenConnectedGamesSettingsInDiscordCallback callback);

	/// \brief This function is used to set the application ID for the client. This is used to
	/// identify the application to the Discord client. This is used for things like
	/// authentication, rich presence, and activity invites when *not* connected with
	/// Client::Connect. When calling Client::Connect, the application ID is set automatically
	void SetApplicationId(uint64_t applicationId);

	/// \brief Causes logs generated by the SDK to be written to disk in the specified directory.
	/// This function explicitly excludes most logs for voice and webrtc activity since those are
	/// generally much noisier and you may want to pick a different log level for those. So it will
	/// instead include logs for things such as lobbies, relationships, presence, and
	/// authentication. An empty path defaults to logging alongside the client library. A
	/// minSeverity = LoggingSeverity::None disables logging to a file (also the current default).
	/// The logs will be placed into a file called "discord.log" in the specified directory.
	/// Overwrites any existing discord.log file.
	/// We strongly recommend invoking this function immediately after constructing the Client
	/// object.
	/// Returns true if the log file was successfully opened, false otherwise.
	bool SetLogDir(std::string const &path, discordpp::LoggingSeverity minSeverity);

	/// \brief Sets a callback function to be invoked whenever the SDKs status changes.
	void SetStatusChangedCallback(discordpp::Client::OnStatusChanged cb);

	/// \brief Causes logs generated by the voice subsystem of the SDK to be written to disk in the
	/// specified directory.
	/// These logs will be in a file like discord-webrtc_0, and if they grow to big will be rotated
	/// and the number incremented. If the log files already exist the old ones will be renamed to
	/// discord-last-webrtc_0.
	/// An empty path defaults to logging alongside the client library.
	/// A minSeverity = LoggingSeverity::None disables logging to a file (also the current default).
	/// WARNING: This function MUST be invoked immediately after constructing the Client object!
	/// It will print out a warning if invoked too late.
	void SetVoiceLogDir(std::string const &path, discordpp::LoggingSeverity minSeverity);


	/// \brief Joins the user to the specified lobby, creating one if it does not exist.
	/// The lobby is specified by the supplied string, which should be a hard to guess secret
	/// generated by the game. All users who join the lobby with the same secret will be placed in
	/// the same lobby.
	/// For exchanging the secret, we strongly encourage looking into the activity invite and rich
	/// presence systems which provide a way to include a secret string that only accepted party
	/// members are able to see.
	/// As with server created lobbies, client created lobbies auto-delete once they have been idle
	/// for a few minutes (which currently defaults to 5 minutes). A lobby is idle if no users are
	/// connected to it.
	/// This function shouldn't be used for long lived lobbies. The "secret" value expires after ~30
	/// days, at which point the existing lobby cannot be joined and a new one would be created
	/// instead.
	void CreateOrJoinLobby(std::string const &secret,
			discordpp::Client::CreateOrJoinLobbyCallback callback);

	/// \brief Variant of Client::CreateOrJoinLobby that also accepts developer-supplied metadata.
	/// Metadata is just simple string key/value pairs.
	/// An example use case for this might be to the internal game ID of the user of each lobby so
	/// all members of the lobby can have a mapping of discord IDs to game IDs. Subsequent calls to
	/// CreateOrJoinLobby will overwrite the metadata for the lobby and member.
	void CreateOrJoinLobbyWithMetadata(
			std::string const &secret,
			std::unordered_map<std::string, std::string> const &lobbyMetadata,
			std::unordered_map<std::string, std::string> const &memberMetadata,
			discordpp::Client::CreateOrJoinLobbyCallback callback);

	/// \brief Fetches all of the channels that the current user can access in the given guild.
	/// The purpose of this is to power the channel linking flow for linking a Discord channel to an
	/// in-game lobby. So this function can be used to power a UI to let the user pick which channel
	/// to link to once they have picked a guild. See the docs on LobbyHandle for more information.
	void GetGuildChannels(uint64_t guildId, discordpp::Client::GetGuildChannelsCallback cb);

	/// \brief Returns a reference to the Discord lobby object for the given ID.
	std::optional<discordpp::LobbyHandle> GetLobbyHandle(uint64_t lobbyId) const;

	/// \brief Returns a list of all the lobbies that the user is a member of and the SDK has
	/// loaded.
	/// Lobbies are optimistically loaded when the SDK starts but in some cases may not be available
	/// immediately after the SDK status changes to Status::Ready.
	std::vector<uint64_t> GetLobbyIds() const;

	/// \brief Fetches all of the guilds (also known as Discord servers) that the current user is a
	/// member of.
	/// The purpose of this is to power the channel linking flow for linking a Discord channel
	/// to an in-game lobby. So this function can be used to power a UI to let the user which guild
	/// to link to. See the docs on LobbyHandle for more information.
	void GetUserGuilds(discordpp::Client::GetUserGuildsCallback cb);

	/// \brief Invites the current user to the Discord guild of the channel that is linked to the
	/// specified lobby. The user is forwarded to the Discord client with the resulting invite url,
	/// upon which the user can decide to accept or decline that invite.
	/// On console platforms, the user is not navigated to any Discord client, so the invite url
	/// should be presented to the user in some way, so they can use it.
	void JoinLinkedLobbyGuild(
			uint64_t lobbyId,
			discordpp::Client::ProvisionalUserMergeRequiredCallback provisionalUserMergeRequiredCallback,
			discordpp::Client::JoinLinkedLobbyGuildCallback callback);

	/// \brief Removes the current user from the specified lobby.
	/// Only lobbies that contain a "secret" can be left.
	/// In other words, only lobbies created with Client::CreateOrJoinLobby can be left.
	/// Lobbies created using the server API may not be manipulated by clients, so you must
	/// use the server API to remove them too.
	void LeaveLobby(uint64_t lobbyId, discordpp::Client::LeaveLobbyCallback callback);

	/// \brief Links the specified channel on Discord to the specified in-game lobby.
	/// Any message sent in one will be copied over to the other!
	/// See the docs on LobbyHandle for more information.
	void LinkChannelToLobby(uint64_t lobbyId,
			uint64_t channelId,
			discordpp::Client::LinkOrUnlinkChannelCallback callback);

	/// \brief Sets a callback to be invoked when a lobby "becomes available" to the client.
	/// A lobby can become available in a few situations:
	/// - A new lobby is created and the current user is a member of it
	/// - The current user is added to an existing lobby
	/// - A lobby recovers after a backend crash and is available once again
	/// This means that the LobbyCreated callback can be invoked more than once in a single session!
	/// Generally though it should never be invoked twice in a row. For example if a lobby crashes
	/// or a user is removed from the lobby, you should expect to have the LobbyDeleted callback
	/// invoked first.
	void SetLobbyCreatedCallback(discordpp::Client::LobbyCreatedCallback cb);

	/// \brief Sets a callback to be invoked when a lobby is no longer available.
	/// This callback can be invoked in a number of situations:
	/// - A lobby the user is a member of is deleted
	/// - The current user is removed from a lobby
	/// - There is a backend crash that causes the lobby to be unavailable for all users
	/// This means that this callback might be invoked even though the lobby still exists for other
	/// users!
	void SetLobbyDeletedCallback(discordpp::Client::LobbyDeletedCallback cb);

	/// \brief Sets a callback function to be invoked whenever a user is added to a lobby.
	/// This callback will not be invoked when the current user is added to a lobby, instead the
	/// LobbyCreated callback will be invoked. Additionally, the SDK separates membership in a lobby
	/// from whether a user is connected to a lobby. So a user being added does not necessarily mean
	/// they are online and in the lobby at that moment, just that they have permission to connect
	/// to that lobby.
	void SetLobbyMemberAddedCallback(discordpp::Client::LobbyMemberAddedCallback cb);

	/// \brief Sets a callback function to be invoked whenever a member of a lobby is removed and
	/// can no longer connect to it.
	/// This callback will not be invoked when the current user is removed from a lobby, instead
	/// LobbyDeleted callback will be invoked. Additionally this is not invoked when a user simply
	/// exits the game. That would cause the LobbyMemberUpdatedCallback to be invoked, and the
	/// LobbyMemberHandle object will indicate they are not connected now.
	void SetLobbyMemberRemovedCallback(discordpp::Client::LobbyMemberRemovedCallback cb);

	/// \brief Sets a callback function to be invoked whenever a member of a lobby is changed.
	/// This is invoked when:
	/// - The user connects or disconnects
	/// - The metadata of the member is changed
	void SetLobbyMemberUpdatedCallback(discordpp::Client::LobbyMemberUpdatedCallback cb);

	/// \brief Sets a callback to be invoked when a lobby is edited, for example if the lobby's
	/// metadata is changed.
	void SetLobbyUpdatedCallback(discordpp::Client::LobbyUpdatedCallback cb);

	/// \brief Removes any existing channel link from the specified lobby.
	/// See the docs on LobbyHandle for more information.
	/// A lobby can be unlinked by any user with the LobbyMemberFlags::CanLinkLobby flag, they do
	/// not need to have any permissions on the Discord channel in order to sever the in-game link.
	void UnlinkChannelFromLobby(uint64_t lobbyId,
			discordpp::Client::LinkOrUnlinkChannelCallback callback);


	/// \brief Accepts an activity invite that the current user has received.
	/// The given callback will be invoked with the join secret for the activity, which can be used
	/// to join the user to the game's internal party system for example.
	/// This join secret comes from the other user's rich presence activity.
	void AcceptActivityInvite(discordpp::ActivityInvite invite,
			discordpp::Client::AcceptActivityInviteCallback cb);

	/// \brief Clears the right presence for the current user.
	void ClearRichPresence();

	/// \brief When a user accepts an activity invite for your game within the Discord client,
	/// Discord needs to know how to launch the game for that user. This function allows you to
	/// register a command that Discord will run to launch your game. You should invoke this when
	/// the SDK starts up so that if the user in the future tries to join from Discord the game will
	/// be able to be launched for them. Returns true if the command was successfully registered,
	/// false otherwise.
	/// On Windows and Linux, this command should be a path to an executable. It also supports any
	/// launch parameters that may be needed, like
	/// "C:\path\to my\game.exe" --full-screen --no-hax
	/// If you pass an empty string in for the command, the SDK will register the current running
	/// executable. To launch the game from a custom protocol like my-awesome-game://, pass that in
	/// as an argument of the executable that should be launched by that protocol. For example,
	/// "C:\path\to my\game.exe" my-awesome-game://
	/// On macOS, due to the way Discord registers executables, your game needs to be bundled for
	/// this command to work. That means it should be a .app. You can pass a custom protocol like
	/// my-awesome-game:// as the custom command, but *not* a path to an executable. If you pass an
	/// empty string in for the command, the SDK will register the current running bundle, if any.
	bool RegisterLaunchCommand(uint64_t applicationId, std::string command);

	/// \brief When a user accepts an activity invite for your game within the Discord client,
	/// Discord needs to know how to launch the game for that user. For steam games, this function
	/// allows you to indicate to Discord what the steam game ID is. You should invoke this when the
	/// SDK starts up so that if the user in the future tries to join from Discord the game will be
	/// able to be launched for them. Returns true if the command was successfully registered, false
	/// otherwise.
	bool RegisterLaunchSteamApplication(uint64_t applicationId, uint32_t steamAppId);

	/// \brief Sends a Discord activity invite to the specified user.
	/// The invite is sent as a message on Discord, which means it can be sent in the following
	/// situations:
	/// - Both users are online and in the game and have not blocked each other
	/// - Both users are friends with each other
	/// - Both users share a mutual Discord server and have previously DM'd each other on Discord
	/// You can optionally include some message content to include in the message containing the
	/// invite, but it's ok to pass an empty string too.
	void SendActivityInvite(uint64_t userId,
			std::string const &content,
			discordpp::Client::SendActivityInviteCallback cb);

	/// \brief Requests to join the activity of the specified user.
	/// This can be called whenever the target user has a rich presence activity for the current
	/// game and that activity has space for another user to join them.
	/// That user will basically receive an activity invite which they can accept or reject.
	void SendActivityJoinRequest(uint64_t userId, discordpp::Client::SendActivityInviteCallback cb);

	/// \brief When another user requests to join the current user's party, this function is called
	/// to to allow that user to join. Specifically this will send the original user an activity
	/// invite which they then need to accept again.
	void SendActivityJoinRequestReply(discordpp::ActivityInvite invite,
			discordpp::Client::SendActivityInviteCallback cb);

	/// \brief Sets a callback function that is invoked when the current user receives an activity
	/// invite from another user.
	/// These invites are always sent as messages, so the SDK is parsing these
	/// messages to look for invites and invokes this callback instead. The message create callback
	/// will not be invoked for these messages. The invite object contains all the necessary
	/// information to identity the invite, which you can later pass to
	/// Client::AcceptActivityInvite.
	void SetActivityInviteCreatedCallback(discordpp::Client::ActivityInviteCallback cb);

	/// \brief Sets a callback function that is invoked when an existing activity invite changes.
	/// Currently, the only thing that changes on an activity invite is its validity. If the sender
	/// goes offline or exits the party the receiver was invited to, the invite is no longer
	/// joinable. It is possible for an invalid invite to go from invalid to valid if the sender
	/// rejoins the activity.
	void SetActivityInviteUpdatedCallback(discordpp::Client::ActivityInviteCallback cb);

	/// \brief Sets a callback function that is invoked when the current user also has Discord
	/// running on their computer and they accept an activity invite in the Discord client.
	/// This callback is invoked with the join secret from the activity rich presence, which you can
	/// use to join them to the game's internal party system. See Activity for more information on
	/// invites.
	void SetActivityJoinCallback(discordpp::Client::ActivityJoinCallback cb);

	/// \brief Sets a callback function that is invoked when the current user also has Discord
	/// running on their computer and they accept an activity invite in the Discord client.
	/// This callback is invoked with the join secret from the activity rich presence, which you can
	/// use to join them to the game's internal party system. See Activity for more information on
	/// invites.
	void SetActivityJoinWithApplicationCallback(
			discordpp::Client::ActivityJoinWithApplicationCallback cb);

	/// \brief Sets whether a user is online/invisible/idle/dnd on Discord.
	void SetOnlineStatus(discordpp::StatusType status,
			discordpp::Client::UpdateStatusCallback callback);

	/// \brief Updates the rich presence for the current user.
	/// You should use rich presence so that other users on Discord know this user is playing a game
	/// and you can include some hints of what they are playing such as a character name or map
	/// name. Rich presence also enables Discord game invites to work too!
	/// Note: On Desktop, rich presence can be set before calling Client::Connect, but it will be
	/// cleared if the Client connects. When Client is not connected, this sets the rich presence in
	/// the current user's Discord client when available.
	/// See the docs on the Activity struct for more details.
	/// Note: The Activity object here is a partial object, fields such as name, and applicationId
	/// cannot be set and will be overwritten by the SDK. See
	/// https://discord.com/developers/docs/rich-presence/using-with-the-game-sdk#partial-activity-struct
	/// for more information.
	void UpdateRichPresence(discordpp::Activity activity,
			discordpp::Client::UpdateRichPresenceCallback cb);


	/// \brief Accepts an incoming Discord friend request from the target user.
	/// Fails if the target user has not sent a Discord friend request to the current user, meaning
	/// that the Discord relationship type between the users must be
	/// RelationshipType::PendingIncoming.
	void AcceptDiscordFriendRequest(uint64_t userId,
			discordpp::Client::UpdateRelationshipCallback cb);

	/// \brief Accepts an incoming game friend request from the target user.
	/// Fails if the target user has not sent a game friend request to the current user, meaning
	/// that the game relationship type between the users must be RelationshipType::PendingIncoming.
	void AcceptGameFriendRequest(uint64_t userId, discordpp::Client::UpdateRelationshipCallback cb);

	/// \brief Blocks the target user so that they cannot send the user friend or activity invites
	/// and cannot message them anymore.
	/// Blocking a user will also remove any existing relationship
	/// between the two users, and persists across games, so blocking a user in one game or on
	/// Discord will block them in all other games and on Discord as well.
	void BlockUser(uint64_t userId, discordpp::Client::UpdateRelationshipCallback cb);

	/// \brief Cancels an outgoing Discord friend request to the target user.
	/// Fails if a Discord friend request has not been sent to the target user, meaning
	/// that the Discord relationship type between the users must be
	/// RelationshipType::PendingOutgoing.
	void CancelDiscordFriendRequest(uint64_t userId,
			discordpp::Client::UpdateRelationshipCallback cb);

	/// \brief Cancels an outgoing game friend request to the target user.
	/// Fails if a game friend request has not been sent to the target user, meaning
	/// that the game relationship type between the users must be RelationshipType::PendingOutgoing.
	void CancelGameFriendRequest(uint64_t userId, discordpp::Client::UpdateRelationshipCallback cb);

	/// \brief Returns the RelationshipHandle that corresponds to the relationship between the
	/// current user and the given user.
	discordpp::RelationshipHandle GetRelationshipHandle(uint64_t userId) const;

	/// \brief Returns a list of all of the relationships the current user has with others,
	/// including all Discord relationships and all Game relationships for the current game.
	std::vector<discordpp::RelationshipHandle> GetRelationships() const;

	/// \brief Returns a list of relationships that belong to the specified relationship group type.
	/// Relationships are logically partitioned into groups based on online status and game
	/// activity:
	/// - OnlinePlayingGame: Users who are online and currently playing the game
	/// - OnlineElsewhere: Users who are online but not playing the game (users who have played the
	/// game before are sorted to the top)
	/// - Offline: Users who are offline
	std::vector<discordpp::RelationshipHandle> GetRelationshipsByGroup(
			discordpp::RelationshipGroupType groupType) const;

	/// \brief Declines an incoming Discord friend request from the target user.
	/// Fails if the target user has not sent a Discord friend request to the current user, meaning
	/// that the Discord relationship type between the users must be
	/// RelationshipType::PendingIncoming.
	void RejectDiscordFriendRequest(uint64_t userId,
			discordpp::Client::UpdateRelationshipCallback cb);

	/// \brief Declines an incoming game friend request from the target user.
	/// Fails if the target user has not sent a game friend request to the current user, meaning
	/// that the game relationship type between the users must be RelationshipType::PendingIncoming.
	void RejectGameFriendRequest(uint64_t userId, discordpp::Client::UpdateRelationshipCallback cb);

	/// \brief Removes any friendship between the current user and the target user. This function
	/// will remove BOTH any Discord friendship and any game friendship between the users.
	/// Fails if the target user is not currently a Discord OR game friend with the current user.
	void RemoveDiscordAndGameFriend(uint64_t userId,
			discordpp::Client::UpdateRelationshipCallback cb);

	/// \brief Removes any game friendship between the current user and the target user.
	/// Fails if the target user is not currently a game friend with the current user.
	void RemoveGameFriend(uint64_t userId, discordpp::Client::UpdateRelationshipCallback cb);

	/// \brief Searches all of your friends by both username and display name, returning
	/// a list of all friends that match the search string.
	/// Under the hood uses the Levenshtein distance algorithm.
	std::vector<discordpp::UserHandle> SearchFriendsByUsername(std::string searchStr) const;

	/// \brief Sends a Discord friend request to the target user.
	/// The target user is identified by their Discord unique username (not their DisplayName).
	/// After the friend request is sent, each user will have a new Discord relationship created.
	/// For the current user the RelationshipHandle::DiscordRelationshipType will be
	/// RelationshipType::PendingOutgoing and for the target user it will be
	/// RelationshipType::PendingIncoming.
	/// If the current user already has received a Discord friend request from the target user
	/// (meaning RelationshipHandle::DiscordRelationshipType is RelationshipType::PendingIncoming),
	/// then the two users will become Discord friends.
	/// See RelationshipHandle for more information on the difference between Discord and Game
	/// relationships.
	void SendDiscordFriendRequest(std::string const &username,
			discordpp::Client::SendFriendRequestCallback cb);

	/// \brief Sends a Discord friend request to the target user.
	/// The target user is identified by their Discord ID.
	/// After the friend request is sent, each user will have a new Discord relationship created.
	/// For the current user the RelationshipHandle::DiscordRelationshipType will be
	/// RelationshipType::PendingOutgoing and for the target user it will be
	/// RelationshipType::PendingIncoming.
	/// If the current user already has received a Discord friend request from the target user
	/// (meaning RelationshipHandle::DiscordRelationshipType is RelationshipType::PendingIncoming),
	/// then the two users will become Discord friends.
	/// See RelationshipHandle for more information on the difference between Discord and Game
	/// relationships.
	void SendDiscordFriendRequestById(uint64_t userId,
			discordpp::Client::UpdateRelationshipCallback cb);

	/// \brief Sends (or accepts) a game friend request to the target user.
	/// The target user is identified by their Discord unique username (not their DisplayName).
	/// After the friend request is sent, each user will have a new game relationship created. For
	/// the current user the RelationshipHandle::GameRelationshipType will be
	/// RelationshipType::PendingOutgoing and for the target user it will be
	/// RelationshipType::PendingIncoming.
	/// If the current user already has received a game friend request from the target user
	/// (meaning RelationshipHandle::GameRelationshipType is RelationshipType::PendingIncoming),
	/// then the two users will become game friends.
	/// See RelationshipHandle for more information on the difference between Discord and Game
	/// relationships.
	void SendGameFriendRequest(std::string const &username,
			discordpp::Client::SendFriendRequestCallback cb);

	/// \brief Sends (or accepts) a game friend request to the target user.
	/// The target user is identified by their Discord ID.
	/// After the friend request is sent, each user will have a new game relationship created. For
	/// the current user the RelationshipHandle::GameRelationshipType will be
	/// RelationshipType::PendingOutgoing and for the target user it will be
	/// RelationshipType::PendingIncoming.
	/// If the current user already has received a game friend request from the target user
	/// (meaning RelationshipHandle::GameRelationshipType is RelationshipType::PendingIncoming),
	/// then the two users will become game friends.
	/// See RelationshipHandle for more information on the difference between Discord and Game
	/// relationships.
	void SendGameFriendRequestById(uint64_t userId,
			discordpp::Client::UpdateRelationshipCallback cb);

	/// \brief Sets a callback to be invoked whenever a relationship for this user is established or
	/// changes type.
	/// This can be invoked when a user sends or accepts a friend invite or blocks a user for
	/// example.
	void SetRelationshipCreatedCallback(discordpp::Client::RelationshipCreatedCallback cb);

	/// \brief Sets a callback to be invoked whenever a relationship for this user is removed,
	/// such as when the user rejects a friend request or removes a friend.
	/// When a relationship is removed, Client::GetRelationshipHandle will
	/// return a relationship with the type set to RelationshipType::None.
	void SetRelationshipDeletedCallback(discordpp::Client::RelationshipDeletedCallback cb);

	/// \brief Unblocks the target user. Does not restore any old relationship between the users
	/// though.
	/// Fails if the target user is not currently blocked.
	void UnblockUser(uint64_t userId, discordpp::Client::UpdateRelationshipCallback cb);


	/// \brief Returns the user associated with the current client.
	/// **Must not be called before the Client::GetStatus has changed to Status::Ready.**
	/// If the client has disconnected, or is in the process of reconnecting, it will return the
	/// previous value of the user, even if the auth token has changed since then. Wait for
	/// client.GetStatus() to change to Ready before accessing it again.
	/// If accessed before the client is ready, it will return a dummy object.
	discordpp::UserHandle GetCurrentUser() const;

	/// \brief Returns the UserHandle associated with the current user, if one is available.
	/// Unlike GetCurrentUser(), this method returns std::nullopt instead of a dummy object
	/// when no user is authenticated or available. This provides clearer intent about when
	/// the user data is actually available.
	std::optional<discordpp::UserHandle> GetCurrentUserV2() const;

	/// \brief If the Discord app is running on the user's computer and the SDK establishes a
	/// connection to it, this function will return the user that is currently logged in to the
	/// Discord app.
	void GetDiscordClientConnectedUser(
			uint64_t applicationId,
			discordpp::Client::GetDiscordClientConnectedUserCallback callback) const;

	/// \brief Returns the UserHandle associated with the given user ID.
	/// It will not fetch a user from Discord's API if it is not available. Generally you can trust
	/// that users will be available for all relationships and for the authors of any messages
	/// received.
	std::optional<discordpp::UserHandle> GetUser(uint64_t userId) const;

	/// \brief The RelationshipGroupsUpdatedCallback is invoked whenever any user in the friends
	/// list changes. This is intended to be the callback used to ensure the friends list is kept
	/// fresh. This can be used in tandem with Client::GetRelationshipsByGroup to build and update
	/// the friends list.
	void SetRelationshipGroupsUpdatedCallback(
			discordpp::Client::RelationshipGroupsUpdatedCallback cb);

	/// \brief The UserUpdatedCallback is invoked whenever *any* user the current session knows
	/// about changes, not just if the current user changes. For example if one of your Discord
	/// friends changes their name or avatar the UserUpdatedCallback will be invoked. It is also
	/// invoked when users come online, go offline, or start playing your game.
	void SetUserUpdatedCallback(discordpp::Client::UserUpdatedCallback cb);
};

/// \brief Convenience class that represents the state of a single Discord call in a lobby.
class CallInfoHandle {

	/// Copy constructor for CallInfoHandle
	CallInfoHandle(const CallInfoHandle &other);

	void Drop();

	/// \brief Returns the lobby ID of the call.
	uint64_t ChannelId() const;

	/// \brief Returns a list of the user IDs of the participants in the call.
	std::vector<uint64_t> GetParticipants() const;

	/// \brief Accesses the voice state for a single user so you can know if they have muted or
	/// deafened themselves.
	std::optional<discordpp::VoiceStateHandle> GetVoiceStateHandle(uint64_t userId) const;

	/// \brief Returns the lobby ID of the call.
	uint64_t GuildId() const;
};
/// Converts a discordpp::ActivityActionTypes to a string.
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
/// Converts a discordpp::ActivityPartyPrivacy to a string.
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
/// Converts a discordpp::ActivityTypes to a string.
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
/// Converts a discordpp::StatusDisplayTypes to a string.
inline const char *EnumToString(discordpp::StatusDisplayTypes value) {
	switch (value) {
		case discordpp::StatusDisplayTypes::Name:
			return "Name";
		case discordpp::StatusDisplayTypes::State:
			return "State";
		case discordpp::StatusDisplayTypes::Details:
			return "Details";
		default:
			return "unknown";
	}
}
/// Converts a discordpp::ActivityGamePlatforms to a string.
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
/// Converts a discordpp::ErrorType to a string.
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
/// Converts a discordpp::HttpStatusCode to a string.
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
/// Converts a discordpp::AuthenticationCodeChallengeMethod to a string.
inline const char *EnumToString(discordpp::AuthenticationCodeChallengeMethod value) {
	switch (value) {
		case discordpp::AuthenticationCodeChallengeMethod::S256:
			return "S256";
		default:
			return "unknown";
	}
}
/// Converts a discordpp::IntegrationType to a string.
inline const char *EnumToString(discordpp::IntegrationType value) {
	switch (value) {
		case discordpp::IntegrationType::GuildInstall:
			return "GuildInstall";
		case discordpp::IntegrationType::UserInstall:
			return "UserInstall";
		default:
			return "unknown";
	}
}
/// Converts a discordpp::AdditionalContentType to a string.
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
/// Converts a discordpp::AudioSystem to a string.
inline const char *EnumToString(discordpp::AudioSystem value) {
	switch (value) {
		case discordpp::AudioSystem::Standard:
			return "Standard";
		case discordpp::AudioSystem::Game:
			return "Game";
		default:
			return "unknown";
	}
}
/// Converts a discordpp::Call::Error to a string.
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
/// Converts a discordpp::AudioModeType to a string.
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
/// Converts a discordpp::Call::Status to a string.
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
/// Converts a discordpp::ChannelType to a string.
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
/// Converts a discordpp::RelationshipType to a string.
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
/// Converts a discordpp::UserHandle::AvatarType to a string.
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
/// Converts a discordpp::StatusType to a string.
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
/// Converts a discordpp::DisclosureTypes to a string.
inline const char *EnumToString(discordpp::DisclosureTypes value) {
	switch (value) {
		case discordpp::DisclosureTypes::MessageDataVisibleOnDiscord:
			return "MessageDataVisibleOnDiscord";
		default:
			return "unknown";
	}
}
/// Converts a discordpp::Client::Error to a string.
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
/// Converts a discordpp::Client::Status to a string.
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
/// Converts a discordpp::Client::Thread to a string.
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
/// Converts a discordpp::AuthorizationTokenType to a string.
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
/// Converts a discordpp::AuthenticationExternalAuthType to a string.
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
		case discordpp::AuthenticationExternalAuthType::UnityServicesIdToken:
			return "UnityServicesIdToken";
		default:
			return "unknown";
	}
}
/// Converts a discordpp::LoggingSeverity to a string.
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
/// Converts a discordpp::RelationshipGroupType to a string.
inline const char *EnumToString(discordpp::RelationshipGroupType value) {
	switch (value) {
		case discordpp::RelationshipGroupType::OnlinePlayingGame:
			return "OnlinePlayingGame";
		case discordpp::RelationshipGroupType::OnlineElsewhere:
			return "OnlineElsewhere";
		case discordpp::RelationshipGroupType::Offline:
			return "Offline";
		default:
			return "unknown";
	}
}