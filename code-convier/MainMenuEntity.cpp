#include "MainMenuEntity.h"

namespace Entity {

	ECS::EntityIdType MainMenu::create(ECS::Manager* manager, Graphics* graphics) {

		ECS::EntityIdType mainMenuId = manager->createEntity<MainMenu>();

		Component::Texture textureComponent = Component::Texture();
		if (!textureComponent.loadTexture(graphics, MAINMENU_IMAGE))
		{
			throw(GameError(gameErrorNS::FATAL_ERROR, "Error loading Main Menu entity texture"));
		}
		textureComponent.zIndex = 0;

		manager->addComponent<Component::Texture>(mainMenuId, textureComponent);

		Component::Transform transformComponent = Component::Transform();
		transformComponent.scale = GAME_HEIGHT / (float) textureComponent.totalHeight;
		transformComponent.x = -(textureComponent.totalWidth * transformComponent.scale - GAME_WIDTH) / 2.0f;
		transformComponent.y = 0;

		manager->addComponent<Component::Transform>(mainMenuId, transformComponent);

		return mainMenuId;
	}
}

