#pragma once

#include "State.h"

class GameMenuState : public FSM::State {
	void update(float frameTime);
};
