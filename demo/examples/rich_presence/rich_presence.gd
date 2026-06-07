extends Node


# ATTENTION: Replace DotEnv.read_int("APPLICATION_ID") with your application ID.
# This only exist so I don't accidentally git push my ID.
var application_id: int = DotEnv.read_int("APPLICATION_ID")

var client := DiscordClient.new()


func _ready() -> void:
	client.set_application_id(application_id)
	client.add_log_callback(_on_log, DiscordLoggingSeverity.INFO)
	
	var activity := DiscordActivity.new()
	activity.set_type(DiscordActivityTypes.PLAYING)
	
	activity.set_details("Tutorial")
	activity.set_state("In Group")
	
	var timestamps := DiscordActivityTimestamps.new()
	var ten_minutes_ago: int = int(Time.get_unix_time_from_system() - 600)
	timestamps.set_start(ten_minutes_ago * 1000)
	activity.set_timestamps(timestamps)
	
	var assets := DiscordActivityAssets.new()
	assets.set_large_image("surprise")
	assets.set_large_text("Surprise")
	assets.set_small_image("happy-face")
	assets.set_small_text("Happy face")
	assets.set_invite_cover_image("thumbnail")
	activity.set_assets(assets)
	
	activity.set_details_url("https://github.com/thiagola92/discord-social-sdk/tree/main")
	activity.set_state_url("https://store.godotengine.org/asset/thiagola92/discord-social-sdk/")
	
	#var issue_button := DiscordActivityButton.new()
	#issue_button.set_label("Report bugs")
	#issue_button.set_url("https://github.com/thiagola92/discord-social-sdk/issues")
	#activity.add_button(issue_button)
	
	activity.set_status_display_type(DiscordStatusDisplayTypes.STATE)
	
	var party := DiscordActivityParty.new()
	party.set_id("party1234")
	party.set_current_size(1)
	party.set_max_size(5)
	activity.set_party(party)
	
	# Cannot be used with buttons at the moment.
	var secrets := DiscordActivitySecrets.new()
	secrets.set_join("your-join-secret")
	activity.set_secrets(secrets)
	
	client.update_rich_presence(activity, _on_rich_presence_updated)


func _process(_delta: float) -> void:
	Discord.run_callbacks()


func _on_log(message: String, severity: DiscordLoggingSeverity.Enum) -> void:
	var enum_str: String = Discord.enum_to_string(severity, DiscordLoggingSeverity.id)
	
	print("[%s] %s" % [enum_str, message])


func _on_rich_presence_updated(result: DiscordClientResult) -> void:
	if result.successful():
		print("✅ Rich presence updated!")
