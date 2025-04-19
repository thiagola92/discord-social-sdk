
#include "discordpp_classes.h"

using namespace godot;

void DiscordppClient::Drop() {
	obj->Drop();
}

String DiscordppClient::ErrorToString(DiscordppClientError::Enum type) {
	discordpp::Client::Error p0 = (discordpp::Client::Error)type;

	return String(obj->ErrorToString(p0).c_str());
}

String DiscordppClient::GetDefaultAudioDeviceId() {
	return String(obj->GetDefaultAudioDeviceId().c_str());
}

String DiscordppClient::GetDefaultCommunicationScopes() {
	return String(obj->GetDefaultCommunicationScopes().c_str());
}

String DiscordppClient::GetDefaultPresenceScopes() {
	return String(obj->GetDefaultPresenceScopes().c_str());
}

String DiscordppClient::GetVersionHash() {
	return String(obj->GetVersionHash().c_str());
}

int64_t DiscordppClient::GetVersionMajor() {
	return obj->GetVersionMajor();
}

int64_t DiscordppClient::GetVersionMinor() {
	return obj->GetVersionMinor();
}

int64_t DiscordppClient::GetVersionPatch() {
	return obj->GetVersionPatch();
}

String DiscordppClient::StatusToString(DiscordppClientStatus::Enum type) {
	discordpp::Client::Status p0 = (discordpp::Client::Status)type;

	return String(obj->StatusToString(p0).c_str());
}

String DiscordppClient::ThreadToString(DiscordppClientThread::Enum type) {
	discordpp::Client::Thread p0 = (discordpp::Client::Thread)type;

	return String(obj->ThreadToString(p0).c_str());
}

void DiscordppClient::EndCall(int64_t channelId, Callable callback) {
	int64_t p0 = channelId;

	obj->EndCall(p0, [callback]() {
		callback.call();
	});
}

void DiscordppClient::EndCalls(Callable callback) {
	obj->EndCalls([callback]() {
		callback.call();
	});
}

DiscordppCall *DiscordppClient::GetCall(int64_t channelId) {
	int64_t p0 = channelId;

	discordpp::Call *t_r = (discordpp::Call *)memalloc(sizeof(discordpp::Call));
	*t_r = obj->GetCall(p0);
	return memnew(DiscordppCall{ t_r });
}

TypedArray<DiscordppCall> DiscordppClient::GetCalls() {
	auto r = obj->GetCalls();
	TypedArray<DiscordppCall> t_r = TypedArray<DiscordppCall>();

	for (auto i : r) {
		t_r.push_back(memnew(DiscordppCall{ &i }));
	}

	return t_r;
}

void DiscordppClient::GetCurrentInputDevice(Callable cb) {
	obj->GetCurrentInputDevice([cb](auto device) {
		discordpp::AudioDevice *t_p0 = (discordpp::AudioDevice *)memalloc(sizeof(discordpp::AudioDevice));
		*t_p0 = device;
		DiscordppAudioDevice *p0 = memnew(DiscordppAudioDevice{ t_p0 });

		cb.call(p0);
	});
}

void DiscordppClient::GetCurrentOutputDevice(Callable cb) {
	obj->GetCurrentOutputDevice([cb](auto device) {
		discordpp::AudioDevice *t_p0 = (discordpp::AudioDevice *)memalloc(sizeof(discordpp::AudioDevice));
		*t_p0 = device;
		DiscordppAudioDevice *p0 = memnew(DiscordppAudioDevice{ t_p0 });

		cb.call(p0);
	});
}

void DiscordppClient::GetInputDevices(Callable cb) {
	obj->GetInputDevices([cb](auto devices) {
		TypedArray<DiscordppAudioDevice> p0 = TypedArray<DiscordppAudioDevice>();

		for (auto i : devices) {
			p0.push_back(memnew(DiscordppAudioDevice{ &i }));
		}

		cb.call(p0);
	});
}

float DiscordppClient::GetInputVolume() {
	return obj->GetInputVolume();
}

void DiscordppClient::GetOutputDevices(Callable cb) {
	obj->GetOutputDevices([cb](auto devices) {
		TypedArray<DiscordppAudioDevice> p0 = TypedArray<DiscordppAudioDevice>();

		for (auto i : devices) {
			p0.push_back(memnew(DiscordppAudioDevice{ &i }));
		}

		cb.call(p0);
	});
}

float DiscordppClient::GetOutputVolume() {
	return obj->GetOutputVolume();
}

bool DiscordppClient::GetSelfDeafAll() {
	return obj->GetSelfDeafAll();
}

bool DiscordppClient::GetSelfMuteAll() {
	return obj->GetSelfMuteAll();
}

void DiscordppClient::SetAutomaticGainControl(bool on) {
	bool p0 = on;

	obj->SetAutomaticGainControl(p0);
}

void DiscordppClient::SetDeviceChangeCallback(Callable callback) {
	obj->SetDeviceChangeCallback([callback](auto inputDevices, auto outputDevices) {
		TypedArray<DiscordppAudioDevice> p0 = TypedArray<DiscordppAudioDevice>();

		for (auto i : inputDevices) {
			p0.push_back(memnew(DiscordppAudioDevice{ &i }));
		}

		TypedArray<DiscordppAudioDevice> p1 = TypedArray<DiscordppAudioDevice>();

		for (auto i : outputDevices) {
			p1.push_back(memnew(DiscordppAudioDevice{ &i }));
		}

		callback.call(p0, p1);
	});
}

void DiscordppClient::SetEchoCancellation(bool on) {
	bool p0 = on;

	obj->SetEchoCancellation(p0);
}

void DiscordppClient::SetInputDevice(String deviceId, Callable cb) {
	const char *p0 = deviceId.utf8().get_data();

	obj->SetInputDevice(p0, [cb](auto result) {
		discordpp::ClientResult *t_p0 = (discordpp::ClientResult *)memalloc(sizeof(discordpp::ClientResult));
		*t_p0 = result;
		DiscordppClientResult *p0 = memnew(DiscordppClientResult{ t_p0 });

		cb.call(p0);
	});
}

void DiscordppClient::SetInputVolume(float inputVolume) {
	float p0 = inputVolume;

	obj->SetInputVolume(p0);
}

void DiscordppClient::SetNoAudioInputCallback(Callable callback) {
	obj->SetNoAudioInputCallback([callback](auto inputDetected) {
		bool p0 = inputDetected;
		callback.call(p0);
	});
}

void DiscordppClient::SetNoAudioInputThreshold(float dBFSThreshold) {
	float p0 = dBFSThreshold;

	obj->SetNoAudioInputThreshold(p0);
}

void DiscordppClient::SetNoiseSuppression(bool on) {
	bool p0 = on;

	obj->SetNoiseSuppression(p0);
}

void DiscordppClient::SetOpusHardwareCoding(bool encode, bool decode) {
	bool p0 = encode;
	bool p1 = decode;

	obj->SetOpusHardwareCoding(p0, p1);
}

void DiscordppClient::SetOutputDevice(String deviceId, Callable cb) {
	const char *p0 = deviceId.utf8().get_data();

	obj->SetOutputDevice(p0, [cb](auto result) {
		discordpp::ClientResult *t_p0 = (discordpp::ClientResult *)memalloc(sizeof(discordpp::ClientResult));
		*t_p0 = result;
		DiscordppClientResult *p0 = memnew(DiscordppClientResult{ t_p0 });

		cb.call(p0);
	});
}

void DiscordppClient::SetOutputVolume(float outputVolume) {
	float p0 = outputVolume;

	obj->SetOutputVolume(p0);
}

void DiscordppClient::SetSelfDeafAll(bool deaf) {
	bool p0 = deaf;

	obj->SetSelfDeafAll(p0);
}

void DiscordppClient::SetSelfMuteAll(bool mute) {
	bool p0 = mute;

	obj->SetSelfMuteAll(p0);
}

bool DiscordppClient::SetSpeakerMode(bool speakerMode) {
	bool p0 = speakerMode;

	return obj->SetSpeakerMode(p0);
}

void DiscordppClient::SetThreadPriority(DiscordppClientThread::Enum thread, int64_t priority) {
	discordpp::Client::Thread p0 = (discordpp::Client::Thread)thread;
	int64_t p1 = priority;

	obj->SetThreadPriority(p0, p1);
}

void DiscordppClient::SetVoiceParticipantChangedCallback(Callable cb) {
	obj->SetVoiceParticipantChangedCallback([cb](auto lobbyId, auto memberId, auto added) {
		int64_t p0 = (int64_t)lobbyId;
		int64_t p1 = (int64_t)memberId;
		bool p2 = added;
		cb.call(p0, p1, p2);
	});
}

bool DiscordppClient::ShowAudioRoutePicker() {
	return obj->ShowAudioRoutePicker();
}

DiscordppCall *DiscordppClient::StartCall(int64_t channelId) {
	int64_t p0 = channelId;

	discordpp::Call *t_r = (discordpp::Call *)memalloc(sizeof(discordpp::Call));
	*t_r = obj->StartCall(p0);
	return memnew(DiscordppCall{ t_r });
}

