#include "CreditsEntity.h"

namespace Entity {

	ECS::EntityIdType Credits::create(ECS::Manager* manager, Graphics* graphics) {

		ECS::EntityIdType creditsId = manager->createEntity<Credits>();

		Component::Texture textureComponent = Component::Texture();
		if (!textureComponent.loadTexture(graphics, CREDITSBACKGROUND_IMAGE))
		{
			throw(GameError(gameErrorNS::FATAL_ERROR, "Error loading Credits background entity texture"));
		}
		textureComponent.visible = true;

		manager->addComponent<Component::Texture>(creditsId, textureComponent);

		Component::Transform transformComponent = Component::Transform();
		//transformComponent.scale = GAME_HEIGHT / (float)textureComponent.totalHeight;
		//transformComponent.x = -(textureComponent.totalWidth * transformComponent.scale - GAME_WIDTH) / 2.0f;
		transformComponent.x = 0;
		transformComponent.y = 0;

		manager->addComponent<Component::Transform>(creditsId, transformComponent);

		return creditsId;
	}
}

