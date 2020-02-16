#include "GamePlayerDeathState.h"

void GamePlayerDeathState::enter(Component::State state) {
	// Create Player Death Screen background
	Entity::PlayerDeathScreen::create(this->manager, this->graphics);
}

FSM::Action GamePlayerDeathState::update(float frameTime, Component::State state) {
	if (this->input->anyKeyPressed()) {
		return PrepareMenuAction();
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