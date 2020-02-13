#include "PauseMenuEntity.h"

namespace Entity {

	ECS::EntityIdType PauseMenu::create(ECS::Manager* manager, Graphics* graphics) {

		ECS::EntityIdType pauseMenuId = manager->createEntity<PauseMenu>();

		Component::Texture textureComponent = Component::Texture();
		if (!textureComponent.loadTexture(graphics, PAUSEMENU_IMAGE))
		{
			throw(GameError(gameErrorNS::FATAL_ERROR, "Error loading Pause Menu entity texture"));
		}
		textureComponent.zIndex = 3;

		manager->addComponent<Component::Texture>(pauseMenuId, textureComponent);

		Component::Transform transformComponent = Component::Transform();
		//transformComponent.scale = GAME_HEIGHT / (float)textureComponent.totalHeight;
		//transformComponent.x = -(textureComponent.totalWidth * transformComponent.scale - GAME_WIDTH) / 2.0f;
		transformComponent.x = 0;
		transformComponent.y = 0;

		manager->addComponent<Component::Transform>(pauseMenuId, transformComponent);

		return pauseMenuId;
	}
}

