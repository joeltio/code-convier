#include "GameMenuState.h"

void GameMenuState::enter(Component::State state) {
	// Create menu background
	Entity::MainMenu::create(this->manager, this->graphics);

	// Create menu buttons
	float yOffset = GAME_HEIGHT / 2;
	ECS::EntityIdType startButtonId = Entity::Button::create(
		this->manager, this->graphics, START_BUTTON, "Start", 0, yOffset, true, false);
	Component::Texture startButtonTexture = this->manager->getEntityComponent<Component::Texture>(startButtonId);
	yOffset += startButtonTexture.totalHeight + BUTTON_MARGIN;

	ECS::EntityIdType creditsButtonId = Entity::Button::create(
		this->manager, this->graphics, CREDITS_BUTTON, "Credits", 0, yOffset, true, false);
	Component::Texture creditsButtonTexture = this->manager->getEntityComponent<Component::Texture>(creditsButtonId);
	yOffset += creditsButtonTexture.totalHeight + BUTTON_MARGIN;

	ECS::EntityIdType quitButtonId = Entity::Button::create(
		this->manager, this->graphics, QUIT_BUTTON, "Quit", 0, yOffset, true, false);
}

FSM::Action GameMenuState::update(float frameTime, Component::State state) {
	return FSM::NoAction();
}

void GameMenuState::exit(Component::State state) {
	// Destroy menu background

	// Destroy menu buttons
}