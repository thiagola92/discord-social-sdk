extends Control


# ATTENTION: Replace DotEnv.read_int("APPLICATION_ID") with your application ID.
# This only exist so I don't accidentally use my ID.
var APPLICATION_ID: int = DotEnv.read_int("APPLICATION_ID")

var client := DiscordClient.new()
var args := DiscordAuthorizationArgs.new()
var code_verifier: DiscordAuthorizationCodeVerifier = null


func _ready() -> void:
	code_verifier = client.create_authorization_code_verifier()
	
	args.set_client_id(APPLICATION_ID)
	args.set_scopes(DiscordClient.get_default_presence_scopes())
	args.set_code_challenge(code_verifier.challenge())
	
	client.authorize(args, _on_authorized)


func _process(_delta: float) -> void:
	Discord.run_callbacks()


func _on_authorized(result: DiscordClientResult, code: String, redirect_uri: String) -> void:
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
