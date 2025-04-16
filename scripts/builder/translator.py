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
            "int16_t const*",
            "int16_t const *",
            "int32_t",
            "uint32_t",
            "static int32_t",
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

        if self.is_c_bool(type_name):
            return "Variant::BOOL"

        if self.is_c_int(type_name):
            return "Variant::INT"

        if self.is_c_float(type_name):
            return "Variant::FLOAT"

        if self.is_c_string(type_name):
            return "Variant::STRING"

        if self.is_c_vec(type_name):
            return "Variant::ARRAY"

        if self.is_c_map(type_name):
            return "Variant::DICTIONARY"

        if self.is_c_callback(type_name):
            return "Variant::CALLABLE"

        if self.is_c_discord(type_name):
            return "Variant::OBJECT"

        assert False, f'Fail to identify a good Variant type for "{type_name}"'

    ########################################################################
    ########################################################################
    # Data convertions (C -> Godot).
    ########################################################################
    ########################################################################

    def c_type_to_godot_type(self, token: TokenType, ref: bool = True) -> str:
        """
        Return the Godot type that would be equivalent to this C type.

        Very useful when building the Godot methods signature, it tell us
        which return type and params type Godot will use for them.

        The ref parameter is useful for cases outside of
        method signature, where you may need it response raw.
        """

        if self.is_c_void(token.name):
            return "void"

        if self.is_c_bool(token.name):
            return "bool"

        if self.is_c_int(token.name):
            return "int64_t"

        if self.is_c_float(token.name):
            return "float"

        if self.is_c_string(token.name):
            return "String"

        if self.is_c_opt(token.name):
            return "Variant"

        if self.is_c_vec(token.name):
            subtype = self.c_type_to_godot_type(token.subtype, ref)
            return f"TypedArray<{subtype}>"

        if self.is_c_map(token.name):
            subtype = self.c_type_to_godot_type(token.subtype, ref)
            return f"TypedDictionary<{subtype}>"

        if self.is_c_callback(token.name):
            return "Callable"

        if self.is_c_enum(token.name):
            return self.c_name_to_godot_name(token.name)

        if self.is_c_discord(token.name):
            name = self.c_name_to_godot_name(token.name)
            return f"Ref<{name}>" if ref else name

        if self.is_c_many(token.name):
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
        """

        if self.is_c_bool(src.type.name):
            return f"bool {dest} = {src.name};"

        if self.is_c_int(src.type.name):
            return f"int64_t {dest} = (int64_t){src.name};"

        if self.is_c_float(src.type.name):
            return f"float {dest} = (float){src.name};"

        if self.is_c_string(src.type.name):
            return f"String {dest} = String({src.name}.c_str());"

        if self.is_c_opt(src.type.name):
            return self.c_opt_to_godot_variant(src, dest)

        if self.is_c_vec(src.type.name):
            return self.c_vec_to_godot_array(src, dest)

        if self.is_c_map(src.type.name):
            return self.c_map_to_godot_dict(src, dest)

        if self.is_c_callback(src.type.name):
            assert False, "Not implemented (implement if needed)"

        if self.is_c_enum(src.type.name):
            enum = self.c_name_to_godot_name(src.type.name)
            return f"{enum} {dest} = ({enum}){src.name};"

        if self.is_c_discord(src.type.name):
            return self.c_discord_to_godot_discord(src, dest)

        assert False, f'Fail to convert return from "{src.type.name}" to Godot type'

    def c_opt_to_godot_variant(self, src: TokenParam, dest: str) -> str:
        """
        Return statements that convert the SDK response,
        which is a std::optional, to Godot Variant type.

        Variant can hold the same value as std::optional
        or null in case the std::optional doesn't has a value.
        """

        # It's intentional to cause error if no condition match.
        convertion_statements = None

        if self.is_c_bool(src.type.subtype.name):
            convertion_statements = [f"{dest} = Variant({src.name}.value());"]

        if self.is_c_int(src.type.subtype.name):
            convertion_statements = [f"{dest} = Variant((int64_t){src.name}.value());"]

        if self.is_c_float(src.type.subtype.name):
            convertion_statements = [f"{dest} = Variant((float){src.name}.value());"]

        if self.is_c_string(src.type.subtype.name):
            convertion_statements = [f"{dest} = Variant({src.name}.value().c_str());"]

        if self.is_c_opt(src.type.subtype.name):
            assert False, "Not implemented (implement if needed)"

        if self.is_c_vec(src.type.subtype.name):
            assert False, "Not implemented (implement if needed)"

        if self.is_c_map(src.type.subtype.name):
            assert False, "Not implemented (implement if needed)"

        if self.is_c_callback(src.type.subtype.name):
            assert False, "Not implemented (implement if needed)"

        if self.is_c_enum(src.type.subtype.name):
            enum = self.c_name_to_godot_name(src.type.subtype.name)
            convertion_statements = [f"{dest} = Variant(({enum}) {src.name}.value());"]

        if self.is_c_discord(src.type.subtype.name):
            type_name = self.c_type_to_godot_type(src.type.subtype, ref=False)

            convertion_statements = [
                f"{src.type.subtype.name} * t = ({src.type.subtype.name} *)memalloc(sizeof({src.type.subtype.name}));",
                f"*t = {src.name}.value();",
                f"Ref<{type_name}> t2 = memnew({type_name}{{ t }});",
                f"{dest} = Variant(t2);",
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
        # It's intentional to cause error if no condition match.
        append_statements = None

        if self.is_c_bool(src.type.subtype.name):
            append_statements = [f"{dest}.push_back(i);"]

        if self.is_c_int(src.type.subtype.name):
            append_statements = [f"{dest}.push_back((int64_t)i);"]

        if self.is_c_float(src.type.subtype.name):
            append_statements = [f"{dest}.push_back((float)i);"]

        if self.is_c_string(src.type.subtype.name):
            append_statements = [f"{dest}.push_back(String(i.c_str()));"]

        if self.is_c_opt(src.type.subtype.name):
            assert False, "Not implemented (implement if needed)"

        if self.is_c_vec(src.type.subtype.name):
            assert False, "Not implemented (implement if needed)"

        if self.is_c_map(src.type.subtype.name):
            assert False, "Not implemented (implement if needed)"

        if self.is_c_callback(src.type.subtype.name):
            assert False, "Not implemented (implement if needed)"

        if self.is_c_enum(src.type.subtype.name):
            assert False, "Not implemented (implement if needed)"

        if self.is_c_discord(src.type.subtype.name):
            obj_type = self.c_type_to_godot_type(src.type.subtype, ref=False)
            append_statements = [
                f"Ref<{obj_type}> t = memnew({obj_type}{{ &i }});",
                f"{dest}.push_back(t);",
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
        name = self.c_name_to_godot_name(src.type.name)

        statements = [
            f"{src.type.name} *t_{dest} = ({src.type.name} *)memalloc(sizeof({src.type.name}));",
            f"*t_{dest} = {src.name};",
            f"Ref<{name}> {dest} = memnew({name} {{ t_{dest} }});",
            f"",
        ]

        statements = "\n    ".join(statements)

        return statements

    ########################################################################
    ########################################################################
    # Data convertions (Godot -> C).
    ########################################################################
    ########################################################################

    def godot_var_to_c_var(self, param: TokenParam, var_name: str) -> str:
        """
        Returns statements that convert a variable from
        Godot type to C type and store it value in var_name.

        We will be using a TokenParam, which holds a C type instead
        of a Godot type, but there is no problem because we can
        deduce which will be the Godot type from it.
        """

        if self.is_c_bool(param.type.name):
            return f"bool {var_name} = {param.name};"

        if self.is_c_int(param.type.name):
            return f"int64_t {var_name} = {param.name};"

        if self.is_c_float(param.type.name):
            return f"float {var_name} = {param.name};"

        if self.is_c_string(param.type.name):
            return f"const char *{var_name} = {param.name}.utf8().get_data();"

        if self.is_c_opt(param.type.name):
            return self.godot_variant_to_c_opt(param, var_name)

        if self.is_c_vec(param.type.name):
            return self.godot_array_to_c_vec(param, var_name)

        if self.is_c_map(param.type.name):
            return self.godot_dict_to_c_map(param, var_name)

        if self.is_c_callback(param.type.name):
            assert False, "Not implemented (implement if needed)"

        if self.is_c_enum(param.type.name):
            return f"{param.type.name} {var_name} = ({param.type.name}){param.name};"

        if self.is_c_discord(param.type.name):
            return f"{param.type.name} {var_name} = *{param.name}->unwrap();"

        if self.is_c_many(param.type.name):
            assert False, "Not implemented (implement if needed)"

        assert False, (
            f'Fail to convert Godot variable "{param.type.name}" to C variable'
        )

    def godot_variant_to_c_opt(self, param: TokenParam, var_name: str) -> str:
        """
        Returns statements that convert a variable from
        Variant to C type and store it value in var_name.
        """

        variant_type = self.c_type_to_variant_type(param.type.subtype.name)
        convertion_statements = None

        if self.is_c_bool(param.type.subtype.name):
            convertion_statements = [f"{var_name} = {param.name};"]

        if self.is_c_int(param.type.subtype.name):
            convertion_statements = [f"{var_name} = {param.name};"]

        if self.is_c_float(param.type.subtype.name):
            convertion_statements = [f"{var_name} = {param.name};"]

        if self.is_c_string(param.type.subtype.name):
            convertion_statements = [
                f"{var_name} = {param.name}.stringify().utf8().get_data();"
            ]

        if self.is_c_vec(param.type.subtype.name):
            assert False, "Not implemented (implement if needed)"

        if self.is_c_map(param.type.subtype.name):
            assert False, "Not implemented (implement if needed)"

        if self.is_c_callback(param.type.subtype.name):
            assert False, "Not implemented (implement if needed)"

        if self.is_c_discord(param.type.subtype.name):
            class_type = self.c_type_to_godot_type(param.type.subtype, False)

            convertion_statements = [
                f"{class_type} t_{var_name} = Object::cast_to<{class_type}>({param.name});",
                f"auto t2_{var_name} = t_{var_name}->unwrap();",
                f"{var_name} = std::optional<{param.type.subtype.name}>{{ *t2_{var_name} }};",
            ]

        convertion_statements = "\n        ".join(convertion_statements)

        statements = [
            f"std::optional<{param.type.subtype.name}> {var_name};",
            f"",
            f"if ({param.name}.get_type() == {variant_type}) {{",
            f"    {convertion_statements}",
            f"}}",
            f"",
        ]

        statements = "\n    ".join(statements)

        return statements

    def godot_array_to_c_vec(self, param: TokenParam, var_name: str) -> str:
        append_statements = None

        if self.is_c_bool(param.type.subtype.name):
            append_statements = [f"{var_name}.append(i_{var_name});"]

        if self.is_c_int(param.type.subtype.name):
            append_statements = [f"{var_name}.append(i_{var_name});"]

        if self.is_c_float(param.type.subtype.name):
            append_statements = [f"{var_name}.append(i_{var_name});"]

        if self.is_c_string(param.type.subtype.name):
            append_statements = [f"{var_name}.append(i_{var_name}.utf8().get_data());"]

        if self.is_c_opt(param.type.subtype.name):
            assert False, "Not implemented (implement if needed)"

        if self.is_c_vec(param.type.subtype.name):
            assert False, "Not implemented (implement if needed)"

        if self.is_c_map(param.type.subtype.name):
            assert False, "Not implemented (implement if needed)"

        if self.is_c_callback(param.type.subtype.name):
            assert False, "Not implemented (implement if needed)"

        if self.is_c_enum(param.type.subtype.name):
            append_statements = [f"{var_name}.append(i_{var_name});"]

        if self.is_c_discord(param.type.subtype.name):
            append_statements = [f"{var_name}.append(i_{var_name}->unwrap());"]

        append_statements = "\n        ".join(append_statements)

        statements = [
            f"std::vector<{param.type.subtype.name}> {var_name} = std::vector<{param.type.subtype.name}>();",
            f"",
            f"for (auto i_{var_name} : {param.name}) {{",
            f"    {append_statements}",
            f"}}",
        ]

        statements = "\n    ".join(statements)

        return ""

    def godot_dict_to_c_map(self, param: TokenParam, var_name: str) -> str:
        statements = [
            # NOTE: This is a "gambiarra" because I know that we only works with std::string maps.
            f"std::unordered_map<std::string, std::string> {var_name} = std::unordered_map<std::string, std::string>();",
            f"auto k_{var_name} = {param.name}.keys();",
            f"",
            f"for (int i = 0; i < k_{var_name}.size(); i++) {{",
            f"    auto k = k_{var_name}[i];",
            f"    auto v = {param.name}[k];",
            f"    auto k_s = k.stringify().utf8().get_data();",
            f"    auto v_s = v.stringify().utf8().get_data();",
            f"    {var_name}[k_s]= v_s;",
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
            discordpp::Call *r = (discordpp::Call *)memalloc(sizeof(discordpp::Call));
            *r = client->StartCall(p0);
            return memnew(DiscordppCall{ *r });
        """

        if self.is_c_void(ret_type.name):
            return f"{call};"

        if self.is_c_bool(ret_type.name):
            return f"return {call};"

        if self.is_c_int(ret_type.name):
            return f"return {call};"

        if self.is_c_float(ret_type.name):
            return f"return {call};"

        if self.is_c_string(ret_type.name):
            return f"return String({call}.c_str());"

        if self.is_c_opt(ret_type.name):
            return self.c_opt_ret_to_godot_variant_ret(ret_type.subtype, call)

        if self.is_c_vec(ret_type.name):
            return self.c_vec_ret_to_godot_array_ret(ret_type, call)

        if self.is_c_map(ret_type.name):
            return self.c_map_ret_to_godot_dict_ret(ret_type, call)

        if self.is_c_callback(ret_type.name):
            assert False, "Not implemented (implement if needed)"

        if self.is_c_enum(ret_type.name):
            enum = self.c_name_to_godot_name(ret_type.name)
            return f"return ({enum}){call};"

        if self.is_c_discord(ret_type.name):
            return self.c_discord_ret_to_godot_discord_ret(ret_type, call)

        assert False, f'Fail to convert return from "{ret_type.name}" to Godot type'

    def c_opt_ret_to_godot_variant_ret(self, ret_type: TokenType, call: str) -> str:
        """
        Return statements that convert the SDK response,
        which is a std::optional, to Godot Variant type
        while returning this new Variant.

        Variant can hold the same value as std::optional
        or null in case the std::optional doesn't has a value.
        """

        ret_statements = None

        if self.is_c_bool(ret_type.name):
            ret_statements = ["return Variant(r.value());"]

        if self.is_c_int(ret_type.name):
            ret_statements = ["return Variant(r.value());"]

        if self.is_c_float(ret_type.name):
            ret_statements = ["return Variant(r.value());"]

        if self.is_c_string(ret_type.name):
            ret_statements = ["return Variant(r.value().c_str());"]

        if self.is_c_opt(ret_type.name):
            assert False, "Not implemented (implement if needed)"

        if self.is_c_vec(ret_type.name):
            assert False, "Not implemented (implement if needed)"

        if self.is_c_map(ret_type.name):
            assert False, "Not implemented (implement if needed)"

        if self.is_c_callback(ret_type.name):
            assert False, "Not implemented (implement if needed)"

        if self.is_c_enum(ret_type.name):
            enum = self.c_name_to_godot_name(ret_type.name)
            ret_statements = [f"return Variant(({enum}) r.value());"]

        if self.is_c_discord(ret_type.name):
            class_ = self.c_type_to_godot_type(ret_type, ref=False)

            ret_statements = [
                f"{ret_type.name} *t_r = ({ret_type.name} *)memalloc(sizeof({ret_type.name}));",
                f"*t_r = r.value();",
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
        append_statements = None

        if self.is_c_bool(vec_type.subtype.name):
            append_statements = ["t_r.push_back(i);"]

        if self.is_c_int(vec_type.subtype.name):
            append_statements = ["t_r.push_back((int64_t)i);"]

        if self.is_c_float(vec_type.subtype.name):
            append_statements = ["t_r.push_back((float)i);"]

        if self.is_c_string(vec_type.subtype.name):
            append_statements = ["t_r.push_back(String(i.c_str()));"]

        if self.is_c_opt(vec_type.subtype.name):
            assert False, "Not implemented (implement if needed)"

        if self.is_c_vec(vec_type.subtype.name):
            assert False, "Not implemented (implement if needed)"

        if self.is_c_map(vec_type.subtype.name):
            assert False, "Not implemented (implement if needed)"

        if self.is_c_callback(vec_type.subtype.name):
            assert False, "Not implemented (implement if needed)"

        if self.is_c_enum(vec_type.subtype.name):
            assert False, "Not implemented (implement if needed)"

        if self.is_c_discord(vec_type.subtype.name):
            obj_type = self.c_type_to_godot_type(vec_type.subtype, ref=False)
            append_statements = [
                f"Ref<{obj_type}> t2_r = memnew({obj_type}{{ &i }});",
                f"t_r.push_back(t2_r);",
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
        name = self.c_name_to_godot_name(ret_type.name)

        statements = [
            f"{ret_type.name} *t_r = ({ret_type.name} *)memalloc(sizeof({ret_type.name}));",
            f"*t_r = {call};",
            f"Ref<{name}> t2_r = memnew({name} {{ t_r }});",
            f"return t2_r;",
        ]

        statements = "\n    ".join(statements)

        return statements
