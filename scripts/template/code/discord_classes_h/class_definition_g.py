def get_class_definition_g(functions: str) -> str:
    return f"""
class Discord : public RefCounted {{
	GDCLASS(Discord, RefCounted)

private:
	Discord() {{}}
protected:
	static void _bind_methods();
public:
	{functions}

	~Discord() {{}}
}};
"""
