#pragma once

#include "State.h"

class GameRunningState : FSM::State {
	void update(float frameTime);
};
