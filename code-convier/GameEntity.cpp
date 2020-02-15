#include "GameEntity.h"

namespace Entity {

ECS::EntityIdType Game::create(ECS::Manager* manager) {
	ECS::EntityIdType entityId = manager->createEntity<Game>();

	Component::GameState gameStateComponent = Component::GameState {
		entityId,
		true, // isActive
		Types::toTypeId<GameMenuState>()
	};
	gameStateComponent.renderRect.left = 0;
	gameStateComponent.renderRect.right = GAME_WIDTH;
	gameStateComponent.renderRect.top = 0;
	gameStateComponent.renderRect.bottom = GAME_HEIGHT;

	manager->addComponent<Component::GameState>(entityId, gameStateComponent);

	Component::Augmentation augmentationComponent = Component::Augmentation();
	manager->addComponent<Component::Augmentation>(entityId, augmentationComponent);

	return entityId;
}

}