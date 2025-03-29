TEMPLATE_H_1 = """#ifndef DISCORD_{header_definition}_H
#define DISCORD_{header_definition}_H

#include "discordpp.h"{includes}
#include "godot_cpp/classes/ref_counted.hpp"

namespace godot {{

class Discord{class_name} : public RefCounted {{
	GDCLASS(Discord{class_name}, RefCounted)

private:
	discordpp::{class_name} {property_name};

protected:
	static void _bind_methods();

public:
	discordpp::{class_name} *unwrap(); // Internal usage.
{signatures}
	Discord{class_name}();
	~Discord{class_name}();
}};

}} //namespace godot

#endif
"""

#####################################################

TEMPLATE_H_2 = """#ifndef DISCORD_{header_definition}_H
#define DISCORD_{header_definition}_H

#include "discordpp.h"{includes}
#include "godot_cpp/classes/ref_counted.hpp"

namespace godot {{

class Discord{class_name} : public RefCounted {{
	GDCLASS(Discord{class_name}, RefCounted)

    Discord{class_name}();

private:
	// Doesn't have empty contrusctor, needs to be a pointer.
	discordpp::{class_name} *{property_name};

protected:
	static void _bind_methods();

public:
	discordpp::{class_name} *unwrap(); // Internal usage.

{signatures}
	Discord{class_name}(discordpp::{class_name} *{property_name});
	~Discord{class_name}();
}};

}} //namespace godot

#endif
"""

#####################################################


def get_header_template(is_property_pointer: bool) -> str:
    if is_property_pointer:
        return TEMPLATE_H_2
    return TEMPLATE_H_1
