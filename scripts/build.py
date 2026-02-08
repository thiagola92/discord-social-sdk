# Responsible for building the C++ files.
from pathlib import Path
from xml.etree import ElementTree

from cli import clang_format, doctool
from name import to_snake_case, to_gdscript_class_name
from collect import (
    NamespaceInfo,
    ClassInfo,
    EnumInfo,
    collect_namespace,
)
from documentation import document_functions, document_class, document_enum
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
    forge_functions_definitions,
    forge_overloadings_definitions,
)


class Builder:
    def __init__(self, xml_dir: str, src_dir: str, doc_dir: str) -> None:
        self.src_dir = Path(src_dir)
        self.xml_dir = Path(xml_dir)
        self.doc_dir = Path(doc_dir)

        filepath = self.xml_dir.joinpath("index.xml")
        tree = ElementTree.parse(filepath)
        self.namespace_info = collect_namespace(tree, self.xml_dir)

    ######################################################################
    # Build C++ files.
    ######################################################################

    def build_files(self) -> None:
        self.build_register_types_h()
        self.build_register_types_cpp()
        self.build_discord_enum_h()
        self.build_discord_classes_h()
        self.build_discord_cpp()

        for c in self.namespace_info.classes:
            self.build_discord_class_cpp(c)

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

    def build_register_types_cpp(self) -> None:
        """
        Build register_types.cpp

        This file tells Godot which classes are abstract and
        which can be initialized (like "Example.new()").
        """

        register_abstracts = forge_register_abstracts(self.namespace_info)
        register_runtimes = forge_register_runtimes(self.namespace_info)
        filepath = self.src_dir.joinpath("register_types.cpp")
        content = get_register_types_cpp(
            register_abstracts=register_abstracts,
            register_runtimes=register_runtimes,
        )

        filepath.write_text(content)

        clang_format(filepath)

    def build_discord_enum_h(self) -> None:
        """
        Build discord_enum.h

        This file contains all classes that are used
        to represent the Discord enums.
        """

        enums_definitions = forge_enum_definitions(self.namespace_info)
        enums_casts = forge_enum_casts(self.namespace_info)
        filepath = self.src_dir.joinpath("discord_enum.h")
        content = get_discord_enum_h(
            enums_definitions=enums_definitions,
            enums_casts=enums_casts,
        )

        filepath.write_text(content)

        clang_format(filepath)

    def build_discord_classes_h(self) -> None:
        """
        Build discord_classes.h

        This file contains are classes signatures.
        """

        classes_declarations = forge_classes_declarations(self.namespace_info)
        classes_definitions = forge_classes_definitions(self.namespace_info)
        filepath = self.src_dir.joinpath("discord_classes.h")
        content = get_discord_classes_h(
            classes_declarations=classes_declarations,
            classes_definitions=classes_definitions,
        )

        filepath.write_text(content)

        clang_format(filepath)

    def build_discord_cpp(self) -> None:
        """
        Build discord.cpp

        This file contains the static functions
        from the discordpp namespace.
        """

        functions_definitions = forge_functions_definitions(self.namespace_info)
        overloadings_definitions = forge_overloadings_definitions(self.namespace_info)
        binds = forge_binds(self.namespace_info)
        filepath = self.src_dir.joinpath("discord.cpp")
        content = get_discord_class_cpp(
            class_name="",
            functions=functions_definitions,
            overloadings=overloadings_definitions,
            binds=binds,
        )

        filepath.write_text(content)

        clang_format(filepath)

    def build_discord_class_cpp(self, class_info: ClassInfo) -> None:
        """
        Build a file to represent one of the discord classes.

        This file contains all methods of the specific discord class.
        """

        functions_definitions = forge_functions_definitions(class_info)
        overloadings_definitions = forge_overloadings_definitions(class_info)
        binds = forge_binds(class_info)
        filename = to_snake_case(class_info.name)
        filepath = self.src_dir.joinpath(f"discord_{filename}.cpp")
        content = get_discord_class_cpp(
            class_name=class_info.name,
            functions=functions_definitions,
            overloadings=overloadings_definitions,
            binds=binds,
        )

        filepath.write_text(content)

        clang_format(filepath)

    ######################################################################
    # Update XML documentation.
    ######################################################################

    def update_documentations(self) -> None:
        doctool()

        self.update_namespace_class()

        for e in self.namespace_info.enums:
            self.update_enum_class(e, "")

        for c in self.namespace_info.classes:
            self.update_object_class(c)

            for e in c.enums:
                self.update_enum_class(e, c.name)

    def update_namespace_class(self) -> None:
        filename = to_gdscript_class_name("")
        filepath = self.doc_dir.joinpath(f"{filename}.xml")

        assert filepath.exists(), "Make sure to execute scons before"
        
        tree = ElementTree.parse(filepath)

        document_functions(tree, self.namespace_info)

        tree.write(filepath)

    def update_object_class(self, class_info: ClassInfo) -> None:
        filename = to_gdscript_class_name(class_info.name)
        filepath = self.doc_dir.joinpath(f"{filename}.xml")

        assert filepath.exists(), "Make sure to execute scons before"
    
        tree = ElementTree.parse(filepath)

        document_class(tree, class_info)
        document_functions(tree, class_info)

        tree.write(filepath)

    def update_enum_class(self, enum_info: EnumInfo, class_name: str = "") -> None:
        filename = to_gdscript_class_name(class_name + enum_info.name)
        filepath = self.doc_dir.joinpath(f"{filename}.xml")

        assert filepath.exists(), "Make sure to execute scons before"
        
        tree = ElementTree.parse(filepath)

        document_enum(tree, enum_info)

        tree.write(filepath)
