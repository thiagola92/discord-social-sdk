# ruff: noqa: F541
# Remove warnings about f-strings without using variables.

from helper import clang_format, to_snake_case
from parser.tokens import TokenEnum, TokenClass, TokenFunction, TokenParam
from pathlib import Path
from builder.translator import Translator
from builder.util import get_functions_names

from template.file import (
    get_register_types_h,
    get_register_types_cpp,
    get_discord_enum_h,
    get_discord_classes_h,
    get_discord_class_cpp,
)

from template.code import (
    # register_types_cpp
    get_runtime_macro,
    get_abstract_macro,
    # discord_enum_h
    get_enum_cast,
    get_enum_bind,
    get_enum_definition,
    get_enum_value,
    # discord_classes_h
    get_class_declaration,
    get_class_definition,
    get_class_definition_global,
    get_constructor,
    get_constructor_empty,
    get_function_declaration,
    # discord_classe_cpp
    get_method,
    get_method_bind,
)


class Builder:
    """
    Write all the files from GDExtension.

    Responsible for formating the files so
    the GDExtension works properly.

    It uses another class called Translator
    to create the data convertion between
    Godot and Discord SDK.
    """

    def __init__(self, src_dir: str, tokens: list):
        self.src = Path(src_dir)
        self.tokens = self.clean_tokens(tokens)
        self.translator = Translator(self.tokens)

    def clean_tokens(self, tokens: list) -> list:
        for t in tokens.copy():
            if isinstance(t, TokenEnum):
                if t.name == "DiscordObjectState":
                    tokens.remove(t)

        return tokens

    def build_files(self):
        self.build_register_types_h()
        self.build_register_types_cpp()
        self.build_discord_enum_h()
        self.build_discord_classes_h()
        self.build_discord_classes_cpp()

    def build_register_types_h(self):
        filepath = self.src.joinpath("register_types.h")
        content = get_register_types_h()

        filepath.write_text(content)

        clang_format(filepath)

    def build_register_types_cpp(self):
        filepath = self.src.joinpath("register_types.cpp")

        # Get information.
        enums = []
        classes = [""]  # An extra to represent Discord class.

        for token in self.tokens:
            if isinstance(token, TokenEnum):
                enums.append(token.name)
            elif isinstance(token, TokenClass):
                classes.append(token.name)

                for token_enum in token.enums:
                    name = token.name + token_enum.name
                    enums.append(name)

        # Build content.
        abstract_macros = [get_abstract_macro(e) for e in enums]
        abstract_macros = "\n    ".join(abstract_macros)

        runtime_macros = [get_runtime_macro(c) for c in classes]
        runtime_macros = "\n    ".join(runtime_macros)

        content = get_register_types_cpp(
            abstract_macros=abstract_macros,
            runtime_macros=runtime_macros,
        )

        filepath.write_text(content)

        clang_format(filepath)

    def build_discord_enum_h(self):
        filepath = self.src.joinpath("discord_enum.h")

        # Get information.
        tokens: dict[str, TokenEnum] = {}

        for token in self.tokens:
            if isinstance(token, TokenEnum):
                tokens[token.name] = token
            elif isinstance(token, TokenClass):
                for token_enum in token.enums:
                    name = token.name + token_enum.name
                    tokens[name] = token_enum

        # Build content.
        definitions = []

        for enum_name in tokens:
            token = tokens[enum_name]
            binds = []
            values = []

            for name, value in token.options.items():
                binds.append(get_enum_bind(name=name))
                values.append(get_enum_value(name=name, value=value))

            binds = "\n        ".join(binds)
            values = "\n        ".join(values)

            definition = get_enum_definition(
                enum_name=enum_name,
                binds=binds,
                values=values,
            )

            definitions.append(definition)

        enums = "\n".join(definitions)

        casts = [get_enum_cast(e) for e in tokens.keys()]
        casts = "\n".join(casts)

        content = get_discord_enum_h(
            enums=enums,
            casts=casts,
        )

        filepath.write_text(content)

        clang_format(filepath)

    def build_discord_classes_h(self):
        filepath = self.src.joinpath("discord_classes.h")

        # Get informations.
        classes: list[TokenClass] = []

        for token in self.tokens:
            if isinstance(token, TokenClass):
                classes.append(token)

        # Build content.
        declarations = [get_class_declaration(c.name) for c in classes]
        declarations = [
            get_class_declaration("")
        ] + declarations  # An extra to force Discordpp class creation.

        declarations = "\n".join(declarations)
        definitions = self.build_definitions(classes=classes)

        content = get_discord_classes_h(
            declarations=declarations,
            definitions=definitions,
        )

        filepath.write_text(content)

        clang_format(filepath)

    def build_definitions(self, classes: list[TokenClass]) -> str:
        """
        Build all classes definition together,
        which will be added to "discord_classes.h".

        Having all definitions together avoid recursive includes.
        """
        definitions = [self.build_definition_global()]

        for class_ in classes:
            # Get informations.
            exist_empty_constructor = False

            for c in class_.constructors:
                if len(c.params) == 0:
                    exist_empty_constructor = True

            # Build content.
            public_constructor = ""
            private_constructor = ""

            if exist_empty_constructor:
                public_constructor = get_constructor(class_name=class_.name)
            else:
                private_constructor = get_constructor_empty(class_name=class_.name)

            methods = []

            for function in class_.functions:
                ret = self.translator.c_type_to_godot_type(function.ret)
                name = function.name
                params = self.build_params(function.params)

                method = get_function_declaration(
                    ret=ret,
                    name=name,
                    params=params,
                )

                methods.append(method)

            methods = "\n    ".join(methods)

            definition = get_class_definition(
                class_name=class_.name,
                private_constructors=private_constructor,
                methods=methods,
                public_constructors=public_constructor,
            )

            definitions.append(definition)

        definitions = "\n".join(definitions)

        return definitions

    def build_definition_global(self) -> str:
        """Build definition for class Discordpp which holds global functions."""

        # Get informations.
        functions: list[TokenFunction] = []

        for token in self.tokens:
            if isinstance(token, TokenFunction):
                functions.append(token)

        functions_names = get_functions_names(functions)

        # Build content.
        methods = []

        for function, name in functions_names.items():
            ret = self.translator.c_type_to_godot_type(function.ret)
            params = self.build_params(function.params)

            method = get_function_declaration(
                ret=ret,
                name=name,
                params=params,
            )

            methods.append(method)

        methods = "\n    ".join(methods)

        definition = get_class_definition_global(methods=methods)

        return definition

    def build_params(self, params: list[TokenParam]) -> str:
        """
        Build parameters to be used in functions or callbacks signatures.

        Is everything inside parentheses, like:
            (String e0, TypedArray<int> e1, Variant e2)
        """

        string = []

        for p in params:
            type = self.translator.c_type_to_godot_type(p.type)

            string.append(f"{type} {p.name}")

        string = ", ".join(string)

        return string

    def build_discord_classes_cpp(self):
        for token in self.tokens:
            if not isinstance(token, TokenClass):
                continue

            snake_name = to_snake_case(token.name)
            filepath = self.src.joinpath(f"discordpp_{snake_name}.cpp")
            content = self.build_class(token)

            filepath.write_text(content)

            clang_format(filepath)

        global_functions = [t for t in self.tokens if isinstance(t, TokenFunction)]
        fake_token = TokenClass("", [], [], [], global_functions)
        filepath = self.src.joinpath(f"discordpp.cpp")
        content = self.build_class(fake_token)

        filepath.write_text(content)

        clang_format(filepath)

        return

    def build_class(self, token: TokenClass, is_global: bool = False) -> str:
        methods = self.build_methods(token, is_global)
        binds = self.build_binds(token)

        content = get_discord_class_cpp(
            class_name=token.name,
            methods=methods,
            binds=binds,
        )

        return content

    def build_methods(self, class_: TokenClass, is_global: bool) -> str:
        """Build all methods from one class."""

        methods = []
        functions_names = get_functions_names(class_.functions)

        for function, name in functions_names.items():
            method = self.build_method(class_, function, name, is_global)
            methods.append(method)

        methods = "\n".join(methods)

        return methods

    def build_method(
        self,
        class_: TokenClass,
        function: TokenFunction,
        name: str,
        is_global: bool,
    ) -> str:
        """
        Build one method from the class. This is the main
        logic from this GDExtension.

        How it works:
            - Convert params from Godot type to C type
            - Call SDK method
            - If the function has return
                - Convert return to Godot type
                - Return it
        """

        ret = self.translator.c_type_to_godot_type(function.ret)
        params = self.build_params(function.params)
        statements = []

        # First step.
        for i, param in enumerate(function.params):
            if self.translator.is_c_callback(param.type.name):
                continue

            statement = self.translator.godot_var_to_c_var(param, f"p{i}")
            statements.append(statement)

        # Second step.
        call = self.build_call(class_, function, is_global)

        # Third step.
        ret_statements = self.translator.c_ret_to_godot_ret(function.ret, call)
        statements.append("\n")
        statements.append(ret_statements)

        statements = "\n    ".join(statements)

        method = get_method(
            ret=ret,
            class_name=class_.name,
            method=name,
            params=params,
            statements=statements,
        )

        return method

    def build_call(
        self,
        class_: TokenClass,
        function: TokenFunction,
        is_global: bool,
    ) -> str:
        """
        Build the call for SDK method. Example:
            client->GetChannelHandle(p0);
        Where the parameters will follow the name:
            p0, p1, p2, ..., pN

        If the parameter is a Callback, it will
        create a lambda expression instead.
        """

        params = []

        for i, param in enumerate(function.params):
            if self.translator.is_c_callback(param.type.name):
                lambda_ = self.build_lambda(class_, param)
                params.append(lambda_)
            else:
                params.append(f"p{i}")

        params = ", ".join(params)

        if is_global:
            call = f"discordpp::{function.name}({params})"
        else:
            call = f"obj->{function.name}({params})"

        return call

    def build_lambda(self, class_: TokenClass, param: TokenParam) -> str:
        """Build the lambda expression that will call a Callable."""

        # Get informations.
        callback_name = param.type.name
        _, _, callback_name = callback_name.rpartition("::")
        callback = None

        for cb in class_.callbacks:
            if cb.name == callback_name:
                callback = cb
                break

        if not callback:
            assert False, "Fail to found callback."

        # Build content.
        params = []
        statements = []
        args = []

        for i, p in enumerate(callback.params):
            params.append(f"auto {p.name}")
            statement = self.translator.c_var_to_godot_var(p, f"p{i}")
            statements.append(statement)
            args.append(f"p{i}")

        params = ", ".join(params)
        statements = "\n    ".join(statements)
        args = ", ".join(args)

        lambda_statements = [
            f"[{param.name}]({params}) {{",
            f"    {statements}",
            f"    {param.name}.call({args});",
            f"}}",
        ]

        lambda_statements = "\n    ".join(lambda_statements)

        return lambda_statements

    def build_binds(self, class_: TokenClass) -> str:
        """
        Build code expected to be inside bind_methods().

        Responsible for letting it visible for Godot users.
        """
        binds = []

        for function in class_.functions:
            params = [f'"{p.name}"' for p in function.params]
            params = ", ".join(params)
            params = f", {params}" if params else ""
            bind = get_method_bind(function.name, class_.name, params)
            binds.append(bind)

        binds = "\n".join(binds)

        return binds
