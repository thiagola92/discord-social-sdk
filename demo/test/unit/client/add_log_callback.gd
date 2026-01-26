extends Node


var log_working := false


func test_add_log_callback(client: DiscordppClient) -> void:
	client.AddLogCallback(
		func(_message: String, _severity: DiscordppLoggingSeverity.Enum):
			log_working = true,
		DiscordppLoggingSeverity.Verbose
	)
	
	await get_tree().create_timer(10).timeout
	
	assert(log_working)
