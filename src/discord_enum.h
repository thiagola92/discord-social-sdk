
#ifndef DISCORD_ENUM_H
#define DISCORD_ENUM_H

#include "godot_cpp/classes/ref_counted.hpp"
#include "godot_cpp/classes/wrapped.hpp"
#include "godot_cpp/core/binder_common.hpp"
#include "godot_cpp/core/class_db.hpp"

namespace godot {

// Enums.

class DiscordActivityActionTypes : public RefCounted {
	GDCLASS(DiscordActivityActionTypes, RefCounted)

private:
	DiscordActivityActionTypes() {}
	~DiscordActivityActionTypes() {}

protected:
	static void _bind_methods() {
		// Enums binds.
		BIND_ENUM_CONSTANT(INVALID);
		BIND_ENUM_CONSTANT(JOIN);
		BIND_ENUM_CONSTANT(JOIN_REQUEST);

		// Constant binds.
		BIND_CONSTANT(id);
	}

public:
	static const int64_t id = 0;

	enum Enum {
		INVALID = 0,
		JOIN = 1,
		JOIN_REQUEST = 5,
	};
};

class DiscordActivityGamePlatforms : public RefCounted {
	GDCLASS(DiscordActivityGamePlatforms, RefCounted)

private:
	DiscordActivityGamePlatforms() {}
	~DiscordActivityGamePlatforms() {}

protected:
	static void _bind_methods() {
		// Enums binds.
		BIND_ENUM_CONSTANT(DESKTOP);
		BIND_ENUM_CONSTANT(XBOX);
		BIND_ENUM_CONSTANT(SAMSUNG);
		BIND_ENUM_CONSTANT(IOS);
		BIND_ENUM_CONSTANT(ANDROID);
		BIND_ENUM_CONSTANT(EMBEDDED);
		BIND_ENUM_CONSTANT(PS4);
		BIND_ENUM_CONSTANT(PS5);

		// Constant binds.
		BIND_CONSTANT(id);
	}

public:
	static const int64_t id = 4;

	enum Enum {
		DESKTOP = 1,
		XBOX = 2,
		SAMSUNG = 4,
		IOS = 8,
		ANDROID = 16,
		EMBEDDED = 32,
		PS4 = 64,
		PS5 = 128,
	};
};

class DiscordActivityPartyPrivacy : public RefCounted {
	GDCLASS(DiscordActivityPartyPrivacy, RefCounted)

private:
	DiscordActivityPartyPrivacy() {}
	~DiscordActivityPartyPrivacy() {}

protected:
	static void _bind_methods() {
		// Enums binds.
		BIND_ENUM_CONSTANT(PRIVATE);
		BIND_ENUM_CONSTANT(PUBLIC);

		// Constant binds.
		BIND_CONSTANT(id);
	}

public:
	static const int64_t id = 1;

	enum Enum {
		PRIVATE = 0,
		PUBLIC = 1,
	};
};

class DiscordActivityTypes : public RefCounted {
	GDCLASS(DiscordActivityTypes, RefCounted)

private:
	DiscordActivityTypes() {}
	~DiscordActivityTypes() {}

protected:
	static void _bind_methods() {
		// Enums binds.
		BIND_ENUM_CONSTANT(PLAYING);
		BIND_ENUM_CONSTANT(STREAMING);
		BIND_ENUM_CONSTANT(LISTENING);
		BIND_ENUM_CONSTANT(WATCHING);
		BIND_ENUM_CONSTANT(CUSTOM_STATUS);
		BIND_ENUM_CONSTANT(COMPETING);
		BIND_ENUM_CONSTANT(HANG_STATUS);

		// Constant binds.
		BIND_CONSTANT(id);
	}

public:
	static const int64_t id = 2;

