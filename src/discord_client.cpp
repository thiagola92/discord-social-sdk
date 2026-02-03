
#include "discord_classes.h"

using namespace godot;

// Functions.

DiscordAuthorizationCodeVerifier *DiscordClient::create_authorization_code_verifier() {
	auto r = obj->CreateAuthorizationCodeVerifier();

	discordpp::AuthorizationCodeVerifier *cr_t = memnew(discordpp::AuthorizationCodeVerifier(std::move(r)));
	DiscordAuthorizationCodeVerifier *cr = memnew(DiscordAuthorizationCodeVerifier{ cr_t });

	return cr;
}

DiscordCall *DiscordClient::get_call(int64_t channel_id) {
	int64_t p0 = channel_id;
	auto r = obj->GetCall(p0);

	discordpp::Call *cr_t = memnew(discordpp::Call(std::move(r)));
	DiscordCall *cr = memnew(DiscordCall{ cr_t });

	return cr;
}

DiscordCall *DiscordClient::start_call(int64_t channel_id) {
	int64_t p0 = channel_id;
	auto r = obj->StartCall(p0);

	discordpp::Call *cr_t = memnew(discordpp::Call(std::move(r)));
	DiscordCall *cr = memnew(DiscordCall{ cr_t });

	return cr;
}

DiscordCall *DiscordClient::start_call_with_audio_callbacks(int64_t lobby_id, Callable received_cb, Callable captured_cb) {
	int64_t p0 = lobby_id;
	auto p1 = [received_cb](auto user_id, auto data, auto samples_per_channel, auto sample_rate, auto channels, auto out_should_mute) {
		int64_t p0 = (int64_t)user_id;
		int64_t p1 = (int64_t)data;
		int64_t p2 = (int64_t)samples_per_channel;
		int64_t p3 = (int64_t)sample_rate;
		int64_t p4 = (int64_t)channels;
		bool p5 = out_should_mute;
	};

	auto p2 = [captured_cb](auto data, auto samples_per_channel, auto sample_rate, auto channels) {
		int64_t p0 = (int64_t)data;
		int64_t p1 = (int64_t)samples_per_channel;
		int64_t p2 = (int64_t)sample_rate;
		int64_t p3 = (int64_t)channels;
	};

	auto r = obj->StartCallWithAudioCallbacks(p0, p1, p2);

	discordpp::Call *cr_t = memnew(discordpp::Call(std::move(r)));
	DiscordCall *cr = memnew(DiscordCall{ cr_t });

	return cr;
}

DiscordClientStatus::Enum DiscordClient::get_status() {
	auto r = obj->GetStatus();

	DiscordClientStatus::Enum cr = (DiscordClientStatus::Enum)r;
	return cr;
}

DiscordRelationshipHandle *DiscordClient::get_relationship_handle(int64_t user_id) {
	int64_t p0 = user_id;
	auto r = obj->GetRelationshipHandle(p0);

	discordpp::RelationshipHandle *cr_t = memnew(discordpp::RelationshipHandle(std::move(r)));
	DiscordRelationshipHandle *cr = memnew(DiscordRelationshipHandle{ cr_t });

	return cr;
}

DiscordUserHandle *DiscordClient::get_current_user() {
	auto r = obj->GetCurrentUser();

	discordpp::UserHandle *cr_t = memnew(discordpp::UserHandle(std::move(r)));
	DiscordUserHandle *cr = memnew(DiscordUserHandle{ cr_t });

	return cr;
}

String DiscordClient::error_to_string(DiscordClientError::Enum type) {
	discordpp::Client::Error p0 = (discordpp::Client::Error)type;
	auto r = discordpp::Client::ErrorToString(p0);

	String cr = String(r.c_str());
	return cr;
}

String DiscordClient::get_default_audio_device_id() {
	auto r = discordpp::Client::GetDefaultAudioDeviceId();

	String cr = String(r.c_str());
	return cr;
}

String DiscordClient::get_default_communication_scopes() {
	auto r = discordpp::Client::GetDefaultCommunicationScopes();

	String cr = String(r.c_str());
	return cr;
}

String DiscordClient::get_default_presence_scopes() {
	auto r = discordpp::Client::GetDefaultPresenceScopes();

	String cr = String(r.c_str());
	return cr;
}

String DiscordClient::get_version_hash() {
	auto r = discordpp::Client::GetVersionHash();

	String cr = String(r.c_str());
	return cr;
}

String DiscordClient::status_to_string(DiscordClientStatus::Enum type) {
	discordpp::Client::Status p0 = (discordpp::Client::Status)type;
	auto r = discordpp::Client::StatusToString(p0);

	String cr = String(r.c_str());
	return cr;
}

String DiscordClient::thread_to_string(DiscordClientThread::Enum type) {
	discordpp::Client::Thread p0 = (discordpp::Client::Thread)type;
	auto r = discordpp::Client::ThreadToString(p0);

	String cr = String(r.c_str());
	return cr;
}

TypedArray<DiscordCall> DiscordClient::get_calls() {
	auto r = obj->GetCalls();

	TypedArray<DiscordCall> cr = TypedArray<DiscordCall>();

	for (auto i : r) {
		discordpp::Call *cr_t_t = memnew(discordpp::Call(std::move(i)));
		DiscordCall *cr_t = memnew(DiscordCall{ cr_t_t });

		cr.push_back(cr_t);
	}

	return cr;
}

TypedArray<DiscordRelationshipHandle> DiscordClient::get_relationships() {
	auto r = obj->GetRelationships();

	TypedArray<DiscordRelationshipHandle> cr = TypedArray<DiscordRelationshipHandle>();

	for (auto i : r) {
		discordpp::RelationshipHandle *cr_t_t = memnew(discordpp::RelationshipHandle(std::move(i)));
		DiscordRelationshipHandle *cr_t = memnew(DiscordRelationshipHandle{ cr_t_t });

		cr.push_back(cr_t);
	}

	return cr;
}

TypedArray<DiscordRelationshipHandle> DiscordClient::get_relationships_by_group(DiscordRelationshipGroupType::Enum group_type) {
	discordpp::RelationshipGroupType p0 = (discordpp::RelationshipGroupType)group_type;
	auto r = obj->GetRelationshipsByGroup(p0);

	TypedArray<DiscordRelationshipHandle> cr = TypedArray<DiscordRelationshipHandle>();

	for (auto i : r) {
		discordpp::RelationshipHandle *cr_t_t = memnew(discordpp::RelationshipHandle(std::move(i)));
		DiscordRelationshipHandle *cr_t = memnew(DiscordRelationshipHandle{ cr_t_t });

		cr.push_back(cr_t);
	}

	return cr;
}

TypedArray<DiscordUserHandle> DiscordClient::search_friends_by_username(String search_str) {
	std::string p0 = std::string(search_str.utf8().get_data());
	auto r = obj->SearchFriendsByUsername(p0);

	TypedArray<DiscordUserHandle> cr = TypedArray<DiscordUserHandle>();

	for (auto i : r) {
		discordpp::UserHandle *cr_t_t = memnew(discordpp::UserHandle(std::move(i)));
		DiscordUserHandle *cr_t = memnew(DiscordUserHandle{ cr_t_t });

		cr.push_back(cr_t);
	}

	return cr;
}

TypedArray<int64_t> DiscordClient::get_lobby_ids() {
	auto r = obj->GetLobbyIds();

	TypedArray<int64_t> cr = TypedArray<int64_t>();

	for (auto i : r) {
		int64_t cr_t = (int64_t)i;
		cr.push_back(cr_t);
	}

	return cr;
}

Variant DiscordClient::get_channel_handle(int64_t channel_id) {
	int64_t p0 = channel_id;
	auto r = obj->GetChannelHandle(p0);

	Variant cr;

	if (!r.has_value()) {
		cr = nullptr;
	} else {
		auto r_v = r.value();

		discordpp::ChannelHandle *cr_v_t = memnew(discordpp::ChannelHandle(std::move(r_v)));
		DiscordChannelHandle *cr_v = memnew(DiscordChannelHandle{ cr_v_t });

		cr = Variant(cr_v);
	}

	return cr;
}

Variant DiscordClient::get_current_user_v2() {
	auto r = obj->GetCurrentUserV2();

	Variant cr;

	if (!r.has_value()) {
		cr = nullptr;
	} else {
		auto r_v = r.value();

		discordpp::UserHandle *cr_v_t = memnew(discordpp::UserHandle(std::move(r_v)));
		DiscordUserHandle *cr_v = memnew(DiscordUserHandle{ cr_v_t });

		cr = Variant(cr_v);
	}

	return cr;
}

Variant DiscordClient::get_lobby_handle(int64_t lobby_id) {
	int64_t p0 = lobby_id;
	auto r = obj->GetLobbyHandle(p0);

	Variant cr;

	if (!r.has_value()) {
		cr = nullptr;
	} else {
		auto r_v = r.value();

		discordpp::LobbyHandle *cr_v_t = memnew(discordpp::LobbyHandle(std::move(r_v)));
		DiscordLobbyHandle *cr_v = memnew(DiscordLobbyHandle{ cr_v_t });

		cr = Variant(cr_v);
	}

	return cr;
}

Variant DiscordClient::get_message_handle(int64_t message_id) {
	int64_t p0 = message_id;
	auto r = obj->GetMessageHandle(p0);

	Variant cr;

	if (!r.has_value()) {
		cr = nullptr;
	} else {
		auto r_v = r.value();

		discordpp::MessageHandle *cr_v_t = memnew(discordpp::MessageHandle(std::move(r_v)));
		DiscordMessageHandle *cr_v = memnew(DiscordMessageHandle{ cr_v_t });

		cr = Variant(cr_v);
	}

	return cr;
}

Variant DiscordClient::get_user(int64_t user_id) {
	int64_t p0 = user_id;
	auto r = obj->GetUser(p0);

	Variant cr;

	if (!r.has_value()) {
		cr = nullptr;
	} else {
		auto r_v = r.value();

		discordpp::UserHandle *cr_v_t = memnew(discordpp::UserHandle(std::move(r_v)));
		DiscordUserHandle *cr_v = memnew(DiscordUserHandle{ cr_v_t });

		cr = Variant(cr_v);
	}

	return cr;
}

bool DiscordClient::can_open_message_in_discord(int64_t message_id) {
	int64_t p0 = message_id;
	auto r = obj->CanOpenMessageInDiscord(p0);

	bool cr = r;
	return cr;
}

