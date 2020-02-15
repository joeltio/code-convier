#include "PlayerMovementMovingState.h"

FSM::Action PlayerMovementMovingState::update(float frametime, Component::State stateComponent)
{
	ECS::EntityIdType referenceId = stateComponent.entityId; // for use later

	// check for player movement button clicks
	if (input->isKeyDown('A')) // left
	{
		Component::Physics physicsComponent = manager->getEntityComponent<Component::Physics>(referenceId);
		physicsComponent.velocity.x = -PLAYER_SPEED * SCALE_FACTOR;
	}
	if (input->isKeyDown('D')) // right
	{
		Component::Physics physicsComponent = manager->getEntityComponent<Component::Physics>(referenceId);
		physicsComponent.velocity.x = PLAYER_SPEED * SCALE_FACTOR;
	}
	if (input->isKeyDown('W')) // jump
	{
		// check if the entity is already jumping or not
		if (!manager->getEntityComponent<Component::Jumping>(referenceId).isJumping)
		{
			Component::Physics physicsComponent = manager->getEntityComponent<Component::Physics>(referenceId);
			physicsComponent.velocity.y = JUMP_SPEED * SCALE_FACTOR;
		}
	}

	// mutually exclusive with charging, and walking states
	if (input->isKeyDown(LSHIFT_KEY))
	{
		// check for direction
		if (input->isKeyDown('A')) // left
		{
			Component::Physics physicsComponent = manager->getEntityComponent<Component::Physics>(stateComponent.entityId);
			physicsComponent.velocity.x = -PLAYER_SPEED * SCALE_FACTOR * RUN_MULTIPLIER;
			Component::Health healthComponent = manager->getEntityComponent<Component::Health>(stateComponent.entityId);
			healthComponent.health -= RUNNING_HEATLH_TICK;
		}

		else if (input->isKeyDown('D')) // right
		{
			Component::Physics physicsComponent = manager->getEntityComponent<Component::Physics>(stateComponent.entityId);
			physicsComponent.velocity.x = PLAYER_SPEED * SCALE_FACTOR * RUN_MULTIPLIER;
			Component::Health healthComponent = manager->getEntityComponent<Component::Health>(stateComponent.entityId);
			healthComponent.health -= RUNNING_HEATLH_TICK;
		}
	}

	// mutually exclusive with running and walking
	if (input->isKeyDown('K')) // charge
	{
		Component::Physics physicsComponent = manager->getEntityComponent<Component::Physics>(stateComponent.entityId);
		physicsComponent.velocity.x = PLAYER_CHARGE_SPEED * SCALE_FACTOR;
		Component::Health healthComponent = manager->getEntityComponent<Component::Health>(stateComponent.entityId);
		healthComponent.health -= CHARGE_HEALTH_TICK;
	}


	return FSM::NoAction();
}