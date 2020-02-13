#include "AugmentationSystem.h"

namespace System {

	void Augmentation::update(float frameTime)
	{
		// get the id of the player entity
		std::unordered_set<ECS::EntityIdType>* playerPtrs = manager->getEntities<Entity::Player>();

		for (ECS::EntityIdType id : *playerPtrs)
		{
			Component::Augmentation augmentationComponent = manager->getEntityComponent<Component::Augmentation>(id);
			Component::Health healthComponent = manager->getEntityComponent<Component::Health>(id);
			Component::Physics physicsComponent = manager->getEntityComponent<Component::Physics>(id);
			Component::Attack attackComponent = manager->getEntityComponent<Component::Attack>(id);
		}
	}

}

