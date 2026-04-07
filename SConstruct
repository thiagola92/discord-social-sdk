#!/usr/bin/env python
import shutil
from pathlib import Path

env = SConscript("godot-cpp/SConstruct")
sources = Glob("src/*.cpp")

# For reference:
# - CCFLAGS are compilation flags shared between C and C++
# - CFLAGS are for C-specific compilation flags
# - CXXFLAGS are for C++-specific compilation flags
# - CPPFLAGS are for pre-processor flags
# - CPPDEFINES are for pre-processor defines
# - LINKFLAGS are for linking flags

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
    src = list(Path(".").glob(pattern))

    for f in src:
        if f.is_file():
            shutil.copy(f, dest)
        elif f.is_dir():
            d = dest.joinpath(f.name)
            shutil.copytree(f, d, dirs_exist_ok=True)


# Generate library.
if env["platform"] == "android":
    env.Append(
        CPPPATH=["src/", "include/"],
        LIBPATH=["lib/android/aar/jni/arm64-v8a"],
        LIBS=["discord_partner_sdk"],
        RPATH=["."],
    )

    copy_lib(
        "demo/addons/discord_social_sdk/bin/android/",
        "lib/android/aar/jni/arm64-v8a/*.so",
    )

    library = env.SharedLibrary(
        "demo/addons/discord_social_sdk/bin/android/libdiscord_social_sdk{}{}".format(
            env["suffix"], env["SHLIBSUFFIX"]
        ),
        source=sources,
    )
elif env["platform"] == "ios":
    env.Append(
        CPPPATH=["src/", "include/"],
        LIBPATH=["lib/ios"],
        LIBS=["discord_partner_sdk"],
        RPATH=["."],
    )

    copy_lib(
        "demo/addons/discord_social_sdk/bin/ios/",
        "lib/ios/*",
    )

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
    env.Append(
        CPPPATH=["src/", "include/"],
        LIBPATH=["lib/linux"],
        LIBS=["discord_partner_sdk"],
        RPATH=["."],
    )

    copy_lib(
        "demo/addons/discord_social_sdk/bin/linux/",
        "lib/linux/*",
    )

    library = env.SharedLibrary(
        "demo/addons/discord_social_sdk/bin/linux/libdiscord_social_sdk{}{}".format(
            env["suffix"], env["SHLIBSUFFIX"]
        ),
        source=sources,
    )
elif env["platform"] == "macos":
    env.Append(
        CPPPATH=["src/", "include/"],
        LIBPATH=["lib/macos"],
        LIBS=["discord_partner_sdk"],
        LINKFLAGS=["-Wl,-rpath,@loader_path"],
    )

    copy_lib(
        "demo/addons/discord_social_sdk/bin/macos/",
        "lib/macos/*",
    )

    library = env.SharedLibrary(
        "demo/addons/discord_social_sdk/bin/macos/libdiscord_social_sdk.{}.{}.framework/libdiscord_social_sdk.{}.{}".format(
            env["platform"], env["target"], env["platform"], env["target"]
        ),
        source=sources,
    )
elif env["platform"] == "windows":
    env.Append(
        CPPPATH=["src/", "include/"],
        LIBPATH=["lib/windows"],
        LIBS=["discord_partner_sdk"],
        RPATH=["."],
    )

    copy_lib(
        "demo/addons/discord_social_sdk/bin/windows/",
        "lib/windows/*",
    )

    library = env.SharedLibrary(
        "demo/addons/discord_social_sdk/bin/windows/libdiscord_social_sdk{}{}".format(
            env["suffix"], env["SHLIBSUFFIX"]
        ),
        source=sources,
    )
else:
    assert False, "Not a valid OS"

Default(library)
