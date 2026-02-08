extends Control


# ATTENTION: Replace DotEnv.read_int("APPLICATION_ID") with your application ID.
# This only exist so I don't accidentally git push my ID.
var APPLICATION_ID: int = DotEnv.read_int("APPLICATION_ID")

var client := DiscordClient.new()
var args := DiscordAuthorizationArgs.new()
var code_verifier: DiscordAuthorizationCodeVerifier = null


func _ready() -> void:
	code_verifier = client.create_authorization_code_verifier()
	
	args.set_client_id(APPLICATION_ID)
	args.set_scopes(DiscordClient.get_default_presence_scopes())
	args.set_code_challenge(code_verifier.challenge())
	
	client.add_log_callback(_on_log_message, DiscordLoggingSeverity.INFO)
	client.set_relationship_groups_updated_callback(_on_relationship_groups_updated)
	client.authorize(args, _on_authorization_result)


func _process(_delta: float) -> void:
	Discord.run_callbacks()


func _on_log_message(message: String, severity: DiscordLoggingSeverity.Enum) -> void:
	print("[%s] %s" % [Discord.enum_to_string(severity, DiscordLoggingSeverity.id), message])


func display_unified_friends_list() -> void:
	var online_in_game := client.get_relationships_by_group(DiscordRelationshipGroupType.ONLINE_PLAYING_GAME)
	var online_elsewhere := client.get_relationships_by_group(DiscordRelationshipGroupType.ONLINE_ELSEWHERE)
	var offline := client.get_relationships_by_group(DiscordRelationshipGroupType.OFFLINE)
	
	print("=== Online - GameTitle (%s) ===" % online_in_game.size())
	for relationship in online_in_game:
		var user := relationship.user() as DiscordUserHandle
		
		if user != null:
			var display_str = "🟣 %s" % user.display_name()
			
			if relationship.discord_relationship_type() == DiscordRelationshipType.FRIEND:
				display_str += " 👾"
			
			if relationship.game_relationship_type() == DiscordRelationshipType.FRIEND:
				display_str += " 🎮"
			
			print(display_str)
	
	print("=== Online - Elsewhere (%s) ===" % online_elsewhere.size())
	for relationship in online_elsewhere:
		var user := relationship.user() as DiscordUserHandle
		
		if user != null:
			var display_str = "🟢 %s" % user.display_name()
			
			if relationship.discord_relationship_type() == DiscordRelationshipType.FRIEND:
				display_str += " 👾"
			
			if relationship.game_relationship_type() == DiscordRelationshipType.FRIEND:
				display_str += " 🎮"
			
			print(display_str)
	
	print("=== Offline (%s) ===" % offline.size())
	for relationship in offline:
		var user := relationship.user() as DiscordUserHandle
		
		if user != null:
			var display_str = "⚫ %s" % user.display_name()
			
			if relationship.discord_relationship_type() == DiscordRelationshipType.FRIEND:
				display_str += " 👾"
			
			if relationship.game_relationship_type() == DiscordRelationshipType.FRIEND:
				display_str += " 🎮"
			
			print(display_str)


func _on_relationship_groups_updated(user_id: int) -> void:
	print("👥 Friends list updated for user: %s" % user_id)
	display_unified_friends_list()


func _on_authorization_result(result: DiscordClientResult, code: String, redirect_uri: String) -> void:
	if not result.successful():
		print("❌ Authorization Error: %s" % result.error())
		return
	
	client.get_token(APPLICATION_ID, code, code_verifier.verifier(), redirect_uri, _on_token_received)


func _on_token_received(
	result: DiscordClientResult,
	access_token: String,
	_refresh_token: String,
	_token_type: DiscordAuthorizationTokenType.Enum,
	_expires_in: int,
	_scopes: String
) -> void:
	if not result.successful():
		print("❌ Get Token Error: %s" % result.error())
		return
		
	client.update_token(DiscordAuthorizationTokenType.BEARER, access_token, _on_token_updated)


func _on_token_updated(result: DiscordClientResult) -> void:
	if not result.successful():
		print("❌ Update Token Error: %s" % result.error())
		return
	
	client.connect_discord()
	display_unified_friends_list()
