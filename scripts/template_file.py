AUTO_GENERATED_COMMENT = "// AUTO-GENERATED"


def header_(
    header_definition: str,
    includes: str,
    class_name: str,
    property_name: str,
    signatures: str,
    is_property_pointer: bool,
) -> str:
    empty_constructor = f"Discord{class_name}();"

    if is_property_pointer:
        private_empty_constructor = empty_constructor
        public_empty_constructor = ""
        property_declaration = f"discordpp::{class_name} *{property_name}; // Doesn't have public empty contrusctor, needs to be a pointer."
        public_constructor = (
            f"Discord{class_name}(discordpp::{class_name} *{property_name});"
        )
    else:
        private_empty_constructor = ""
        public_empty_constructor = empty_constructor
        property_declaration = f"discordpp::{class_name} {property_name};"
        public_constructor = (
            f"Discord{class_name}(discordpp::{class_name} {property_name});"
        )

    return f"""{AUTO_GENERATED_COMMENT}
#ifndef DISCORD_{header_definition}_H
#define DISCORD_{header_definition}_H

{includes}
#include "discordpp.h"
#include "godot_cpp/classes/ref_counted.hpp"

namespace godot {{

class Discord{class_name} : public RefCounted {{
    GDCLASS(Discord{class_name}, RefCounted)

private:
    {property_declaration}

    {private_empty_constructor}
protected:
    static void _bind_methods();

public:
    discordpp::{class_name} *unwrap(); // Internal usage.

{signatures}

    {public_empty_constructor}
    {public_constructor}
    ~Discord{class_name}();
}};

}} //namespace godot

#endif
"""


def source_(
    filename_h: str,
    class_name: str,
    property_name: str,
    methods: str,
    signals: str,
    binds: str,
    is_property_pointer: bool,
) -> str:
    if is_property_pointer:
        ampersand = ""
        asterisk = "*"
    else:
        ampersand = "&"
        asterisk = ""

    return f"""{AUTO_GENERATED_COMMENT}
#include "{filename_h}"

using namespace godot;

discordpp::{class_name} *Discord{class_name}::unwrap() {{
    return {ampersand}{property_name};
}}
{methods}
void Discord{class_name}::_bind_methods() {{
    {signals}
    {binds}
}}

Discord{class_name}::Discord{class_name}() {{}}

Discord{class_name}::Discord{class_name}(discordpp::{class_name} {asterisk}{property_name}) {{
    this->{property_name} = {property_name};
}}

Discord{class_name}::~Discord{class_name}() {{}}
"""
