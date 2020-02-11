#include "GameEntity.h"

namespace Entity {

ECS::EntityIdType Game::create(ECS::Manager* manager) {
	ECS::EntityIdType entityId = manager->createEntity<Game>();

	Component::GameState gameStateComponent = Component::GameState {
		entityId,
		true, // isActive
		Types::toTypeId<GameMenuState>()
	};

	manager->addComponent<Component::GameState>(entityId, gameStateComponent);

	Component::GameData gameDataComponent = Component::GameData();
	gameDataComponent.renderRect.left = 0;
	gameDataComponent.renderRect.right = GAME_WIDTH;
	gameDataComponent.renderRect.top = 0;
	gameDataComponent.renderRect.bottom = GAME_HEIGHT;

	manager->addComponent<Component::GameData>(entityId, gameDataComponent);

	return entityId;
}

}