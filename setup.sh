# Clone repository, submodules and only file needed.
git submodule update --init --recursive

# Manually download the DiscordSocialSdk zip to the project directory.

# Unzip libraries and headers to correct directories.
unzip DiscordSocialSdk*.zip -d /tmp/
cp -r /tmp/discord_social_sdk/* sdk/
rm -rf /tmp/discord_social_sdk

# Generate GDExtension API files.
cd godot-cpp
$GODOT --headless --dump-extension-api
scons custom_api_file=extension_api.json
cd ..

# Generate GDExtension source code.
python scripts/main.py --code

# Generate GDExtension library.
scons custom_api_file=godot-cpp/extension_api.json

# Open project, at least once, to be able to generate GDExtension documentation.
$GODOT --headless --quit ./demo/project.godot

# Generate GDExtension documentations.
python scripts/main.py --docs

# Link documentation to GDExtension library.
scons custom_api_file=godot-cpp/extension_api.json

# Open project (may need to open two times for the documentation to load).
$GODOT ./demo/project.godot
