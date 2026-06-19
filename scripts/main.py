import sys
from pathlib import Path

from cli import clang_format, doxygen
from utility import clean_dir
from build import Builder


CDISCORD_PATH = Path("include/cdiscord.h")
DISCORDPP_PATH = Path("include/discordpp.h")

SRC_DIR = Path("src/")
DOC_DIR = Path("doc_classes/")
XML_DIR = Path("scripts/xml")

ARG_CODE = "--code"
ARG_DOCS = "--docs"


def generate_code() -> None:
    clean_dir(XML_DIR)
    clean_dir(SRC_DIR)

    clang_format(CDISCORD_PATH)
    clang_format(DISCORDPP_PATH)

    doxygen()

    builder = Builder(XML_DIR, SRC_DIR, DOC_DIR)
    builder.build_files()


def generate_docs() -> None:
    clean_dir(XML_DIR)
    clean_dir(DOC_DIR)

    clang_format(CDISCORD_PATH)
    clang_format(DISCORDPP_PATH)

    doxygen()

    builder = Builder(XML_DIR, SRC_DIR, DOC_DIR)
    builder.update_documentations()


if __name__ == "__main__":
    if ARG_CODE not in sys.argv and ARG_DOCS not in sys.argv:
        print(f'Pass "{ARG_CODE}" to generate GDExtension code')
        print(f'Pass "{ARG_DOCS}" to generate GDExtension documentations')
        print("Or both to do one after other")

        sys.exit(1)

    if ARG_CODE in sys.argv:
        generate_code()

    if ARG_DOCS in sys.argv:
        generate_docs()
