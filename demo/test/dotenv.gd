class_name DotEnv
extends RefCounted


static func read(name: String) -> String:
	var text = FileAccess.get_file_as_string("../.env")
	
	if text == null:
		push_error("Create a .env file with APPLICATION_ID")
	
	var lines = text.split("\n")
	
	for line in lines:
		var part = line.split("=", false, 1)
		
		if part[0] == "APPLICATION_ID":
			return part[1]
	
	return text


static func read_int(name: String) -> int:
	return int(read(name))
