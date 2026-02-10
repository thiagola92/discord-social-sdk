extends FoldableContainer

signal invite_requested(user_id: int, message: String)


func on_activity_invite_sent(result: DiscordClientResult) -> void:
	if result.successful():
		%Warning.text = "✔️ Sent"
	else:
		%Warning.text = "❌ Error: %s" % result.error()


func _on_send_pressed() -> void:
	var user_id: String = %UserId.text
	
	if not user_id.is_valid_int():
		%Warning.text = "User ID must be an int"
		return
	
	invite_requested.emit(int(user_id), %Message.text)
