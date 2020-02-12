#include "GamePauseState.h"

void GamePauseState::enter(Component::State state) {
	// Create Pause menu background
	Entity::PauseMenu::create(this->manager, this->graphics);

	// Create Pause menu buttons
	float yOffset = GAME_HEIGHT / 2;
	ECS::EntityIdType resumeButtonId = Entity::Button::create(
		this->manager, this->graphics, RESUME_BUTTON, "Resume", 0, yOffset, true, false);
	Component::Texture resumeButtonTexture = this->manager->getEntityComponent<Component::Texture>(resumeButtonId);
	yOffset += resumeButtonTexture.totalHeight + BUTTON_MARGIN;

	ECS::EntityIdType menuButtonId = Entity::Button::create(
		this->manager, this->graphics, MENU_BUTTON, "Menu", 0, yOffset, true, false);
}


FSM::Action GamePauseState::update(float frameTime, Component::State state) {
	return FSM::NoAction();
}

void GamePauseState::exit(Component::State state) {
	// Destroy Pause menu background
	std::unordered_set<ECS::EntityIdType> pauseMenuEntityIds = *this->manager->getEntities<Entity::PauseMenu>();
	for (ECS::EntityIdType pauseMenuEntityId : pauseMenuEntityIds)
	{
		this->manager->removeEntity<Entity::PauseMenu>(pauseMenuEntityId);
	}
	// Destroy Pause menu buttons
	std::unordered_set<ECS::EntityIdType> butttonEntityIds = *this->manager->getEntities<Entity::Button>();
	for (ECS::EntityIdType butttonEntityId : butttonEntityIds)
	{
		this->manager->removeEntity<Entity::Button>(butttonEntityId);
	}
}