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
	
	client.add_log_callback(_on_log_message, DiscordLoggingSeverity.INFO)
	client.set_status_changed_callback(_on_status_changed)
	client.authorize(args, _on_authorization_result)


func _process(_delta: float) -> void:
	Discord.run_callbacks()


func _on_log_message(message: String, severity: DiscordLoggingSeverity.Enum) -> void:
	print("[%s] %s" % [Discord.enum_to_string(severity, DiscordLoggingSeverity.id), message])


func display_friends_list() -> void:
	var relationships: Array[String] = []
	
	for relationship in client.get_relationships():
		var user = relationship.user() as DiscordUserHandle
		
		if user == null:
			continue
		
		var string: String = ""
		
		string += " DiscordName: %s\n" % user.display_name()
		string += " DiscordId: %s\n" % user.id()
		string += " IsProvisional: %s\n" % user.is_provisional()
		string += " DiscordRelationshipType: %s\n" % Discord.enum_to_string(relationship.discord_relationship_type(), DiscordRelationshipType.id)
		string += " GameRelationshipType: %s\n" % Discord.enum_to_string(relationship.game_relationship_type(),  DiscordRelationshipType.id)
		string += " IsOnlineAnywhere: %s\n" % (user.status() != DiscordStatusType.OFFLINE)
		string += " IsOnlineInGame: %s\n" % (user.game_activity() != null)
		
		relationships.push_back(string)
	
	relationships.sort()
	
	for string in relationships:
		print(string)


func _on_status_changed(
	status: DiscordClientStatus.Enum,
	error: DiscordClientError.Enum,
	error_detail: int
) -> void:
	print("🔄 Status changed: %s" % DiscordClient.status_to_string(status))
	
	if status == DiscordClientStatus.READY:
		print("✅ Client is ready! You can now call SDK functions.")
		print("👥 Friends Count: %s" % client.get_relationships().size())
		
		display_friends_list()
	elif error != DiscordClientError.NONE:
		print("❌ Connection Error: %s - Details: %s" % [
			DiscordClient.error_to_string(error), error_detail
		])


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
	display_friends_list()
