#include "PlayerHealthReplenishingState.h"

FSM::Action PlayerHealthReplenishingState::update(float frametime, Component::State stateComponent)
{
	ECS::EntityIdType playerId = stateComponent.entityId;
	Component::Health healthComponent = manager->getEntityComponent<Component::Health>(playerId);

	// ignore the damage taken when recovering health
	healthComponent.health += healthComponent.storedHealth;

	return IdlePlayerHealth();
}