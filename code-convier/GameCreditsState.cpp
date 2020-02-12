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
}