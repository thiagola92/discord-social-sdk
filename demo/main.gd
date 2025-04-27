extends Node


var i = 0

func _ready() -> void:
	pass
	

#func _process(delta: float) -> void:
	#var c = DiscordppClient.new()


func _on_button_pressed() -> void:
	var c = DiscordppClient.new()
	i += 1
	$Label.text = str(i)
	
	do_nothing(c)


func do_nothing(c: DiscordppClient) -> void:
	print("Doing nothing: ", c.GetStatus())
