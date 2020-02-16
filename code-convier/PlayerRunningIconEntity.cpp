#include "PlayerRunningIconEntity.h"

namespace Entity {
	ECS::EntityIdType PlayerRunningIcon::create(ECS::Manager* manager, Graphics* graphics, float x, float y) {
		ECS::EntityIdType playerRunningIconEntityId = manager->createEntity<PlayerRunningIcon>();

		// add the transform component
		Component::Transform transformComponent = Component::Transform();
		transformComponent.x = x;
		transformComponent.y = y;
		manager->addComponent<Component::Transform>(playerRunningIconEntityId, transformComponent);

		// add the texture component
		Component::Texture textureComponent = Component::Texture();
		if (!textureComponent.loadTexture(graphics, PLAYER_RUNNING_ICON))
		{
			throw(GameError(gameErrorNS::FATAL_ERROR, "Error loading Player Running Icon entity texture"));
		}
		textureComponent.visible = true;
		textureComponent.zIndex = 3;
		manager->addComponent<Component::Texture>(playerRunningIconEntityId, textureComponent);

		//add animation component
		Component::Animatable animatableComponent = Component::Animatable();
		animatableComponent.columns = 2;
		animatableComponent.currentFrame = 1;
		animatableComponent.rows = 1;
		manager->addComponent<Component::Animatable>(playerRunningIconEntityId, animatableComponent);

		return playerRunningIconEntityId;
	}
}