	enum Enum {
		PLAYING = 0,
		STREAMING = 1,
		LISTENING = 2,
		WATCHING = 3,
		CUSTOM_STATUS = 4,
		COMPETING = 5,
		HANG_STATUS = 6,
	};
};

class DiscordAdditionalContentType : public RefCounted {
	GDCLASS(DiscordAdditionalContentType, RefCounted)

private:
	DiscordAdditionalContentType() {}
	~DiscordAdditionalContentType() {}

protected:
	static void _bind_methods() {
		// Enums binds.
		BIND_ENUM_CONSTANT(OTHER);
		BIND_ENUM_CONSTANT(ATTACHMENT);
		BIND_ENUM_CONSTANT(POLL);
		BIND_ENUM_CONSTANT(VOICE_MESSAGE);
		BIND_ENUM_CONSTANT(THREAD);
		BIND_ENUM_CONSTANT(EMBED);
		BIND_ENUM_CONSTANT(STICKER);

		// Constant binds.
		BIND_CONSTANT(id);
	}

public:
	static const int64_t id = 10;

	enum Enum {
		OTHER = 0,
		ATTACHMENT = 1,
		POLL = 2,
		VOICE_MESSAGE = 3,
		THREAD = 4,
		EMBED = 5,
		STICKER = 6,
	};
};

class DiscordAudioModeType : public RefCounted {
	GDCLASS(DiscordAudioModeType, RefCounted)

private:
	DiscordAudioModeType() {}
	~DiscordAudioModeType() {}

protected:
	static void _bind_methods() {
		// Enums binds.
		BIND_ENUM_CONSTANT(MODE_UNINIT);
		BIND_ENUM_CONSTANT(MODE_VAD);
		BIND_ENUM_CONSTANT(MODE_PTT);

		// Constant binds.
		BIND_CONSTANT(id);
	}

public:
	static const int64_t id = 12;

	enum Enum {
		MODE_UNINIT = 0,
		MODE_VAD = 1,
		MODE_PTT = 2,
	};
};

class DiscordAudioSystem : public RefCounted {
	GDCLASS(DiscordAudioSystem, RefCounted)

private:
	DiscordAudioSystem() {}
	~DiscordAudioSystem() {}

protected:
	static void _bind_methods() {
		// Enums binds.
		BIND_ENUM_CONSTANT(STANDARD);
		BIND_ENUM_CONSTANT(GAME);

		// Constant binds.
		BIND_CONSTANT(id);
	}

public:
	static const int64_t id = 11;

	enum Enum {
		STANDARD = 0,
		GAME = 1,
	};
};

class DiscordAuthenticationCodeChallengeMethod : public RefCounted {
	GDCLASS(DiscordAuthenticationCodeChallengeMethod, RefCounted)

private:
	DiscordAuthenticationCodeChallengeMethod() {}
	~DiscordAuthenticationCodeChallengeMethod() {}

protected:
	static void _bind_methods() {
		// Enums binds.
		BIND_ENUM_CONSTANT(S256);

		// Constant binds.
		BIND_CONSTANT(id);
	}

public:
	static const int64_t id = 7;

	enum Enum {
		S256 = 0,
	};
};

class DiscordAuthenticationExternalAuthType : public RefCounted {
	GDCLASS(DiscordAuthenticationExternalAuthType, RefCounted)

private:
	DiscordAuthenticationExternalAuthType() {}
	~DiscordAuthenticationExternalAuthType() {}

protected:
	static void _bind_methods() {
		// Enums binds.
		BIND_ENUM_CONSTANT(OIDC);
		BIND_ENUM_CONSTANT(EPIC_ONLINE_SERVICES_ACCESS_TOKEN);
		BIND_ENUM_CONSTANT(EPIC_ONLINE_SERVICES_ID_TOKEN);
		BIND_ENUM_CONSTANT(STEAM_SESSION_TICKET);
		BIND_ENUM_CONSTANT(UNITY_SERVICES_ID_TOKEN);
		BIND_ENUM_CONSTANT(DISCORD_BOT_ISSUED_ACCESS_TOKEN);
		BIND_ENUM_CONSTANT(APPLE_ID_TOKEN);
		BIND_ENUM_CONSTANT(PLAY_STATION_NETWORK_ID_TOKEN);

		// Constant binds.
		BIND_CONSTANT(id);
	}

public:
	static const int64_t id = 18;

