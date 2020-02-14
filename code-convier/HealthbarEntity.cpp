#include "HealthbarEntity.h"

namespace Entity {
	ECS::EntityIdType Healthbar::create(ECS::Manager* manager, Graphics* graphics, float x, float y) {
		ECS::EntityIdType healthbarEntityId = manager->createEntity<Healthbar>();

		// add the transform component
		Component::Transform transformComponent = Component::Transform();
		transformComponent.x = 10;
		transformComponent.y = 10;
		manager->addComponent<Component::Transform>(healthbarEntityId, transformComponent);

		// add the texture component
		Component::Texture textureComponent = Component::Texture();
		if (!textureComponent.loadTexture(graphics, HEALTHBAR_IMAGE))
		{
			throw(GameError(gameErrorNS::FATAL_ERROR, "Error loading Healthbar entity texture"));
		}
		textureComponent.visible = true;
		textureComponent.zIndex = 3;

		// get the health component
		std::unordered_set<ECS::EntityIdType>* playerEntityIds = manager->getEntities<Player>();
		for (ECS::EntityIdType playerEntityId : *playerEntityIds)
		{
			Component::Health& healthComponent = manager->getEntityComponent<Component::Health>(playerEntityId);
			textureComponent.viewableRect.right = healthComponent.health / PLAYER_HEALTH;
		}

		manager->addComponent<Component::Texture>(healthbarEntityId, textureComponent);		

		return healthbarEntityId;
	}
}