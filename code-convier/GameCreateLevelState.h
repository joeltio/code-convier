#pragma once

#include "Action.h"
#include "State.h"

class GameCreateLevelState : public FSM::State {
	FSM::Action update(float frameTime);
};