	enum Enum {
		OIDC = 0,
		EPIC_ONLINE_SERVICES_ACCESS_TOKEN = 1,
		EPIC_ONLINE_SERVICES_ID_TOKEN = 2,
		STEAM_SESSION_TICKET = 3,
		UNITY_SERVICES_ID_TOKEN = 4,
		DISCORD_BOT_ISSUED_ACCESS_TOKEN = 5,
		APPLE_ID_TOKEN = 6,
		PLAY_STATION_NETWORK_ID_TOKEN = 7,
	};
};

class DiscordAuthorizationTokenType : public RefCounted {
	GDCLASS(DiscordAuthorizationTokenType, RefCounted)

private:
	DiscordAuthorizationTokenType() {}
	~DiscordAuthorizationTokenType() {}

protected:
	static void _bind_methods() {
		// Enums binds.
		BIND_ENUM_CONSTANT(USER);
		BIND_ENUM_CONSTANT(BEARER);

		// Constant binds.
		BIND_CONSTANT(id);
	}

public:
	static const int64_t id = 17;

	enum Enum {
		USER = 0,
		BEARER = 1,
	};
};

class DiscordCallError : public RefCounted {
	GDCLASS(DiscordCallError, RefCounted)

private:
	DiscordCallError() {}
	~DiscordCallError() {}

protected:
	static void _bind_methods() {
		// Enums binds.
		BIND_ENUM_CONSTANT(NONE);
		BIND_ENUM_CONSTANT(SIGNALING_CONNECTION_FAILED);
		BIND_ENUM_CONSTANT(SIGNALING_UNEXPECTED_CLOSE);
		BIND_ENUM_CONSTANT(VOICE_CONNECTION_FAILED);
		BIND_ENUM_CONSTANT(JOIN_TIMEOUT);
		BIND_ENUM_CONSTANT(FORBIDDEN);

		// Constant binds.
		BIND_CONSTANT(id);
	}

public:
	static const int64_t id = 21;

	enum Enum {
		NONE = 0,
		SIGNALING_CONNECTION_FAILED = 1,
		SIGNALING_UNEXPECTED_CLOSE = 2,
		VOICE_CONNECTION_FAILED = 3,
		JOIN_TIMEOUT = 4,
		FORBIDDEN = 5,
	};
};

class DiscordCallStatus : public RefCounted {
	GDCLASS(DiscordCallStatus, RefCounted)

private:
	DiscordCallStatus() {}
	~DiscordCallStatus() {}

protected:
	static void _bind_methods() {
		// Enums binds.
		BIND_ENUM_CONSTANT(DISCONNECTED);
		BIND_ENUM_CONSTANT(JOINING);
		BIND_ENUM_CONSTANT(CONNECTING);
		BIND_ENUM_CONSTANT(SIGNALING_CONNECTED);
		BIND_ENUM_CONSTANT(CONNECTED);
		BIND_ENUM_CONSTANT(RECONNECTING);
		BIND_ENUM_CONSTANT(DISCONNECTING);

		// Constant binds.
		BIND_CONSTANT(id);
	}

public:
	static const int64_t id = 22;

