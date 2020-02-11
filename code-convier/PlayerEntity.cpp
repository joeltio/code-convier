#include "PlayerEntity.h"

namespace Entity {
	ECS::EntityIdType Player::create(ECS::Manager* manager, Graphics* graphics, float x, float y) {
		ECS::EntityIdType entityId = manager->createEntity<Player>();

		// add the physics component
		Component::Physics physicsComponent = Component::Physics();
		physicsComponent.acceleration.y = 9.81;
		manager->addComponent<Component::Physics>(entityId, physicsComponent);

		// add the transform component
		Component::Transform transformComponent = Component::Transform();
		transformComponent.x = x;
		transformComponent.y = y;
		manager->addComponent<Component::Transform>(entityId, transformComponent);

		// add the health component
		Component::Health healthComponent = Component::Health();
		healthComponent.health = 100;
		manager->addComponent<Component::Health>(entityId, healthComponent);

		// add the texture component
		Component::Texture textureComponent = Component::Texture();
		textureComponent.loadTexture(graphics, PLAYER_IMAGE);
		manager->addComponent<Component::Texture>(entityId, textureComponent);

		return entityId;
	}
}