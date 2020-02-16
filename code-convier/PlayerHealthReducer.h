#pragma once

#include "Reducer.h"
#include "State.h"

#include "PlayerEntity.h"
#include "PlayerHealthStateComponent.h"

#include "PlayerHealthIdleState.h"
#include "PlayerHealthReplenishingState.h"
#include "PlayerDeathState.h"

#include "PlayerHealthIdleAction.h"
#include "PlayerHealthReplenishingAction.h"
#include "PlayerHealthDeathAction.h"

static std::string HEALTH_ACCEPTED_ACTIONS[] = {
	IDLE_PLAYER_HEALTH,
	REPLENISHING_PLAYER_HEALTH,
	DEAD_PLAYER_HEALTH
};

class PlayerHealthReducer : public FSM::Reducer {
public:
	bool acceptsAction(FSM::Action& action);
	void reduce(
		ECS::Manager* manager,
		std::unordered_map<Types::TypeId, FSM::State*> states,
		FSM::Action action
	);
};

