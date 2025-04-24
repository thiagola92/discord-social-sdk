extends Node


signal log_added


func test_add_log_callback(client: DiscordppClient) -> void:
	
	client.AddLogCallback(
		func(message: String, severity: DiscordppLoggingSeverity.Enum):
			log_added.emit(),
		DiscordppLoggingSeverity.Verbose
	)
