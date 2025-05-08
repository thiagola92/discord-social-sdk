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
	
	client.SetActivityInviteCreatedCallback(
		func(invite: DiscordppActivityInvite):
			print("Activity Invite received from user: %s" % invite.SenderId())
			
			var message = client.GetMessageHandle(invite.MessageId())
			
			if message:
				message = message as DiscordppMessageHandle
				print("Invite Message: %s" % message.Content())
			
			client.AcceptActivityInvite(
				invite,
				func(result: DiscordppClientResult, joinSecret: String):
					if result.Successful():
						print("Activity Invite accepted successfully!")
					else:
						print("❌ Activity Invite accept failed")
			)
	)
	
	client.SetActivityJoinCallback(
		func(joinSecret: String):
			pass # Use the joinSecret to connect the players in your game
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
	# Create DiscordppActivity
	var activity := DiscordppActivity.new()
	activity.SetType(DiscordppActivityTypes.Playing);
	
	# Set the game state and details
	activity.SetState("In Competitive Match");
	activity.SetDetails("Valhalla");
	
	# Set the party information
	# Create DiscordppActivityParty
	var party := DiscordppActivityParty.new()
	party.SetId("party1234")
	party.SetCurrentSize(1) # current party size
	party.SetMaxSize(5) # max party size
	activity.SetParty(party)
	
	# Create DiscordppActivitySecrets
	var secrets := DiscordppActivitySecrets.new()
	secrets.SetJoin("joinsecret1234")
	activity.SetSecrets(secrets)
	
	# Set supported platforms that can join the game
	# See DiscordppActivityGamePlatforms for available platforms
	activity.SetSupportedPlatforms(DiscordppActivityGamePlatforms.Desktop)
	
	# Update Rich Presence presence
	client.UpdateRichPresence(
		activity,
		func(result: DiscordppClientResult):
			if result.Successful():
				print("🎮 Rich Presence updated successfully!")
				
				_send_game_invite()
			else:
				print("❌ Rich Presence update failed")
	)


func _send_game_invite() -> void:
	var targetUserId = 1111785262289277050
	var inviteMessage = "Join my game!"
	client.SendActivityInvite(
		targetUserId,
		inviteMessage,
		func(result: DiscordppClientResult):
			print("Activity Invite sent to user")
	)
