// AUTO-GENERATED
#include "discord_classes.h"

using namespace godot;

discordpp::Client *DiscordClient::unwrap() {
	return client;
}

void DiscordClient::end_call(uint64_t channel_id) {
	client->EndCall(channel_id, [this]() {
		this->emit_signal("end_call_callback");
	});
}

void DiscordClient::end_calls() {
	client->EndCalls([this]() {
		this->emit_signal("end_calls_callback");
	});
}

DiscordCall *DiscordClient::get_call(uint64_t channel_id) {
	auto r = client->GetCall(channel_id);
	auto t_r = (discordpp::Call *)memalloc(sizeof(discordpp::Call));
	*t_r = r;
	return memnew(DiscordCall{ t_r });
}

TypedArray<DiscordCall> DiscordClient::get_calls() {
	auto r = client->GetCalls();
	auto t_r = TypedArray<DiscordCall>();

	for (auto i_r : r) {
		t_r.push_back(memnew(DiscordCall{ &i_r }));
	}

	return t_r;
}

void DiscordClient::get_current_input_device() {
	client->GetCurrentInputDevice([this](discordpp::AudioDevice device) {
		auto t_device = (discordpp::AudioDevice *)memalloc(sizeof(discordpp::AudioDevice));
		*t_device = device;
		auto p0 = memnew(DiscordAudioDevice{ t_device });

		this->emit_signal("get_current_input_device_callback", p0);
	});
}

void DiscordClient::get_current_output_device() {
	client->GetCurrentOutputDevice([this](discordpp::AudioDevice device) {
		auto t_device = (discordpp::AudioDevice *)memalloc(sizeof(discordpp::AudioDevice));
		*t_device = device;
		auto p0 = memnew(DiscordAudioDevice{ t_device });

		this->emit_signal("get_current_output_device_callback", p0);
	});
}

void DiscordClient::get_input_devices() {
	client->GetInputDevices([this](std::vector<discordpp::AudioDevice> devices) {
		auto t_devices = TypedArray<DiscordAudioDevice>();

		for (auto i_devices : devices) {
			t_devices.push_back(memnew(DiscordAudioDevice{ &i_devices }));
		}

		auto p0 = t_devices;

		this->emit_signal("get_input_devices_callback", p0);
	});
}

float DiscordClient::get_input_volume() {
	auto r = client->GetInputVolume();
	return r;
}

void DiscordClient::get_output_devices() {
	client->GetOutputDevices([this](std::vector<discordpp::AudioDevice> devices) {
		auto t_devices = TypedArray<DiscordAudioDevice>();

		for (auto i_devices : devices) {
			t_devices.push_back(memnew(DiscordAudioDevice{ &i_devices }));
		}

		auto p0 = t_devices;

		this->emit_signal("get_output_devices_callback", p0);
	});
}

float DiscordClient::get_output_volume() {
	auto r = client->GetOutputVolume();
	return r;
}

bool DiscordClient::get_self_deaf_all() {
	auto r = client->GetSelfDeafAll();
	return r;
}

bool DiscordClient::get_self_mute_all() {
	auto r = client->GetSelfMuteAll();
	return r;
}

void DiscordClient::set_automatic_gain_control(bool on) {
	client->SetAutomaticGainControl(on);
}

void DiscordClient::set_device_change_callback() {
	client->SetDeviceChangeCallback([this](std::vector<discordpp::AudioDevice> inputDevices, std::vector<discordpp::AudioDevice> outputDevices) {
		auto t_inputDevices = TypedArray<DiscordAudioDevice>();

		for (auto i_inputDevices : inputDevices) {
			t_inputDevices.push_back(memnew(DiscordAudioDevice{ &i_inputDevices }));
		}

		auto p0 = t_inputDevices;

		auto t_outputDevices = TypedArray<DiscordAudioDevice>();

		for (auto i_outputDevices : outputDevices) {
			t_outputDevices.push_back(memnew(DiscordAudioDevice{ &i_outputDevices }));
		}

		auto p1 = t_outputDevices;

		this->emit_signal("set_device_change_callback_callback", p0, p1);
	});
}

void DiscordClient::set_echo_cancellation(bool on) {
	client->SetEchoCancellation(on);
}

void DiscordClient::set_input_device(String device_id) {
	auto p0 = device_id.utf8().get_data();
	client->SetInputDevice(p0, [this](discordpp::ClientResult result) {
		auto t_result = (discordpp::ClientResult *)memalloc(sizeof(discordpp::ClientResult));
		*t_result = result;
		auto p0 = memnew(DiscordClientResult{ t_result });

		this->emit_signal("set_input_device_callback", p0);
	});
}

void DiscordClient::set_input_volume(float input_volume) {
	client->SetInputVolume(input_volume);
}

void DiscordClient::set_no_audio_input_callback() {
	client->SetNoAudioInputCallback([this](bool inputDetected) {
		auto p0 = inputDetected;
		this->emit_signal("set_no_audio_input_callback_callback", p0);
	});
}

void DiscordClient::set_no_audio_input_threshold(float d_bfsthreshold) {
	client->SetNoAudioInputThreshold(d_bfsthreshold);
}

void DiscordClient::set_noise_suppression(bool on) {
	client->SetNoiseSuppression(on);
}

void DiscordClient::set_opus_hardware_coding(bool encode, bool decode) {
	client->SetOpusHardwareCoding(encode, decode);
}

void DiscordClient::set_output_device(String device_id) {
	auto p0 = device_id.utf8().get_data();
	client->SetOutputDevice(p0, [this](discordpp::ClientResult result) {
		auto t_result = (discordpp::ClientResult *)memalloc(sizeof(discordpp::ClientResult));
		*t_result = result;
		auto p0 = memnew(DiscordClientResult{ t_result });

		this->emit_signal("set_output_device_callback", p0);
	});
}

void DiscordClient::set_output_volume(float output_volume) {
	client->SetOutputVolume(output_volume);
}

void DiscordClient::set_self_deaf_all(bool deaf) {
	client->SetSelfDeafAll(deaf);
}

void DiscordClient::set_self_mute_all(bool mute) {
	client->SetSelfMuteAll(mute);
}

bool DiscordClient::set_speaker_mode(bool speaker_mode) {
	auto r = client->SetSpeakerMode(speaker_mode);
	return r;
}

void DiscordClient::set_thread_priority(DiscordClientThread::Enum thread, int32_t priority) {
	auto p0 = (discordpp::Client::Thread)thread;
	client->SetThreadPriority(p0, priority);
}

void DiscordClient::set_voice_participant_changed_callback() {
	client->SetVoiceParticipantChangedCallback([this](uint64_t lobbyId, uint64_t memberId, bool added) {
		auto p0 = lobbyId;
		auto p1 = memberId;
		auto p2 = added;
		this->emit_signal("set_voice_participant_changed_callback_callback", p0, p1, p2);
	});
}

bool DiscordClient::show_audio_route_picker() {
	auto r = client->ShowAudioRoutePicker();
	return r;
}

DiscordCall *DiscordClient::start_call(uint64_t channel_id) {
	auto r = client->StartCall(channel_id);
	auto t_r = (discordpp::Call *)memalloc(sizeof(discordpp::Call));
	*t_r = r;
	return memnew(DiscordCall{ t_r });
}

DiscordCall *DiscordClient::start_call_with_audio_callbacks(uint64_t lobby_id) {
	auto r = client->StartCallWithAudioCallbacks(lobby_id, [this](uint64_t userId, int16_t const *data, uint64_t samplesPerChannel, int32_t sampleRate, uint64_t channels, bool &outShouldMute) {
        auto p0 = userId;
auto p1 = data;
auto p2 = samplesPerChannel;
auto p3 = sampleRate;
auto p4 = channels;
auto p5 = outShouldMute;
        this->emit_signal("start_call_with_audio_callbacks_callback",p0,p1,p2,p3,p4,p5); }, [this](int16_t const *data, uint64_t samplesPerChannel, int32_t sampleRate, uint64_t channels) {
        auto p0 = data;
auto p1 = samplesPerChannel;
auto p2 = sampleRate;
auto p3 = channels;
        this->emit_signal("start_call_with_audio_callbacks_callback",p0,p1,p2,p3); });
	auto t_r = (discordpp::Call *)memalloc(sizeof(discordpp::Call));
	*t_r = r;
	return memnew(DiscordCall{ t_r });
}

void DiscordClient::abort_authorize() {
	client->AbortAuthorize();
}

void DiscordClient::abort_get_token_from_device() {
	client->AbortGetTokenFromDevice();
}

void DiscordClient::authorize(DiscordAuthorizationArgs *args) {
	auto p0 = *args->unwrap();
	client->Authorize(p0, [this](discordpp::ClientResult result, std::string code, std::string redirectUri) {
		auto t_result = (discordpp::ClientResult *)memalloc(sizeof(discordpp::ClientResult));
		*t_result = result;
		auto p0 = memnew(DiscordClientResult{ t_result });

		auto p1 = String(code.c_str());
		auto p2 = String(redirectUri.c_str());
		this->emit_signal("authorize_callback", p0, p1, p2);
	});
}

void DiscordClient::close_authorize_device_screen() {
	client->CloseAuthorizeDeviceScreen();
}

DiscordAuthorizationCodeVerifier *DiscordClient::create_authorization_code_verifier() {
	auto r = client->CreateAuthorizationCodeVerifier();
	auto t_r = (discordpp::AuthorizationCodeVerifier *)memalloc(sizeof(discordpp::AuthorizationCodeVerifier));
	*t_r = r;
	return memnew(DiscordAuthorizationCodeVerifier{ t_r });
}

