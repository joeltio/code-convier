#pragma once

#include "Action.h"
#include "State.h"

class AttackIdleState : public FSM::State {
	FSM::Action update(float frametime);
};
