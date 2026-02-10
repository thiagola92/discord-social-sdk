extends FoldableContainer

signal update_pressed(activity)


func _ready() -> void:
	for n in range(DiscordActivityTypes.HANG_STATUS + 1):
		%TypeOption.add_item(
			Discord.enum_to_string(n, DiscordActivityTypes.id), n
		)
	
	%TypeOption.select(0)
	
	for n in range(DiscordActivityPartyPrivacy.PUBLIC + 1):
		%PrivacyOption.add_item(
			Discord.enum_to_string(n, DiscordActivityPartyPrivacy.id), n
		)
	
	%PrivacyOption.select(0)
	
	%Counter.min_value = int(Time.get_unix_time_from_system())


func on_rich_presence_updated(result: DiscordClientResult) -> void:
	if result.successful():
		%Warning.text = "✔️ Updated"
	else:
		%Warning.text = "❌ Error: %s" % result.error()


func _on_update_pressed() -> void:
	var activity := DiscordActivity.new()
	var party := DiscordActivityParty.new()
	var timestamps := DiscordActivityTimestamps.new()
	
	activity.set_name(%Name.text)
	activity.set_type(%TypeOption.get_selected_id())
	activity.set_details(%Details.text)
	activity.set_state(%State.text)
	
	party.set_current_size(%CurrentSize.value)
	party.set_max_size(%MaxSize.value)
	party.set_privacy(%PrivacyOption.get_selected_id())
	party.set_id("not really important for the example")
	activity.set_party(party)
	
	if %TimestampsType.get_selected_id() == 0:
		timestamps.set_start(%Counter.value)
	elif %TimestampsType.get_selected_id() == 1:
		timestamps.set_end(%Counter.value)
	activity.set_timestamps(timestamps)
	
	if not %GameInvite.button_pressed:
		update_pressed.emit(activity)
		return
	
	var platforms := 0
	
	platforms |= 1 if %PlatformDesktop.button_pressed else 0
	platforms |= 2 if %PlatformXbox.button_pressed else 0
	platforms |= 4 if %PlatformSamsung.button_pressed else 0
	platforms |= 8 if %PlatformIOS.button_pressed else 0
	platforms |= 16 if %PlatformAndroid.button_pressed else 0
	platforms |= 32 if %PlatformEmbedded.button_pressed else 0
	platforms |= 64 if %PlatformPS4.button_pressed else 0
	platforms |= 128 if %PlatformPS5.button_pressed else 0
	
	if platforms:
		activity.set_supported_platforms(platforms)
	
	var secrets := DiscordActivitySecrets.new()
	
	secrets.set_join(%Secrets.text)
	activity.set_secrets(secrets)
	
	update_pressed.emit(activity)
