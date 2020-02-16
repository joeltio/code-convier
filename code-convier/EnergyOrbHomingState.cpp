#include "EnergyOrbhomingState.h"

FSM::Action EnergyOrbHomingState::update(float frametime, Component::State stateComponent)
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
		Component::Physics& orbPhysics = this->manager->getEntityComponent<Component::Physics>(orbID);
		float xDiff = playerCollidable.getCenter()[0] - orbCollidable.getCenter()[0];
		float yDiff = playerCollidable.getCenter()[1] - orbCollidable.getCenter()[1];
		float angle;

		if (xDiff > 0 && yDiff < 0)
		{
			//Player in 1st quodrant
			angle = atan(abs(yDiff) / abs(xDiff));
		}
		else if (xDiff < 0 && yDiff < 0)
		{
			//Player in 2nd quodrant
			angle = 180 - atan(abs(yDiff) / abs(xDiff));
		}
		else if (xDiff < 0 && yDiff > 0)
		{
			//Player in 3rd quodrant
			angle = 180 + atan(abs(yDiff) / abs(xDiff));
		}
		else if (xDiff > 0 && yDiff > 0)
		{
			//Player in 4th quodrant
			angle = 360 - atan(abs(yDiff) / abs(xDiff));
		}

		orbPhysics.acceleration[0] = ORB_ACCELERATION;
		orbPhysics.acceleration[1] = ORB_ACCELERATION;
	}

	return FSM::NoAction();
}