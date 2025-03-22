#ifndef DISCORD_ENUM_H
#define DISCORD_ENUM_H

#include <discordpp.h>
#include <godot_cpp/classes/ref_counted.hpp>
#include <godot_cpp/classes/wrapped.hpp>

namespace godot {

class DiscordEnum : public RefCounted {
	GDCLASS(DiscordEnum, RefCounted)

private:
protected:
	static void _bind_methods() {};

public:
	enum class ActivityActionTypes {
		JOIN = 1,
		JOIN_REQUEST = 5,
	};

	enum class ActivityPartyPrivacy {
		PRIVATE = 0,
		PUBLIC = 1,
	};

	enum class activity_types {
		PLAYING = 0,
		STREAMING = 1,
		LISTENING = 2,
		WATCHING = 3,
		CUSTOM_STATUS = 4,
		COMPETING = 5,
		HANG_STATUS = 6,
	};

	enum class ActivityGamePlatforms {
		DESKTOP = 1,
		XBOX = 2,
		SAMSUNG = 4,
		IOS = 8,
		ANDROID = 16,
		EMBEDDED = 32,
		PS4 = 64,
		PS5 = 128,
	};

	enum class ErrorType {
		NONE = 0,
		NETWORK_ERROR = 1,
		HTTP_ERROR = 2,
		CLIENT_NOT_READY = 3,
		DISABLED = 4,
		CLIENT_DESTROYED = 5,
		VALIDATION_ERROR = 6,
		ABORTED = 7,
		AUTHORIZATION_FAILED = 8,
		RPC_ERROR = 9,
	};

	enum class HttpStatusCode {
		NONE = 0,
		CONTINUE = 100,
		SWITCHING_PROTOCOLS = 101,
		PROCESSING = 102,
		EARLY_HINTS = 103,
		OK = 200,
		CREATED = 201,
		ACCEPTED = 202,
		NON_AUTHORITATIVE_INFO = 203,
		NO_CONTENT = 204,
		RESET_CONTENT = 205,
		PARTIAL_CONTENT = 206,
		MULTI_STATUS = 207,
		ALREADY_REPORTED = 208,
		IM_USED = 209,
		MULTIPLE_CHOICES = 300,
		MOVED_PERMANENTLY = 301,
		FOUND = 302,
		SEE_OTHER = 303,
		NOT_MODIFIED = 304,
		TEMPORARY_REDIRECT = 307,
		PERMANENT_REDIRECT = 308,
		BAD_REQUEST = 400,
		UNAUTHORIZED = 401,
		PAYMENT_REQUIRED = 402,
		FORBIDDEN = 403,
		NOT_FOUND = 404,
		METHOD_NOT_ALLOWED = 405,
		NOT_ACCEPTABLE = 406,
		PROXY_AUTH_REQUIRED = 407,
		REQUEST_TIMEOUT = 408,
		CONFLICT = 409,
		GONE = 410,
		LENGTH_REQUIRED = 411,
		PRECONDITION_FAILED = 412,
		PAYLOAD_TOO_LARGE = 413,
		URI_TOO_LONG = 414,
		UNSUPPORTED_MEDIA_TYPE = 415,
		RANGE_NOT_SATISFIABLE = 416,
		EXPECTATION_FAILED = 417,
		MISDIRECTED_REQUEST = 421,
		UNPROCESSABLE_ENTITY = 422,
		LOCKED = 423,
		FAILED_DEPENDENCY = 424,
		TOO_EARLY = 425,
		UPGRADE_REQUIRED = 426,
		PRECONDITION_REQUIRED = 428,
		TOO_MANY_REQUESTS = 429,
		REQUEST_HEADER_FIELDS_TOO_LARGE = 431,
		INTERNAL_SERVER_ERROR = 500,
		NOT_IMPLEMENTED = 501,
		BAD_GATEWAY = 502,
		SERVICE_UNAVAILABLE = 503,
		GATEWAY_TIMEOUT = 504,
		HTTP_VERSION_NOT_SUPPORTED = 505,
		VARIANT_ALSO_NEGOTIATES = 506,
		INSUFFICIENT_STORAGE = 507,
		LOOP_DETECTED = 508,
		NOT_EXTENDED = 510,
		NETWORK_AUTHORIZATION_REQUIRED = 511,
	};

