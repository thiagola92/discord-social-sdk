from builder.translator import Translator
from parser.tokens import TokenType


class DocTranslator(Translator):
    def __init__(self, tokens: list):
        self.tokens = tokens

    def c_type_to_gdscript_type(self, token: TokenType) -> str:
        """
        Return the GDScript type that would be equivalent to this C type.

        Same as c_type_to_godot_type() but instead of returning
        the C type used in GDExtensions, returns the GDScript type
        used in GDScript code.
        """

        if self.is_c_void(token.name):
            return "void"

        elif self.is_c_bool(token.name):
            return "bool"

        elif self.is_c_int(token.name):
            return "int"

        elif self.is_c_float(token.name):
            return "float"

        elif self.is_c_string(token.name):
            return "String"

        elif self.is_c_char_array(token.name):
            return f"String"

        elif self.is_c_opt(token.name):
            return "Variant"

        elif self.is_c_vec(token.name):
            subtype = self.c_type_to_godot_type(token.subtype, False)
            return f"TypedArray[{subtype}]"

        elif self.is_c_map(token.name):
            subtype = self.c_type_to_godot_type(token.subtype, False)
            return f"TypedDictionary[{subtype}]"

        elif self.is_c_callback(token.name):
            return "Callable"

        elif self.is_c_enum(token.name):
            return self.c_name_to_godot_name(token.name).replace("::", ".")

        elif self.is_c_discord(token.name):
            return self.c_name_to_godot_name(token.name)

        elif self.is_c_many(token.name):
            # NOTE: This is a "gambiarra" because I know that
            # this will only be trigger by "std::string, std::string"
            types = token.name.split(",")
            types = [t.strip() for t in types]
            types = [TokenType(name=t, subtype=None) for t in types]
            types = [self.c_type_to_godot_type(t) for t in types]
            types = ", ".join(types)
            return types

        assert False, f'Fail to convert from "{token.name}" to Godot type'
