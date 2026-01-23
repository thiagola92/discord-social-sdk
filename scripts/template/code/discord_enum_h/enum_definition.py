def get_enum_definition(enum_name: str, binds: str, values: str) -> str:
    return f"""
class Discord{enum_name} : public RefCounted {{
	GDCLASS(Discord{enum_name}, RefCounted)

private:
	Discord{enum_name}(){{}};
	~Discord{enum_name}(){{}};

protected:
	static void _bind_methods() {{
		{binds}
	}}

public:
	enum Enum {{
		{values}
	}};
}};
"""
