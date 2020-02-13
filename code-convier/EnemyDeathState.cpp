#include "EnemyDeathState.h"

FSM::Action EnemyDeathState::update(float frametime, Component::State stateComponent)
{
	std::unordered_set<ECS::EntityIdType> enemyEntityIds = *this->manager->getEntities<Entity::Enemy>();
	for (ECS::EntityIdType enemyEntityId : enemyEntityIds) 
	{
		Component::Health& healthComponent = manager->getEntityComponent<Component::Health>(enemyEntityId);
		Component::Texture& textureComponent = manager->getEntityComponent<Component::Texture>(enemyEntityId);

		if (healthComponent.health <= 0) {
			//insert Enemy Death Action
			textureComponent.loadTexture(graphics, SKELETON_DEAD_IMAGE);
		}
		this->manager->removeEntity<Entity::Enemy>(enemyEntityId);
	}

	return FSM::NoAction();
}
