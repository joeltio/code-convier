#pragma once

#include "Reducer.h"
#include "State.h"

#include "PlayerEntity.h"
#include "PlayerMovementStateComponent.h"

#include "IdlePlayerMovementAction.h"
#include "WalkingPlayerMovementAction.h"
#include "RunningPlayerMovementAction.h"
#include "ChargingPlayerMovementAction.h"

#include "PlayerMovementIdleState.h"
#include "PlayerMovementMovingState.h"
#include "PlayerMovementRunningState.h"
#include "PlayerMovementChargingState.h"

static std::string ACCEPTED_ACTIONS[] = {
	IDLE_PLAYER_MOVEMENT,
	WALKING_PLAYER_MOVEMENT,
	RUNNING_PLAYER_MOVEMENT,
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
