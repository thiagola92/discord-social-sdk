def get_map(
    template1: str,
    template2: str,
    target: str,
    source: str,
    statements: str,
) -> str:
    return f"""
std::unordered_map<{template1}, {template2}> {target} = std::unordered_map<{template1}, {template2}>();
auto {target}k = {source}.keys();

for (int i = 0; i < {target}k.size(); i++) {{
    auto k = {target}k[i];
    auto v = {source}[k];
    {template1} kv;
    {template2} vv;

    {statements}

    {target}[kv] = vv;
}}
"""
