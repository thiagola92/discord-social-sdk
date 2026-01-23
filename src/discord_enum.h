
#ifndef DISCORD_ENUM_H
#define DISCORD_ENUM_H

#include "godot_cpp/classes/ref_counted.hpp"
#include "godot_cpp/classes/wrapped.hpp"
#include "godot_cpp/core/binder_common.hpp"
#include "godot_cpp/core/class_db.hpp"

namespace godot {

class DiscordActivityActionTypes : public RefCounted {
	GDCLASS(DiscordActivityActionTypes, RefCounted)

private:
	DiscordActivityActionTypes() {}
	~DiscordActivityActionTypes() {}

protected:
	static void _bind_methods() {
		BIND_ENUM_CONSTANT(Invalid);
		BIND_ENUM_CONSTANT(Join);
		BIND_ENUM_CONSTANT(JoinRequest);
	}

public:
	enum Enum {
		Invalid = 0,
		Join = 1,
		JoinRequest = 5,
	};
};

class DiscordActivityGamePlatforms : public RefCounted {
	GDCLASS(DiscordActivityGamePlatforms, RefCounted)

private:
	DiscordActivityGamePlatforms() {}
	~DiscordActivityGamePlatforms() {}

protected:
	static void _bind_methods() {
		BIND_ENUM_CONSTANT(Desktop);
		BIND_ENUM_CONSTANT(Xbox);
		BIND_ENUM_CONSTANT(Samsung);
		BIND_ENUM_CONSTANT(IOS);
		BIND_ENUM_CONSTANT(Android);
		BIND_ENUM_CONSTANT(Embedded);
		BIND_ENUM_CONSTANT(PS4);
		BIND_ENUM_CONSTANT(PS5);
	}

public:
	enum Enum {
		Desktop = 1,
		Xbox = 2,
		Samsung = 4,
		IOS = 8,
		Android = 16,
		Embedded = 32,
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
		BIND_ENUM_CONSTANT(Private);
		BIND_ENUM_CONSTANT(Public);
	}

public:
	enum Enum {
		Private = 0,
		Public = 1,
	};
};

class DiscordActivityTypes : public RefCounted {
	GDCLASS(DiscordActivityTypes, RefCounted)

private:
	DiscordActivityTypes() {}
	~DiscordActivityTypes() {}

protected:
	static void _bind_methods() {
		BIND_ENUM_CONSTANT(Playing);
		BIND_ENUM_CONSTANT(Streaming);
		BIND_ENUM_CONSTANT(Listening);
		BIND_ENUM_CONSTANT(Watching);
		BIND_ENUM_CONSTANT(CustomStatus);
		BIND_ENUM_CONSTANT(Competing);
		BIND_ENUM_CONSTANT(HangStatus);
	}

public:
	enum Enum {
		Playing = 0,
		Streaming = 1,
		Listening = 2,
		Watching = 3,
		CustomStatus = 4,
		Competing = 5,
		HangStatus = 6,
	};
};

class DiscordAdditionalContentType : public RefCounted {
	GDCLASS(DiscordAdditionalContentType, RefCounted)

private:
	DiscordAdditionalContentType() {}
	~DiscordAdditionalContentType() {}

protected:
	static void _bind_methods() {
		BIND_ENUM_CONSTANT(Other);
		BIND_ENUM_CONSTANT(Attachment);
		BIND_ENUM_CONSTANT(Poll);
		BIND_ENUM_CONSTANT(VoiceMessage);
		BIND_ENUM_CONSTANT(Thread);
		BIND_ENUM_CONSTANT(Embed);
		BIND_ENUM_CONSTANT(Sticker);
	}

public:
	enum Enum {
		Other = 0,
		Attachment = 1,
		Poll = 2,
		VoiceMessage = 3,
		Thread = 4,
		Embed = 5,
		Sticker = 6,
	};
};

class DiscordAudioModeType : public RefCounted {
	GDCLASS(DiscordAudioModeType, RefCounted)

private:
	DiscordAudioModeType() {}
	~DiscordAudioModeType() {}

protected:
	static void _bind_methods() {
		BIND_ENUM_CONSTANT(MODE_UNINIT);
		BIND_ENUM_CONSTANT(MODE_VAD);
		BIND_ENUM_CONSTANT(MODE_PTT);
	}

public:
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
		BIND_ENUM_CONSTANT(Standard);
		BIND_ENUM_CONSTANT(Game);
	}

public:
	enum Enum {
		Standard = 0,
		Game = 1,
	};
};

