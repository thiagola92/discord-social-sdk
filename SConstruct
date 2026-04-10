#!/usr/bin/env python
#
# For reference:
# - CCFLAGS are compilation flags shared between C and C++
# - CFLAGS are for C-specific compilation flags
# - CXXFLAGS are for C++-specific compilation flags
# - CPPFLAGS are for pre-processor flags
# - CPPDEFINES are for pre-processor defines
# - LINKFLAGS are for linking flags

import shutil
from pathlib import Path

GDEXTENSION_NAME = "discord_social_sdk"
DISCORD_LIB_NAME = "discord_partner_sdk"
INCLUDE_DIR = "include/"
BIN_DIR = "demo/addons/discord_social_sdk/bin/"
LIB_DIR = "lib/"
SRC_DIR = "src/"

env = SConscript("godot-cpp/SConstruct")
platform = env["platform"]
target = env["target"]
suffix = env["suffix"]
lib_suffix = env["SHLIBSUFFIX"]
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


# Copy libs to destination directory.
def copy_lib(dest_dir: str, pattern: str):
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
if platform == "android":
    env.Append(
        CPPPATH=[SRC_DIR, INCLUDE_DIR],
        LIBPATH=[f"{LIB_DIR}{platform}/aar/jni/arm64-v8a"],
        LIBS=[DISCORD_LIB_NAME],
        RPATH=["."],
    )

    copy_lib(
        f"{BIN_DIR}{platform}/",
        f"{LIB_DIR}{platform}/aar/jni/arm64-v8a/*.so",
    )

    library = env.SharedLibrary(
        f"{BIN_DIR}{platform}/lib{GDEXTENSION_NAME}{suffix}{lib_suffix}",
        source=sources,
    )
elif platform == "ios":
    env.Append(
        CPPPATH=[SRC_DIR, INCLUDE_DIR],
        LIBPATH=[f"{LIB_DIR}{platform}"],
        LIBS=[DISCORD_LIB_NAME],
        RPATH=["."],
    )

    copy_lib(
        f"{BIN_DIR}{platform}/",
        f"{LIB_DIR}{platform}/*",
    )

    if env["ios_simulator"]:
        library = env.StaticLibrary(
            f"{BIN_DIR}{platform}/lib{GDEXTENSION_NAME}.{platform}.{target}.simulator.a",
            source=sources,
        )
    else:
        library = env.StaticLibrary(
            f"{BIN_DIR}{platform}/lib{GDEXTENSION_NAME}.{platform}.{target}.a",
            source=sources,
        )
elif platform == "linux":
    env.Append(
        CPPPATH=[SRC_DIR, INCLUDE_DIR],
        LIBPATH=[f"{LIB_DIR}{platform}"],
        LIBS=[DISCORD_LIB_NAME],
        RPATH=["."],
    )

    copy_lib(
        f"{BIN_DIR}{platform}/",
        f"{LIB_DIR}{platform}/*",
    )

    library = env.SharedLibrary(
        f"{BIN_DIR}{platform}/lib{GDEXTENSION_NAME}{suffix}{lib_suffix}",
        source=sources,
    )
elif platform == "macos":
    env.Append(
        CPPPATH=[SRC_DIR, INCLUDE_DIR],
        LIBPATH=[f"{LIB_DIR}{platform}"],
        LIBS=[DISCORD_LIB_NAME],
        LINKFLAGS=["-Wl,-rpath,@loader_path"],
    )

    copy_lib(
        f"{BIN_DIR}{platform}/",
        f"{LIB_DIR}{platform}/*",
    )

    library = env.SharedLibrary(
        f"{BIN_DIR}{platform}/lib{GDEXTENSION_NAME}.{platform}.{target}.framework/lib{GDEXTENSION_NAME}.{platform}.{target}",
        source=sources,
    )
elif platform == "windows":
    env.Append(
        CPPPATH=[SRC_DIR, INCLUDE_DIR],
        LIBPATH=[f"{LIB_DIR}{platform}"],
        LIBS=[DISCORD_LIB_NAME],
        RPATH=["."],
    )

    copy_lib(
        f"{BIN_DIR}{platform}/",
        f"{LIB_DIR}{platform}/*",
    )

    library = env.SharedLibrary(
        f"{BIN_DIR}{platform}/lib{GDEXTENSION_NAME}{suffix}{lib_suffix}",
        source=sources,
    )
else:
    assert False, "Not a valid OS"

Default(library)
