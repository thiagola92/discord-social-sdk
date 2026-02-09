extends HBoxContainer


const status_emoji = {
	DiscordStatusType.ONLINE: "🟢",
	DiscordStatusType.OFFLINE: "⚫",
	DiscordStatusType.BLOCKED: "🔴",
	DiscordStatusType.IDLE: "🟡",
	DiscordStatusType.DND: "🟠",
	DiscordStatusType.INVISIBLE: "⚪",
	DiscordStatusType.STREAMING: "🟣",
	DiscordStatusType.UNKNOWN: "🟤",
}

const relationship_emoji = {
	DiscordRelationshipType.NONE: "🫥",
	DiscordRelationshipType.FRIEND: "👾",
	DiscordRelationshipType.BLOCKED: "🚫",
	DiscordRelationshipType.PENDING_INCOMING: "📬",
	DiscordRelationshipType.PENDING_OUTGOING: "📨",
	DiscordRelationshipType.IMPLICIT: "👥",
	DiscordRelationshipType.SUGGESTION: "💬",
}


func setup(user: DiscordUserHandle, relationship: DiscordRelationshipHandle) -> void:
	%DisplayName.text = "" 
	%DisplayName.text += status_emoji.get(user.status(), "")
	%DisplayName.text += user.display_name()
	%DisplayName.text += " (Discord relationship: %s)" % relationship_emoji.get(
		relationship.discord_relationship_type(), ""
	)
	%DisplayName.text += " (Game relationship: %s)" % relationship_emoji.get(
		relationship.game_relationship_type(), ""
	)
