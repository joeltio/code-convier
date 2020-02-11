#pragma once

#include "Action.h"
#include "State.h"

class PlayerHealthIdleState : public FSM::State {
	FSM::Action update(float frametime);
};
