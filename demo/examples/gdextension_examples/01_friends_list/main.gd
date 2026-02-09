extends VBoxContainer

var client := DiscordClient.new()


func _ready() -> void:
	%LogContainer.setup(client)
	%StatusContainer.setup(client)
	%FriendsContainer.setup(client)
	%ConnectContainer.setup(client)


func _process(_delta: float) -> void:
	Discord.run_callbacks()


func _on_status_container_status_ready() -> void:
	%FriendsContainer.update_friends_list(client)
