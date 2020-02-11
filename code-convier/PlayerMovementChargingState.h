#pragma once

#include "Action.h"
#include "State.h"

class PlayerMovementChargingState : public FSM::State {
	FSM::Action update(float frametime);
}; 