DiscordppCall *DiscordppClient::StartCallWithAudioCallbacks(int64_t lobbyId, Callable receivedCb, Callable capturedCb) {
	int64_t p0 = lobbyId;

	discordpp::Call *t_r = (discordpp::Call *)memalloc(sizeof(discordpp::Call));
	*t_r = obj->StartCallWithAudioCallbacks(p0, [receivedCb](auto userId, auto data, auto samplesPerChannel, auto sampleRate, auto channels, auto outShouldMute) {
        int64_t p0 = (int64_t)userId;
    int64_t p1 = (int64_t)data;
    int64_t p2 = (int64_t)samplesPerChannel;
    int64_t p3 = (int64_t)sampleRate;
    int64_t p4 = (int64_t)channels;
    bool p5 = outShouldMute;
        receivedCb.call(p0, p1, p2, p3, p4, p5); }, [capturedCb](auto data, auto samplesPerChannel, auto sampleRate, auto channels) {
        int64_t p0 = (int64_t)data;
    int64_t p1 = (int64_t)samplesPerChannel;
    int64_t p2 = (int64_t)sampleRate;
    int64_t p3 = (int64_t)channels;
        capturedCb.call(p0, p1, p2, p3); });
	return memnew(DiscordppCall{ t_r });
}

void DiscordppClient::AbortAuthorize() {
	obj->AbortAuthorize();
}

void DiscordppClient::AbortGetTokenFromDevice() {
	obj->AbortGetTokenFromDevice();
}

void DiscordppClient::Authorize(DiscordppAuthorizationArgs *args, Callable callback) {
	discordpp::AuthorizationArgs p0 = *args->unwrap();

	obj->Authorize(p0, [callback](auto result, auto code, auto redirectUri) {
		discordpp::ClientResult *t_p0 = (discordpp::ClientResult *)memalloc(sizeof(discordpp::ClientResult));
		*t_p0 = result;
		DiscordppClientResult *p0 = memnew(DiscordppClientResult{ t_p0 });

		String p1 = String(code.c_str());
		String p2 = String(redirectUri.c_str());
		callback.call(p0, p1, p2);
	});
}

void DiscordppClient::CloseAuthorizeDeviceScreen() {
	obj->CloseAuthorizeDeviceScreen();
}

DiscordppAuthorizationCodeVerifier *DiscordppClient::CreateAuthorizationCodeVerifier() {
	discordpp::AuthorizationCodeVerifier *t_r = (discordpp::AuthorizationCodeVerifier *)memalloc(sizeof(discordpp::AuthorizationCodeVerifier));
	*t_r = obj->CreateAuthorizationCodeVerifier();
	return memnew(DiscordppAuthorizationCodeVerifier{ t_r });
}

void DiscordppClient::FetchCurrentUser(DiscordppAuthorizationTokenType::Enum tokenType, String token, Callable callback) {
	discordpp::AuthorizationTokenType p0 = (discordpp::AuthorizationTokenType)tokenType;
	const char *p1 = token.utf8().get_data();

	obj->FetchCurrentUser(p0, p1, [callback](auto result, auto id, auto name) {
		discordpp::ClientResult *t_p0 = (discordpp::ClientResult *)memalloc(sizeof(discordpp::ClientResult));
		*t_p0 = result;
		DiscordppClientResult *p0 = memnew(DiscordppClientResult{ t_p0 });

		int64_t p1 = (int64_t)id;
		String p2 = String(name.c_str());
		callback.call(p0, p1, p2);
	});
}

void DiscordppClient::GetProvisionalToken(int64_t applicationId, DiscordppAuthenticationExternalAuthType::Enum externalAuthType, String externalAuthToken, Callable callback) {
	int64_t p0 = applicationId;
	discordpp::AuthenticationExternalAuthType p1 = (discordpp::AuthenticationExternalAuthType)externalAuthType;
	const char *p2 = externalAuthToken.utf8().get_data();

	obj->GetProvisionalToken(p0, p1, p2, [callback](auto result, auto accessToken, auto refreshToken, auto tokenType, auto expiresIn, auto scopes) {
		discordpp::ClientResult *t_p0 = (discordpp::ClientResult *)memalloc(sizeof(discordpp::ClientResult));
		*t_p0 = result;
		DiscordppClientResult *p0 = memnew(DiscordppClientResult{ t_p0 });

		String p1 = String(accessToken.c_str());
		String p2 = String(refreshToken.c_str());
		DiscordppAuthorizationTokenType::Enum p3 = (DiscordppAuthorizationTokenType::Enum)tokenType;
		int64_t p4 = (int64_t)expiresIn;
		String p5 = String(scopes.c_str());
		callback.call(p0, p1, p2, p3, p4, p5);
	});
}

void DiscordppClient::GetToken(int64_t applicationId, String code, String codeVerifier, String redirectUri, Callable callback) {
	int64_t p0 = applicationId;
	const char *p1 = code.utf8().get_data();
	const char *p2 = codeVerifier.utf8().get_data();
	const char *p3 = redirectUri.utf8().get_data();

	obj->GetToken(p0, p1, p2, p3, [callback](auto result, auto accessToken, auto refreshToken, auto tokenType, auto expiresIn, auto scopes) {
		discordpp::ClientResult *t_p0 = (discordpp::ClientResult *)memalloc(sizeof(discordpp::ClientResult));
		*t_p0 = result;
		DiscordppClientResult *p0 = memnew(DiscordppClientResult{ t_p0 });

		String p1 = String(accessToken.c_str());
		String p2 = String(refreshToken.c_str());
		DiscordppAuthorizationTokenType::Enum p3 = (DiscordppAuthorizationTokenType::Enum)tokenType;
		int64_t p4 = (int64_t)expiresIn;
		String p5 = String(scopes.c_str());
		callback.call(p0, p1, p2, p3, p4, p5);
	});
}

void DiscordppClient::GetTokenFromDevice(DiscordppDeviceAuthorizationArgs *args, Callable callback) {
	discordpp::DeviceAuthorizationArgs p0 = *args->unwrap();

	obj->GetTokenFromDevice(p0, [callback](auto result, auto accessToken, auto refreshToken, auto tokenType, auto expiresIn, auto scopes) {
		discordpp::ClientResult *t_p0 = (discordpp::ClientResult *)memalloc(sizeof(discordpp::ClientResult));
		*t_p0 = result;
		DiscordppClientResult *p0 = memnew(DiscordppClientResult{ t_p0 });

		String p1 = String(accessToken.c_str());
		String p2 = String(refreshToken.c_str());
		DiscordppAuthorizationTokenType::Enum p3 = (DiscordppAuthorizationTokenType::Enum)tokenType;
		int64_t p4 = (int64_t)expiresIn;
		String p5 = String(scopes.c_str());
		callback.call(p0, p1, p2, p3, p4, p5);
	});
}

void DiscordppClient::GetTokenFromDeviceProvisionalMerge(DiscordppDeviceAuthorizationArgs *args, DiscordppAuthenticationExternalAuthType::Enum externalAuthType, String externalAuthToken, Callable callback) {
	discordpp::DeviceAuthorizationArgs p0 = *args->unwrap();
	discordpp::AuthenticationExternalAuthType p1 = (discordpp::AuthenticationExternalAuthType)externalAuthType;
	const char *p2 = externalAuthToken.utf8().get_data();

	obj->GetTokenFromDeviceProvisionalMerge(p0, p1, p2, [callback](auto result, auto accessToken, auto refreshToken, auto tokenType, auto expiresIn, auto scopes) {
		discordpp::ClientResult *t_p0 = (discordpp::ClientResult *)memalloc(sizeof(discordpp::ClientResult));
		*t_p0 = result;
		DiscordppClientResult *p0 = memnew(DiscordppClientResult{ t_p0 });

		String p1 = String(accessToken.c_str());
		String p2 = String(refreshToken.c_str());
		DiscordppAuthorizationTokenType::Enum p3 = (DiscordppAuthorizationTokenType::Enum)tokenType;
		int64_t p4 = (int64_t)expiresIn;
		String p5 = String(scopes.c_str());
		callback.call(p0, p1, p2, p3, p4, p5);
	});
}

void DiscordppClient::GetTokenFromProvisionalMerge(int64_t applicationId, String code, String codeVerifier, String redirectUri, DiscordppAuthenticationExternalAuthType::Enum externalAuthType, String externalAuthToken, Callable callback) {
	int64_t p0 = applicationId;
	const char *p1 = code.utf8().get_data();
	const char *p2 = codeVerifier.utf8().get_data();
	const char *p3 = redirectUri.utf8().get_data();
	discordpp::AuthenticationExternalAuthType p4 = (discordpp::AuthenticationExternalAuthType)externalAuthType;
	const char *p5 = externalAuthToken.utf8().get_data();

	obj->GetTokenFromProvisionalMerge(p0, p1, p2, p3, p4, p5, [callback](auto result, auto accessToken, auto refreshToken, auto tokenType, auto expiresIn, auto scopes) {
		discordpp::ClientResult *t_p0 = (discordpp::ClientResult *)memalloc(sizeof(discordpp::ClientResult));
		*t_p0 = result;
		DiscordppClientResult *p0 = memnew(DiscordppClientResult{ t_p0 });

		String p1 = String(accessToken.c_str());
		String p2 = String(refreshToken.c_str());
		DiscordppAuthorizationTokenType::Enum p3 = (DiscordppAuthorizationTokenType::Enum)tokenType;
		int64_t p4 = (int64_t)expiresIn;
		String p5 = String(scopes.c_str());
		callback.call(p0, p1, p2, p3, p4, p5);
	});
}

