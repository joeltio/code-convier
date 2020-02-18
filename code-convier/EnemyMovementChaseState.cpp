#include "EnemyMovementChaseState.h"

FSM::Action EnemyMovementChaseState::update(float frameTime, Component::State state) {
	// Get the line of sight component
	Component::LineOfSight& losComponent =
		this->manager->getEntityComponent<Component::LineOfSight>(state.entityId);

	// Check if there are any obstacles between the enemy and the player
	if (!losComponent.collidingWith.empty())
	{
		return FSM::NoAction();
	}

	// Check if the player is within range
	Component::EnemyAI enemyAIComponent =
		this->manager->getEntityComponent<Component::EnemyAI>(state.entityId);
	float sqDistance = losComponent.getSqDistance();
	if (sqDistance > (enemyAIComponent.chaseRange * enemyAIComponent.chaseRange))
	{
		return FSM::NoAction();
	}

	// Check if the player and the enemy are on the same platform
	ECS::EntityIdType playerId = *this->manager->getEntities<Entity::Player>()->begin();
	Component::Transform& enemyTrans = this->manager->getEntityComponent<Component::Transform>(state.entityId);
	Component::Transform& playerTrans = this->manager->getEntityComponent<Component::Transform>(playerId);
	Component::GameLevel gamelevel;
	if (!gamelevel.isOnSamePlatform(enemyTrans.x, enemyTrans.y, playerTrans.x, playerTrans.y))
	{
		return FSM::NoAction();
	}


	// Move away from the player if they are too close
	char velocitySign = 1;
	if (sqDistance < (enemyAIComponent.minRange * enemyAIComponent.minRange))
	{
		velocitySign *= -1;
	}

	// Move towards the player
	Component::Physics& physicsComponent =
		this->manager->getEntityComponent<Component::Physics>(state.entityId);
	if (losComponent.getTargetPos().x < losComponent.getEntityPos().x)
	{
		// Player is on the left of enemy
		velocitySign *= -1;
		enemyTrans.flipHorizontal = true;
	}
	else
	{
		enemyTrans.flipHorizontal = false;
	}

	// Get the attack component and check if the player is in range
	Component::Attack& attackComp =
		this->manager->getEntityComponent<Component::Attack>(state.entityId);
	float distance = losComponent.getSqDistance();
	if (distance <= attackComp.range)
	{
		// Get the current enemy's type
		ECS::Entity* ownerEntity = this->manager->getEntity(state.entityId);
		return EnemyAttackAction();
	}

	physicsComponent.velocity.x = ENEMY_SPEED * velocitySign;

	return FSM::NoAction();
};
