#pragma once

#include "Action.h"
#include "State.h"

class GameDestroyLevelState : public FSM::State {
	FSM::Action update(float frameTime, Component::State state);
};
