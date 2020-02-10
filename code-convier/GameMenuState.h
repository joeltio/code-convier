#pragma once

#include "Action.h"
#include "State.h"

class GameMenuState : public FSM::State {
	FSM::Action update(float frameTime);
};
