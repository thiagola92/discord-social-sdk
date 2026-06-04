## Simple .env reader to use during examples.
##
## Used to preventing accidentally using personal APPLICATION_ID and pushing to the repository.
class_name DotEnv
extends RefCounted


static func read(name: String) -> String:
	var text = FileAccess.get_file_as_string("res://.env")
	
	if text == "":
		push_error("Create a .env file with %s" % name)
	
	var lines = text.split("\n")
	
	for line in lines:
		var part = line.split("=", false, 1)
		
		if part[0] == name:
			return part[1]
	
	return text


static func read_int(name: String) -> int:
	return int(read(name))