bool DiscordClient::get_self_deaf_all() {
	auto r = obj->GetSelfDeafAll();

	bool cr = r;
	return cr;
}

bool DiscordClient::get_self_mute_all() {
	auto r = obj->GetSelfMuteAll();

	bool cr = r;
	return cr;
}

bool DiscordClient::is_authenticated() {
	auto r = obj->IsAuthenticated();

	bool cr = r;
	return cr;
}

bool DiscordClient::register_launch_command(int64_t application_id, String command) {
	int64_t p0 = application_id;
	std::string p1 = std::string(command.utf8().get_data());
	auto r = obj->RegisterLaunchCommand(p0, p1);

	bool cr = r;
	return cr;
}

bool DiscordClient::register_launch_steam_application(int64_t application_id, int64_t steam_app_id) {
	int64_t p0 = application_id;
	int64_t p1 = steam_app_id;
	auto r = obj->RegisterLaunchSteamApplication(p0, p1);

	bool cr = r;
	return cr;
}

bool DiscordClient::set_log_dir(String path, DiscordLoggingSeverity::Enum min_severity) {
	std::string p0 = std::string(path.utf8().get_data());
	discordpp::LoggingSeverity p1 = (discordpp::LoggingSeverity)min_severity;
	auto r = obj->SetLogDir(p0, p1);

	bool cr = r;
	return cr;
}

bool DiscordClient::set_speaker_mode(bool speaker_mode) {
	bool p0 = speaker_mode;
	auto r = obj->SetSpeakerMode(p0);

	bool cr = r;
	return cr;
}

bool DiscordClient::show_audio_route_picker() {
	auto r = obj->ShowAudioRoutePicker();

	bool cr = r;
	return cr;
}

float DiscordClient::get_input_volume() {
	auto r = obj->GetInputVolume();

	float cr = (float)r;
	return cr;
}

float DiscordClient::get_output_volume() {
	auto r = obj->GetOutputVolume();

	float cr = (float)r;
	return cr;
}

int64_t DiscordClient::get_application_id() {
	auto r = obj->GetApplicationId();

	int64_t cr = (int64_t)r;
	return cr;
}

int64_t DiscordClient::get_version_major() {
	auto r = discordpp::Client::GetVersionMajor();

	int64_t cr = (int64_t)r;
	return cr;
}

int64_t DiscordClient::get_version_minor() {
	auto r = discordpp::Client::GetVersionMinor();

	int64_t cr = (int64_t)r;
	return cr;
}

int64_t DiscordClient::get_version_patch() {
	auto r = discordpp::Client::GetVersionPatch();

	int64_t cr = (int64_t)r;
	return cr;
}

void DiscordClient::abort_authorize() {
	obj->AbortAuthorize();
}

void DiscordClient::abort_get_token_from_device() {
	obj->AbortGetTokenFromDevice();
}

void DiscordClient::accept_activity_invite(DiscordActivityInvite *invite, Callable cb) {
	discordpp::ActivityInvite p0 = *invite->unwrap();
	auto p1 = [cb](auto result, auto join_secret) {
		discordpp::ClientResult *p0_t = memnew(discordpp::ClientResult(std::move(result)));
		DiscordClientResult *p0 = memnew(DiscordClientResult{ p0_t });

		String p1 = String(join_secret.c_str());
	};

	obj->AcceptActivityInvite(p0, p1);
}

void DiscordClient::accept_discord_friend_request(int64_t user_id, Callable cb) {
	int64_t p0 = user_id;
	auto p1 = [cb](auto result) {
		discordpp::ClientResult *p0_t = memnew(discordpp::ClientResult(std::move(result)));
		DiscordClientResult *p0 = memnew(DiscordClientResult{ p0_t });
	};

	obj->AcceptDiscordFriendRequest(p0, p1);
}

void DiscordClient::accept_game_friend_request(int64_t user_id, Callable cb) {
	int64_t p0 = user_id;
	auto p1 = [cb](auto result) {
		discordpp::ClientResult *p0_t = memnew(discordpp::ClientResult(std::move(result)));
		DiscordClientResult *p0 = memnew(DiscordClientResult{ p0_t });
	};

	obj->AcceptGameFriendRequest(p0, p1);
}

void DiscordClient::add_log_callback(Callable callback, DiscordLoggingSeverity::Enum min_severity) {
	auto p0 = [callback](auto message, auto severity) {
		String p0 = String(message.c_str());
		DiscordLoggingSeverity::Enum p1 = (DiscordLoggingSeverity::Enum)severity;
	};
	discordpp::LoggingSeverity p1 = (discordpp::LoggingSeverity)min_severity;
	obj->AddLogCallback(p0, p1);
}

void DiscordClient::add_voice_log_callback(Callable callback, DiscordLoggingSeverity::Enum min_severity) {
	auto p0 = [callback](auto message, auto severity) {
		String p0 = String(message.c_str());
		DiscordLoggingSeverity::Enum p1 = (DiscordLoggingSeverity::Enum)severity;
	};
	discordpp::LoggingSeverity p1 = (discordpp::LoggingSeverity)min_severity;
	obj->AddVoiceLogCallback(p0, p1);
}

void DiscordClient::authorize(DiscordAuthorizationArgs *args, Callable callback) {
	discordpp::AuthorizationArgs p0 = *args->unwrap();
	auto p1 = [callback](auto result, auto code, auto redirect_uri) {
		discordpp::ClientResult *p0_t = memnew(discordpp::ClientResult(std::move(result)));
		DiscordClientResult *p0 = memnew(DiscordClientResult{ p0_t });

		String p1 = String(code.c_str());
		String p2 = String(redirect_uri.c_str());
	};

	obj->Authorize(p0, p1);
}

void DiscordClient::block_user(int64_t user_id, Callable cb) {
	int64_t p0 = user_id;
	auto p1 = [cb](auto result) {
		discordpp::ClientResult *p0_t = memnew(discordpp::ClientResult(std::move(result)));
		DiscordClientResult *p0 = memnew(DiscordClientResult{ p0_t });
	};

	obj->BlockUser(p0, p1);
}

void DiscordClient::cancel_discord_friend_request(int64_t user_id, Callable cb) {
	int64_t p0 = user_id;
	auto p1 = [cb](auto result) {
		discordpp::ClientResult *p0_t = memnew(discordpp::ClientResult(std::move(result)));
		DiscordClientResult *p0 = memnew(DiscordClientResult{ p0_t });
	};

	obj->CancelDiscordFriendRequest(p0, p1);
}

void DiscordClient::cancel_game_friend_request(int64_t user_id, Callable cb) {
	int64_t p0 = user_id;
	auto p1 = [cb](auto result) {
		discordpp::ClientResult *p0_t = memnew(discordpp::ClientResult(std::move(result)));
		DiscordClientResult *p0 = memnew(DiscordClientResult{ p0_t });
	};

	obj->CancelGameFriendRequest(p0, p1);
}

void DiscordClient::clear_rich_presence() {
	obj->ClearRichPresence();
}

void DiscordClient::close_authorize_device_screen() {
	obj->CloseAuthorizeDeviceScreen();
}

void DiscordClient::connect_discord() {
	obj->Connect();
}

void DiscordClient::create_or_join_lobby(String secret, Callable callback) {
	std::string p0 = std::string(secret.utf8().get_data());
	auto p1 = [callback](auto result, auto lobby_id) {
		discordpp::ClientResult *p0_t = memnew(discordpp::ClientResult(std::move(result)));
		DiscordClientResult *p0 = memnew(DiscordClientResult{ p0_t });

		int64_t p1 = (int64_t)lobby_id;
	};

	obj->CreateOrJoinLobby(p0, p1);
}

void DiscordClient::create_or_join_lobby_with_metadata(String secret, TypedDictionary<String, String> lobby_metadata, TypedDictionary<String, String> member_metadata, Callable callback) {
	std::string p0 = std::string(secret.utf8().get_data());
	std::unordered_map<std::string, std::string> p1 = std::unordered_map<std::string, std::string>();
	auto p1k = lobby_metadata.keys();

	for (int i = 0; i < p1k.size(); i++) {
		auto k = p1k[i];
		auto v = lobby_metadata[k];
		std::string kv;
		std::string vv;

		kv = k.stringify().utf8().get_data();
		vv = v.stringify().utf8().get_data();

		p1[kv] = vv;
	}

	std::unordered_map<std::string, std::string> p2 = std::unordered_map<std::string, std::string>();
	auto p2k = member_metadata.keys();

	for (int i = 0; i < p2k.size(); i++) {
		auto k = p2k[i];
		auto v = member_metadata[k];
		std::string kv;
		std::string vv;

		kv = k.stringify().utf8().get_data();
		vv = v.stringify().utf8().get_data();

		p2[kv] = vv;
	}

	auto p3 = [callback](auto result, auto lobby_id) {
		discordpp::ClientResult *p0_t = memnew(discordpp::ClientResult(std::move(result)));
		DiscordClientResult *p0 = memnew(DiscordClientResult{ p0_t });

		int64_t p1 = (int64_t)lobby_id;
	};

	obj->CreateOrJoinLobbyWithMetadata(p0, p1, p2, p3);
}

void DiscordClient::delete_user_message(int64_t recipient_id, int64_t message_id, Callable cb) {
	int64_t p0 = recipient_id;
	int64_t p1 = message_id;
	auto p2 = [cb](auto result) {
		discordpp::ClientResult *p0_t = memnew(discordpp::ClientResult(std::move(result)));
		DiscordClientResult *p0 = memnew(DiscordClientResult{ p0_t });
	};

	obj->DeleteUserMessage(p0, p1, p2);
}

void DiscordClient::disconnect_discord() {
	obj->Disconnect();
}

void DiscordClient::edit_user_message(int64_t recipient_id, int64_t message_id, String content, Callable cb) {
	int64_t p0 = recipient_id;
	int64_t p1 = message_id;
	std::string p2 = std::string(content.utf8().get_data());
	auto p3 = [cb](auto result) {
		discordpp::ClientResult *p0_t = memnew(discordpp::ClientResult(std::move(result)));
		DiscordClientResult *p0 = memnew(DiscordClientResult{ p0_t });
	};

	obj->EditUserMessage(p0, p1, p2, p3);
}

void DiscordClient::end_call(int64_t channel_id, Callable callback) {
	int64_t p0 = channel_id;
	auto p1 = [callback]() {

	};

	obj->EndCall(p0, p1);
}

