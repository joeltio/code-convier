#pragma once

#include "Action.h"
#include "State.h"

// player jumps with a constant V value

class PlayerMovementMovingState : public FSM::State {
	FSM::Action update(float frametime);
};
