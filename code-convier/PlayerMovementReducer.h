#pragma once

#include "Reducer.h"
#include "State.h"

#include "PlayerEntity.h"
#include "PlayerMovementStateComponent.h"

#include "MovingPlayerMovementAction.h"
#include "ChargingPlayerMovementAction.h"

#include "PlayerMovementMovingState.h"
#include "PlayerMovementChargingState.h"

static std::string MOVEMENT_ACCEPTED_ACTIONS[] = {
	MOVING_PLAYER_MOVEMENT,
	CHARGING_PLAYER_MOVEMENT
};

class PlayerMovementReducer : public FSM::Reducer {
public:
	bool acceptsAction(FSM::Action& action);
	void reduce(
		ECS::Manager* manager,
		std::unordered_map<Types::TypeId, FSM::State*> states,
		FSM::Action action
	);
};
