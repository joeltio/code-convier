#include "PlayerMovementChargingState.h"

FSM::Action PlayerMovementChargingState::update(float frametime, Component::State stateComponent) 
{
	// mutually exclusive with running and walking
	if (input->isKeyDown('K'))
	{
		Component::Physics physicsComponent = manager->getEntityComponent<Component::Physics>(stateComponent.entityId);
		physicsComponent.velocity.x = PLAYER_CHARGE_SPEED * SCALE_FACTOR;
	}

	return FSM::Action();
}