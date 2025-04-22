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
#   func EnumToString0(value: DiscordppActivityTypes.Enum) -> String:
#       pass
#
#   func EnumToString1(value: DiscordppAuthenticationExternalAuthType.Enum) -> String:
#       pass
#
# Sadly this means that this GDExtension will not be an one-to-one with the SDK 😭.
#
# NOTE: Sort the functions before numering! Why?
#
# Let's say that I execute my script today and the following functions are created:
#   EnumToString0(value: DiscordppActivityTypes.Enum)
#   EnumToString1(value: DiscordppAuthenticationExternalAuthType.Enum)
#
# The following day Discord update the headers files and switch functions,
# this could cause functions to switch place. Example:
#   EnumToString0(value: DiscordppAuthenticationExternalAuthType.Enum)
#   EnumToString1(value: DiscordppActivityTypes.Enum)
#
# The solution is sorting before numering functions.
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
        if counter[function.name] == 0:
            functions_names[function] = function.name
            del counter[function.name]

    # Only sort for the overloadeds.
    sorted_functions = sorted(functions, key=lambda t: str(t))

    for function in reversed(sorted_functions):
        if function.name in counter:
            number = counter[function.name]
            functions_names[function] = f"{function.name}{number}"
            counter[function.name] -= 1

    return functions_names
