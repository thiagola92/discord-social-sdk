extends GdUnitTestSuite


func test_default_values() -> void:
	var code_challenge := DiscordAuthorizationCodeChallenge.new()
	
	assert(code_challenge.get_challenge() == "")


func test_set_valid_values() -> void:
	var code_challenge := DiscordAuthorizationCodeChallenge.new()
	var challenge := "challenge"
	
	code_challenge.set_challenge(challenge)
	
	assert(code_challenge.get_challenge() == challenge)
