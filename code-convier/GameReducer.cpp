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

void GameReducer::reduce(ECS::Manager* manager, FSM::Action action) {
	if (action.type == PREPARE_GAME_ACTION)
	{
	}
}