	enum Enum {
		DISCONNECTED = 0,
		JOINING = 1,
		CONNECTING = 2,
		SIGNALING_CONNECTED = 3,
		CONNECTED = 4,
		RECONNECTING = 5,
		DISCONNECTING = 6,
	};
};

class DiscordChannelType : public RefCounted {
	GDCLASS(DiscordChannelType, RefCounted)

private:
	DiscordChannelType() {}
	~DiscordChannelType() {}

protected:
	static void _bind_methods() {
		// Enums binds.
		BIND_ENUM_CONSTANT(GUILD_TEXT);
		BIND_ENUM_CONSTANT(DM);
		BIND_ENUM_CONSTANT(GUILD_VOICE);
		BIND_ENUM_CONSTANT(GROUP_DM);
		BIND_ENUM_CONSTANT(GUILD_CATEGORY);
		BIND_ENUM_CONSTANT(GUILD_NEWS);
		BIND_ENUM_CONSTANT(GUILD_STORE);
		BIND_ENUM_CONSTANT(GUILD_NEWS_THREAD);
		BIND_ENUM_CONSTANT(GUILD_PUBLIC_THREAD);
		BIND_ENUM_CONSTANT(GUILD_PRIVATE_THREAD);
		BIND_ENUM_CONSTANT(GUILD_STAGE_VOICE);
		BIND_ENUM_CONSTANT(GUILD_DIRECTORY);
		BIND_ENUM_CONSTANT(GUILD_FORUM);
		BIND_ENUM_CONSTANT(GUILD_MEDIA);
		BIND_ENUM_CONSTANT(LOBBY);
		BIND_ENUM_CONSTANT(EPHEMERAL_DM);

		// Constant binds.
		BIND_CONSTANT(id);
	}

public:
	static const int64_t id = 9;

	enum Enum {
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
};

class DiscordClientError : public RefCounted {
	GDCLASS(DiscordClientError, RefCounted)

private:
	DiscordClientError() {}
	~DiscordClientError() {}

protected:
	static void _bind_methods() {
		// Enums binds.
		BIND_ENUM_CONSTANT(NONE);
		BIND_ENUM_CONSTANT(CONNECTION_FAILED);
		BIND_ENUM_CONSTANT(UNEXPECTED_CLOSE);
		BIND_ENUM_CONSTANT(CONNECTION_CANCELED);

		// Constant binds.
		BIND_CONSTANT(id);
	}

public:
	static const int64_t id = 23;

	enum Enum {
		NONE = 0,
		CONNECTION_FAILED = 1,
		UNEXPECTED_CLOSE = 2,
		CONNECTION_CANCELED = 3,
	};
};

class DiscordClientStatus : public RefCounted {
	GDCLASS(DiscordClientStatus, RefCounted)

private:
	DiscordClientStatus() {}
	~DiscordClientStatus() {}

protected:
	static void _bind_methods() {
		// Enums binds.
		BIND_ENUM_CONSTANT(DISCONNECTED);
		BIND_ENUM_CONSTANT(CONNECTING);
		BIND_ENUM_CONSTANT(CONNECTED);
		BIND_ENUM_CONSTANT(READY);
		BIND_ENUM_CONSTANT(RECONNECTING);
		BIND_ENUM_CONSTANT(DISCONNECTING);
		BIND_ENUM_CONSTANT(HTTP_WAIT);

		// Constant binds.
		BIND_CONSTANT(id);
	}

public:
	static const int64_t id = 24;

	enum Enum {
		DISCONNECTED = 0,
		CONNECTING = 1,
		CONNECTED = 2,
		READY = 3,
		RECONNECTING = 4,
		DISCONNECTING = 5,
		HTTP_WAIT = 6,
	};
};

class DiscordClientThread : public RefCounted {
	GDCLASS(DiscordClientThread, RefCounted)

private:
	DiscordClientThread() {}
	~DiscordClientThread() {}

protected:
	static void _bind_methods() {
		// Enums binds.
		BIND_ENUM_CONSTANT(CLIENT);
		BIND_ENUM_CONSTANT(VOICE);
		BIND_ENUM_CONSTANT(NETWORK);

		// Constant binds.
		BIND_CONSTANT(id);
	}

public:
	static const int64_t id = 25;

	enum Enum {
		CLIENT = 0,
		VOICE = 1,
		NETWORK = 2,
	};
};

class DiscordDisclosureTypes : public RefCounted {
	GDCLASS(DiscordDisclosureTypes, RefCounted)

private:
	DiscordDisclosureTypes() {}
	~DiscordDisclosureTypes() {}

protected:
	static void _bind_methods() {
		// Enums binds.
		BIND_ENUM_CONSTANT(MESSAGE_DATA_VISIBLE_ON_DISCORD);

		// Constant binds.
		BIND_CONSTANT(id);
	}

public:
	static const int64_t id = 16;

