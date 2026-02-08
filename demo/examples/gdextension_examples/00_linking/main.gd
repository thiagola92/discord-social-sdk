extends VBoxContainer

var client := DiscordClient.new()


func _ready() -> void:
	%LogContainer.setup(client)
	%ConnectContainer.setup(client)


func _process(_delta: float) -> void:
	Discord.run_callbacks()