void DiscordClient::fetch_current_user(DiscordAuthorizationTokenType::Enum token_type, String token) {
	auto p0 = (discordpp::AuthorizationTokenType)token_type;
	auto p1 = token.utf8().get_data();
	client->FetchCurrentUser(p0, p1, [this](discordpp::ClientResult result, uint64_t id, std::string name) {
		auto t_result = (discordpp::ClientResult *)memalloc(sizeof(discordpp::ClientResult));
		*t_result = result;
		auto p0 = memnew(DiscordClientResult{ t_result });

		auto p1 = id;
		auto p2 = String(name.c_str());
		this->emit_signal("fetch_current_user_callback", p0, p1, p2);
	});
}

void DiscordClient::get_provisional_token(uint64_t application_id, DiscordAuthenticationExternalAuthType::Enum external_auth_type, String external_auth_token) {
	auto p1 = (discordpp::AuthenticationExternalAuthType)external_auth_type;
	auto p2 = external_auth_token.utf8().get_data();
	client->GetProvisionalToken(application_id, p1, p2, [this](discordpp::ClientResult result, std::string accessToken, std::string refreshToken, discordpp::AuthorizationTokenType tokenType, int32_t expiresIn, std::string scopes) {
		auto t_result = (discordpp::ClientResult *)memalloc(sizeof(discordpp::ClientResult));
		*t_result = result;
		auto p0 = memnew(DiscordClientResult{ t_result });

		auto p1 = String(accessToken.c_str());
		auto p2 = String(refreshToken.c_str());
		auto p3 = (DiscordAuthorizationTokenType::Enum)tokenType;
		auto p4 = expiresIn;
		auto p5 = String(scopes.c_str());
		this->emit_signal("get_provisional_token_callback", p0, p1, p2, p3, p4, p5);
	});
}

void DiscordClient::get_token(uint64_t application_id, String code, String code_verifier, String redirect_uri) {
	auto p1 = code.utf8().get_data();
	auto p2 = code_verifier.utf8().get_data();
	auto p3 = redirect_uri.utf8().get_data();
	client->GetToken(application_id, p1, p2, p3, [this](discordpp::ClientResult result, std::string accessToken, std::string refreshToken, discordpp::AuthorizationTokenType tokenType, int32_t expiresIn, std::string scopes) {
		auto t_result = (discordpp::ClientResult *)memalloc(sizeof(discordpp::ClientResult));
		*t_result = result;
		auto p0 = memnew(DiscordClientResult{ t_result });

		auto p1 = String(accessToken.c_str());
		auto p2 = String(refreshToken.c_str());
		auto p3 = (DiscordAuthorizationTokenType::Enum)tokenType;
		auto p4 = expiresIn;
		auto p5 = String(scopes.c_str());
		this->emit_signal("get_token_callback", p0, p1, p2, p3, p4, p5);
	});
}

void DiscordClient::get_token_from_device(DiscordDeviceAuthorizationArgs *args) {
	auto p0 = *args->unwrap();
	client->GetTokenFromDevice(p0, [this](discordpp::ClientResult result, std::string accessToken, std::string refreshToken, discordpp::AuthorizationTokenType tokenType, int32_t expiresIn, std::string scopes) {
		auto t_result = (discordpp::ClientResult *)memalloc(sizeof(discordpp::ClientResult));
		*t_result = result;
		auto p0 = memnew(DiscordClientResult{ t_result });

		auto p1 = String(accessToken.c_str());
		auto p2 = String(refreshToken.c_str());
		auto p3 = (DiscordAuthorizationTokenType::Enum)tokenType;
		auto p4 = expiresIn;
		auto p5 = String(scopes.c_str());
		this->emit_signal("get_token_from_device_callback", p0, p1, p2, p3, p4, p5);
	});
}

void DiscordClient::get_token_from_device_provisional_merge(DiscordDeviceAuthorizationArgs *args, DiscordAuthenticationExternalAuthType::Enum external_auth_type, String external_auth_token) {
	auto p0 = *args->unwrap();
	auto p1 = (discordpp::AuthenticationExternalAuthType)external_auth_type;
	auto p2 = external_auth_token.utf8().get_data();
	client->GetTokenFromDeviceProvisionalMerge(p0, p1, p2, [this](discordpp::ClientResult result, std::string accessToken, std::string refreshToken, discordpp::AuthorizationTokenType tokenType, int32_t expiresIn, std::string scopes) {
		auto t_result = (discordpp::ClientResult *)memalloc(sizeof(discordpp::ClientResult));
		*t_result = result;
		auto p0 = memnew(DiscordClientResult{ t_result });

		auto p1 = String(accessToken.c_str());
		auto p2 = String(refreshToken.c_str());
		auto p3 = (DiscordAuthorizationTokenType::Enum)tokenType;
		auto p4 = expiresIn;
		auto p5 = String(scopes.c_str());
		this->emit_signal("get_token_from_device_provisional_merge_callback", p0, p1, p2, p3, p4, p5);
	});
}

void DiscordClient::get_token_from_provisional_merge(uint64_t application_id, String code, String code_verifier, String redirect_uri, DiscordAuthenticationExternalAuthType::Enum external_auth_type, String external_auth_token) {
	auto p1 = code.utf8().get_data();
	auto p2 = code_verifier.utf8().get_data();
	auto p3 = redirect_uri.utf8().get_data();
	auto p4 = (discordpp::AuthenticationExternalAuthType)external_auth_type;
	auto p5 = external_auth_token.utf8().get_data();
	client->GetTokenFromProvisionalMerge(application_id, p1, p2, p3, p4, p5, [this](discordpp::ClientResult result, std::string accessToken, std::string refreshToken, discordpp::AuthorizationTokenType tokenType, int32_t expiresIn, std::string scopes) {
		auto t_result = (discordpp::ClientResult *)memalloc(sizeof(discordpp::ClientResult));
		*t_result = result;
		auto p0 = memnew(DiscordClientResult{ t_result });

		auto p1 = String(accessToken.c_str());
		auto p2 = String(refreshToken.c_str());
		auto p3 = (DiscordAuthorizationTokenType::Enum)tokenType;
		auto p4 = expiresIn;
		auto p5 = String(scopes.c_str());
		this->emit_signal("get_token_from_provisional_merge_callback", p0, p1, p2, p3, p4, p5);
	});
}

bool DiscordClient::is_authenticated() {
	auto r = client->IsAuthenticated();
	return r;
}

void DiscordClient::open_authorize_device_screen(uint64_t client_id, String user_code) {
	auto p1 = user_code.utf8().get_data();
	client->OpenAuthorizeDeviceScreen(client_id, p1);
}

void DiscordClient::provisional_user_merge_completed(bool success) {
	client->ProvisionalUserMergeCompleted(success);
}

void DiscordClient::refresh_token(uint64_t application_id, String refresh_token) {
	auto p1 = refresh_token.utf8().get_data();
	client->RefreshToken(application_id, p1, [this](discordpp::ClientResult result, std::string accessToken, std::string refreshToken, discordpp::AuthorizationTokenType tokenType, int32_t expiresIn, std::string scopes) {
		auto t_result = (discordpp::ClientResult *)memalloc(sizeof(discordpp::ClientResult));
		*t_result = result;
		auto p0 = memnew(DiscordClientResult{ t_result });

		auto p1 = String(accessToken.c_str());
		auto p2 = String(refreshToken.c_str());
		auto p3 = (DiscordAuthorizationTokenType::Enum)tokenType;
		auto p4 = expiresIn;
		auto p5 = String(scopes.c_str());
		this->emit_signal("refresh_token_callback", p0, p1, p2, p3, p4, p5);
	});
}

void DiscordClient::set_authorize_device_screen_closed_callback() {
	client->SetAuthorizeDeviceScreenClosedCallback([this]() {
		this->emit_signal("set_authorize_device_screen_closed_callback_callback");
	});
}

void DiscordClient::set_game_window_pid(int32_t pid) {
	client->SetGameWindowPid(pid);
}

void DiscordClient::set_token_expiration_callback() {
	client->SetTokenExpirationCallback([this]() {
		this->emit_signal("set_token_expiration_callback_callback");
	});
}

void DiscordClient::update_provisional_account_display_name(String name) {
	auto p0 = name.utf8().get_data();
	client->UpdateProvisionalAccountDisplayName(p0, [this](discordpp::ClientResult result) {
		auto t_result = (discordpp::ClientResult *)memalloc(sizeof(discordpp::ClientResult));
		*t_result = result;
		auto p0 = memnew(DiscordClientResult{ t_result });

		this->emit_signal("update_provisional_account_display_name_callback", p0);
	});
}

void DiscordClient::update_token(DiscordAuthorizationTokenType::Enum token_type, String token) {
	auto p0 = (discordpp::AuthorizationTokenType)token_type;
	auto p1 = token.utf8().get_data();
	client->UpdateToken(p0, p1, [this](discordpp::ClientResult result) {
		auto t_result = (discordpp::ClientResult *)memalloc(sizeof(discordpp::ClientResult));
		*t_result = result;
		auto p0 = memnew(DiscordClientResult{ t_result });

		this->emit_signal("update_token_callback", p0);
	});
}

bool DiscordClient::can_open_message_in_discord(uint64_t message_id) {
	auto r = client->CanOpenMessageInDiscord(message_id);
	return r;
}

void DiscordClient::delete_user_message(uint64_t recipient_id, uint64_t message_id) {
	client->DeleteUserMessage(recipient_id, message_id, [this](discordpp::ClientResult result) {
		auto t_result = (discordpp::ClientResult *)memalloc(sizeof(discordpp::ClientResult));
		*t_result = result;
		auto p0 = memnew(DiscordClientResult{ t_result });

		this->emit_signal("delete_user_message_callback", p0);
	});
}

void DiscordClient::edit_user_message(uint64_t recipient_id, uint64_t message_id, String content) {
	auto p2 = content.utf8().get_data();
	client->EditUserMessage(recipient_id, message_id, p2, [this](discordpp::ClientResult result) {
		auto t_result = (discordpp::ClientResult *)memalloc(sizeof(discordpp::ClientResult));
		*t_result = result;
		auto p0 = memnew(DiscordClientResult{ t_result });

		this->emit_signal("edit_user_message_callback", p0);
	});
}

