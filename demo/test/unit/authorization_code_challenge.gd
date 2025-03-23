extends GdUnitTestSuite


func test_default_values() -> void:
	var code_challenge := DiscordAuthorizationCodeChallenge.new()
	
	assert(code_challenge.get_challenge() == "")
