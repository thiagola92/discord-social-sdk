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
	
	args.set_scopes(DiscordClient.get_default_presence_scopes())
	args.set_code_challenge(code_verifier.challenge())
	
	client.set_application_id(application_id)
	client.add_log_callback(_on_log, DiscordLoggingSeverity.INFO)
	client.register_launch_command(application_id, "yourgame://")
	client.set_activity_join_callback(_on_joined_activity)
	client.set_status_changed_callback(_on_status_changed)
	client.authorize(args, _on_authorization_response)


func _process(_delta: float) -> void:
	Discord.run_callbacks()


func _on_log(message: String, severity: DiscordLoggingSeverity.Enum) -> void:
	var enum_str: String = Discord.enum_to_string(severity, DiscordLoggingSeverity.id)
	
	print("[%s] %s" % [enum_str, message])


func _on_joined_activity(join_secret: String) -> void:
	print("User joined with secret: %s" % join_secret)


func _on_status_changed(status: DiscordClientStatus.Enum, _error: DiscordClientError.Enum, _error_detail: int) -> void:
	var enum_str: String = Discord.enum_to_string(status, DiscordClientStatus.id)
	
	print("Status changed to %s" % enum_str)
	
	if status == DiscordClientStatus.READY:
		var activity := DiscordActivity.new()
		activity.set_type(DiscordActivityTypes.PLAYING)
		activity.set_details("Learning to Use")
		activity.set_state("In Godot")
		
		var timestamps := DiscordActivityTimestamps.new()
		timestamps.set_start(0)
		activity.set_timestamps(timestamps)
		
		var party := DiscordActivityParty.new()
		party.set_id("party1234")
		party.set_current_size(1)
		party.set_max_size(5)
		activity.set_party(party)
		
		var secrets := DiscordActivitySecrets.new()
		secrets.set_join("your-join-secret")
		activity.set_secrets(secrets)
		
		activity.set_supported_platforms(DiscordActivityGamePlatforms.DESKTOP)
		
		client.update_rich_presence(activity, _on_rich_presence_updated)
		
		var invite_message = "Join my game!"
		
		client.send_activity_invite(target_id, invite_message, _on_activity_invite_sent)


func _on_rich_presence_updated(result: DiscordClientResult) -> void:
	if result.successful():
		print("✅ Rich presence updated!")


func _on_activity_invite_sent(result: DiscordClientResult) -> void:
	if result.successful():
		print("✉️ Invite sent!")


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
