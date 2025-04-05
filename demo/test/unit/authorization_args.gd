extends GdUnitTestSuite


func test_default_values() -> void:
	var args := DiscordAuthorizationArgs.new()
	
	assert(args.client_id() == 0)
	assert(args.scopes() == "")
	assert(args.state() == null)
	assert(args.nonce() == null)
	assert(args.code_challenge() == null)


func test_set_valid_values() -> void:
	var args := DiscordAuthorizationArgs.new()
	var client_id := 123
	var scope := "openid sdk.social_layer_presence"
	var state := "c3ab8ff13720e8ad9047dd39466b3c8974e592c2fa383d4a3960714caef0c4f2"
	var nonce := "test"
	var code_challenge := DiscordAuthorizationCodeChallenge.new()
	code_challenge.set_challenge("challenge")
	
	args.set_client_id(client_id)
	args.set_scopes(scope)
	args.set_state(state)
	args.set_nonce(nonce)
	args.set_code_challenge(code_challenge)
	
	assert(args.client_id() == client_id)
	assert(args.scopes() == scope)
	assert(args.state() == state)
	assert(args.nonce() == nonce)
	assert(args.code_challenge() is DiscordAuthorizationCodeChallenge)
	assert(args.code_challenge().challenge() == code_challenge.challenge())
