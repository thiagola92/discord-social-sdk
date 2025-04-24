extends Node


func test_default_values(_client: DiscordppClient) -> void:
	var code_challenge := DiscordppAuthorizationCodeChallenge.new()
	
	assert(code_challenge.Method() == DiscordppAuthenticationCodeChallengeMethod.S256)
	assert(code_challenge.Challenge() == "")


func test_set_valid_values(_client: DiscordppClient) -> void:
	var code_challenge := DiscordppAuthorizationCodeChallenge.new()
	var method := DiscordppAuthenticationCodeChallengeMethod.S256 # Only options right now.
	var challenge := "challenge"
	
	code_challenge.SetMethod(method)
	code_challenge.SetChallenge(challenge)
	
	assert(code_challenge.Method() == method)
	assert(code_challenge.Challenge() == challenge)
