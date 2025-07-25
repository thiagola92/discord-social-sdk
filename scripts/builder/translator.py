# ruff: noqa: F541
# Remove warnings about f-strings without using variables.

from parser.tokens import TokenType, TokenEnum, TokenClass, TokenParam


class Translator:
    """
    Focus in translate between Godot types and C types.

    When I say "C types", I mean types that we would normally
    use when writing C/C++ or objects from Discord SDK.

    When I say "Godot types", I mean types that we use
    when writing GDScript code in Godot.
    """

    def __init__(self, tokens: list):
        self.tokens = tokens

    ########################################################################
    ########################################################################
    # Type checkers.
    ########################################################################
    ########################################################################

    def is_c_void(self, type_name: str) -> bool:
        return type_name in ["void"]

    def is_c_bool(self, type_name: str) -> bool:
        return type_name in ["bool", "bool&", "bool &"]

    def is_c_int(self, type_name: str) -> bool:
        return type_name in [
            "uint8_t",
            "int16_t *",
            "int16_t const*",
            "int16_t const *",
            "int32_t",
            "static int32_t",
            "uint32_t",
            "int64_t",
            "uint64_t",
        ]

    def is_c_float(self, type_name: str) -> bool:
        return type_name in ["float"]

    def is_c_string(self, type_name: str) -> bool:
        return type_name in [
            "std::string",
            "std::string const",
            "static std::string",
            "std::string const &",
        ]

    def is_c_char_array(self, type_name: str) -> bool:
        return type_name in [
            "const char *",
        ]

    def is_c_opt(self, type_name: str) -> bool:
        return type_name.startswith("std::optional")

    def is_c_vec(self, type_name: str) -> bool:
        return type_name.startswith("std::vector")

    def is_c_map(self, type_name: str) -> bool:
        return type_name.startswith("std::unordered_map")

    def is_c_callback(self, type_name: str) -> bool:
        if not type_name.startswith("discordpp::"):
            return False

        for token in self.tokens:
            if isinstance(token, TokenClass):
                for c in token.callbacks:
                    if type_name == f"discordpp::{token.name}::{c.name}":
                        return True

        return False

    def is_c_enum(self, type_name: str) -> bool:
        if not type_name.startswith("discordpp::"):
            return False

        for token in self.tokens:
            if isinstance(token, TokenEnum):
                if type_name == f"discordpp::{token.name}":
                    return True
            elif isinstance(token, TokenClass):
                for t in token.enums:
                    if type_name == f"discordpp::{token.name}::{t.name}":
                        return True

        return False

    def is_c_discord(self, type1: str) -> bool:
        return type1.startswith("discordpp::")

    def is_c_many(self, type_name: str) -> bool:
        """
        Check if this type is in reality more than one type.

        Use when parsing generics that accept many types. Example:
            std::unordered_map<std::string, std::string>
        When passing "std::string, std::string" it will return True.
        """

        return "," in type_name

    ########################################################################
    ########################################################################
    # String convertions.
    ########################################################################
    ########################################################################

    def c_name_to_godot_name(self, type_name: str) -> str | None:
        """
        Convert C enum/object name to Godot enum/object name.

        Also used used to discover if a type is enum or not because
        it will return None if can't find the enum.

        Examples:
            Input:     discordpp::Client::Error
            Output:    DiscordppClientError::Enum

            Input:     discordpp::Client
            Output:    DiscordppClient
        """

        if not type_name.startswith("discordpp::"):
            return None

        # Returns if find an enum with this name.
        for token in self.tokens:
            if isinstance(token, TokenEnum):
                if type_name == f"discordpp::{token.name}":
                    return f"Discordpp{token.name}::Enum"
            elif isinstance(token, TokenClass):
                for t in token.enums:
                    if type_name == f"discordpp::{token.name}::{t.name}":
                        return f"Discordpp{token.name}{t.name}::Enum"

        # Otherwise a simple replace is enough.
        return type_name.replace("discordpp::", "Discordpp")

    def c_type_to_variant_type(self, type_name: str) -> str:
        """
        Get the Variant::Type expected for a specific C type.
        """

        if self.is_c_void(type_name):
            return "Variant::NIL"

        elif self.is_c_bool(type_name):
            return "Variant::BOOL"

        elif self.is_c_int(type_name):
            return "Variant::INT"

        elif self.is_c_float(type_name):
            return "Variant::FLOAT"

        elif self.is_c_string(type_name):
            return "Variant::STRING"

        elif self.is_c_vec(type_name):
            return "Variant::ARRAY"

        elif self.is_c_map(type_name):
            return "Variant::DICTIONARY"

        elif self.is_c_callback(type_name):
            return "Variant::CALLABLE"

        elif self.is_c_enum(type_name):
            return "Variant::INT"

        elif self.is_c_discord(type_name):
            return "Variant::OBJECT"

        assert False, f'Fail to identify a good Variant type for "{type_name}"'

    ########################################################################
    ########################################################################
    # Data convertions (C -> Godot).
    ########################################################################
    ########################################################################

    def c_type_to_godot_type(self, token: TokenType, pointer: bool = True) -> str:
        """
        Return the Godot type that would be equivalent to this C type.

        Very useful when building the Godot methods signature, it tell us
        which return type and params type Godot will use for them.

        The pointer parameter is useful for cases outside of
        method signature, where you may need it response raw.
        """

        if self.is_c_void(token.name):
            return "void"

        elif self.is_c_bool(token.name):
            return "bool"

        elif self.is_c_int(token.name):
            return "int64_t"

        elif self.is_c_float(token.name):
            return "float"

        elif self.is_c_string(token.name):
            return "String"

        elif self.is_c_char_array(token.name):
            return "String"

        elif self.is_c_opt(token.name):
            return "Variant"

        elif self.is_c_vec(token.name):
            subtype = self.c_type_to_godot_type(token.subtype, False)
            return f"TypedArray<{subtype}>"

        elif self.is_c_map(token.name):
            subtype = self.c_type_to_godot_type(token.subtype, False)
            return f"TypedDictionary<{subtype}>"

        elif self.is_c_callback(token.name):
            return "Callable"

        elif self.is_c_enum(token.name):
            return self.c_name_to_godot_name(token.name)

        elif self.is_c_discord(token.name):
            name = self.c_name_to_godot_name(token.name)
            return f"{name}*" if pointer else name

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

    def c_var_to_godot_var(self, src: TokenParam, dest: str) -> str:
        """
        Returns statements that convert a variable from
        C type to Godot type and store it value in dest.

        Mostly used for lambda expressions from callbacks,
        because it receives C variables and we need to
        convert to Godot before passing to a Callable.
        """

        if self.is_c_bool(src.type.name):
            return f"bool {dest} = {src.name};"

        elif self.is_c_int(src.type.name):
            return f"int64_t {dest} = (int64_t){src.name};"

        elif self.is_c_float(src.type.name):
            return f"float {dest} = (float){src.name};"

        elif self.is_c_string(src.type.name):
            return f"String {dest} = String({src.name}.c_str());"

        elif self.is_c_char_array(src.type.name):
            return f"String {dest} = String({src.name});"

        elif self.is_c_opt(src.type.name):
            return self.c_opt_to_godot_variant(src, dest)

        elif self.is_c_vec(src.type.name):
            return self.c_vec_to_godot_array(src, dest)

        elif self.is_c_map(src.type.name):
            return self.c_map_to_godot_dict(src, dest)

        elif self.is_c_callback(src.type.name):
            assert False, "Not implemented (implement if needed)"

        elif self.is_c_enum(src.type.name):
            enum = self.c_name_to_godot_name(src.type.name)
            return f"{enum} {dest} = ({enum}){src.name};"

        elif self.is_c_discord(src.type.name):
            return self.c_discord_to_godot_discord(src, dest)

        assert False, f'Fail to convert return from "{src.type.name}" to Godot type'

    def c_opt_to_godot_variant(self, src: TokenParam, dest: str) -> str:
        """
        Branch of c_var_to_godot_var().
            from:   std::optional<>
            to:     Variant
        """

        # It's intentional to cause error if no condition match.
        convertion_statements = None

        if self.is_c_bool(src.type.subtype.name):
            convertion_statements = [f"{dest} = Variant({src.name}.value());"]

        elif self.is_c_int(src.type.subtype.name):
            convertion_statements = [f"{dest} = Variant((int64_t){src.name}.value());"]

        elif self.is_c_float(src.type.subtype.name):
            convertion_statements = [f"{dest} = Variant((float){src.name}.value());"]

        elif self.is_c_string(src.type.subtype.name):
            convertion_statements = [f"{dest} = Variant({src.name}.value().c_str());"]

        elif self.is_c_char_array(src.type.name):
            convertion_statements = [f"{dest} = Variant({src.name}.value());"]

        elif self.is_c_opt(src.type.subtype.name):
            assert False, "Not implemented (implement if needed)"

        elif self.is_c_vec(src.type.subtype.name):
            assert False, "Not implemented (implement if needed)"

        elif self.is_c_map(src.type.subtype.name):
            assert False, "Not implemented (implement if needed)"

        elif self.is_c_callback(src.type.subtype.name):
            assert False, "Not implemented (implement if needed)"

        elif self.is_c_enum(src.type.subtype.name):
            enum = self.c_name_to_godot_name(src.type.subtype.name)
            convertion_statements = [f"{dest} = Variant(({enum}) {src.name}.value());"]

        elif self.is_c_discord(src.type.subtype.name):
            type_name = self.c_type_to_godot_type(src.type.subtype, False)

            convertion_statements = [
                f"{src.type.subtype.name} *t = memnew({src.type.subtype.name}(std::move({src.name}.value())));",
                f"{dest} = Variant(memnew({type_name}{{ t }}));",
                f"",
            ]

        convertion_statements = "\n    ".join(convertion_statements)

        statements = [
            f"Variant {dest};",
            f"",
            f"if (!{src.name}.has_value()) {{",
            f"    {dest} = nullptr;",
            f"}} else {{",
            f"    {convertion_statements}",
            f"}}",
            f"",
        ]

        statements = "\n    ".join(statements)

        return statements

    def c_vec_to_godot_array(self, src: TokenParam, dest: str) -> str:
        """
        Branch of c_var_to_godot_var().
            from:   std::vector<>
            to:     TypedArray<>
        """

        # It's intentional to cause error if no condition match.
        append_statements = None

        if self.is_c_bool(src.type.subtype.name):
            append_statements = [f"{dest}.push_back(i);"]

        elif self.is_c_int(src.type.subtype.name):
            append_statements = [f"{dest}.push_back((int64_t)i);"]

        elif self.is_c_float(src.type.subtype.name):
            append_statements = [f"{dest}.push_back((float)i);"]

        elif self.is_c_string(src.type.subtype.name):
            append_statements = [f"{dest}.push_back(String(i.c_str()));"]

        elif self.is_c_opt(src.type.subtype.name):
            assert False, "Not implemented (implement if needed)"

        elif self.is_c_vec(src.type.subtype.name):
            assert False, "Not implemented (implement if needed)"

        elif self.is_c_map(src.type.subtype.name):
            assert False, "Not implemented (implement if needed)"

        elif self.is_c_callback(src.type.subtype.name):
            assert False, "Not implemented (implement if needed)"

        elif self.is_c_enum(src.type.subtype.name):
            assert False, "Not implemented (implement if needed)"

        elif self.is_c_discord(src.type.subtype.name):
            obj_type = self.c_type_to_godot_type(src.type.subtype, False)
            append_statements = [
                f"{src.type.subtype.name} *t_i = memnew({src.type.subtype.name}(std::move(i)));",
                f"{dest}.push_back(memnew({obj_type}{{ t_i }}));",
            ]

        append_statements = "\n        ".join(append_statements)
        typed_array = self.c_type_to_godot_type(src.type)

        statements = [
            f"{typed_array} {dest} = {typed_array}();",
            f"",
            f"for (auto i : {src.name}) {{",
            f"    {append_statements}",
            f"}}",
            f"",
        ]

        statements = "\n    ".join(statements)

        return statements

    def c_map_to_godot_dict(self, src: TokenParam, dest: str) -> str:
        """
        Branch of c_var_to_godot_var().
            from:   std::vector<>
            to:     TypedArray<>
        """

        # It's intentional to cause error if no condition match.
        set_statements = None

        if self.is_c_many(src.type.subtype.name):
            set_statements = [
                "t_r[String(p.first.c_str())] = String(p.second.c_str());"
            ]

        set_statements = "\n        ".join(set_statements)
        typed_dict = self.c_type_to_godot_type(src.type)

        statements = [
            f"{typed_dict} {dest} = {typed_dict}();",
            f"",
            f"for (auto p : {src.name}) {{",
            f"    {set_statements}",
            f"}}",
            f"",
        ]

        statements = "\n    ".join(statements)

        return statements

    def c_discord_to_godot_discord(self, src: TokenParam, dest: str) -> str:
        """
        Branch of c_var_to_godot_var().
            from:   discordpp::Class
            to:     DiscordppClass
        """

        name = self.c_name_to_godot_name(src.type.name)

        statements = [
            f"{src.type.name} *t_{dest} = memnew({src.type.name}(std::move({src.name})));",
            f"{name} *{dest} = memnew({name} {{ t_{dest} }});",
            f"",
        ]

        statements = "\n    ".join(statements)

        return statements

    ########################################################################
    ########################################################################
    # Data convertions (Godot -> C).
    ########################################################################
    ########################################################################

    def godot_var_to_c_var(self, param: TokenParam, dest: str) -> str:
        """
        Returns statements that convert a variable from
        Godot type to C type and store it value in dest.

        Mostly used at the start of functions,
        because it receives Godot variables and we need to
        convert to C before passing to a SDK method.

        We will be using a TokenParam, which holds a C type instead
        of a Godot type, but there is no problem because we can
        deduce which will be the Godot type from it.
        """

        if self.is_c_bool(param.type.name):
            return f"bool {dest} = {param.name};"

        elif self.is_c_int(param.type.name):
            return f"int64_t {dest} = {param.name};"

        elif self.is_c_float(param.type.name):
            return f"float {dest} = {param.name};"

        elif self.is_c_string(param.type.name):
            return f"std::string {dest} = std::string({param.name}.utf8().get_data());"

        elif self.is_c_char_array(param.type.name):
            return f"std::string {dest} = std::string({param.name}.utf8().get_data());"

        elif self.is_c_opt(param.type.name):
            return self.godot_variant_to_c_opt(param, dest)

        elif self.is_c_vec(param.type.name):
            return self.godot_array_to_c_vec(param, dest)

        elif self.is_c_map(param.type.name):
            return self.godot_dict_to_c_map(param, dest)

        elif self.is_c_callback(param.type.name):
            assert False, "Not implemented (implement if needed)"

        elif self.is_c_enum(param.type.name):
            return f"{param.type.name} {dest} = ({param.type.name}){param.name};"

        elif self.is_c_discord(param.type.name):
            return f"{param.type.name} {dest} = *{param.name}->unwrap();"

        elif self.is_c_many(param.type.name):
            assert False, "Not implemented (implement if needed)"

        assert False, (
            f'Fail to convert Godot variable "{param.type.name}" to C variable'
        )

    def godot_variant_to_c_opt(self, param: TokenParam, dest: str) -> str:
        """
        Branch of godot_var_to_c_var().
            from:   Variant
            to:     std::optional<>
        """

        variant_type = self.c_type_to_variant_type(param.type.subtype.name)
        convertion_statements = None

        if self.is_c_bool(param.type.subtype.name):
            convertion_statements = [f"{dest} = {param.name};"]

        elif self.is_c_int(param.type.subtype.name):
            convertion_statements = [f"{dest} = {param.name};"]

        elif self.is_c_float(param.type.subtype.name):
            convertion_statements = [f"{dest} = {param.name};"]

        elif self.is_c_string(param.type.subtype.name):
            convertion_statements = [
                f"{dest} = {param.name}.stringify().utf8().get_data();"
            ]

        elif self.is_c_vec(param.type.subtype.name):
            assert False, "Not implemented (implement if needed)"

        elif self.is_c_map(param.type.subtype.name):
            assert False, "Not implemented (implement if needed)"

        elif self.is_c_callback(param.type.subtype.name):
            assert False, "Not implemented (implement if needed)"

        elif self.is_c_enum(param.type.subtype.name):
            convertion_statements = [
                f"{dest} = std::optional<{param.type.subtype.name}>{{ ({param.type.subtype.name})(uint64_t){param.name} }};",
            ]

        elif self.is_c_discord(param.type.subtype.name):
            class_type = self.c_type_to_godot_type(param.type.subtype, False)

            convertion_statements = [
                f"{class_type} *t_{dest} = Object::cast_to<{class_type}>({param.name});",
                f"{dest} = std::optional<{param.type.subtype.name}>{{ *t_{dest}->unwrap() }};",
            ]

        convertion_statements = "\n        ".join(convertion_statements)

        statements = [
            f"std::optional<{param.type.subtype.name}> {dest};",
            f"",
            f"if ({param.name}.get_type() == {variant_type}) {{",
            f"    {convertion_statements}",
            f"}}",
            f"",
        ]

        statements = "\n    ".join(statements)

        return statements

    def godot_array_to_c_vec(self, param: TokenParam, dest: str) -> str:
        """
        Branch of godot_var_to_c_var().
            from:   TypedArray<>
            to:     std::vector<>
        """

        append_statements = None

        if self.is_c_bool(param.type.subtype.name):
            append_statements = [f"{dest}.append(i_{dest});"]

        elif self.is_c_int(param.type.subtype.name):
            append_statements = [f"{dest}.append(i_{dest});"]

        elif self.is_c_float(param.type.subtype.name):
            append_statements = [f"{dest}.append(i_{dest});"]

        elif self.is_c_string(param.type.subtype.name):
            append_statements = [f"{dest}.append(i_{dest}.utf8().get_data());"]

        elif self.is_c_opt(param.type.subtype.name):
            assert False, "Not implemented (implement if needed)"

        elif self.is_c_vec(param.type.subtype.name):
            assert False, "Not implemented (implement if needed)"

        elif self.is_c_map(param.type.subtype.name):
            assert False, "Not implemented (implement if needed)"

        elif self.is_c_callback(param.type.subtype.name):
            assert False, "Not implemented (implement if needed)"

        elif self.is_c_enum(param.type.subtype.name):
            append_statements = [f"{dest}.append(i_{dest});"]

        elif self.is_c_discord(param.type.subtype.name):
            append_statements = [f"{dest}.append(i_{dest}->unwrap());"]

        append_statements = "\n        ".join(append_statements)

        statements = [
            f"std::vector<{param.type.subtype.name}> {dest} = std::vector<{param.type.subtype.name}>();",
            f"",
            f"for (auto i_{dest} : {param.name}) {{",
            f"    {append_statements}",
            f"}}",
        ]

        statements = "\n    ".join(statements)

        return ""

    def godot_dict_to_c_map(self, param: TokenParam, dest: str) -> str:
        """
        Branch of godot_var_to_c_var().
            from:   TypedDictionary<>
            to:     std::unordered_map<>
        """

        statements = [
            # NOTE: This is a "gambiarra" because I know that we only works with std::string maps.
            f"std::unordered_map<std::string, std::string> {dest} = std::unordered_map<std::string, std::string>();",
            f"auto k_{dest} = {param.name}.keys();",
            f"",
            f"for (int i = 0; i < k_{dest}.size(); i++) {{",
            f"    auto k = k_{dest}[i];",
            f"    auto v = {param.name}[k];",
            f"    auto k_s = k.stringify().utf8().get_data();",
            f"    auto v_s = v.stringify().utf8().get_data();",
            f"    {dest}[k_s]= v_s;",
            f"}}",
        ]

        statements = "\n    ".join(statements)

        return statements

    ########################################################################
    ########################################################################
    # Return convertions.
    ########################################################################
    ########################################################################

    def c_ret_to_godot_ret(self, ret_type: TokenType, call: str) -> str:
        """
        Return statements that convert the SDK response
        to Godot type while returning this new value.

        Used after calling SDK method, to return
        it value to Godot. Object example:
            auto r = client->StartCall(p0);
            discordpp::Call *t_r = memnew(discordpp::Call(std::move(r)));
            return memnew(DiscordppCall{ t_r });
        """

        if self.is_c_void(ret_type.name):
            return f"{call};"

        elif self.is_c_bool(ret_type.name):
            return f"return {call};"

        elif self.is_c_int(ret_type.name):
            return f"return {call};"

        elif self.is_c_float(ret_type.name):
            return f"return {call};"

        elif self.is_c_string(ret_type.name):
            return f"return String({call}.c_str());"

        elif self.is_c_char_array(ret_type.name):
            return f"return String({call});"

        elif self.is_c_opt(ret_type.name):
            return self.c_opt_ret_to_godot_variant_ret(ret_type.subtype, call)

        elif self.is_c_vec(ret_type.name):
            return self.c_vec_ret_to_godot_array_ret(ret_type, call)

        elif self.is_c_map(ret_type.name):
            return self.c_map_ret_to_godot_dict_ret(ret_type, call)

        elif self.is_c_callback(ret_type.name):
            assert False, "Not implemented (implement if needed)"

        elif self.is_c_enum(ret_type.name):
            enum = self.c_name_to_godot_name(ret_type.name)
            return f"return ({enum}){call};"

        elif self.is_c_discord(ret_type.name):
            return self.c_discord_ret_to_godot_discord_ret(ret_type, call)

        assert False, f'Fail to convert return from "{ret_type.name}" to Godot type'

    def c_opt_ret_to_godot_variant_ret(self, ret_type: TokenType, call: str) -> str:
        """
        Branch of c_ret_to_godot_ret().
            from:       std::optional<>
            return:     Variant
        """

        ret_statements = None

        if self.is_c_bool(ret_type.name):
            ret_statements = ["return Variant(r.value());"]

        elif self.is_c_int(ret_type.name):
            ret_statements = ["return Variant(r.value());"]

        elif self.is_c_float(ret_type.name):
            ret_statements = ["return Variant(r.value());"]

        elif self.is_c_string(ret_type.name):
            ret_statements = ["return Variant(r.value().c_str());"]

        elif self.is_c_opt(ret_type.name):
            assert False, "Not implemented (implement if needed)"

        elif self.is_c_vec(ret_type.name):
            assert False, "Not implemented (implement if needed)"

        elif self.is_c_map(ret_type.name):
            assert False, "Not implemented (implement if needed)"

        elif self.is_c_callback(ret_type.name):
            assert False, "Not implemented (implement if needed)"

        elif self.is_c_enum(ret_type.name):
            enum = self.c_name_to_godot_name(ret_type.name)
            ret_statements = [f"return Variant(({enum}) r.value());"]

        elif self.is_c_discord(ret_type.name):
            class_ = self.c_type_to_godot_type(ret_type, False)

            ret_statements = [
                f"{ret_type.name} *t_r = memnew({ret_type.name}(std::move(r.value())));",
                f"return Variant(memnew({class_}{{ t_r }}));",
            ]

        ret_statements = "\n    ".join(ret_statements)

        statements = [
            f"auto r = {call};",
            f"",
            f"if (!r.has_value()) {{",
            f"    return nullptr;",
            f"}}",
            f"",
            f"{ret_statements}",
        ]

        statements = "\n    ".join(statements)

        return statements

    def c_vec_ret_to_godot_array_ret(self, vec_type: TokenType, call: str) -> str:
        """
        Branch of c_ret_to_godot_ret().
            from:       std::vector<>
            return:     TypedArray<>
        """
        append_statements = None

        if self.is_c_bool(vec_type.subtype.name):
            append_statements = ["t_r.push_back(i);"]

        elif self.is_c_int(vec_type.subtype.name):
            append_statements = ["t_r.push_back((int64_t)i);"]

        elif self.is_c_float(vec_type.subtype.name):
            append_statements = ["t_r.push_back((float)i);"]

        elif self.is_c_string(vec_type.subtype.name):
            append_statements = ["t_r.push_back(String(i.c_str()));"]

        elif self.is_c_opt(vec_type.subtype.name):
            assert False, "Not implemented (implement if needed)"

        elif self.is_c_vec(vec_type.subtype.name):
            assert False, "Not implemented (implement if needed)"

        elif self.is_c_map(vec_type.subtype.name):
            assert False, "Not implemented (implement if needed)"

        elif self.is_c_callback(vec_type.subtype.name):
            assert False, "Not implemented (implement if needed)"

        elif self.is_c_enum(vec_type.subtype.name):
            assert False, "Not implemented (implement if needed)"

        elif self.is_c_discord(vec_type.subtype.name):
            obj_type = self.c_type_to_godot_type(vec_type.subtype, False)
            append_statements = [
                f"{vec_type.subtype.name} *t_i = memnew({vec_type.subtype.name}(std::move(i)));",
                f"t_r.push_back(memnew({obj_type}{{ t_i }}));",
            ]

        append_statements = "\n        ".join(append_statements)
        typed_array = self.c_type_to_godot_type(vec_type)

        statements = [
            f"auto r = {call};",
            f"{typed_array} t_r = {typed_array}();",
            f"",
            f"for (auto i : r) {{",
            f"    {append_statements}",
            f"}}",
            f"",
            f"return t_r;",
        ]

        statements = "\n    ".join(statements)

        return statements

    def c_map_ret_to_godot_dict_ret(self, map_type: TokenType, call: str) -> str:
        """
        Branch of c_ret_to_godot_ret().
            from:       std::unordered_map<>
            return:     TypedDictionary<>
        """

        set_statements = None

        if self.is_c_many(map_type.subtype.name):
            set_statements = [
                "t_r[String(p_r.first.c_str())] = String(p_r.second.c_str());"
            ]

        set_statements = "\n        ".join(set_statements)
        typed_dict = self.c_type_to_godot_type(map_type)

        statements = [
            f"auto r = {call};",
            f"{typed_dict} t_r = {typed_dict}();",
            f"",
            f"for (auto p_r : r) {{",
            f"    {set_statements}",
            f"}}",
            f"",
            f"return t_r;",
        ]

        statements = "\n    ".join(statements)

        return statements

    def c_discord_ret_to_godot_discord_ret(self, ret_type: TokenType, call: str) -> str:
        """
        Branch of c_ret_to_godot_ret().
            from:       discordpp::Class
            return:     DiscordppClass
        """

        name = self.c_name_to_godot_name(ret_type.name)

        statements = [
            f"{ret_type.name} r = {call};",
            f"{ret_type.name} *t_r = memnew({ret_type.name}(std::move(r)));",
            f"return memnew({name} {{ t_r }});",
        ]

        statements = "\n    ".join(statements)

        return statements
