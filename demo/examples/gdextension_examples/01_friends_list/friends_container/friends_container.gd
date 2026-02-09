extends FoldableContainer


const FriendContainerScene: PackedScene = preload("friend_container/friend_container.tscn")
const FriendContainer := preload("friend_container/friend_container.gd")


func setup(client: DiscordClient) -> void:
	client.set_relationship_groups_updated_callback(_on_relationship_updated.bind(client))


func update_friends_list(client: DiscordClient) -> void:
	print("Here")
	for children in %FriendsList.get_children():
		children.queue_free()
	
	var playing_game := client.get_relationships_by_group(
		DiscordRelationshipGroupType.ONLINE_PLAYING_GAME
	)
	
	var online := client.get_relationships_by_group(
		DiscordRelationshipGroupType.ONLINE_ELSEWHERE
	)
	
	var offline := client.get_relationships_by_group(
		DiscordRelationshipGroupType.OFFLINE
	)
	
	for relationship in playing_game:
		var user = relationship.user() as DiscordUserHandle
		
		if not user:
			continue
		
		var friend_container: FriendContainer = FriendContainerScene.instantiate()
		
		friend_container.setup(user, relationship)
		%FriendsList.add_child(friend_container)
	
	for relationship in online:
		var user = relationship.user() as DiscordUserHandle
		
		if not user:
			continue
		
		var friend_container: FriendContainer = FriendContainerScene.instantiate()
		
		friend_container.setup(user, relationship)
		%FriendsList.add_child(friend_container)
	
	for relationship in offline:
		var user = relationship.user() as DiscordUserHandle
		
		if not user:
			continue
		
		var friend_container: FriendContainer = FriendContainerScene.instantiate()
		
		friend_container.setup(user, relationship)
		%FriendsList.add_child(friend_container)


func _on_relationship_updated(_user_id: int, client: DiscordClient) -> void:
	update_friends_list(client)