	enum Enum {
		MESSAGE_DATA_VISIBLE_ON_DISCORD = 3,
	};
};

class DiscordErrorType : public RefCounted {
	GDCLASS(DiscordErrorType, RefCounted)

private:
	DiscordErrorType() {}
	~DiscordErrorType() {}

protected:
	static void _bind_methods() {
		// Enums binds.
		BIND_ENUM_CONSTANT(NONE);
		BIND_ENUM_CONSTANT(NETWORK_ERROR);
		BIND_ENUM_CONSTANT(HTTPERROR);
		BIND_ENUM_CONSTANT(CLIENT_NOT_READY);
		BIND_ENUM_CONSTANT(DISABLED);
		BIND_ENUM_CONSTANT(CLIENT_DESTROYED);
		BIND_ENUM_CONSTANT(VALIDATION_ERROR);
		BIND_ENUM_CONSTANT(ABORTED);
		BIND_ENUM_CONSTANT(AUTHORIZATION_FAILED);
		BIND_ENUM_CONSTANT(RPCERROR);

		// Constant binds.
		BIND_CONSTANT(id);
	}

public:
	static const int64_t id = 5;

	enum Enum {
		NONE = 0,
		NETWORK_ERROR = 1,
		HTTPERROR = 2,
		CLIENT_NOT_READY = 3,
		DISABLED = 4,
		CLIENT_DESTROYED = 5,
		VALIDATION_ERROR = 6,
		ABORTED = 7,
		AUTHORIZATION_FAILED = 8,
		RPCERROR = 9,
	};
};

class DiscordExternalIdentityProviderType : public RefCounted {
	GDCLASS(DiscordExternalIdentityProviderType, RefCounted)

private:
	DiscordExternalIdentityProviderType() {}
	~DiscordExternalIdentityProviderType() {}

protected:
	static void _bind_methods() {
		// Enums binds.
		BIND_ENUM_CONSTANT(OIDC);
		BIND_ENUM_CONSTANT(EPIC_ONLINE_SERVICES);
		BIND_ENUM_CONSTANT(STEAM);
		BIND_ENUM_CONSTANT(UNITY);
		BIND_ENUM_CONSTANT(DISCORD_BOT);
		BIND_ENUM_CONSTANT(NONE);
		BIND_ENUM_CONSTANT(UNKNOWN);

		// Constant binds.
		BIND_CONSTANT(id);
	}

public:
	static const int64_t id = 14;

