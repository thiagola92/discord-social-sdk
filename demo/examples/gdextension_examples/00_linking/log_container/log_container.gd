extends FoldableContainer


@export var log_severity: DiscordLoggingSeverity.Enum = DiscordLoggingSeverity.VERBOSE

func setup(client: DiscordClient) -> void:
	client.add_log_callback(_on_log_received, log_severity)


func _on_log_received(message: String, severity: DiscordLoggingSeverity.Enum) -> void:
	%Logs.text += "[%s] %s" % [
		Discord.enum_to_string(severity, DiscordLoggingSeverity.id),
		message
	]


func _on_logs_text_set() -> void:
	%Logs.scroll_vertical = 99999999999
