#include "PlayerHealthIdleState.h"

FSM::Action PlayerHealthIdleState::update(float frametime, Component::State stateComponent)
{
	// reduce the health of the player
	Component::Health healthComponent = manager->getEntityComponent<Component::Health>(stateComponent.entityId);
	healthComponent.health -= HEALTH_TICK;

	return FSM::NoAction();
}