extends Control


# ATTENTION: Replace DotEnv.read_int("APPLICATION_ID") with your application ID.
# This only exist so I don't accidentally use my ID.
var APPLICATION_ID: int = DotEnv.read_int("APPLICATION_ID")

var client := DiscordppClient.new()


func _ready() -> void:
	var code_verifier := client.CreateAuthorizationCodeVerifier()
	var args = DiscordppAuthorizationArgs.new()
	args.SetClientId(APPLICATION_ID)
	args.SetScopes(DiscordppClient.GetDefaultPresenceScopes())
	args.SetCodeChallenge(code_verifier.Challenge())
	
	client.SetStatusChangedCallback(
		func(
			status: DiscordppClientStatus.Enum,
			error: DiscordppClientError.Enum,
			errorDetail: int
		):
			print("🔄 Status changed: %s" % DiscordppClient.StatusToString(status))
			
			if status == DiscordppClientStatus.Ready:
				print("✅ Client is ready! You can now call SDK functions.")
				print("👥 Friends Count: %s" % client.GetRelationships().size())
				
				update_presence()
			elif error != DiscordppClientError.None:
				print("❌ Connection Error: %s - Details: %s" % [
					DiscordppClient.ErrorToString(error), errorDetail
				])
	)
	
	client.Authorize(
		args,
		func(result: DiscordppClientResult, code: String, redirectUri: String):
			if not result.Successful():
				print("❌ Authorization Error: %s" % result.Error())
				return
			
			client.GetToken(
				APPLICATION_ID,
				code,
				code_verifier.Verifier(),
				redirectUri,
				func(
					result: DiscordppClientResult,
					accessToken: String,
					_refreshToken: String,
					_tokenType: DiscordppAuthorizationTokenType.Enum,
					_expiresIn: int,
					_scopes: String
				):
					if not result.Successful():
						print("❌ Get Token Error: %s" % result.Error())
						return
					
					client.UpdateToken(
						DiscordppAuthorizationTokenType.Bearer,
						accessToken,
						func(result: DiscordppClientResult):
							if not result.Successful():
								print("❌ Update Token Error: %s" % result.Error())
								return
							
							client.Connect()
					)
			)
	)


func _process(_delta: float) -> void:
	Discordpp.RunCallbacks()


func update_presence() -> void:
	# Create a new activity
	var activity := DiscordppActivity.new()
	activity.SetType(DiscordppActivityTypes.Playing);
	activity.SetDetails("Battle Creek");
	activity.SetState("In Competitive Match");
	
	# Update the presence
	client.UpdateRichPresence(
		activity,
		func(result: DiscordppClientResult):
			if result.Successful():
				print("✅ Rich presence updated!")
	)
	
	# Setting Timestamps
	var timestamps := DiscordppActivityTimestamps.new();
	timestamps.SetStart(int(Time.get_unix_time_from_system()));
	# timestamps.SetEnd(int(Time.get_unix_time_from_system()) + 3600);
	activity.SetTimestamps(timestamps);
