#include "PlayerAttackingState.h"

FSM::Action PlayerAttackingState::update(float frameTime, Component::State stateComponent) {

	// Get the direction the entity is facing, using right as the benchmark
	ECS::EntityIdType playerId = stateComponent.entityId;
	Component::Transform& transformComponent = manager->getEntityComponent<Component::Transform>(playerId);
	Component::Texture& textureComponent = manager->getEntityComponent<Component::Texture>(playerId);
	Component::Animatable& animatableComponent = manager->getEntityComponent<Component::Animatable>(playerId);
	Component::Attack& attackComponent = manager->getEntityComponent<Component::Attack>(playerId);
	int attackDirectionSign = (transformComponent.flipHorizontal) ? 1 : -1;

	// Create the hitboxes, taking into account the direction
	Component::HurtBox hitBoxComponent = Component::HurtBox();
	float playerWidth = textureComponent.totalWidth / animatableComponent.columns * transformComponent.scale;
	float playerHeight = textureComponent.totalHeight / animatableComponent.rows * transformComponent.scale;

	// Set the corners of the hitbox
	hitBoxComponent.corners.push_back(D3DXVECTOR2(
		transformComponent.x + playerWidth / 2, 
		transformComponent.y
	));

	hitBoxComponent.corners.push_back(D3DXVECTOR2(
		transformComponent.x + playerWidth / 2,
		transformComponent.y + playerHeight
	));
	
	hitBoxComponent.corners.push_back(D3DXVECTOR2(
		transformComponent.x + playerWidth / 2 + attackComponent.range * attackDirectionSign,
		transformComponent.y
	));

	hitBoxComponent.corners.push_back(D3DXVECTOR2(
		transformComponent.x + playerWidth / 2 + attackComponent.range * attackDirectionSign,
		transformComponent.y + playerHeight
	));

	// determine whether component should be destroyed on first impact
	if (!attackComponent.multiHits)
	{
		hitBoxComponent.onEnter = [playerId, attackComponent](ECS::Manager* manager, ECS::EntityIdType id) {
			// check for collision with enemy types and deal damage to them
			if (manager->getEntity(id)->isSameType<Entity::Enemy>())
			{
				manager->getEntityComponent<Component::Health>(id).health -= attackComponent.damage;
				manager->removeComponent<Component::HurtBox>(playerId);
			}
		};
	}
	else
	{
		hitBoxComponent.onStay = [playerId, attackComponent](ECS::Manager* manager, ECS::EntityIdType id, float frameTime) {
			// check for collision with enemy types and deal damage to them
			if (manager->getEntity(id)->isSameType<Entity::Enemy>())
			{
				manager->getEntityComponent<Component::Health>(id).health -= attackComponent.damage;
				manager->removeComponent<Component::HurtBox>(playerId);
			}
		};
	}
	
	// reset the attack timer
	attackComponent.cooldownTimer = attackComponent.cooldown;

	return PlayerAttackingIdle();
}
