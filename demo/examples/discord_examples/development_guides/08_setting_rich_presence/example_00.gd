extends Control


# ATTENTION: Replace DotEnv.read_int("APPLICATION_ID") with your application ID.
# This only exist so I don't accidentally use my ID.
var APPLICATION_ID: int = DotEnv.read_int("APPLICATION_ID")

var client := DiscordClient.new()


func _ready() -> void:
	var code_verifier := client.CreateAuthorizationCodeVerifier()
	var args = DiscordAuthorizationArgs.new()
	args.SetClientId(APPLICATION_ID)
	args.SetScopes(DiscordClient.GetDefaultPresenceScopes())
	args.SetCodeChallenge(code_verifier.Challenge())
	
	client.SetStatusChangedCallback(
		func(
			status: DiscordClientStatus.Enum,
			error: DiscordClientError.Enum,
			errorDetail: int
		):
			print("🔄 Status changed: %s" % DiscordClient.StatusToString(status))
			
			if status == DiscordClientStatus.Ready:
				print("✅ Client is ready! You can now call SDK functions.")
				print("👥 Friends Count: %s" % client.GetRelationships().size())
				
				update_presence()
			elif error != DiscordClientError.None:
				print("❌ Connection Error: %s - Details: %s" % [
					DiscordClient.ErrorToString(error), errorDetail
				])
	)
	
	client.Authorize(
		args,
		func(result: DiscordClientResult, code: String, redirectUri: String):
			if not result.Successful():
				print("❌ Authorization Error: %s" % result.Error())
				return
			
			client.GetToken(
				APPLICATION_ID,
				code,
				code_verifier.Verifier(),
				redirectUri,
				func(
					result: DiscordClientResult,
					accessToken: String,
					_refreshToken: String,
					_tokenType: DiscordAuthorizationTokenType.Enum,
					_expiresIn: int,
					_scopes: String
				):
					if not result.Successful():
						print("❌ Get Token Error: %s" % result.Error())
						return
					
					client.UpdateToken(
						DiscordAuthorizationTokenType.Bearer,
						accessToken,
						func(result: DiscordClientResult):
							if not result.Successful():
								print("❌ Update Token Error: %s" % result.Error())
								return
							
							client.Connect()
					)
			)
	)


func _process(_delta: float) -> void:
	Discord.RunCallbacks()


func update_presence() -> void:
	# Create a new activity
	var activity := DiscordActivity.new()
	activity.SetType(DiscordActivityTypes.Playing);
	activity.SetDetails("Battle Creek");
	activity.SetState("In Competitive Match");
	
	# Update the presence
	client.UpdateRichPresence(
		activity,
		func(result: DiscordClientResult):
			if result.Successful():
				print("✅ Rich presence updated!")
	)
	
	# Setting Timestamps
	var timestamps := DiscordActivityTimestamps.new();
	timestamps.SetStart(int(Time.get_unix_time_from_system()));
	# timestamps.SetEnd(int(Time.get_unix_time_from_system()) + 3600);
	activity.SetTimestamps(timestamps);
