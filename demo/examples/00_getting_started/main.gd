extends Control


# ATTENTION: Replace DotEnv.read_int("APPLICATION_ID") with your application ID.
# This only exist so I don't accidentally use my ID.
var APPLICATION_ID: int = DotEnv.read_int("APPLICATION_ID")

var client := DiscordppClient.new()


func _ready() -> void:
	print("🚀 Initializing Discord SDK...")
	
	client.AddLogCallback(
		func(message: String, severity: DiscordppLoggingSeverity.Enum):
			print("[%s] %s" % [Discordpp.EnumToStringLoggingSeverity(severity), message]),
		DiscordppLoggingSeverity.Info
	)
	
	client.SetStatusChangedCallback(
		func(status: DiscordppClientStatus.Enum, error: DiscordppClientError.Enum, errorDetail: int):
			print("🔄 Status changed: %s" % status)
			
			if status == DiscordppClientStatus.Ready:
				print("✅ Client is ready! You can now call SDK functions.")
				print("👥 Friends Count: %s" % client.GetRelationships().size())
				
				var activity := DiscordppActivity.new()
				activity.SetType(DiscordppActivityTypes.Playing)
				activity.SetState("In Competitive Match")
				activity.SetDetails("Rank: Diamond II")
				
				client.UpdateRichPresence(activity,
					func(result: DiscordppClientResult):
						if result.Successful():
							print("🎮 Rich Presence updated successfully!")
						else:
							print("❌ Rich Presence update failed")
				)
				
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
				
				client.GetToken(APPLICATION_ID, code, code_verifier.Verifier(), redirectUri,
					func(
						result: DiscordppClientResult,
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
							func(result: DiscordppClientResult):
								if result.Successful():
									print("🔑 Token updated, connecting to Discord...")
									
									client.Connect()
						)
				)
	)


func _process(_delta: float) -> void:
	Discordpp.RunCallbacks()