bool DiscordppClient::IsAuthenticated() {
	return obj->IsAuthenticated();
}

void DiscordppClient::OpenAuthorizeDeviceScreen(int64_t clientId, String userCode) {
	int64_t p0 = clientId;
	const char *p1 = userCode.utf8().get_data();

	obj->OpenAuthorizeDeviceScreen(p0, p1);
}

void DiscordppClient::ProvisionalUserMergeCompleted(bool success) {
	bool p0 = success;

	obj->ProvisionalUserMergeCompleted(p0);
}

void DiscordppClient::RefreshToken(int64_t applicationId, String refreshToken, Callable callback) {
	int64_t p0 = applicationId;
	const char *p1 = refreshToken.utf8().get_data();

	obj->RefreshToken(p0, p1, [callback](auto result, auto accessToken, auto refreshToken, auto tokenType, auto expiresIn, auto scopes) {
		discordpp::ClientResult *t_p0 = (discordpp::ClientResult *)memalloc(sizeof(discordpp::ClientResult));
		*t_p0 = result;
		DiscordppClientResult *p0 = memnew(DiscordppClientResult{ t_p0 });

		String p1 = String(accessToken.c_str());
		String p2 = String(refreshToken.c_str());
		DiscordppAuthorizationTokenType::Enum p3 = (DiscordppAuthorizationTokenType::Enum)tokenType;
		int64_t p4 = (int64_t)expiresIn;
		String p5 = String(scopes.c_str());
		callback.call(p0, p1, p2, p3, p4, p5);
	});
}

void DiscordppClient::SetAuthorizeDeviceScreenClosedCallback(Callable cb) {
	obj->SetAuthorizeDeviceScreenClosedCallback([cb]() {
		cb.call();
	});
}

void DiscordppClient::SetGameWindowPid(int64_t pid) {
	int64_t p0 = pid;

	obj->SetGameWindowPid(p0);
}

void DiscordppClient::SetTokenExpirationCallback(Callable callback) {
	obj->SetTokenExpirationCallback([callback]() {
		callback.call();
	});
}

void DiscordppClient::UpdateProvisionalAccountDisplayName(String name, Callable callback) {
	const char *p0 = name.utf8().get_data();

	obj->UpdateProvisionalAccountDisplayName(p0, [callback](auto result) {
		discordpp::ClientResult *t_p0 = (discordpp::ClientResult *)memalloc(sizeof(discordpp::ClientResult));
		*t_p0 = result;
		DiscordppClientResult *p0 = memnew(DiscordppClientResult{ t_p0 });

		callback.call(p0);
	});
}

void DiscordppClient::UpdateToken(DiscordppAuthorizationTokenType::Enum tokenType, String token, Callable callback) {
	discordpp::AuthorizationTokenType p0 = (discordpp::AuthorizationTokenType)tokenType;
	const char *p1 = token.utf8().get_data();

	obj->UpdateToken(p0, p1, [callback](auto result) {
		discordpp::ClientResult *t_p0 = (discordpp::ClientResult *)memalloc(sizeof(discordpp::ClientResult));
		*t_p0 = result;
		DiscordppClientResult *p0 = memnew(DiscordppClientResult{ t_p0 });

		callback.call(p0);
	});
}

bool DiscordppClient::CanOpenMessageInDiscord(int64_t messageId) {
	int64_t p0 = messageId;

	return obj->CanOpenMessageInDiscord(p0);
}

void DiscordppClient::DeleteUserMessage(int64_t recipientId, int64_t messageId, Callable cb) {
	int64_t p0 = recipientId;
	int64_t p1 = messageId;

	obj->DeleteUserMessage(p0, p1, [cb](auto result) {
		discordpp::ClientResult *t_p0 = (discordpp::ClientResult *)memalloc(sizeof(discordpp::ClientResult));
		*t_p0 = result;
		DiscordppClientResult *p0 = memnew(DiscordppClientResult{ t_p0 });

		cb.call(p0);
	});
}

void DiscordppClient::EditUserMessage(int64_t recipientId, int64_t messageId, String content, Callable cb) {
	int64_t p0 = recipientId;
	int64_t p1 = messageId;
	const char *p2 = content.utf8().get_data();

	obj->EditUserMessage(p0, p1, p2, [cb](auto result) {
		discordpp::ClientResult *t_p0 = (discordpp::ClientResult *)memalloc(sizeof(discordpp::ClientResult));
		*t_p0 = result;
		DiscordppClientResult *p0 = memnew(DiscordppClientResult{ t_p0 });

		cb.call(p0);
	});
}

Variant DiscordppClient::GetChannelHandle(int64_t channelId) {
	int64_t p0 = channelId;

	auto r = obj->GetChannelHandle(p0);

	if (!r.has_value()) {
		return nullptr;
	}

	discordpp::ChannelHandle *t_r = (discordpp::ChannelHandle *)memalloc(sizeof(discordpp::ChannelHandle));
	*t_r = r.value();
	return Variant(memnew(DiscordppChannelHandle{ t_r }));
}

Variant DiscordppClient::GetMessageHandle(int64_t messageId) {
	int64_t p0 = messageId;

	auto r = obj->GetMessageHandle(p0);

	if (!r.has_value()) {
		return nullptr;
	}

	discordpp::MessageHandle *t_r = (discordpp::MessageHandle *)memalloc(sizeof(discordpp::MessageHandle));
	*t_r = r.value();
	return Variant(memnew(DiscordppMessageHandle{ t_r }));
}

void DiscordppClient::OpenMessageInDiscord(int64_t messageId, Callable provisionalUserMergeRequiredCallback, Callable callback) {
	int64_t p0 = messageId;

	obj->OpenMessageInDiscord(p0, [provisionalUserMergeRequiredCallback]() { provisionalUserMergeRequiredCallback.call(); }, [callback](auto result) {
        discordpp::ClientResult *t_p0 = (discordpp::ClientResult *)memalloc(sizeof(discordpp::ClientResult));
    *t_p0 = result;
    DiscordppClientResult *p0 = memnew(DiscordppClientResult { t_p0 });
    
        callback.call(p0); });
}

void DiscordppClient::SendLobbyMessage(int64_t lobbyId, String content, Callable cb) {
	int64_t p0 = lobbyId;
	const char *p1 = content.utf8().get_data();

	obj->SendLobbyMessage(p0, p1, [cb](auto result, auto messageId) {
		discordpp::ClientResult *t_p0 = (discordpp::ClientResult *)memalloc(sizeof(discordpp::ClientResult));
		*t_p0 = result;
		DiscordppClientResult *p0 = memnew(DiscordppClientResult{ t_p0 });

		int64_t p1 = (int64_t)messageId;
		cb.call(p0, p1);
	});
}

void DiscordppClient::SendLobbyMessageWithMetadata(int64_t lobbyId, String content, TypedDictionary<String, String> metadata, Callable cb) {
	int64_t p0 = lobbyId;
	const char *p1 = content.utf8().get_data();
	std::unordered_map<std::string, std::string> p2 = std::unordered_map<std::string, std::string>();
	auto k_p2 = metadata.keys();

	for (int i = 0; i < k_p2.size(); i++) {
		auto k = k_p2[i];
		auto v = metadata[k];
		auto k_s = k.stringify().utf8().get_data();
		auto v_s = v.stringify().utf8().get_data();
		p2[k_s] = v_s;
	}

	obj->SendLobbyMessageWithMetadata(p0, p1, p2, [cb](auto result, auto messageId) {
		discordpp::ClientResult *t_p0 = (discordpp::ClientResult *)memalloc(sizeof(discordpp::ClientResult));
		*t_p0 = result;
		DiscordppClientResult *p0 = memnew(DiscordppClientResult{ t_p0 });

		int64_t p1 = (int64_t)messageId;
		cb.call(p0, p1);
	});
}

void DiscordppClient::SendUserMessage(int64_t recipientId, String content, Callable cb) {
	int64_t p0 = recipientId;
	const char *p1 = content.utf8().get_data();

	obj->SendUserMessage(p0, p1, [cb](auto result, auto messageId) {
		discordpp::ClientResult *t_p0 = (discordpp::ClientResult *)memalloc(sizeof(discordpp::ClientResult));
		*t_p0 = result;
		DiscordppClientResult *p0 = memnew(DiscordppClientResult{ t_p0 });

		int64_t p1 = (int64_t)messageId;
		cb.call(p0, p1);
	});
}

void DiscordppClient::SendUserMessageWithMetadata(int64_t recipientId, String content, TypedDictionary<String, String> metadata, Callable cb) {
	int64_t p0 = recipientId;
	const char *p1 = content.utf8().get_data();
	std::unordered_map<std::string, std::string> p2 = std::unordered_map<std::string, std::string>();
	auto k_p2 = metadata.keys();

	for (int i = 0; i < k_p2.size(); i++) {
		auto k = k_p2[i];
		auto v = metadata[k];
		auto k_s = k.stringify().utf8().get_data();
		auto v_s = v.stringify().utf8().get_data();
		p2[k_s] = v_s;
	}

	obj->SendUserMessageWithMetadata(p0, p1, p2, [cb](auto result, auto messageId) {
		discordpp::ClientResult *t_p0 = (discordpp::ClientResult *)memalloc(sizeof(discordpp::ClientResult));
		*t_p0 = result;
		DiscordppClientResult *p0 = memnew(DiscordppClientResult{ t_p0 });

		int64_t p1 = (int64_t)messageId;
		cb.call(p0, p1);
	});
}

