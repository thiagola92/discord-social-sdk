extends Node


const APPLICATION_ID = 123

@onready var client: DiscordClient = $DiscordClient


func _ready() -> void:
	client.add_log_callback(DiscordLoggingSeverity.VERBOSE)
	client.add_log_callback(DiscordLoggingSeverity.VERBOSE)
	client.add_log_callback(DiscordLoggingSeverity.VERBOSE)
	
	# Just for testing (it's suppose to fail)
	client.authorize(DiscordAuthorizationArgs.new())
