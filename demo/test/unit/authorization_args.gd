extends Node


func test_default_values(_client: DiscordppClient) -> void:
	var args := DiscordppAuthorizationArgs.new()
	
	assert(args.ClientId() == 0)
	assert(args.Scopes() != "")
	assert(args.State() == null)
	assert(args.Nonce() == null)
	assert(args.CodeChallenge() == null)


func test_set_valid_values(_client: DiscordppClient) -> void:
	var args := DiscordppAuthorizationArgs.new()
	var client_id := 123
	var scope := "openid sdk.social_layer_presence"
	var state := "c3ab8ff13720e8ad9047dd39466b3c8974e592c2fa383d4a3960714caef0c4f2"
	var nonce := "test"
	var code_challenge := DiscordppAuthorizationCodeChallenge.new()
	code_challenge.SetChallenge("challenge")
	
	args.SetClientId(client_id)
	args.SetScopes(scope)
	args.SetState(state)
	args.SetNonce(nonce)
	args.SetCodeChallenge(code_challenge)
	
	assert(args.ClientId() == client_id)
	assert(args.Scopes() == scope)
	assert(args.State() == state)
	assert(args.Nonce() == nonce)
	assert(args.CodeChallenge() is DiscordppAuthorizationCodeChallenge)
	assert(args.CodeChallenge() != null)
	assert(args.CodeChallenge().Challenge() == code_challenge.Challenge())