void DiscordppClient::SetMessageCreatedCallback(Callable cb) {
	obj->SetMessageCreatedCallback([cb](auto messageId) {
		int64_t p0 = (int64_t)messageId;
		cb.call(p0);
	});
}

void DiscordppClient::SetMessageDeletedCallback(Callable cb) {
	obj->SetMessageDeletedCallback([cb](auto messageId, auto channelId) {
		int64_t p0 = (int64_t)messageId;
		int64_t p1 = (int64_t)channelId;
		cb.call(p0, p1);
	});
}

void DiscordppClient::SetMessageUpdatedCallback(Callable cb) {
	obj->SetMessageUpdatedCallback([cb](auto messageId) {
		int64_t p0 = (int64_t)messageId;
		cb.call(p0);
	});
}

void DiscordppClient::SetShowingChat(bool showingChat) {
	bool p0 = showingChat;

	obj->SetShowingChat(p0);
}

void DiscordppClient::AddLogCallback(Callable callback, DiscordppLoggingSeverity::Enum minSeverity) {
	discordpp::LoggingSeverity p1 = (discordpp::LoggingSeverity)minSeverity;

	obj->AddLogCallback([callback](auto message, auto severity) {
		String p0 = String(message.c_str());
		DiscordppLoggingSeverity::Enum p1 = (DiscordppLoggingSeverity::Enum)severity;
		callback.call(p0, p1);
	},
			p1);
}

void DiscordppClient::AddVoiceLogCallback(Callable callback, DiscordppLoggingSeverity::Enum minSeverity) {
	discordpp::LoggingSeverity p1 = (discordpp::LoggingSeverity)minSeverity;

	obj->AddVoiceLogCallback([callback](auto message, auto severity) {
		String p0 = String(message.c_str());
		DiscordppLoggingSeverity::Enum p1 = (DiscordppLoggingSeverity::Enum)severity;
		callback.call(p0, p1);
	},
			p1);
}

void DiscordppClient::Connect() {
	obj->Connect();
}

void DiscordppClient::Disconnect() {
	obj->Disconnect();
}

DiscordppClientStatus::Enum DiscordppClient::GetStatus() {
	return (DiscordppClientStatus::Enum)obj->GetStatus();
}

bool DiscordppClient::SetLogDir(String path, DiscordppLoggingSeverity::Enum minSeverity) {
	const char *p0 = path.utf8().get_data();
	discordpp::LoggingSeverity p1 = (discordpp::LoggingSeverity)minSeverity;

	return obj->SetLogDir(p0, p1);
}

void DiscordppClient::SetStatusChangedCallback(Callable cb) {
	obj->SetStatusChangedCallback([cb](auto status, auto error, auto errorDetail) {
		DiscordppClientStatus::Enum p0 = (DiscordppClientStatus::Enum)status;
		DiscordppClientError::Enum p1 = (DiscordppClientError::Enum)error;
		int64_t p2 = (int64_t)errorDetail;
		cb.call(p0, p1, p2);
	});
}

void DiscordppClient::SetVoiceLogDir(String path, DiscordppLoggingSeverity::Enum minSeverity) {
	const char *p0 = path.utf8().get_data();
	discordpp::LoggingSeverity p1 = (discordpp::LoggingSeverity)minSeverity;

	obj->SetVoiceLogDir(p0, p1);
}

void DiscordppClient::CreateOrJoinLobby(String secret, Callable callback) {
	const char *p0 = secret.utf8().get_data();

	obj->CreateOrJoinLobby(p0, [callback](auto result, auto lobbyId) {
		discordpp::ClientResult *t_p0 = (discordpp::ClientResult *)memalloc(sizeof(discordpp::ClientResult));
		*t_p0 = result;
		DiscordppClientResult *p0 = memnew(DiscordppClientResult{ t_p0 });

		int64_t p1 = (int64_t)lobbyId;
		callback.call(p0, p1);
	});
}

void DiscordppClient::CreateOrJoinLobbyWithMetadata(String secret, TypedDictionary<String, String> lobbyMetadata, TypedDictionary<String, String> memberMetadata, Callable callback) {
	const char *p0 = secret.utf8().get_data();
	std::unordered_map<std::string, std::string> p1 = std::unordered_map<std::string, std::string>();
	auto k_p1 = lobbyMetadata.keys();

	for (int i = 0; i < k_p1.size(); i++) {
		auto k = k_p1[i];
		auto v = lobbyMetadata[k];
		auto k_s = k.stringify().utf8().get_data();
		auto v_s = v.stringify().utf8().get_data();
		p1[k_s] = v_s;
	}
	std::unordered_map<std::string, std::string> p2 = std::unordered_map<std::string, std::string>();
	auto k_p2 = memberMetadata.keys();

	for (int i = 0; i < k_p2.size(); i++) {
		auto k = k_p2[i];
		auto v = memberMetadata[k];
		auto k_s = k.stringify().utf8().get_data();
		auto v_s = v.stringify().utf8().get_data();
		p2[k_s] = v_s;
	}

	obj->CreateOrJoinLobbyWithMetadata(p0, p1, p2, [callback](auto result, auto lobbyId) {
		discordpp::ClientResult *t_p0 = (discordpp::ClientResult *)memalloc(sizeof(discordpp::ClientResult));
		*t_p0 = result;
		DiscordppClientResult *p0 = memnew(DiscordppClientResult{ t_p0 });

		int64_t p1 = (int64_t)lobbyId;
		callback.call(p0, p1);
	});
}

void DiscordppClient::GetGuildChannels(int64_t guildId, Callable cb) {
	int64_t p0 = guildId;

	obj->GetGuildChannels(p0, [cb](auto result, auto guildChannels) {
		discordpp::ClientResult *t_p0 = (discordpp::ClientResult *)memalloc(sizeof(discordpp::ClientResult));
		*t_p0 = result;
		DiscordppClientResult *p0 = memnew(DiscordppClientResult{ t_p0 });

		TypedArray<DiscordppGuildChannel> p1 = TypedArray<DiscordppGuildChannel>();

		for (auto i : guildChannels) {
			p1.push_back(memnew(DiscordppGuildChannel{ &i }));
		}

		cb.call(p0, p1);
	});
}

Variant DiscordppClient::GetLobbyHandle(int64_t lobbyId) {
	int64_t p0 = lobbyId;

	auto r = obj->GetLobbyHandle(p0);

	if (!r.has_value()) {
		return nullptr;
	}

	discordpp::LobbyHandle *t_r = (discordpp::LobbyHandle *)memalloc(sizeof(discordpp::LobbyHandle));
	*t_r = r.value();
	return Variant(memnew(DiscordppLobbyHandle{ t_r }));
}

TypedArray<int64_t> DiscordppClient::GetLobbyIds() {
	auto r = obj->GetLobbyIds();
	TypedArray<int64_t> t_r = TypedArray<int64_t>();

	for (auto i : r) {
		t_r.push_back((int64_t)i);
	}

	return t_r;
}

void DiscordppClient::GetUserGuilds(Callable cb) {
	obj->GetUserGuilds([cb](auto result, auto guilds) {
		discordpp::ClientResult *t_p0 = (discordpp::ClientResult *)memalloc(sizeof(discordpp::ClientResult));
		*t_p0 = result;
		DiscordppClientResult *p0 = memnew(DiscordppClientResult{ t_p0 });

		TypedArray<DiscordppGuildMinimal> p1 = TypedArray<DiscordppGuildMinimal>();

		for (auto i : guilds) {
			p1.push_back(memnew(DiscordppGuildMinimal{ &i }));
		}

		cb.call(p0, p1);
	});
}

void DiscordppClient::LeaveLobby(int64_t lobbyId, Callable callback) {
	int64_t p0 = lobbyId;

	obj->LeaveLobby(p0, [callback](auto result) {
		discordpp::ClientResult *t_p0 = (discordpp::ClientResult *)memalloc(sizeof(discordpp::ClientResult));
		*t_p0 = result;
		DiscordppClientResult *p0 = memnew(DiscordppClientResult{ t_p0 });

		callback.call(p0);
	});
}

void DiscordppClient::LinkChannelToLobby(int64_t lobbyId, int64_t channelId, Callable callback) {
	int64_t p0 = lobbyId;
	int64_t p1 = channelId;

	obj->LinkChannelToLobby(p0, p1, [callback](auto result) {
		discordpp::ClientResult *t_p0 = (discordpp::ClientResult *)memalloc(sizeof(discordpp::ClientResult));
		*t_p0 = result;
		DiscordppClientResult *p0 = memnew(DiscordppClientResult{ t_p0 });

		callback.call(p0);
	});
}

void DiscordppClient::SetLobbyCreatedCallback(Callable cb) {
	obj->SetLobbyCreatedCallback([cb](auto lobbyId) {
		int64_t p0 = (int64_t)lobbyId;
		cb.call(p0);
	});
}

void DiscordppClient::SetLobbyDeletedCallback(Callable cb) {
	obj->SetLobbyDeletedCallback([cb](auto lobbyId) {
		int64_t p0 = (int64_t)lobbyId;
		cb.call(p0);
	});
}

void DiscordppClient::SetLobbyMemberAddedCallback(Callable cb) {
	obj->SetLobbyMemberAddedCallback([cb](auto lobbyId, auto memberId) {
		int64_t p0 = (int64_t)lobbyId;
		int64_t p1 = (int64_t)memberId;
		cb.call(p0, p1);
	});
}

