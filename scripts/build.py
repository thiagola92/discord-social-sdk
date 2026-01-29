# Responsible for building the C++ files.
from pprint import pprint
from pathlib import Path
from xml.etree import ElementTree

from help import clang_format
from collect import NamespaceInfo, collect_namespace
from template.file.register_types_h import get_register_types_h
from template.file.register_types_cpp import get_register_types_cpp
from template.file.discord_enum_h import get_discord_enum_h
from template.file.discord_classes_h import get_discord_classes_h
from template.file.discord_class_cpp import get_discord_class_cpp
from template.code.register_types_cpp.register_abstract import get_register_abstract
from template.code.register_types_cpp.register_runtime import get_register_runtime
from template.code.discord_enum_h.enum_definition import get_enum_definition
from template.code.discord_enum_h.enum_bind import get_enum_bind
from template.code.discord_enum_h.enum_cast import get_enum_cast
from template.code.discord_classes_h.class_declaration import get_class_declaration
from template.code.discord_classes_h.class_definition import get_class_definition
from template.code.discord_classes_h.class_definition_g import get_class_definition_g
from template.code.discord_classes_h.constructor_private import get_constructor_private
from template.code.discord_classes_h.constructor_public import get_constructor_public
from template.code.discord_classes_h.function_declaration import (
    get_function_declaration,
)


class Builder:
    def __init__(self, xml_dir: str, src_dir: str) -> None:
        self.src_dir = Path(src_dir)
        self.xml_dir = Path(xml_dir)

    def build_files(self) -> None:
        file = self.xml_dir.joinpath("index.xml")
        tree = ElementTree.parse(file)
        namespace_info = collect_namespace(tree, self.xml_dir)

        self.build_register_types_h()
        self.build_register_types_cpp(namespace_info)
        self.build_discord_enum_h(namespace_info)
        self.build_discord_classes_h(namespace_info)
        # self.build_discord_cpp()

        # for c in classes:
        #     self.build_discord_class_cpp()

    def build_register_types_h(self):
        # Build file.
        filepath = self.src_dir.joinpath("register_types.h")
        content = get_register_types_h()

        filepath.write_text(content)

        clang_format(filepath)

    def build_register_types_cpp(self, namespace_info: NamespaceInfo) -> None:
        # Build code.
        register_abstracts = []
        register_runtimes = []

        for e in namespace_info.enums:
            register_abstracts.append(get_register_abstract(e.name))

        for c in namespace_info.classes:
            register_runtimes.append(get_register_runtime(c.name))

            for e in c.enums:
                register_abstracts.append(get_register_abstract(f"{c.name}{e.name}"))

        register_abstracts += [get_register_abstract("")]  # "Discord" class.
        register_abstracts = sorted(register_abstracts)
        register_abstracts = "\n".join(register_abstracts)
        register_runtimes = "\n".join(register_runtimes)

        # Build file.
        filepath = self.src_dir.joinpath("register_types.cpp")
        content = get_register_types_cpp(
            register_abstracts=register_abstracts,
            register_runtimes=register_runtimes,
        )

        filepath.write_text(content)

        clang_format(filepath)

    def build_discord_enum_h(self, namespace: NamespaceInfo) -> None:
        # Build code.
        enums_casts = [get_enum_cast(e.name) for e in namespace.enums]
        enums_definitions = [
            get_enum_definition(
                enum_name=e.name,
                binds="".join([get_enum_bind(v.name) for v in e.values]),
                values="".join([v.name + v.init for v in e.values]),
            )
            for e in namespace.enums
        ]

        for c in namespace.classes:
            enums_casts += [get_enum_cast(c.name + e.name) for e in c.enums]
            enums_definitions += [
                get_enum_definition(
                    enum_name=c.name + e.name,
                    binds="".join([get_enum_bind(v.name) for v in e.values]),
                    values="".join([v.name + v.init for v in e.values]),
                )
                for e in c.enums
            ]

        enums_casts = sorted(enums_casts)
        enums_casts = "".join(enums_casts)
        enums_definitions = sorted(enums_definitions)
        enums_definitions = "".join(enums_definitions)

        # Build file.
        filepath = self.src_dir.joinpath("discord_enum.h")
        content = get_discord_enum_h(
            enums_definitions=enums_definitions,
            enums_casts=enums_casts,
        )

        filepath.write_text(content)

        clang_format(filepath)

    def build_discord_classes_h(self, namespace_info: NamespaceInfo) -> None:
        # Build code.
        classes_declarations = []
        classes_definitions = []

        for c in namespace_info.classes:
            classes_declarations.append(get_class_declaration(c.name))
            cf = []

            for f in c.functions:
                cf.append(
                    get_function_declaration(
                        modifier="static " if f.static else "",
                        ret="void",  # TODO: Translate to GDScript.
                        name=f.gdscript_name,
                        params="",
                    )
                )

            cf = "\n".join(cf)

            if any([cc for cc in c.constructors if len(cc.params) == 0]):
                classes_definitions.append(
                    get_class_definition(
                        class_name=c.name,
                        constructor_private="",
                        functions=cf,
                        constructor_public=get_constructor_public(c.name),
                    )
                )
            else:
                classes_definitions.append(
                    get_class_definition(
                        class_name=c.name,
                        constructor_private=get_constructor_private(c.name),
                        functions=cf,
                        constructor_public="",
                    )
                )

        classes_declarations.append(get_class_declaration(""))
        classes_declarations = sorted(classes_declarations)
        classes_declarations = "".join(classes_declarations)
        classes_definitions.append(get_class_definition_g(""))  # TODO
        classes_definitions = sorted(classes_definitions)
        classes_definitions = "".join(classes_definitions)

        # Build file.
        filepath = self.src_dir.joinpath("discord_classes.h")
        content = get_discord_classes_h(
            classes_declarations=classes_declarations,
            classes_definitions=classes_definitions,
        )

        filepath.write_text(content)

        clang_format(filepath)

    def build_discord_cpp(self) -> None:
        # Build file.
        filepath = self.src_dir.joinpath("discord.cpp")
        content = get_discord_class_cpp(
            class_name="",
            methods="",
            binds="",
        )

        filepath.write_text(content)

        clang_format(filepath)

    def build_discord_class_cpp(self) -> None:
        # Build file.
        filepath = self.src_dir.joinpath("discord_class.cpp")
        content = get_discord_class_cpp(
            class_name="",
            methods="",
            binds="",
        )

        filepath.write_text(content)

        clang_format(filepath)
