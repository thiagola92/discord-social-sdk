extends GdUnitTestSuite


func test_default_values() -> void:
	var code_challenge := DiscordAuthorizationCodeChallenge.new()
	
	assert(code_challenge.method() == DiscordAuthenticationCodeChallengeMethod.S256)
	assert(code_challenge.challenge() == "")


func test_set_valid_values() -> void:
	var code_challenge := DiscordAuthorizationCodeChallenge.new()
	var method := DiscordAuthenticationCodeChallengeMethod.S256 # Only options right now.
	var challenge := "challenge"
	
	code_challenge.set_method(method)
	code_challenge.set_challenge(challenge)
	
	assert(code_challenge.method() == method)
	assert(code_challenge.challenge() == challenge)