Variant DiscordClient::get_channel_handle(uint64_t channel_id) {
	auto r = client->GetChannelHandle(channel_id);

	if (!r.has_value()) {
		return nullptr;
	}

	auto t_r = (discordpp::ChannelHandle *)memalloc(sizeof(discordpp::ChannelHandle));
	*t_r = r.value();
	return Variant(memnew(DiscordChannelHandle{ t_r }));
}

Variant DiscordClient::get_message_handle(uint64_t message_id) {
	auto r = client->GetMessageHandle(message_id);

	if (!r.has_value()) {
		return nullptr;
	}

	auto t_r = (discordpp::MessageHandle *)memalloc(sizeof(discordpp::MessageHandle));
	*t_r = r.value();
	return Variant(memnew(DiscordMessageHandle{ t_r }));
}

void DiscordClient::open_message_in_discord(uint64_t message_id) {
	client->OpenMessageInDiscord(message_id, [this]() { this->emit_signal("open_message_in_discord_callback"); }, [this](discordpp::ClientResult result) {
        auto t_result = (discordpp::ClientResult *)memalloc(sizeof(discordpp::ClientResult));
    *t_result = result;
    auto p0 = memnew(DiscordClientResult{ t_result });
    
        this->emit_signal("open_message_in_discord_callback",p0); });
}

void DiscordClient::send_lobby_message(uint64_t lobby_id, String content) {
	auto p1 = content.utf8().get_data();
	client->SendLobbyMessage(lobby_id, p1, [this](discordpp::ClientResult result, uint64_t messageId) {
		auto t_result = (discordpp::ClientResult *)memalloc(sizeof(discordpp::ClientResult));
		*t_result = result;
		auto p0 = memnew(DiscordClientResult{ t_result });

		auto p1 = messageId;
		this->emit_signal("send_lobby_message_callback", p0, p1);
	});
}

void DiscordClient::send_lobby_message_with_metadata(uint64_t lobby_id, String content, TypedDictionary<String, String> metadata) {
	auto p1 = content.utf8().get_data();
	auto p2 = std::unordered_map<std::string, std::string>();
	auto k_p2 = metadata.keys();

	for (int i = 0; i < k_p2.size(); i++) {
		auto k = k_p2[i];
		auto v = metadata[k];
		auto k_s = k.stringify().utf8().get_data();
		auto v_s = v.stringify().utf8().get_data();
		p2[k_s] = v_s;
	}

	client->SendLobbyMessageWithMetadata(lobby_id, p1, p2, [this](discordpp::ClientResult result, uint64_t messageId) {
		auto t_result = (discordpp::ClientResult *)memalloc(sizeof(discordpp::ClientResult));
		*t_result = result;
		auto p0 = memnew(DiscordClientResult{ t_result });

		auto p1 = messageId;
		this->emit_signal("send_lobby_message_with_metadata_callback", p0, p1);
	});
}

void DiscordClient::send_user_message(uint64_t recipient_id, String content) {
	auto p1 = content.utf8().get_data();
	client->SendUserMessage(recipient_id, p1, [this](discordpp::ClientResult result, uint64_t messageId) {
		auto t_result = (discordpp::ClientResult *)memalloc(sizeof(discordpp::ClientResult));
		*t_result = result;
		auto p0 = memnew(DiscordClientResult{ t_result });

		auto p1 = messageId;
		this->emit_signal("send_user_message_callback", p0, p1);
	});
}

void DiscordClient::send_user_message_with_metadata(uint64_t recipient_id, String content, TypedDictionary<String, String> metadata) {
	auto p1 = content.utf8().get_data();
	auto p2 = std::unordered_map<std::string, std::string>();
	auto k_p2 = metadata.keys();

	for (int i = 0; i < k_p2.size(); i++) {
		auto k = k_p2[i];
		auto v = metadata[k];
		auto k_s = k.stringify().utf8().get_data();
		auto v_s = v.stringify().utf8().get_data();
		p2[k_s] = v_s;
	}

	client->SendUserMessageWithMetadata(recipient_id, p1, p2, [this](discordpp::ClientResult result, uint64_t messageId) {
		auto t_result = (discordpp::ClientResult *)memalloc(sizeof(discordpp::ClientResult));
		*t_result = result;
		auto p0 = memnew(DiscordClientResult{ t_result });

		auto p1 = messageId;
		this->emit_signal("send_user_message_with_metadata_callback", p0, p1);
	});
}

void DiscordClient::set_message_created_callback() {
	client->SetMessageCreatedCallback([this](uint64_t messageId) {
		auto p0 = messageId;
		this->emit_signal("set_message_created_callback_callback", p0);
	});
}

void DiscordClient::set_message_deleted_callback() {
	client->SetMessageDeletedCallback([this](uint64_t messageId, uint64_t channelId) {
		auto p0 = messageId;
		auto p1 = channelId;
		this->emit_signal("set_message_deleted_callback_callback", p0, p1);
	});
}

void DiscordClient::set_message_updated_callback() {
	client->SetMessageUpdatedCallback([this](uint64_t messageId) {
		auto p0 = messageId;
		this->emit_signal("set_message_updated_callback_callback", p0);
	});
}

void DiscordClient::set_showing_chat(bool showing_chat) {
	client->SetShowingChat(showing_chat);
}

void DiscordClient::add_log_callback(DiscordLoggingSeverity::Enum min_severity) {
	auto p0 = (discordpp::LoggingSeverity)min_severity;
	client->AddLogCallback([this](std::string message, discordpp::LoggingSeverity severity) {
		auto p0 = String(message.c_str());
		auto p1 = (DiscordLoggingSeverity::Enum)severity;
		this->emit_signal("add_log_callback_callback", p0, p1);
	},
			p0);
}

void DiscordClient::add_voice_log_callback(DiscordLoggingSeverity::Enum min_severity) {
	auto p0 = (discordpp::LoggingSeverity)min_severity;
	client->AddVoiceLogCallback([this](std::string message, discordpp::LoggingSeverity severity) {
		auto p0 = String(message.c_str());
		auto p1 = (DiscordLoggingSeverity::Enum)severity;
		this->emit_signal("add_voice_log_callback_callback", p0, p1);
	},
			p0);
}

void DiscordClient::connect() {
	client->Connect();
}

void DiscordClient::disconnect() {
	client->Disconnect();
}

DiscordClientStatus::Enum DiscordClient::get_status() {
	auto r = client->GetStatus();
	return (DiscordClientStatus::Enum)r;
}

bool DiscordClient::set_log_dir(String path, DiscordLoggingSeverity::Enum min_severity) {
	auto p0 = path.utf8().get_data();
	auto p1 = (discordpp::LoggingSeverity)min_severity;
	auto r = client->SetLogDir(p0, p1);
	return r;
}

void DiscordClient::set_status_changed_callback() {
	client->SetStatusChangedCallback([this](discordpp::Client::Status status, discordpp::Client::Error error, int32_t errorDetail) {
		auto p0 = (DiscordClientStatus::Enum)status;
		auto p1 = (DiscordClientError::Enum)error;
		auto p2 = errorDetail;
		this->emit_signal("set_status_changed_callback_callback", p0, p1, p2);
	});
}

void DiscordClient::set_voice_log_dir(String path, DiscordLoggingSeverity::Enum min_severity) {
	auto p0 = path.utf8().get_data();
	auto p1 = (discordpp::LoggingSeverity)min_severity;
	client->SetVoiceLogDir(p0, p1);
}

void DiscordClient::create_or_join_lobby(String secret) {
	auto p0 = secret.utf8().get_data();
	client->CreateOrJoinLobby(p0, [this](discordpp::ClientResult result, uint64_t lobbyId) {
		auto t_result = (discordpp::ClientResult *)memalloc(sizeof(discordpp::ClientResult));
		*t_result = result;
		auto p0 = memnew(DiscordClientResult{ t_result });

		auto p1 = lobbyId;
		this->emit_signal("create_or_join_lobby_callback", p0, p1);
	});
}

void DiscordClient::create_or_join_lobby_with_metadata(String secret, TypedDictionary<String, String> lobby_metadata, TypedDictionary<String, String> member_metadata) {
	auto p0 = secret.utf8().get_data();
	auto p1 = std::unordered_map<std::string, std::string>();
	auto k_p1 = lobby_metadata.keys();

	for (int i = 0; i < k_p1.size(); i++) {
		auto k = k_p1[i];
		auto v = lobby_metadata[k];
		auto k_s = k.stringify().utf8().get_data();
		auto v_s = v.stringify().utf8().get_data();
		p1[k_s] = v_s;
	}

	auto p2 = std::unordered_map<std::string, std::string>();
	auto k_p2 = member_metadata.keys();

	for (int i = 0; i < k_p2.size(); i++) {
		auto k = k_p2[i];
		auto v = member_metadata[k];
		auto k_s = k.stringify().utf8().get_data();
		auto v_s = v.stringify().utf8().get_data();
		p2[k_s] = v_s;
	}

	client->CreateOrJoinLobbyWithMetadata(p0, p1, p2, [this](discordpp::ClientResult result, uint64_t lobbyId) {
		auto t_result = (discordpp::ClientResult *)memalloc(sizeof(discordpp::ClientResult));
		*t_result = result;
		auto p0 = memnew(DiscordClientResult{ t_result });

		auto p1 = lobbyId;
		this->emit_signal("create_or_join_lobby_with_metadata_callback", p0, p1);
	});
}

void DiscordClient::get_guild_channels(uint64_t guild_id) {
	client->GetGuildChannels(guild_id, [this](discordpp::ClientResult result, std::vector<discordpp::GuildChannel> guildChannels) {
		auto t_result = (discordpp::ClientResult *)memalloc(sizeof(discordpp::ClientResult));
		*t_result = result;
		auto p0 = memnew(DiscordClientResult{ t_result });

		auto t_guildChannels = TypedArray<DiscordGuildChannel>();

		for (auto i_guildChannels : guildChannels) {
			t_guildChannels.push_back(memnew(DiscordGuildChannel{ &i_guildChannels }));
		}

		auto p1 = t_guildChannels;

		this->emit_signal("get_guild_channels_callback", p0, p1);
	});
}

