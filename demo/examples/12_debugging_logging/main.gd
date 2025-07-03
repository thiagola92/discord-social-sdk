extends Control


# ATTENTION: Replace DotEnv.read_int("APPLICATION_ID") with your application ID.
# This only exist so I don't accidentally use my ID.
var APPLICATION_ID: int = DotEnv.read_int("APPLICATION_ID")

var client := DiscordppClient.new()


func _ready() -> void:
	var code_verifier := client.CreateAuthorizationCodeVerifier()
	var args = DiscordppAuthorizationArgs.new()
	args.SetClientId(APPLICATION_ID)
	args.SetScopes(DiscordppClient.GetDefaultPresenceScopes())
	args.SetCodeChallenge(code_verifier.Challenge())
	
	client.AddLogCallback(
		func(message: String, severity: DiscordppLoggingSeverity.Enum):
			print("[%s] %s" % [Discordpp.EnumToString20(severity), message]),
		DiscordppLoggingSeverity.Info
	)
	
	# Just to trigger the log.
	client.Authorize(
		args,
		func(_result: DiscordppClientResult, _code: String, _redirectUri: String):
			pass
	)


func _process(_delta: float) -> void:
	Discordpp.RunCallbacks()
