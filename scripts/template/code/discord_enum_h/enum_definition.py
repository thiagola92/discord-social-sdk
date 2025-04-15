def get_enum_definition(enum_name: str, binds: str, values: str) -> str:
    return f"""
class Discordpp{enum_name} : public RefCounted {{
	GDCLASS(Discordpp{enum_name}, RefCounted)

private:
	Discordpp{enum_name}(){{}};
	~Discordpp{enum_name}(){{}};

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
