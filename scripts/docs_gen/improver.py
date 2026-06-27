# Responsible for improving the XML docs.
#
# type: ignore
from pathlib import Path
from xml.etree import ElementTree

from utility.name import to_gdscript_class_name
from docs_gen.update import update_functions, update_class, update_enum
from utility.collect import ClassInfo, EnumInfo, collect_namespace

DOCS_ERROR = (
    "Make sure to execute scons & open godot project before generating documentations"
)


class Improver:
    def __init__(self, xml_dir: Path, doc_dir: Path) -> None:
        self.xml_dir = xml_dir
        self.doc_dir = doc_dir

        filepath = self.xml_dir.joinpath("index.xml")
        tree = ElementTree.parse(filepath)
        self.namespace_info = collect_namespace(tree, self.xml_dir)

    def improve_documentations(self) -> None:
        self.improve_namespace_class()

        for e in self.namespace_info.enums:
            self.improve_enum_class(e, "")

        for c in self.namespace_info.classes:
            self.improve_object_class(c)

            for e in c.enums:
                self.improve_enum_class(e, c.name)

    def improve_namespace_class(self) -> None:
        filename = to_gdscript_class_name("")
        filepath = self.doc_dir.joinpath(f"{filename}.xml")

        assert filepath.exists(), DOCS_ERROR

        tree = ElementTree.parse(filepath)

        update_functions(tree, self.namespace_info)

        tree.write(filepath)

    def improve_object_class(self, class_info: ClassInfo) -> None:
        filename = to_gdscript_class_name(class_info.name)
        filepath = self.doc_dir.joinpath(f"{filename}.xml")

        assert filepath.exists(), DOCS_ERROR

        tree = ElementTree.parse(filepath)

        update_class(tree, class_info)
        update_functions(tree, class_info)

        tree.write(filepath)

    def improve_enum_class(self, enum_info: EnumInfo, class_name: str = "") -> None:
        filename = to_gdscript_class_name(class_name + enum_info.name)
        filepath = self.doc_dir.joinpath(f"{filename}.xml")

        assert filepath.exists(), DOCS_ERROR

        tree = ElementTree.parse(filepath)

        update_enum(tree, enum_info)

        tree.write(filepath)
