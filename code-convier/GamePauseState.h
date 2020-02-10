#pragma once

#include "Action.h"
#include "State.h"

class GamePauseState : FSM::State {
	FSM::Action update(float frameTime);
};
