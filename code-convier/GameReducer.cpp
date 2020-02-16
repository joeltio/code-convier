#include "GameReducer.h"

bool GameReducer::acceptsAction(FSM::Action& action) {
	for (std::string acceptedAction : GAME_ACCEPTED_ACTIONS)
	{
		if (action.type == acceptedAction)
		{
			return true;
		}
	}

	return false;
}

void GameReducer::reduce(
	ECS::Manager* manager,
	std::unordered_map<Types::TypeId, FSM::State*> states,
	FSM::Action action
) {
	if (action.type == PREPARE_GAME_ACTION)
	{
		// Change the state of the game entity
		ECS::EntityIdType gameEntityId = *manager->getEntities<Entity::Game>()->begin();
		Component::GameState& gameState = manager->getEntityComponent<Component::GameState>(gameEntityId);

		FSM::Reducer::changeState<GameCreateLevelState>(states, gameState);
	}
	else if (action.type == PAUSE_GAME_ACTION)
	{
		// Change the state of the game entity
		ECS::EntityIdType gameEntityId = *manager->getEntities<Entity::Game>()->begin();
		Component::GameState& gameState = manager->getEntityComponent<Component::GameState>(gameEntityId);

		FSM::Reducer::changeState<GamePauseState>(states, gameState);
	}
	else if (action.type == PREPARE_MENU_ACTION)
	{
		// Change the state of the game entity
		ECS::EntityIdType gameEntityId = *manager->getEntities<Entity::Game>()->begin();
		Component::GameState& gameState = manager->getEntityComponent<Component::GameState>(gameEntityId);

		FSM::Reducer::changeState<GameMenuState>(states, gameState);
	}
	else if (action.type == RESUME_GAME_ACTION)
	{
		// Change the state of the game entity
		ECS::EntityIdType gameEntityId = *manager->getEntities<Entity::Game>()->begin();
		Component::GameState& gameState = manager->getEntityComponent<Component::GameState>(gameEntityId);

		FSM::Reducer::changeState<GameRunningState>(states, gameState);
	}
	else if (action.type == QUIT_GAME_ACTION)
	{
		PostQuitMessage(0);
	}
	else if (action.type == SHOW_CREDITS_ACTION)
	{
		// Change the state of the game entity
		ECS::EntityIdType gameEntityId = *manager->getEntities<Entity::Game>()->begin();
		Component::GameState& gameState = manager->getEntityComponent<Component::GameState>(gameEntityId);

		FSM::Reducer::changeState<GameCreditsState>(states, gameState);
	}
	else if (action.type == PREPARE_TEMPORARY_AUGMENTATION_ACTION)
	{
		// Change the state of the game entity
		ECS::EntityIdType gameEntityId = *manager->getEntities<Entity::Game>()->begin();
		Component::GameState& gameState = manager->getEntityComponent<Component::GameState>(gameEntityId);

		FSM::Reducer::changeState<GameAugmentationState>(states, gameState);
	}
	else if (action.type == PREPARE_PLAYER_DEATH_ACTION)
	{
		// Change the state of the game entity
		ECS::EntityIdType gameEntityId = *manager->getEntities<Entity::Game>()->begin();
		Component::GameState& gameState = manager->getEntityComponent<Component::GameState>(gameEntityId);

		FSM::Reducer::changeState<GamePlayerDeathState>(states, gameState);
	}
	else if (action.type == DESTROY_GAME_LEVEL_ACTION) 
	{
		// Change the state of the game entity
		ECS::EntityIdType gameEntityId = *manager->getEntities<Entity::Game>()->begin();
		Component::GameState& gameState = manager->getEntityComponent<Component::GameState>(gameEntityId);

		FSM::Reducer::changeState<GameDestroyLevelState>(states, gameState);
	}
}
