#pragma once

#include "Action.h"
#include "State.h"
#include "IdlePlayerMovementAction.h"

class PlayerMovementIdleState : public FSM::State {
	FSM::Action update(float frametime, Component::State stateComponent);
};