#include "PlayerMovementChargingState.h"

FSM::Action PlayerMovementChargingState::update(float frametime, Component::State stateComponent)
{
	// get the charge component
	Component::Charge& chargeComponent = manager->getEntityComponent<Component::Charge>(stateComponent.entityId);
	chargeComponent.chargeTime -= frametime;
	if (chargeComponent.chargeTime >= 0)
	{
		Component::Health& healthComponent = manager->getEntityComponent<Component::Health>(stateComponent.entityId);
		healthComponent.health -= CHARGE_HEALTH_TICK;
		return FSM::NoAction();
	}
	else
	{
		return MovingPlayerMovement();
	}
}