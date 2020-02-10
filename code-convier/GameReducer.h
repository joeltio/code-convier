#pragma once

#include "Reducer.h"

// Actions this reducer handles
#include "PrepareGameAction.h"

static std::string ACCEPTED_ACTIONS[] = {
	PREPARE_GAME_ACTION
};

class GameReducer : public FSM::Reducer {
	public:
		bool acceptsAction(FSM::Action &action);
		void reduce(ECS::Manager* manager, FSM::Action action);
};