void DiscordClient::end_calls(Callable callback) {
	auto p0 = [callback]() {

	};

	obj->EndCalls(p0);
}

void DiscordClient::exchange_child_token(String parent_application_token, int64_t child_application_id, Callable callback) {
	std::string p0 = std::string(parent_application_token.utf8().get_data());
	int64_t p1 = child_application_id;
	auto p2 = [callback](auto result, auto access_token, auto token_type, auto expires_in, auto scopes) {
		discordpp::ClientResult *p0_t = memnew(discordpp::ClientResult(std::move(result)));
		DiscordClientResult *p0 = memnew(DiscordClientResult{ p0_t });

		String p1 = String(access_token.c_str());
		DiscordAuthorizationTokenType::Enum p2 = (DiscordAuthorizationTokenType::Enum)token_type;
		int64_t p3 = (int64_t)expires_in;
		String p4 = String(scopes.c_str());
	};

	obj->ExchangeChildToken(p0, p1, p2);
}

void DiscordClient::fetch_current_user(DiscordAuthorizationTokenType::Enum token_type, String token, Callable callback) {
	discordpp::AuthorizationTokenType p0 = (discordpp::AuthorizationTokenType)token_type;
	std::string p1 = std::string(token.utf8().get_data());
	auto p2 = [callback](auto result, auto id, auto name) {
		discordpp::ClientResult *p0_t = memnew(discordpp::ClientResult(std::move(result)));
		DiscordClientResult *p0 = memnew(DiscordClientResult{ p0_t });

		int64_t p1 = (int64_t)id;
		String p2 = String(name.c_str());
	};

	obj->FetchCurrentUser(p0, p1, p2);
}

void DiscordClient::get_current_input_device(Callable cb) {
	auto p0 = [cb](auto device) {
		discordpp::AudioDevice *p0_t = memnew(discordpp::AudioDevice(std::move(device)));
		DiscordAudioDevice *p0 = memnew(DiscordAudioDevice{ p0_t });
	};

	obj->GetCurrentInputDevice(p0);
}

void DiscordClient::get_current_output_device(Callable cb) {
	auto p0 = [cb](auto device) {
		discordpp::AudioDevice *p0_t = memnew(discordpp::AudioDevice(std::move(device)));
		DiscordAudioDevice *p0 = memnew(DiscordAudioDevice{ p0_t });
	};

	obj->GetCurrentOutputDevice(p0);
}

void DiscordClient::get_discord_client_connected_user(int64_t application_id, Callable callback) {
	int64_t p0 = application_id;
	auto p1 = [callback](auto result, auto user) {
		discordpp::ClientResult *p0_t = memnew(discordpp::ClientResult(std::move(result)));
		DiscordClientResult *p0 = memnew(DiscordClientResult{ p0_t });

		Variant p1;

		if (!user.has_value()) {
			p1 = nullptr;
		} else {
			auto user_v = user.value();

			discordpp::UserHandle *p1_v_t = memnew(discordpp::UserHandle(std::move(user_v)));
			DiscordUserHandle *p1_v = memnew(DiscordUserHandle{ p1_v_t });

			p1 = Variant(p1_v);
		}
	};

	obj->GetDiscordClientConnectedUser(p0, p1);
}

void DiscordClient::get_guild_channels(int64_t guild_id, Callable cb) {
	int64_t p0 = guild_id;
	auto p1 = [cb](auto result, auto guild_channels) {
		discordpp::ClientResult *p0_t = memnew(discordpp::ClientResult(std::move(result)));
		DiscordClientResult *p0 = memnew(DiscordClientResult{ p0_t });

		TypedArray<DiscordGuildChannel> p1 = TypedArray<DiscordGuildChannel>();

		for (auto i : guild_channels) {
			discordpp::GuildChannel *p1_t_t = memnew(discordpp::GuildChannel(std::move(i)));
			DiscordGuildChannel *p1_t = memnew(DiscordGuildChannel{ p1_t_t });

			p1.push_back(p1_t);
		}
	};

	obj->GetGuildChannels(p0, p1);
}

void DiscordClient::get_input_devices(Callable cb) {
	auto p0 = [cb](auto devices) {
		TypedArray<DiscordAudioDevice> p0 = TypedArray<DiscordAudioDevice>();

		for (auto i : devices) {
			discordpp::AudioDevice *p0_t_t = memnew(discordpp::AudioDevice(std::move(i)));
			DiscordAudioDevice *p0_t = memnew(DiscordAudioDevice{ p0_t_t });

			p0.push_back(p0_t);
		}
	};

	obj->GetInputDevices(p0);
}

void DiscordClient::get_lobby_messages_with_limit(int64_t lobby_id, int64_t limit, Callable cb) {
	int64_t p0 = lobby_id;
	int64_t p1 = limit;
	auto p2 = [cb](auto result, auto messages) {
		discordpp::ClientResult *p0_t = memnew(discordpp::ClientResult(std::move(result)));
		DiscordClientResult *p0 = memnew(DiscordClientResult{ p0_t });

		TypedArray<DiscordMessageHandle> p1 = TypedArray<DiscordMessageHandle>();

		for (auto i : messages) {
			discordpp::MessageHandle *p1_t_t = memnew(discordpp::MessageHandle(std::move(i)));
			DiscordMessageHandle *p1_t = memnew(DiscordMessageHandle{ p1_t_t });

			p1.push_back(p1_t);
		}
	};

	obj->GetLobbyMessagesWithLimit(p0, p1, p2);
}

void DiscordClient::get_output_devices(Callable cb) {
	auto p0 = [cb](auto devices) {
		TypedArray<DiscordAudioDevice> p0 = TypedArray<DiscordAudioDevice>();

		for (auto i : devices) {
			discordpp::AudioDevice *p0_t_t = memnew(discordpp::AudioDevice(std::move(i)));
			DiscordAudioDevice *p0_t = memnew(DiscordAudioDevice{ p0_t_t });

			p0.push_back(p0_t);
		}
	};

	obj->GetOutputDevices(p0);
}

void DiscordClient::get_provisional_token(int64_t application_id, DiscordAuthenticationExternalAuthType::Enum external_auth_type, String external_auth_token, Callable callback) {
	int64_t p0 = application_id;
	discordpp::AuthenticationExternalAuthType p1 = (discordpp::AuthenticationExternalAuthType)external_auth_type;
	std::string p2 = std::string(external_auth_token.utf8().get_data());
	auto p3 = [callback](auto result, auto access_token, auto refresh_token, auto token_type, auto expires_in, auto scopes) {
		discordpp::ClientResult *p0_t = memnew(discordpp::ClientResult(std::move(result)));
		DiscordClientResult *p0 = memnew(DiscordClientResult{ p0_t });

		String p1 = String(access_token.c_str());
		String p2 = String(refresh_token.c_str());
		DiscordAuthorizationTokenType::Enum p3 = (DiscordAuthorizationTokenType::Enum)token_type;
		int64_t p4 = (int64_t)expires_in;
		String p5 = String(scopes.c_str());
	};

	obj->GetProvisionalToken(p0, p1, p2, p3);
}

void DiscordClient::get_token(int64_t application_id, String code, String code_verifier, String redirect_uri, Callable callback) {
	int64_t p0 = application_id;
	std::string p1 = std::string(code.utf8().get_data());
	std::string p2 = std::string(code_verifier.utf8().get_data());
	std::string p3 = std::string(redirect_uri.utf8().get_data());
	auto p4 = [callback](auto result, auto access_token, auto refresh_token, auto token_type, auto expires_in, auto scopes) {
		discordpp::ClientResult *p0_t = memnew(discordpp::ClientResult(std::move(result)));
		DiscordClientResult *p0 = memnew(DiscordClientResult{ p0_t });

		String p1 = String(access_token.c_str());
		String p2 = String(refresh_token.c_str());
		DiscordAuthorizationTokenType::Enum p3 = (DiscordAuthorizationTokenType::Enum)token_type;
		int64_t p4 = (int64_t)expires_in;
		String p5 = String(scopes.c_str());
	};

	obj->GetToken(p0, p1, p2, p3, p4);
}

void DiscordClient::get_token_from_device(DiscordDeviceAuthorizationArgs *args, Callable callback) {
	discordpp::DeviceAuthorizationArgs p0 = *args->unwrap();
	auto p1 = [callback](auto result, auto access_token, auto refresh_token, auto token_type, auto expires_in, auto scopes) {
		discordpp::ClientResult *p0_t = memnew(discordpp::ClientResult(std::move(result)));
		DiscordClientResult *p0 = memnew(DiscordClientResult{ p0_t });

		String p1 = String(access_token.c_str());
		String p2 = String(refresh_token.c_str());
		DiscordAuthorizationTokenType::Enum p3 = (DiscordAuthorizationTokenType::Enum)token_type;
		int64_t p4 = (int64_t)expires_in;
		String p5 = String(scopes.c_str());
	};

	obj->GetTokenFromDevice(p0, p1);
}

void DiscordClient::get_token_from_device_provisional_merge(DiscordDeviceAuthorizationArgs *args, DiscordAuthenticationExternalAuthType::Enum external_auth_type, String external_auth_token, Callable callback) {
	discordpp::DeviceAuthorizationArgs p0 = *args->unwrap();
	discordpp::AuthenticationExternalAuthType p1 = (discordpp::AuthenticationExternalAuthType)external_auth_type;
	std::string p2 = std::string(external_auth_token.utf8().get_data());
	auto p3 = [callback](auto result, auto access_token, auto refresh_token, auto token_type, auto expires_in, auto scopes) {
		discordpp::ClientResult *p0_t = memnew(discordpp::ClientResult(std::move(result)));
		DiscordClientResult *p0 = memnew(DiscordClientResult{ p0_t });

		String p1 = String(access_token.c_str());
		String p2 = String(refresh_token.c_str());
		DiscordAuthorizationTokenType::Enum p3 = (DiscordAuthorizationTokenType::Enum)token_type;
		int64_t p4 = (int64_t)expires_in;
		String p5 = String(scopes.c_str());
	};

	obj->GetTokenFromDeviceProvisionalMerge(p0, p1, p2, p3);
}

