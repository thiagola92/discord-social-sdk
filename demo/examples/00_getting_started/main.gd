extends Control


# ATTENTION: Replace DotEnv.read_int("APPLICATION_ID") with your application ID.
# This only exist so I don't accidentally use my ID.
var APPLICATION_ID: int = DotEnv.read_int("APPLICATION_ID")

var client := DiscordClient.new()
var args := DiscordAuthorizationArgs.new()
var code_verifier: DiscordAuthorizationCodeVerifier = null


func _ready() -> void:
	print("🚀 Initializing Discord SDK...")
	
	client.add_log_callback(_on_log, DiscordLoggingSeverity.INFO)
	client.set_status_changed_callback(_on_status_changed)
	
	code_verifier = client.create_authorization_code_verifier()
	
	args.set_client_id(APPLICATION_ID)
	args.set_scopes(DiscordClient.get_default_presence_scopes())
	args.set_code_challenge(code_verifier.challenge())
	client.authorize(args, _on_authorized)

func _process(_delta: float) -> void:
	Discord.run_callbacks()

func _on_log(message: String, severity: DiscordLoggingSeverity.Enum) -> void:
	print("[%s] %s" % [Discord.enum_to_string(severity, DiscordLoggingSeverity.id), message])

func _on_status_changed(status: DiscordClientStatus.Enum, error: DiscordClientError.Enum, error_detail: int) -> void:
	print("🔄 Status changed: %s" % status)
	
	if status == DiscordClientStatus.READY:
		print("✅ Client is ready! You can now call SDK functions.")
		print("👥 Friends Count: %s" % client.get_relationships().size())
		
		var activity := DiscordActivity.new()
		activity.set_type(DiscordActivityTypes.PLAYING)
		activity.set_state("In Competitive Match")
		activity.set_details("Rank: Diamond II")
		
		client.update_rich_presence(activity, _on_rich_presence_updated)
	elif error != DiscordClientError.NONE:
		print("❌ Connection Error: %s - Details: %s" % [error, error_detail])

func _on_rich_presence_updated(result: DiscordClientResult) -> void:
	if result.successful():
		print("🎮 Rich Presence updated successfully!")
	else:
		print("❌ Rich Presence update failed")

func _on_authorized(result: DiscordClientResult, code: String, redirect_uri: String) -> void:
	if not result.successful():
		print("❌ Authentication Error: %s" % result.error())
	else:
		print("✅ Authorization successful! Getting access token...")
		
		client.get_token(APPLICATION_ID, code, code_verifier.verifier(), redirect_uri, _on_token_received)

func _on_token_received(
		_result: DiscordClientResult,
		access_token: String,
		_refresh_token: String,
		_token_type: DiscordAuthorizationTokenType.Enum,
		_expires_in: int,
		_scopes: String
) -> void:
	print("🔓 Access token received! Establishing connection...")
	
	client.update_token(DiscordAuthorizationTokenType.BEARER, access_token, _on_token_updated)

func _on_token_updated(result: DiscordClientResult) -> void:
	if result.successful():
		print("🔑 Token updated, connecting to Discord...")
		
		client.connect_discord()
