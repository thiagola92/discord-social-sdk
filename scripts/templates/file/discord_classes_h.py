def get_discord_classes_h(classes_declarations: str, classes_definitions: str) -> str:
    return f"""
#ifndef DISCORD_CLASSES_H
#define DISCORD_CLASSES_H

#include "discord_enum.h"
#include "discordpp.h"
#include "godot_cpp/classes/node.hpp"
#include "godot_cpp/classes/ref_counted.hpp"
#include "godot_cpp/variant/typed_array.hpp"
#include "godot_cpp/variant/typed_dictionary.hpp"

namespace godot {{

// Generated declarations.
{classes_declarations}

// Support declarations.
class DiscordInt16Array;
class DiscordBoolRef;

// Generated definitions.
{classes_definitions}

// Support definitions.
class DiscordInt16Array : public RefCounted {{
	GDCLASS(DiscordInt16Array, RefCounted)

private:
	int16_t *_ptr;
	int64_t _size;

	DiscordInt16Array() {{}}

protected:
	static void _bind_methods();

public:
	// Internal usage.
	int16_t *unwrap() {{
		return _ptr;
	}}

	// Functions.
	int64_t get(int64_t p_index);
	int64_t size();
	void set(int64_t p_index, int64_t value);

	// Internal usage.
	DiscordInt16Array(int16_t *ptr, int64_t size) {{
		_ptr = ptr;
		_size = size;
	}}

	~DiscordInt16Array() {{}}
}};

class DiscordBoolRef : public RefCounted {{
	GDCLASS(DiscordBoolRef, RefCounted)

private:
  bool *_ptr = nullptr;
  
  DiscordBoolRef() {{}}
  
protected:
	static void _bind_methods();

public:
	DiscordBoolRef(bool *ptr) {{
    _ptr = ptr;
	}}
  
  bool get_value() {{
		return _ptr ? *_ptr : false;
	}}
    
  void set_value(bool p_value) {{
		if (_ptr) *_ptr = p_value;
	}}
  
  ~DiscordBoolRef() {{}}
}};

}} //namespace godot

#endif
"""
