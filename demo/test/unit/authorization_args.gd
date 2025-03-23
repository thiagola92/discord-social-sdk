extends GdUnitTestSuite


func test_default_values() -> void:
	var args := DiscordAuthorizationArgs.new()
	
	assert(args.get_client_id() == 0)
	assert(args.get_scopes() == "")
	assert(args.get_state() == null)
	assert(args.get_nonce() == null)
