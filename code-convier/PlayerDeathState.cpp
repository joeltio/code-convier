#include "PlayerDeathState.h"

FSM::Action PlayerDeathState::update(float frametime)
{
	std::unordered_set<ECS::EntityIdType> playerEntityIds = *this->manager->getEntities<Entity::Player>();
	for (ECS::EntityIdType playerEntityId : playerEntityIds)
	{
		this->manager->removeEntity<Entity::Player>(playerEntityId);
	}
	return PreparePlayerDeathAction();
}
