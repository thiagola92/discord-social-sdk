extends HBoxContainer


signal status_ready


func setup(client: DiscordClient) -> void:
	client.set_status_changed_callback(_on_status_changed)


func _on_status_changed(
	status: DiscordClientStatus.Enum,
	error: DiscordClientError.Enum,
	_error_detail: int
) -> void:
	%Status.text = "Status: %s" % Discord.enum_to_string(status, DiscordClientStatus.id)
	
	if error != DiscordClientError.NONE:
		%Error.text = Discord.enum_to_string(error, DiscordClientError.id)
	else:
		%Error.text = ""
	
	if status == DiscordClientStatus.READY:
		status_ready.emit()
