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
from forge import (
    forge_register_abstracts,
    forge_register_runtimes,
    forge_enum_casts,
    forge_enum_definitions,
    forge_classes_declarations,
    forge_classes_definitions,
    forge_binds,
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
        self.build_discord_cpp(namespace_info)

        # for c in classes:
        #     self.build_discord_class_cpp()

    def build_register_types_h(self):
        """
        Build register_types.h

        This file is always the same because we don't
        use any information from Discord to generate it.
        """

        filepath = self.src_dir.joinpath("register_types.h")
        content = get_register_types_h()

        filepath.write_text(content)

        clang_format(filepath)

    def build_register_types_cpp(self, namespace_info: NamespaceInfo) -> None:
        """
        Build register_types.cpp

        This file tells Godot which classes are abstract and
        which can be initialized (like "Example.new()").
        """

        register_abstracts = forge_register_abstracts(namespace_info)
        register_runtimes = forge_register_runtimes(namespace_info)
        filepath = self.src_dir.joinpath("register_types.cpp")
        content = get_register_types_cpp(
            register_abstracts=register_abstracts,
            register_runtimes=register_runtimes,
        )

        filepath.write_text(content)

        clang_format(filepath)

    def build_discord_enum_h(self, namespace_info: NamespaceInfo) -> None:
        """
        Build discord_enum.h

        This file contains all classes that are used
        to represent the Discord enums.
        """

        enums_definitions = forge_enum_definitions(namespace_info)
        enums_casts = forge_enum_casts(namespace_info)
        filepath = self.src_dir.joinpath("discord_enum.h")
        content = get_discord_enum_h(
            enums_definitions=enums_definitions,
            enums_casts=enums_casts,
        )

        filepath.write_text(content)

        clang_format(filepath)

    def build_discord_classes_h(self, namespace_info: NamespaceInfo) -> None:
        """
        Build discord_classes.h

        This file contains are classes signatures.
        """

        classes_declarations = forge_classes_declarations(namespace_info)
        classes_definitions = forge_classes_definitions(namespace_info)
        filepath = self.src_dir.joinpath("discord_classes.h")
        content = get_discord_classes_h(
            classes_declarations=classes_declarations,
            classes_definitions=classes_definitions,
        )

        filepath.write_text(content)

        clang_format(filepath)

    def build_discord_cpp(self, namespace_info: NamespaceInfo) -> None:
        """
        Build discord.cpp

        This file contains the static functions
        from the discordpp namespace.
        """

        functions_definitions = ""
        overloadings_definitions = ""
        binds = forge_binds(namespace_info)
        filepath = self.src_dir.joinpath("discord.cpp")
        content = get_discord_class_cpp(
            class_name="",
            functions=functions_definitions,
            overloadings=overloadings_definitions,
            binds=binds,
        )

        filepath.write_text(content)

        clang_format(filepath)

    def build_discord_class_cpp(self) -> None:
        """
        Build a file to represent a discord classes.
        """
        filepath = self.src_dir.joinpath("discord_class.cpp")
        content = get_discord_class_cpp(
            class_name="",
            methods="",
            binds="",
        )

        filepath.write_text(content)

        clang_format(filepath)
