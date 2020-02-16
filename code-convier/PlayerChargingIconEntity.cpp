#include "PlayerChargingIconEntity.h"

namespace Entity {
	ECS::EntityIdType PlayerChargingIcon::create(ECS::Manager* manager, Graphics* graphics, float x, float y) {
		ECS::EntityIdType playerChargingIconEntityId = manager->createEntity<PlayerChargingIcon>();

		// add the transform component
		Component::Transform transformComponent = Component::Transform();
		transformComponent.x = x;
		transformComponent.y = y;
		manager->addComponent<Component::Transform>(playerChargingIconEntityId, transformComponent);

		// add the texture component
		Component::Texture textureComponent = Component::Texture();
		if (!textureComponent.loadTexture(graphics, PLAYER_CHARGING_ICON))
		{
			throw(GameError(gameErrorNS::FATAL_ERROR, "Error loading Player Charging Icon entity texture"));
		}
		textureComponent.visible = true;
		textureComponent.zIndex = 3;
		manager->addComponent<Component::Texture>(playerChargingIconEntityId, textureComponent);

		//add animation component
		Component::Animatable animatableComponent = Component::Animatable();
		animatableComponent.columns = 2;
		animatableComponent.currentFrame = 1;
		animatableComponent.rows = 1;
		animatableComponent.startFrame = 1;
		manager->addComponent<Component::Animatable>(playerChargingIconEntityId, animatableComponent);

		return playerChargingIconEntityId;
	}
}