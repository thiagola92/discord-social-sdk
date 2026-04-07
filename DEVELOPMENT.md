# Introduction
As I already said some times... This GDExtension is just a wrapper around [Discord Social SDK](https://discord.com/developers/docs/discord-social-sdk/overview), which means that you call the GDExtension method and it calls the SDK method.  

```mermaid
flowchart LR
    gdscript[GDScript]
    gdextension[GDExtension]
    sdk[SDK]

    gdscript --"Discord.enum_to_string()"--> gdextension
    gdextension --discordpp::EnumToString()--> sdk

    gdextension --"return"--> gdscript
    sdk --return--> gdextension
```

Basically, this GDExtension job is convert between Godot variables and C++ variables.  

For example, when you pass a [`String`](https://docs.godotengine.org/en/stable/classes/class_string.html) to a GDExtension method, it will convert to a [`std::string`](https://en.cppreference.com/w/cpp/string/basic_string.html) before passing to the SDK method. And the same convertion needs to happen when returning from SDK, that's what this GDExtension do.  

# Project Tree
```
.
├── demo/
│   └── Godot project containing the addon, examples and tests
├── doc_classes/
│   └── Project classes documentation
├── godot-cpp/
│   └── C++ bindings for GDExtension API
├── include/
│   └── Discord headers
├── lib/
│   └── Discord libs
├── scripts/
│   └── Python scripts
└── src/
    └── GDExtension source codes and headers
```

All the important code is written in Python (inside `scripts`) and this code is responsible for generating the GDExtension code (inside `src`). So let me be very clear...  

> [!CAUTION]
> No code should be manually added to `src` directory.  

# Prerequisites
The following tools were used in the project:
- [Godot](https://godotengine.org/)
- [SCons](https://scons.org/)
- [Python](https://www.python.org/) >=3.12
- [Clang](https://clang.llvm.org/)
- [Clang format](https://clang.llvm.org/docs/ClangFormat.html)
    - [VSCode](https://marketplace.visualstudio.com/items?itemName=xaver.clang-format)
- [Mingw64](https://www.mingw-w64.org/)
- [OpenJDK](https://openjdk.org/)
- [Android SDK](https://developer.android.com/tools/sdkmanager)
    - [Godot instructions](https://docs.godotengine.org/en/stable/tutorials/export/exporting_for_android.html#download-the-android-sdk)
- [Discord SDK for C++](https://discord.com/developers/docs/discord-social-sdk/getting-started/using-c++#step-4-download-the-discord-sdk-for-c++)

### Fedora Script
```bash
# Scons.
sudo dnf install python3-scons;

# Provide GNU static libraries (Fedora doesn't come with it).
sudo dnf install libstdc++-static;

# Clang.
sudo dnf install clang;

# Clang-format.
sudo dnf install clang-tools-extra;

# Cross compile for Windows.
sudo dnf install mingw64-gcc-c++;

# OpenJDK.
sudo dnf install java-latest-openjdk-devel

# Android SDK.
mkdir -p $HOME/Android/Sdk;
curl -fl https://dl.google.com/android/repository/commandlinetools-linux-14742923_latest.zip -o commandlinetools.zip;
unzip commandlinetools.zip;
mv cmdline-tools $HOME/Android/Sdk;
mkdir $HOME/Android/Sdk/comdline-tools/latest
mv $HOME/Android/Sdk/comdline-tools/bin $HOME/Android/Sdk/comdline-tools/latest;
mv $HOME/Android/Sdk/comdline-tools/lib $HOME/Android/Sdk/comdline-tools/latest;
mv $HOME/Android/Sdk/comdline-tools/NOTICE.txt $HOME/Android/Sdk/comdline-tools/latest;
mv $HOME/Android/Sdk/comdline-tools/source.properties $HOME/Android/Sdk/comdline-tools/latest;
echo "PATH=\"\$HOME/Android/SDK/cmdline-tools/latest/bin:\$PATH\"" >> $HOME/.bashrc;
sdkmanager --sdk_root=$HOME/Android/Sdk "platform-tools" "build-tools;35.0.1" "platforms;android-35" "cmdline-tools;latest" "cmake;3.10.2.4988404" "ndk;28.1.13356709"
rm commandlinetools.zip;
```

### Ubuntu script
```bash
# Scons.
sudo apt install scons;

# Clang.
sudo apt install clang;

# Clang-format.
sudo apt install clang-format;

# Cross compile for Windows.
sudo apt install mingw-w64;

# Android SDK.
mkdir -p $HOME/Android/Sdk;
curl -fl https://dl.google.com/android/repository/commandlinetools-linux-14742923_latest.zip -o commandlinetools.zip;
unzip commandlinetools.zip;
mv cmdline-tools $HOME/Android/Sdk;
mkdir $HOME/Android/Sdk/comdline-tools/latest
mv $HOME/Android/Sdk/comdline-tools/bin $HOME/Android/Sdk/comdline-tools/latest;
mv $HOME/Android/Sdk/comdline-tools/lib $HOME/Android/Sdk/comdline-tools/latest;
mv $HOME/Android/Sdk/comdline-tools/NOTICE.txt $HOME/Android/Sdk/comdline-tools/latest;
mv $HOME/Android/Sdk/comdline-tools/source.properties $HOME/Android/Sdk/comdline-tools/latest;
echo "PATH=\"\$HOME/Android/SDK/cmdline-tools/latest/bin:\$PATH\"" >> $HOME/.bashrc;
sdkmanager --sdk_root=$HOME/Android/Sdk "platform-tools" "build-tools;35.0.1" "platforms;android-35" "cmdline-tools;latest" "cmake;3.10.2.4988404" "ndk;28.1.13356709"
rm commandlinetools.zip;
```

# Step by step
> [!WARNING]
> Make sure that Godot version match with `godot-cpp` repository.  

### Setup repository
```bash
# Environment variables.
export ANDROID_HOME=$HOME/Android/Sdk # Where Android SDK is installed.

# Clone repository, submodules and only file needed.
git clone --recurse-submodules --filter=blob:none https://github.com/thiagola92/discord-social-sdk.git
cd discord-social-sdk

# Manually download the DiscordSocialSdk zip to the project directory.

# Create libraries directory.
mkdir -p lib/android
mkdir -p lib/ios
mkdir -p lib/linux
mkdir -p lib/macos
mkdir -p lib/windows

# Unzip libraries and headers to correct directories.
unzip DiscordSocialSdk*.zip -d /tmp/
cp -r /tmp/discord_social_sdk/lib/release/*.aar lib/android/
cp -r /tmp/discord_social_sdk/lib/release/*.xcframework lib/ios/
cp -r /tmp/discord_social_sdk/lib/release/*.so lib/linux/
cp -r /tmp/discord_social_sdk/lib/release/*.dylib lib/macos/
cp -r /tmp/discord_social_sdk/bin/release/*.dll lib/windows/
cp -r /tmp/discord_social_sdk/lib/release/*.lib lib/windows/
cp -r /tmp/discord_social_sdk/include/* include/
unzip lib/android/discord_partner_sdk.aar -d lib/android/aar
rm -rf /tmp/discord_social_sdk

# Generate GDExtension API files.
cd godot-cpp
godot --dump-extension-api
scons platform=linux custom_api_file=extension_api.json
cd ..

# Generate GDExtension source code.
python3 scripts/main.py --code

# Generate GDExtension library.
scons platform=linux                            # Debug
scons platform=linux target=template_release    # Release
scons platform=windows                            # Debug
scons platform=windows target=template_release    # Release

# Open project, at least once, to be able to generate GDExtension documentation.
godot ./demo/project.godot

# Generate GDExtension documentations.
python3 scripts/main.py --docs

# Link documentation to GDExtension library.
scons platform=linux                            # Debug
scons platform=linux target=template_release    # Release
scons platform=windows                            # Debug
scons platform=windows target=template_release    # Release

# Open project (may need to open two times).
godot ./demo/project.godot
```

### Repeat during development
```bash
# Generate GDExtension source code and documentations.
python3 scripts/main.py --code --docs

# Generate GDExtension library.
scons platform=linux                            # Debug
scons platform=linux target=template_release    # Release
scons platform=windows                            # Debug
scons platform=windows target=template_release    # Release

# Open project.
godot ./demo/project.godot
```

### Publish addon
```bash
# Generate ZIP file for the Asset Library.
zip -r discord_social_sdk.zip demo/addons/discord_social_sdk/**

# Manually add as assets in your Github release.
```

# References
- [Discord Social SDK Overview](https://discord.com/developers/docs/discord-social-sdk/overview)
- [Discord Social SDK Rich Presence](https://discord.com/developers/docs/rich-presence/using-with-the-discord-social-sdk)
- [Discord Social SDK Reference](https://discord.com/developers/docs/social-sdk/index.html)
- [Doxygen](https://www.doxygen.nl/)
