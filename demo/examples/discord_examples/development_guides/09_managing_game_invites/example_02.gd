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
	client.set_activity_invite_created_callback(_on_activity_invite_created)
	client.set_activity_join_callback(_on_activity_joined)
	client.authorize(args, _on_authorization_result)


func _process(_delta: float) -> void:
	Discord.run_callbacks()


func _on_log_message(message: String, severity: DiscordLoggingSeverity.Enum) -> void:
	print("[%s] %s" % [Discord.enum_to_string(severity, DiscordLoggingSeverity.id), message])


func _on_activity_invite_created(invite: DiscordActivityInvite) -> void:
	print("Activity Invite received from user: %s" % invite.sender_id())
	
	var message := client.get_message_handle(invite.message_id()) as DiscordMessageHandle
	
	if message:
		print("Invite Message: %s" % message.content())
	
	client.accept_activity_invite(invite, _on_invite_accepted)


func _on_invite_accepted(result: DiscordClientResult, _join_secret: String) -> void:
	if result.successful():
		print("Activity Invite accepted successfully!")
	else:
		print("❌ Activity Invite accept failed")


func _on_activity_joined(_join_secret: String) -> void:
	print('User manually clicked "join" in an Activity')


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
