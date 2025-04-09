extends Node


const APPLICATION_ID = 123

@onready var client: DiscordClient = $DiscordClient


func _ready() -> void:
	client.add_log_callback(
		func(m, s):
			printt("[%s] %s" % [s, m]),
		DiscordLoggingSeverity.VERBOSE
	)
	
	# Just for testing (it's suppose to fail)
	client.authorize(DiscordAuthorizationArgs.new())


func _on_discord_client_client_log_callback(message: String, severity: int) -> void:
	printt("message", message)
	printt("severity", severity)