void DiscordppClient::SetLobbyMemberRemovedCallback(Callable cb) {
	obj->SetLobbyMemberRemovedCallback([cb](auto lobbyId, auto memberId) {
		int64_t p0 = (int64_t)lobbyId;
		int64_t p1 = (int64_t)memberId;
		cb.call(p0, p1);
	});
}

void DiscordppClient::SetLobbyMemberUpdatedCallback(Callable cb) {
	obj->SetLobbyMemberUpdatedCallback([cb](auto lobbyId, auto memberId) {
		int64_t p0 = (int64_t)lobbyId;
		int64_t p1 = (int64_t)memberId;
		cb.call(p0, p1);
	});
}

void DiscordppClient::SetLobbyUpdatedCallback(Callable cb) {
	obj->SetLobbyUpdatedCallback([cb](auto lobbyId) {
		int64_t p0 = (int64_t)lobbyId;
		cb.call(p0);
	});
}

void DiscordppClient::UnlinkChannelFromLobby(int64_t lobbyId, Callable callback) {
	int64_t p0 = lobbyId;

	obj->UnlinkChannelFromLobby(p0, [callback](auto result) {
		discordpp::ClientResult *t_p0 = (discordpp::ClientResult *)memalloc(sizeof(discordpp::ClientResult));
		*t_p0 = result;
		DiscordppClientResult *p0 = memnew(DiscordppClientResult{ t_p0 });

		callback.call(p0);
	});
}

void DiscordppClient::AcceptActivityInvite(DiscordppActivityInvite *invite, Callable cb) {
	discordpp::ActivityInvite p0 = *invite->unwrap();

	obj->AcceptActivityInvite(p0, [cb](auto result, auto joinSecret) {
		discordpp::ClientResult *t_p0 = (discordpp::ClientResult *)memalloc(sizeof(discordpp::ClientResult));
		*t_p0 = result;
		DiscordppClientResult *p0 = memnew(DiscordppClientResult{ t_p0 });

		String p1 = String(joinSecret.c_str());
		cb.call(p0, p1);
	});
}

void DiscordppClient::ClearRichPresence() {
	obj->ClearRichPresence();
}

bool DiscordppClient::RegisterLaunchCommand(int64_t applicationId, String command) {
	int64_t p0 = applicationId;
	const char *p1 = command.utf8().get_data();

	return obj->RegisterLaunchCommand(p0, p1);
}

bool DiscordppClient::RegisterLaunchSteamApplication(int64_t applicationId, int64_t steamAppId) {
	int64_t p0 = applicationId;
	int64_t p1 = steamAppId;

	return obj->RegisterLaunchSteamApplication(p0, p1);
}

void DiscordppClient::SendActivityInvite(int64_t userId, String content, Callable cb) {
	int64_t p0 = userId;
	const char *p1 = content.utf8().get_data();

	obj->SendActivityInvite(p0, p1, [cb](auto result) {
		discordpp::ClientResult *t_p0 = (discordpp::ClientResult *)memalloc(sizeof(discordpp::ClientResult));
		*t_p0 = result;
		DiscordppClientResult *p0 = memnew(DiscordppClientResult{ t_p0 });

		cb.call(p0);
	});
}

void DiscordppClient::SendActivityJoinRequest(int64_t userId, Callable cb) {
	int64_t p0 = userId;

	obj->SendActivityJoinRequest(p0, [cb](auto result) {
		discordpp::ClientResult *t_p0 = (discordpp::ClientResult *)memalloc(sizeof(discordpp::ClientResult));
		*t_p0 = result;
		DiscordppClientResult *p0 = memnew(DiscordppClientResult{ t_p0 });

		cb.call(p0);
	});
}

void DiscordppClient::SendActivityJoinRequestReply(DiscordppActivityInvite *invite, Callable cb) {
	discordpp::ActivityInvite p0 = *invite->unwrap();

	obj->SendActivityJoinRequestReply(p0, [cb](auto result) {
		discordpp::ClientResult *t_p0 = (discordpp::ClientResult *)memalloc(sizeof(discordpp::ClientResult));
		*t_p0 = result;
		DiscordppClientResult *p0 = memnew(DiscordppClientResult{ t_p0 });

		cb.call(p0);
	});
}

void DiscordppClient::SetActivityInviteCreatedCallback(Callable cb) {
	obj->SetActivityInviteCreatedCallback([cb](auto invite) {
		discordpp::ActivityInvite *t_p0 = (discordpp::ActivityInvite *)memalloc(sizeof(discordpp::ActivityInvite));
		*t_p0 = invite;
		DiscordppActivityInvite *p0 = memnew(DiscordppActivityInvite{ t_p0 });

		cb.call(p0);
	});
}

void DiscordppClient::SetActivityInviteUpdatedCallback(Callable cb) {
	obj->SetActivityInviteUpdatedCallback([cb](auto invite) {
		discordpp::ActivityInvite *t_p0 = (discordpp::ActivityInvite *)memalloc(sizeof(discordpp::ActivityInvite));
		*t_p0 = invite;
		DiscordppActivityInvite *p0 = memnew(DiscordppActivityInvite{ t_p0 });

		cb.call(p0);
	});
}

void DiscordppClient::SetActivityJoinCallback(Callable cb) {
	obj->SetActivityJoinCallback([cb](auto joinSecret) {
		String p0 = String(joinSecret.c_str());
		cb.call(p0);
	});
}

void DiscordppClient::SetOnlineStatus(DiscordppStatusType::Enum status, Callable callback) {
	discordpp::StatusType p0 = (discordpp::StatusType)status;

	obj->SetOnlineStatus(p0, [callback](auto result) {
		discordpp::ClientResult *t_p0 = (discordpp::ClientResult *)memalloc(sizeof(discordpp::ClientResult));
		*t_p0 = result;
		DiscordppClientResult *p0 = memnew(DiscordppClientResult{ t_p0 });

		callback.call(p0);
	});
}

void DiscordppClient::UpdateRichPresence(DiscordppActivity *activity, Callable cb) {
	discordpp::Activity p0 = *activity->unwrap();

	obj->UpdateRichPresence(p0, [cb](auto result) {
		discordpp::ClientResult *t_p0 = (discordpp::ClientResult *)memalloc(sizeof(discordpp::ClientResult));
		*t_p0 = result;
		DiscordppClientResult *p0 = memnew(DiscordppClientResult{ t_p0 });

		cb.call(p0);
	});
}

void DiscordppClient::AcceptDiscordFriendRequest(int64_t userId, Callable cb) {
	int64_t p0 = userId;

	obj->AcceptDiscordFriendRequest(p0, [cb](auto result) {
		discordpp::ClientResult *t_p0 = (discordpp::ClientResult *)memalloc(sizeof(discordpp::ClientResult));
		*t_p0 = result;
		DiscordppClientResult *p0 = memnew(DiscordppClientResult{ t_p0 });

		cb.call(p0);
	});
}

void DiscordppClient::AcceptGameFriendRequest(int64_t userId, Callable cb) {
	int64_t p0 = userId;

	obj->AcceptGameFriendRequest(p0, [cb](auto result) {
		discordpp::ClientResult *t_p0 = (discordpp::ClientResult *)memalloc(sizeof(discordpp::ClientResult));
		*t_p0 = result;
		DiscordppClientResult *p0 = memnew(DiscordppClientResult{ t_p0 });

		cb.call(p0);
	});
}

void DiscordppClient::BlockUser(int64_t userId, Callable cb) {
	int64_t p0 = userId;

	obj->BlockUser(p0, [cb](auto result) {
		discordpp::ClientResult *t_p0 = (discordpp::ClientResult *)memalloc(sizeof(discordpp::ClientResult));
		*t_p0 = result;
		DiscordppClientResult *p0 = memnew(DiscordppClientResult{ t_p0 });

		cb.call(p0);
	});
}

void DiscordppClient::CancelDiscordFriendRequest(int64_t userId, Callable cb) {
	int64_t p0 = userId;

	obj->CancelDiscordFriendRequest(p0, [cb](auto result) {
		discordpp::ClientResult *t_p0 = (discordpp::ClientResult *)memalloc(sizeof(discordpp::ClientResult));
		*t_p0 = result;
		DiscordppClientResult *p0 = memnew(DiscordppClientResult{ t_p0 });

		cb.call(p0);
	});
}

void DiscordppClient::CancelGameFriendRequest(int64_t userId, Callable cb) {
	int64_t p0 = userId;

	obj->CancelGameFriendRequest(p0, [cb](auto result) {
		discordpp::ClientResult *t_p0 = (discordpp::ClientResult *)memalloc(sizeof(discordpp::ClientResult));
		*t_p0 = result;
		DiscordppClientResult *p0 = memnew(DiscordppClientResult{ t_p0 });

		cb.call(p0);
	});
}

DiscordppRelationshipHandle *DiscordppClient::GetRelationshipHandle(int64_t userId) {
	int64_t p0 = userId;

	discordpp::RelationshipHandle *t_r = (discordpp::RelationshipHandle *)memalloc(sizeof(discordpp::RelationshipHandle));
	*t_r = obj->GetRelationshipHandle(p0);
	return memnew(DiscordppRelationshipHandle{ t_r });
}

