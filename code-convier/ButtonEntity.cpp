#include "ButtonEntity.h"

namespace Entity {

	ECS::EntityIdType Button::create(ECS::Manager* manager, Graphics* graphics, const char* buttonSprite, float x, float y) {

		ECS::EntityIdType buttonId = manager->createEntity<Button>();

		Component::GameState gameStateComponent = Component::GameState{
			buttonId,
			true, // isActive
			Types::toTypeId<GameMenuState>()
		};

		manager->addComponent<Component::GameState>(buttonId, gameStateComponent);


		Component::Texture textureComponent = Component::Texture();
		if (!textureComponent.loadTexture(graphics, buttonSprite))
		{
			throw(GameError(gameErrorNS::FATAL_ERROR, "Error loading button entity texture"));
		}
		textureComponent.visible = true;

		manager->addComponent<Component::Texture>(buttonId, textureComponent);

		return buttonId;
	}
}