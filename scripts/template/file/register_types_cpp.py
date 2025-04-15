def get_register_types_cpp(runtime_macros: str, abstract_macros: str) -> str:
    return f"""
#include "register_types.h"
#include "discord_classes.h"
#include "discord_enum.h"
#include "gdextension_interface.h"
#include "godot_cpp/core/class_db.hpp"
#include "godot_cpp/core/defs.hpp"
#include "godot_cpp/godot.hpp"

using namespace godot;

void initialize_module(ModuleInitializationLevel p_level) {{
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {{
		return;
	}}

	// discord_enum.h
    {abstract_macros}

	// discord_classes.h
    {runtime_macros}
}}

void uninitialize_module(ModuleInitializationLevel p_level) {{
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {{
		return;
	}}
}}

extern "C" {{
// Initialization.
GDExtensionBool GDE_EXPORT
initialize_extension(GDExtensionInterfaceGetProcAddress p_get_proc_address,
		const GDExtensionClassLibraryPtr p_library,
		GDExtensionInitialization *r_initialization) {{
	godot::GDExtensionBinding::InitObject init_obj(p_get_proc_address, p_library,
			r_initialization);

	init_obj.register_initializer(initialize_module);
	init_obj.register_terminator(uninitialize_module);
	init_obj.set_minimum_library_initialization_level(
			MODULE_INITIALIZATION_LEVEL_SCENE);

	return init_obj.init();
}}
}}
"""
