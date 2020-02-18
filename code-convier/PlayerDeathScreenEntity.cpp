#include "PlayerDeathScreenEntity.h"

namespace Entity {

	ECS::EntityIdType PlayerDeathScreen::create(ECS::Manager* manager, Graphics* graphics) {

		ECS::EntityIdType playerDeathScreenId = manager->createEntity<PlayerDeathScreen>();

		Component::Texture textureComponent = Component::Texture();
		if (!textureComponent.loadTexture(graphics, PLAYER_DEATH_SCREEN_IMAGE))
		{
			throw(GameError(gameErrorNS::FATAL_ERROR, "Error loading Player Death Screen entity texture"));
		}
		textureComponent.zIndex = 3;

		manager->addComponent<Component::Texture>(playerDeathScreenId, textureComponent);

		Component::Transform transformComponent = Component::Transform();
		transformComponent.x = 0;
		transformComponent.y = 0;

		manager->addComponent<Component::Transform>(playerDeathScreenId, transformComponent);


		Component::GameState gameStateComponent = Component::GameState{
		playerDeathScreenId,
		true, // isActive
		Types::toTypeId<GamePlayerDeathState>()
		};
		gameStateComponent.renderRect.top = 0;
		gameStateComponent.renderRect.left = 0;
		manager->addComponent<Component::GameState>(playerDeathScreenId, gameStateComponent);


		return playerDeathScreenId;
	}
}

