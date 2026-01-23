from pathlib import Path
from xml.etree import ElementTree
from xml.etree.ElementTree import Element

from helper import clang_format
from builder.helper import collect_enums
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
        assert namespace is not None

        self.build_register_types_h()
        self.build_register_types_cpp(namespace, classes)
        self.build_discord_enum_h(namespace, classes)
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

    def build_register_types_cpp(
        self, namespace: Element, classes: list[Element]
    ) -> None:
        # Collect information.
        enums_names = namespace.findall("member[@kind='enum']/name")
        enums_names = [e.text for e in enums_names]
        enums_names = [e for e in enums_names if e != "DiscordObjectState"]  # Exclude.
        classes_names = [c.find("name") for c in classes]
        classes_names = [c.text for c in classes_names]
        classes_names = [c.removeprefix("discordpp::") for c in classes_names]
        classes_enums_names = []

        for c in classes:
            cn = c.find("name")
            cn = cn.text
            cn = cn.removeprefix("discordpp::")
            ce = c.findall("member[@kind='enum']/name")

            for e in ce:
                classes_enums_names.append(f"{cn}{e.text}")

        # Build code.
        register_abstracts = [get_register_abstract(e) for e in enums_names]
        register_abstracts += [get_register_abstract(ce) for ce in classes_enums_names]
        register_abstracts += [get_register_abstract("")]
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

    def build_discord_enum_h(self, namespace: Element, classes: list[Element]) -> None:
        # Parse XML.
        namespace_file = namespace.attrib["refid"] + ".xml"
        namespace_file = self.xml_dir.joinpath(namespace_file)
        namespace_tree = ElementTree.parse(namespace_file)
        classes_files = [c.attrib["refid"] for c in classes]
        classes_files = [f"{c}.xml" for c in classes_files]
        classes_files = [self.xml_dir.joinpath(c) for c in classes_files]
        classes_trees = [ElementTree.parse(c) for c in classes_files]

        # Collect information.
        namespace_enums = collect_enums(namespace_tree)
        classes_enums = {}

        for t in classes_trees:
            c = t.find(".//compoundname").text
            c = c.removeprefix("discordpp::")
            ce = collect_enums(t)

            if ce:
                classes_enums[c] = ce

        # Build code.
        enums_casts = [get_enum_cast(e["name"]) for e in namespace_enums]
        enums_definitions = [
            get_enum_definition(
                enum_name=e["name"],
                binds="".join([get_enum_bind(v["name"]) for v in e["values"]]),
                values="".join([v["name"] + v["init"] for v in e["values"]]),
            )
            for e in namespace_enums
        ]

        for c, ce in classes_enums.items():
            enums_casts += [get_enum_cast(c + e["name"]) for e in ce]
            enums_definitions += [
                get_enum_definition(
                    enum_name=c + e["name"],
                    binds="".join([get_enum_bind(v["name"]) for v in e["values"]]),
                    values="".join([v["name"] + v["init"] for v in e["values"]]),
                )
                for e in ce
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
