extends Control


# ATTENTION: Replace DotEnv.read_int("APPLICATION_ID") with your application ID.
# This only exist so I don't accidentally use my ID.
var APPLICATION_ID: int = DotEnv.read_int("APPLICATION_ID")

#var client := DiscordClient.new()
#
#
#func _ready() -> void:
	#var code_verifier := client.CreateAuthorizationCodeVerifier()
	#var args = DiscordAuthorizationArgs.new()
	#args.SetClientId(APPLICATION_ID)
	#args.SetScopes(DiscordClient.GetDefaultPresenceScopes())
	#args.SetCodeChallenge(code_verifier.Challenge())
	#
	#client.AddLogCallback(
		#func(message: String, severity: DiscordLoggingSeverity.Enum):
			#print("[%s] %s" % [Discord.EnumToStringLoggingSeverity(severity), message]),
		#DiscordLoggingSeverity.Info
	#)
	#
	## Just to trigger the log.
	#client.Authorize(
		#args,
		#func(_result: DiscordClientResult, _code: String, _redirectUri: String):
			#pass
	#)
#
#
#func _process(_delta: float) -> void:
	#Discord.RunCallbacks()
