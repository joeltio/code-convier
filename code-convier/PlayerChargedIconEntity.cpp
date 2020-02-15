#include "PlayerChargedIconEntity.h"

namespace Entity {
	ECS::EntityIdType PlayerChargedIcon::create(ECS::Manager* manager, Graphics* graphics, float x, float y) {
		ECS::EntityIdType playerChargedIconEntityId = manager->createEntity<PlayerChargedIcon>();

		// add the transform component
		Component::Transform transformComponent = Component::Transform();
		transformComponent.x = x;
		transformComponent.y = y;
		manager->addComponent<Component::Transform>(playerChargedIconEntityId, transformComponent);

		// add the texture component
		Component::Texture textureComponent = Component::Texture();
		if (!textureComponent.loadTexture(graphics, PLAYER_CHARGED_ICON))
		{
			throw(GameError(gameErrorNS::FATAL_ERROR, "Error loading Player Charged Icon entity texture"));
		}
		textureComponent.visible = true;
		textureComponent.zIndex = 3;
		manager->addComponent<Component::Texture>(playerChargedIconEntityId, textureComponent);

		return playerChargedIconEntityId;
	}
}