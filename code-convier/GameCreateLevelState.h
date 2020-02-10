#pragma once

#include "State.h"

class GameCreateLevelState : public FSM::State {
	void update(float frameTime);
};
