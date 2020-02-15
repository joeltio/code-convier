#include "PlayerRunIconEntity.h"

namespace Entity {
	ECS::EntityIdType PlayerRunIcon::create(ECS::Manager* manager, Graphics* graphics, float x, float y) {
		ECS::EntityIdType playerRunIconEntityId = manager->createEntity<PlayerRunIcon>();

		// add the transform component
		Component::Transform transformComponent = Component::Transform();
		transformComponent.x = x;
		transformComponent.y = y;
		manager->addComponent<Component::Transform>(playerRunIconEntityId, transformComponent);

		// add the texture component
		Component::Texture textureComponent = Component::Texture();
		if (!textureComponent.loadTexture(graphics, PLAYER_RUN_ICON))
		{
			throw(GameError(gameErrorNS::FATAL_ERROR, "Error loading Player Run Icon entity texture"));
		}
		textureComponent.visible = true;
		textureComponent.zIndex = 3;
		manager->addComponent<Component::Texture>(playerRunIconEntityId, textureComponent);

		return playerRunIconEntityId;
	}
}