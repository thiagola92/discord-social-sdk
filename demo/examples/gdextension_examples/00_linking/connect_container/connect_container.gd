extends HBoxContainer

var args := DiscordAuthorizationArgs.new()
var code_verifier: DiscordAuthorizationCodeVerifier = null


func setup(client: DiscordClient) -> void:
	%Connect.pressed.connect(_on_connect_pressed.bind(client))


func _on_connect_pressed(client: DiscordClient) -> void:
	var text: String = %ApplicationID.text
	
	if not text.is_valid_int():
		%Warning.text = "Not a valid Application ID"
		return
	else:
		%Warning.text = ""
	
	var application_id := int(text)
	code_verifier = client.create_authorization_code_verifier()
	
	args.set_client_id(application_id)
	
	if %Scope.get_selected_id() == 0:
		args.set_scopes(DiscordClient.get_default_presence_scopes())
	else:
		args.set_scopes(DiscordClient.get_default_communication_scopes())
	
	args.set_code_challenge(code_verifier.challenge())
	client.authorize(args, _on_authorization_result.bind(client, application_id))
	
	%Warning.text = "Waiting user authorization..."


func _on_authorization_result(
	result: DiscordClientResult,
	code: String,
	redirect_uri: String,
	client: DiscordClient,
	application_id: int
) -> void:
	if not result.successful():
		%Warning.text = "Authorization Error: %s" % result.error()
		return
	
	client.get_token(
		application_id,
		code,
		code_verifier.verifier(),
		redirect_uri,
		_on_token_result.bind(client)
	)
	
	%Warning.text = "Waiting for access token..."


func _on_token_result(
	result: DiscordClientResult,
	access_token: String,
	_refresh_token: String,
	_token_type: DiscordAuthorizationTokenType.Enum,
	_expires_in: int,
	_scopes: String,
	client: DiscordClient
) -> void:
	if not result.successful():
		%Warning.text = "Failed to get token: %s" % result.error()
		return
	
	client.update_token(
		DiscordAuthorizationTokenType.BEARER,
		access_token,
		_on_token_updated.bind(client)
	)
	
	%Warning.text = "Updating token..."


func _on_token_updated(result: DiscordClientResult, client: DiscordClient) -> void:
	if not result.successful():
		%Warning.text = "Failed to update token: %s" % result.error()
		return
	
	client.connect_discord()
	hide()
	
	%Warning.text = ""
