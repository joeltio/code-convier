#pragma once

#include "Reducer.h"
#include "State.h"

#include "PlayerEntity.h"
#include "PlayerAttackStateComponent.h"

#include "PlayerAttackingAction.h"
#include "PlayerAttackIdleAction.h"

#include "PlayerAttackIdleState.h"
#include "PlayerAttackingState.h"

static std::string ATTACK_ACCEPTED_ACTIONS[] = {
	PLAYER_ATTACKING,
	PLAYER_ATTACK_IDLE
};

class PlayerAttackReducer : public FSM::Reducer {
public:
	bool acceptsAction(FSM::Action& action);
	void reduce(
		ECS::Manager* manager,
		std::unordered_map<Types::TypeId, FSM::State*> states,
		FSM::Action action
	);
};
