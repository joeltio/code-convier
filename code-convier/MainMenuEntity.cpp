#include "MainMenuEntity.h"

namespace Entity {

	ECS::EntityIdType MainMenu::create(ECS::Manager* manager, Graphics* graphics) {

		ECS::EntityIdType mainMenuId = manager->createEntity<MainMenu>();

		Component::Texture textureComponent = Component::Texture();
		if (!textureComponent.loadTexture(graphics, MAINMENU_IMAGE))
		{
			throw(GameError(gameErrorNS::FATAL_ERROR, "Error loading Main Menu entity texture"));
		}
		textureComponent.visible = true;

		manager->addComponent<Component::Texture>(mainMenuId, textureComponent);

		Component::Transform transformComponent = Component::Transform();
		transformComponent.x = 0;
		transformComponent.y = 0;
		transformComponent.scale = GAME_WIDTH / textureComponent.totalWidth;

		manager->addComponent<Component::Transform>(mainMenuId, transformComponent);

		return mainMenuId;
	}
}

