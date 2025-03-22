# Discord GDExtension
Wrapper around [Discord Social SDK](https://discord.com/developers/docs/discord-social-sdk/overview).  

# Development
```bash
# Only once
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

