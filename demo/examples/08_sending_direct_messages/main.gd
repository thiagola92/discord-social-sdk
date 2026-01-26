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
				
				send_message()
			elif error != DiscordppClientError.None:
				print("❌ Connection Error: %s - Details: %s" % [
					DiscordppClient.ErrorToString(error), errorDetail
				])
	)
	
	client.SetMessageCreatedCallback(
		func(messageId: int):
			var message = client.GetMessageHandle(messageId)
			
			if message != null:
				print("New message from %s: %s" % [message.AuthorId(), message.Content()])
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


func send_message() -> void:
	var message := "ready to queue?"
	
	# ATTENTION: Replace DotEnv.read_int("USER_ID") with the target user ID.
	# This only exist so I don't accidentally use my ID.
	var recipientId := DotEnv.read_int("USER_ID")
	
	client.SendUserMessage(
		recipientId,
		message,
		func(result: DiscordppClientResult, _messageId: int):
			if result.Successful():
				print("✅ Message sent successfully")
			else:
				print("❌ Failed to send message: %s" % result.Error())
	)
