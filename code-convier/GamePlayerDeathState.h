#pragma once

#include "Action.h"
#include "State.h"

class GamePlayerDeathState : FSM::State {
	FSM::Action update(float frameTime);
};
