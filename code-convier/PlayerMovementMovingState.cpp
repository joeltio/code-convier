#include "PlayerMovementMovingState.h"

FSM::Action PlayerMovementMovingState::update(float frametime, Component::State stateComponent) 
{
	ECS::EntityIdType referenceId = stateComponent.entityId; // for use later

	// check for player movement button clicks
	if (input->isKeyDown('A'))
	{
		Component::Physics physicsComponent = manager->getEntityComponent<Component::Physics>(referenceId);
		physicsComponent.velocity.x = -PLAYER_SPEED * SCALE_FACTOR;
	}
	if (input->isKeyDown('D'))
	{
		Component::Physics physicsComponent = manager->getEntityComponent<Component::Physics>(referenceId);
		physicsComponent.velocity.x = PLAYER_SPEED * SCALE_FACTOR;
	}
	if (input->isKeyDown('W'))
	{
		// check if the entity is already jumping or not
		if (!manager->getEntityComponent<Component::Jumping>(referenceId).isJumping)
		{
			Component::Physics physicsComponent = manager->getEntityComponent<Component::Physics>(referenceId);
			physicsComponent.velocity.y = JUMP_SPEED * SCALE_FACTOR;
		}
	}

	return FSM::Action();
}