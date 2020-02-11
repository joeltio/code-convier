#pragma once

#include "Action.h"
#include "State.h"

class PlayerMovementIdleState : public FSM::State {
	FSM::Action update(float frametime);
};