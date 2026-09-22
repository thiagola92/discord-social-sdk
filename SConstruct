#!/usr/bin/env python
#
# For reference:
# - CCFLAGS are compilation flags shared between C and C++
# - CFLAGS are for C-specific compilation flags
# - CXXFLAGS are for C++-specific compilation flags
# - CPPFLAGS are for pre-processor flags
# - CPPDEFINES are for pre-processor defines
# - LINKFLAGS are for linking flags

import os
import sys
import shutil
from pathlib import Path

GDEXTENSION_NAME = "discord_social_sdk"
DISCORD_LIB_NAME = "discord_partner_sdk"
INCLUDE_DIR = "sdk/include/"
OUTPUT_DIR = "demo/addons/discord_social_sdk/lib/"
BIN_DIR = "sdk/bin/release/"
LIB_DIR = "sdk/lib/release/"
SRC_DIR = "src/"

os.environ["SCONS_CACHE"] = ".scons-cache/"

env = SConscript("godot-cpp/SConstruct")
platform = env["platform"]
target = env["target"]
suffix = env["suffix"]
arch = env["arch"]
lib_prefix = env.subst("$SHLIBPREFIX")
lib_suffix = env.subst("$SHLIBSUFFIX")
sources = Glob("src/*.cpp")

# Include classes XML documentation.
if target in ["editor", "template_debug"]:
    try:
        doc_data = env.GodotCPPDocData(
            "src/gen/doc_data.gen.cpp", source=Glob("doc_classes/*.xml")
        )
        sources.append(doc_data)
    except AttributeError:
        print("Not including class reference as we're targeting a pre-4.3 baseline.")


# Copy files to destination directory.
def copy_lib(pattern: str, dest_dir: str):
    Path(dest_dir).mkdir(exist_ok=True)

    dest = Path(dest_dir).absolute()
    src = list(Path(".").glob(pattern))

    for f in src:
        if f.is_file():
            shutil.copy(f, dest)
        elif f.is_dir():
            d = dest.joinpath(f.name)
            shutil.copytree(f, d, dirs_exist_ok=True)


# Generate library.
if platform == "linux":
    env.Append(
        CPPPATH=[SRC_DIR, INCLUDE_DIR],
        LIBPATH=[LIB_DIR],
        LIBS=[DISCORD_LIB_NAME],
        RPATH=["."],
    )

    copy_lib(
        f"{LIB_DIR}/*.so",
        f"{OUTPUT_DIR}{platform}/",
    )

    library = env.SharedLibrary(
        f"{OUTPUT_DIR}{platform}/{lib_prefix}{GDEXTENSION_NAME}{suffix}{lib_suffix}",
        source=sources,
    )
elif platform == "macos":  # TODO
    env.Append(
        CPPPATH=[SRC_DIR, INCLUDE_DIR],
        LIBPATH=[LIB_DIR],
        LIBS=[DISCORD_LIB_NAME],
        LINKFLAGS=["-Wl,-rpath,@loader_path"],
    )

    copy_lib(
        f"{LIB_DIR}/*.so",
        f"{OUTPUT_DIR}{platform}/",
    )

    library = env.SharedLibrary(
        f"{OUTPUT_DIR}{platform}/{lib_prefix}{GDEXTENSION_NAME}.{platform}.{target}.framework/{lib_prefix}{GDEXTENSION_NAME}.{platform}.{target}",
        source=sources,
    )
elif platform == "windows":
    env.Append(
        CPPPATH=[SRC_DIR, INCLUDE_DIR],
        LIBPATH=[LIB_DIR, BIN_DIR],
        LIBS=[DISCORD_LIB_NAME],
        RPATH=["."],
    )

    copy_lib(
        f"{LIB_DIR}/*.lib",
        f"{OUTPUT_DIR}/",
    )

    copy_lib(
        f"{BIN_DIR}/*.dll",
        f"{OUTPUT_DIR}/",
    )

    library = env.SharedLibrary(
        f"{OUTPUT_DIR}{platform}/{GDEXTENSION_NAME}{suffix}{lib_suffix}",
        source=sources,
    )
else:
    print(f"No support for this operating system: {platform}", file=sys.stderr)
    sys.exit(1)

Default(library)
