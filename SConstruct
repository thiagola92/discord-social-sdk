#!/usr/bin/env python
import os
import sys
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
env.Append(CPPPATH=["src/", "include/"], LIBS=["discord_partner_sdk"], RPATH=["."])
sources = Glob("src/*.cpp")

# Include classes XML documentation.
if env["target"] in ["editor", "template_debug"]:
    try:
        doc_data = env.GodotCPPDocData("src/gen/doc_data.gen.cpp", source=Glob("doc_classes/*.xml"))
        sources.append(doc_data)
    except AttributeError:
        print("Not including class reference as we're targeting a pre-4.3 baseline.")

# Copy Discord Social SDK lib to the same place where this lib will be.
destination_dir = Path("demo/addons/discord_social_sdk/bin/")

if env["target"] == "template_release":
    env.Append(LIBPATH=["lib/release/"])

    for f in Path("lib/release/").glob("*"):
        shutil.copy(f.absolute(), destination_dir.absolute())
else:
    env.Append(LIBPATH=["lib/debug/"])

    for f in Path("lib/debug/").glob("*"):
        shutil.copy(f.absolute(), destination_dir.absolute())

# Generate library.
if env["platform"] == "macos":
    library = env.SharedLibrary(
        "demo/addons/discord_social_sdk/bin/libdiscord_social_sdk.{}.{}.framework/libdiscord_social_sdk.{}.{}".format(
            env["platform"], env["target"], env["platform"], env["target"]
        ),
        source=sources,
    )
elif env["platform"] == "ios":
    if env["ios_simulator"]:
        library = env.StaticLibrary(
            "demo/addons/discord_social_sdk/bin/libdiscord_social_sdk.{}.{}.simulator.a".format(env["platform"], env["target"]),
            source=sources,
        )
    else:
        library = env.StaticLibrary(
            "demo/addons/discord_social_sdk/bin/libdiscord_social_sdk.{}.{}.a".format(env["platform"], env["target"]),
            source=sources,
        )
else:
    library = env.SharedLibrary(
        "demo/addons/discord_social_sdk/bin/libdiscord_social_sdk{}{}".format(env["suffix"], env["SHLIBSUFFIX"]),
        source=sources,
    )

Default(library)