Variant DiscordClient::get_lobby_handle(uint64_t lobby_id) {
	auto r = client->GetLobbyHandle(lobby_id);

	if (!r.has_value()) {
		return nullptr;
	}

	auto t_r = (discordpp::LobbyHandle *)memalloc(sizeof(discordpp::LobbyHandle));
	*t_r = r.value();
	return Variant(memnew(DiscordLobbyHandle{ t_r }));
}

TypedArray<uint64_t> DiscordClient::get_lobby_ids() {
	auto r = client->GetLobbyIds();
	auto t_r = TypedArray<uint64_t>();

	for (auto i_r : r) {
		t_r.push_back(i_r);
	}

	return t_r;
}

void DiscordClient::get_user_guilds() {
	client->GetUserGuilds([this](discordpp::ClientResult result, std::vector<discordpp::GuildMinimal> guilds) {
		auto t_result = (discordpp::ClientResult *)memalloc(sizeof(discordpp::ClientResult));
		*t_result = result;
		auto p0 = memnew(DiscordClientResult{ t_result });

		auto t_guilds = TypedArray<DiscordGuildMinimal>();

		for (auto i_guilds : guilds) {
			t_guilds.push_back(memnew(DiscordGuildMinimal{ &i_guilds }));
		}

		auto p1 = t_guilds;

		this->emit_signal("get_user_guilds_callback", p0, p1);
	});
}

void DiscordClient::leave_lobby(uint64_t lobby_id) {
	client->LeaveLobby(lobby_id, [this](discordpp::ClientResult result) {
		auto t_result = (discordpp::ClientResult *)memalloc(sizeof(discordpp::ClientResult));
		*t_result = result;
		auto p0 = memnew(DiscordClientResult{ t_result });

		this->emit_signal("leave_lobby_callback", p0);
	});
}

void DiscordClient::link_channel_to_lobby(uint64_t lobby_id, uint64_t channel_id) {
	client->LinkChannelToLobby(lobby_id, channel_id, [this](discordpp::ClientResult result) {
		auto t_result = (discordpp::ClientResult *)memalloc(sizeof(discordpp::ClientResult));
		*t_result = result;
		auto p0 = memnew(DiscordClientResult{ t_result });

		this->emit_signal("link_channel_to_lobby_callback", p0);
	});
}

void DiscordClient::set_lobby_created_callback() {
	client->SetLobbyCreatedCallback([this](uint64_t lobbyId) {
		auto p0 = lobbyId;
		this->emit_signal("set_lobby_created_callback_callback", p0);
	});
}

void DiscordClient::set_lobby_deleted_callback() {
	client->SetLobbyDeletedCallback([this](uint64_t lobbyId) {
		auto p0 = lobbyId;
		this->emit_signal("set_lobby_deleted_callback_callback", p0);
	});
}

void DiscordClient::set_lobby_member_added_callback() {
	client->SetLobbyMemberAddedCallback([this](uint64_t lobbyId, uint64_t memberId) {
		auto p0 = lobbyId;
		auto p1 = memberId;
		this->emit_signal("set_lobby_member_added_callback_callback", p0, p1);
	});
}

void DiscordClient::set_lobby_member_removed_callback() {
	client->SetLobbyMemberRemovedCallback([this](uint64_t lobbyId, uint64_t memberId) {
		auto p0 = lobbyId;
		auto p1 = memberId;
		this->emit_signal("set_lobby_member_removed_callback_callback", p0, p1);
	});
}

void DiscordClient::set_lobby_member_updated_callback() {
	client->SetLobbyMemberUpdatedCallback([this](uint64_t lobbyId, uint64_t memberId) {
		auto p0 = lobbyId;
		auto p1 = memberId;
		this->emit_signal("set_lobby_member_updated_callback_callback", p0, p1);
	});
}

void DiscordClient::set_lobby_updated_callback() {
	client->SetLobbyUpdatedCallback([this](uint64_t lobbyId) {
		auto p0 = lobbyId;
		this->emit_signal("set_lobby_updated_callback_callback", p0);
	});
}

void DiscordClient::unlink_channel_from_lobby(uint64_t lobby_id) {
	client->UnlinkChannelFromLobby(lobby_id, [this](discordpp::ClientResult result) {
		auto t_result = (discordpp::ClientResult *)memalloc(sizeof(discordpp::ClientResult));
		*t_result = result;
		auto p0 = memnew(DiscordClientResult{ t_result });

		this->emit_signal("unlink_channel_from_lobby_callback", p0);
	});
}

void DiscordClient::accept_activity_invite(DiscordActivityInvite *invite) {
	auto p0 = *invite->unwrap();
	client->AcceptActivityInvite(p0, [this](discordpp::ClientResult result, std::string joinSecret) {
		auto t_result = (discordpp::ClientResult *)memalloc(sizeof(discordpp::ClientResult));
		*t_result = result;
		auto p0 = memnew(DiscordClientResult{ t_result });

		auto p1 = String(joinSecret.c_str());
		this->emit_signal("accept_activity_invite_callback", p0, p1);
	});
}

void DiscordClient::clear_rich_presence() {
	client->ClearRichPresence();
}

bool DiscordClient::register_launch_command(uint64_t application_id, String command) {
	auto p1 = command.utf8().get_data();
	auto r = client->RegisterLaunchCommand(application_id, p1);
	return r;
}

bool DiscordClient::register_launch_steam_application(uint64_t application_id, uint32_t steam_app_id) {
	auto r = client->RegisterLaunchSteamApplication(application_id, steam_app_id);
	return r;
}

void DiscordClient::send_activity_invite(uint64_t user_id, String content) {
	auto p1 = content.utf8().get_data();
	client->SendActivityInvite(user_id, p1, [this](discordpp::ClientResult result) {
		auto t_result = (discordpp::ClientResult *)memalloc(sizeof(discordpp::ClientResult));
		*t_result = result;
		auto p0 = memnew(DiscordClientResult{ t_result });

		this->emit_signal("send_activity_invite_callback", p0);
	});
}

void DiscordClient::send_activity_join_request(uint64_t user_id) {
	client->SendActivityJoinRequest(user_id, [this](discordpp::ClientResult result) {
		auto t_result = (discordpp::ClientResult *)memalloc(sizeof(discordpp::ClientResult));
		*t_result = result;
		auto p0 = memnew(DiscordClientResult{ t_result });

		this->emit_signal("send_activity_join_request_callback", p0);
	});
}

void DiscordClient::send_activity_join_request_reply(DiscordActivityInvite *invite) {
	auto p0 = *invite->unwrap();
	client->SendActivityJoinRequestReply(p0, [this](discordpp::ClientResult result) {
		auto t_result = (discordpp::ClientResult *)memalloc(sizeof(discordpp::ClientResult));
		*t_result = result;
		auto p0 = memnew(DiscordClientResult{ t_result });

		this->emit_signal("send_activity_join_request_reply_callback", p0);
	});
}

void DiscordClient::set_activity_invite_created_callback() {
	client->SetActivityInviteCreatedCallback([this](discordpp::ActivityInvite invite) {
		auto t_invite = (discordpp::ActivityInvite *)memalloc(sizeof(discordpp::ActivityInvite));
		*t_invite = invite;
		auto p0 = memnew(DiscordActivityInvite{ t_invite });

		this->emit_signal("set_activity_invite_created_callback_callback", p0);
	});
}

void DiscordClient::set_activity_invite_updated_callback() {
	client->SetActivityInviteUpdatedCallback([this](discordpp::ActivityInvite invite) {
		auto t_invite = (discordpp::ActivityInvite *)memalloc(sizeof(discordpp::ActivityInvite));
		*t_invite = invite;
		auto p0 = memnew(DiscordActivityInvite{ t_invite });

		this->emit_signal("set_activity_invite_updated_callback_callback", p0);
	});
}

void DiscordClient::set_activity_join_callback() {
	client->SetActivityJoinCallback([this](std::string joinSecret) {
		auto p0 = String(joinSecret.c_str());
		this->emit_signal("set_activity_join_callback_callback", p0);
	});
}

void DiscordClient::set_online_status(DiscordStatusType::Enum status) {
	auto p0 = (discordpp::StatusType)status;
	client->SetOnlineStatus(p0, [this](discordpp::ClientResult result) {
		auto t_result = (discordpp::ClientResult *)memalloc(sizeof(discordpp::ClientResult));
		*t_result = result;
		auto p0 = memnew(DiscordClientResult{ t_result });

		this->emit_signal("set_online_status_callback", p0);
	});
}

void DiscordClient::update_rich_presence(DiscordActivity *activity) {
	auto p0 = *activity->unwrap();
	client->UpdateRichPresence(p0, [this](discordpp::ClientResult result) {
		auto t_result = (discordpp::ClientResult *)memalloc(sizeof(discordpp::ClientResult));
		*t_result = result;
		auto p0 = memnew(DiscordClientResult{ t_result });

		this->emit_signal("update_rich_presence_callback", p0);
	});
}

void DiscordClient::accept_discord_friend_request(uint64_t user_id) {
	client->AcceptDiscordFriendRequest(user_id, [this](discordpp::ClientResult result) {
		auto t_result = (discordpp::ClientResult *)memalloc(sizeof(discordpp::ClientResult));
		*t_result = result;
		auto p0 = memnew(DiscordClientResult{ t_result });

		this->emit_signal("accept_discord_friend_request_callback", p0);
	});
}

