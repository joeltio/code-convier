#include "GameCreditsState.h"

void GameCreditsState::enter(Component::State state) {
	// Create Credits background
	Entity::Credits::create(this->manager, this->graphics);
}


FSM::Action GameCreditsState::update(float frameTime, Component::State state) {
	if (this->input->anyKeyPressed()) {
		return PrepareMenuAction();
	}
	return FSM::NoAction();
}

void GameCreditsState::exit(Component::State state) {
	// Destroy Credits background
	std::unordered_set<ECS::EntityIdType> creditsEntityIds = *this->manager->getEntities<Entity::Credits>();
	for (ECS::EntityIdType creditsEntityId : creditsEntityIds)
	{
		this->manager->removeEntity<Entity::Credits>(creditsEntityId);
	}
}