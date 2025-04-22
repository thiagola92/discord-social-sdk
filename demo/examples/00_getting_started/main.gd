extends Control


# Replace with your Discord Application ID
var APPLICATION_ID = DotEnv.read_int("APPLICATION_ID")

# Create our Discord Client
var client := DiscordppClient.new()

func _ready() -> void:
	print("🚀 Initializing Discord SDK...")
	
	client.AddLogCallback(
		func(message: String, severity: DiscordppLoggingSeverity.Enum):
			print("[%s] %s" % [
				severity, message
			]),
			DiscordppLoggingSeverity.Info
	)
	
	client.SetStatusChangedCallback(
		func(status: DiscordppClientStatus.Enum, error: DiscordppClientError.Enum, errorDetail: int):
			print("🔄 Status changed: %s" % status)
			
			if status == DiscordppClientStatus.Ready:
				print("✅ Client is ready! You can now call SDK functions.")
			elif error != DiscordppClientError.None:
				print("❌ Connection Error: %s - Details: %s" % [
					error, errorDetail
				])
	)
	
	var code_verifier = client.CreateAuthorizationCodeVerifier()
	
	var args := DiscordppAuthorizationArgs.new()
	args.SetClientId(APPLICATION_ID)
	args.SetScopes(DiscordppClient.GetDefaultPresenceScopes())
	args.SetCodeChallenge(code_verifier.Challenge())
	
	client.Authorize(args,
		func(result: DiscordppClientResult, code: String, redirectUri: String):
			print(result)
			print(code)
			print(redirectUri)
	)


func _process(_delta: float) -> void:
	Discordpp.RunCallbacks()
