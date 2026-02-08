def get_class_definition_g(functions: str, overloadings: str) -> str:
    return f"""
class Discord : public RefCounted {{
	GDCLASS(Discord, RefCounted)

private:
	Discord() {{}}
protected:
	static void _bind_methods();
public:
	// Functions.
	{functions}
    
	// Overloading functions.
    {overloadings}

	~Discord() {{}}
}};
"""
