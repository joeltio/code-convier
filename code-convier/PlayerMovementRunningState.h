#pragma once

#include "Action.h"
#include "State.h"

class PlayerMovementRunningState : public FSM::State {
	FSM::Action update(float frametime);
};