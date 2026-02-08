extends Control


# ATTENTION: Replace DotEnv.read_int("APPLICATION_ID") with your application ID.
# This only exist so I don't accidentally use my ID.
var APPLICATION_ID: int = DotEnv.read_int("APPLICATION_ID")

#var client := DiscordClient.new()
#
#
#func _ready() -> void:
	## Create a code verifier and challenge if using GetToken
	#var code_verifier := client.CreateAuthorizationCodeVerifier()
	#var args = DiscordAuthorizationArgs.new()
	#args.SetClientId(APPLICATION_ID)
	#args.SetScopes(DiscordClient.GetDefaultPresenceScopes())
	#args.SetCodeChallenge(code_verifier.Challenge())
	#
	#client.SetStatusChangedCallback(
		#func(
			#status: DiscordClientStatus.Enum,
			#error: DiscordClientError.Enum,
			#errorDetail: int
		#):
			#print("🔄 Status changed: %s" % DiscordClient.StatusToString(status))
			#
			#if status == DiscordClientStatus.Ready:
				#print("✅ Client is ready! You can now call SDK functions.")
				#print("👥 Friends Count: %s" % client.GetRelationships().size())
				#
				#update_presence()
			#elif error != DiscordClientError.None:
				#print("❌ Connection Error: %s - Details: %s" % [
					#DiscordClient.ErrorToString(error), errorDetail
				#])
	#)
	#
	#client.SetActivityInviteCreatedCallback(
		#func(invite: DiscordActivityInvite):
			#print("Activity Invite received from user: %s" % invite.SenderId())
			#
			#var message = client.GetMessageHandle(invite.MessageId())
			#
			#if message:
				#message = message as DiscordMessageHandle
				#print("Invite Message: %s" % message.Content())
			#
			#client.AcceptActivityInvite(
				#invite,
				#func(result: DiscordClientResult, joinSecret: String):
					#if result.Successful():
						#print("Activity Invite accepted successfully!")
					#else:
						#print("❌ Activity Invite accept failed")
			#)
	#)
	#
	#client.SetActivityJoinCallback(
		#func(joinSecret: String):
			#pass # Use the joinSecret to connect the players in your game
	#)
	#
	#client.Authorize(
		#args,
		#func(result: DiscordClientResult, code: String, redirectUri: String):
			#if not result.Successful():
				#print("❌ Authorization Error: %s" % result.Error())
				#return
			#
			#client.GetToken(
				#APPLICATION_ID,
				#code,
				#code_verifier.Verifier(),
				#redirectUri,
				#func(
					#result: DiscordClientResult,
					#accessToken: String,
					#_refreshToken: String,
					#_tokenType: DiscordAuthorizationTokenType.Enum,
					#_expiresIn: int,
					#_scopes: String
				#):
					#if not result.Successful():
						#print("❌ Get Token Error: %s" % result.Error())
						#return
					#
					#client.UpdateToken(
						#DiscordAuthorizationTokenType.Bearer,
						#accessToken,
						#func(result: DiscordClientResult):
							#if not result.Successful():
								#print("❌ Update Token Error: %s" % result.Error())
								#return
							#
							#client.Connect()
					#)
			#)
	#)
#
#
#func _process(_delta: float) -> void:
	#Discord.RunCallbacks()
#
#
#func update_presence() -> void:
	## Create DiscordActivity
	#var activity := DiscordActivity.new()
	#activity.SetType(DiscordActivityTypes.Playing);
	#
	## Set the game state and details
	#activity.SetState("In Competitive Match");
	#activity.SetDetails("Valhalla");
	#
	## Set the party information
	## Create DiscordActivityParty
	#var party := DiscordActivityParty.new()
	#party.SetId("party1234")
	#party.SetCurrentSize(1) # current party size
	#party.SetMaxSize(5) # max party size
	#activity.SetParty(party)
	#
	## Create DiscordActivitySecrets
	#var secrets := DiscordActivitySecrets.new()
	#secrets.SetJoin("joinsecret1234")
	#activity.SetSecrets(secrets)
	#
	## Set supported platforms that can join the game
	## See DiscordActivityGamePlatforms for available platforms
	#activity.SetSupportedPlatforms(DiscordActivityGamePlatforms.Desktop)
	#
	## Update Rich Presence presence
	#client.UpdateRichPresence(
		#activity,
		#func(result: DiscordClientResult):
			#if result.Successful():
				#print("🎮 Rich Presence updated successfully!")
				#
				#_send_game_invite()
			#else:
				#print("❌ Rich Presence update failed")
	#)
#
#
#func _send_game_invite() -> void:
	#var targetUserId = 1111785262289277050
	#var inviteMessage = "Join my game!"
	#client.SendActivityInvite(
		#targetUserId,
		#inviteMessage,
		#func(result: DiscordClientResult):
			#print("Activity Invite sent to user")
	#)
