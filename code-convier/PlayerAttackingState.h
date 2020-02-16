#pragma once

#include "Action.h"
#include "State.h"

class PlayerAttackingState : public FSM::State {
	FSM::Action update(float frametime, Component::State stateComponent);
};