TypedArray<DiscordppRelationshipHandle> DiscordppClient::GetRelationships() {
	auto r = obj->GetRelationships();
	TypedArray<DiscordppRelationshipHandle> t_r = TypedArray<DiscordppRelationshipHandle>();

	for (auto i : r) {
		t_r.push_back(memnew(DiscordppRelationshipHandle{ &i }));
	}

	return t_r;
}

void DiscordppClient::RejectDiscordFriendRequest(int64_t userId, Callable cb) {
	int64_t p0 = userId;

	obj->RejectDiscordFriendRequest(p0, [cb](auto result) {
		discordpp::ClientResult *t_p0 = (discordpp::ClientResult *)memalloc(sizeof(discordpp::ClientResult));
		*t_p0 = result;
		DiscordppClientResult *p0 = memnew(DiscordppClientResult{ t_p0 });

		cb.call(p0);
	});
}

void DiscordppClient::RejectGameFriendRequest(int64_t userId, Callable cb) {
	int64_t p0 = userId;

	obj->RejectGameFriendRequest(p0, [cb](auto result) {
		discordpp::ClientResult *t_p0 = (discordpp::ClientResult *)memalloc(sizeof(discordpp::ClientResult));
		*t_p0 = result;
		DiscordppClientResult *p0 = memnew(DiscordppClientResult{ t_p0 });

		cb.call(p0);
	});
}

void DiscordppClient::RemoveDiscordAndGameFriend(int64_t userId, Callable cb) {
	int64_t p0 = userId;

	obj->RemoveDiscordAndGameFriend(p0, [cb](auto result) {
		discordpp::ClientResult *t_p0 = (discordpp::ClientResult *)memalloc(sizeof(discordpp::ClientResult));
		*t_p0 = result;
		DiscordppClientResult *p0 = memnew(DiscordppClientResult{ t_p0 });

		cb.call(p0);
	});
}

void DiscordppClient::RemoveGameFriend(int64_t userId, Callable cb) {
	int64_t p0 = userId;

	obj->RemoveGameFriend(p0, [cb](auto result) {
		discordpp::ClientResult *t_p0 = (discordpp::ClientResult *)memalloc(sizeof(discordpp::ClientResult));
		*t_p0 = result;
		DiscordppClientResult *p0 = memnew(DiscordppClientResult{ t_p0 });

		cb.call(p0);
	});
}

TypedArray<DiscordppUserHandle> DiscordppClient::SearchFriendsByUsername(String searchStr) {
	const char *p0 = searchStr.utf8().get_data();

	auto r = obj->SearchFriendsByUsername(p0);
	TypedArray<DiscordppUserHandle> t_r = TypedArray<DiscordppUserHandle>();

	for (auto i : r) {
		t_r.push_back(memnew(DiscordppUserHandle{ &i }));
	}

	return t_r;
}

void DiscordppClient::SendDiscordFriendRequest(String username, Callable cb) {
	const char *p0 = username.utf8().get_data();

	obj->SendDiscordFriendRequest(p0, [cb](auto result) {
		discordpp::ClientResult *t_p0 = (discordpp::ClientResult *)memalloc(sizeof(discordpp::ClientResult));
		*t_p0 = result;
		DiscordppClientResult *p0 = memnew(DiscordppClientResult{ t_p0 });

		cb.call(p0);
	});
}

void DiscordppClient::SendDiscordFriendRequestById(int64_t userId, Callable cb) {
	int64_t p0 = userId;

	obj->SendDiscordFriendRequestById(p0, [cb](auto result) {
		discordpp::ClientResult *t_p0 = (discordpp::ClientResult *)memalloc(sizeof(discordpp::ClientResult));
		*t_p0 = result;
		DiscordppClientResult *p0 = memnew(DiscordppClientResult{ t_p0 });

		cb.call(p0);
	});
}

void DiscordppClient::SendGameFriendRequest(String username, Callable cb) {
	const char *p0 = username.utf8().get_data();

	obj->SendGameFriendRequest(p0, [cb](auto result) {
		discordpp::ClientResult *t_p0 = (discordpp::ClientResult *)memalloc(sizeof(discordpp::ClientResult));
		*t_p0 = result;
		DiscordppClientResult *p0 = memnew(DiscordppClientResult{ t_p0 });

		cb.call(p0);
	});
}

void DiscordppClient::SendGameFriendRequestById(int64_t userId, Callable cb) {
	int64_t p0 = userId;

	obj->SendGameFriendRequestById(p0, [cb](auto result) {
		discordpp::ClientResult *t_p0 = (discordpp::ClientResult *)memalloc(sizeof(discordpp::ClientResult));
		*t_p0 = result;
		DiscordppClientResult *p0 = memnew(DiscordppClientResult{ t_p0 });

		cb.call(p0);
	});
}

void DiscordppClient::SetRelationshipCreatedCallback(Callable cb) {
	obj->SetRelationshipCreatedCallback([cb](auto userId, auto isDiscordRelationshipUpdate) {
		int64_t p0 = (int64_t)userId;
		bool p1 = isDiscordRelationshipUpdate;
		cb.call(p0, p1);
	});
}

void DiscordppClient::SetRelationshipDeletedCallback(Callable cb) {
	obj->SetRelationshipDeletedCallback([cb](auto userId, auto isDiscordRelationshipUpdate) {
		int64_t p0 = (int64_t)userId;
		bool p1 = isDiscordRelationshipUpdate;
		cb.call(p0, p1);
	});
}

void DiscordppClient::UnblockUser(int64_t userId, Callable cb) {
	int64_t p0 = userId;

	obj->UnblockUser(p0, [cb](auto result) {
		discordpp::ClientResult *t_p0 = (discordpp::ClientResult *)memalloc(sizeof(discordpp::ClientResult));
		*t_p0 = result;
		DiscordppClientResult *p0 = memnew(DiscordppClientResult{ t_p0 });

		cb.call(p0);
	});
}

DiscordppUserHandle *DiscordppClient::GetCurrentUser() {
	discordpp::UserHandle *t_r = (discordpp::UserHandle *)memalloc(sizeof(discordpp::UserHandle));
	*t_r = obj->GetCurrentUser();
	return memnew(DiscordppUserHandle{ t_r });
}

void DiscordppClient::GetDiscordClientConnectedUser(int64_t applicationId, Callable callback) {
	int64_t p0 = applicationId;

	obj->GetDiscordClientConnectedUser(p0, [callback](auto result, auto user) {
		discordpp::ClientResult *t_p0 = (discordpp::ClientResult *)memalloc(sizeof(discordpp::ClientResult));
		*t_p0 = result;
		DiscordppClientResult *p0 = memnew(DiscordppClientResult{ t_p0 });

		Variant p1;

		if (!user.has_value()) {
			p1 = nullptr;
		} else {
			discordpp::UserHandle *t = (discordpp::UserHandle *)memalloc(sizeof(discordpp::UserHandle));
			*t = user.value();
			p1 = Variant(memnew(DiscordppUserHandle{ t }));
		}

		callback.call(p0, p1);
	});
}

Variant DiscordppClient::GetUser(int64_t userId) {
	int64_t p0 = userId;

	auto r = obj->GetUser(p0);

	if (!r.has_value()) {
		return nullptr;
	}

	discordpp::UserHandle *t_r = (discordpp::UserHandle *)memalloc(sizeof(discordpp::UserHandle));
	*t_r = r.value();
	return Variant(memnew(DiscordppUserHandle{ t_r }));
}

void DiscordppClient::SetUserUpdatedCallback(Callable cb) {
	obj->SetUserUpdatedCallback([cb](auto userId) {
		int64_t p0 = (int64_t)userId;
		cb.call(p0);
	});
}

