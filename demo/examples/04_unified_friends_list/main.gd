extends Control


# ATTENTION: Replace DotEnv.read_int("APPLICATION_ID") with your application ID.
# This only exist so I don't accidentally use my ID.
var APPLICATION_ID: int = DotEnv.read_int("APPLICATION_ID")

#var client := DiscordClient.new()
#
#
#func _ready() -> void:
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
				#display_friends_list()
				#display_friends_list2()
			#elif error != DiscordClientError.None:
				#print("❌ Connection Error: %s - Details: %s" % [
					#DiscordClient.ErrorToString(error), errorDetail
				#])
	#)
	#
	#client.SetUserUpdatedCallback(
		#func(userId: int):
			#print("👤 User updated: %s" % userId)
			#display_friends_list2()
	#)
	#
	#client.SetRelationshipCreatedCallback(
		#func(userId: int, _isDiscordRelationshipUpdate: bool):
			#var user = client.GetUser(userId)
			#
			#if user != null:
				#user = user as DiscordUserHandle
				#print("🤝 Relationship created: %s" % user.DisplayName())
				#display_friends_list2()
	#)
	#
	#client.SetRelationshipDeletedCallback(
		#func(userId: int, _isDiscordRelationshipUpdate: bool):
			#print("🔥 Relationship deleted: %s" % userId)
			#display_friends_list2()
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
#func display_friends_list() -> void:
	#var relationships: Array[String] = []
	#
	#for relationship in client.GetRelationships():
		#var user = relationship.User()
		#
		#if user == null:
			#continue
		#
		#user = user as DiscordUserHandle
		#
		#var string: String = ""
		#
		## Identifying information about the user:
		#string += " DiscordName: %s" % user.DisplayName()
		#string += " DiscordId: %s" % user.Id()
		#
		## Provisional users don't have a Discord icon shown next to them:
		#string += " IsProvisional: %s" % user.IsProvisional()
		#
		## Whether the relationship is for a friend, a friend request, or because the user is blocked:
		## For a friends list you'll want to filter out blocked users
		## And likely display friend requests in a different section
		#string += " DiscordRelationshipType: %s" % Discord.EnumToStringRelationshipType(relationship.DiscordRelationshipType())
		#string += " GameRelationshipType: %s" % Discord.EnumToStringRelationshipType(relationship.GameRelationshipType())
		#
		## Whether the user is online/offline/etc:
		#string += " IsOnlineAnywhere: %s" % (user.Status() != DiscordStatusType.Offline)
		#string += " IsOnlineInGame: %s" % (user.GameActivity() != null)
		#
		#relationships.push_back(string)
	#
	#relationships.sort()
	#
	#for string in relationships:
		#print(string)
#
#
#func display_friends_list2() -> void:
	#var in_game: Array[String] = []
	#var online: Array[String] = []
	#var offline: Array[String] = []
	#
	#for relationship in client.GetRelationships():
		#var user = relationship.User()
		#
		#if user == null:
			#continue
		#
		#user = user as DiscordUserHandle
		#
		#if relationship.DiscordRelationshipType() != DiscordRelationshipType.Friend:
			#continue
		#
		#var string: String = ""
		#string += user.DisplayName()
		#
		## Add Discord friend indicator
		## In a real game, please use the official Discord logo available in our design guidelines
		#if relationship.DiscordRelationshipType() == DiscordRelationshipType.Friend:
			#string += " 👾"
		#
		## Add game friend indicator
		#if relationship.GameRelationshipType() == DiscordRelationshipType.Friend:
			#string += " 🎮"
		#
		## Add provisional indicator
		#if user.IsProvisional():
			#string += " (Provisional)"
		#
		## Categorize based on status
		#if user.GameActivity():
			#in_game.append("🟣 " + string)
		#if user.Status() != DiscordStatusType.Offline:
			#online.append("🟢 " + string)
		#else:
			#offline.append("⚫ " + string)
		#
		#in_game.sort()
		#online.sort()
		#offline.sort()
		#
	## Display "Online - GameTitle" Friends
	#print("\n=== Online - GameTitle (%s) ===" % in_game.size())
	#for s in in_game:
		#print(s)
	#
	## Display "Online - Elsewhere" Friends
	#print("\n=== Online - Elsewhere (%s) ===" % online.size())
	#for s in online:
		#print(s)
	#
	## Display "Offline" Friends
	#print("\n=== Offline (%s) ===" % offline.size())
	#for s in offline:
		#print(s)
