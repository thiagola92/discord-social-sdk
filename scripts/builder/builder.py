from pathlib import Path
from xml.etree import ElementTree
from xml.etree.ElementTree import Element

from helper import clang_format
from template.file.register_types_h import get_register_types_h
from template.file.register_types_cpp import get_register_types_cpp
from template.file.discord_enum_h import get_discord_enum_h
from template.file.discord_classes_h import get_discord_classes_h
from template.file.discord_class_cpp import get_discord_class_cpp
from template.code.register_types_cpp.register_abstract import get_register_abstract
from template.code.register_types_cpp.register_runtime import get_register_runtime


class Builder:
    def __init__(self, xml_dir: str, src_dir: str) -> None:
        self.src_dir = Path(src_dir)
        self.xml_dir = Path(xml_dir)

    def build_files(self) -> None:
        file = self.xml_dir.joinpath("index.xml")
        tree = ElementTree.parse(file)
        namespace = tree.find("compound[@kind='namespace']")
        classes = tree.findall("compound[@kind='class']")

        assert len(classes) > 0

        self.build_register_types_h()
        self.build_register_types_cpp(namespace, classes)
        self.build_discord_enum_h()
        self.build_discord_classes_h()
        self.build_discord_cpp()

        # for c in classes:
        #     self.build_discord_class_cpp()

    def build_register_types_h(self):
        # Build file.
        filepath = self.src_dir.joinpath("register_types.h")
        content = get_register_types_h()

        filepath.write_text(content)

        clang_format(filepath)

    def build_register_types_cpp(self, namespace: Element, classes: list[Element]):
        # Collect information.
        enums_names = namespace.findall("member[@kind='enum']/name")
        enums_names = [e.text for e in enums_names]
        enums_names = [e for e in enums_names if e != "DiscordObjectState"]  # Internal.
        enums_names = [f"Discord{e}" for e in enums_names]
        classes_names = [c.find("name") for c in classes]
        classes_names = [c.text for c in classes_names]
        classes_names = [c.removeprefix("discordpp::") for c in classes_names]
        classes_names = [f"Discord{c}" for c in classes_names]
        classes_enums_names = []

        for c in classes:
            cn = c.find("name")
            cn = cn.text
            cn = cn.removeprefix("discordpp::")
            cn = f"Discord{cn}"
            ce = c.findall("member[@kind='enum']/name")

            for e in ce:
                classes_enums_names.append(f"{cn}{e.text}")

        print(classes_enums_names)

        # Build code.
        register_abstracts = [get_register_abstract(e) for e in enums_names]
        register_abstracts += [get_register_abstract(ce) for ce in classes_enums_names]
        register_abstracts += [get_register_abstract("Discord")]
        register_abstracts = "\n".join(register_abstracts)
        register_runtimes = [get_register_runtime(c) for c in classes_names]
        register_runtimes = "\n".join(register_runtimes)

        # Build file.
        filepath = self.src_dir.joinpath("register_types.cpp")
        content = get_register_types_cpp(
            register_abstracts=register_abstracts,
            register_runtimes=register_runtimes,
        )

        filepath.write_text(content)

        clang_format(filepath)

    def build_discord_enum_h(self):
        # Build file.
        filepath = self.src_dir.joinpath("discord_enum.h")
        content = get_discord_enum_h(
            enums="",
            casts="",
        )

        filepath.write_text(content)

        clang_format(filepath)

    def build_discord_classes_h(self):
        # Build file.
        filepath = self.src_dir.joinpath("discord_classes.h")
        content = get_discord_classes_h(
            declarations="",
            definitions="",
        )

        filepath.write_text(content)

        clang_format(filepath)

    def build_discord_cpp(self):
        # Build file.
        filepath = self.src_dir.joinpath("discord.cpp")
        content = get_discord_class_cpp(
            class_name="",
            methods="",
            binds="",
        )

        filepath.write_text(content)

        clang_format(filepath)

    def build_discord_class_cpp(self):
        # Build file.
        filepath = self.src_dir.joinpath("discord_class.cpp")
        content = get_discord_class_cpp(
            class_name="",
            methods="",
            binds="",
        )

        filepath.write_text(content)

        clang_format(filepath)
