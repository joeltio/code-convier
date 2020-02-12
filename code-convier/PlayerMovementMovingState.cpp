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

	return FSM::NoAction();
}