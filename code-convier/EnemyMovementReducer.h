#pragma once

#include "Reducer.h"
#include "State.h"

#include "EnergyOrbEntity.h"
#include "EnemyMovementStateComponent.h"

// Actions this reducer handles
#include "ChasePlayerAction.h"
#include "EnemyAttackAction.h"

// States that this reducer hanndles
#include "EnemyMovementIdleState.h"
#include "EnemyMovementChaseState.h"
#include "SkeletonAttackState.h"

static std::string ENEMY_MOVEMENT_ACCEPTED_ACTIONS[] = {
	CHASE_PLAYER_ACTION,
	ENEMY_ATTACK_ACTION
};

class EnemyMovementReducer : public FSM::Reducer {
public:
	bool acceptsAction(FSM::Action& action);
	void reduce(
		ECS::Manager* manager,
		std::unordered_map<Types::TypeId, FSM::State*> states,
		FSM::Action action
	);
};
