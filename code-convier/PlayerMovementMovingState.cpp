#include "PlayerMovementMovingState.h"

FSM::Action PlayerMovementMovingState::update(float frametime, Component::State stateComponent)
{
	ECS::EntityIdType referenceId = stateComponent.entityId; // for use later
	Component::Physics& physicsComponent = manager->getEntityComponent<Component::Physics>(referenceId);
	Component::Transform& transformComponent = manager->getEntityComponent<Component::Transform>(referenceId);

	// reset the velocity in the state before checking for input
	physicsComponent.velocity.x = 0;
	physicsComponent.velocity.y = 0;

	// check for player movement button clicks
	if (input->isKeyDown('A')) // left
	{
		transformComponent.flipHorizontal = true;
		physicsComponent.velocity.x = -PLAYER_SPEED * SCALE_FACTOR;
	}
	if (input->isKeyDown('D')) // right
	{
		transformComponent.flipHorizontal = false;
		physicsComponent.velocity.x = PLAYER_SPEED * SCALE_FACTOR;
	}
	if (input->isKeyDown('W')) // jump
	{
		// check if the entity is already jumping or not
		if (!manager->getEntityComponent<Component::Jumping>(referenceId).isJumping)
		{
			// initial velocity, slowly decelerated by gravity
			physicsComponent.velocity.y = JUMP_SPEED * SCALE_FACTOR;
		}
	}

	// mutually exclusive with charging, and walking states
	if (input->isKeyDown(LSHIFT_KEY))
	{
		Component::Health& healthComponent = manager->getEntityComponent<Component::Health>(stateComponent.entityId);
		// check for direction
		if (input->isKeyDown('A')) // left run
		{
			transformComponent.flipHorizontal = true;
			physicsComponent.velocity.x = -PLAYER_SPEED * SCALE_FACTOR * RUN_MULTIPLIER;
			healthComponent.health -= RUNNING_HEATLH_TICK;
		}

		else if (input->isKeyDown('D')) // right run
		{
			transformComponent.flipHorizontal = false;
			physicsComponent.velocity.x = PLAYER_SPEED * SCALE_FACTOR * RUN_MULTIPLIER;
			healthComponent.health -= RUNNING_HEATLH_TICK;
		}

		std::unordered_set<ECS::EntityIdType> playerRunningEntityIds = *this->manager->getEntities<Entity::PlayerRunningIcon>();
		for (ECS::EntityIdType playerRunningEntityId : playerRunningEntityIds)
		{
			Component::Animatable& animatableComponent = manager->getEntityComponent<Component::Animatable>(playerRunningEntityId);
			animatableComponent.currentFrame = 2;
		}
	}

	// mutually exclusive with running and walking
	if (input->isKeyDown('K')) // charge
	{
		transformComponent.flipHorizontal = false;
		Component::Health& healthComponent = manager->getEntityComponent<Component::Health>(stateComponent.entityId);
		Component::Charge& chargeComponent = manager->getEntityComponent<Component::Charge>(stateComponent.entityId);

		physicsComponent.velocity.x = PLAYER_CHARGE_SPEED * SCALE_FACTOR;
		healthComponent.health -= CHARGE_HEALTH_TICK;
		chargeComponent.cooldownTimer = chargeComponent.cooldown;

		std::unordered_set<ECS::EntityIdType> playerChargingEntityIds = *this->manager->getEntities<Entity::PlayerChargingIcon>();
		for (ECS::EntityIdType playerChargingEntityId : playerChargingEntityIds)
		{
			Component::Animatable& animatableComponent = manager->getEntityComponent<Component::Animatable>(playerChargingEntityId);
			animatableComponent.currentFrame = 2;
		}

		return ChargingPlayerMovement();
	}

	return FSM::NoAction();
}