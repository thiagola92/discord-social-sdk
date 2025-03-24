extends Node


const APPLICATION_ID = 123456789012345678

@onready var client: DiscordClient = $DiscordClient


func _ready() -> void:
	var args := DiscordAuthorizationArgs.new()
	args.set_client_id(APPLICATION_ID)
	args.set_scopes("openid sdk.social_layer_presence")
	#args.set_code_challenge(codeVerifier.Challenge());
	
	client.authorize(args)
