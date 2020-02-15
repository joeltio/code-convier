#include "SkeletonAttackState.h"

void SkeletonAttackState::enter(Component::State state) {
	// Get the attack component
	Component::Attack& attackComponent =
		this->manager->getEntityComponent<Component::Attack>(state.entityId);

	// Set the initial cooldown delay
	attackComponent.initialDelayTimer = attackComponent.initialDelayTimer;
	attackComponent.cooldownTimer = attackComponent.cooldown;
}

FSM::Action SkeletonAttackState::update(float frameTime, Component::State state) {
	// Get the attack component
	Component::Attack& attackComponent =
		this->manager->getEntityComponent<Component::Attack>(state.entityId);

	// Decrement the cooldown timer
	attackComponent.initialDelayTimer -= frameTime;
	if (attackComponent.initialDelayTimer > 0)
	{
		return FSM::NoAction();
	}

	// Reset the timer
	attackComponent.initialDelayTimer = 0.0f;

	// Determine the location of the player
	// Assumes there is only one player
	ECS::EntityIdType playerEntityId = *this->manager->getEntities<Entity::Player>()->begin();
	// Get the position of the player
	Component::Transform& playerTransformComp =
		this->manager->getEntityComponent<Component::Transform>(playerEntityId);

	// Determine the location of the current enemy
	Component::Transform& enemyTransformComp =
		this->manager->getEntityComponent<Component::Transform>(state.entityId);
	// Determine the height of the enemy
	Component::Texture& enemyTextureComp =
		this->manager->getEntityComponent<Component::Texture>(state.entityId);

	float enemyHeight = enemyTextureComp.viewableRect.bottom - enemyTextureComp.viewableRect.top;
	enemyHeight *= enemyTransformComp.scale;
	float enemyWidth = enemyTextureComp.viewableRect.right - enemyTextureComp.viewableRect.left;
	enemyWidth *= enemyTransformComp.scale;

	// Create the hurtbox
	Component::HurtBox hurtBoxComponent = Component::HurtBox();

	// Determine direction of player (left of right)
	char attackDirectionSign = 1;
	if (enemyTransformComp.x > playerTransformComp.x)
	{
		attackDirectionSign = -1;
	}

	hurtBoxComponent.corners.push_back(D3DXVECTOR2(
		enemyTransformComp.x + enemyWidth/2,
		enemyTransformComp.y
	));

	hurtBoxComponent.corners.push_back(D3DXVECTOR2(
		enemyTransformComp.x + enemyWidth/2 + attackComponent.range * attackDirectionSign,
		enemyTransformComp.y
	));

	hurtBoxComponent.corners.push_back(D3DXVECTOR2(
		enemyTransformComp.x + enemyWidth/2 + attackComponent.range * attackDirectionSign,
		enemyTransformComp.y + enemyHeight
	));

	hurtBoxComponent.corners.push_back(D3DXVECTOR2(
		enemyTransformComp.x + enemyWidth/2,
		enemyTransformComp.y + enemyHeight
	));

	int damage = attackComponent.damage;
	ECS::EntityIdType ownerEntityId = state.entityId;
	hurtBoxComponent.onEnter = [damage, ownerEntityId](ECS::Manager* manager, ECS::EntityIdType id) {
		if (!manager->getEntity(id)->isSameType<Entity::Player>())
		{
			return;
		}

		// Remove health from player
		Component::Health& playerHealthComp = manager->getEntityComponent<Component::Health>(id);
		playerHealthComp.health -= damage;

		// Delete the component from the owner entity
		manager->removeComponent<Component::HurtBox>(ownerEntityId);
	};

	return ChasePlayerAction();
}

void SkeletonAttackState::exit(Component::State state) {
	// Get the attack component
	Component::Attack& attackComponent =
		this->manager->getEntityComponent<Component::Attack>(state.entityId);

	// Set the cooldown timer
	attackComponent.cooldownTimer = attackComponent.cooldown;
}