#include "GameMenuState.h"

void GameMenuState::enter(Component::State state) {
	// Create menu background
	Entity::MainMenu::create(this->manager, this->graphics);
	// Create menu buttons
	Component::Texture textureComponent = this->manager->getEntityComponent<Component::Texture>(state.entityId);
	float buttonx = GAME_WIDTH / 2 - textureComponent.totalWidth / 2;
	float totalspace = GAME_HEIGHT / 2;
	float buttonsize = textureComponent.totalHeight + 30;

	Entity::Button::create(this->manager, this->graphics, START_BUTTON, "Start", buttonx, totalspace);
	Entity::Button::create(this->manager, this->graphics, CREDITS_BUTTON, "Credits", buttonx, totalspace + buttonsize);
	Entity::Button::create(this->manager, this->graphics, QUIT_BUTTON, "Quit", buttonx, totalspace + buttonsize*2);
}

FSM::Action GameMenuState::update(float frameTime, Component::State state) {
	
}

void GameMenuState::exit(Component::State state) {
	// Destroy menu background

	// Destroy menu buttons
}