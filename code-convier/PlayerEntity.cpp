#include "PlayerEntity.h"

namespace Entity {
	ECS::EntityIdType Player::create(ECS::Manager* manager, Graphics* graphics, float x, float y) {
		ECS::EntityIdType entityId = manager->createEntity<Player>();

		// add the physics component
		Component::Physics physicsComponent = Component::Physics();
		physicsComponent.acceleration.y = 9.81f;
		manager->addComponent<Component::Physics>(entityId, physicsComponent);

		// add the transform component
		Component::Transform transformComponent = Component::Transform();
		transformComponent.x = x;
		transformComponent.y = y;
		manager->addComponent<Component::Transform>(entityId, transformComponent);

		// add the health component
		Component::Health healthComponent = Component::Health();
		healthComponent.health = PLAYER_HEALTH;
		manager->addComponent<Component::Health>(entityId, healthComponent);

		// add the texture component
		Component::Texture textureComponent = Component::Texture();
		if (!textureComponent.loadTexture(graphics, PLAYER_IMAGE))
		{
			throw(GameError(gameErrorNS::FATAL_ERROR, "Error loading player entity texture"));
		}
		manager->addComponent<Component::Texture>(entityId, textureComponent);

		// add the attack component
		Component::Attack attackComponent = Component::Attack();
		// tune the values later on
		manager->addComponent<Component::Attack>(entityId, attackComponent);

		// add the Jumping component
		Component::Jumping jumpingComponent = Component::Jumping();
		manager->addComponent<Component::Jumping>(entityId, jumpingComponent);

		// add the augmentation component, (might actually be shifted to the game)
		Component::Augmentation augmentationComponent = Component::Augmentation();
		manager->addComponent<Component::Augmentation>(entityId, augmentationComponent);

		return entityId;
	}
}