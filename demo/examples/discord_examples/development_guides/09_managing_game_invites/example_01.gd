extends Control


# ATTENTION: Replace DotEnv.read_int("APPLICATION_ID") with your application ID.
# This only exist so I don't accidentally git push my ID.
var APPLICATION_ID: int = DotEnv.read_int("APPLICATION_ID")


var client := DiscordClient.new()
var args := DiscordAuthorizationArgs.new()
var code_verifier: DiscordAuthorizationCodeVerifier = null


func _ready() -> void:
	code_verifier = client.create_authorization_code_verifier()
	
	args.set_client_id(APPLICATION_ID)
	args.set_scopes(DiscordClient.get_default_presence_scopes())
	args.set_code_challenge(code_verifier.challenge())
	
	if not client.register_launch_command(APPLICATION_ID, "~/.local/bin/godot"):
		print("Failed to register your command")
		return
	
	client.add_log_callback(_on_log_message, DiscordLoggingSeverity.INFO)
	client.set_status_changed_callback(_on_status_changed)
	client.authorize(args, _on_authorization_result)


func _process(_delta: float) -> void:
	Discord.run_callbacks()


func _on_log_message(message: String, severity: DiscordLoggingSeverity.Enum) -> void:
	print("[%s] %s" % [Discord.enum_to_string(severity, DiscordLoggingSeverity.id), message])


func _on_status_changed(status: DiscordClientStatus.Enum, error: DiscordClientError.Enum, error_detail: int) -> void:
	if error != DiscordClientError.NONE:
		print("❌ Connection Error: %s - Details: %s" % [error, error_detail])
		return
	
	if status != DiscordClientStatus.READY:
		return
		
	var activity := DiscordActivity.new()
	
	activity.set_type(DiscordActivityTypes.PLAYING)
	activity.set_state("In Competitive Match")
	activity.set_details("Valhalla")
	
	var party := DiscordActivityParty.new()
	
	party.set_id("party1234")
	party.set_current_size(1)
	party.set_max_size(5)
	activity.set_party(party)
	
	var secrets := DiscordActivitySecrets.new();
	
	secrets.set_join("joinsecret1234")
	activity.set_secrets(secrets)
	activity.set_supported_platforms(DiscordActivityGamePlatforms.DESKTOP)
	
	client.update_rich_presence(activity, _on_rich_presence_updated)
	
	# ATTENTION: Replace DotEnv.read_int("TARGET_ID") with your target ID.
	# This only exist so I don't accidentally git push my ID.
	var target_user_id := DotEnv.read_int("TARGET_ID")
	var invite_message := "Join my game!"
	
	client.send_activity_invite(target_user_id, invite_message, _on_activity_invite_sent)


func _on_activity_invite_sent(result: DiscordClientResult) -> void:
	if result.successful():
		print("Activity Invite sent to user")
	else:
		print("Failed - check if Rich Presence has party, secret, and platforms set")


func _on_rich_presence_updated(result: DiscordClientResult) -> void:
	if result.successful():
		print("✅ Rich presence updated!")
	else:
		print("❌ Rich Presence update failed")


func _on_authorization_result(result: DiscordClientResult, code: String, redirect_uri: String) -> void:
	if not result.successful():
		print("❌ Authorization Error: %s" % result.error())
		return
	
	client.get_token(APPLICATION_ID, code, code_verifier.verifier(), redirect_uri, _on_token_received)


func _on_token_received(
	result: DiscordClientResult,
	access_token: String,
	_refresh_token: String,
	_token_type: DiscordAuthorizationTokenType.Enum,
	_expires_in: int,
	_scopes: String
) -> void:
	if not result.successful():
		print("❌ Get Token Error: %s" % result.error())
		return
		
	client.update_token(DiscordAuthorizationTokenType.BEARER, access_token, _on_token_updated)


func _on_token_updated(result: DiscordClientResult) -> void:
	if not result.successful():
		print("❌ Update Token Error: %s" % result.error())
		return
	
	client.connect_discord()
