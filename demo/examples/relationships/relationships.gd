extends Node


# ATTENTION: Replace DotEnv.read_int("APPLICATION_ID") with your application ID.
# This only exist so I don't accidentally git push my ID.
var application_id: int = DotEnv.read_int("APPLICATION_ID")

var client := DiscordClient.new()

var code_verifier: DiscordAuthorizationCodeVerifier


func _ready() -> void:
	var args := DiscordAuthorizationArgs.new()
	code_verifier = client.create_authorization_code_verifier()
	
	args.set_scopes(DiscordClient.get_default_presence_scopes())
	args.set_code_challenge(code_verifier.challenge())
	
	client.set_application_id(application_id)
	client.add_log_callback(_on_log, DiscordLoggingSeverity.INFO)
	client.set_status_changed_callback(_on_status_changed)
	client.set_relationship_groups_updated_callback(_on_relationship_updated)
	client.authorize(args, _on_authorization_response)


func _process(_delta: float) -> void:
	Discord.run_callbacks()


func _on_log(message: String, severity: DiscordLoggingSeverity.Enum) -> void:
	var enum_str: String = Discord.enum_to_string(severity, DiscordLoggingSeverity.id)
	
	print("[%s] %s" % [enum_str, message])


func _on_status_changed(status: DiscordClientStatus.Enum, _error: DiscordClientError.Enum, _error_detail: int) -> void:
	var enum_str: String = Discord.enum_to_string(status, DiscordClientStatus.id)
	
	print("Status changed to %s" % enum_str)
	
	if status == DiscordClientStatus.READY:
		_on_status_ready()


func _on_authorization_response(result: DiscordClientResult, code: String, redirect_uri: String) -> void:
	if not result.successful():
		print("❌ Authorization Error: %s" % result.error())
		return
	
	print("✅ Authorization successful! Next step: exchange code for an access token")
	client.get_token(application_id, code, code_verifier.verifier(), redirect_uri, _on_token_received)


func _on_token_received(
	result: DiscordClientResult,
	access_token: String,
	_refresh_token: String,
	token_type: DiscordAuthorizationTokenType.Enum,
	_expires_in: int,
	_scopes: String
) -> void:
	if not result.successful():
		print("❌ Token Error: %s" % result.error())
		return
	
	print("🔓 Access token received! Establishing connection...")
	client.update_token(token_type, access_token, _on_token_updated)


func _on_token_updated(result: DiscordClientResult) -> void:
	if not result.successful():
		print("❌ Token Update Error: %s" % result.error())
		return
	
	print("🔑 Token updated, connecting to Discord...")
	client.connect_discord()


func _on_status_ready() -> void:
	var online_in_game: Array[DiscordRelationshipHandle] = client.get_relationships_by_group(
		DiscordRelationshipGroupType.ONLINE_PLAYING_GAME
	)
	
	print("=== Online - In Game (%s)" % online_in_game.size())
	
	for relationship in online_in_game:
		var user = relationship.user()
		
		if user is DiscordUserHandle:
			var display_str := "🟣 %s" % user.display_name()
			
			if relationship.discord_relationship_type() == DiscordRelationshipType.FRIEND:
				display_str += " 👾"
			
			if relationship.game_relationship_type() == DiscordRelationshipType.FRIEND:
				display_str += " 🎮"
			
			print(display_str)
	
	var online_elsewhere: Array[DiscordRelationshipHandle] = client.get_relationships_by_group(
		DiscordRelationshipGroupType.ONLINE_ELSEWHERE
	)
	
	print("=== Online - Elsewhere (%s)" % online_elsewhere.size())
	
	for relationship in online_elsewhere:
		var user = relationship.user()
		
		if user is DiscordUserHandle:
			var display_str := "🟢 %s" % user.display_name()
			
			if relationship.discord_relationship_type() == DiscordRelationshipType.FRIEND:
				display_str += " 👾"
			
			if relationship.game_relationship_type() == DiscordRelationshipType.FRIEND:
				display_str += " 🎮"
			
			print(display_str)
	
	var offline: Array[DiscordRelationshipHandle] = client.get_relationships_by_group(
		DiscordRelationshipGroupType.OFFLINE
	)
	
	print("=== Offline (%s)" % offline.size())
	
	for relationship in offline:
		var user = relationship.user()
		
		if user is DiscordUserHandle:
			var display_str := "⚫ %s" % user.display_name()
			
			if relationship.discord_relationship_type() == DiscordRelationshipType.FRIEND:
				display_str += " 👾"
			
			if relationship.game_relationship_type() == DiscordRelationshipType.FRIEND:
				display_str += " 🎮"
			
			print(display_str)


func _on_relationship_updated(user_id: int) -> void:
	var user = client.get_user(user_id)
	
	if user is DiscordUserHandle:
		var display_str := "User %s status changed to" % user.display_name()
		var relationship: DiscordRelationshipHandle = user.relationship()
		
		if user.status() == DiscordStatusType.OFFLINE:
			display_str += " ⚫"
		elif user.game_activity() == null:
			display_str += " 🟢"
		elif user.game_activity() != null:
			display_str += " 🟣"
		
		if relationship.discord_relationship_type() == DiscordRelationshipType.FRIEND:
			display_str += " 👾"
		
		if relationship.game_relationship_type() == DiscordRelationshipType.FRIEND:
			display_str += " 🎮"
		
		print(display_str)
