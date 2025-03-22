# Discord GDExtension
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

## Develop
```bash
# Setup once
cd godot-cpp
godot --dump-extension-api
scons platform=linux custom_api_file=extension_api.json
cd ..

# Generate classes documentation
cd demo
godot --doctool ../ --gdextension-docs

# Generate GDExtension
scons platform=linux                            # Debug
scons platform=linux target=template_release    # Release
```

