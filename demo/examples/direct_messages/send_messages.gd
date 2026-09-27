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
	client.set_status_changed_callback(_on_status_changed)
	client.authorize(args, _on_authorization_response)


func _process(_delta: float) -> void:
	Discord.run_callbacks()


func _on_log(message: String, severity: DiscordLoggingSeverity.Enum) -> void:
	var enum_str: String = Discord.enum_to_string(severity, DiscordLoggingSeverity.id)
	
	print("[%s] %s" % [enum_str, message])


func _on_status_changed(status: DiscordClientStatus.Enum, _error: DiscordClientError.Enum, _error_detail: int) -> void:
	var enum_str: String = Discord.enum_to_string(status, DiscordClientStatus.id)
	
	print("Status changed to %s" % enum_str)
	
	if status == DiscordClientStatus.READY:
		var message := "ready to queue?"
		
		client.send_user_message(target_id, message, _on_message_sent)


func _on_message_sent(result: DiscordClientResult, message_id: int) -> void:
	if result.successful():
		print("✅ Message sent successfully (message id: %s)" % message_id)
	else:
		print("❌ Failed to send message: %s" % result.error())


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
