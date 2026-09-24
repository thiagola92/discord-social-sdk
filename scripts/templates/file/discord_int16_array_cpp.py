def get_discord_int16_array_cpp() -> str:
    return """
#include "discord_classes.h"

using namespace godot;

int64_t DiscordInt16Array::get_value(int64_t p_index) {{
	CRASH_BAD_INDEX(p_index, _size);

	return (int64_t)_ptr[p_index];
}}

void DiscordInt16Array::set_value(int64_t p_index, int64_t value) {{
	ERR_FAIL_INDEX(p_index, _size);

	_ptr[p_index] = (int16_t)value;
}}

int64_t DiscordInt16Array::size() {{
	return _size;
}}

// Binding.
void DiscordInt16Array::_bind_methods() {{
	ClassDB::bind_method(D_METHOD("get_value", "index"),
			&DiscordInt16Array::get_value);

	ClassDB::bind_method(D_METHOD("set_value", "index", "value"),
			&DiscordInt16Array::set_value);

	ClassDB::bind_method(D_METHOD("size"),
			&DiscordInt16Array::size);
}}
"""
