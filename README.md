# Discord Social SDK
Wrapper around [Discord Social SDK](https://discord.com/developers/docs/discord-social-sdk/overview).  

# Development

## Prerequisites
- [Godot](https://godotengine.org/)
- [SCons](https://scons.org/)
    - Debian/Ubuntu: `sudo apt install scons`
- Discord Social SDK in `lib/` directory
    - [Download the Discord SDK for C++](https://discord.com/developers/docs/discord-social-sdk/getting-started/using-c++#step-4-download-the-discord-sdk-for-c++)
    - Extract files from:
        - `discord_social_sdk/lib/debug/` to `lib/debug/`
        - `discord_social_sdk/bin/debug/` to `lib/debug/`
        - `discord_social_sdk/lib/release/` to `lib/release/`
        - `discord_social_sdk/bin/release/` to `lib/release/`

## Tree
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
└── src/
    └── Project source code and headers
```

## Setup
Generate GDExtension API files.

```bash
cd godot-cpp
godot --dump-extension-api
scons platform=linux custom_api_file=extension_api.json
cd ..
```

## Generate Documentation
Execute to create/update/delete XMLs with classes documentation.

```bash
cd demo
godot --doctool ../ --gdextension-docs
cd ..
```

## Generate GDExtension
Execute to generate the GDExtension.

```bash
scons platform=linux                            # Debug
scons platform=linux target=template_release    # Release
```

# References
- [Discord Social SDK Overview](https://discord.com/developers/docs/discord-social-sdk/overview)
- [Discord Social SDK Rich Presence](https://discord.com/developers/docs/rich-presence/using-with-the-discord-social-sdk)
- [Discord Social SDK Reference](https://discord.com/developers/docs/social-sdk/index.html)