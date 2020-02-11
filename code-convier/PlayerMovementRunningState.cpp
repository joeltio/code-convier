#include "PlayerMovementRunningState.h"

FSM::Action PlayerMovementRunningState::update(float frametime, Component::State stateComponent)
{
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

	return FSM::Action();
}