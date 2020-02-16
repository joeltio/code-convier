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
		transformComponent.x = 0;
		transformComponent.y = 0;

		manager->addComponent<Component::Transform>(pauseMenuId, transformComponent);

		Component::GameState gameStateComponent = Component::GameState{
		pauseMenuId,
		true, // isActive
		Types::toTypeId<GamePauseState>()
		};
		gameStateComponent.renderRect.top = 0;
		gameStateComponent.renderRect.left = 0;
		manager->addComponent<Component::GameState>(pauseMenuId, gameStateComponent);


		return pauseMenuId;
	}
}

