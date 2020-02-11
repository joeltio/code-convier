#pragma once

#include "Action.h"
#include "State.h"

class ClickingState : public FSM::State {
	FSM::Action update(float frameTime);
};