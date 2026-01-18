#!/usr/bin/env python
import shutil
from pathlib import Path

env = SConscript("godot-cpp/SConstruct")

# For reference:
# - CCFLAGS are compilation flags shared between C and C++
# - CFLAGS are for C-specific compilation flags
# - CXXFLAGS are for C++-specific compilation flags
# - CPPFLAGS are for pre-processor flags
# - CPPDEFINES are for pre-processor defines
# - LINKFLAGS are for linking flags

# Tweak this if you want to use different folders, or more folders, to store your source code in.
env.Append(
    CPPPATH=["src/", "include/"],
    LIBPATH=["lib/"],
    LIBS=["discord_partner_sdk"],
)

# Dynamic linking libs.
if env["platform"] == "macos":
    env.Append(LINKFLAGS=["-Wl,-rpath,@loader_path"])
elif env["platform"] == "linux":
    env.Append(RPATH=["."])

sources = Glob("src/*.cpp")

# Include classes XML documentation.
if env["target"] in ["editor", "template_debug"]:
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
    src = list(Path("lib/").glob(pattern))

    for f in src:
        if f.is_file():
            shutil.copy(f, dest)
        elif f.is_dir():
            d = dest.joinpath(f.name)
            shutil.copytree(f, d, dirs_exist_ok=True)


# Generate library.
if env["platform"] == "macos":
    copy_lib("demo/addons/discord_social_sdk/bin/macos/", "*.dylib")

    library = env.SharedLibrary(
        "demo/addons/discord_social_sdk/bin/macos/libdiscord_social_sdk.{}.{}.framework/libdiscord_social_sdk.{}.{}".format(
            env["platform"], env["target"], env["platform"], env["target"]
        ),
        source=sources,
    )
elif env["platform"] == "ios":
    copy_lib("demo/addons/discord_social_sdk/bin/linux/", "*.xcframework")

    if env["ios_simulator"]:
        library = env.StaticLibrary(
            "demo/addons/discord_social_sdk/bin/ios/libdiscord_social_sdk.{}.{}.simulator.a".format(
                env["platform"], env["target"]
            ),
            source=sources,
        )
    else:
        library = env.StaticLibrary(
            "demo/addons/discord_social_sdk/bin/ios/libdiscord_social_sdk.{}.{}.a".format(
                env["platform"], env["target"]
            ),
            source=sources,
        )
elif env["platform"] == "linux":
    copy_lib("demo/addons/discord_social_sdk/bin/linux/", "*.so")

    library = env.SharedLibrary(
        "demo/addons/discord_social_sdk/bin/linux/libdiscord_social_sdk{}{}".format(
            env["suffix"], env["SHLIBSUFFIX"]
        ),
        source=sources,
    )
elif env["platform"] == "android":
    copy_lib("demo/addons/discord_social_sdk/bin/linux/", "*.aar")

    library = env.SharedLibrary(
        "demo/addons/discord_social_sdk/bin/android/libdiscord_social_sdk{}{}".format(
            env["suffix"], env["SHLIBSUFFIX"]
        ),
        source=sources,
    )
elif env["platform"] == "windows":
    copy_lib("demo/addons/discord_social_sdk/bin/windows/", "*.dll")
    copy_lib("demo/addons/discord_social_sdk/bin/windows/", "*.lib")

    library = env.SharedLibrary(
        "demo/addons/discord_social_sdk/bin/windows/libdiscord_social_sdk{}{}".format(
            env["suffix"], env["SHLIBSUFFIX"]
        ),
        source=sources,
    )
else:
    assert False, "Not a valid OS"

Default(library)