void DiscordClient::accept_game_friend_request(uint64_t user_id) {
	client->AcceptGameFriendRequest(user_id, [this](discordpp::ClientResult result) {
		auto t_result = (discordpp::ClientResult *)memalloc(sizeof(discordpp::ClientResult));
		*t_result = result;
		auto p0 = memnew(DiscordClientResult{ t_result });

		this->emit_signal("accept_game_friend_request_callback", p0);
	});
}

void DiscordClient::block_user(uint64_t user_id) {
	client->BlockUser(user_id, [this](discordpp::ClientResult result) {
		auto t_result = (discordpp::ClientResult *)memalloc(sizeof(discordpp::ClientResult));
		*t_result = result;
		auto p0 = memnew(DiscordClientResult{ t_result });

		this->emit_signal("block_user_callback", p0);
	});
}

void DiscordClient::cancel_discord_friend_request(uint64_t user_id) {
	client->CancelDiscordFriendRequest(user_id, [this](discordpp::ClientResult result) {
		auto t_result = (discordpp::ClientResult *)memalloc(sizeof(discordpp::ClientResult));
		*t_result = result;
		auto p0 = memnew(DiscordClientResult{ t_result });

		this->emit_signal("cancel_discord_friend_request_callback", p0);
	});
}

void DiscordClient::cancel_game_friend_request(uint64_t user_id) {
	client->CancelGameFriendRequest(user_id, [this](discordpp::ClientResult result) {
		auto t_result = (discordpp::ClientResult *)memalloc(sizeof(discordpp::ClientResult));
		*t_result = result;
		auto p0 = memnew(DiscordClientResult{ t_result });

		this->emit_signal("cancel_game_friend_request_callback", p0);
	});
}

DiscordRelationshipHandle *DiscordClient::get_relationship_handle(uint64_t user_id) {
	auto r = client->GetRelationshipHandle(user_id);
	auto t_r = (discordpp::RelationshipHandle *)memalloc(sizeof(discordpp::RelationshipHandle));
	*t_r = r;
	return memnew(DiscordRelationshipHandle{ t_r });
}

TypedArray<DiscordRelationshipHandle> DiscordClient::get_relationships() {
	auto r = client->GetRelationships();
	auto t_r = TypedArray<DiscordRelationshipHandle>();

	for (auto i_r : r) {
		t_r.push_back(memnew(DiscordRelationshipHandle{ &i_r }));
	}

	return t_r;
}

void DiscordClient::reject_discord_friend_request(uint64_t user_id) {
	client->RejectDiscordFriendRequest(user_id, [this](discordpp::ClientResult result) {
		auto t_result = (discordpp::ClientResult *)memalloc(sizeof(discordpp::ClientResult));
		*t_result = result;
		auto p0 = memnew(DiscordClientResult{ t_result });

		this->emit_signal("reject_discord_friend_request_callback", p0);
	});
}

void DiscordClient::reject_game_friend_request(uint64_t user_id) {
	client->RejectGameFriendRequest(user_id, [this](discordpp::ClientResult result) {
		auto t_result = (discordpp::ClientResult *)memalloc(sizeof(discordpp::ClientResult));
		*t_result = result;
		auto p0 = memnew(DiscordClientResult{ t_result });

		this->emit_signal("reject_game_friend_request_callback", p0);
	});
}

void DiscordClient::remove_discord_and_game_friend(uint64_t user_id) {
	client->RemoveDiscordAndGameFriend(user_id, [this](discordpp::ClientResult result) {
		auto t_result = (discordpp::ClientResult *)memalloc(sizeof(discordpp::ClientResult));
		*t_result = result;
		auto p0 = memnew(DiscordClientResult{ t_result });

		this->emit_signal("remove_discord_and_game_friend_callback", p0);
	});
}

void DiscordClient::remove_game_friend(uint64_t user_id) {
	client->RemoveGameFriend(user_id, [this](discordpp::ClientResult result) {
		auto t_result = (discordpp::ClientResult *)memalloc(sizeof(discordpp::ClientResult));
		*t_result = result;
		auto p0 = memnew(DiscordClientResult{ t_result });

		this->emit_signal("remove_game_friend_callback", p0);
	});
}

TypedArray<DiscordUserHandle> DiscordClient::search_friends_by_username(String search_str) {
	auto p0 = search_str.utf8().get_data();
	auto r = client->SearchFriendsByUsername(p0);
	auto t_r = TypedArray<DiscordUserHandle>();

	for (auto i_r : r) {
		t_r.push_back(memnew(DiscordUserHandle{ &i_r }));
	}

	return t_r;
}

void DiscordClient::send_discord_friend_request(String username) {
	auto p0 = username.utf8().get_data();
	client->SendDiscordFriendRequest(p0, [this](discordpp::ClientResult result) {
		auto t_result = (discordpp::ClientResult *)memalloc(sizeof(discordpp::ClientResult));
		*t_result = result;
		auto p0 = memnew(DiscordClientResult{ t_result });

		this->emit_signal("send_discord_friend_request_callback", p0);
	});
}

void DiscordClient::send_discord_friend_request_by_id(uint64_t user_id) {
	client->SendDiscordFriendRequestById(user_id, [this](discordpp::ClientResult result) {
		auto t_result = (discordpp::ClientResult *)memalloc(sizeof(discordpp::ClientResult));
		*t_result = result;
		auto p0 = memnew(DiscordClientResult{ t_result });

		this->emit_signal("send_discord_friend_request_by_id_callback", p0);
	});
}

void DiscordClient::send_game_friend_request(String username) {
	auto p0 = username.utf8().get_data();
	client->SendGameFriendRequest(p0, [this](discordpp::ClientResult result) {
		auto t_result = (discordpp::ClientResult *)memalloc(sizeof(discordpp::ClientResult));
		*t_result = result;
		auto p0 = memnew(DiscordClientResult{ t_result });

		this->emit_signal("send_game_friend_request_callback", p0);
	});
}

void DiscordClient::send_game_friend_request_by_id(uint64_t user_id) {
	client->SendGameFriendRequestById(user_id, [this](discordpp::ClientResult result) {
		auto t_result = (discordpp::ClientResult *)memalloc(sizeof(discordpp::ClientResult));
		*t_result = result;
		auto p0 = memnew(DiscordClientResult{ t_result });

		this->emit_signal("send_game_friend_request_by_id_callback", p0);
	});
}

void DiscordClient::set_relationship_created_callback() {
	client->SetRelationshipCreatedCallback([this](uint64_t userId, bool isDiscordRelationshipUpdate) {
		auto p0 = userId;
		auto p1 = isDiscordRelationshipUpdate;
		this->emit_signal("set_relationship_created_callback_callback", p0, p1);
	});
}

void DiscordClient::set_relationship_deleted_callback() {
	client->SetRelationshipDeletedCallback([this](uint64_t userId, bool isDiscordRelationshipUpdate) {
		auto p0 = userId;
		auto p1 = isDiscordRelationshipUpdate;
		this->emit_signal("set_relationship_deleted_callback_callback", p0, p1);
	});
}

void DiscordClient::unblock_user(uint64_t user_id) {
	client->UnblockUser(user_id, [this](discordpp::ClientResult result) {
		auto t_result = (discordpp::ClientResult *)memalloc(sizeof(discordpp::ClientResult));
		*t_result = result;
		auto p0 = memnew(DiscordClientResult{ t_result });

		this->emit_signal("unblock_user_callback", p0);
	});
}

DiscordUserHandle *DiscordClient::get_current_user() {
	auto r = client->GetCurrentUser();
	auto t_r = (discordpp::UserHandle *)memalloc(sizeof(discordpp::UserHandle));
	*t_r = r;
	return memnew(DiscordUserHandle{ t_r });
}

void DiscordClient::get_discord_client_connected_user(uint64_t application_id) {
	client->GetDiscordClientConnectedUser(application_id, [this](discordpp::ClientResult result, std::optional<discordpp::UserHandle> user) {
		auto t_result = (discordpp::ClientResult *)memalloc(sizeof(discordpp::ClientResult));
		*t_result = result;
		auto p0 = memnew(DiscordClientResult{ t_result });

		if (!user.has_value()) {
			auto p1 = nullptr;
		}

		auto t_user = (discordpp::UserHandle *)memalloc(sizeof(discordpp::UserHandle));
		*t_user = user.value();
		auto p1 = Variant(memnew(DiscordUserHandle{ t_user }));

		this->emit_signal("get_discord_client_connected_user_callback", p0, p1);
	});
}

Variant DiscordClient::get_user(uint64_t user_id) {
	auto r = client->GetUser(user_id);

	if (!r.has_value()) {
		return nullptr;
	}

	auto t_r = (discordpp::UserHandle *)memalloc(sizeof(discordpp::UserHandle));
	*t_r = r.value();
	return Variant(memnew(DiscordUserHandle{ t_r }));
}

void DiscordClient::set_user_updated_callback() {
	client->SetUserUpdatedCallback([this](uint64_t userI) {
		auto p0 = userI;
		this->emit_signal("set_user_updated_callback_callback", p0);
	});
}

