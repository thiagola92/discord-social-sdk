extends Control


const APPLICATION_ID = 1349146942634065960

var client := DiscordppClient.new()

var code_verifier := client.CreateAuthorizationCodeVerifier()

var args = DiscordppAuthorizationArgs.new()


func _ready() -> void:
	args.SetClientId(APPLICATION_ID)
	args.SetScopes(DiscordppClient.GetDefaultPresenceScopes())
	args.SetCodeChallenge(code_verifier.Challenge())
	client.Authorize(args, _on_authorize)


func _process(_delta: float) -> void:
	Discordpp.RunCallbacks()


func _on_authorize(result: DiscordppClientResult, code: String, redirect_uri: String) -> void:
	if not result.Successful():
		print("❌ Authorization Error: %s" % result.Error())
	else:
		print("✅ Authorization successful! Next step: exchange code for an access token")
		client.GetToken(APPLICATION_ID, code, code_verifier.Verifier(), redirect_uri, _on_get_token)


func _on_get_token(
	result: DiscordppClientResult,
	access_token: String,
	refresh_token: String,
	token_type: DiscordppAuthorizationTokenType.Enum,
	expires_in: int,
	scopes: String
) -> void:
	print("🔓 Access token received! Establishing connection...")
	client.UpdateToken(DiscordppAuthorizationTokenType.Bearer, access_token, _on_update_token)


func _on_update_token(result: DiscordppClientResult) -> void:
	client.Connect()
