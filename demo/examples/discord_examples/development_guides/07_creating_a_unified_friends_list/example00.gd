extends Control


# ATTENTION: Replace DotEnv.read_int("APPLICATION_ID") with your application ID.
# This only exist so I don't accidentally use my ID.
var APPLICATION_ID: int = DotEnv.read_int("APPLICATION_ID")

var client := DiscordClient.new()
var args := DiscordAuthorizationArgs.new()
var code_verifier: DiscordAuthorizationCodeVerifier = null


func _ready() -> void:
	code_verifier = client.create_authorization_code_verifier()
	
	args.set_client_id(APPLICATION_ID)
	args.set_scopes(DiscordClient.get_default_presence_scopes())
	args.set_code_challenge(code_verifier.challenge())
	
	client.set_status_changed_callback(
		func(
			status: DiscordClientStatus.Enum,
			error: DiscordClientError.Enum,
			error_detail: int
		):
			print("🔄 Status changed: %s" % DiscordClient.status_to_string(status))
			
			if status == DiscordClientStatus.READY:
				print("✅ Client is ready! You can now call SDK functions.")
				print("👥 Friends Count: %s" % client.get_relationships().size())
				
				display_friends_list()
				display_friends_list2()
			elif error != DiscordClientError.NONE:
				print("❌ Connection Error: %s - Details: %s" % [
					DiscordClient.error_to_string(error), error_detail
				])
	)
	
	client.set_user_updated_callback(
		func(user_id: int):
			print("👤 User updated: %s" % user_id)
			display_friends_list2()
	)
	
	client.set_relationship_created_callback(
		func(user_id: int, _is_discord_relationship_update: bool):
			var user = client.get_user(user_id)
			
			if user != null:
				user = user as DiscordUserHandle
				print("🤝 Relationship created: %s" % user.display_name())
				display_friends_list2()
	)
	
	client.set_relationship_deleted_callback(
		func(user_id: int, _is_discord_relationship_update: bool):
			print("🔥 Relationship deleted: %s" % user_id)
			display_friends_list2()
	)
	
	client.Authorize(
		args,
		func(result: DiscordClientResult, code: String, redirect_uri: String):
			if not result.successful():
				print("❌ Authorization Error: %s" % result.error())
				return
			
			client.get_token(
				APPLICATION_ID,
				code,
				code_verifier.verifier(),
				redirect_uri,
				func(
					result: DiscordClientResult,
					access_token: String,
					_refresh_token: String,
					_token_type: DiscordAuthorizationTokenType.Enum,
					_expires_in: int,
					_scopes: String
				):
					if not result.successful():
						print("❌ Get Token Error: %s" % result.error())
						return
					
					client.update_token(
						DiscordAuthorizationTokenType.BEARER,
						access_token,
						func(result: DiscordClientResult):
							if not result.successful():
								print("❌ Update Token Error: %s" % result.error())
								return
							
							client.connect_discord()
					)
			)
	)


func _process(_delta: float) -> void:
	Discord.run_callbacks()


func display_friends_list() -> void:
	var relationships: Array[String] = []
	
	for relationship in client.get_relationships():
		var user = relationship.user()
		
		if user == null:
			continue
		
		user = user as DiscordUserHandle
		
		var string: String = ""
		
		# Identifying information about the user:
		string += " DiscordName: %s" % user.display_name()
		string += " DiscordId: %s" % user.id()
		
		# Provisional users don't have a Discord icon shown next to them:
		string += " IsProvisional: %s" % user.is_provisional()
		
		# Whether the relationship is for a friend, a friend request, or because the user is blocked:
		# For a friends list you'll want to filter out blocked users
		# And likely display friend requests in a different section
		string += " DiscordRelationshipType: %s" % Discord.enum_to_string(relationship.discord_relationship_type(), DiscordRelationshipType.id)
		string += " GameRelationshipType: %s" % Discord.enum_to_string(relationship.game_relationship_type(),  DiscordRelationshipType.id)
		
		# Whether the user is online/offline/etc:
		string += " IsOnlineAnywhere: %s" % (user.status() != DiscordStatusType.OFFLINE)
		string += " IsOnlineInGame: %s" % (user.game_activity() != null)
		
		relationships.push_back(string)
	
	relationships.sort()
	
	for string in relationships:
		print(string)


func display_friends_list2() -> void:
	var in_game: Array[String] = []
	var online: Array[String] = []
	var offline: Array[String] = []
	
	for relationship in client.get_relationships():
		var user = relationship.user()
		
		if user == null:
			continue
		
		user = user as DiscordUserHandle
		
		if relationship.discord_relationship_type() != DiscordRelationshipType.FRIEND:
			continue
		
		var string: String = ""
		string += user.display_name()
		
		# Add Discord friend indicator
		# In a real game, please use the official Discord logo available in our design guidelines
		if relationship.discord_relationship_type() == DiscordRelationshipType.FRIEND:
			string += " 👾"
		
		# Add game friend indicator
		if relationship.game_relationship_type() == DiscordRelationshipType.FRIEND:
			string += " 🎮"
		
		# Add provisional indicator
		if user.is_provisional():
			string += " (Provisional)"
		
		# Categorize based on status
		if user.game_activity():
			in_game.append("🟣 " + string)
		if user.status() != DiscordStatusType.OFFLINE:
			online.append("🟢 " + string)
		else:
			offline.append("⚫ " + string)
		
		in_game.sort()
		online.sort()
		offline.sort()
		
	# Display "Online - GameTitle" Friends
	print("\n=== Online - GameTitle (%s) ===" % in_game.size())
	for s in in_game:
		print(s)
	
	# Display "Online - Elsewhere" Friends
	print("\n=== Online - Elsewhere (%s) ===" % online.size())
	for s in online:
		print(s)
	
	# Display "Offline" Friends
	print("\n=== Offline (%s) ===" % offline.size())
	for s in offline:
		print(s)