	enum Enum {
		OIDC = 0,
		EPIC_ONLINE_SERVICES = 1,
		STEAM = 2,
		UNITY = 3,
		DISCORD_BOT = 4,
		NONE = 5,
		UNKNOWN = 6,
	};
};

class DiscordHttpStatusCode : public RefCounted {
	GDCLASS(DiscordHttpStatusCode, RefCounted)

private:
	DiscordHttpStatusCode() {}
	~DiscordHttpStatusCode() {}

protected:
	static void _bind_methods() {
		// Enums binds.
		BIND_ENUM_CONSTANT(NONE);
		BIND_ENUM_CONSTANT(CONTINUE);
		BIND_ENUM_CONSTANT(SWITCHING_PROTOCOLS);
		BIND_ENUM_CONSTANT(PROCESSING);
		BIND_ENUM_CONSTANT(EARLY_HINTS);
		BIND_ENUM_CONSTANT(OK);
		BIND_ENUM_CONSTANT(CREATED);
		BIND_ENUM_CONSTANT(ACCEPTED);
		BIND_ENUM_CONSTANT(NON_AUTHORITATIVE_INFO);
		BIND_ENUM_CONSTANT(NO_CONTENT);
		BIND_ENUM_CONSTANT(RESET_CONTENT);
		BIND_ENUM_CONSTANT(PARTIAL_CONTENT);
		BIND_ENUM_CONSTANT(MULTI_STATUS);
		BIND_ENUM_CONSTANT(ALREADY_REPORTED);
		BIND_ENUM_CONSTANT(IM_USED);
		BIND_ENUM_CONSTANT(MULTIPLE_CHOICES);
		BIND_ENUM_CONSTANT(MOVED_PERMANENTLY);
		BIND_ENUM_CONSTANT(FOUND);
		BIND_ENUM_CONSTANT(SEE_OTHER);
		BIND_ENUM_CONSTANT(NOT_MODIFIED);
		BIND_ENUM_CONSTANT(TEMPORARY_REDIRECT);
		BIND_ENUM_CONSTANT(PERMANENT_REDIRECT);
		BIND_ENUM_CONSTANT(BAD_REQUEST);
		BIND_ENUM_CONSTANT(UNAUTHORIZED);
		BIND_ENUM_CONSTANT(PAYMENT_REQUIRED);
		BIND_ENUM_CONSTANT(FORBIDDEN);
		BIND_ENUM_CONSTANT(NOT_FOUND);
		BIND_ENUM_CONSTANT(METHOD_NOT_ALLOWED);
		BIND_ENUM_CONSTANT(NOT_ACCEPTABLE);
		BIND_ENUM_CONSTANT(PROXY_AUTH_REQUIRED);
		BIND_ENUM_CONSTANT(REQUEST_TIMEOUT);
		BIND_ENUM_CONSTANT(CONFLICT);
		BIND_ENUM_CONSTANT(GONE);
		BIND_ENUM_CONSTANT(LENGTH_REQUIRED);
		BIND_ENUM_CONSTANT(PRECONDITION_FAILED);
		BIND_ENUM_CONSTANT(PAYLOAD_TOO_LARGE);
		BIND_ENUM_CONSTANT(URI_TOO_LONG);
		BIND_ENUM_CONSTANT(UNSUPPORTED_MEDIA_TYPE);
		BIND_ENUM_CONSTANT(RANGE_NOT_SATISFIABLE);
		BIND_ENUM_CONSTANT(EXPECTATION_FAILED);
		BIND_ENUM_CONSTANT(MISDIRECTED_REQUEST);
		BIND_ENUM_CONSTANT(UNPROCESSABLE_ENTITY);
		BIND_ENUM_CONSTANT(LOCKED);
		BIND_ENUM_CONSTANT(FAILED_DEPENDENCY);
		BIND_ENUM_CONSTANT(TOO_EARLY);
		BIND_ENUM_CONSTANT(UPGRADE_REQUIRED);
		BIND_ENUM_CONSTANT(PRECONDITION_REQUIRED);
		BIND_ENUM_CONSTANT(TOO_MANY_REQUESTS);
		BIND_ENUM_CONSTANT(REQUEST_HEADER_FIELDS_TOO_LARGE);
		BIND_ENUM_CONSTANT(INTERNAL_SERVER_ERROR);
		BIND_ENUM_CONSTANT(NOT_IMPLEMENTED);
		BIND_ENUM_CONSTANT(BAD_GATEWAY);
		BIND_ENUM_CONSTANT(SERVICE_UNAVAILABLE);
		BIND_ENUM_CONSTANT(GATEWAY_TIMEOUT);
		BIND_ENUM_CONSTANT(HTTP_VERSION_NOT_SUPPORTED);
		BIND_ENUM_CONSTANT(VARIANT_ALSO_NEGOTIATES);
		BIND_ENUM_CONSTANT(INSUFFICIENT_STORAGE);
		BIND_ENUM_CONSTANT(LOOP_DETECTED);
		BIND_ENUM_CONSTANT(NOT_EXTENDED);
		BIND_ENUM_CONSTANT(NETWORK_AUTHORIZATION_REQUIRED);

		// Constant binds.
		BIND_CONSTANT(id);
	}

public:
	static const int64_t id = 6;

