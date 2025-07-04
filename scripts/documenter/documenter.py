from pathlib import Path
from xml.etree import ElementTree
from xml.etree.ElementTree import Element
from parser.parser import TokenFunction, TokenClass
from documenter.doc_translator import DocTranslator
from template.xml import (
    get_callback_param,
    get_version,
    get_class_reference,
    get_variant_param,
    get_variant_return,
)


class Documenter:
    """
    Update all XML documentations with informations from Tokens.

    It will walk through tokens to extract informations
    and insert in their respective XML.
    """

    def __init__(self, doc_dir: str, tokens: list):
        self.doc_dir = Path(doc_dir)
        self.tokens = tokens
        self.translator = DocTranslator(self.tokens)

    def get_xml_file(self, class_name: str) -> Path:
        name = f"Discordpp{class_name}.xml"

        for file in self.doc_dir.iterdir():
            if file.is_dir():
                continue

            if file.name == name:
                return file

        return None

    def get_method_element(
        self,
        class_element: Element,
        method_name: str,
    ) -> Element | None:
        methods_element = class_element.find("methods")

        for element in methods_element:
            if element.tag != "method":
                continue

            if element.attrib["name"] == method_name:
                return element

        return None

    def update_docs(self):
        for token in self.tokens:
            if isinstance(token, TokenFunction):
                pass  # TODO
            elif isinstance(token, TokenClass):
                self.update_class(token)

    def update_class(self, class_: TokenClass):
        # Get XML.
        file = self.get_xml_file(class_.name)

        if file is None:
            return

        tree = ElementTree.parse(file)
        class_element = tree.getroot()

        # Update XML.
        self.clear_class(class_element, class_)
        self.add_class_reference(class_element, class_)
        self.add_variant_param(class_element, class_)
        self.add_callback_param(class_element, class_)
        self.add_variant_return(class_element, class_)

        # Save XML.
        tree.write(file)
        file.write_text(get_version() + file.read_text() + "\n")

    def clear_class(self, class_element: Element, class_: TokenClass):
        description_ele = class_element.find("description")
        description_ele.text = "\n\t"

        for method_ele in class_element.find("methods"):
            description_ele = method_ele.find("description")
            description_ele.text = "\n\t\t\t"

    def add_class_reference(self, class_element: Element, class_: TokenClass):
        reference = get_class_reference(class_.name)
        description_element = class_element.find("description")
        description_element.text = reference

    def add_variant_param(self, class_element: Element, class_: TokenClass):
        for function in class_.functions:
            for param in function.params:
                if self.translator.is_c_opt(param.type.name):
                    element = self.get_method_element(class_element, function.name)
                    element = element.find("description")
                    bbcode = self.translator.c_type_to_bbcode(param.type.subtype)
                    content = get_variant_param(param.name, bbcode)
                    element.text += content

    def add_callback_param(self, class_element: Element, class_: TokenClass):
        if not class_.callbacks:
            return

        # Map type name used in functions with callbacks.
        callbacks = {
            f"discordpp::{class_.name}::{cb.name}": cb for cb in class_.callbacks
        }

        for function in class_.functions:
            for param in function.params:
                if cb := callbacks.get(param.type.name):
                    element = self.get_method_element(class_element, function.name)
                    element = element.find("description")
                    params = []

                    for p in cb.params:
                        gdscript_type = self.translator.c_type_to_gdscript_type(p.type)
                        params.append(f"{p.name}: {gdscript_type}")

                    params = ", ".join(params)
                    content = get_callback_param(param_name=param.name, params=params)
                    element.text += content

    def add_variant_return(self, class_element: Element, class_: TokenClass):
        for function in class_.functions:
            if self.translator.is_c_opt(function.ret.name):
                element = self.get_method_element(class_element, function.name)
                element = element.find("description")
                bbcode = self.translator.c_type_to_bbcode(function.ret.subtype)
                content = get_variant_return(bbcode)
                element.text += content
