extends Control


# Replace with your Discord Application ID
const APPLICATION_ID = 123

# Create our Discord Client
var client := DiscordppClient.new()

func _ready() -> void:
	print("🚀 Initializing Discord SDK...\n")
	
	client.AddLogCallback(
		func(message: String, severity: DiscordppLoggingSeverity.Enum):
			print("[%s] %s" % [
				severity, message
			]),
			DiscordppLoggingSeverity.Info
	)
	
	client.SetStatusChangedCallback(
		func(status: DiscordppClientStatus.Enum, error: DiscordppClientError.Enum, errorDetail: int):
			print("🔄 Status changed: %s" % status)
			
			if status == DiscordppClientStatus.Ready:
				print("✅ Client is ready! You can now call SDK functions.")
			elif error != DiscordppClientError.None:
				print("❌ Connection Error: %s - Details: %s" % [
					error, errorDetail
				])
	)
	
	var args := DiscordppAuthorizationArgs.new()
	
	client.Authorize(args,
		func(result, code, redirectUri):
			print("Here")
	)


func _process(_delta: float) -> void:
	Discordpp.RunCallbacks()
