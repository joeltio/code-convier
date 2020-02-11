#include "ButtonEntity.h"

namespace Entity {

	ECS::EntityIdType Button::create(ECS::Manager* manager, Graphics* graphics, const char* buttonSprite, std::string buttonText, float x, float y) {

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

		return buttonId;
	}
}