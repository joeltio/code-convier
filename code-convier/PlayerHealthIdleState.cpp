#include "PlayerHealthIdleState.h"

FSM::Action PlayerHealthIdleState::update(float frametime, Component::State stateComponent)
{
	ECS::EntityIdType playerId = stateComponent.entityId;
	Component::Health& healthComponent = manager->getEntityComponent<Component::Health>(playerId);

	// reduce the health of the player first based on the frametime 
	healthComponent.health -= HEALTH_TICK * frametime;

	// check for any replenished health so player does not die 
	if (healthComponent.storedHealth > 0)
	{
		return PlayerHealthReplenishing();
	}

	if (healthComponent.health <= 0) {
		return DeadPlayerHealth();
	}

	return FSM::NoAction();
}