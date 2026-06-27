import sys
from pathlib import Path

from utility.cli import clang_format, doxygen, doctool
from code_gen.builder import Builder
from docs_gen.improver import Improver
from utility.clean import clean_dir


CDISCORD_PATH = Path("include/cdiscord.h")
DISCORDPP_PATH = Path("include/discordpp.h")

SRC_DIR = Path("src/")
DOC_DIR = Path("doc_classes/")
XML_DIR = Path("scripts/__xml__")

ARG_CODE = "--code"
ARG_DOCS = "--docs"


def generate_code() -> None:
    clean_dir(XML_DIR)
    clean_dir(SRC_DIR)

    clang_format(CDISCORD_PATH)
    clang_format(DISCORDPP_PATH)

    doxygen()

    builder = Builder(XML_DIR, SRC_DIR)
    builder.build_files()


def generate_docs() -> None:
    clean_dir(XML_DIR)
    clean_dir(DOC_DIR)

    clang_format(CDISCORD_PATH)
    clang_format(DISCORDPP_PATH)

    doctool()
    doxygen()

    improver = Improver(XML_DIR, DOC_DIR)
    improver.refine_documentations()


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
