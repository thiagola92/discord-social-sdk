from cleaner.cleaner import clean_content
from parser.parser import Parser
from helper import clang_format
from pathlib import Path
from builder.builder import Builder


DISCORDPP_PATH = "include/discordpp.h"
SRC_DIR = "src/"

# Used for visualization of each step.
TEMP_DIR = "scripts/temporary"
STEP0 = f"{TEMP_DIR}/0_discordpp.h"
STEP1 = f"{TEMP_DIR}/1_discordpp.txt"


if __name__ == "__main__":
    Path(SRC_DIR).mkdir(exist_ok=True)
    Path(TEMP_DIR).mkdir(exist_ok=True)

    clang_format(DISCORDPP_PATH)

    discordpp_content = Path(DISCORDPP_PATH).read_text()
    discordpp_content = clean_content(discordpp_content)
    Path(STEP0).write_text(discordpp_content)

    tokens = Parser(discordpp_content).start()
    Path(STEP1).write_text("\n".join([str(t) for t in tokens]))

    Builder(src_dir=SRC_DIR, tokens=tokens).build_files()
