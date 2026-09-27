extends Node


# ATTENTION: Replace DotEnv.read_int("APPLICATION_ID") with your application ID.
# This only exist so I don't accidentally git push my ID.
var application_id: int = DotEnv.read_int("APPLICATION_ID")

var client := DiscordClient.new()


func _ready() -> void:
	client.set_application_id(application_id)
	client.add_log_callback(_on_log, DiscordLoggingSeverity.INFO)
	client.register_launch_command(application_id, OS.get_executable_path())
	client.set_activity_invite_created_callback(_on_activity_invite_created)
	client.set_activity_join_callback(_on_activity_joined)


func _process(_delta: float) -> void:
	Discord.run_callbacks()


func _on_log(message: String, severity: DiscordLoggingSeverity.Enum) -> void:
	var enum_str: String = Discord.enum_to_string(severity, DiscordLoggingSeverity.id)
	
	print("[%s] %s" % [enum_str, message])


func _on_activity_invite_created(invite: DiscordActivityInvite) -> void:
	print("Activity Invite received from user: %s" % invite.sender_id())
	
	var message: DiscordMessageHandle = client.get_message_handle(invite.message_id())
	
	if message:
		print("Invite Message: %s" % message.content())
	
	client.accept_activity_invite(invite, _on_activity_invite_accepted)


func _on_activity_invite_accepted(result: DiscordClientResult, join_secret: String) -> void:
	if result.successful():
		print("Activity Invite accepted successfully! Secret: %s" % join_secret)
	else:
		print("❌ Activity Invite accept failed")


func _on_activity_joined(join_secret: String) -> void:
	print("Joined activity! Secret: %s" % join_secret)
