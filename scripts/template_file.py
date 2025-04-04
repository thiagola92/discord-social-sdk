AUTO_GENERATED_COMMENT = "// AUTO-GENERATED"


def header_(
    header_definition: str,
    includes: str,
    class_name: str,
    property_name: str,
    signatures: str,
    has_empty_constructor: bool,
    has_callbacks: bool,
) -> str:
    empty_constructor = f"Discord{class_name}();"
    property_declaration = f"discordpp::{class_name} *{property_name};"
    public_constructor = (
        f"Discord{class_name}(discordpp::{class_name} *{property_name});"
    )

    include_class = "node" if has_callbacks else "ref_counted"
    super_class = "Node" if has_callbacks else "RefCounted"

    if has_empty_constructor:
        private_empty_constructor = ""
        public_empty_constructor = empty_constructor
    else:
        private_empty_constructor = empty_constructor
        public_empty_constructor = ""

    return f"""{AUTO_GENERATED_COMMENT}
#ifndef DISCORD_{header_definition}_H
#define DISCORD_{header_definition}_H

{includes}
#include "discordpp.h"
#include "godot_cpp/classes/{include_class}.hpp"
#include "godot_cpp/variant/typed_dictionary.hpp"
#include "godot_cpp/variant/typed_array.hpp"

namespace godot {{

class Discord{class_name} : public {super_class} {{
    GDCLASS(Discord{class_name}, {super_class})

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
    has_empty_constructor: bool,
) -> str:
    if has_empty_constructor:
        constructor = f"this->{property_name} = memnew(discordpp::{class_name});"
    else:
        constructor = ""

    return f"""{AUTO_GENERATED_COMMENT}
#include "{filename_h}"

using namespace godot;

discordpp::{class_name} *Discord{class_name}::unwrap() {{
    return {property_name};
}}
{methods}
void Discord{class_name}::_bind_methods() {{
    {signals}
    {binds}
}}

Discord{class_name}::Discord{class_name}() {{
    {constructor}
}}

Discord{class_name}::Discord{class_name}(discordpp::{class_name} *{property_name}) {{
    this->{property_name} = {property_name};
}}

Discord{class_name}::~Discord{class_name}() {{}}
"""