void DiscordClient::get_token_from_provisional_merge(int64_t application_id, String code, String code_verifier, String redirect_uri, DiscordAuthenticationExternalAuthType::Enum external_auth_type, String external_auth_token, Callable callback) {
	int64_t p0 = application_id;
	std::string p1 = std::string(code.utf8().get_data());
	std::string p2 = std::string(code_verifier.utf8().get_data());
	std::string p3 = std::string(redirect_uri.utf8().get_data());
	discordpp::AuthenticationExternalAuthType p4 = (discordpp::AuthenticationExternalAuthType)external_auth_type;
	std::string p5 = std::string(external_auth_token.utf8().get_data());
	auto p6 = [callback](auto result, auto access_token, auto refresh_token, auto token_type, auto expires_in, auto scopes) {
		discordpp::ClientResult *p0_t = memnew(discordpp::ClientResult(std::move(result)));
		DiscordClientResult *p0 = memnew(DiscordClientResult{ p0_t });

		String p1 = String(access_token.c_str());
		String p2 = String(refresh_token.c_str());
		DiscordAuthorizationTokenType::Enum p3 = (DiscordAuthorizationTokenType::Enum)token_type;
		int64_t p4 = (int64_t)expires_in;
		String p5 = String(scopes.c_str());
	};

	obj->GetTokenFromProvisionalMerge(p0, p1, p2, p3, p4, p5, p6);
}

void DiscordClient::get_user_guilds(Callable cb) {
	auto p0 = [cb](auto result, auto guilds) {
		discordpp::ClientResult *p0_t = memnew(discordpp::ClientResult(std::move(result)));
		DiscordClientResult *p0 = memnew(DiscordClientResult{ p0_t });

		TypedArray<DiscordGuildMinimal> p1 = TypedArray<DiscordGuildMinimal>();

		for (auto i : guilds) {
			discordpp::GuildMinimal *p1_t_t = memnew(discordpp::GuildMinimal(std::move(i)));
			DiscordGuildMinimal *p1_t = memnew(DiscordGuildMinimal{ p1_t_t });

			p1.push_back(p1_t);
		}
	};

	obj->GetUserGuilds(p0);
}

void DiscordClient::get_user_message_summaries(Callable cb) {
	auto p0 = [cb](auto result, auto summaries) {
		discordpp::ClientResult *p0_t = memnew(discordpp::ClientResult(std::move(result)));
		DiscordClientResult *p0 = memnew(DiscordClientResult{ p0_t });

		TypedArray<DiscordUserMessageSummary> p1 = TypedArray<DiscordUserMessageSummary>();

		for (auto i : summaries) {
			discordpp::UserMessageSummary *p1_t_t = memnew(discordpp::UserMessageSummary(std::move(i)));
			DiscordUserMessageSummary *p1_t = memnew(DiscordUserMessageSummary{ p1_t_t });

			p1.push_back(p1_t);
		}
	};

	obj->GetUserMessageSummaries(p0);
}

void DiscordClient::get_user_messages_with_limit(int64_t recipient_id, int64_t limit, Callable cb) {
	int64_t p0 = recipient_id;
	int64_t p1 = limit;
	auto p2 = [cb](auto result, auto messages) {
		discordpp::ClientResult *p0_t = memnew(discordpp::ClientResult(std::move(result)));
		DiscordClientResult *p0 = memnew(DiscordClientResult{ p0_t });

		TypedArray<DiscordMessageHandle> p1 = TypedArray<DiscordMessageHandle>();

		for (auto i : messages) {
			discordpp::MessageHandle *p1_t_t = memnew(discordpp::MessageHandle(std::move(i)));
			DiscordMessageHandle *p1_t = memnew(DiscordMessageHandle{ p1_t_t });

			p1.push_back(p1_t);
		}
	};

	obj->GetUserMessagesWithLimit(p0, p1, p2);
}

void DiscordClient::is_discord_app_installed(Callable callback) {
	auto p0 = [callback](auto installed) {
		bool p0 = installed;
	};

	obj->IsDiscordAppInstalled(p0);
}

void DiscordClient::join_linked_lobby_guild(int64_t lobby_id, Callable provisional_user_merge_required_callback, Callable callback) {
	int64_t p0 = lobby_id;
	auto p1 = [provisional_user_merge_required_callback]() {

	};

	auto p2 = [callback](auto result, auto invite_url) {
		discordpp::ClientResult *p0_t = memnew(discordpp::ClientResult(std::move(result)));
		DiscordClientResult *p0 = memnew(DiscordClientResult{ p0_t });

		String p1 = String(invite_url.c_str());
	};

	obj->JoinLinkedLobbyGuild(p0, p1, p2);
}

void DiscordClient::leave_lobby(int64_t lobby_id, Callable callback) {
	int64_t p0 = lobby_id;
	auto p1 = [callback](auto result) {
		discordpp::ClientResult *p0_t = memnew(discordpp::ClientResult(std::move(result)));
		DiscordClientResult *p0 = memnew(DiscordClientResult{ p0_t });
	};

	obj->LeaveLobby(p0, p1);
}

void DiscordClient::link_channel_to_lobby(int64_t lobby_id, int64_t channel_id, Callable callback) {
	int64_t p0 = lobby_id;
	int64_t p1 = channel_id;
	auto p2 = [callback](auto result) {
		discordpp::ClientResult *p0_t = memnew(discordpp::ClientResult(std::move(result)));
		DiscordClientResult *p0 = memnew(DiscordClientResult{ p0_t });
	};

	obj->LinkChannelToLobby(p0, p1, p2);
}

void DiscordClient::open_authorize_device_screen(int64_t client_id, String user_code) {
	int64_t p0 = client_id;
	std::string p1 = std::string(user_code.utf8().get_data());
	obj->OpenAuthorizeDeviceScreen(p0, p1);
}

void DiscordClient::open_connected_games_settings_in_discord(Callable callback) {
	auto p0 = [callback](auto result) {
		discordpp::ClientResult *p0_t = memnew(discordpp::ClientResult(std::move(result)));
		DiscordClientResult *p0 = memnew(DiscordClientResult{ p0_t });
	};

	obj->OpenConnectedGamesSettingsInDiscord(p0);
}

void DiscordClient::open_message_in_discord(int64_t message_id, Callable provisional_user_merge_required_callback, Callable callback) {
	int64_t p0 = message_id;
	auto p1 = [provisional_user_merge_required_callback]() {

	};

	auto p2 = [callback](auto result) {
		discordpp::ClientResult *p0_t = memnew(discordpp::ClientResult(std::move(result)));
		DiscordClientResult *p0 = memnew(DiscordClientResult{ p0_t });
	};

	obj->OpenMessageInDiscord(p0, p1, p2);
}

void DiscordClient::provisional_user_merge_completed(bool success) {
	bool p0 = success;
	obj->ProvisionalUserMergeCompleted(p0);
}

void DiscordClient::refresh_token(int64_t application_id, String refresh_token, Callable callback) {
	int64_t p0 = application_id;
	std::string p1 = std::string(refresh_token.utf8().get_data());
	auto p2 = [callback](auto result, auto access_token, auto refresh_token, auto token_type, auto expires_in, auto scopes) {
		discordpp::ClientResult *p0_t = memnew(discordpp::ClientResult(std::move(result)));
		DiscordClientResult *p0 = memnew(DiscordClientResult{ p0_t });

		String p1 = String(access_token.c_str());
		String p2 = String(refresh_token.c_str());
		DiscordAuthorizationTokenType::Enum p3 = (DiscordAuthorizationTokenType::Enum)token_type;
		int64_t p4 = (int64_t)expires_in;
		String p5 = String(scopes.c_str());
	};

	obj->RefreshToken(p0, p1, p2);
}

void DiscordClient::register_authorize_request_callback(Callable callback) {
	auto p0 = [callback]() {

	};

	obj->RegisterAuthorizeRequestCallback(p0);
}

void DiscordClient::reject_discord_friend_request(int64_t user_id, Callable cb) {
	int64_t p0 = user_id;
	auto p1 = [cb](auto result) {
		discordpp::ClientResult *p0_t = memnew(discordpp::ClientResult(std::move(result)));
		DiscordClientResult *p0 = memnew(DiscordClientResult{ p0_t });
	};

	obj->RejectDiscordFriendRequest(p0, p1);
}

void DiscordClient::reject_game_friend_request(int64_t user_id, Callable cb) {
	int64_t p0 = user_id;
	auto p1 = [cb](auto result) {
		discordpp::ClientResult *p0_t = memnew(discordpp::ClientResult(std::move(result)));
		DiscordClientResult *p0 = memnew(DiscordClientResult{ p0_t });
	};

	obj->RejectGameFriendRequest(p0, p1);
}

void DiscordClient::remove_authorize_request_callback() {
	obj->RemoveAuthorizeRequestCallback();
}

void DiscordClient::remove_discord_and_game_friend(int64_t user_id, Callable cb) {
	int64_t p0 = user_id;
	auto p1 = [cb](auto result) {
		discordpp::ClientResult *p0_t = memnew(discordpp::ClientResult(std::move(result)));
		DiscordClientResult *p0 = memnew(DiscordClientResult{ p0_t });
	};

	obj->RemoveDiscordAndGameFriend(p0, p1);
}

void DiscordClient::remove_game_friend(int64_t user_id, Callable cb) {
	int64_t p0 = user_id;
	auto p1 = [cb](auto result) {
		discordpp::ClientResult *p0_t = memnew(discordpp::ClientResult(std::move(result)));
		DiscordClientResult *p0 = memnew(DiscordClientResult{ p0_t });
	};

	obj->RemoveGameFriend(p0, p1);
}

void DiscordClient::revoke_token(int64_t application_id, String token, Callable callback) {
	int64_t p0 = application_id;
	std::string p1 = std::string(token.utf8().get_data());
	auto p2 = [callback](auto result) {
		discordpp::ClientResult *p0_t = memnew(discordpp::ClientResult(std::move(result)));
		DiscordClientResult *p0 = memnew(DiscordClientResult{ p0_t });
	};

	obj->RevokeToken(p0, p1, p2);
}

void DiscordClient::send_activity_invite(int64_t user_id, String content, Callable cb) {
	int64_t p0 = user_id;
	std::string p1 = std::string(content.utf8().get_data());
	auto p2 = [cb](auto result) {
		discordpp::ClientResult *p0_t = memnew(discordpp::ClientResult(std::move(result)));
		DiscordClientResult *p0 = memnew(DiscordClientResult{ p0_t });
	};

	obj->SendActivityInvite(p0, p1, p2);
}

