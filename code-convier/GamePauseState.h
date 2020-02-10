#pragma once

#include "State.h"

class GamePauseState : FSM::State {
	void update(float frameTime);
};
