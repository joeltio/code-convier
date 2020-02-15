#include "EnemyDeathState.h"

FSM::Action EnemyDeathState::update(float frametime, Component::State stateComponent)
{
	std::unordered_set<ECS::EntityIdType> enemyEntityIds = *this->manager->getEntities<Entity::Enemy>();
	for (ECS::EntityIdType enemyEntityId : enemyEntityIds) 
	{
		Component::Health& healthComponent = manager->getEntityComponent<Component::Health>(enemyEntityId);
		Component::Texture& textureComponent = manager->getEntityComponent<Component::Texture>(enemyEntityId);
		Component::Collidable& collidableComponent = manager->getEntityComponent<Component::Collidable>(enemyEntityId);
		if (healthComponent.health <= 0) {
			//insert Enemy Death Action
			textureComponent.loadTexture(graphics, SKELETON_DEAD_IMAGE);
			int energy = rand() % 20 + 1;
			int orbCount = rand() % 5 + 5;
			float orbEnergy = energy / orbCount;
			for (size_t i = 0; i < orbCount; i++)
			{
				float orbX = rand() % 30 - 15 + collidableComponent.getCenter()[0];
				float orbY = rand() % 30 - 15 + collidableComponent.getCenter()[1];
				Entity::EnergyOrb::create(this->manager, this->graphics, orbX, orbY, orbEnergy);
			}
		}
		this->manager->removeEntity<Entity::Enemy>(enemyEntityId);
	}

	return FSM::NoAction();
}