void DiscordClient::send_activity_join_request(int64_t user_id, Callable cb) {
	int64_t p0 = user_id;
	auto p1 = [cb](auto result) {
		discordpp::ClientResult *p0_t = memnew(discordpp::ClientResult(std::move(result)));
		DiscordClientResult *p0 = memnew(DiscordClientResult{ p0_t });
	};

	obj->SendActivityJoinRequest(p0, p1);
}

void DiscordClient::send_activity_join_request_reply(DiscordActivityInvite *invite, Callable cb) {
	discordpp::ActivityInvite p0 = *invite->unwrap();
	auto p1 = [cb](auto result) {
		discordpp::ClientResult *p0_t = memnew(discordpp::ClientResult(std::move(result)));
		DiscordClientResult *p0 = memnew(DiscordClientResult{ p0_t });
	};

	obj->SendActivityJoinRequestReply(p0, p1);
}

void DiscordClient::send_discord_friend_request(String username, Callable cb) {
	std::string p0 = std::string(username.utf8().get_data());
	auto p1 = [cb](auto result) {
		discordpp::ClientResult *p0_t = memnew(discordpp::ClientResult(std::move(result)));
		DiscordClientResult *p0 = memnew(DiscordClientResult{ p0_t });
	};

	obj->SendDiscordFriendRequest(p0, p1);
}

void DiscordClient::send_discord_friend_request_by_id(int64_t user_id, Callable cb) {
	int64_t p0 = user_id;
	auto p1 = [cb](auto result) {
		discordpp::ClientResult *p0_t = memnew(discordpp::ClientResult(std::move(result)));
		DiscordClientResult *p0 = memnew(DiscordClientResult{ p0_t });
	};

	obj->SendDiscordFriendRequestById(p0, p1);
}

void DiscordClient::send_game_friend_request(String username, Callable cb) {
	std::string p0 = std::string(username.utf8().get_data());
	auto p1 = [cb](auto result) {
		discordpp::ClientResult *p0_t = memnew(discordpp::ClientResult(std::move(result)));
		DiscordClientResult *p0 = memnew(DiscordClientResult{ p0_t });
	};

	obj->SendGameFriendRequest(p0, p1);
}

void DiscordClient::send_game_friend_request_by_id(int64_t user_id, Callable cb) {
	int64_t p0 = user_id;
	auto p1 = [cb](auto result) {
		discordpp::ClientResult *p0_t = memnew(discordpp::ClientResult(std::move(result)));
		DiscordClientResult *p0 = memnew(DiscordClientResult{ p0_t });
	};

	obj->SendGameFriendRequestById(p0, p1);
}

void DiscordClient::send_lobby_message(int64_t lobby_id, String content, Callable cb) {
	int64_t p0 = lobby_id;
	std::string p1 = std::string(content.utf8().get_data());
	auto p2 = [cb](auto result, auto message_id) {
		discordpp::ClientResult *p0_t = memnew(discordpp::ClientResult(std::move(result)));
		DiscordClientResult *p0 = memnew(DiscordClientResult{ p0_t });

		int64_t p1 = (int64_t)message_id;
	};

	obj->SendLobbyMessage(p0, p1, p2);
}

void DiscordClient::send_lobby_message_with_metadata(int64_t lobby_id, String content, TypedDictionary<String, String> metadata, Callable cb) {
	int64_t p0 = lobby_id;
	std::string p1 = std::string(content.utf8().get_data());
	std::unordered_map<std::string, std::string> p2 = std::unordered_map<std::string, std::string>();
	auto p2k = metadata.keys();

	for (int i = 0; i < p2k.size(); i++) {
		auto k = p2k[i];
		auto v = metadata[k];
		std::string kv;
		std::string vv;

		kv = k.stringify().utf8().get_data();
		vv = v.stringify().utf8().get_data();

		p2[kv] = vv;
	}

	auto p3 = [cb](auto result, auto message_id) {
		discordpp::ClientResult *p0_t = memnew(discordpp::ClientResult(std::move(result)));
		DiscordClientResult *p0 = memnew(DiscordClientResult{ p0_t });

		int64_t p1 = (int64_t)message_id;
	};

	obj->SendLobbyMessageWithMetadata(p0, p1, p2, p3);
}

void DiscordClient::send_user_message(int64_t recipient_id, String content, Callable cb) {
	int64_t p0 = recipient_id;
	std::string p1 = std::string(content.utf8().get_data());
	auto p2 = [cb](auto result, auto message_id) {
		discordpp::ClientResult *p0_t = memnew(discordpp::ClientResult(std::move(result)));
		DiscordClientResult *p0 = memnew(DiscordClientResult{ p0_t });

		int64_t p1 = (int64_t)message_id;
	};

	obj->SendUserMessage(p0, p1, p2);
}

void DiscordClient::send_user_message_with_metadata(int64_t recipient_id, String content, TypedDictionary<String, String> metadata, Callable cb) {
	int64_t p0 = recipient_id;
	std::string p1 = std::string(content.utf8().get_data());
	std::unordered_map<std::string, std::string> p2 = std::unordered_map<std::string, std::string>();
	auto p2k = metadata.keys();

	for (int i = 0; i < p2k.size(); i++) {
		auto k = p2k[i];
		auto v = metadata[k];
		std::string kv;
		std::string vv;

		kv = k.stringify().utf8().get_data();
		vv = v.stringify().utf8().get_data();

		p2[kv] = vv;
	}

	auto p3 = [cb](auto result, auto message_id) {
		discordpp::ClientResult *p0_t = memnew(discordpp::ClientResult(std::move(result)));
		DiscordClientResult *p0 = memnew(DiscordClientResult{ p0_t });

		int64_t p1 = (int64_t)message_id;
	};

	obj->SendUserMessageWithMetadata(p0, p1, p2, p3);
}

void DiscordClient::set_activity_invite_created_callback(Callable cb) {
	auto p0 = [cb](auto invite) {
		discordpp::ActivityInvite *p0_t = memnew(discordpp::ActivityInvite(std::move(invite)));
		DiscordActivityInvite *p0 = memnew(DiscordActivityInvite{ p0_t });
	};

	obj->SetActivityInviteCreatedCallback(p0);
}

void DiscordClient::set_activity_invite_updated_callback(Callable cb) {
	auto p0 = [cb](auto invite) {
		discordpp::ActivityInvite *p0_t = memnew(discordpp::ActivityInvite(std::move(invite)));
		DiscordActivityInvite *p0 = memnew(DiscordActivityInvite{ p0_t });
	};

	obj->SetActivityInviteUpdatedCallback(p0);
}

void DiscordClient::set_activity_join_callback(Callable cb) {
	auto p0 = [cb](auto join_secret) {
		String p0 = String(join_secret.c_str());
	};

	obj->SetActivityJoinCallback(p0);
}

void DiscordClient::set_activity_join_with_application_callback(Callable cb) {
	auto p0 = [cb](auto application_id, auto join_secret) {
		int64_t p0 = (int64_t)application_id;
		String p1 = String(join_secret.c_str());
	};

	obj->SetActivityJoinWithApplicationCallback(p0);
}

void DiscordClient::set_aec_dump(bool on) {
	bool p0 = on;
	obj->SetAecDump(p0);
}

void DiscordClient::set_application_id(int64_t application_id) {
	int64_t p0 = application_id;
	obj->SetApplicationId(p0);
}

void DiscordClient::set_authorize_device_screen_closed_callback(Callable cb) {
	auto p0 = [cb]() {

	};

	obj->SetAuthorizeDeviceScreenClosedCallback(p0);
}

void DiscordClient::set_automatic_gain_control(bool on) {
	bool p0 = on;
	obj->SetAutomaticGainControl(p0);
}

void DiscordClient::set_device_change_callback(Callable callback) {
	auto p0 = [callback](auto input_devices, auto output_devices) {
		TypedArray<DiscordAudioDevice> p0 = TypedArray<DiscordAudioDevice>();

		for (auto i : input_devices) {
			discordpp::AudioDevice *p0_t_t = memnew(discordpp::AudioDevice(std::move(i)));
			DiscordAudioDevice *p0_t = memnew(DiscordAudioDevice{ p0_t_t });

			p0.push_back(p0_t);
		}

		TypedArray<DiscordAudioDevice> p1 = TypedArray<DiscordAudioDevice>();

		for (auto i : output_devices) {
			discordpp::AudioDevice *p1_t_t = memnew(discordpp::AudioDevice(std::move(i)));
			DiscordAudioDevice *p1_t = memnew(DiscordAudioDevice{ p1_t_t });

			p1.push_back(p1_t);
		}
	};

	obj->SetDeviceChangeCallback(p0);
}

void DiscordClient::set_echo_cancellation(bool on) {
	bool p0 = on;
	obj->SetEchoCancellation(p0);
}

void DiscordClient::set_engine_managed_audio_session(bool is_engine_managed) {
	bool p0 = is_engine_managed;
	obj->SetEngineManagedAudioSession(p0);
}

void DiscordClient::set_game_window_pid(int64_t pid) {
	int64_t p0 = pid;
	obj->SetGameWindowPid(p0);
}

void DiscordClient::set_http_request_timeout(int64_t http_timeout_in_milliseconds) {
	int64_t p0 = http_timeout_in_milliseconds;
	obj->SetHttpRequestTimeout(p0);
}

void DiscordClient::set_input_device(String device_id, Callable cb) {
	std::string p0 = std::string(device_id.utf8().get_data());
	auto p1 = [cb](auto result) {
		discordpp::ClientResult *p0_t = memnew(discordpp::ClientResult(std::move(result)));
		DiscordClientResult *p0 = memnew(DiscordClientResult{ p0_t });
	};

	obj->SetInputDevice(p0, p1);
}

void DiscordClient::set_input_volume(float input_volume) {
	float p0 = input_volume;
	obj->SetInputVolume(p0);
}

void DiscordClient::set_lobby_created_callback(Callable cb) {
	auto p0 = [cb](auto lobby_id) {
		int64_t p0 = (int64_t)lobby_id;
	};

	obj->SetLobbyCreatedCallback(p0);
}

void DiscordClient::set_lobby_deleted_callback(Callable cb) {
	auto p0 = [cb](auto lobby_id) {
		int64_t p0 = (int64_t)lobby_id;
	};

	obj->SetLobbyDeletedCallback(p0);
}

void DiscordClient::set_lobby_member_added_callback(Callable cb) {
	auto p0 = [cb](auto lobby_id, auto member_id) {
		int64_t p0 = (int64_t)lobby_id;
		int64_t p1 = (int64_t)member_id;
	};

	obj->SetLobbyMemberAddedCallback(p0);
}

