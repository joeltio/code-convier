#include "EnergyOrbIdleState.h"

FSM::Action EnergyOrbIdleState::update(float frametime, Component::State stateComponent)
{
	std::unordered_set<ECS::EntityIdType> orbEntityIds = *this->manager->getEntities<Entity::EnergyOrb>();
	std::unordered_set<ECS::EntityIdType> playerEntityIds = *this->manager->getEntities<Entity::Player>();
	ECS::EntityIdType playerId;
	for (ECS::EntityIdType playerEntityId : playerEntityIds)
	{
		playerId = playerEntityId;
	}
	Component::Collidable playerCollidable = this->manager->getEntityComponent<Component::Collidable>(playerId);

	for (ECS::EntityIdType orbID : orbEntityIds) 
	{
		Component::Collidable orbCollidable = this->manager->getEntityComponent<Component::Collidable>(orbID);
		float xDiff = playerCollidable.getCenter()[0] - orbCollidable.getCenter()[0];
		float yDiff = playerCollidable.getCenter()[1] - orbCollidable.getCenter()[1];
		float distance = sqrt(abs(xDiff) + abs(yDiff));
		if (distance <= ORB_DETECTION_RANGE)
		{
			return(OrbDetectPlayerAction());
		}
	}

	return FSM::NoAction();
}