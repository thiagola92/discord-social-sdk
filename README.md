# Discord Social SDK
Wrapper around [Discord Social SDK](https://discord.com/developers/docs/discord-social-sdk/overview).  

# Development
This GDExtension is **all** built using Python and **nothing** should be add manually at `src`. If this is weird for you, listen to me...  

All that I want is to use the SDK from GDScript, without assuming any setup from the user, which means that I can guess all the logic behind the methods wrappers:  

```mermaid
flowchart TD
    gd_to_c[gdscript types to c types]
    return_void{return void?}
    call_method1["method(args)"]
    call_method2["auto r = method(args)"]
    c_to_gd[c type to gdscript type]

    gd_to_c-->return_void
    return_void--"yes"-->call_method1
    return_void--"no"-->call_method2
    call_method2-->c_to_gd
```

Knowing this I automated generating all the GDExtension source code through Python code, which is a language that I prefer to user when I don't have to care about low level/security/speed/anything.  

Now that you understand why everything is done through Python, let me explain what is done through Python: Parsing headers and build source code, that's it.  

```mermaid
flowchart LR
    Parse --> Build
```

When I say parse, I just mean scanning headers to collect informations about the SDK (it's nothing nothing fancy as a C/C++ parser).  

## Prerequisites
- [Godot](https://godotengine.org/)
- [SCons](https://scons.org/)
    - Debian/Ubuntu: `sudo apt install scons`
- [Python](https://www.python.org/) >=3.12
    - Included in Debian
- Clang format
    - Debian: `sudo apt install clang-format`
    - [VSCode](https://marketplace.visualstudio.com/items?itemName=xaver.clang-format)
- Discord Social SDK in `lib/` directory
    - [Download the Discord SDK for C++](https://discord.com/developers/docs/discord-social-sdk/getting-started/using-c++#step-4-download-the-discord-sdk-for-c++)
        - SDK Version: **1.0.7445**
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
├── scripts/
│   └── Python scripts
└── src/
    └── GDExtension source codes and headers
```

## Execute
```bash
# Generate GDExtension API files.
cd godot-cpp
godot --dump-extension-api
scons platform=linux custom_api_file=extension_api.json
cd ..

# Generate GDExtension source code.
python3 scripts/main.py

# Generate GDExtension documentation.
cd demo
godot --doctool ../ --gdextension-docs
cd ..

# Generate GDExtension library.
scons platform=linux                            # Debug
scons platform=linux target=template_release    # Release
```

# References
- [Discord Social SDK Overview](https://discord.com/developers/docs/discord-social-sdk/overview)
- [Discord Social SDK Rich Presence](https://discord.com/developers/docs/rich-presence/using-with-the-discord-social-sdk)
- [Discord Social SDK Reference](https://discord.com/developers/docs/social-sdk/index.html)
