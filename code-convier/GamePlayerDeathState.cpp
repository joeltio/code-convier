#include "GamePlayerDeathState.h"

void GamePlayerDeathState::enter(Component::State state) {
	// Get the current game state
	Component::GameState& gameState = *this->manager->getComponents<Component::GameState>()->begin();
	// Create Player Death Screen background
	Entity::PlayerDeathScreen::create(this->manager, this->graphics, gameState.renderRect.left, gameState.renderRect.top);
}

FSM::Action GamePlayerDeathState::update(float frameTime, Component::State state) {
	if (this->input->anyKeyPressed()) {
		return QuitGameAction();
	}
	return FSM::NoAction();
}

void GamePlayerDeathState::exit(Component::State state) {
	// Destroy  Player Death Screen background
	std::unordered_set<ECS::EntityIdType> playerDeathScreenEntityIds = *this->manager->getEntities<Entity::PlayerDeathScreen>();
	for (ECS::EntityIdType playerDeathScreenEntityId : playerDeathScreenEntityIds)
	{
		this->manager->removeEntity<Entity::PlayerDeathScreen>(playerDeathScreenEntityId);
	}
}