class DiscordAuthenticationCodeChallengeMethod : public RefCounted {
	GDCLASS(DiscordAuthenticationCodeChallengeMethod, RefCounted)

private:
	DiscordAuthenticationCodeChallengeMethod() {}
	~DiscordAuthenticationCodeChallengeMethod() {}

protected:
	static void _bind_methods() {
		BIND_ENUM_CONSTANT(S256);
	}

public:
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
		BIND_ENUM_CONSTANT(OIDC);
		BIND_ENUM_CONSTANT(EpicOnlineServicesAccessToken);
		BIND_ENUM_CONSTANT(EpicOnlineServicesIdToken);
		BIND_ENUM_CONSTANT(SteamSessionTicket);
		BIND_ENUM_CONSTANT(UnityServicesIdToken);
		BIND_ENUM_CONSTANT(DiscordBotIssuedAccessToken);
		BIND_ENUM_CONSTANT(AppleIdToken);
		BIND_ENUM_CONSTANT(PlayStationNetworkIdToken);
	}

public:
	enum Enum {
		OIDC = 0,
		EpicOnlineServicesAccessToken = 1,
		EpicOnlineServicesIdToken = 2,
		SteamSessionTicket = 3,
		UnityServicesIdToken = 4,
		DiscordBotIssuedAccessToken = 5,
		AppleIdToken = 6,
		PlayStationNetworkIdToken = 7,
	};
};

class DiscordAuthorizationTokenType : public RefCounted {
	GDCLASS(DiscordAuthorizationTokenType, RefCounted)

private:
	DiscordAuthorizationTokenType() {}
	~DiscordAuthorizationTokenType() {}

protected:
	static void _bind_methods() {
		BIND_ENUM_CONSTANT(User);
		BIND_ENUM_CONSTANT(Bearer);
	}

public:
	enum Enum {
		User = 0,
		Bearer = 1,
	};
};

class DiscordCallError : public RefCounted {
	GDCLASS(DiscordCallError, RefCounted)

private:
	DiscordCallError() {}
	~DiscordCallError() {}

protected:
	static void _bind_methods() {
		BIND_ENUM_CONSTANT(None);
		BIND_ENUM_CONSTANT(SignalingConnectionFailed);
		BIND_ENUM_CONSTANT(SignalingUnexpectedClose);
		BIND_ENUM_CONSTANT(VoiceConnectionFailed);
		BIND_ENUM_CONSTANT(JoinTimeout);
		BIND_ENUM_CONSTANT(Forbidden);
	}

public:
	enum Enum {
		None = 0,
		SignalingConnectionFailed = 1,
		SignalingUnexpectedClose = 2,
		VoiceConnectionFailed = 3,
		JoinTimeout = 4,
		Forbidden = 5,
	};
};

class DiscordCallStatus : public RefCounted {
	GDCLASS(DiscordCallStatus, RefCounted)

private:
	DiscordCallStatus() {}
	~DiscordCallStatus() {}

protected:
	static void _bind_methods() {
		BIND_ENUM_CONSTANT(Disconnected);
		BIND_ENUM_CONSTANT(Joining);
		BIND_ENUM_CONSTANT(Connecting);
		BIND_ENUM_CONSTANT(SignalingConnected);
		BIND_ENUM_CONSTANT(Connected);
		BIND_ENUM_CONSTANT(Reconnecting);
		BIND_ENUM_CONSTANT(Disconnecting);
	}

public:
	enum Enum {
		Disconnected = 0,
		Joining = 1,
		Connecting = 2,
		SignalingConnected = 3,
		Connected = 4,
		Reconnecting = 5,
		Disconnecting = 6,
	};
};