void DiscordppClient::_bind_methods() {
	ClassDB::bind_method(D_METHOD("Drop"),
			&DiscordppClient::Drop);

	ClassDB::bind_method(D_METHOD("ErrorToString", "type"),
			&DiscordppClient::ErrorToString);

	ClassDB::bind_method(D_METHOD("GetDefaultAudioDeviceId"),
			&DiscordppClient::GetDefaultAudioDeviceId);

	ClassDB::bind_method(D_METHOD("GetDefaultCommunicationScopes"),
			&DiscordppClient::GetDefaultCommunicationScopes);

	ClassDB::bind_method(D_METHOD("GetDefaultPresenceScopes"),
			&DiscordppClient::GetDefaultPresenceScopes);

	ClassDB::bind_method(D_METHOD("GetVersionHash"),
			&DiscordppClient::GetVersionHash);

	ClassDB::bind_method(D_METHOD("GetVersionMajor"),
			&DiscordppClient::GetVersionMajor);

	ClassDB::bind_method(D_METHOD("GetVersionMinor"),
			&DiscordppClient::GetVersionMinor);

	ClassDB::bind_method(D_METHOD("GetVersionPatch"),
			&DiscordppClient::GetVersionPatch);

	ClassDB::bind_method(D_METHOD("StatusToString", "type"),
			&DiscordppClient::StatusToString);

	ClassDB::bind_method(D_METHOD("ThreadToString", "type"),
			&DiscordppClient::ThreadToString);

	ClassDB::bind_method(D_METHOD("EndCall", "channelId", "callback"),
			&DiscordppClient::EndCall);

	ClassDB::bind_method(D_METHOD("EndCalls", "callback"),
			&DiscordppClient::EndCalls);

	ClassDB::bind_method(D_METHOD("GetCall", "channelId"),
			&DiscordppClient::GetCall);

	ClassDB::bind_method(D_METHOD("GetCalls"),
			&DiscordppClient::GetCalls);

	ClassDB::bind_method(D_METHOD("GetCurrentInputDevice", "cb"),
			&DiscordppClient::GetCurrentInputDevice);

	ClassDB::bind_method(D_METHOD("GetCurrentOutputDevice", "cb"),
			&DiscordppClient::GetCurrentOutputDevice);

	ClassDB::bind_method(D_METHOD("GetInputDevices", "cb"),
			&DiscordppClient::GetInputDevices);

	ClassDB::bind_method(D_METHOD("GetInputVolume"),
			&DiscordppClient::GetInputVolume);

	ClassDB::bind_method(D_METHOD("GetOutputDevices", "cb"),
			&DiscordppClient::GetOutputDevices);

	ClassDB::bind_method(D_METHOD("GetOutputVolume"),
			&DiscordppClient::GetOutputVolume);

	ClassDB::bind_method(D_METHOD("GetSelfDeafAll"),
			&DiscordppClient::GetSelfDeafAll);

	ClassDB::bind_method(D_METHOD("GetSelfMuteAll"),
			&DiscordppClient::GetSelfMuteAll);

	ClassDB::bind_method(D_METHOD("SetAutomaticGainControl", "on"),
			&DiscordppClient::SetAutomaticGainControl);

	ClassDB::bind_method(D_METHOD("SetDeviceChangeCallback", "callback"),
			&DiscordppClient::SetDeviceChangeCallback);

	ClassDB::bind_method(D_METHOD("SetEchoCancellation", "on"),
			&DiscordppClient::SetEchoCancellation);

	ClassDB::bind_method(D_METHOD("SetInputDevice", "deviceId", "cb"),
			&DiscordppClient::SetInputDevice);

	ClassDB::bind_method(D_METHOD("SetInputVolume", "inputVolume"),
			&DiscordppClient::SetInputVolume);

	ClassDB::bind_method(D_METHOD("SetNoAudioInputCallback", "callback"),
			&DiscordppClient::SetNoAudioInputCallback);

	ClassDB::bind_method(D_METHOD("SetNoAudioInputThreshold", "dBFSThreshold"),
			&DiscordppClient::SetNoAudioInputThreshold);

	ClassDB::bind_method(D_METHOD("SetNoiseSuppression", "on"),
			&DiscordppClient::SetNoiseSuppression);

	ClassDB::bind_method(D_METHOD("SetOpusHardwareCoding", "encode", "decode"),
			&DiscordppClient::SetOpusHardwareCoding);

	ClassDB::bind_method(D_METHOD("SetOutputDevice", "deviceId", "cb"),
			&DiscordppClient::SetOutputDevice);

	ClassDB::bind_method(D_METHOD("SetOutputVolume", "outputVolume"),
			&DiscordppClient::SetOutputVolume);

	ClassDB::bind_method(D_METHOD("SetSelfDeafAll", "deaf"),
			&DiscordppClient::SetSelfDeafAll);

	ClassDB::bind_method(D_METHOD("SetSelfMuteAll", "mute"),
			&DiscordppClient::SetSelfMuteAll);

	ClassDB::bind_method(D_METHOD("SetSpeakerMode", "speakerMode"),
			&DiscordppClient::SetSpeakerMode);

	ClassDB::bind_method(D_METHOD("SetThreadPriority", "thread", "priority"),
			&DiscordppClient::SetThreadPriority);

	ClassDB::bind_method(D_METHOD("SetVoiceParticipantChangedCallback", "cb"),
			&DiscordppClient::SetVoiceParticipantChangedCallback);

	ClassDB::bind_method(D_METHOD("ShowAudioRoutePicker"),
			&DiscordppClient::ShowAudioRoutePicker);

	ClassDB::bind_method(D_METHOD("StartCall", "channelId"),
			&DiscordppClient::StartCall);

	ClassDB::bind_method(D_METHOD("StartCallWithAudioCallbacks", "lobbyId", "receivedCb", "capturedCb"),
			&DiscordppClient::StartCallWithAudioCallbacks);

	ClassDB::bind_method(D_METHOD("AbortAuthorize"),
			&DiscordppClient::AbortAuthorize);

	ClassDB::bind_method(D_METHOD("AbortGetTokenFromDevice"),
			&DiscordppClient::AbortGetTokenFromDevice);

	ClassDB::bind_method(D_METHOD("Authorize", "args", "callback"),
			&DiscordppClient::Authorize);

	ClassDB::bind_method(D_METHOD("CloseAuthorizeDeviceScreen"),
			&DiscordppClient::CloseAuthorizeDeviceScreen);

	ClassDB::bind_method(D_METHOD("CreateAuthorizationCodeVerifier"),
			&DiscordppClient::CreateAuthorizationCodeVerifier);

	ClassDB::bind_method(D_METHOD("FetchCurrentUser", "tokenType", "token", "callback"),
			&DiscordppClient::FetchCurrentUser);

	ClassDB::bind_method(D_METHOD("GetProvisionalToken", "applicationId", "externalAuthType", "externalAuthToken", "callback"),
			&DiscordppClient::GetProvisionalToken);

	ClassDB::bind_method(D_METHOD("GetToken", "applicationId", "code", "codeVerifier", "redirectUri", "callback"),
			&DiscordppClient::GetToken);

	ClassDB::bind_method(D_METHOD("GetTokenFromDevice", "args", "callback"),
			&DiscordppClient::GetTokenFromDevice);

	ClassDB::bind_method(D_METHOD("GetTokenFromDeviceProvisionalMerge", "args", "externalAuthType", "externalAuthToken", "callback"),
			&DiscordppClient::GetTokenFromDeviceProvisionalMerge);

	ClassDB::bind_method(D_METHOD("GetTokenFromProvisionalMerge", "applicationId", "code", "codeVerifier", "redirectUri", "externalAuthType", "externalAuthToken", "callback"),
			&DiscordppClient::GetTokenFromProvisionalMerge);

	ClassDB::bind_method(D_METHOD("IsAuthenticated"),
			&DiscordppClient::IsAuthenticated);

	ClassDB::bind_method(D_METHOD("OpenAuthorizeDeviceScreen", "clientId", "userCode"),
			&DiscordppClient::OpenAuthorizeDeviceScreen);

	ClassDB::bind_method(D_METHOD("ProvisionalUserMergeCompleted", "success"),
			&DiscordppClient::ProvisionalUserMergeCompleted);

	ClassDB::bind_method(D_METHOD("RefreshToken", "applicationId", "refreshToken", "callback"),
			&DiscordppClient::RefreshToken);

	ClassDB::bind_method(D_METHOD("SetAuthorizeDeviceScreenClosedCallback", "cb"),
			&DiscordppClient::SetAuthorizeDeviceScreenClosedCallback);

	ClassDB::bind_method(D_METHOD("SetGameWindowPid", "pid"),
			&DiscordppClient::SetGameWindowPid);

	ClassDB::bind_method(D_METHOD("SetTokenExpirationCallback", "callback"),
			&DiscordppClient::SetTokenExpirationCallback);

	ClassDB::bind_method(D_METHOD("UpdateProvisionalAccountDisplayName", "name", "callback"),
			&DiscordppClient::UpdateProvisionalAccountDisplayName);

	ClassDB::bind_method(D_METHOD("UpdateToken", "tokenType", "token", "callback"),
			&DiscordppClient::UpdateToken);

	ClassDB::bind_method(D_METHOD("CanOpenMessageInDiscord", "messageId"),
			&DiscordppClient::CanOpenMessageInDiscord);

	ClassDB::bind_method(D_METHOD("DeleteUserMessage", "recipientId", "messageId", "cb"),
			&DiscordppClient::DeleteUserMessage);

	ClassDB::bind_method(D_METHOD("EditUserMessage", "recipientId", "messageId", "content", "cb"),
			&DiscordppClient::EditUserMessage);

	ClassDB::bind_method(D_METHOD("GetChannelHandle", "channelId"),
			&DiscordppClient::GetChannelHandle);

	ClassDB::bind_method(D_METHOD("GetMessageHandle", "messageId"),
			&DiscordppClient::GetMessageHandle);

	ClassDB::bind_method(D_METHOD("OpenMessageInDiscord", "messageId", "provisionalUserMergeRequiredCallback", "callback"),
			&DiscordppClient::OpenMessageInDiscord);

	ClassDB::bind_method(D_METHOD("SendLobbyMessage", "lobbyId", "content", "cb"),
			&DiscordppClient::SendLobbyMessage);

	ClassDB::bind_method(D_METHOD("SendLobbyMessageWithMetadata", "lobbyId", "content", "metadata", "cb"),
			&DiscordppClient::SendLobbyMessageWithMetadata);

	ClassDB::bind_method(D_METHOD("SendUserMessage", "recipientId", "content", "cb"),
			&DiscordppClient::SendUserMessage);

	ClassDB::bind_method(D_METHOD("SendUserMessageWithMetadata", "recipientId", "content", "metadata", "cb"),
			&DiscordppClient::SendUserMessageWithMetadata);

	ClassDB::bind_method(D_METHOD("SetMessageCreatedCallback", "cb"),
			&DiscordppClient::SetMessageCreatedCallback);

	ClassDB::bind_method(D_METHOD("SetMessageDeletedCallback", "cb"),
			&DiscordppClient::SetMessageDeletedCallback);

	ClassDB::bind_method(D_METHOD("SetMessageUpdatedCallback", "cb"),
			&DiscordppClient::SetMessageUpdatedCallback);

	ClassDB::bind_method(D_METHOD("SetShowingChat", "showingChat"),
			&DiscordppClient::SetShowingChat);

	ClassDB::bind_method(D_METHOD("AddLogCallback", "callback", "minSeverity"),
			&DiscordppClient::AddLogCallback);

	ClassDB::bind_method(D_METHOD("AddVoiceLogCallback", "callback", "minSeverity"),
			&DiscordppClient::AddVoiceLogCallback);

	ClassDB::bind_method(D_METHOD("Connect"),
			&DiscordppClient::Connect);

	ClassDB::bind_method(D_METHOD("Disconnect"),
			&DiscordppClient::Disconnect);

	ClassDB::bind_method(D_METHOD("GetStatus"),
			&DiscordppClient::GetStatus);

	ClassDB::bind_method(D_METHOD("SetLogDir", "path", "minSeverity"),
			&DiscordppClient::SetLogDir);

	ClassDB::bind_method(D_METHOD("SetStatusChangedCallback", "cb"),
			&DiscordppClient::SetStatusChangedCallback);

	ClassDB::bind_method(D_METHOD("SetVoiceLogDir", "path", "minSeverity"),
			&DiscordppClient::SetVoiceLogDir);

	ClassDB::bind_method(D_METHOD("CreateOrJoinLobby", "secret", "callback"),
			&DiscordppClient::CreateOrJoinLobby);

	ClassDB::bind_method(D_METHOD("CreateOrJoinLobbyWithMetadata", "secret", "lobbyMetadata", "memberMetadata", "callback"),
			&DiscordppClient::CreateOrJoinLobbyWithMetadata);

	ClassDB::bind_method(D_METHOD("GetGuildChannels", "guildId", "cb"),
			&DiscordppClient::GetGuildChannels);

	ClassDB::bind_method(D_METHOD("GetLobbyHandle", "lobbyId"),
			&DiscordppClient::GetLobbyHandle);

	ClassDB::bind_method(D_METHOD("GetLobbyIds"),
			&DiscordppClient::GetLobbyIds);

	ClassDB::bind_method(D_METHOD("GetUserGuilds", "cb"),
			&DiscordppClient::GetUserGuilds);

	ClassDB::bind_method(D_METHOD("LeaveLobby", "lobbyId", "callback"),
			&DiscordppClient::LeaveLobby);

	ClassDB::bind_method(D_METHOD("LinkChannelToLobby", "lobbyId", "channelId", "callback"),
			&DiscordppClient::LinkChannelToLobby);

	ClassDB::bind_method(D_METHOD("SetLobbyCreatedCallback", "cb"),
			&DiscordppClient::SetLobbyCreatedCallback);

	ClassDB::bind_method(D_METHOD("SetLobbyDeletedCallback", "cb"),
			&DiscordppClient::SetLobbyDeletedCallback);

	ClassDB::bind_method(D_METHOD("SetLobbyMemberAddedCallback", "cb"),
			&DiscordppClient::SetLobbyMemberAddedCallback);

	ClassDB::bind_method(D_METHOD("SetLobbyMemberRemovedCallback", "cb"),
			&DiscordppClient::SetLobbyMemberRemovedCallback);

	ClassDB::bind_method(D_METHOD("SetLobbyMemberUpdatedCallback", "cb"),
			&DiscordppClient::SetLobbyMemberUpdatedCallback);

	ClassDB::bind_method(D_METHOD("SetLobbyUpdatedCallback", "cb"),
			&DiscordppClient::SetLobbyUpdatedCallback);

	ClassDB::bind_method(D_METHOD("UnlinkChannelFromLobby", "lobbyId", "callback"),
			&DiscordppClient::UnlinkChannelFromLobby);

	ClassDB::bind_method(D_METHOD("AcceptActivityInvite", "invite", "cb"),
			&DiscordppClient::AcceptActivityInvite);

	ClassDB::bind_method(D_METHOD("ClearRichPresence"),
			&DiscordppClient::ClearRichPresence);

	ClassDB::bind_method(D_METHOD("RegisterLaunchCommand", "applicationId", "command"),
			&DiscordppClient::RegisterLaunchCommand);

	ClassDB::bind_method(D_METHOD("RegisterLaunchSteamApplication", "applicationId", "steamAppId"),
			&DiscordppClient::RegisterLaunchSteamApplication);

	ClassDB::bind_method(D_METHOD("SendActivityInvite", "userId", "content", "cb"),
			&DiscordppClient::SendActivityInvite);

	ClassDB::bind_method(D_METHOD("SendActivityJoinRequest", "userId", "cb"),
			&DiscordppClient::SendActivityJoinRequest);

	ClassDB::bind_method(D_METHOD("SendActivityJoinRequestReply", "invite", "cb"),
			&DiscordppClient::SendActivityJoinRequestReply);

	ClassDB::bind_method(D_METHOD("SetActivityInviteCreatedCallback", "cb"),
			&DiscordppClient::SetActivityInviteCreatedCallback);

	ClassDB::bind_method(D_METHOD("SetActivityInviteUpdatedCallback", "cb"),
			&DiscordppClient::SetActivityInviteUpdatedCallback);

	ClassDB::bind_method(D_METHOD("SetActivityJoinCallback", "cb"),
			&DiscordppClient::SetActivityJoinCallback);

	ClassDB::bind_method(D_METHOD("SetOnlineStatus", "status", "callback"),
			&DiscordppClient::SetOnlineStatus);

	ClassDB::bind_method(D_METHOD("UpdateRichPresence", "activity", "cb"),
			&DiscordppClient::UpdateRichPresence);

	ClassDB::bind_method(D_METHOD("AcceptDiscordFriendRequest", "userId", "cb"),
			&DiscordppClient::AcceptDiscordFriendRequest);

	ClassDB::bind_method(D_METHOD("AcceptGameFriendRequest", "userId", "cb"),
			&DiscordppClient::AcceptGameFriendRequest);

	ClassDB::bind_method(D_METHOD("BlockUser", "userId", "cb"),
			&DiscordppClient::BlockUser);

	ClassDB::bind_method(D_METHOD("CancelDiscordFriendRequest", "userId", "cb"),
			&DiscordppClient::CancelDiscordFriendRequest);

	ClassDB::bind_method(D_METHOD("CancelGameFriendRequest", "userId", "cb"),
			&DiscordppClient::CancelGameFriendRequest);

	ClassDB::bind_method(D_METHOD("GetRelationshipHandle", "userId"),
			&DiscordppClient::GetRelationshipHandle);

	ClassDB::bind_method(D_METHOD("GetRelationships"),
			&DiscordppClient::GetRelationships);

	ClassDB::bind_method(D_METHOD("RejectDiscordFriendRequest", "userId", "cb"),
			&DiscordppClient::RejectDiscordFriendRequest);

	ClassDB::bind_method(D_METHOD("RejectGameFriendRequest", "userId", "cb"),
			&DiscordppClient::RejectGameFriendRequest);

	ClassDB::bind_method(D_METHOD("RemoveDiscordAndGameFriend", "userId", "cb"),
			&DiscordppClient::RemoveDiscordAndGameFriend);

	ClassDB::bind_method(D_METHOD("RemoveGameFriend", "userId", "cb"),
			&DiscordppClient::RemoveGameFriend);

	ClassDB::bind_method(D_METHOD("SearchFriendsByUsername", "searchStr"),
			&DiscordppClient::SearchFriendsByUsername);

	ClassDB::bind_method(D_METHOD("SendDiscordFriendRequest", "username", "cb"),
			&DiscordppClient::SendDiscordFriendRequest);

	ClassDB::bind_method(D_METHOD("SendDiscordFriendRequestById", "userId", "cb"),
			&DiscordppClient::SendDiscordFriendRequestById);

	ClassDB::bind_method(D_METHOD("SendGameFriendRequest", "username", "cb"),
			&DiscordppClient::SendGameFriendRequest);

	ClassDB::bind_method(D_METHOD("SendGameFriendRequestById", "userId", "cb"),
			&DiscordppClient::SendGameFriendRequestById);

	ClassDB::bind_method(D_METHOD("SetRelationshipCreatedCallback", "cb"),
			&DiscordppClient::SetRelationshipCreatedCallback);

	ClassDB::bind_method(D_METHOD("SetRelationshipDeletedCallback", "cb"),
			&DiscordppClient::SetRelationshipDeletedCallback);

	ClassDB::bind_method(D_METHOD("UnblockUser", "userId", "cb"),
			&DiscordppClient::UnblockUser);

	ClassDB::bind_method(D_METHOD("GetCurrentUser"),
			&DiscordppClient::GetCurrentUser);

	ClassDB::bind_method(D_METHOD("GetDiscordClientConnectedUser", "applicationId", "callback"),
			&DiscordppClient::GetDiscordClientConnectedUser);

	ClassDB::bind_method(D_METHOD("GetUser", "userId"),
			&DiscordppClient::GetUser);

	ClassDB::bind_method(D_METHOD("SetUserUpdatedCallback", "cb"),
			&DiscordppClient::SetUserUpdatedCallback);
}
