#include "ButtonEntity.h"

namespace Entity {

	ECS::EntityIdType Button::create(
		ECS::Manager* manager,
		Graphics* graphics,
		const char* buttonSprite,
		std::string buttonText,
		float x,
		float y,
		bool centerX,
		bool centerY
	) {

		ECS::EntityIdType buttonId = manager->createEntity<Button>();

		Component::Texture textureComponent = Component::Texture();
		if (!textureComponent.loadTexture(graphics, buttonSprite))
		{
			throw(GameError(gameErrorNS::FATAL_ERROR, "Error loading button entity texture"));
		}
		textureComponent.visible = true;

		manager->addComponent<Component::Texture>(buttonId, textureComponent);

		Component::Text textComponent = Component::Text();
		textComponent.buttonText = buttonText;

		manager->addComponent<Component::Text>(buttonId, textComponent);

		Component::Transform transformComponent = Component::Transform();
		transformComponent.x = x;
		transformComponent.y = y;
		if (centerX)
		{
			transformComponent.x = GAME_WIDTH / 2 - textureComponent.totalWidth / 2;
		}
		if (centerY)
		{
			transformComponent.y = GAME_HEIGHT / 2 - textureComponent.totalHeight / 2;
		}

		manager->addComponent<Component::Transform>(buttonId, transformComponent);

		Component::ClickState clickStateComponent{
			buttonId,
			true, // isActive
			Types::toTypeId<NotClickedState>()
		};

		manager->addComponent<Component::ClickState>(buttonId, clickStateComponent);

		return buttonId;
	}
}