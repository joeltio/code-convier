#pragma once

#include "Action.h"
#include "State.h"

class GameRunningState : FSM::State {
	FSM::Action update(float frameTime);
};
