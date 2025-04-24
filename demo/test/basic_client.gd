class_name BasicClient
extends RefCounted


static var APPLICATION_ID := DotEnv.read_int("APPLICATION_ID")


static func get_client() -> DiscordppClient:
	var client := DiscordppClient.new()
	var code_verifier := client.CreateAuthorizationCodeVerifier()
	var args := DiscordppAuthorizationArgs.new()
	
	args.SetClientId(APPLICATION_ID)
	args.SetScopes(DiscordppClient.GetDefaultPresenceScopes())
	args.SetCodeChallenge(code_verifier.Challenge())
	
	client.Authorize(args,
		func(result: DiscordppClientResult, code: String, redirectUri: String):
			assert(result.Successful())
			assert(not code.is_empty())
			assert(not redirectUri.is_empty())
			
			client.GetToken(APPLICATION_ID, code, code_verifier.Verifier(), redirectUri,
				func(
					result: DiscordppClientResult,
					accessToken: String,
					refreshToken: String,
					tokenType: DiscordppAuthorizationTokenType.Enum,
					expiresIn: int,
					scopes: String
				):
					assert(result.Successful())
					assert(not accessToken.is_empty())
					assert(not refreshToken.is_empty())
					assert(expiresIn > 0)
					
					client.UpdateToken(
						tokenType,
						accessToken,
						func(result: DiscordppClientResult):
							assert(result.Successful())
							client.Connect()
					)
			)
	)
	
	return client
