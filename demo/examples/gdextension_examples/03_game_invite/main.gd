extends VBoxContainer

var client := DiscordClient.new()


func _ready() -> void:
	%LogContainer.setup(client)
	%StatusContainer.setup(client)
	%FriendsContainer.setup(client)
	%ConnectContainer.setup(client)


func _process(_delta: float) -> void:
	Discord.run_callbacks()


func _on_rich_presence_container_update_pressed(activity: Variant) -> void:
	client.update_rich_presence(activity, %RichPresenceContainer.on_rich_presence_updated)


func _on_status_container_status_ready() -> void:
	%FriendsContainer.update_friends_list(client)


func _on_invite_container_invite_requested(user_id: int, message: String) -> void:
	client.send_activity_invite(user_id, message, %InviteContainer.on_activity_invite_sent)
