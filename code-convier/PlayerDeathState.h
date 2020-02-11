#pragma once

#include "Action.h"
#include "State.h"

class PlayerDeathState : public FSM::State {
	FSM::Action update(float frametime);
};