void DiscordClient::set_lobby_member_removed_callback(Callable cb) {
	auto p0 = [cb](auto lobby_id, auto member_id) {
		int64_t p0 = (int64_t)lobby_id;
		int64_t p1 = (int64_t)member_id;
	};

	obj->SetLobbyMemberRemovedCallback(p0);
}

void DiscordClient::set_lobby_member_updated_callback(Callable cb) {
	auto p0 = [cb](auto lobby_id, auto member_id) {
		int64_t p0 = (int64_t)lobby_id;
		int64_t p1 = (int64_t)member_id;
	};

	obj->SetLobbyMemberUpdatedCallback(p0);
}

void DiscordClient::set_lobby_updated_callback(Callable cb) {
	auto p0 = [cb](auto lobby_id) {
		int64_t p0 = (int64_t)lobby_id;
	};

	obj->SetLobbyUpdatedCallback(p0);
}

void DiscordClient::set_message_created_callback(Callable cb) {
	auto p0 = [cb](auto message_id) {
		int64_t p0 = (int64_t)message_id;
	};

	obj->SetMessageCreatedCallback(p0);
}

void DiscordClient::set_message_deleted_callback(Callable cb) {
	auto p0 = [cb](auto message_id, auto channel_id) {
		int64_t p0 = (int64_t)message_id;
		int64_t p1 = (int64_t)channel_id;
	};

	obj->SetMessageDeletedCallback(p0);
}

void DiscordClient::set_message_updated_callback(Callable cb) {
	auto p0 = [cb](auto message_id) {
		int64_t p0 = (int64_t)message_id;
	};

	obj->SetMessageUpdatedCallback(p0);
}

void DiscordClient::set_no_audio_input_callback(Callable callback) {
	auto p0 = [callback](auto input_detected) {
		bool p0 = input_detected;
	};

	obj->SetNoAudioInputCallback(p0);
}

void DiscordClient::set_no_audio_input_threshold(float d_bfsthreshold) {
	float p0 = d_bfsthreshold;
	obj->SetNoAudioInputThreshold(p0);
}

void DiscordClient::set_noise_suppression(bool on) {
	bool p0 = on;
	obj->SetNoiseSuppression(p0);
}

void DiscordClient::set_online_status(DiscordStatusType::Enum status, Callable callback) {
	discordpp::StatusType p0 = (discordpp::StatusType)status;
	auto p1 = [callback](auto result) {
		discordpp::ClientResult *p0_t = memnew(discordpp::ClientResult(std::move(result)));
		DiscordClientResult *p0 = memnew(DiscordClientResult{ p0_t });
	};

	obj->SetOnlineStatus(p0, p1);
}

void DiscordClient::set_opus_hardware_coding(bool encode, bool decode) {
	bool p0 = encode;
	bool p1 = decode;
	obj->SetOpusHardwareCoding(p0, p1);
}

void DiscordClient::set_output_device(String device_id, Callable cb) {
	std::string p0 = std::string(device_id.utf8().get_data());
	auto p1 = [cb](auto result) {
		discordpp::ClientResult *p0_t = memnew(discordpp::ClientResult(std::move(result)));
		DiscordClientResult *p0 = memnew(DiscordClientResult{ p0_t });
	};

	obj->SetOutputDevice(p0, p1);
}

void DiscordClient::set_output_volume(float output_volume) {
	float p0 = output_volume;
	obj->SetOutputVolume(p0);
}

void DiscordClient::set_relationship_created_callback(Callable cb) {
	auto p0 = [cb](auto user_id, auto is_discord_relationship_update) {
		int64_t p0 = (int64_t)user_id;
		bool p1 = is_discord_relationship_update;
	};

	obj->SetRelationshipCreatedCallback(p0);
}

void DiscordClient::set_relationship_deleted_callback(Callable cb) {
	auto p0 = [cb](auto user_id, auto is_discord_relationship_update) {
		int64_t p0 = (int64_t)user_id;
		bool p1 = is_discord_relationship_update;
	};

	obj->SetRelationshipDeletedCallback(p0);
}

void DiscordClient::set_relationship_groups_updated_callback(Callable cb) {
	auto p0 = [cb](auto user_id) {
		int64_t p0 = (int64_t)user_id;
	};

	obj->SetRelationshipGroupsUpdatedCallback(p0);
}

void DiscordClient::set_self_deaf_all(bool deaf) {
	bool p0 = deaf;
	obj->SetSelfDeafAll(p0);
}

void DiscordClient::set_self_mute_all(bool mute) {
	bool p0 = mute;
	obj->SetSelfMuteAll(p0);
}

void DiscordClient::set_showing_chat(bool showing_chat) {
	bool p0 = showing_chat;
	obj->SetShowingChat(p0);
}

void DiscordClient::set_status_changed_callback(Callable cb) {
	auto p0 = [cb](auto status, auto error, auto error_detail) {
		DiscordClientStatus::Enum p0 = (DiscordClientStatus::Enum)status;
		DiscordClientError::Enum p1 = (DiscordClientError::Enum)error;
		int64_t p2 = (int64_t)error_detail;
	};

	obj->SetStatusChangedCallback(p0);
}

void DiscordClient::set_thread_priority(DiscordClientThread::Enum thread, int64_t priority) {
	discordpp::Client::Thread p0 = (discordpp::Client::Thread)thread;
	int64_t p1 = priority;
	obj->SetThreadPriority(p0, p1);
}

void DiscordClient::set_token_expiration_callback(Callable callback) {
	auto p0 = [callback]() {

	};

	obj->SetTokenExpirationCallback(p0);
}

void DiscordClient::set_user_updated_callback(Callable cb) {
	auto p0 = [cb](auto user_id) {
		int64_t p0 = (int64_t)user_id;
	};

	obj->SetUserUpdatedCallback(p0);
}

void DiscordClient::set_voice_log_dir(String path, DiscordLoggingSeverity::Enum min_severity) {
	std::string p0 = std::string(path.utf8().get_data());
	discordpp::LoggingSeverity p1 = (discordpp::LoggingSeverity)min_severity;
	obj->SetVoiceLogDir(p0, p1);
}

void DiscordClient::set_voice_participant_changed_callback(Callable cb) {
	auto p0 = [cb](auto lobby_id, auto member_id, auto added) {
		int64_t p0 = (int64_t)lobby_id;
		int64_t p1 = (int64_t)member_id;
		bool p2 = added;
	};

	obj->SetVoiceParticipantChangedCallback(p0);
}

void DiscordClient::unblock_user(int64_t user_id, Callable cb) {
	int64_t p0 = user_id;
	auto p1 = [cb](auto result) {
		discordpp::ClientResult *p0_t = memnew(discordpp::ClientResult(std::move(result)));
		DiscordClientResult *p0 = memnew(DiscordClientResult{ p0_t });
	};

	obj->UnblockUser(p0, p1);
}

void DiscordClient::unlink_channel_from_lobby(int64_t lobby_id, Callable callback) {
	int64_t p0 = lobby_id;
	auto p1 = [callback](auto result) {
		discordpp::ClientResult *p0_t = memnew(discordpp::ClientResult(std::move(result)));
		DiscordClientResult *p0 = memnew(DiscordClientResult{ p0_t });
	};

	obj->UnlinkChannelFromLobby(p0, p1);
}

void DiscordClient::unmerge_into_provisional_account(int64_t application_id, DiscordAuthenticationExternalAuthType::Enum external_auth_type, String external_auth_token, Callable callback) {
	int64_t p0 = application_id;
	discordpp::AuthenticationExternalAuthType p1 = (discordpp::AuthenticationExternalAuthType)external_auth_type;
	std::string p2 = std::string(external_auth_token.utf8().get_data());
	auto p3 = [callback](auto result) {
		discordpp::ClientResult *p0_t = memnew(discordpp::ClientResult(std::move(result)));
		DiscordClientResult *p0 = memnew(DiscordClientResult{ p0_t });
	};

	obj->UnmergeIntoProvisionalAccount(p0, p1, p2, p3);
}

void DiscordClient::update_provisional_account_display_name(String name, Callable callback) {
	std::string p0 = std::string(name.utf8().get_data());
	auto p1 = [callback](auto result) {
		discordpp::ClientResult *p0_t = memnew(discordpp::ClientResult(std::move(result)));
		DiscordClientResult *p0 = memnew(DiscordClientResult{ p0_t });
	};

	obj->UpdateProvisionalAccountDisplayName(p0, p1);
}

void DiscordClient::update_rich_presence(DiscordActivity *activity, Callable cb) {
	discordpp::Activity p0 = *activity->unwrap();
	auto p1 = [cb](auto result) {
		discordpp::ClientResult *p0_t = memnew(discordpp::ClientResult(std::move(result)));
		DiscordClientResult *p0 = memnew(DiscordClientResult{ p0_t });
	};

	obj->UpdateRichPresence(p0, p1);
}

void DiscordClient::update_token(DiscordAuthorizationTokenType::Enum token_type, String token, Callable callback) {
	discordpp::AuthorizationTokenType p0 = (discordpp::AuthorizationTokenType)token_type;
	std::string p1 = std::string(token.utf8().get_data());
	auto p2 = [callback](auto result) {
		discordpp::ClientResult *p0_t = memnew(discordpp::ClientResult(std::move(result)));
		DiscordClientResult *p0 = memnew(DiscordClientResult{ p0_t });
	};

	obj->UpdateToken(p0, p1, p2);
}

// Overload functions.

