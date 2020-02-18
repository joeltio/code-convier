#include "PhysicsSystem.h"

namespace System {

void Physics::update(float frameTime) {
	std::vector<Component::Physics>* physicsComponents = this->manager->getComponents<Component::Physics>();

	// Move the corresponding entity
	for (Component::Physics& physicsComponent : *physicsComponents)
	{
		// Ignore inactive components
		if (!physicsComponent.isActive)
		{
			continue;
		}

		// Get the corresponding entity's transform component
		Component::Transform& transformComponent =
			this->manager->getEntityComponent<Component::Transform>(physicsComponent.entityId);

		// Calculate new position
		physicsComponent.velocity += physicsComponent.acceleration * frameTime;
		D3DXVECTOR2 offset = physicsComponent.velocity * frameTime;
		if (offset.x == 0 && offset.y == 0)
		{
			continue;
		}

		transformComponent.x += offset.x;
		transformComponent.y += offset.y;

		// Update the collidable component (if any)
		if (this->manager->entityHasComponent<Component::Collidable>(physicsComponent.entityId))
		{
			Component::Collidable& collidableComponent =
				this->manager->getEntityComponent<Component::Collidable>(physicsComponent.entityId);

			collidableComponent.move(offset.x, offset.y);
		}
	}
}

void Physics::render() {

}

void Physics::releaseAll() {

}

}