void DiscordClient::_bind_methods() {
	ADD_SIGNAL(MethodInfo("client_end_call_callback"));

	ADD_SIGNAL(MethodInfo("client_end_calls_callback"));

	ADD_SIGNAL(MethodInfo("client_get_current_input_device_callback", PropertyInfo(Variant::OBJECT, "device")));

	ADD_SIGNAL(MethodInfo("client_get_current_output_device_callback", PropertyInfo(Variant::OBJECT, "device")));

	ADD_SIGNAL(MethodInfo("client_get_input_devices_callback", PropertyInfo(Variant::ARRAY, "devices")));

	ADD_SIGNAL(MethodInfo("client_get_output_devices_callback", PropertyInfo(Variant::ARRAY, "devices")));

	ADD_SIGNAL(MethodInfo("client_device_change_callback", PropertyInfo(Variant::ARRAY, "input_devices"), PropertyInfo(Variant::ARRAY, "output_devices")));

	ADD_SIGNAL(MethodInfo("client_set_input_device_callback", PropertyInfo(Variant::OBJECT, "result")));

	ADD_SIGNAL(MethodInfo("client_no_audio_input_callback", PropertyInfo(Variant::BOOL, "input_detected")));

	ADD_SIGNAL(MethodInfo("client_set_output_device_callback", PropertyInfo(Variant::OBJECT, "result")));

	ADD_SIGNAL(MethodInfo("client_voice_participant_changed_callback", PropertyInfo(Variant::INT, "lobby_id"), PropertyInfo(Variant::INT, "member_id"), PropertyInfo(Variant::BOOL, "added")));

	ADD_SIGNAL(MethodInfo("client_user_audio_received_callback", PropertyInfo(Variant::INT, "user_id"), PropertyInfo(Variant::INT, "data"), PropertyInfo(Variant::INT, "samples_per_channel"), PropertyInfo(Variant::INT, "sample_rate"), PropertyInfo(Variant::INT, "channels"), PropertyInfo(Variant::BOOL, "out_should_mute")));

	ADD_SIGNAL(MethodInfo("client_user_audio_captured_callback", PropertyInfo(Variant::INT, "data"), PropertyInfo(Variant::INT, "samples_per_channel"), PropertyInfo(Variant::INT, "sample_rate"), PropertyInfo(Variant::INT, "channels")));

	ADD_SIGNAL(MethodInfo("client_authorization_callback", PropertyInfo(Variant::OBJECT, "result"), PropertyInfo(Variant::STRING, "code"), PropertyInfo(Variant::STRING, "redirect_uri")));

	ADD_SIGNAL(MethodInfo("client_fetch_current_user_callback", PropertyInfo(Variant::OBJECT, "result"), PropertyInfo(Variant::INT, "id"), PropertyInfo(Variant::STRING, "name")));

	ADD_SIGNAL(MethodInfo("client_token_exchange_callback", PropertyInfo(Variant::OBJECT, "result"), PropertyInfo(Variant::STRING, "access_token"), PropertyInfo(Variant::STRING, "refresh_token"), PropertyInfo(Variant::OBJECT, "token_type"), PropertyInfo(Variant::INT, "expires_in"), PropertyInfo(Variant::STRING, "scopes")));

	ADD_SIGNAL(MethodInfo("client_token_exchange_callback", PropertyInfo(Variant::OBJECT, "result"), PropertyInfo(Variant::STRING, "access_token"), PropertyInfo(Variant::STRING, "refresh_token"), PropertyInfo(Variant::OBJECT, "token_type"), PropertyInfo(Variant::INT, "expires_in"), PropertyInfo(Variant::STRING, "scopes")));

	ADD_SIGNAL(MethodInfo("client_token_exchange_callback", PropertyInfo(Variant::OBJECT, "result"), PropertyInfo(Variant::STRING, "access_token"), PropertyInfo(Variant::STRING, "refresh_token"), PropertyInfo(Variant::OBJECT, "token_type"), PropertyInfo(Variant::INT, "expires_in"), PropertyInfo(Variant::STRING, "scopes")));

	ADD_SIGNAL(MethodInfo("client_token_exchange_callback", PropertyInfo(Variant::OBJECT, "result"), PropertyInfo(Variant::STRING, "access_token"), PropertyInfo(Variant::STRING, "refresh_token"), PropertyInfo(Variant::OBJECT, "token_type"), PropertyInfo(Variant::INT, "expires_in"), PropertyInfo(Variant::STRING, "scopes")));

	ADD_SIGNAL(MethodInfo("client_token_exchange_callback", PropertyInfo(Variant::OBJECT, "result"), PropertyInfo(Variant::STRING, "access_token"), PropertyInfo(Variant::STRING, "refresh_token"), PropertyInfo(Variant::OBJECT, "token_type"), PropertyInfo(Variant::INT, "expires_in"), PropertyInfo(Variant::STRING, "scopes")));

	ADD_SIGNAL(MethodInfo("client_token_exchange_callback", PropertyInfo(Variant::OBJECT, "result"), PropertyInfo(Variant::STRING, "access_token"), PropertyInfo(Variant::STRING, "refresh_token"), PropertyInfo(Variant::OBJECT, "token_type"), PropertyInfo(Variant::INT, "expires_in"), PropertyInfo(Variant::STRING, "scopes")));

	ADD_SIGNAL(MethodInfo("client_authorize_device_screen_closed_callback"));

	ADD_SIGNAL(MethodInfo("client_token_expiration_callback"));

	ADD_SIGNAL(MethodInfo("client_update_provisional_account_display_name_callback", PropertyInfo(Variant::OBJECT, "result")));

	ADD_SIGNAL(MethodInfo("client_update_token_callback", PropertyInfo(Variant::OBJECT, "result")));

	ADD_SIGNAL(MethodInfo("client_delete_user_message_callback", PropertyInfo(Variant::OBJECT, "result")));

	ADD_SIGNAL(MethodInfo("client_edit_user_message_callback", PropertyInfo(Variant::OBJECT, "result")));

	ADD_SIGNAL(MethodInfo("client_provisional_user_merge_required_callback"));

	ADD_SIGNAL(MethodInfo("client_open_message_in_discord_callback", PropertyInfo(Variant::OBJECT, "result")));

	ADD_SIGNAL(MethodInfo("client_send_user_message_callback", PropertyInfo(Variant::OBJECT, "result"), PropertyInfo(Variant::INT, "message_id")));

	ADD_SIGNAL(MethodInfo("client_send_user_message_callback", PropertyInfo(Variant::OBJECT, "result"), PropertyInfo(Variant::INT, "message_id")));

	ADD_SIGNAL(MethodInfo("client_send_user_message_callback", PropertyInfo(Variant::OBJECT, "result"), PropertyInfo(Variant::INT, "message_id")));

	ADD_SIGNAL(MethodInfo("client_send_user_message_callback", PropertyInfo(Variant::OBJECT, "result"), PropertyInfo(Variant::INT, "message_id")));

	ADD_SIGNAL(MethodInfo("client_message_created_callback", PropertyInfo(Variant::INT, "message_id")));

	ADD_SIGNAL(MethodInfo("client_message_deleted_callback", PropertyInfo(Variant::INT, "message_id"), PropertyInfo(Variant::INT, "channel_id")));

	ADD_SIGNAL(MethodInfo("client_message_updated_callback", PropertyInfo(Variant::INT, "message_id")));

	ADD_SIGNAL(MethodInfo("client_log_callback", PropertyInfo(Variant::STRING, "message"), PropertyInfo(Variant::OBJECT, "severity")));

	ADD_SIGNAL(MethodInfo("client_log_callback", PropertyInfo(Variant::STRING, "message"), PropertyInfo(Variant::OBJECT, "severity")));

	ADD_SIGNAL(MethodInfo("client_on_status_changed", PropertyInfo(Variant::OBJECT, "status"), PropertyInfo(Variant::OBJECT, "error"), PropertyInfo(Variant::INT, "error_detail")));

	ADD_SIGNAL(MethodInfo("client_create_or_join_lobby_callback", PropertyInfo(Variant::OBJECT, "result"), PropertyInfo(Variant::INT, "lobby_id")));

	ADD_SIGNAL(MethodInfo("client_create_or_join_lobby_callback", PropertyInfo(Variant::OBJECT, "result"), PropertyInfo(Variant::INT, "lobby_id")));

	ADD_SIGNAL(MethodInfo("client_get_guild_channels_callback", PropertyInfo(Variant::OBJECT, "result"), PropertyInfo(Variant::ARRAY, "guild_channels")));

	ADD_SIGNAL(MethodInfo("client_get_user_guilds_callback", PropertyInfo(Variant::OBJECT, "result"), PropertyInfo(Variant::ARRAY, "guilds")));

	ADD_SIGNAL(MethodInfo("client_leave_lobby_callback", PropertyInfo(Variant::OBJECT, "result")));

	ADD_SIGNAL(MethodInfo("client_link_or_unlink_channel_callback", PropertyInfo(Variant::OBJECT, "result")));

	ADD_SIGNAL(MethodInfo("client_lobby_created_callback", PropertyInfo(Variant::INT, "lobby_id")));

	ADD_SIGNAL(MethodInfo("client_lobby_deleted_callback", PropertyInfo(Variant::INT, "lobby_id")));

	ADD_SIGNAL(MethodInfo("client_lobby_member_added_callback", PropertyInfo(Variant::INT, "lobby_id"), PropertyInfo(Variant::INT, "member_id")));

	ADD_SIGNAL(MethodInfo("client_lobby_member_removed_callback", PropertyInfo(Variant::INT, "lobby_id"), PropertyInfo(Variant::INT, "member_id")));

	ADD_SIGNAL(MethodInfo("client_lobby_member_updated_callback", PropertyInfo(Variant::INT, "lobby_id"), PropertyInfo(Variant::INT, "member_id")));

	ADD_SIGNAL(MethodInfo("client_lobby_updated_callback", PropertyInfo(Variant::INT, "lobby_id")));

	ADD_SIGNAL(MethodInfo("client_link_or_unlink_channel_callback", PropertyInfo(Variant::OBJECT, "result")));

	ADD_SIGNAL(MethodInfo("client_accept_activity_invite_callback", PropertyInfo(Variant::OBJECT, "result"), PropertyInfo(Variant::STRING, "join_secret")));

	ADD_SIGNAL(MethodInfo("client_send_activity_invite_callback", PropertyInfo(Variant::OBJECT, "result")));

	ADD_SIGNAL(MethodInfo("client_send_activity_invite_callback", PropertyInfo(Variant::OBJECT, "result")));

	ADD_SIGNAL(MethodInfo("client_send_activity_invite_callback", PropertyInfo(Variant::OBJECT, "result")));

	ADD_SIGNAL(MethodInfo("client_activity_invite_callback", PropertyInfo(Variant::OBJECT, "invite")));

	ADD_SIGNAL(MethodInfo("client_activity_invite_callback", PropertyInfo(Variant::OBJECT, "invite")));

	ADD_SIGNAL(MethodInfo("client_activity_join_callback", PropertyInfo(Variant::STRING, "join_secret")));

	ADD_SIGNAL(MethodInfo("client_update_status_callback", PropertyInfo(Variant::OBJECT, "result")));

	ADD_SIGNAL(MethodInfo("client_update_rich_presence_callback", PropertyInfo(Variant::OBJECT, "result")));

	ADD_SIGNAL(MethodInfo("client_update_relationship_callback", PropertyInfo(Variant::OBJECT, "result")));

	ADD_SIGNAL(MethodInfo("client_update_relationship_callback", PropertyInfo(Variant::OBJECT, "result")));

	ADD_SIGNAL(MethodInfo("client_update_relationship_callback", PropertyInfo(Variant::OBJECT, "result")));

	ADD_SIGNAL(MethodInfo("client_update_relationship_callback", PropertyInfo(Variant::OBJECT, "result")));

	ADD_SIGNAL(MethodInfo("client_update_relationship_callback", PropertyInfo(Variant::OBJECT, "result")));

	ADD_SIGNAL(MethodInfo("client_update_relationship_callback", PropertyInfo(Variant::OBJECT, "result")));

	ADD_SIGNAL(MethodInfo("client_update_relationship_callback", PropertyInfo(Variant::OBJECT, "result")));

	ADD_SIGNAL(MethodInfo("client_update_relationship_callback", PropertyInfo(Variant::OBJECT, "result")));

	ADD_SIGNAL(MethodInfo("client_update_relationship_callback", PropertyInfo(Variant::OBJECT, "result")));

	ADD_SIGNAL(MethodInfo("client_send_friend_request_callback", PropertyInfo(Variant::OBJECT, "result")));

	ADD_SIGNAL(MethodInfo("client_update_relationship_callback", PropertyInfo(Variant::OBJECT, "result")));

	ADD_SIGNAL(MethodInfo("client_send_friend_request_callback", PropertyInfo(Variant::OBJECT, "result")));

	ADD_SIGNAL(MethodInfo("client_update_relationship_callback", PropertyInfo(Variant::OBJECT, "result")));

	ADD_SIGNAL(MethodInfo("client_relationship_created_callback", PropertyInfo(Variant::INT, "user_id"), PropertyInfo(Variant::BOOL, "is_discord_relationship_update")));

	ADD_SIGNAL(MethodInfo("client_relationship_deleted_callback", PropertyInfo(Variant::INT, "user_id"), PropertyInfo(Variant::BOOL, "is_discord_relationship_update")));

	ADD_SIGNAL(MethodInfo("client_update_relationship_callback", PropertyInfo(Variant::OBJECT, "result")));

	ADD_SIGNAL(MethodInfo("client_get_discord_client_connected_user_callback", PropertyInfo(Variant::OBJECT, "result"), PropertyInfo(Variant::NIL, "user")));

	ADD_SIGNAL(MethodInfo("client_user_updated_callback", PropertyInfo(Variant::INT, "user_i")));

	ClassDB::bind_method(D_METHOD("end_call", "channel_id"),
			&DiscordClient::end_call);

	ClassDB::bind_method(D_METHOD("end_calls"),
			&DiscordClient::end_calls);

	ClassDB::bind_method(D_METHOD("get_call", "channel_id"),
			&DiscordClient::get_call);

	ClassDB::bind_method(D_METHOD("get_calls"),
			&DiscordClient::get_calls);

	ClassDB::bind_method(D_METHOD("get_current_input_device"),
			&DiscordClient::get_current_input_device);

	ClassDB::bind_method(D_METHOD("get_current_output_device"),
			&DiscordClient::get_current_output_device);

	ClassDB::bind_method(D_METHOD("get_input_devices"),
			&DiscordClient::get_input_devices);

	ClassDB::bind_method(D_METHOD("get_input_volume"),
			&DiscordClient::get_input_volume);

	ClassDB::bind_method(D_METHOD("get_output_devices"),
			&DiscordClient::get_output_devices);

	ClassDB::bind_method(D_METHOD("get_output_volume"),
			&DiscordClient::get_output_volume);

	ClassDB::bind_method(D_METHOD("get_self_deaf_all"),
			&DiscordClient::get_self_deaf_all);

	ClassDB::bind_method(D_METHOD("get_self_mute_all"),
			&DiscordClient::get_self_mute_all);

	ClassDB::bind_method(D_METHOD("set_automatic_gain_control", "on"),
			&DiscordClient::set_automatic_gain_control);

	ClassDB::bind_method(D_METHOD("set_device_change_callback"),
			&DiscordClient::set_device_change_callback);

	ClassDB::bind_method(D_METHOD("set_echo_cancellation", "on"),
			&DiscordClient::set_echo_cancellation);

	ClassDB::bind_method(D_METHOD("set_input_device", "device_id"),
			&DiscordClient::set_input_device);

	ClassDB::bind_method(D_METHOD("set_input_volume", "input_volume"),
			&DiscordClient::set_input_volume);

	ClassDB::bind_method(D_METHOD("set_no_audio_input_callback"),
			&DiscordClient::set_no_audio_input_callback);

	ClassDB::bind_method(D_METHOD("set_no_audio_input_threshold", "d_bfsthreshold"),
			&DiscordClient::set_no_audio_input_threshold);

	ClassDB::bind_method(D_METHOD("set_noise_suppression", "on"),
			&DiscordClient::set_noise_suppression);

	ClassDB::bind_method(D_METHOD("set_opus_hardware_coding", "encode", "decode"),
			&DiscordClient::set_opus_hardware_coding);

	ClassDB::bind_method(D_METHOD("set_output_device", "device_id"),
			&DiscordClient::set_output_device);

	ClassDB::bind_method(D_METHOD("set_output_volume", "output_volume"),
			&DiscordClient::set_output_volume);

	ClassDB::bind_method(D_METHOD("set_self_deaf_all", "deaf"),
			&DiscordClient::set_self_deaf_all);

	ClassDB::bind_method(D_METHOD("set_self_mute_all", "mute"),
			&DiscordClient::set_self_mute_all);

	ClassDB::bind_method(D_METHOD("set_speaker_mode", "speaker_mode"),
			&DiscordClient::set_speaker_mode);

	ClassDB::bind_method(D_METHOD("set_thread_priority", "thread", "priority"),
			&DiscordClient::set_thread_priority);

	ClassDB::bind_method(D_METHOD("set_voice_participant_changed_callback"),
			&DiscordClient::set_voice_participant_changed_callback);

	ClassDB::bind_method(D_METHOD("show_audio_route_picker"),
			&DiscordClient::show_audio_route_picker);

	ClassDB::bind_method(D_METHOD("start_call", "channel_id"),
			&DiscordClient::start_call);

	ClassDB::bind_method(D_METHOD("start_call_with_audio_callbacks", "lobby_id"),
			&DiscordClient::start_call_with_audio_callbacks);

	ClassDB::bind_method(D_METHOD("abort_authorize"),
			&DiscordClient::abort_authorize);

	ClassDB::bind_method(D_METHOD("abort_get_token_from_device"),
			&DiscordClient::abort_get_token_from_device);

	ClassDB::bind_method(D_METHOD("authorize", "args"),
			&DiscordClient::authorize);

	ClassDB::bind_method(D_METHOD("close_authorize_device_screen"),
			&DiscordClient::close_authorize_device_screen);

	ClassDB::bind_method(D_METHOD("create_authorization_code_verifier"),
			&DiscordClient::create_authorization_code_verifier);

	ClassDB::bind_method(D_METHOD("fetch_current_user", "token_type", "token"),
			&DiscordClient::fetch_current_user);

	ClassDB::bind_method(D_METHOD("get_provisional_token", "application_id", "external_auth_type", "external_auth_token"),
			&DiscordClient::get_provisional_token);

	ClassDB::bind_method(D_METHOD("get_token", "application_id", "code", "code_verifier", "redirect_uri"),
			&DiscordClient::get_token);

	ClassDB::bind_method(D_METHOD("get_token_from_device", "args"),
			&DiscordClient::get_token_from_device);

	ClassDB::bind_method(D_METHOD("get_token_from_device_provisional_merge", "args", "external_auth_type", "external_auth_token"),
			&DiscordClient::get_token_from_device_provisional_merge);

	ClassDB::bind_method(D_METHOD("get_token_from_provisional_merge", "application_id", "code", "code_verifier", "redirect_uri", "external_auth_type", "external_auth_token"),
			&DiscordClient::get_token_from_provisional_merge);

	ClassDB::bind_method(D_METHOD("is_authenticated"),
			&DiscordClient::is_authenticated);

	ClassDB::bind_method(D_METHOD("open_authorize_device_screen", "client_id", "user_code"),
			&DiscordClient::open_authorize_device_screen);

	ClassDB::bind_method(D_METHOD("provisional_user_merge_completed", "success"),
			&DiscordClient::provisional_user_merge_completed);

	ClassDB::bind_method(D_METHOD("refresh_token", "application_id", "refresh_token"),
			&DiscordClient::refresh_token);

	ClassDB::bind_method(D_METHOD("set_authorize_device_screen_closed_callback"),
			&DiscordClient::set_authorize_device_screen_closed_callback);

	ClassDB::bind_method(D_METHOD("set_game_window_pid", "pid"),
			&DiscordClient::set_game_window_pid);

	ClassDB::bind_method(D_METHOD("set_token_expiration_callback"),
			&DiscordClient::set_token_expiration_callback);

	ClassDB::bind_method(D_METHOD("update_provisional_account_display_name", "name"),
			&DiscordClient::update_provisional_account_display_name);

	ClassDB::bind_method(D_METHOD("update_token", "token_type", "token"),
			&DiscordClient::update_token);

	ClassDB::bind_method(D_METHOD("can_open_message_in_discord", "message_id"),
			&DiscordClient::can_open_message_in_discord);

	ClassDB::bind_method(D_METHOD("delete_user_message", "recipient_id", "message_id"),
			&DiscordClient::delete_user_message);

	ClassDB::bind_method(D_METHOD("edit_user_message", "recipient_id", "message_id", "content"),
			&DiscordClient::edit_user_message);

	ClassDB::bind_method(D_METHOD("get_channel_handle", "channel_id"),
			&DiscordClient::get_channel_handle);

	ClassDB::bind_method(D_METHOD("get_message_handle", "message_id"),
			&DiscordClient::get_message_handle);

	ClassDB::bind_method(D_METHOD("open_message_in_discord", "message_id"),
			&DiscordClient::open_message_in_discord);

	ClassDB::bind_method(D_METHOD("send_lobby_message", "lobby_id", "content"),
			&DiscordClient::send_lobby_message);

	ClassDB::bind_method(D_METHOD("send_lobby_message_with_metadata", "lobby_id", "content", "metadata"),
			&DiscordClient::send_lobby_message_with_metadata);

	ClassDB::bind_method(D_METHOD("send_user_message", "recipient_id", "content"),
			&DiscordClient::send_user_message);

	ClassDB::bind_method(D_METHOD("send_user_message_with_metadata", "recipient_id", "content", "metadata"),
			&DiscordClient::send_user_message_with_metadata);

	ClassDB::bind_method(D_METHOD("set_message_created_callback"),
			&DiscordClient::set_message_created_callback);

	ClassDB::bind_method(D_METHOD("set_message_deleted_callback"),
			&DiscordClient::set_message_deleted_callback);

	ClassDB::bind_method(D_METHOD("set_message_updated_callback"),
			&DiscordClient::set_message_updated_callback);

	ClassDB::bind_method(D_METHOD("set_showing_chat", "showing_chat"),
			&DiscordClient::set_showing_chat);

	ClassDB::bind_method(D_METHOD("add_log_callback", "min_severity"),
			&DiscordClient::add_log_callback);

	ClassDB::bind_method(D_METHOD("add_voice_log_callback", "min_severity"),
			&DiscordClient::add_voice_log_callback);

	ClassDB::bind_method(D_METHOD("connect"),
			&DiscordClient::connect);

	ClassDB::bind_method(D_METHOD("disconnect"),
			&DiscordClient::disconnect);

	ClassDB::bind_method(D_METHOD("get_status"),
			&DiscordClient::get_status);

	ClassDB::bind_method(D_METHOD("set_log_dir", "path", "min_severity"),
			&DiscordClient::set_log_dir);

	ClassDB::bind_method(D_METHOD("set_status_changed_callback"),
			&DiscordClient::set_status_changed_callback);

	ClassDB::bind_method(D_METHOD("set_voice_log_dir", "path", "min_severity"),
			&DiscordClient::set_voice_log_dir);

	ClassDB::bind_method(D_METHOD("create_or_join_lobby", "secret"),
			&DiscordClient::create_or_join_lobby);

	ClassDB::bind_method(D_METHOD("create_or_join_lobby_with_metadata", "secret", "lobby_metadata", "member_metadata"),
			&DiscordClient::create_or_join_lobby_with_metadata);

	ClassDB::bind_method(D_METHOD("get_guild_channels", "guild_id"),
			&DiscordClient::get_guild_channels);

	ClassDB::bind_method(D_METHOD("get_lobby_handle", "lobby_id"),
			&DiscordClient::get_lobby_handle);

	ClassDB::bind_method(D_METHOD("get_lobby_ids"),
			&DiscordClient::get_lobby_ids);

	ClassDB::bind_method(D_METHOD("get_user_guilds"),
			&DiscordClient::get_user_guilds);

	ClassDB::bind_method(D_METHOD("leave_lobby", "lobby_id"),
			&DiscordClient::leave_lobby);

	ClassDB::bind_method(D_METHOD("link_channel_to_lobby", "lobby_id", "channel_id"),
			&DiscordClient::link_channel_to_lobby);

	ClassDB::bind_method(D_METHOD("set_lobby_created_callback"),
			&DiscordClient::set_lobby_created_callback);

	ClassDB::bind_method(D_METHOD("set_lobby_deleted_callback"),
			&DiscordClient::set_lobby_deleted_callback);

	ClassDB::bind_method(D_METHOD("set_lobby_member_added_callback"),
			&DiscordClient::set_lobby_member_added_callback);

	ClassDB::bind_method(D_METHOD("set_lobby_member_removed_callback"),
			&DiscordClient::set_lobby_member_removed_callback);

	ClassDB::bind_method(D_METHOD("set_lobby_member_updated_callback"),
			&DiscordClient::set_lobby_member_updated_callback);

	ClassDB::bind_method(D_METHOD("set_lobby_updated_callback"),
			&DiscordClient::set_lobby_updated_callback);

	ClassDB::bind_method(D_METHOD("unlink_channel_from_lobby", "lobby_id"),
			&DiscordClient::unlink_channel_from_lobby);

	ClassDB::bind_method(D_METHOD("accept_activity_invite", "invite"),
			&DiscordClient::accept_activity_invite);

	ClassDB::bind_method(D_METHOD("clear_rich_presence"),
			&DiscordClient::clear_rich_presence);

	ClassDB::bind_method(D_METHOD("register_launch_command", "application_id", "command"),
			&DiscordClient::register_launch_command);

	ClassDB::bind_method(D_METHOD("register_launch_steam_application", "application_id", "steam_app_id"),
			&DiscordClient::register_launch_steam_application);

	ClassDB::bind_method(D_METHOD("send_activity_invite", "user_id", "content"),
			&DiscordClient::send_activity_invite);

	ClassDB::bind_method(D_METHOD("send_activity_join_request", "user_id"),
			&DiscordClient::send_activity_join_request);

	ClassDB::bind_method(D_METHOD("send_activity_join_request_reply", "invite"),
			&DiscordClient::send_activity_join_request_reply);

	ClassDB::bind_method(D_METHOD("set_activity_invite_created_callback"),
			&DiscordClient::set_activity_invite_created_callback);

	ClassDB::bind_method(D_METHOD("set_activity_invite_updated_callback"),
			&DiscordClient::set_activity_invite_updated_callback);

	ClassDB::bind_method(D_METHOD("set_activity_join_callback"),
			&DiscordClient::set_activity_join_callback);

	ClassDB::bind_method(D_METHOD("set_online_status", "status"),
			&DiscordClient::set_online_status);

	ClassDB::bind_method(D_METHOD("update_rich_presence", "activity"),
			&DiscordClient::update_rich_presence);

	ClassDB::bind_method(D_METHOD("accept_discord_friend_request", "user_id"),
			&DiscordClient::accept_discord_friend_request);

	ClassDB::bind_method(D_METHOD("accept_game_friend_request", "user_id"),
			&DiscordClient::accept_game_friend_request);

	ClassDB::bind_method(D_METHOD("block_user", "user_id"),
			&DiscordClient::block_user);

	ClassDB::bind_method(D_METHOD("cancel_discord_friend_request", "user_id"),
			&DiscordClient::cancel_discord_friend_request);

	ClassDB::bind_method(D_METHOD("cancel_game_friend_request", "user_id"),
			&DiscordClient::cancel_game_friend_request);

	ClassDB::bind_method(D_METHOD("get_relationship_handle", "user_id"),
			&DiscordClient::get_relationship_handle);

	ClassDB::bind_method(D_METHOD("get_relationships"),
			&DiscordClient::get_relationships);

	ClassDB::bind_method(D_METHOD("reject_discord_friend_request", "user_id"),
			&DiscordClient::reject_discord_friend_request);

	ClassDB::bind_method(D_METHOD("reject_game_friend_request", "user_id"),
			&DiscordClient::reject_game_friend_request);

	ClassDB::bind_method(D_METHOD("remove_discord_and_game_friend", "user_id"),
			&DiscordClient::remove_discord_and_game_friend);

	ClassDB::bind_method(D_METHOD("remove_game_friend", "user_id"),
			&DiscordClient::remove_game_friend);

	ClassDB::bind_method(D_METHOD("search_friends_by_username", "search_str"),
			&DiscordClient::search_friends_by_username);

	ClassDB::bind_method(D_METHOD("send_discord_friend_request", "username"),
			&DiscordClient::send_discord_friend_request);

	ClassDB::bind_method(D_METHOD("send_discord_friend_request_by_id", "user_id"),
			&DiscordClient::send_discord_friend_request_by_id);

	ClassDB::bind_method(D_METHOD("send_game_friend_request", "username"),
			&DiscordClient::send_game_friend_request);

	ClassDB::bind_method(D_METHOD("send_game_friend_request_by_id", "user_id"),
			&DiscordClient::send_game_friend_request_by_id);

	ClassDB::bind_method(D_METHOD("set_relationship_created_callback"),
			&DiscordClient::set_relationship_created_callback);

	ClassDB::bind_method(D_METHOD("set_relationship_deleted_callback"),
			&DiscordClient::set_relationship_deleted_callback);

	ClassDB::bind_method(D_METHOD("unblock_user", "user_id"),
			&DiscordClient::unblock_user);

	ClassDB::bind_method(D_METHOD("get_current_user"),
			&DiscordClient::get_current_user);

	ClassDB::bind_method(D_METHOD("get_discord_client_connected_user", "application_id"),
			&DiscordClient::get_discord_client_connected_user);

	ClassDB::bind_method(D_METHOD("get_user", "user_id"),
			&DiscordClient::get_user);

	ClassDB::bind_method(D_METHOD("set_user_updated_callback"),
			&DiscordClient::set_user_updated_callback);
}

DiscordClient::DiscordClient() {
	this->client = memnew(discordpp::Client);
}

DiscordClient::DiscordClient(discordpp::Client *client) {
	this->client = client;
}

DiscordClient::~DiscordClient() {}
