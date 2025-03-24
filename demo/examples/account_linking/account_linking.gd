extends Node


const APPLICATION_ID = 123

@onready var client: DiscordClient = $DiscordClient


func _ready() -> void:
	var code_verifier := client.create_authorization_code_verifier()
	
	var args := DiscordAuthorizationArgs.new()
	args.set_client_id(APPLICATION_ID)
	args.set_scopes("openid sdk.social_layer_presence")
	args.set_code_challenge(code_verifier.get_challenge());
	
	client.authorize(args)


func _on_discord_client_authorized() -> void:
	print("authorized")


func _on_discord_client_rejected() -> void:
	print("rejected")
