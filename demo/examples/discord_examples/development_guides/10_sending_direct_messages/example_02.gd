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
	
	client.get_user_message_summaries(_on_user_message_summaries)


func _on_user_message_summaries(result: DiscordClientResult, summaries: Array[DiscordUserMessageSummary]) -> void:
	if result.successful():
		print("📋 Retrieved %s conversations" % summaries.size())
		
		for summary in summaries:
			print("User ID: %s, Last Message ID: %s" % [summary.user_id(), summary.last_message_id()])
	else:
		print("❌ Failed to retrieve conversation summaries")


func _on_authorization_result(result: DiscordClientResult, code: String, redirect_uri: String) -> void:
	if not result.successful():
		print("❌ Authorization Error: %s" % result.error())
	else:
		print("✅ Authorization successful! Next step: exchange code for an access token")
		
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


func _on_token_updated(_result: DiscordClientResult) -> void:
	client.connect_discord()
