#include "GameReducer.h"

bool GameReducer::acceptsAction(FSM::Action& action) {
	for (std::string acceptedAction : ACCEPTED_ACTIONS)
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
}
