from parser import parse_signature

method = parse_signature("uint64_t 	ClientId () const")
assert method.ret.name == "uint64_t"
assert not method.ret.is_opt
assert not method.ret.is_discord
assert not method.ret.is_enum
assert method.name == "ClientId"
assert len(method.params) == 0
assert not method.is_setter
assert method.maybe_getter

method = parse_signature("std::string 	Scopes () const")
assert method.ret.name == "std::string"
assert not method.ret.is_opt
assert not method.ret.is_discord
assert not method.ret.is_enum
assert method.name == "Scopes"
assert len(method.params) == 0
assert not method.is_setter
assert method.maybe_getter

method = parse_signature("std::optional< std::string > 	State () const")
assert method.ret.name == "std::string"
assert method.ret.is_opt
assert not method.ret.is_discord
assert not method.ret.is_enum
assert method.name == "State"
assert len(method.params) == 0
assert not method.is_setter
assert method.maybe_getter

method = parse_signature(
    "discordpp::AuthorizationCodeVerifier 	CreateAuthorizationCodeVerifier ()"
)
assert method.ret.name == "AuthorizationCodeVerifier"
assert not method.ret.is_opt
assert method.ret.is_discord
assert not method.ret.is_enum
assert method.name == "CreateAuthorizationCodeVerifier"
assert len(method.params) == 0
assert not method.is_setter
assert method.maybe_getter

method = parse_signature(
    "discordpp::AuthenticationCodeChallengeMethod 	Method () const"
)
assert method.ret.name == "AuthenticationCodeChallengeMethod"
assert not method.ret.is_opt
assert method.ret.is_discord
assert method.ret.is_enum
assert method.name == "Method"
assert len(method.params) == 0
assert not method.is_setter
assert method.maybe_getter
