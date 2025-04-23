extends Control


# Replace with your Discord Application ID
var APPLICATION_ID = DotEnv.read_int("APPLICATION_ID")

# Create our Discord Client
var client := DiscordppClient.new()

func _ready() -> void:
	print("🚀 Initializing Discord SDK...")
	
	client.AddLogCallback(
		func(message: String, severity: DiscordppLoggingSeverity.Enum):
			print("[%s] %s" % [severity, message]),
			DiscordppLoggingSeverity.Info
	)
	
	client.SetStatusChangedCallback(
		func(status: DiscordppClientStatus.Enum, error: DiscordppClientError.Enum, errorDetail: int):
			print("🔄 Status changed: %s" % status)
			
			if status == DiscordppClientStatus.Ready:
				print("✅ Client is ready! You can now call SDK functions.")
			elif error != DiscordppClientError.None:
				print("❌ Connection Error: %s - Details: %s" % [error, errorDetail])
	)
	
	var code_verifier = client.CreateAuthorizationCodeVerifier()
	
	var args := DiscordppAuthorizationArgs.new()
	args.SetClientId(APPLICATION_ID)
	args.SetScopes(DiscordppClient.GetDefaultPresenceScopes())
	args.SetCodeChallenge(code_verifier.Challenge())
	
	client.Authorize(args,
		func(result: DiscordppClientResult, code: String, redirectUri: String):
			if not result.Successful():
				print("❌ Authentication Error: %s" % result.Error())
			else:
				print("✅ Authorization successful! Getting access token...")
				
				print(">>>> CODE:", code, "<<<<")
				client.GetToken(APPLICATION_ID, code, code_verifier.Verifier(), redirectUri,
					func(result: DiscordppClientResult, accessToken: String, refreshToken: String, tokenType: DiscordppAuthorizationTokenType.Enum, expiresIn: int, scopes: String):
						print("🔓 Access token received! Establishing connection...")
						
						print(">>>> RESULT:", result.Successful(), "<<<<")
						print(">>>> ACCESS_TOKEN:", accessToken, "<<<<")
						client.UpdateToken(DiscordppAuthorizationTokenType.Bearer, accessToken,
							func(result: DiscordppClientResult):
								if result.Successful():
									print("🔑 Token updated, connecting to Discord...")
									client.Connect()
						)
				)
	)


func _process(_delta: float) -> void:
	Discordpp.RunCallbacks()
