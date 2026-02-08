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
	activity.set_details("Battle Creek")
	activity.set_state("In Competitive Match")
	
	client.update_rich_presence(activity, _on_rich_presence_updated)

	var timestamps := DiscordActivityTimestamps.new()
	
	timestamps.set_start(int(Time.get_unix_time_from_system()))
	# timestamps.SetEnd(int(Time.get_unix_time_from_system()) + 3600)
	activity.set_timestamps(timestamps)
	
	# TODO: Included the others examples from:
	# https://discord.com/developers/docs/discord-social-sdk/development-guides/setting-rich-presence#setting-field-urls


func _on_rich_presence_updated(result: DiscordClientResult) -> void:
	if result.successful():
		print("✅ Rich presence updated!")


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
