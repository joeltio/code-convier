#pragma once

#include "Reducer.h"
#include "State.h"
#include "GameEntity.h"
#include "GameStateComponent.h"

// Actions this reducer handles
#include "PrepareGameAction.h"

static std::string ACCEPTED_ACTIONS[] = {
	PREPARE_GAME_ACTION
};

class GameReducer : public FSM::Reducer {
	public:
		bool acceptsAction(FSM::Action &action);
		void reduce(
			ECS::Manager* manager,
			std::unordered_map<Types::TypeId, FSM::State*> states,
			FSM::Action action
		);
};