	enum Enum {
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
};

class DiscordIntegrationType : public RefCounted {
	GDCLASS(DiscordIntegrationType, RefCounted)

private:
	DiscordIntegrationType() {}
	~DiscordIntegrationType() {}

protected:
	static void _bind_methods() {
		// Enums binds.
		BIND_ENUM_CONSTANT(GUILD_INSTALL);
		BIND_ENUM_CONSTANT(USER_INSTALL);

		// Constant binds.
		BIND_CONSTANT(id);
	}

public:
	static const int64_t id = 8;

	enum Enum {
		GUILD_INSTALL = 0,
		USER_INSTALL = 1,
	};
};

class DiscordLoggingSeverity : public RefCounted {
	GDCLASS(DiscordLoggingSeverity, RefCounted)

private:
	DiscordLoggingSeverity() {}
	~DiscordLoggingSeverity() {}

protected:
	static void _bind_methods() {
		// Enums binds.
		BIND_ENUM_CONSTANT(VERBOSE);
		BIND_ENUM_CONSTANT(INFO);
		BIND_ENUM_CONSTANT(WARNING);
		BIND_ENUM_CONSTANT(ERROR);
		BIND_ENUM_CONSTANT(NONE);

		// Constant binds.
		BIND_CONSTANT(id);
	}

public:
	static const int64_t id = 19;

	enum Enum {
		VERBOSE = 1,
		INFO = 2,
		WARNING = 3,
		ERROR = 4,
		NONE = 5,
	};
};

class DiscordRelationshipGroupType : public RefCounted {
	GDCLASS(DiscordRelationshipGroupType, RefCounted)

private:
	DiscordRelationshipGroupType() {}
	~DiscordRelationshipGroupType() {}

protected:
	static void _bind_methods() {
		// Enums binds.
		BIND_ENUM_CONSTANT(ONLINE_PLAYING_GAME);
		BIND_ENUM_CONSTANT(ONLINE_ELSEWHERE);
		BIND_ENUM_CONSTANT(OFFLINE);

		// Constant binds.
		BIND_CONSTANT(id);
	}

public:
	static const int64_t id = 20;

	enum Enum {
		ONLINE_PLAYING_GAME = 0,
		ONLINE_ELSEWHERE = 1,
		OFFLINE = 2,
	};
};

class DiscordRelationshipType : public RefCounted {
	GDCLASS(DiscordRelationshipType, RefCounted)

private:
	DiscordRelationshipType() {}
	~DiscordRelationshipType() {}

protected:
	static void _bind_methods() {
		// Enums binds.
		BIND_ENUM_CONSTANT(NONE);
		BIND_ENUM_CONSTANT(FRIEND);
		BIND_ENUM_CONSTANT(BLOCKED);
		BIND_ENUM_CONSTANT(PENDING_INCOMING);
		BIND_ENUM_CONSTANT(PENDING_OUTGOING);
		BIND_ENUM_CONSTANT(IMPLICIT);
		BIND_ENUM_CONSTANT(SUGGESTION);

		// Constant binds.
		BIND_CONSTANT(id);
	}

public:
	static const int64_t id = 13;

	enum Enum {
		NONE = 0,
		FRIEND = 1,
		BLOCKED = 2,
		PENDING_INCOMING = 3,
		PENDING_OUTGOING = 4,
		IMPLICIT = 5,
		SUGGESTION = 6,
	};
};

class DiscordStatusDisplayTypes : public RefCounted {
	GDCLASS(DiscordStatusDisplayTypes, RefCounted)

private:
	DiscordStatusDisplayTypes() {}
	~DiscordStatusDisplayTypes() {}

protected:
	static void _bind_methods() {
		// Enums binds.
		BIND_ENUM_CONSTANT(NAME);
		BIND_ENUM_CONSTANT(STATE);
		BIND_ENUM_CONSTANT(DETAILS);

		// Constant binds.
		BIND_CONSTANT(id);
	}

public:
	static const int64_t id = 3;

