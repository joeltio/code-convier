#include "PlayerHealthIdleState.h"

FSM::Action PlayerHealthIdleState::update(float frametime, Component::State stateComponent)
{
	std::unordered_set<ECS::EntityIdType> playerEntityIds = *this->manager->getEntities<Entity::Player>();
	for (ECS::EntityIdType playerEntityId : playerEntityIds)
	{
		Component::Health healthComponent = manager->getEntityComponent<Component::Health>(playerEntityId);
		if (healthComponent.health <= 0) {
			return PreparePlayerDeathAction();
		}

		// reduce the health of the player
		Component::Health& healthComponent = manager->getEntityComponent<Component::Health>(playerEntityId);
		healthComponent.health -= HEALTH_TICK;
	}
	return FSM::NoAction();
}