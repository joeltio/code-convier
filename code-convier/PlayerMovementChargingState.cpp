#include "PlayerMovementChargingState.h"

FSM::Action PlayerMovementChargingState::update(float frametime, Component::State stateComponent)
{
	if (input->isKeyDown('K')) // charge
	{
		Component::Physics physicsComponent = manager->getEntityComponent<Component::Physics>(stateComponent.entityId);
		physicsComponent.velocity.x = PLAYER_CHARGE_SPEED * SCALE_FACTOR;
		Component::Health healthComponent = manager->getEntityComponent<Component::Health>(stateComponent.entityId);
		healthComponent.health -= CHARGE_HEALTH_TICK;
	}

	return FSM::NoAction();
}