	enum Enum {
		NAME = 0,
		STATE = 1,
		DETAILS = 2,
	};
};

class DiscordStatusType : public RefCounted {
	GDCLASS(DiscordStatusType, RefCounted)

private:
	DiscordStatusType() {}
	~DiscordStatusType() {}

protected:
	static void _bind_methods() {
		// Enums binds.
		BIND_ENUM_CONSTANT(ONLINE);
		BIND_ENUM_CONSTANT(OFFLINE);
		BIND_ENUM_CONSTANT(BLOCKED);
		BIND_ENUM_CONSTANT(IDLE);
		BIND_ENUM_CONSTANT(DND);
		BIND_ENUM_CONSTANT(INVISIBLE);
		BIND_ENUM_CONSTANT(STREAMING);
		BIND_ENUM_CONSTANT(UNKNOWN);

		// Constant binds.
		BIND_CONSTANT(id);
	}

public:
	static const int64_t id = 15;

	enum Enum {
		ONLINE = 0,
		OFFLINE = 1,
		BLOCKED = 2,
		IDLE = 3,
		DND = 4,
		INVISIBLE = 5,
		STREAMING = 6,
		UNKNOWN = 7,
	};
};

class DiscordUserHandleAvatarType : public RefCounted {
	GDCLASS(DiscordUserHandleAvatarType, RefCounted)

private:
	DiscordUserHandleAvatarType() {}
	~DiscordUserHandleAvatarType() {}

protected:
	static void _bind_methods() {
		// Enums binds.
		BIND_ENUM_CONSTANT(GIF);
		BIND_ENUM_CONSTANT(WEBP);
		BIND_ENUM_CONSTANT(PNG);
		BIND_ENUM_CONSTANT(JPEG);

		// Constant binds.
		BIND_CONSTANT(id);
	}

public:
	static const int64_t id = 26;

	enum Enum {
		GIF = 0,
		WEBP = 1,
		PNG = 2,
		JPEG = 3,
	};
};

} // namespace godot

// Needed so we can bind functions.
VARIANT_ENUM_CAST(DiscordActivityActionTypes::Enum);
VARIANT_ENUM_CAST(DiscordActivityGamePlatforms::Enum);
VARIANT_ENUM_CAST(DiscordActivityPartyPrivacy::Enum);
VARIANT_ENUM_CAST(DiscordActivityTypes::Enum);
VARIANT_ENUM_CAST(DiscordAdditionalContentType::Enum);
VARIANT_ENUM_CAST(DiscordAudioModeType::Enum);
VARIANT_ENUM_CAST(DiscordAudioSystem::Enum);
VARIANT_ENUM_CAST(DiscordAuthenticationCodeChallengeMethod::Enum);
VARIANT_ENUM_CAST(DiscordAuthenticationExternalAuthType::Enum);
VARIANT_ENUM_CAST(DiscordAuthorizationTokenType::Enum);
VARIANT_ENUM_CAST(DiscordCallError::Enum);
VARIANT_ENUM_CAST(DiscordCallStatus::Enum);
VARIANT_ENUM_CAST(DiscordChannelType::Enum);
VARIANT_ENUM_CAST(DiscordClientError::Enum);
VARIANT_ENUM_CAST(DiscordClientStatus::Enum);
VARIANT_ENUM_CAST(DiscordClientThread::Enum);
VARIANT_ENUM_CAST(DiscordDisclosureTypes::Enum);
VARIANT_ENUM_CAST(DiscordErrorType::Enum);
VARIANT_ENUM_CAST(DiscordExternalIdentityProviderType::Enum);
VARIANT_ENUM_CAST(DiscordHttpStatusCode::Enum);
VARIANT_ENUM_CAST(DiscordIntegrationType::Enum);
VARIANT_ENUM_CAST(DiscordLoggingSeverity::Enum);
VARIANT_ENUM_CAST(DiscordRelationshipGroupType::Enum);
VARIANT_ENUM_CAST(DiscordRelationshipType::Enum);
VARIANT_ENUM_CAST(DiscordStatusDisplayTypes::Enum);
VARIANT_ENUM_CAST(DiscordStatusType::Enum);
VARIANT_ENUM_CAST(DiscordUserHandleAvatarType::Enum);

#endif
