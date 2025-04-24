extends Node


var client: DiscordppClient = BasicClient.get_client()


func _ready() -> void:
	test_dir("res://test/unit")


func test_dir(dirname: String) -> void:
	print(dirname)
	
	var dir = DirAccess.open(dirname)
	
	for f in dir.get_files():
		test_file("%s/%s" % [dirname, f])
	
	for d in dir.get_directories():
		test_dir("%s/%s" % [dirname, d])


func test_file(filename: String) -> void:
	if filename.ends_with(".gd"):
		test_script(filename)


func test_script(filename: String) -> void:
	print(filename)
	
	var script: Script = load(filename)
	var node: Node = script.new()
	
	add_child(node)
	
	for method in node.get_method_list():
		var method_name: String = method["name"]
		
		if method_name.begins_with("test_"):
			print(filename, " -> ", method_name, "()")
			node.call(method_name, client)


func _process(_delta: float) -> void:
	Discordpp.RunCallbacks()