// Binding.
void DiscordClient::_bind_methods() {
	ClassDB::bind_method(D_METHOD("abort_authorize"),
			&DiscordClient::abort_authorize);

	ClassDB::bind_method(D_METHOD("abort_get_token_from_device"),
			&DiscordClient::abort_get_token_from_device);

	ClassDB::bind_method(D_METHOD("accept_activity_invite", "invite", "cb"),
			&DiscordClient::accept_activity_invite);

	ClassDB::bind_method(D_METHOD("accept_discord_friend_request", "user_id", "cb"),
			&DiscordClient::accept_discord_friend_request);

	ClassDB::bind_method(D_METHOD("accept_game_friend_request", "user_id", "cb"),
			&DiscordClient::accept_game_friend_request);

	ClassDB::bind_method(D_METHOD("add_log_callback", "callback", "min_severity"),
			&DiscordClient::add_log_callback);

	ClassDB::bind_method(D_METHOD("add_voice_log_callback", "callback", "min_severity"),
			&DiscordClient::add_voice_log_callback);

	ClassDB::bind_method(D_METHOD("authorize", "args", "callback"),
			&DiscordClient::authorize);

	ClassDB::bind_method(D_METHOD("block_user", "user_id", "cb"),
			&DiscordClient::block_user);

	ClassDB::bind_method(D_METHOD("can_open_message_in_discord", "message_id"),
			&DiscordClient::can_open_message_in_discord);

	ClassDB::bind_method(D_METHOD("cancel_discord_friend_request", "user_id", "cb"),
			&DiscordClient::cancel_discord_friend_request);

	ClassDB::bind_method(D_METHOD("cancel_game_friend_request", "user_id", "cb"),
			&DiscordClient::cancel_game_friend_request);

	ClassDB::bind_method(D_METHOD("clear_rich_presence"),
			&DiscordClient::clear_rich_presence);

	ClassDB::bind_method(D_METHOD("close_authorize_device_screen"),
			&DiscordClient::close_authorize_device_screen);

	ClassDB::bind_method(D_METHOD("connect_discord"),
			&DiscordClient::connect_discord);

	ClassDB::bind_method(D_METHOD("create_authorization_code_verifier"),
			&DiscordClient::create_authorization_code_verifier);

	ClassDB::bind_method(D_METHOD("create_or_join_lobby", "secret", "callback"),
			&DiscordClient::create_or_join_lobby);

	ClassDB::bind_method(D_METHOD("create_or_join_lobby_with_metadata", "secret", "lobby_metadata", "member_metadata", "callback"),
			&DiscordClient::create_or_join_lobby_with_metadata);

	ClassDB::bind_method(D_METHOD("delete_user_message", "recipient_id", "message_id", "cb"),
			&DiscordClient::delete_user_message);

	ClassDB::bind_method(D_METHOD("disconnect_discord"),
			&DiscordClient::disconnect_discord);

	ClassDB::bind_method(D_METHOD("edit_user_message", "recipient_id", "message_id", "content", "cb"),
			&DiscordClient::edit_user_message);

	ClassDB::bind_method(D_METHOD("end_call", "channel_id", "callback"),
			&DiscordClient::end_call);

	ClassDB::bind_method(D_METHOD("end_calls", "callback"),
			&DiscordClient::end_calls);

	ClassDB::bind_method(D_METHOD("exchange_child_token", "parent_application_token", "child_application_id", "callback"),
			&DiscordClient::exchange_child_token);

	ClassDB::bind_method(D_METHOD("fetch_current_user", "token_type", "token", "callback"),
			&DiscordClient::fetch_current_user);

	ClassDB::bind_method(D_METHOD("get_application_id"),
			&DiscordClient::get_application_id);

	ClassDB::bind_method(D_METHOD("get_call", "channel_id"),
			&DiscordClient::get_call);

	ClassDB::bind_method(D_METHOD("get_calls"),
			&DiscordClient::get_calls);

	ClassDB::bind_method(D_METHOD("get_channel_handle", "channel_id"),
			&DiscordClient::get_channel_handle);

	ClassDB::bind_method(D_METHOD("get_current_input_device", "cb"),
			&DiscordClient::get_current_input_device);

	ClassDB::bind_method(D_METHOD("get_current_output_device", "cb"),
			&DiscordClient::get_current_output_device);

	ClassDB::bind_method(D_METHOD("get_current_user"),
			&DiscordClient::get_current_user);

	ClassDB::bind_method(D_METHOD("get_current_user_v2"),
			&DiscordClient::get_current_user_v2);

	ClassDB::bind_method(D_METHOD("get_discord_client_connected_user", "application_id", "callback"),
			&DiscordClient::get_discord_client_connected_user);

	ClassDB::bind_method(D_METHOD("get_guild_channels", "guild_id", "cb"),
			&DiscordClient::get_guild_channels);

	ClassDB::bind_method(D_METHOD("get_input_devices", "cb"),
			&DiscordClient::get_input_devices);

	ClassDB::bind_method(D_METHOD("get_input_volume"),
			&DiscordClient::get_input_volume);

	ClassDB::bind_method(D_METHOD("get_lobby_handle", "lobby_id"),
			&DiscordClient::get_lobby_handle);

	ClassDB::bind_method(D_METHOD("get_lobby_ids"),
			&DiscordClient::get_lobby_ids);

	ClassDB::bind_method(D_METHOD("get_lobby_messages_with_limit", "lobby_id", "limit", "cb"),
			&DiscordClient::get_lobby_messages_with_limit);

	ClassDB::bind_method(D_METHOD("get_message_handle", "message_id"),
			&DiscordClient::get_message_handle);

	ClassDB::bind_method(D_METHOD("get_output_devices", "cb"),
			&DiscordClient::get_output_devices);

	ClassDB::bind_method(D_METHOD("get_output_volume"),
			&DiscordClient::get_output_volume);

	ClassDB::bind_method(D_METHOD("get_provisional_token", "application_id", "external_auth_type", "external_auth_token", "callback"),
			&DiscordClient::get_provisional_token);

	ClassDB::bind_method(D_METHOD("get_relationship_handle", "user_id"),
			&DiscordClient::get_relationship_handle);

	ClassDB::bind_method(D_METHOD("get_relationships"),
			&DiscordClient::get_relationships);

	ClassDB::bind_method(D_METHOD("get_relationships_by_group", "group_type"),
			&DiscordClient::get_relationships_by_group);

	ClassDB::bind_method(D_METHOD("get_self_deaf_all"),
			&DiscordClient::get_self_deaf_all);

	ClassDB::bind_method(D_METHOD("get_self_mute_all"),
			&DiscordClient::get_self_mute_all);

	ClassDB::bind_method(D_METHOD("get_status"),
			&DiscordClient::get_status);

	ClassDB::bind_method(D_METHOD("get_token", "application_id", "code", "code_verifier", "redirect_uri", "callback"),
			&DiscordClient::get_token);

	ClassDB::bind_method(D_METHOD("get_token_from_device", "args", "callback"),
			&DiscordClient::get_token_from_device);

	ClassDB::bind_method(D_METHOD("get_token_from_device_provisional_merge", "args", "external_auth_type", "external_auth_token", "callback"),
			&DiscordClient::get_token_from_device_provisional_merge);

	ClassDB::bind_method(D_METHOD("get_token_from_provisional_merge", "application_id", "code", "code_verifier", "redirect_uri", "external_auth_type", "external_auth_token", "callback"),
			&DiscordClient::get_token_from_provisional_merge);

	ClassDB::bind_method(D_METHOD("get_user", "user_id"),
			&DiscordClient::get_user);

	ClassDB::bind_method(D_METHOD("get_user_guilds", "cb"),
			&DiscordClient::get_user_guilds);

	ClassDB::bind_method(D_METHOD("get_user_message_summaries", "cb"),
			&DiscordClient::get_user_message_summaries);

	ClassDB::bind_method(D_METHOD("get_user_messages_with_limit", "recipient_id", "limit", "cb"),
			&DiscordClient::get_user_messages_with_limit);

	ClassDB::bind_method(D_METHOD("is_authenticated"),
			&DiscordClient::is_authenticated);

	ClassDB::bind_method(D_METHOD("is_discord_app_installed", "callback"),
			&DiscordClient::is_discord_app_installed);

	ClassDB::bind_method(D_METHOD("join_linked_lobby_guild", "lobby_id", "provisional_user_merge_required_callback", "callback"),
			&DiscordClient::join_linked_lobby_guild);

	ClassDB::bind_method(D_METHOD("leave_lobby", "lobby_id", "callback"),
			&DiscordClient::leave_lobby);

	ClassDB::bind_method(D_METHOD("link_channel_to_lobby", "lobby_id", "channel_id", "callback"),
			&DiscordClient::link_channel_to_lobby);

	ClassDB::bind_method(D_METHOD("open_authorize_device_screen", "client_id", "user_code"),
			&DiscordClient::open_authorize_device_screen);

	ClassDB::bind_method(D_METHOD("open_connected_games_settings_in_discord", "callback"),
			&DiscordClient::open_connected_games_settings_in_discord);

	ClassDB::bind_method(D_METHOD("open_message_in_discord", "message_id", "provisional_user_merge_required_callback", "callback"),
			&DiscordClient::open_message_in_discord);

	ClassDB::bind_method(D_METHOD("provisional_user_merge_completed", "success"),
			&DiscordClient::provisional_user_merge_completed);

	ClassDB::bind_method(D_METHOD("refresh_token", "application_id", "refresh_token", "callback"),
			&DiscordClient::refresh_token);

	ClassDB::bind_method(D_METHOD("register_authorize_request_callback", "callback"),
			&DiscordClient::register_authorize_request_callback);

	ClassDB::bind_method(D_METHOD("register_launch_command", "application_id", "command"),
			&DiscordClient::register_launch_command);

	ClassDB::bind_method(D_METHOD("register_launch_steam_application", "application_id", "steam_app_id"),
			&DiscordClient::register_launch_steam_application);

	ClassDB::bind_method(D_METHOD("reject_discord_friend_request", "user_id", "cb"),
			&DiscordClient::reject_discord_friend_request);

	ClassDB::bind_method(D_METHOD("reject_game_friend_request", "user_id", "cb"),
			&DiscordClient::reject_game_friend_request);

	ClassDB::bind_method(D_METHOD("remove_authorize_request_callback"),
			&DiscordClient::remove_authorize_request_callback);

	ClassDB::bind_method(D_METHOD("remove_discord_and_game_friend", "user_id", "cb"),
			&DiscordClient::remove_discord_and_game_friend);

	ClassDB::bind_method(D_METHOD("remove_game_friend", "user_id", "cb"),
			&DiscordClient::remove_game_friend);

	ClassDB::bind_method(D_METHOD("revoke_token", "application_id", "token", "callback"),
			&DiscordClient::revoke_token);

	ClassDB::bind_method(D_METHOD("search_friends_by_username", "search_str"),
			&DiscordClient::search_friends_by_username);

	ClassDB::bind_method(D_METHOD("send_activity_invite", "user_id", "content", "cb"),
			&DiscordClient::send_activity_invite);

	ClassDB::bind_method(D_METHOD("send_activity_join_request", "user_id", "cb"),
			&DiscordClient::send_activity_join_request);

	ClassDB::bind_method(D_METHOD("send_activity_join_request_reply", "invite", "cb"),
			&DiscordClient::send_activity_join_request_reply);

	ClassDB::bind_method(D_METHOD("send_discord_friend_request", "username", "cb"),
			&DiscordClient::send_discord_friend_request);

	ClassDB::bind_method(D_METHOD("send_discord_friend_request_by_id", "user_id", "cb"),
			&DiscordClient::send_discord_friend_request_by_id);

	ClassDB::bind_method(D_METHOD("send_game_friend_request", "username", "cb"),
			&DiscordClient::send_game_friend_request);

	ClassDB::bind_method(D_METHOD("send_game_friend_request_by_id", "user_id", "cb"),
			&DiscordClient::send_game_friend_request_by_id);

	ClassDB::bind_method(D_METHOD("send_lobby_message", "lobby_id", "content", "cb"),
			&DiscordClient::send_lobby_message);

	ClassDB::bind_method(D_METHOD("send_lobby_message_with_metadata", "lobby_id", "content", "metadata", "cb"),
			&DiscordClient::send_lobby_message_with_metadata);

	ClassDB::bind_method(D_METHOD("send_user_message", "recipient_id", "content", "cb"),
			&DiscordClient::send_user_message);

	ClassDB::bind_method(D_METHOD("send_user_message_with_metadata", "recipient_id", "content", "metadata", "cb"),
			&DiscordClient::send_user_message_with_metadata);

	ClassDB::bind_method(D_METHOD("set_activity_invite_created_callback", "cb"),
			&DiscordClient::set_activity_invite_created_callback);

	ClassDB::bind_method(D_METHOD("set_activity_invite_updated_callback", "cb"),
			&DiscordClient::set_activity_invite_updated_callback);

	ClassDB::bind_method(D_METHOD("set_activity_join_callback", "cb"),
			&DiscordClient::set_activity_join_callback);

	ClassDB::bind_method(D_METHOD("set_activity_join_with_application_callback", "cb"),
			&DiscordClient::set_activity_join_with_application_callback);

	ClassDB::bind_method(D_METHOD("set_aec_dump", "on"),
			&DiscordClient::set_aec_dump);

	ClassDB::bind_method(D_METHOD("set_application_id", "application_id"),
			&DiscordClient::set_application_id);

	ClassDB::bind_method(D_METHOD("set_authorize_device_screen_closed_callback", "cb"),
			&DiscordClient::set_authorize_device_screen_closed_callback);

	ClassDB::bind_method(D_METHOD("set_automatic_gain_control", "on"),
			&DiscordClient::set_automatic_gain_control);

	ClassDB::bind_method(D_METHOD("set_device_change_callback", "callback"),
			&DiscordClient::set_device_change_callback);

	ClassDB::bind_method(D_METHOD("set_echo_cancellation", "on"),
			&DiscordClient::set_echo_cancellation);

	ClassDB::bind_method(D_METHOD("set_engine_managed_audio_session", "is_engine_managed"),
			&DiscordClient::set_engine_managed_audio_session);

	ClassDB::bind_method(D_METHOD("set_game_window_pid", "pid"),
			&DiscordClient::set_game_window_pid);

	ClassDB::bind_method(D_METHOD("set_http_request_timeout", "http_timeout_in_milliseconds"),
			&DiscordClient::set_http_request_timeout);

	ClassDB::bind_method(D_METHOD("set_input_device", "device_id", "cb"),
			&DiscordClient::set_input_device);

	ClassDB::bind_method(D_METHOD("set_input_volume", "input_volume"),
			&DiscordClient::set_input_volume);

	ClassDB::bind_method(D_METHOD("set_lobby_created_callback", "cb"),
			&DiscordClient::set_lobby_created_callback);

	ClassDB::bind_method(D_METHOD("set_lobby_deleted_callback", "cb"),
			&DiscordClient::set_lobby_deleted_callback);

	ClassDB::bind_method(D_METHOD("set_lobby_member_added_callback", "cb"),
			&DiscordClient::set_lobby_member_added_callback);

	ClassDB::bind_method(D_METHOD("set_lobby_member_removed_callback", "cb"),
			&DiscordClient::set_lobby_member_removed_callback);

	ClassDB::bind_method(D_METHOD("set_lobby_member_updated_callback", "cb"),
			&DiscordClient::set_lobby_member_updated_callback);

	ClassDB::bind_method(D_METHOD("set_lobby_updated_callback", "cb"),
			&DiscordClient::set_lobby_updated_callback);

	ClassDB::bind_method(D_METHOD("set_log_dir", "path", "min_severity"),
			&DiscordClient::set_log_dir);

	ClassDB::bind_method(D_METHOD("set_message_created_callback", "cb"),
			&DiscordClient::set_message_created_callback);

	ClassDB::bind_method(D_METHOD("set_message_deleted_callback", "cb"),
			&DiscordClient::set_message_deleted_callback);

	ClassDB::bind_method(D_METHOD("set_message_updated_callback", "cb"),
			&DiscordClient::set_message_updated_callback);

	ClassDB::bind_method(D_METHOD("set_no_audio_input_callback", "callback"),
			&DiscordClient::set_no_audio_input_callback);

	ClassDB::bind_method(D_METHOD("set_no_audio_input_threshold", "d_bfsthreshold"),
			&DiscordClient::set_no_audio_input_threshold);

	ClassDB::bind_method(D_METHOD("set_noise_suppression", "on"),
			&DiscordClient::set_noise_suppression);

	ClassDB::bind_method(D_METHOD("set_online_status", "status", "callback"),
			&DiscordClient::set_online_status);

	ClassDB::bind_method(D_METHOD("set_opus_hardware_coding", "encode", "decode"),
			&DiscordClient::set_opus_hardware_coding);

	ClassDB::bind_method(D_METHOD("set_output_device", "device_id", "cb"),
			&DiscordClient::set_output_device);

	ClassDB::bind_method(D_METHOD("set_output_volume", "output_volume"),
			&DiscordClient::set_output_volume);

	ClassDB::bind_method(D_METHOD("set_relationship_created_callback", "cb"),
			&DiscordClient::set_relationship_created_callback);

	ClassDB::bind_method(D_METHOD("set_relationship_deleted_callback", "cb"),
			&DiscordClient::set_relationship_deleted_callback);

	ClassDB::bind_method(D_METHOD("set_relationship_groups_updated_callback", "cb"),
			&DiscordClient::set_relationship_groups_updated_callback);

	ClassDB::bind_method(D_METHOD("set_self_deaf_all", "deaf"),
			&DiscordClient::set_self_deaf_all);

	ClassDB::bind_method(D_METHOD("set_self_mute_all", "mute"),
			&DiscordClient::set_self_mute_all);

	ClassDB::bind_method(D_METHOD("set_showing_chat", "showing_chat"),
			&DiscordClient::set_showing_chat);

	ClassDB::bind_method(D_METHOD("set_speaker_mode", "speaker_mode"),
			&DiscordClient::set_speaker_mode);

	ClassDB::bind_method(D_METHOD("set_status_changed_callback", "cb"),
			&DiscordClient::set_status_changed_callback);

	ClassDB::bind_method(D_METHOD("set_thread_priority", "thread", "priority"),
			&DiscordClient::set_thread_priority);

	ClassDB::bind_method(D_METHOD("set_token_expiration_callback", "callback"),
			&DiscordClient::set_token_expiration_callback);

	ClassDB::bind_method(D_METHOD("set_user_updated_callback", "cb"),
			&DiscordClient::set_user_updated_callback);

	ClassDB::bind_method(D_METHOD("set_voice_log_dir", "path", "min_severity"),
			&DiscordClient::set_voice_log_dir);

	ClassDB::bind_method(D_METHOD("set_voice_participant_changed_callback", "cb"),
			&DiscordClient::set_voice_participant_changed_callback);

	ClassDB::bind_method(D_METHOD("show_audio_route_picker"),
			&DiscordClient::show_audio_route_picker);

	ClassDB::bind_method(D_METHOD("start_call", "channel_id"),
			&DiscordClient::start_call);

	ClassDB::bind_method(D_METHOD("start_call_with_audio_callbacks", "lobby_id", "received_cb", "captured_cb"),
			&DiscordClient::start_call_with_audio_callbacks);

	ClassDB::bind_method(D_METHOD("unblock_user", "user_id", "cb"),
			&DiscordClient::unblock_user);

	ClassDB::bind_method(D_METHOD("unlink_channel_from_lobby", "lobby_id", "callback"),
			&DiscordClient::unlink_channel_from_lobby);

	ClassDB::bind_method(D_METHOD("unmerge_into_provisional_account", "application_id", "external_auth_type", "external_auth_token", "callback"),
			&DiscordClient::unmerge_into_provisional_account);

	ClassDB::bind_method(D_METHOD("update_provisional_account_display_name", "name", "callback"),
			&DiscordClient::update_provisional_account_display_name);

	ClassDB::bind_method(D_METHOD("update_rich_presence", "activity", "cb"),
			&DiscordClient::update_rich_presence);

	ClassDB::bind_method(D_METHOD("update_token", "token_type", "token", "callback"),
			&DiscordClient::update_token);

	ClassDB::bind_static_method("DiscordClient", D_METHOD("error_to_string", "type"),
			&DiscordClient::error_to_string);

	ClassDB::bind_static_method("DiscordClient", D_METHOD("get_default_audio_device_id"),
			&DiscordClient::get_default_audio_device_id);

	ClassDB::bind_static_method("DiscordClient", D_METHOD("get_default_communication_scopes"),
			&DiscordClient::get_default_communication_scopes);

	ClassDB::bind_static_method("DiscordClient", D_METHOD("get_default_presence_scopes"),
			&DiscordClient::get_default_presence_scopes);

	ClassDB::bind_static_method("DiscordClient", D_METHOD("get_version_hash"),
			&DiscordClient::get_version_hash);

	ClassDB::bind_static_method("DiscordClient", D_METHOD("get_version_major"),
			&DiscordClient::get_version_major);

	ClassDB::bind_static_method("DiscordClient", D_METHOD("get_version_minor"),
			&DiscordClient::get_version_minor);

	ClassDB::bind_static_method("DiscordClient", D_METHOD("get_version_patch"),
			&DiscordClient::get_version_patch);

	ClassDB::bind_static_method("DiscordClient", D_METHOD("status_to_string", "type"),
			&DiscordClient::status_to_string);

	ClassDB::bind_static_method("DiscordClient", D_METHOD("thread_to_string", "type"),
			&DiscordClient::thread_to_string);
}
