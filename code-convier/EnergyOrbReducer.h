#pragma once

#include "Reducer.h"
#include "State.h"

#include "EnergyOrbEntity.h"
#include "EnergyOrbStateComponent.h"

// Actions this reducer handles
#include "OrbDetectPlayerAction.h"

// States that this reducer hanndles
#include "EnergyOrbIdleState.h"
#include "EnergyOrbHomingState.h"

static std::string ACCEPTED_ACTIONS[] = {
	ORB_DETECT_PLAYER_ACTION
};

class EnergyOrbReducer : public FSM::Reducer {
public:
	bool acceptsAction(FSM::Action& action);
	void reduce(
		ECS::Manager* manager,
		std::unordered_map<Types::TypeId, FSM::State*> states,
		FSM::Action action
	);
};
