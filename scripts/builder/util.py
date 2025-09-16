########################## PROBLEM ##########################
# GDScript doesn't support function overloading, this is when
# you have two functions with same name but different parameters.
# Example:
#
#   func example(a: int)
#   func example(a: int, b: int)
#   func example(a: float)
#
# In Discord SDK, there is cases where function overload is used:
#
#   inline const char *EnumToString(discordpp::ActivityActionTypes value)
#   inline const char *EnumToString(discordpp::ActivityPartyPrivacy value)
#   inline const char *EnumToString(discordpp::ActivityTypes value)
#   inline const char *EnumToString(discordpp::AuthenticationExternalAuthType value)
#
# We can't solve this using Variant, because we wouldn't be able
# to distinguish between different enums passed as arguments:
#
#   func _ready() -> void:
#       EnumToString(DiscordppActivityTypes.PLAYING)
#
#   func EnumToString(value: Variant) -> String:
#       print(value is DiscordppActivityTypes.Enum)                       # true
#       print(value is is DiscordppAuthenticationExternalAuthType.Enum)   # true
#
# There is no way to maintain one function for multiple uses
# without drastically changing the parameters... 😕
#
########################## SOLUTION ##########################
# An easier solution is to create more functions.
#
#   func EnumToStringActivityTypes(value: DiscordppActivityTypes.Enum) -> String:
#       pass
#
#   func EnumToStringAuthenticationExternalAuthType(value: DiscordppAuthenticationExternalAuthType.Enum) -> String:
#       pass
#
# Basically we just append the type of each parameter to the function name.
#
# Sadly this means that this GDExtension will not be an one-to-one with the SDK 😭.
from parser.tokens import TokenFunction


def get_functions_names(functions: list[TokenFunction]) -> dict[TokenFunction, str]:
    # Count how many overloading a function has.
    counter: dict[str, int] = {}

    for function in functions:
        if function.name in counter:
            counter[function.name] += 1
        else:
            counter[function.name] = 0

    # Set overloadings names.
    functions_names = {}

    for function in functions:
        if counter[function.name] > 0:
            types = [p.type.name for p in function.params]
            types = [t.removeprefix("discordpp::") for t in types]
            types = [t.replace("::", "") for t in types]
            types = "".join(types)
            functions_names[function] = f"{function.name}{types}"
        else:
            functions_names[function] = function.name

    return functions_names
