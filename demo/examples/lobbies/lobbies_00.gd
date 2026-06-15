extends Node


# ATTENTION: Replace DotEnv.read_int("APPLICATION_ID") with your application ID.
# This only exist so I don't accidentally git push my ID.
var application_id: int = DotEnv.read_int("APPLICATION_ID")

var client := DiscordClient.new()


func _ready() -> void:
	client.set_application_id(application_id)
	client.create_or_join_lobby("your-unique-lobby-secret", _on_joined_lobby)


func _process(_delta: float) -> void:
	Discord.run_callbacks()


func _on_joined_lobby(result: DiscordClientResult, lobby_id: int) -> void:
	pass
