#pragma once

#include "State.h"

class GamePlayerDeathState : FSM::State {
	void update(float frameTime);
};
