extends Control


# ATTENTION: Replace DotEnv.read_int("APPLICATION_ID") with your application ID.
# This only exist so I don't accidentally use my ID.
var APPLICATION_ID: int = DotEnv.read_int("APPLICATION_ID")

#var client := DiscordClient.new()
#
#var lobby_id: int = 0
#
#
#func _ready() -> void:
	## Create a code verifier and challenge if using GetToken
	#var code_verifier := client.CreateAuthorizationCodeVerifier()
	#var args = DiscordAuthorizationArgs.new()
	#args.SetClientId(APPLICATION_ID)
	#args.SetScopes(DiscordClient.GetDefaultCommunicationScopes())
	#args.SetCodeChallenge(code_verifier.Challenge())
	#
	#client.SetMessageCreatedCallback(
		#func(messageId: int):
			#var message = client.GetMessageHandle(messageId)
			#
			#if message == null:
				#return
			#
			#message = message as DiscordMessageHandle
			#
			#print("📨 New message received: %s" % message.Content())
	#)
	#
	#client.SetStatusChangedCallback(
		#func(
			#status: DiscordClientStatus.Enum,
			#error: DiscordClientError.Enum,
			#errorDetail: int
		#):
			#if status == DiscordClientStatus.Ready:
				#create_or_join_lobby()
			#elif error != DiscordClientError.None:
				#print("❌ Connection Error: %s - Details: %s" % [
					#DiscordClient.ErrorToString(error), errorDetail
				#])
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
#func create_or_join_lobby() -> void:
	#client.CreateOrJoinLobby(
		#"your-unique-lobby-secret",
		#func(result: DiscordClientResult, lobbyId: int):
			#if result.Successful():
				#print("🎮 Lobby created or joined successfully! Lobby Id: %s" % lobbyId)
				#
				#lobby_id = lobbyId
				#
				#message_lobby()
			#else:
				#print("❌ Lobby creation/join failed")
			#
	#)
#
#
#func message_lobby() -> void:
	#client.SendLobbyMessage(
		#lobby_id,
		#"Hello",
		#func(result: DiscordClientResult, messageId: int):
			#if result.Successful():
				#print("📨 Message sent successfully!")
				#
				#await get_tree().create_timer(10).timeout
				#leave_lobby()
			#else:
				#print("❌ Message sending failed")
	#)
#
#
#func leave_lobby() -> void:
	#if lobby_id == 0:
		#return
	#
	#client.LeaveLobby(
		#lobby_id,
		#func(result: DiscordClientResult):
			#if result.Successful():
				#print("🎮 Left lobby successfully! Lobby Id: %s" % lobby_id)
			#else:
				#print("❌ Leaving lobby failed")
	#)
#
#
#func _process(_delta: float) -> void:
	#Discord.RunCallbacks()
