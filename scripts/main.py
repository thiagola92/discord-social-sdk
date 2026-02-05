from pathlib import Path

from build import Builder
from help import clang_format, doxygen, clear_dir, doctool


CDISCORD_PATH = "include/cdiscord.h"
DISCORDPP_PATH = "include/discordpp.h"
SRC_DIR = "src/"
DOC_DIR = "doc_classes/"
XML_DIR = "scripts/xml"


if __name__ == "__main__":
    Path(DOC_DIR).mkdir(exist_ok=True)
    Path(SRC_DIR).mkdir(exist_ok=True)
    Path(XML_DIR).mkdir(exist_ok=True)

    clear_dir(DOC_DIR)
    clear_dir(SRC_DIR)
    clear_dir(XML_DIR)

    clang_format(CDISCORD_PATH)
    clang_format(DISCORDPP_PATH)
    doxygen()

    builder = Builder(XML_DIR, SRC_DIR, DOC_DIR)

    builder.build_files()
    doctool()
    builder.update_documentations()
