# Responsible for solving naming problems.

RESERVED_NAMES = [
    # Used by GDScript Object methods.
    "_get",
    "_get_property_list",
    "_init",
    "_iter_get",
    "_iter_init",
    "_iter_next",
    "_notification",
    "_property_can_revert",
    "_property_get_revert",
    "_set",
    "_to_string",
    "_validate_property",
    "add_user_signal",
    "call",
    "call_deferred",
    "callv",
    "can_translate_messages",
    "cancel_free",
    "connect",
    "disconnect",
    "emit_signal",
    "free",
    "get",
    "get_class",
    "get_incoming_connections",
    "get_indexed",
    "get_instance_id",
    "get_meta",
    "get_meta_list",
    "get_method_argument_count",
    "get_method_list",
    "get_property_list",
    "get_script",
    "get_signal_connection_list",
    "get_signal_list",
    "get_translation_domain",
    "has_connections",
    "has_meta",
    "has_method",
    "has_signal",
    "has_user_signal",
    "is_blocking_signals",
    "is_class",
    "is_connected",
    "is_queued_for_deletion",
    "notification",
    "notify_property_list_changed",
    "property_can_revert",
    "property_get_revert",
    "remove_meta",
    "remove_user_signal",
    "set",
    "set_block_signals",
    "set_deferred",
    "set_indexed",
    "set_message_translation",
    "set_meta",
    "set_script",
    "set_translation_domain",
    "to_string",
    "tr",
    "tr_n",
    # Used by GDScript Object signals.
    "property_list_changed",
    "script_changed",
    # Used by GDScript RefCounted methods.
    "get_reference_count",
    "init_ref",
    "reference",
    "unreference",
]


def to_gdscript_variable_name(string: str) -> str:
    """Convert string to a valid gdscript variable name."""
    string = to_snake_case(string)

    if string in RESERVED_NAMES:
        string += "_discord"

    return string


def to_snake_case(string: str) -> str:
    """Convert string to snake_case."""

    new_string = ""
    can_add_underscore = False

    for c in string:
        if c.islower():
            new_string += c
            can_add_underscore = True
        elif c.isupper():
            if can_add_underscore:
                new_string += "_"
                can_add_underscore = False
            new_string += c.lower()
        else:
            new_string += c

    return new_string


def to_constant_case(string: str) -> str:
    """Convert string to CONSTANT_CASE."""

    new_string = ""
    can_add_underscore = False

    for c in string:
        if c.islower():
            new_string += c.upper()
            can_add_underscore = True
        elif c.isupper():
            if can_add_underscore:
                new_string += "_"
                can_add_underscore = False
            new_string += c
        else:
            new_string += c.upper()

    return new_string


def to_godot_class_name(string: str) -> str:
    """Convert string to our expected class name."""
    string = string.replace("discordpp::", "").replace("::", "")
    string = f"Discord{string}"
    return string


def to_godot_enum_name(string: str) -> str:
    """Convert string to our expected enum name."""
    return to_godot_class_name(string) + "::Enum"