	enum class AuthenticationCodeChallengeMethod {
		S256 = 0,
	};

	enum class AdditionalContentType {
		OTHER = 0,
		ATTACHMENT = 1,
		POLL = 2,
		VOICE_MESSAGE = 3,
		THREAD = 4,
		EMBED = 5,
		STICKER = 6,
	};

	enum class Call_Error {
		NONE = 0,
		SIGNALING_CONNECTION_FAILED = 1,
		SIGNALING_UNEXPECTED_CLOSE = 2,
		VOICE_CONNECTION_FAILED = 3,
		JOIN_TIMEOUT = 4,
		FORBIDDEN = 5,
	};

	enum class AudioModeType {
		MODE_UNINIT = 0,
		MODE_VAD = 1,
		MODE_PTT = 2,
	};

	enum class Call_Status {
		DISCONNECTED = 0,
		JOINING = 1,
		CONNECTING = 2,
		SIGNALING_CONNECTED = 3,
		CONNECTED = 4,
		RECONNECTING = 5,
		DISCONNECTING = 6,
	};

	enum class ChannelType {
		GUILD_TEXT = 0,
		DM = 1,
		GUILD_VOICE = 2,
		GROUP_DM = 3,
		GUILD_CATEGORY = 4,
		GUILD_NEWS = 5,
		GUILD_STORE = 6,
		GUILD_NEWS_THREAD = 10,
		GUILD_PUBLIC_THREAD = 11,
		GUILD_PRIVATE_THREAD = 12,
		GUILD_STAGE_VOICE = 13,
		GUILD_DIRECTORY = 14,
		GUILD_FORUM = 15,
		GUILD_MEDIA = 16,
		LOBBY = 17,
		EPHEMERAL_DM = 18,
	};

	enum class RelationshipType {
		NONE = 0,
		FRIEND = 1,
		BLOCKED = 2,
		PENDING_INCOMING = 3,
		PENDING_OUTGOING = 4,
		IMPLICIT = 5,
		SUGGESTION = 6,
	};

	enum class UserHandle_AvatarType {
		GIF = 0,
		WEBP = 1,
		PNG = 2,
		JPEG = 3,
	};

	enum class StatusType {
		ONLINE = 0,
		OFFLINE = 1,
		BLOCKED = 2,
		IDLE = 3,
		DND = 4,
		INVISIBLE = 5,
		STREAMING = 6,
		UNKNOWN = 7,
	};

	enum class DisclosureTypes {
		MESSAGE_DATA_VISIBLE_ON_DISCORD = 3,
	};

	enum class Client_Error {
		NONE = 0,
		CONNECTION_FAILED = 1,
		UNEXPECTED_CLOSE = 2,
		CONNECTION_CANCELED = 3,
	};

	enum class Client_Status {
		DISCONNECTED = 0,
		CONNECTING = 1,
		CONNECTED = 2,
		READY = 3,
		RECONNECTING = 4,
		DISCONNECTING = 5,
		HTTP_WAIT = 6,
	};

	enum class Client_Thread {
		CLIENT = 0,
		VOICE = 1,
		NETWORK = 2,
	};

	enum class AuthorizationTokenType {
		USER = 0,
		BEARER = 1,
	};

	enum class AuthenticationExternalAuthType {
		OIDC = 0,
		EPIC_ONLINE_SERVICES_ACCESS_TOKEN = 1,
		EPIC_ONLINE_SERVICES_ID_TOKEN = 2,
		STEAM_SESSION_TICKET = 3,
	};

	enum class LoggingSeverity {
		VERBOSE = 1,
		INFO = 2,
		WARNING = 3,
		ERROR = 4,
		NONE = 5,
	};
};

} // namespace godot

#endif
