#pragma once

#include "Action.h"
#include "State.h"

class PlayerHealthReplenishingState : public FSM::State {
	FSM::Action update(float frametime);
};
