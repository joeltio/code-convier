#pragma once

#include "Action.h"
#include "State.h"

class AttackingState : public FSM::State {
	FSM::Action update(float frametime);
};
