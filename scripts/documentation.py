# Responsible for updating XML documentation
# Reference: https://docs.godotengine.org/en/latest/engine_details/class_reference/index.html#doc-class-reference-primer
import re
from re import Match
from xml.etree.ElementTree import Element

from name import to_gdscript_class_name, to_gdscript_variable_name, to_constant_case
from data import FunctionInfo, ClassInfo, NamespaceInfo, EnumInfo
from collect import REFERENCES


def document_class(tree: Element, class_info: ClassInfo) -> None:
    brief_description = tree.find("brief_description")

    if class_info.short_desc and brief_description is not None:
        d = to_bbcode(class_info.short_desc)
        brief_description.text += f"{d}\n"

    description = tree.find("description")

    if class_info.long_desc and description is not None:
        d = to_bbcode(class_info.long_desc)
        description.text += f"{d}\n"


def document_functions(tree: Element, info: NamespaceInfo | ClassInfo) -> None:
    for f in info.functions:
        document_function(tree, f)


def document_function(tree: Element, function_info: FunctionInfo) -> None:
    method = tree.find(f"methods/method[@name='{function_info.gdscript_name}']")

    if method is None:
        return

    description = method.find("description")

    if description is None:
        return

    if function_info.short_desc:
        d = to_bbcode(function_info.short_desc)
        description.text += f"{d}\n\t\t\t"

    if function_info.long_desc:
        d = to_bbcode(function_info.long_desc)
        description.text += f"{d}\n\t\t\t"


def document_enum(tree: Element, enum_info: EnumInfo) -> None:
    brief_description = tree.find("brief_description")

    if enum_info.short_desc and brief_description is not None:
        d = to_bbcode(enum_info.short_desc)
        brief_description.text += f"{d}\n"

    description = tree.find("description")

    if enum_info.long_desc and description is not None:
        d = to_bbcode(enum_info.long_desc)
        description.text += f"{d}\n"

    for ev in enum_info.values:
        c = tree.find(f"constants/constant[@name='{ev.name}']")

        if c is not None:
            if ev.short_desc:
                d = to_bbcode(ev.short_desc)
                c.text += f"{d}\n\t\t"

            if ev.long_desc:
                d = to_bbcode(ev.long_desc)
                c.text += f"{d}\n\t\t"


def to_bbcode(text: str) -> str:
    # Remove unnecessary tags.
    text = re.sub(r"<para>", "", text)
    text = re.sub(r"</para>", "", text)
    text = re.sub(r"<sect.*?>", "", text)
    text = re.sub(r"</sect.*?>", "", text)
    text = re.sub(r"<itemizedlist>", "", text)
    text = re.sub(r"</itemizedlist>", "", text)
    text = re.sub(r"<orderedlist>", "", text)
    text = re.sub(r"</orderedlist>", "", text)
    text = re.sub(r"</listitem>", "", text)

    # Fix weird situations.
    text = re.sub(r"&amp;", "&", text)
    text = re.sub(r"&lt;", "<", text)
    text = re.sub(r"&gt;", ">", text)
    text = re.sub(r"(<computeroutput>)(<ulink .*?>)", r"\2\1", text)
    text = re.sub(r"(</ulink>)(</computeroutput>)", r"\2\1", text)

    # Adaptation.
    text = re.sub(r"<title>(.*?)</title>", r"[u][b]\1[/b][/u]\n", text)
    text = re.sub(r"<listitem>", r"- ", text)

    # To BBCode.
    text = re.sub(r'<ulink .*url="(.*?)">(.*?)</ulink>', r"[url=\1]\2[/url]", text)
    text = re.sub(r"<computeroutput>(.*?)</computeroutput>", r"[code]\1[/code]", text)
    text = re.sub(r"<emphasis>(.*?)</emphasis>", r"[i]\1[/i]", text)
    text = re.sub(r"<programlisting.*?>", r"[codeblock]", text, re.DOTALL)
    text = re.sub(r"</programlisting>", r"[/codeblock]", text, re.DOTALL)
    text = re.sub(
        r'<ref .*?refid="(.*?)".*?kindref="(.*?)".*?>(.*?)</ref>',
        link_class,
        text,
    )

    # Too much newline.
    text = re.sub(r"\n\n\n\n", "\n", text)
    text = re.sub(r"\n\n\n", "\n", text)
    text = re.sub(r"\n\n", "\n", text)

    return text.strip()


def link_class(match: Match) -> str:
    global REFERENCES

    refid: str = match.group(1)
    kindref: str = match.group(2)
    content: str = match.group(3)

    if kindref == "compound":
        k = REFERENCES.compound[refid]

        if k == "class":
            class_name = to_gdscript_class_name(content)
            return f"[{class_name}]"

        assert False, f"Kind not implemented: {k}"

    if kindref == "member":
        k = REFERENCES.member[refid]

        if k == "enum":
            class_name = refid.removeprefix("classdiscordpp_1_1")
            class_name = class_name.removeprefix("namespacediscordpp")
            class_name, _, _ = class_name.partition("_")
            class_name = to_gdscript_class_name(class_name)
            content = content.removeprefix("discordpp::")
            _, _, content = content.rpartition("::")
            return f"[{class_name}{content}]"

        if k == "enumvalue":
            class_name = refid.removeprefix("classdiscordpp_1_1")
            class_name = class_name.removeprefix("namespacediscordpp")
            class_name, _, _ = class_name.partition("_")
            class_name = to_gdscript_class_name(class_name)
            enum_name, _, enum_value = content.partition("::")
            enum_value = to_constant_case(enum_value)
            return f"[enum {class_name}{enum_name}.{enum_value}]"

        if k == "function":
            class_name = refid.removeprefix("classdiscordpp_1_1")
            class_name = class_name.removeprefix("namespacediscordpp")
            class_name, _, _ = class_name.partition("_")
            class_name = to_gdscript_class_name(class_name)
            content = content.removesuffix("()")
            _, _, function_name = content.rpartition("::")
            function_name = to_gdscript_variable_name(function_name)
            return f"[method {class_name}.{function_name}]"

        if k == "typedef":
            class_name = refid.removeprefix("classdiscordpp_1_1")
            class_name = class_name.removeprefix("namespacediscordpp")
            class_name, _, _ = class_name.partition("_")
            class_name = to_gdscript_class_name(class_name)
            return f"[member {class_name}.{content}]"

        assert False, f"Kind not implemented: {k}"

    assert False, f"Reference kind not implemented: {kindref}"
