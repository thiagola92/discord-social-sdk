class_name Testing
extends Node


enum Example {
	VALUE = 1,
}

enum Example2 {
	VALUE = 1,
}


func _ready() -> void:
	print(Example2.VALUE)
	print(Example.VALUE)