class DiscordChannelType : public RefCounted {
	GDCLASS(DiscordChannelType, RefCounted)

private:
	DiscordChannelType() {}
	~DiscordChannelType() {}

protected:
	static void _bind_methods() {
		BIND_ENUM_CONSTANT(GuildText);
		BIND_ENUM_CONSTANT(Dm);
		BIND_ENUM_CONSTANT(GuildVoice);
		BIND_ENUM_CONSTANT(GroupDm);
		BIND_ENUM_CONSTANT(GuildCategory);
		BIND_ENUM_CONSTANT(GuildNews);
		BIND_ENUM_CONSTANT(GuildStore);
		BIND_ENUM_CONSTANT(GuildNewsThread);
		BIND_ENUM_CONSTANT(GuildPublicThread);
		BIND_ENUM_CONSTANT(GuildPrivateThread);
		BIND_ENUM_CONSTANT(GuildStageVoice);
		BIND_ENUM_CONSTANT(GuildDirectory);
		BIND_ENUM_CONSTANT(GuildForum);
		BIND_ENUM_CONSTANT(GuildMedia);
		BIND_ENUM_CONSTANT(Lobby);
		BIND_ENUM_CONSTANT(EphemeralDm);
	}

public:
	enum Enum {
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
};

class DiscordClientError : public RefCounted {
	GDCLASS(DiscordClientError, RefCounted)

private:
	DiscordClientError() {}
	~DiscordClientError() {}

protected:
	static void _bind_methods() {
		BIND_ENUM_CONSTANT(None);
		BIND_ENUM_CONSTANT(ConnectionFailed);
		BIND_ENUM_CONSTANT(UnexpectedClose);
		BIND_ENUM_CONSTANT(ConnectionCanceled);
	}

public:
	enum Enum {
		None = 0,
		ConnectionFailed = 1,
		UnexpectedClose = 2,
		ConnectionCanceled = 3,
	};
};

class DiscordClientStatus : public RefCounted {
	GDCLASS(DiscordClientStatus, RefCounted)

private:
	DiscordClientStatus() {}
	~DiscordClientStatus() {}

protected:
	static void _bind_methods() {
		BIND_ENUM_CONSTANT(Disconnected);
		BIND_ENUM_CONSTANT(Connecting);
		BIND_ENUM_CONSTANT(Connected);
		BIND_ENUM_CONSTANT(Ready);
		BIND_ENUM_CONSTANT(Reconnecting);
		BIND_ENUM_CONSTANT(Disconnecting);
		BIND_ENUM_CONSTANT(HttpWait);
	}

public:
	enum Enum {
		Disconnected = 0,
		Connecting = 1,
		Connected = 2,
		Ready = 3,
		Reconnecting = 4,
		Disconnecting = 5,
		HttpWait = 6,
	};
};

class DiscordClientThread : public RefCounted {
	GDCLASS(DiscordClientThread, RefCounted)

private:
	DiscordClientThread() {}
	~DiscordClientThread() {}

protected:
	static void _bind_methods() {
		BIND_ENUM_CONSTANT(Client);
		BIND_ENUM_CONSTANT(Voice);
		BIND_ENUM_CONSTANT(Network);
	}

public:
	enum Enum {
		Client = 0,
		Voice = 1,
		Network = 2,
	};
};

class DiscordDisclosureTypes : public RefCounted {
	GDCLASS(DiscordDisclosureTypes, RefCounted)

private:
	DiscordDisclosureTypes() {}
	~DiscordDisclosureTypes() {}

protected:
	static void _bind_methods() {
		BIND_ENUM_CONSTANT(MessageDataVisibleOnDiscord);
	}

public:
	enum Enum {
		MessageDataVisibleOnDiscord = 3,
	};
};

class DiscordErrorType : public RefCounted {
	GDCLASS(DiscordErrorType, RefCounted)

private:
	DiscordErrorType() {}
	~DiscordErrorType() {}

protected:
	static void _bind_methods() {
		BIND_ENUM_CONSTANT(None);
		BIND_ENUM_CONSTANT(NetworkError);
		BIND_ENUM_CONSTANT(HTTPError);
		BIND_ENUM_CONSTANT(ClientNotReady);
		BIND_ENUM_CONSTANT(Disabled);
		BIND_ENUM_CONSTANT(ClientDestroyed);
		BIND_ENUM_CONSTANT(ValidationError);
		BIND_ENUM_CONSTANT(Aborted);
		BIND_ENUM_CONSTANT(AuthorizationFailed);
		BIND_ENUM_CONSTANT(RPCError);
	}

public:
	enum Enum {
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
};

class DiscordExternalIdentityProviderType : public RefCounted {
	GDCLASS(DiscordExternalIdentityProviderType, RefCounted)

private:
	DiscordExternalIdentityProviderType() {}
	~DiscordExternalIdentityProviderType() {}

protected:
	static void _bind_methods() {
		BIND_ENUM_CONSTANT(OIDC);
		BIND_ENUM_CONSTANT(EpicOnlineServices);
		BIND_ENUM_CONSTANT(Steam);
		BIND_ENUM_CONSTANT(Unity);
		BIND_ENUM_CONSTANT(DiscordBot);
		BIND_ENUM_CONSTANT(None);
		BIND_ENUM_CONSTANT(Unknown);
	}

public:
	enum Enum {
		OIDC = 0,
		EpicOnlineServices = 1,
		Steam = 2,
		Unity = 3,
		DiscordBot = 4,
		None = 5,
		Unknown = 6,
	};
};

class DiscordHttpStatusCode : public RefCounted {
	GDCLASS(DiscordHttpStatusCode, RefCounted)

private:
	DiscordHttpStatusCode() {}
	~DiscordHttpStatusCode() {}

protected:
	static void _bind_methods() {
		BIND_ENUM_CONSTANT(None);
		BIND_ENUM_CONSTANT(Continue);
		BIND_ENUM_CONSTANT(SwitchingProtocols);
		BIND_ENUM_CONSTANT(Processing);
		BIND_ENUM_CONSTANT(EarlyHints);
		BIND_ENUM_CONSTANT(Ok);
		BIND_ENUM_CONSTANT(Created);
		BIND_ENUM_CONSTANT(Accepted);
		BIND_ENUM_CONSTANT(NonAuthoritativeInfo);
		BIND_ENUM_CONSTANT(NoContent);
		BIND_ENUM_CONSTANT(ResetContent);
		BIND_ENUM_CONSTANT(PartialContent);
		BIND_ENUM_CONSTANT(MultiStatus);
		BIND_ENUM_CONSTANT(AlreadyReported);
		BIND_ENUM_CONSTANT(ImUsed);
		BIND_ENUM_CONSTANT(MultipleChoices);
		BIND_ENUM_CONSTANT(MovedPermanently);
		BIND_ENUM_CONSTANT(Found);
		BIND_ENUM_CONSTANT(SeeOther);
		BIND_ENUM_CONSTANT(NotModified);
		BIND_ENUM_CONSTANT(TemporaryRedirect);
		BIND_ENUM_CONSTANT(PermanentRedirect);
		BIND_ENUM_CONSTANT(BadRequest);
		BIND_ENUM_CONSTANT(Unauthorized);
		BIND_ENUM_CONSTANT(PaymentRequired);
		BIND_ENUM_CONSTANT(Forbidden);
		BIND_ENUM_CONSTANT(NotFound);
		BIND_ENUM_CONSTANT(MethodNotAllowed);
		BIND_ENUM_CONSTANT(NotAcceptable);
		BIND_ENUM_CONSTANT(ProxyAuthRequired);
		BIND_ENUM_CONSTANT(RequestTimeout);
		BIND_ENUM_CONSTANT(Conflict);
		BIND_ENUM_CONSTANT(Gone);
		BIND_ENUM_CONSTANT(LengthRequired);
		BIND_ENUM_CONSTANT(PreconditionFailed);
		BIND_ENUM_CONSTANT(PayloadTooLarge);
		BIND_ENUM_CONSTANT(UriTooLong);
		BIND_ENUM_CONSTANT(UnsupportedMediaType);
		BIND_ENUM_CONSTANT(RangeNotSatisfiable);
		BIND_ENUM_CONSTANT(ExpectationFailed);
		BIND_ENUM_CONSTANT(MisdirectedRequest);
		BIND_ENUM_CONSTANT(UnprocessableEntity);
		BIND_ENUM_CONSTANT(Locked);
		BIND_ENUM_CONSTANT(FailedDependency);
		BIND_ENUM_CONSTANT(TooEarly);
		BIND_ENUM_CONSTANT(UpgradeRequired);
		BIND_ENUM_CONSTANT(PreconditionRequired);
		BIND_ENUM_CONSTANT(TooManyRequests);
		BIND_ENUM_CONSTANT(RequestHeaderFieldsTooLarge);
		BIND_ENUM_CONSTANT(InternalServerError);
		BIND_ENUM_CONSTANT(NotImplemented);
		BIND_ENUM_CONSTANT(BadGateway);
		BIND_ENUM_CONSTANT(ServiceUnavailable);
		BIND_ENUM_CONSTANT(GatewayTimeout);
		BIND_ENUM_CONSTANT(HttpVersionNotSupported);
		BIND_ENUM_CONSTANT(VariantAlsoNegotiates);
		BIND_ENUM_CONSTANT(InsufficientStorage);
		BIND_ENUM_CONSTANT(LoopDetected);
		BIND_ENUM_CONSTANT(NotExtended);
		BIND_ENUM_CONSTANT(NetworkAuthorizationRequired);
	}

public:
	enum Enum {
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
};

class DiscordIntegrationType : public RefCounted {
	GDCLASS(DiscordIntegrationType, RefCounted)

private:
	DiscordIntegrationType() {}
	~DiscordIntegrationType() {}

protected:
	static void _bind_methods() {
		BIND_ENUM_CONSTANT(GuildInstall);
		BIND_ENUM_CONSTANT(UserInstall);
	}

public:
	enum Enum {
		GuildInstall = 0,
		UserInstall = 1,
	};
};

class DiscordLoggingSeverity : public RefCounted {
	GDCLASS(DiscordLoggingSeverity, RefCounted)

private:
	DiscordLoggingSeverity() {}
	~DiscordLoggingSeverity() {}

protected:
	static void _bind_methods() {
		BIND_ENUM_CONSTANT(Verbose);
		BIND_ENUM_CONSTANT(Info);
		BIND_ENUM_CONSTANT(Warning);
		BIND_ENUM_CONSTANT(Error);
		BIND_ENUM_CONSTANT(None);
	}

public:
	enum Enum {
		Verbose = 1,
		Info = 2,
		Warning = 3,
		Error = 4,
		None = 5,
	};
};

class DiscordRelationshipGroupType : public RefCounted {
	GDCLASS(DiscordRelationshipGroupType, RefCounted)

private:
	DiscordRelationshipGroupType() {}
	~DiscordRelationshipGroupType() {}

protected:
	static void _bind_methods() {
		BIND_ENUM_CONSTANT(OnlinePlayingGame);
		BIND_ENUM_CONSTANT(OnlineElsewhere);
		BIND_ENUM_CONSTANT(Offline);
	}

public:
	enum Enum {
		OnlinePlayingGame = 0,
		OnlineElsewhere = 1,
		Offline = 2,
	};
};

class DiscordRelationshipType : public RefCounted {
	GDCLASS(DiscordRelationshipType, RefCounted)

private:
	DiscordRelationshipType() {}
	~DiscordRelationshipType() {}

protected:
	static void _bind_methods() {
		BIND_ENUM_CONSTANT(None);
		BIND_ENUM_CONSTANT(Friend);
		BIND_ENUM_CONSTANT(Blocked);
		BIND_ENUM_CONSTANT(PendingIncoming);
		BIND_ENUM_CONSTANT(PendingOutgoing);
		BIND_ENUM_CONSTANT(Implicit);
		BIND_ENUM_CONSTANT(Suggestion);
	}

public:
	enum Enum {
		None = 0,
		Friend = 1,
		Blocked = 2,
		PendingIncoming = 3,
		PendingOutgoing = 4,
		Implicit = 5,
		Suggestion = 6,
	};
};

class DiscordStatusDisplayTypes : public RefCounted {
	GDCLASS(DiscordStatusDisplayTypes, RefCounted)

private:
	DiscordStatusDisplayTypes() {}
	~DiscordStatusDisplayTypes() {}

protected:
	static void _bind_methods() {
		BIND_ENUM_CONSTANT(Name);
		BIND_ENUM_CONSTANT(State);
		BIND_ENUM_CONSTANT(Details);
	}

public:
	enum Enum {
		Name = 0,
		State = 1,
		Details = 2,
	};
};

class DiscordStatusType : public RefCounted {
	GDCLASS(DiscordStatusType, RefCounted)

private:
	DiscordStatusType() {}
	~DiscordStatusType() {}

protected:
	static void _bind_methods() {
		BIND_ENUM_CONSTANT(Online);
		BIND_ENUM_CONSTANT(Offline);
		BIND_ENUM_CONSTANT(Blocked);
		BIND_ENUM_CONSTANT(Idle);
		BIND_ENUM_CONSTANT(Dnd);
		BIND_ENUM_CONSTANT(Invisible);
		BIND_ENUM_CONSTANT(Streaming);
		BIND_ENUM_CONSTANT(Unknown);
	}

public:
	enum Enum {
		Online = 0,
		Offline = 1,
		Blocked = 2,
		Idle = 3,
		Dnd = 4,
		Invisible = 5,
		Streaming = 6,
		Unknown = 7,
	};
};

class DiscordUserHandleAvatarType : public RefCounted {
	GDCLASS(DiscordUserHandleAvatarType, RefCounted)

private:
	DiscordUserHandleAvatarType() {}
	~DiscordUserHandleAvatarType() {}

protected:
	static void _bind_methods() {
		BIND_ENUM_CONSTANT(Gif);
		BIND_ENUM_CONSTANT(Webp);
		BIND_ENUM_CONSTANT(Png);
		BIND_ENUM_CONSTANT(Jpeg);
	}

public:
	enum Enum {
		Gif = 0,
		Webp = 1,
		Png = 2,
		Jpeg = 3,
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
