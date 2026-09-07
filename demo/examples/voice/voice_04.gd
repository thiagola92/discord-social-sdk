extends Node


# ATTENTION: Replace DotEnv.read_int("APPLICATION_ID") with your application ID.
# This only exist so I don't accidentally git push my ID.
var application_id: int = DotEnv.read_int("APPLICATION_ID")

# ATTENTION: Replace DotEnv.read_int("TARGET_ID") with the target ID.
# This only exist so I don't accidentally git push the target ID.
var target_id: int = DotEnv.read_int("TARGET_ID")

var client := DiscordClient.new()

var code_verifier: DiscordAuthorizationCodeVerifier


func _ready() -> void:
	var args := DiscordAuthorizationArgs.new()
	code_verifier = client.create_authorization_code_verifier()
	
	args.set_scopes(DiscordClient.get_default_communication_scopes())
	args.set_code_challenge(code_verifier.challenge())
	
	client.set_application_id(application_id)
	client.add_log_callback(_on_log, DiscordLoggingSeverity.INFO)
	client.authorize(args, _on_authorization_response)
	client.get_voice_settings(_on_voice_settings)
	client.set_voice_settings_updated_callback(_on_voice_settings_updated)


func _process(_delta: float) -> void:
	Discord.run_callbacks()


func _on_log(message: String, severity: DiscordLoggingSeverity.Enum) -> void:
	var enum_str: String = Discord.enum_to_string(severity, DiscordLoggingSeverity.id)
	
	print("[%s] %s" % [enum_str, message])


func _on_authorization_response(result: DiscordClientResult, code: String, redirect_uri: String) -> void:
	if not result.successful():
		print("❌ Authorization Error: %s" % result.error())
		return
	
	print("✅ Authorization successful! Next step: exchange code for an access token")
	client.get_token(application_id, code, code_verifier.verifier(), redirect_uri, _on_token_received)


func _on_token_received(
	result: DiscordClientResult,
	access_token: String,
	_refresh_token: String,
	token_type: DiscordAuthorizationTokenType.Enum,
	_expires_in: int,
	_scopes: String
) -> void:
	if not result.successful():
		print("❌ Token Error: %s" % result.error())
		return
	
	print("🔓 Access token received! Establishing connection...")
	client.update_token(token_type, access_token, _on_token_updated)


func _on_token_updated(result: DiscordClientResult) -> void:
	if not result.successful():
		print("❌ Token Update Error: %s" % result.error())
		return
	
	print("🔑 Token updated, connecting to Discord...")
	client.connect_discord()


func _on_voice_settings(result: DiscordClientResult, settings: DiscordVoiceSettings) -> void:
	if not result.successful():
		print("❌ Failed to fetch voice settings: %s" % result.error())
		return

	print("Self mute: %s" % settings.self_mute())
	print("Self deaf: %s" % settings.self_deaf())
	print("Input volume: %s" % settings.input_volume()) # 0-100
	print("Output volume: %s" % settings.output_volume()) # 0-200

	# input_mode() is either DiscordVoiceInputModeType.VOICE_ACTIVITY or
	# DiscordVoiceInputModeType.PUSH_TO_TALK
	if settings.input_mode() == DiscordVoiceInputModeType.PUSH_TO_TALK:
		# ptt_key() is a display string, e.g. "SHIFT + F", empty if unbound
		print("Push-to-talk key: %s" % settings.ptt_key())


func _on_voice_settings_updated(settings: DiscordVoiceSettings) -> void:
	print("🔄 Voice settings updated - self mute: %s" % settings.self_mute())
