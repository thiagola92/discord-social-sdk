extends Control


# ATTENTION: Replace DotEnv.read_int("APPLICATION_ID") with your application ID.
# This only exist so I don't accidentally use my ID.
var APPLICATION_ID: int = DotEnv.read_int("APPLICATION_ID")

var client := DiscordppClient.new()


func _ready() -> void:
	# Create a code verifier and challenge if using GetToken
	var code_verifier := client.CreateAuthorizationCodeVerifier()
	var args = DiscordppAuthorizationArgs.new()
	args.SetClientId(APPLICATION_ID)
	args.SetScopes(DiscordppClient.GetDefaultPresenceScopes())
	args.SetCodeChallenge(code_verifier.Challenge())
	
	client.Authorize(
		args,
		func(
			result: DiscordppClientResult,
			code: String,
			redirectUri: String
		):
			if not result.Successful():
				print("❌ Authorization Error: %s" % result.Error())
			else:
				print("✅ Authorization successful! Next step: exchange code for an access token")
				
				client.GetToken(
					APPLICATION_ID,
					code,
					code_verifier.Verifier(),
					redirectUri,
					func(
						_result: DiscordppClientResult,
						accessToken: String,
						_refreshToken: String,
						_tokenType: DiscordppAuthorizationTokenType.Enum,
						_expiresIn: int,
						_scopes: String
					):
						print("🔓 Access token received! Establishing connection...")
						
						client.UpdateToken(
							DiscordppAuthorizationTokenType.Bearer,
							accessToken,
							func(_result: DiscordppClientResult):
								client.Connect()
						)
				)
	)


func _process(_delta: float) -> void:
	Discordpp.RunCallbacks()
