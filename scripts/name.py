# Responsible for solving naming problems.
from data import FunctionInfo

# Reserved because they are used in GDScript Object/RefCounted.
RESERVED_NAMES = [
    # Object.
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
    # RefCounted.
    "get_reference_count",
    "init_ref",
    "reference",
    "unreference",
]


def undo_functions_overload(functions: list[FunctionInfo]) -> list[FunctionInfo]:
    """Undo functions overload.

    ### Context
    GDScript doesn't support function overloading.This means that,
    we can't have two functions having the same name but different parameters.

    Example:
        func example(a: int)
        func example(a: int, b: int)
        func example(a: float)

    And it is something that happens in Discord SDK:
        inline const char *EnumToString(discordpp::ActivityActionTypes value)
        inline const char *EnumToString(discordpp::ActivityPartyPrivacy value)
        inline const char *EnumToString(discordpp::ActivityTypes value)
        ...

    We can't solve this using Variant, because we wouldn't be able
    to distinguish between different enums passed as arguments:

        func _ready() -> void:
            enum_to_string(DiscordActivityTypes.PLAYING)

        func enum_to_string(value: Variant) -> String:
            print(value is DiscordActivityTypes.Enum)                  # true
            print(value is DiscordAuthenticationExternalAuthType.Enum) # true

    ### Solution
    A simple solution for our problem is creating more functions.

        func _ready() -> void:
            enum_to_string_activity_types(DiscordActivityTypes.PLAYING)
            enum_to_string_authentication_external_auth_type(DiscordAuthenticationExternalAuthType.OIDC)

    Basically we just append the type of each parameter type to the function name.
    It's ugly... But will probably work forever and for any function overloaded.

    ### Note
    We though about replacing only the "enum" part:

        func _ready() -> void:
            activity_types_to_string(DiscordActivityTypes.PLAYING)
            authentication_external_auth_type_to_string(DiscordAuthenticationExternalAuthType.OIDC)

    But if this were to happen with any other function, we would have to
    make special adjustment for that function too.
    """

    counter: dict[str, int] = {}

    for f in functions:
        if f.gdscript_name in counter:
            counter[f.gdscript_name] += 1
        else:
            counter[f.gdscript_name] = 0

    for f in functions:
        if counter[f.gdscript_name] > 0:
            for p in f.params:
                # TODO: Stop using C++ type name,
                # start using GDScript type name.
                n = p.type.name.replace("const ", "")
                f.gdscript_name += "_" + n

    return functions


def to_gdscript_name(string: str) -> str:
    """Convert string to a valid gdscript name."""
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

    return new_string
